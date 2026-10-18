
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "instructions.h"
#include "memory.h"

CPU *Create_CPU(Memory *mem){
    if (mem == NULL){
        return NULL;
    }

    CPU *cpu = calloc(1, sizeof *cpu);

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

    cpu->PC_L = low;
    cpu->PC_H = high;

    cpu->halt = 0;
    cpu->op_addr = 0;
}

static uint8_t execute(CPU *cpu){

    uint16_t pc = cpu->PC;
    uint8_t opcode = Read_Memory(cpu->mem, pc);
    const struct cpu_ins *ins = &instructions[opcode];

    if (instructions[opcode].execute == NULL) {
        printf("Unimplemented instruction: %s, Opcode: $%02X\n",instructions[opcode].asm_name,opcode);
        cpu->halt = 1;
        return 0;
    }

    printf("%04X  %02X  %-10s A:%02X X:%02X Y:%02X P:%02X SP:%02X\n",
            pc, opcode, instructions[opcode].asm_name,
            cpu->AC, cpu->XR, cpu->YR, cpu->SR, cpu->SP);

    cpu->op_addr = pc + 1;
    cpu->PC = pc + ins->size;

    ins->execute(cpu);
    return ins->cycles;
}

uint8_t Step_CPU(CPU *cpu){
    return execute(cpu);
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

static uint16_t Read_Word(CPU *cpu, uint16_t addr){
    uint8_t low  = Read_Memory(cpu->mem, addr);
    uint8_t high = Read_Memory(cpu->mem, addr + 1);
    return ((uint16_t)high << 8) | low;
}


static void SET_ZERO(CPU *cpu,uint8_t val){
            // zero flag
    if (val == 0){
        cpu->SR |= FLAG_ZERO;
    } else{
        cpu->SR &= ~FLAG_ZERO;
    }
}

static void SET_NEGATIVE(CPU *cpu, uint8_t val){
    // negative flag (if bit 7 is set)
    if (val & FLAG_NEGATIVE){
        cpu->SR |= FLAG_NEGATIVE;
    } else{
        cpu->SR &= ~FLAG_NEGATIVE;
    }
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

void Execute_DEY(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }
    cpu->YR--;

    SET_ZERO(cpu, cpu->YR);

    SET_NEGATIVE(cpu, cpu->YR);
}

void Execute_DEX(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }
    cpu->XR--;

    SET_ZERO(cpu, cpu->XR);

    SET_NEGATIVE(cpu, cpu->XR);
}

void Execute_CMP_IMM(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    uint8_t value = Read_Memory(cpu->mem, cpu->op_addr);
    uint8_t result = cpu->AC - value;

    // carry flag
    if (cpu->AC >= value){
        cpu->SR |= FLAG_CARRY;
    } else{
        cpu->SR &= ~FLAG_CARRY;
    }

    // zero flag
    if (cpu->AC == value){
        cpu->SR |= FLAG_ZERO;
    } else{
        cpu->SR &= ~FLAG_ZERO;
    }


    SET_NEGATIVE(cpu, result);
}

void Execute_BEQ(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    int8_t offset = (int8_t)Read_Memory(cpu->mem, cpu->op_addr);

    if (cpu->SR & FLAG_ZERO) {
        cpu->PC += offset;
    }
}

void Execute_BNE(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    int8_t offset = (int8_t)Read_Memory(cpu->mem, cpu->op_addr);

    if (!(cpu->SR & FLAG_ZERO)) {
        cpu->PC += offset;
    }
}

void Execute_JMP_ABS(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    cpu->PC = Read_Word(cpu, cpu->op_addr);

}

void Execute_CLD(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    cpu->SR &= ~(FLAG_DECIMAL);
}

void Execute_LDX_IMM(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    uint8_t val = Read_Memory(cpu->mem, cpu->op_addr);
    cpu->XR = val;

        // zero flag
    SET_ZERO(cpu, val);

    SET_NEGATIVE(cpu, val);
}

void Execute_TXS(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    cpu->SP = cpu->XR;
}

void Execute_LDA_IMM(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    uint8_t val = Read_Memory(cpu->mem, cpu->op_addr);
    cpu->AC = val;

            // zero flag
    SET_ZERO(cpu, val);

    SET_NEGATIVE(cpu, val);
}


void Execute_STA_ABS(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    uint16_t addr = Read_Word(cpu, cpu->op_addr);

    Write_Memory(cpu->mem, addr, cpu->AC);
}

void Execute_LDY_IMM(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    uint8_t val = Read_Memory(cpu->mem, cpu->op_addr);
    cpu->YR = val;

    SET_ZERO(cpu, val);
    SET_NEGATIVE(cpu, val);
}

void Execute_LDA_ABS(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    uint16_t addr = Read_Word(cpu, cpu->op_addr);
    uint8_t val = Read_Memory(cpu->mem,addr);
    cpu->AC = val;

    SET_ZERO(cpu, val);
    SET_NEGATIVE(cpu, val);
}

void Execute_TYA(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    cpu->AC = cpu->YR;

    SET_ZERO(cpu, cpu->AC);
    SET_NEGATIVE(cpu, cpu->AC);
}

void Execute_TAX(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    cpu->XR = cpu->AC;

    SET_ZERO(cpu, cpu->XR);
    SET_NEGATIVE(cpu, cpu->XR);
}

void Execute_BPL(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    int8_t offset = (int8_t)Read_Memory(cpu->mem, cpu->op_addr);

    if (!(cpu->SR & FLAG_NEGATIVE)) {
        cpu->PC += offset;
    }
}

void Execute_CLC(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    cpu->SR = cpu->SR & ~FLAG_CARRY;
}

void Execute_ADC_IMM(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }

    uint8_t val = Read_Memory(cpu->mem, cpu->op_addr);

    uint16_t sum = (uint16_t)cpu->AC + val + (cpu->SR & FLAG_CARRY);

    if (sum > 0xFF){
        cpu->SR |= FLAG_CARRY;
    } else{
        cpu->SR &= ~FLAG_CARRY;
    }


    if ((~(cpu->AC ^ val) & (cpu->AC ^ sum)) & FLAG_NEGATIVE){
        cpu->SR |= FLAG_OVERFLOW;
    } else{
        cpu->SR &= ~FLAG_OVERFLOW;
    }

    cpu->AC = (uint8_t)sum;

    SET_ZERO(cpu, cpu->AC);
    SET_NEGATIVE(cpu, cpu->AC);
}

void Execute_NOP(CPU *cpu){
    if (cpu == NULL || cpu->mem == NULL) {
        return;
    }
}
