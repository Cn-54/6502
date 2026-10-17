
#include "cpu.h"
#include "memory.h"

int main(){
    Memory *mem = Create_Memory();
    CPU *cpu = Create_CPU(mem);

    Load_Memory(mem, "roms//6502_functional_test.bin", 0x0000);

    while (!cpu->halt) {
        Step_CPU(cpu);
    }
}