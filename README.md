# BinaryConversion Library
A open, two-file library mainly used to convert and revert Strings Integers to Binary

The current functions are
```
void ReverseArray(int *arr, int *dest, size_t dest_size);
int *TrimBinary(int *b, size_t binary_size, size_t *return_size);
int IntFromBinary(int *b, size_t binary_size);
void IntToBinary(int n, int *dest, size_t dest_size);
void StringToInt(char *str, size_t strlen, int *dest, size_t dest_size);
char *StringFromInt(int *arr, size_t array_size);
void StringToBinary(char *str, size_t strlen, int **dest, size_t char_size);
void StringFromBinary(int **binary, size_t binary_size, char *dest, size_t char_size);
void PrintBinaryString(int **arr, size_t strlen, size_t char_size);
void PrintArray(int *arr, size_t array_size);
```

## Examples && Documentation


### ReverseArray
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 8

void main() {
    
    int Array[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 1};

    PrintArray(Array, ARRAY_SIZE); // Output: "[0, 0, 0, 0, 0, 0, 0, 1]"

    ReverseArray(&Array, &Array, ARRAY_SIZE); // Reverses the int array"

    PrintArray(Array, ARRAY_SIZE);// Output: "[1, 0, 0, 0, 0, 0, 0, 0]"
}
```

### TrimBinary
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 8

void main() {
    
    int Array[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 1, 0};

    PrintArray(Array, ARRAY_SIZE); // Output: "[0, 0, 0, 0, 0, 0, 1, 0]"

    int return_size = 0; // Return size
    int *TrimmedArray = TrimBinary(&Array, ARRAY_SIZE, &return_size); // Trims the unnecessary zeros in the binary"

    PrintArray(TrimmedArray, return_size);// Output: "[1, 0]"
}
```

### IntFromBinary
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 8

void main() {
    
    int BinaryArray[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 1, 0};

    PrintArray(BinaryArray, ARRAY_SIZE); // Output: "[0, 0, 0, 0, 0, 0, 1, 0]"

    int ConvertedBinary = IntFromBinary(BinaryArray, ARRAY_SIZE); // '00000001' as binary is '2' as decimal

    printf("%d\n", ConvertedBinary); // Output: "2"
}
```

### IntToBinary
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 8

void main() {

    int Decimal = 2;

    int *ConvertedDecimal = (int *)calloc(ARRAY_SIZE, sizeof(int)); // Allocate memory to the pointer
    IntToBinary(Decimal, ConvertedDecimal, ARRAY_SIZE); // '2' as decimal is '00000001' as binary

    PrintArray(ConvertedDecimal, ARRAY_SIZE); // Output: "[0, 0, 0, 0, 0, 0, 1, 0]"
}
```

### StringToInt
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 13

void main() {

    char Text[13] = "Hello World!";

    int *ASCIIArray = (int *)calloc(ARRAY_SIZE, sizeof(int)); // Allocate memory to the pointer
    StringToInt(&Text, ARRAY_SIZE, ASCIIArray, ARRAY_SIZE); // Converts string to ASCII Array

    PrintArray(ASCIIArray, ARRAY_SIZE); // Output: "[72,101,108,108,111,32,87,111,114,108,100,33]"
}
```

### StringFromInt
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 12

void main() {

    int ASCIIArray[12] = {72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100, 33};
    char *ConvertedASCII = StringFromInt(ASCIIArray, ARRAY_SIZE); // Converts the ASCII Array to string

    printf("%s\n", ConvertedASCII); // Output: "Hello World!"
}
```

### StringToBinary
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 12
#define CHAR_BIT_SIZE 8

void main() {
    
    char Text[ARRAY_SIZE] = "Hello World!";

    int **binary = NULL;
    binary = (int **)calloc(ARRAY_SIZE, sizeof(int));  // Allocate memory to the 'binary' variable's first pointer

    StringToBinary(&Text, ARRAY_SIZE, binary, CHAR_BIT_SIZE); // Convert string to Binary
    PrintBinaryString(binary, ARRAY_SIZE, CHAR_BIT_SIZE); // Output: "[01001000,01100101,01101100,01101100,01101111,00100000,01010111,01101111,01110010,01101100,01100100,00100001]"
}
```

### StringFromBinary
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 12
#define CHAR_BIT_SIZE 8

void main() {
    
    char Text[ARRAY_SIZE] = "Hello World!";

    int **binary = NULL;
    binary = (int **)calloc(ARRAY_SIZE, sizeof(int));  // Allocate memory to the 'binary' variable's first pointer

    StringToBinary(&Text, ARRAY_SIZE, binary, CHAR_BIT_SIZE); // Converts string to Binary
    PrintBinaryString(binary, ARRAY_SIZE, CHAR_BIT_SIZE); // Output: "[01001000,01100101,01101100,01101100,01101111,00100000,01010111,01101111,01110010,01101100,01100100,00100001]"

    char *ConvertedText = StringFromBinary(binary, ARRAY_SIZE, CHAR_BIT_SIZE); // Convert Binary to String
    printf("%s\n", ConvertedText); // Output: "Hello World!"
}
```

### PrintBinaryString
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 12
#define CHAR_BIT_SIZE 8

void main() {
    
    char Text[ARRAY_SIZE] = "Hello World!";

    int **binary = NULL;
    binary = (int **)calloc(ARRAY_SIZE, sizeof(int));  // Allocate memory to the 'binary' variable's first pointer

    StringToBinary(&Text, ARRAY_SIZE, binary, CHAR_BIT_SIZE); // Converts string to Binary
    PrintBinaryString(binary, ARRAY_SIZE, CHAR_BIT_SIZE); // Output: "[01001000,01100101,01101100,01101100,01101111,00100000,01010111,01101111,01110010,01101100,01100100,00100001]"
}
```

### PrintArray
```
#include "BinaryConversion.h"

#define ARRAY_SIZE 8

void main() {
    
    int Array[ARRAY_SIZE] = { 3, 1, 0, 0, 0, 0, 6, 9 };
    PrintArray(Array, ARRAY_SIZE); // Output: "[3,1,0,0,0,0,6,9]"
}
```
