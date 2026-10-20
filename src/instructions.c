#include <stdlib.h>
#include "instructions.h"

const struct cpu_ins instructions[256] = {
    /* 0x00 - 0x0F */
    {"BRK impl", 1, Execute_BRK, 7}, // 00
    {"ORA X, ind", 2, NULL, 6}, // 01
    {"Undefined", 0, NULL, 0}, // 02
    {"Undefined", 0, NULL, 0}, // 03
    {"Undefined", 0, NULL, 0}, // 04
    {"ORA zp", 2, NULL, 3}, // 05
    {"ASL zp", 2, NULL, 5}, // 06
    {"Undefined", 0, NULL, 0}, // 07
    {"PHP impl", 1, Execute_PHP, 3}, // 08
    {"ORA #", 2, NULL, 2}, // 09
    {"ASL A", 1, NULL, 2}, // 0A
    {"Undefined", 0, NULL, 0}, // 0B
    {"Undefined", 0, NULL, 0}, // 0C
    {"ORA abs", 3, NULL, 4}, // 0D
    {"ASL abs", 3, NULL, 6}, // 0E
    {"Undefined", 0, NULL, 0}, // 0F

    /* 0x10 - 0x1F */
    {"BPL rel", 2, Execute_BPL, 2}, // 10
    {"ORA ind, Y", 2, NULL, 5}, // 11
    {"Undefined", 0, NULL, 0}, // 12
    {"Undefined", 0, NULL, 0}, // 13
    {"Undefined", 0, NULL, 0}, // 14
    {"ORA zp, X", 2, NULL, 4}, // 15
    {"ASL zp, X", 2, NULL, 6}, // 16
    {"Undefined", 0, NULL, 0}, // 17
    {"CLC impl", 1, Execute_CLC, 2}, // 18
    {"ORA abs, Y", 3, NULL, 4}, // 19
    {"Undefined", 0, NULL, 0}, // 1A
    {"Undefined", 0, NULL, 0}, // 1B
    {"Undefined", 0, NULL, 0}, // 1C
    {"ORA abs, X", 3, NULL, 4}, // 1D
    {"ASL abs, X", 3, NULL, 7}, // 1E
    {"Undefined", 0, NULL, 0}, // 1F

    /* 0x20 - 0x2F */
    {"JSR abs", 3, NULL, 6}, // 20
    {"AND X, ind", 2, NULL, 6}, // 21
    {"Undefined", 0, NULL, 0}, // 22
    {"Undefined", 0, NULL, 0}, // 23
    {"BIT zp", 2, NULL, 3}, // 24
    {"AND zp", 2, NULL, 3}, // 25
    {"ROL zp", 2, NULL, 5}, // 26
    {"Undefined", 0, NULL, 0}, // 27
    {"PLP impl", 1, NULL, 4}, // 28
    {"AND #", 2, NULL, 2}, // 29
    {"ROL A", 1, NULL, 2}, // 2A
    {"Undefined", 0, NULL, 0}, // 2B
    {"BIT abs", 3, NULL, 4}, // 2C
    {"AND abs", 3, NULL, 4}, // 2D
    {"ROL abs", 3, NULL, 6}, // 2E
    {"Undefined", 0, NULL, 0}, // 2F

    /* 0x30 - 0x3F */
    {"BMI rel", 2, Execute_BMI, 2}, // 30
    {"AND ind, Y", 2, NULL, 5}, // 31
    {"Undefined", 0, NULL, 0}, // 32
    {"Undefined", 0, NULL, 0}, // 33
    {"Undefined", 0, NULL, 0}, // 34
    {"AND zp, X", 2, NULL, 4}, // 35
    {"ROL zp, X", 2, NULL, 6}, // 36
    {"Undefined", 0, NULL, 0}, // 37
    {"SEC impl", 1, NULL, 2}, // 38
    {"AND abs, Y", 3, NULL, 4}, // 39
    {"Undefined", 0, NULL, 0}, // 3A
    {"Undefined", 0, NULL, 0}, // 3B
    {"Undefined", 0, NULL, 0}, // 3C
    {"AND abs, X", 3, NULL, 4}, // 3D
    {"ROL abs, X", 3, NULL, 7}, // 3E
    {"Undefined", 0, NULL, 0}, // 3F

    /* 0x40 - 0x4F */
    {"RTI impl", 1, NULL, 6}, // 40
    {"EOR X, ind", 2, NULL, 6}, // 41
    {"Undefined", 0, NULL, 0}, // 42
    {"Undefined", 0, NULL, 0}, // 43
    {"Undefined", 0, NULL, 0}, // 44
    {"EOR zp", 2, NULL, 3}, // 45
    {"LSR zp", 2, NULL, 5}, // 46
    {"Undefined", 0, NULL, 0}, // 47
    {"PHA impl", 1, Execute_PHA, 3}, // 48
    {"EOR #", 2, Execute_EOR_IMM, 2}, // 49
    {"LSR A", 1, NULL, 2}, // 4A
    {"Undefined", 0, NULL, 0}, // 4B
    {"JMP abs", 3, Execute_JMP_ABS, 3}, // 4C
    {"EOR abs", 3, NULL, 4}, // 4D
    {"LSR abs", 3, NULL, 6}, // 4E
    {"Undefined", 0, NULL, 0}, // 4F

    /* 0x50 - 0x5F */
    {"BVC rel", 2, NULL, 2}, // 50
    {"EOR ind, Y", 2, NULL, 5}, // 51
    {"Undefined", 0, NULL, 0}, // 52
    {"Undefined", 0, NULL, 0}, // 53
    {"Undefined", 0, NULL, 0}, // 54
    {"EOR zp, X", 2, NULL, 4}, // 55
    {"LSR zp, X", 2, NULL, 6}, // 56
    {"Undefined", 0, NULL, 0}, // 57
    {"CLI impl", 1, NULL, 2}, // 58
    {"EOR abs, Y", 3, NULL, 4}, // 59
    {"Undefined", 0, NULL, 0}, // 5A
    {"Undefined", 0, NULL, 0}, // 5B
    {"Undefined", 0, NULL, 0}, // 5C
    {"EOR abs, X", 3, NULL, 4}, // 5D
    {"LSR abs, X", 3, NULL, 7}, // 5E
    {"Undefined", 0, NULL, 0}, // 5F

    /* 0x60 - 0x6F */
    {"RTS impl", 1, NULL, 6}, // 60
    {"ADC X, ind", 2, NULL, 6}, // 61
    {"Undefined", 0, NULL, 0}, // 62
    {"Undefined", 0, NULL, 0}, // 63
    {"Undefined", 0, NULL, 0}, // 64
    {"ADC zp", 2, NULL, 3}, // 65
    {"ROR zp", 2, NULL, 5}, // 66
    {"Undefined", 0, NULL, 0}, // 67
    {"PLA impl", 1, NULL, 4}, // 68
    {"ADC #", 2, Execute_ADC_IMM, 2}, // 69
    {"ROR A", 1, NULL, 2}, // 6A
    {"Undefined", 0, NULL, 0}, // 6B
    {"JMP ind", 3, NULL, 5}, // 6C
    {"ADC abs", 3, NULL, 4}, // 6D
    {"ROR abs", 3, NULL, 6}, // 6E
    {"Undefined", 0, NULL, 0}, // 6F

    /* 0x70 - 0x7F */
    {"BVS rel", 2, NULL, 2}, // 70
    {"ADC ind, Y", 2, NULL, 5}, // 71
    {"Undefined", 0, NULL, 0}, // 72
    {"Undefined", 0, NULL, 0}, // 73
    {"Undefined", 0, NULL, 0}, // 74
    {"ADC zp, X", 2, NULL, 4}, // 75
    {"ROR zp, X", 2, NULL, 6}, // 76
    {"Undefined", 0, NULL, 0}, // 77
    {"SEI impl", 1, NULL, 2}, // 78
    {"ADC abs, Y", 3, NULL, 4}, // 79
    {"Undefined", 0, NULL, 0}, // 7A
    {"Undefined", 0, NULL, 0}, // 7B
    {"Undefined", 0, NULL, 0}, // 7C
    {"ADC abs, X", 3, NULL, 4}, // 7D
    {"ROR abs, X", 3, NULL, 7}, // 7E
    {"Undefined", 0, NULL, 0}, // 7F

    /* 0x80 - 0x8F */
    {"Undefined", 0, NULL, 0}, // 80
    {"STA X, ind", 2, NULL, 6}, // 81
    {"Undefined", 0, NULL, 0}, // 82
    {"Undefined", 0, NULL, 0}, // 83
    {"STY zp", 2, NULL, 3}, // 84
    {"STA zp", 2, NULL, 3}, // 85
    {"STX zp", 2, NULL, 3}, // 86
    {"Undefined", 0, NULL, 0}, // 87
    {"DEY impl", 1, Execute_DEY, 2}, // 88
    {"Undefined", 0, NULL, 0}, // 89
    {"TXA impl", 1, NULL, 2}, // 8A
    {"Undefined", 0, NULL, 0}, // 8B
    {"STY abs", 3, NULL, 4}, // 8C
    {"STA abs", 3, Execute_STA_ABS, 4}, // 8D
    {"STX abs", 3, NULL, 4}, // 8E
    {"Undefined", 0, NULL, 0}, // 8F

    /* 0x90 - 0x9F */
    {"BCC rel", 2, Execute_BCC, 2}, // 90
    {"STA ind, Y", 2, NULL, 6}, // 91
    {"Undefined", 0, NULL, 0}, // 92
    {"Undefined", 0, NULL, 0}, // 93
    {"STY zp, X", 2, NULL, 4}, // 94
    {"STA zp, X", 2, NULL, 4}, // 95
    {"STX zp, Y", 2, NULL, 4}, // 96
    {"Undefined", 0, NULL, 0}, // 97
    {"TYA impl", 1, Execute_TYA, 2}, // 98
    {"STA abs, Y", 3, NULL, 5}, // 99
    {"TXS impl", 1, Execute_TXS, 2}, // 9A
    {"Undefined", 0, NULL, 0}, // 9B
    {"Undefined", 0, NULL, 0}, // 9C
    {"STA abs, X", 3, NULL, 5}, // 9D
    {"Undefined", 0, NULL, 0}, // 9E
    {"Undefined", 0, NULL, 0}, // 9F

    /* 0xA0 - 0xAF */
    {"LDY #", 2, Execute_LDY_IMM, 2}, // A0
    {"LDA X, ind", 2, NULL, 6}, // A1
    {"LDX #", 2, Execute_LDX_IMM, 2}, // A2
    {"Undefined", 0, NULL, 0}, // A3
    {"LDY zp", 2, NULL, 3}, // A4
    {"LDA zp", 2, NULL, 3}, // A5
    {"LDX zp", 2, NULL, 3}, // A6
    {"Undefined", 0, NULL, 0}, // A7
    {"TAY impl", 1, Execute_TAY, 2}, // A8
    {"LDA #", 2, Execute_LDA_IMM, 2}, // A9
    {"TAX impl", 1, Execute_TAX, 2}, // AA
    {"Undefined", 0, NULL, 0}, // AB
    {"LDY abs", 3, NULL, 4}, // AC
    {"LDA abs", 3, Execute_LDA_ABS, 4}, // AD
    {"LDX abs", 3, NULL, 4}, // AE
    {"Undefined", 0, NULL, 0}, // AF

    /* 0xB0 - 0xBF */
    {"BCS rel", 2, Execute_BCS, 2}, // B0
    {"LDA ind, Y", 2, NULL, 5}, // B1
    {"Undefined", 0, NULL, 0}, // B2
    {"Undefined", 0, NULL, 0}, // B3
    {"LDY zp, X", 2, NULL, 4}, // B4
    {"LDA zp, X", 2, NULL, 4}, // B5
    {"LDX zp, Y", 2, NULL, 4}, // B6
    {"Undefined", 0, NULL, 0}, // B7
    {"CLV impl", 1, NULL, 2}, // B8
    {"LDA abs, Y", 3, NULL, 4}, // B9
    {"TSX impl", 1, NULL, 2}, // BA
    {"Undefined", 0, NULL, 0}, // BB
    {"LDY abs, X", 3, NULL, 4}, // BC
    {"LDA abs, X", 3, NULL, 4}, // BD
    {"LDX abs, Y", 3, NULL, 4}, // BE
    {"Undefined", 0, NULL, 0}, // BF

    /* 0xC0 - 0xCF */
    {"CPY #", 2, Execute_CPY_IMM, 2}, // C0
    {"CMP X, ind", 2, NULL, 6}, // C1
    {"Undefined", 0, NULL, 0}, // C2
    {"Undefined", 0, NULL, 0}, // C3
    {"CPY zp", 2, NULL, 3}, // C4
    {"CMP zp", 2, NULL, 3}, // C5
    {"DEC zp", 2, NULL, 5}, // C6
    {"Undefined", 0, NULL, 0}, // C7
    {"INY impl", 1, NULL, 2}, // C8
    {"CMP #", 2, Execute_CMP_IMM, 2}, // C9
    {"DEX impl", 1, Execute_DEX, 2}, // CA
    {"Undefined", 0, NULL, 0}, // CB
    {"CPY abs", 3, NULL, 4}, // CC
    {"CMP abs", 3, Execute_CMP_ABS, 4}, // CD
    {"DEC abs", 3, NULL, 6}, // CE
    {"Undefined", 0, NULL, 0}, // CF

    /* 0xD0 - 0xDF */
    {"BNE rel", 2, Execute_BNE, 2}, // D0
    {"CMP ind, Y", 2, NULL, 5}, // D1
    {"Undefined", 0, NULL, 0}, // D2
    {"Undefined", 0, NULL, 0}, // D3
    {"Undefined", 0, NULL, 0}, // D4
    {"CMP zp, X", 2, NULL, 4}, // D5
    {"DEC zp, X", 2, NULL, 6}, // D6
    {"Undefined", 0, NULL, 0}, // D7
    {"CLD impl", 1, Execute_CLD, 2}, // D8
    {"CMP abs, Y", 3, NULL, 4}, // D9
    {"Undefined", 0, NULL, 0}, // DA
    {"Undefined", 0, NULL, 0}, // DB
    {"Undefined", 0, NULL, 0}, // DC
    {"CMP abs, X", 3, NULL, 4}, // DD
    {"DEC abs, X", 3, NULL, 7}, // DE
    {"Undefined", 0, NULL, 0}, // DF

    /* 0xE0 - 0xEF */
    {"CPX #", 2, Execute_CPX_IMM, 2}, // E0
    {"SBC X, ind", 2, NULL, 6}, // E1
    {"Undefined", 0, NULL, 0}, // E2
    {"Undefined", 0, NULL, 0}, // E3
    {"CPX zp", 2, NULL, 3}, // E4
    {"SBC zp", 2, NULL, 3}, // E5
    {"INC zp", 2, NULL, 5}, // E6
    {"Undefined", 0, NULL, 0}, // E7
    {"INX impl", 1, NULL, 2}, // E8
    {"SBC #", 2, NULL, 2}, // E9
    {"NOP impl", 1, Execute_NOP, 2}, // EA
    {"Undefined", 0, NULL, 0}, // EB
    {"CPX abs", 3, NULL, 4}, // EC
    {"SBC abs", 3, NULL, 4}, // ED
    {"INC abs", 3, NULL, 6}, // EE
    {"Undefined", 0, NULL, 0}, // EF

    /* 0xF0 - 0xFF */
    {"BEQ rel", 2, Execute_BEQ, 2}, // F0
    {"SBC ind, Y", 2, NULL, 5}, // F1
    {"Undefined", 0, NULL, 0}, // F2
    {"Undefined", 0, NULL, 0}, // F3
    {"Undefined", 0, NULL, 0}, // F4
    {"SBC zp, X", 2, NULL, 4}, // F5
    {"INC zp, X", 2, NULL, 6}, // F6
    {"Undefined", 0, NULL, 0}, // F7
    {"SED impl", 1, NULL, 2}, // F8
    {"SBC abs, Y", 3, NULL, 4}, // F9
    {"Undefined", 0, NULL, 0}, // FA
    {"Undefined", 0, NULL, 0}, // FB
    {"Undefined", 0, NULL, 0}, // FC
    {"SBC abs, X", 3, NULL, 4}, // FD
    {"INC abs, X", 3, NULL, 7}, // FE
    {"Undefined", 0, NULL, 0}, // FF
};