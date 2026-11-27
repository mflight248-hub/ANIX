#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "x86.h"
#include "vga.h"
static unsigned char keymap[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', /* 0 - 14 */
  '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',       /* 15 - 28 */
    0,  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',            /* 29 - 41 */
    0,  '#', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',   0,             /* 42 - 54 */
   '*',   0, ' ',   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,             /* 55 - 67 */
    0,    0,   0,   0,   0,   0, '-',   0,   0,   0, '+',   0,   0,             /* 68 - 80 */
    0,    0,   0,   0,   0,   0, '\\'                                           
};
static int cursor_x = 2;
static int cursor_y = 1;

void putch(char c) {
    if (c == '\n') {
        cursor_x = 2;
        cursor_y++;
        print_char('$', 0, cursor_y);
    } else if (c == '\b') {
        if (cursor_x > 2) {
            cursor_x--;
            print_char(' ', cursor_x, cursor_y);
        }
    } else {
        print_char(c, cursor_x, cursor_y);
        cursor_x++;
    }
}
void keyboard_handler(void) {
  if (inb(0x64) & 1) {
    unsigned char scancode;
    scancode = inb(0x60);
    if (scancode & 0x80) {

    } else {
      putch(keymap[scancode]);
    }
  }
}
#endif