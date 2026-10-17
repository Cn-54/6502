
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "instructions.h"

CPU *Create_CPU(Memory *mem){
    if (mem == NULL){
        return NULL;
    }

    CPU *cpu = malloc(sizeof *cpu);

    if (cpu == NULL){
        return NULL;
    }
    cpu->mem = mem;

    return cpu;
}

void Destroy_CPU(CPU *cpu){
    free(cpu);
}

void Reset_CPU(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL){
        return;
    }

    cpu->AC = 0x00;
    cpu->XR = 0x00;
    cpu->YR = 0x00;

    cpu->SR = FLAG_UNUSED | FLAG_INTERRUPT;
    cpu->SP = 0xFD;

    uint8_t low  = Read_Memory(cpu->mem, 0xFFFC);
    uint8_t high = Read_Memory(cpu->mem, 0xFFFD);

    cpu->PC = ((uint16_t)high << 8) | low;
}

static uint8_t Fetch(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL){
        return 0;
    }

    uint8_t opcode = Read_Memory(cpu->mem, cpu->PC);
    cpu->PC++;

    return opcode;
}

static void execute(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL){
        return;
    }

    uint8_t opcode = Fetch(cpu);

    if (instructions[opcode].execute == NULL) {
        printf("Unimplemented instruction: %s, Opcode: $%02X\n",instructions[opcode].asm_name,opcode);
        cpu->halt = 1;
        return;
    }

    instructions[opcode].execute(cpu);
}

void Step_CPU(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL){
        return;
    }

    execute(cpu);
}

static void STACK_PUSH(CPU *cpu, uint8_t byte){
    Write_Memory(cpu->mem, 0x0100 | cpu->SP,byte);
    cpu->SP--;
}

static uint8_t STACK_POP(CPU *cpu){
    uint8_t byte = Read_Memory(cpu->mem, 0x0100 | cpu->SP);
    cpu->SP++;

    return byte;
}

void Execute_BRK(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    cpu->PC++;  // Skip the padding byte after BRK

    // Push return address onto the stack 
    STACK_PUSH(cpu,(uint8_t)(cpu->PC >> 8)); // high byte

    STACK_PUSH(cpu,(uint8_t)cpu->PC); // low byte

    // Push status register with Break and Unused bits set.
    STACK_PUSH(cpu,cpu->SR | FLAG_BREAK | FLAG_UNUSED);

    // Disable IRQ interrupts.
    cpu->SR |= FLAG_INTERRUPT;

    // Load interrupt handler address
    uint8_t low = Read_Memory(cpu->mem, 0xFFFE);
    uint8_t high = Read_Memory(cpu->mem, 0xFFFF);

    cpu->PC = ((uint16_t)high << 8) | low;
}

void Execute_PHP(CPU *cpu){ // pushes the status register to the stack with break and flag 5 set
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    STACK_PUSH(cpu,cpu->SR | FLAG_BREAK | FLAG_UNUSED);

}