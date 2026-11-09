struct rtcdate; 

// console.c - Crucial for printing text to the screen/VGA driver
void consoleinit(void);
void cprintf(char*, ...);
void panic(char*) __attribute__((noreturn));
// void print_char(char c, int x, int y);

// string.c - Essential for managing memory buffers and strings
int memcmp(const void*, const void*, uint);
void* memmove(void*, const void*, uint);
void* memset(void*, int, uint);
char* safestrcpy(char*, const char*, int);
int strlen(const char*);

#define NELEM(x) (sizeof(x)/sizeof((x)[0]))
