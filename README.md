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

## Documentation


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
