#include "BinaryConversion.h"

#define MAX_SIZE 128
#define CHAR_BIT_SIZE 8

void main() {
    
    printf("Convert string to binary: ");

    char UserInput[MAX_SIZE];                                   // 
                                                                //
    if (fgets(UserInput, sizeof(UserInput), stdin) != NULL) {   // Get user input
        size_t len = strlen(UserInput);                         // 
        if (len > 0 && UserInput[len - 1] == '\n') {            // 
            UserInput[len - 1] = '\0';                          //
        }                                                       //
    }                                                           //
                                                                //

    int **buffer = (int **)calloc(strlen(UserInput), sizeof(char)); // Allocate memory to convert string

    StringToBinary(UserInput, strlen(UserInput), buffer, CHAR_BIT_SIZE); // Convert string to binary

    PrintBinaryString(buffer, strlen(UserInput), CHAR_BIT_SIZE); // Print the converted string

    main(); // Loop
}
