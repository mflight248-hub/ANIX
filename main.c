#include <stdio.h> 
#include <Windows.h>

int oofly; 

void numberInput(){ 
    printf("Hello, world!\n"); 
    Sleep(1000);
    printf("Type a number: \n"); 
    scanf("%d", &oofly); 
    Sleep(1000);
    printf("\rProcessing"); 
    fflush(stdout); 
    for (int i = 0; i < 3; i++) {
        Sleep(1000);
        printf("."); 
        fflush(stdout); 
    }
    printf("\n");
    
    printf("Your number is: %d\n", oofly); 
} 

int main(void){ 
    // Brand new, fully escaped ASCII art that strictly spells "Welcome to anix"
    printf("\033[36m _ _  _ ____ _    ____ ____ _  _ ____    ___ ____    ____ _  _ _ _  _ \n");
    printf("\033[34m | |  | |___ |    |    |  | |\\/| |___     |  |  |    |__| |\\ | |  \\/  \n");
    printf("\033[36m |_|\\/| |___ |___ |___ |__| |  | |___     |  |__|    |  | | \\| | _/\\_ \n");
    printf("\033[0m\n"); 

    Sleep(1000);
    numberInput(); // Run terminal input first!
    Sleep(1000);

    printf("So, you like the number %d?\n", oofly);  //shows if you like your number
    Sleep(1000);
    printf("Oh, Ok :)\n");
    Sleep(1000);
    return 0; 
}
//python, not python, not C, wait, C :)
