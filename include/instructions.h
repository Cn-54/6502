#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"
#include <stdint.h>

struct cpu_ins {
    const char *asm_name;
    uint8_t size;
    void (*execute)(CPU *cpu);
    uint8_t cycles;
};

extern const struct cpu_ins instructions[256];


#endif