
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
    union {  // allows PC to read too and written too as the full 16 bit val or from the low 8 or the high 8 (not needed but helps slightly)
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

    uint16_t op_addr;

    Memory *mem; // connected memory

    unsigned int halt : 1;
} CPU;


CPU *Create_CPU(Memory *mem);
void Destroy_CPU(CPU *cpu);

void Reset_CPU(CPU *cpu);
uint8_t Step_CPU(CPU *cpu);



void Execute_BRK(CPU *cpu);
void Execute_PHP(CPU *cpu);
void Execute_DEY(CPU *cpu);
void Execute_DEX(CPU *cpu);
void Execute_CMP_IMM(CPU *cpu);
void Execute_BEQ(CPU *cpu);
void Execute_BNE(CPU *cpu);
void Execute_JMP_ABS(CPU *cpu);
void Execute_CLD(CPU *cpu);
void Execute_LDX_IMM(CPU *cpu);
void Execute_TXS(CPU *cpu);
void Execute_LDA_IMM(CPU *cpu);
void Execute_STA_ABS(CPU *cpu);
void Execute_LDY_IMM(CPU *cpu);
void Execute_LDA_ABS(CPU *cpu);
void Execute_TYA(CPU *cpu);
void Execute_TAX(CPU *cpu);
void Execute_BPL(CPU *cpu);
void Execute_CLC(CPU *cpu);
void Execute_ADC_IMM(CPU *cpu);
void Execute_NOP(CPU *cpu);
void Execute_EOR_IMM(CPU *cpu);
void Execute_CPY_IMM(CPU *cpu);
void Execute_BCC(CPU *cpu);
void Execute_BMI(CPU *cpu);
void Execute_BCS(CPU *cpu);
void Execute_CPX_IMM(CPU *cpu);
void Execute_TAY(CPU *cpu);
void Execute_PHA(CPU *cpu);
void Execute_CMP_ABS(CPU *cpu);

#endif
