#ifndef VGA_H
#define VGA_H
#include "types.h"
static volatile unsigned short *video_memory = (volatile unsigned short*) 0xB8000;
static inline void print_char(char letter, int column, int row) {
    if (column < 0 || column >= 80 || row < 0 || row >= 25) {
        return;
    }
    
    int spot = (row * 80) + column;
    video_memory[spot] = letter | 0x0F00;
}

#endif // VGA_H
