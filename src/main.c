
#include "cpu.h"
#include "memory.h"
#include <stdio.h>

int main(){
    Memory *mem = Create_Memory();
    CPU *cpu = Create_CPU(mem);

    Load_Memory(mem, "roms//6502_functional_test.bin", 0x0000);


    Reset_CPU(cpu);
    cpu->PC = 0x0400;
    while (!cpu->halt) {
        uint16_t prev = cpu->PC;
        Step_CPU(cpu);
        if (cpu->PC == prev) { // trap detection
            printf("Trapped at $%04X\n", cpu->PC);
            break;
        }
    }
}