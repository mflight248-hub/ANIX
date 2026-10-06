//Get ready to see my kernel

void kernel_main(void){
    volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;
    const char *ascii_art ="\\/\\/ E |_ ( 0 /\\/\\ E   T 0  A |\\| I X  ! ! !";

    for (int i = 0; ascii_art[i] != '\0'; i++) {
        video_memory[i] = 0x0F00 | ascii_art[i];
    }
    for(;;);
}
