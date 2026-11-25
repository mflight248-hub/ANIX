#ifndef KEYBOARD_H
#define KEYBOARD_H
static unsigned char keymap[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', /* 0 - 14 */
  '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',       /* 15 - 28 */
    0,  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',            /* 29 - 41 */
    0,  '#', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',   0,             /* 42 - 54 */
   '*',   0, ' ',   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,             /* 55 - 67 */
    0,    0,   0,   0,   0,   0, '-',   0,   0,   0, '+',   0,   0,             /* 68 - 80 */
    0,    0,   0,   0,   0,   0, '\\'                                           
};
void keyboard_handler(void) {
  if (inportb(0x64) & 1) {
    unsigned char scancode;
    scancode = inportb(0x60);
    if (scancode & 0x80) {

    } else {
      putch(keymap[scancode]);
    }
  }
}
void keyboard_install() {
    irq_install_handler(1, keyboard_handler);
}

#endif