#include "vga.h"
#include "x86.h"

struct idt_entry {
    unsigned short low_offset;
    unsigned short selector;
    unsigned char  always0;
    unsigned char  flags;
    unsigned short high_offset;
} __attribute__((packed));

struct idt_ptr {
    unsigned short limit;
    unsigned int   base;
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr idtp;

extern void keyboard_isr_asm_stub(void);

void set_idt_gate(unsigned char num, unsigned int base) {
    idt[num].low_offset  = (base & 0xFFFF);
    idt[num].selector    = 0x08;
    idt[num].always0     = 0;
    idt[num].flags       = 0x8E;
    idt[num].high_offset = ((base >> 16) & 0xFFFF);
}

void init_idt(void) {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base  = (unsigned int)&idt;

    for(int i = 0; i < 256; i++) {
        set_idt_gate(i, 0);
    }

    set_idt_gate(33, (unsigned int)keyboard_isr_asm_stub);

    __asm__ volatile("lidt %0" : : "m"(idtp));
}

void kernel_main(void) {
    print_char('\\', 0, 0); print_char('/',  1, 0); print_char('\\', 2, 0); print_char('/',  3, 0);
    print_char(' ',  4, 0); print_char('E',  5, 0); print_char(' ',  6, 0); print_char('|',  7, 0);
    print_char('_',  8, 0); print_char(' ',  9, 0); print_char('(',  10, 0); print_char(' ',  11, 0);
    print_char('0',  12, 0); print_char(' ',  13, 0); print_char('/',  14, 0); print_char('\\', 15, 0);
    print_char('/',  16, 0); print_char('\\', 17, 0); print_char('E',  18, 0); print_char(' ',  19, 0);
    print_char(' ',  20, 0); print_char(' ',  21, 0); print_char('T',  22, 0); print_char(' ',  23, 0);
    print_char('0',  24, 0); print_char(' ',  25, 0); print_char(' ',  26, 0); print_char(' ',  27, 0);
    print_char(' ',  28, 0); print_char('/',  29, 0); print_char('-',  30, 0); print_char('\\', 31, 0);
    print_char(' ',  32, 0); print_char('|',  33, 0); print_char('\\', 34, 0); print_char('|',  35, 0);
    print_char(' ',  36, 0); print_char('|',  37, 0); print_char(' ',  38, 0); print_char('\\', 39, 0);
    print_char('/',  40, 0); print_char('X',  41, 0);

    init_idt();

    __asm__ volatile("sti");
    while(1);
}
