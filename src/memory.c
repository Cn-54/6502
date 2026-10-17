#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

Memory *Create_Memory(void){
    Memory *mem = calloc(1, sizeof *mem);

    return mem;
}

void Destroy_Memory(Memory *mem){
    free(mem);
}

void Load_Memory(Memory *mem, const char *filename, uint16_t address){
    FILE *file = fopen(filename, "rb");

    if (file == NULL){
        printf(" [!] error loading code");
        return;
    }

    uint8_t byte;

    while (fread(&byte, 1, 1, file) == 1) {
        Write_Memory(mem, address, byte);
        address++;
    }

    fclose(file);
}

uint8_t Read_Memory(const Memory *mem, uint16_t address){
    if (mem == NULL){
        return 0;
    }

    return mem->data[address];
}

void Write_Memory(Memory *mem, uint16_t address, uint8_t value){
    if (mem == NULL){
        return;
    }

    mem->data[address] = value;
}
