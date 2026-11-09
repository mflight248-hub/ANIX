#include "types.h"
#include "x86.h"
#include "defs.h"
#include "keyboard.h"
#include "vga.h"

int kbdgetc(void)
{
  static uint shift;
  static uchar *charcode[4] = {
    normalmap, shiftmap, ctlmap, ctlmap
  };
  uint st, data;
  int c;

  st = inb(KBSTATP);
  if((st & KBS_DIB) == 0)
    return -1;
  data = inb(KBDATAP);

  if(data == 0xE0){
    shift |= E0ESC;
    return 0;
  } else if(data & 0x80){
    data = (data & 0x7F) & 0x7F;
    if(shiftcode[data]){
      shift &= ~(shiftcode[data]);
    } else if(shift & E0ESC){
      shift &= ~E0ESC;
    }
    return 0;
  } else if(shift & E0ESC){
    data |= 0x80;
    shift &= ~E0ESC;
  }

  if(shiftcode[data]){
    shift |= shiftcode[data];
    return 0;
  }
  if(togglecode[data]){
    shift ^= togglecode[data];
    return 0;
  }

  c = charcode[shift & (SHIFT|CTL)][data];
  if(shift & CAPSLOCK){
    if('a' <= c && c <= 'z')
      c += 'A' - 'a';
    else if('A' <= c && c <= 'Z')
      c += 'a' - 'A';
  }
  return c;
}

static int kbd_col = 0;

void keyboard_intr_handler(void) {
    int c = kbdgetc();
    
    if(c > 0) {
        if (c == '\b') {
            if (kbd_col > 0) {
                kbd_col--;
                print_char(' ', kbd_col, 1);
            }
        } 
        else if (c >= ' ' && c <= '~') {
            print_char((char)c, kbd_col, 1);
            kbd_col++;
            if (kbd_col >= 80) kbd_col = 0;
        }
    }
}
