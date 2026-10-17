

#include <stdlib.h>
#include "instructions.h"

const struct cpu_ins instructions[256] = {
    /* 0x00 - 0x0F */
    {"BRK impl",     1, Execute_BRK}, // 00
    {"ORA X, ind",   2, NULL}, // 01
    {"Undefined",    0, NULL}, // 02
    {"Undefined",    0, NULL}, // 03
    {"Undefined",    0, NULL}, // 04
    {"ORA zp",       2, NULL}, // 05
    {"ASL zp",       2, NULL}, // 06
    {"Undefined",    0, NULL}, // 07
    {"PHP impl",     1, Execute_PHP}, // 08
    {"ORA #",        2, NULL}, // 09
    {"ASL A",        1, NULL}, // 0A
    {"Undefined",    0, NULL}, // 0B
    {"Undefined",    0, NULL}, // 0C
    {"ORA abs",      3, NULL}, // 0D
    {"ASL abs",      3, NULL}, // 0E
    {"Undefined",    0, NULL}, // 0F

    /* 0x10 - 0x1F */
    {"BPL rel",      2, NULL}, // 10
    {"ORA ind, Y",   2, NULL}, // 11
    {"Undefined",    0, NULL}, // 12
    {"Undefined",    0, NULL}, // 13
    {"Undefined",    0, NULL}, // 14
    {"ORA zp, X",    2, NULL}, // 15
    {"ASL zp, X",    2, NULL}, // 16
    {"Undefined",    0, NULL}, // 17
    {"CLC impl",     1, NULL}, // 18
    {"ORA abs, Y",   3, NULL}, // 19
    {"Undefined",    0, NULL}, // 1A
    {"Undefined",    0, NULL}, // 1B
    {"Undefined",    0, NULL}, // 1C
    {"ORA abs, X",   3, NULL}, // 1D
    {"ASL abs, X",   3, NULL}, // 1E
    {"Undefined",    0, NULL}, // 1F

    /* 0x20 - 0x2F */
    {"JSR abs",      3, NULL}, // 20
    {"AND X, ind",   2, NULL}, // 21
    {"Undefined",    0, NULL}, // 22
    {"Undefined",    0, NULL}, // 23
    {"BIT zp",       2, NULL}, // 24
    {"AND zp",       2, NULL}, // 25
    {"ROL zp",       2, NULL}, // 26
    {"Undefined",    0, NULL}, // 27
    {"PLP impl",     1, NULL}, // 28
    {"AND #",        2, NULL}, // 29
    {"ROL A",        1, NULL}, // 2A
    {"Undefined",    0, NULL}, // 2B
    {"BIT abs",      3, NULL}, // 2C
    {"AND abs",      3, NULL}, // 2D
    {"ROL abs",      3, NULL}, // 2E
    {"Undefined",    0, NULL}, // 2F

    /* 0x30 - 0x3F */
    {"BMI rel",      2, NULL}, // 30
    {"AND ind, Y",   2, NULL}, // 31
    {"Undefined",    0, NULL}, // 32
    {"Undefined",    0, NULL}, // 33
    {"Undefined",    0, NULL}, // 34
    {"AND zp, X",    2, NULL}, // 35
    {"ROL zp, X",    2, NULL}, // 36
    {"Undefined",    0, NULL}, // 37
    {"SEC impl",     1, NULL}, // 38
    {"AND abs, Y",   3, NULL}, // 39
    {"Undefined",    0, NULL}, // 3A
    {"Undefined",    0, NULL}, // 3B
    {"Undefined",    0, NULL}, // 3C
    {"AND abs, X",   3, NULL}, // 3D
    {"ROL abs, X",   3, NULL}, // 3E
    {"Undefined",    0, NULL}, // 3F

    /* 0x40 - 0x4F */
    {"RTI impl",     1, NULL}, // 40
    {"EOR X, ind",   2, NULL}, // 41
    {"Undefined",    0, NULL}, // 42
    {"Undefined",    0, NULL}, // 43
    {"Undefined",    0, NULL}, // 44
    {"EOR zp",       2, NULL}, // 45
    {"LSR zp",       2, NULL}, // 46
    {"Undefined",    0, NULL}, // 47
    {"PHA impl",     1, NULL}, // 48
    {"EOR #",        2, NULL}, // 49
    {"LSR A",        1, NULL}, // 4A
    {"Undefined",    0, NULL}, // 4B
    {"JMP abs",      3, NULL}, // 4C
    {"EOR abs",      3, NULL}, // 4D
    {"LSR abs",      3, NULL}, // 4E
    {"Undefined",    0, NULL}, // 4F

    /* 0x50 - 0x5F */
    {"BVC rel",      2, NULL}, // 50
    {"EOR ind, Y",   2, NULL}, // 51
    {"Undefined",    0, NULL}, // 52
    {"Undefined",    0, NULL}, // 53
    {"Undefined",    0, NULL}, // 54
    {"EOR zp, X",    2, NULL}, // 55
    {"LSR zp, X",    2, NULL}, // 56
    {"Undefined",    0, NULL}, // 57
    {"CLI impl",     1, NULL}, // 58
    {"EOR abs, Y",   3, NULL}, // 59
    {"Undefined",    0, NULL}, // 5A
    {"Undefined",    0, NULL}, // 5B
    {"Undefined",    0, NULL}, // 5C
    {"EOR abs, X",   3, NULL}, // 5D
    {"LSR abs, X",   3, NULL}, // 5E
    {"Undefined",    0, NULL}, // 5F

    /* 0x60 - 0x6F */
    {"RTS impl",     1, NULL}, // 60
    {"ADC X, ind",   2, NULL}, // 61
    {"Undefined",    0, NULL}, // 62
    {"Undefined",    0, NULL}, // 63
    {"Undefined",    0, NULL}, // 64
    {"ADC zp",       2, NULL}, // 65
    {"ROR zp",       2, NULL}, // 66
    {"Undefined",    0, NULL}, // 67
    {"PLA impl",     1, NULL}, // 68
    {"ADC #",        2, NULL}, // 69
    {"ROR A",        1, NULL}, // 6A
    {"Undefined",    0, NULL}, // 6B
    {"JMP ind",      3, NULL}, // 6C
    {"ADC abs",      3, NULL}, // 6D
    {"ROR abs",      3, NULL}, // 6E
    {"Undefined",    0, NULL}, // 6F

    /* 0x70 - 0x7F */
    {"BVS rel",      2, NULL}, // 70
    {"ADC ind, Y",   2, NULL}, // 71
    {"Undefined",    0, NULL}, // 72
    {"Undefined",    0, NULL}, // 73
    {"Undefined",    0, NULL}, // 74
    {"ADC zp, X",    2, NULL}, // 75
    {"ROR zp, X",    2, NULL}, // 76
    {"Undefined",    0, NULL}, // 77
    {"SEI impl",     1, NULL}, // 78
    {"ADC abs, Y",   3, NULL}, // 79
    {"Undefined",    0, NULL}, // 7A
    {"Undefined",    0, NULL}, // 7B
    {"Undefined",    0, NULL}, // 7C
    {"ADC abs, X",   3, NULL}, // 7D
    {"ROR abs, X",   3, NULL}, // 7E
    {"Undefined",    0, NULL}, // 7F

    /* 0x80 - 0x8F */
    {"Undefined",    0, NULL}, // 80
    {"STA X, ind",   2, NULL}, // 81
    {"Undefined",    0, NULL}, // 82
    {"Undefined",    0, NULL}, // 83
    {"STY zp",       2, NULL}, // 84
    {"STA zp",       2, NULL}, // 85
    {"STX zp",       2, NULL}, // 86
    {"Undefined",    0, NULL}, // 87
    {"DEY impl",     1, NULL}, // 88
    {"Undefined",    0, NULL}, // 89
    {"TXA impl",     1, NULL}, // 8A
    {"Undefined",    0, NULL}, // 8B
    {"STY abs",      3, NULL}, // 8C
    {"STA abs",      3, NULL}, // 8D
    {"STX abs",      3, NULL}, // 8E
    {"Undefined",    0, NULL}, // 8F

    /* 0x90 - 0x9F */
    {"BCC rel",      2, NULL}, // 90
    {"STA ind, Y",   2, NULL}, // 91
    {"Undefined",    0, NULL}, // 92
    {"Undefined",    0, NULL}, // 93
    {"STY zp, X",    2, NULL}, // 94
    {"STA zp, X",    2, NULL}, // 95
    {"STX zp, Y",    2, NULL}, // 96
    {"Undefined",    0, NULL}, // 97
    {"TYA impl",     1, NULL}, // 98
    {"STA abs, Y",   3, NULL}, // 99
    {"TXS impl",     1, NULL}, // 9A
    {"Undefined",    0, NULL}, // 9B
    {"Undefined",    0, NULL}, // 9C
    {"STA abs, X",   3, NULL}, // 9D
    {"Undefined",    0, NULL}, // 9E
    {"Undefined",    0, NULL}, // 9F

    /* 0xA0 - 0xAF */
    {"LDY #",        2, NULL}, // A0
    {"LDA X, ind",   2, NULL}, // A1
    {"LDX #",        2, NULL}, // A2
    {"Undefined",    0, NULL}, // A3
    {"LDY zp",       2, NULL}, // A4
    {"LDA zp",       2, NULL}, // A5
    {"LDX zp",       2, NULL}, // A6
    {"Undefined",    0, NULL}, // A7
    {"TAY impl",     1, NULL}, // A8
    {"LDA #",        2, NULL}, // A9
    {"TAX impl",     1, NULL}, // AA
    {"Undefined",    0, NULL}, // AB
    {"LDY abs",      3, NULL}, // AC
    {"LDA abs",      3, NULL}, // AD
    {"LDX abs",      3, NULL}, // AE
    {"Undefined",    0, NULL}, // AF

    /* 0xB0 - 0xBF */
    {"BCS rel",      2, NULL}, // B0
    {"LDA ind, Y",   2, NULL}, // B1
    {"Undefined",    0, NULL}, // B2
    {"Undefined",    0, NULL}, // B3
    {"LDY zp, X",    2, NULL}, // B4
    {"LDA zp, X",    2, NULL}, // B5
    {"LDX zp, Y",    2, NULL}, // B6
    {"Undefined",    0, NULL}, // B7
    {"CLV impl",     1, NULL}, // B8
    {"LDA abs, Y",   3, NULL}, // B9
    {"TSX impl",     1, NULL}, // BA
    {"Undefined",    0, NULL}, // BB
    {"LDY abs, X",   3, NULL}, // BC
    {"LDA abs, X",   3, NULL}, // BD
    {"LDX abs, Y",   3, NULL}, // BE
    {"Undefined",    0, NULL}, // BF

    /* 0xC0 - 0xCF */
    {"CPY #",        2, NULL}, // C0
    {"CMP X, ind",   2, NULL}, // C1
    {"Undefined",    0, NULL}, // C2
    {"Undefined",    0, NULL}, // C3
    {"CPY zp",       2, NULL}, // C4
    {"CMP zp",       2, NULL}, // C5
    {"DEC zp",       2, NULL}, // C6
    {"Undefined",    0, NULL}, // C7
    {"INY impl",     1, NULL}, // C8
    {"CMP #",        2, NULL}, // C9
    {"DEX impl",     1, NULL}, // CA
    {"Undefined",    0, NULL}, // CB
    {"CPY abs",      3, NULL}, // CC
    {"CMP abs",      3, NULL}, // CD
    {"DEC abs",      3, NULL}, // CE
    {"Undefined",    0, NULL}, // CF

    /* 0xD0 - 0xDF */
    {"BNE rel",      2, NULL}, // D0
    {"CMP ind, Y",   2, NULL}, // D1
    {"Undefined",    0, NULL}, // D2
    {"Undefined",    0, NULL}, // D3
    {"Undefined",    0, NULL}, // D4
    {"CMP zp, X",    2, NULL}, // D5
    {"DEC zp, X",    2, NULL}, // D6
    {"Undefined",    0, NULL}, // D7
    {"CLD impl",     1, NULL}, // D8
    {"CMP abs, Y",   3, NULL}, // D9
    {"Undefined",    0, NULL}, // DA
    {"Undefined",    0, NULL}, // DB
    {"Undefined",    0, NULL}, // DC
    {"CMP abs, X",   3, NULL}, // DD
    {"DEC abs, X",   3, NULL}, // DE
    {"Undefined",    0, NULL}, // DF

    /* 0xE0 - 0xEF */
    {"CPX #",        2, NULL}, // E0
    {"SBC X, ind",   2, NULL}, // E1
    {"Undefined",    0, NULL}, // E2
    {"Undefined",    0, NULL}, // E3
    {"CPX zp",       2, NULL}, // E4
    {"SBC zp",       2, NULL}, // E5
    {"INC zp",       2, NULL}, // E6
    {"Undefined",    0, NULL}, // E7
    {"INX impl",     1, NULL}, // E8
    {"SBC #",        2, NULL}, // E9
    {"NOP impl",     1, NULL}, // EA
    {"Undefined",    0, NULL}, // EB
    {"CPX abs",      3, NULL}, // EC
    {"SBC abs",      3, NULL}, // ED
    {"INC abs",      3, NULL}, // EE
    {"Undefined",    0, NULL}, // EF

    /* 0xF0 - 0xFF */
    {"BEQ rel",      2, NULL}, // F0
    {"SBC ind, Y",   2, NULL}, // F1
    {"Undefined",    0, NULL}, // F2
    {"Undefined",    0, NULL}, // F3
    {"Undefined",    0, NULL}, // F4
    {"SBC zp, X",    2, NULL}, // F5
    {"INC zp, X",    2, NULL}, // F6
    {"Undefined",    0, NULL}, // F7
    {"SED impl",     1, NULL}, // F8
    {"SBC abs, Y",   3, NULL}, // F9
    {"Undefined",    0, NULL}, // FA
    {"Undefined",    0, NULL}, // FB
    {"Undefined",    0, NULL}, // FC
    {"SBC abs, X",   3, NULL}, // FD
    {"INC abs, X",   3, NULL}, // FE
    {"Undefined",    0, NULL}, // FF
};