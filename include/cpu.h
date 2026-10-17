
#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "memory.h"

// bit masks for the status register
#define FLAG_CARRY     0x01
#define FLAG_ZERO      0x02
#define FLAG_INTERRUPT 0x04
#define FLAG_DECIMAL   0x08
#define FLAG_BREAK     0x10
#define FLAG_UNUSED    0x20
#define FLAG_OVERFLOW  0x40
#define FLAG_NEGATIVE  0x80

// CPU state
typedef struct {
    union {
        uint16_t PC;

        struct {
            uint8_t PC_L;
            uint8_t PC_H;
        };
    };

    uint8_t AC;  // accumulator
    uint8_t XR;  // X register
    uint8_t YR;  // Y register
    uint8_t SR;  // Status register
    uint8_t SP;  // Stack pointer

    Memory *mem; // connected memory

    unsigned int halt : 1;
} CPU;


CPU *Create_CPU(Memory *mem);
void Destroy_CPU(CPU *cpu);

void Reset_CPU(CPU *cpu);
void Step_CPU(CPU *cpu);



void Execute_BRK(CPU *cpu);
void Execute_PHP(CPU *cpu);


#endif
