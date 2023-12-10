//
//  BinaryConversion.h
//
//  Copyright (c) 2023 Yurtrimu. All rights reserved.
//  MIT License
//

#pragma once

#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *arr, size_t array_size);
void PrintBinaryString(int **arr, size_t strlen, size_t char_size);
void ReverseArray(int *arr, int *dest, size_t dest_size);
int *TrimBinary(int *b, size_t binary_size, size_t *return_size);
int IntFromBinary(int *b, size_t binary_size);
void IntToBinary(int n, int *dest, size_t dest_size);
char *IntToString(int *arr, size_t array_size);
void StringToInt(char *str, size_t strlen, int *dest, size_t dest_size);
void StringToBinary(char *str, size_t strlen, int **dest, size_t char_size);
char *StringFromBinary(int **binary, size_t binary_size, size_t char_size);