//
//  BinaryConversion.c
//
//  Copyright (c) 2023 Yurtrimu. All rights reserved.
//  MIT License
//

#include "BinaryConversion.h"

void ReverseArray(int *arr, int *dest, size_t dest_size) {
    for (int i = 0; i < (dest_size - (dest_size % 2)) / 2; i++) {
        dest[i] ^= dest[dest_size - i - 1];
        dest[dest_size - i - 1] ^= dest[i];
        dest[i] ^= dest[dest_size - i - 1];
    }
}

int *TrimBinary(int *b, size_t binary_size, size_t *return_size) {
    if (binary_size != 0) {
        size_t dest_size = binary_size;

        int index = 0;
        while (index < binary_size && b[index] == 0) {
            dest_size--;
            index++;
        }

        if (dest_size != 0) {
            int *result = (int *)malloc(dest_size * sizeof(int));

            if (result != NULL) {
                for (index = 0; index < dest_size; index++) {
                    if (index < dest_size) {
                        result[index] = b[index + (binary_size - dest_size)];
                    }
                    else {
                        printf("Out of bounds.\n");
                        return NULL;
                    }
                }

                *return_size = dest_size;

                return result;
            }
            else {
                printf("Memory allocation went wrong.\n");
                return NULL;
            }
        }
        else {
            printf("Destination size is 0.\n");
            return NULL;
        }
    }
    else {
        printf("Binary size is 0.\n");
        return NULL;
    }
}

int IntFromBinary(int *b, size_t binary_size) {
    int result = 0;

    for (int i = 0; i < binary_size; i++) {
        if (b[i] == 0) { continue; }

        result += (1 << ((int)binary_size - (i + 1)));
    }

    return result;
}

void IntToBinary(int n, int *dest, size_t dest_size) {
    memset(dest, 0, dest_size * sizeof(int));
    int count = 0;
    while (n > 0 && count >= 0 && count < dest_size) {
        int mod = n % 2;
        dest[count] = mod;
        n = (n - mod) / 2;
        count++;
    }

    ReverseArray(dest, dest, dest_size);
}

void StringToInt(char *str, size_t strlen, int *dest, size_t dest_size) {
    memset(dest, 0, dest_size * sizeof(int));

    for (int i = 0; i < strlen; i++) {
        dest[i] = (int)str[i];
    }
}

char *IntToString(int *arr, size_t array_size) {
    if (array_size != 0) {
        char *result = (char *)malloc((array_size + 1) * sizeof(char));

        if (result == NULL) {
            printf("Memory allocation went wrong.\n");
            return NULL;
        }

        for (int i = 0; i < array_size; i++) {
            result[i] = (char)arr[i];
        }

        result[array_size] = '\0';

        return result;
    }
    else {
        printf("Array size is 0.\n");
        return NULL;
    }
}

void StringToBinary(char *str, size_t strlen, int **dest, size_t char_size) {
    if (strlen > 0) {
        int *intstr = (int *)malloc(strlen * sizeof(int));

        if (intstr != NULL && char_size > 0 && dest != NULL) {
            StringToInt(str, strlen, intstr, strlen);

            for (int k = 0; k < strlen; k++) {
                dest[k] = (int *)malloc(char_size * sizeof(int));

                IntToBinary(intstr[k], dest[k], char_size); 
            }

            free(intstr);
        }
        else {
            printf("Memory allocation went wrong.\n");
            return;
        }
    }
    else {
        printf("String length is less than 0.\n");
        return;
    }
}

char *StringFromBinary(int **binary, size_t binary_size, size_t char_size) {
    if (binary_size != 0) {
        int *intstr = (int *)malloc(binary_size * sizeof(int));

        if (intstr == NULL) {
            printf("Memory allocation went wrong.\n");
            return NULL;
        }

        for (int k = 0; k < binary_size; k++) {
            intstr[k] = IntFromBinary(binary[k], char_size);
        }

        char *result = IntToString(intstr, binary_size);

        free(intstr);
        return *result;
    }
    else {
        printf("Binary size is 0.\n");
        return NULL;
    }
}

void PrintBinaryString(int **arr, size_t strlen, size_t char_size) {
    printf("[");
    for (int i = 0; i < strlen; i++) {
        for (int b = 0; b < char_size; b++) {
            printf("%d", arr[i][b]);
        }
        if (i < strlen - 1) {
            printf(",");
        }
        else {
            printf("]\n");
        }
    }
}

void PrintArray(int *arr, size_t array_size) {
    if (array_size >= 0) {
        printf("[%d", arr[0]);
        for (int i = 1; i < array_size; i++) {
            printf(",%d", arr[i]);
        }
        printf("]\n");
    }
    else {
        printf("Array size is less than or equal to 0.\n");
    }
}