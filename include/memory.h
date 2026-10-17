#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE 0x10000

typedef struct{
    uint8_t data[MEMORY_SIZE];
} Memory;

Memory *Create_Memory(void);
void Destroy_Memory(Memory *mem);

void Load_Memory(Memory *mem, const char *filename, uint16_t address);


uint8_t Read_Memory(const Memory *mem, uint16_t address);
void Write_Memory(Memory *mem, uint16_t address, uint8_t value);

#endif