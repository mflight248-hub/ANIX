//Get ready to see my kernel

void kernel_main(void){
    volatile unsigned short* video_memory = (volatile unsigned short*) 0xB8000;
    const char *message = "Hello, world!";
    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i] = 0x0F00 | message[i];
    }
}
