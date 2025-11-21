#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


typedef enum ReturnCode{
    OK,
    BAD_INPUT,
    OVERFLOW,
    MALLOC_ERROR,
    POINTER_ERROR,
    WRONG_ARGUMENTS,
    BAD_BASE
} ReturnCode;


ReturnCode convertToBase(long int decimal, char* result, int r);
int sum(int a, int b);
int sub(int a, int b);
int strLen(const char *str);
ReturnCode reverse(char* array);
ReturnCode rightShift(char* array);

#endif