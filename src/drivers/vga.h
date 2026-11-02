#ifndef VGA_H
#define VGA_H
#include <stdint.h>

volatile unsigned short *video_memory = (volatile unsigned short*) 0xB8000;

void print_char(char letter, int column, int row){
    int spot = (row * 80) + column;

    video_memory[spot] = letter | 0x0F00;
}
#endif //VGA_H

/*I believe that people can have the simplisity of the early times where the Internet wasn't filled with all this junk*/

//YAHOO!