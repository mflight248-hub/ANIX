#include "vga.h"
#include "x86.h"
#include "keyboard.h"

void kernel_main(void) {
    __asm__ volatile ("cli"); 
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
    while (1) {
        keyboard_handler();
    }
}
