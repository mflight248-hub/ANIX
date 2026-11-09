#ifndef X86_H
#define X86_H

#include "types.h"

// Reads a byte from the specified I/O port
static inline uchar inb(ushort port) {
    uchar data;
    __asm__ volatile("inb %1, %0" : "=a"(data) : "d"(port));
    return data;
}

#endif
