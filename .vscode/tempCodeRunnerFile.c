#include <stdio.h>

int main() {
    char email[100];
    FILE *fptr; // Pointer to a file

    printf("Type your Email\n");
    scanf("%s", email);

    // Open file for writing ("w" will overwrite existing content, "a" will append to the end)
    fptr = fopen("email.txt", "w");

    // Check if the file opened successfully
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the string to the file
    fprintf(fptr, "%s", email);

    // Always close the file to save changes and free memory
    fclose(fptr);

    printf("Your email has been saved to email.txt\n");

    return 0;
}
