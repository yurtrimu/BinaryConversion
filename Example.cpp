#include "BinaryConversion.h"
#include <iostream>

#define MAX_SIZE 128
#define CHAR_BIT_SIZE 8

void main() {
    
    printf("Convert string to binary: ");

    char UserInput[MAX_SIZE];                                   // 
    std::cin >> UserInput;                                      // Get user input   

    int **buffer = (int **)calloc(strlen(UserInput), sizeof(char)); // Allocate memory to convert string

    StringToBinary(UserInput, strlen(UserInput), buffer, CHAR_BIT_SIZE); // Convert string to binary

    PrintBinaryString(buffer, strlen(UserInput), CHAR_BIT_SIZE); // Print the converted string

    main(); // Loop
}
