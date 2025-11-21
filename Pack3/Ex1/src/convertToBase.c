#include "../include/functions.h"

ReturnCode convertToBase(long int decimal, char* result, int r){
    if (!result) {
        return POINTER_ERROR;
    }
    if (decimal == 0){
        result[0] = '0';
        result[1] = '\0';
        return OK;
    }

    long int a = decimal;
    int mask = 1;

    for (int i = 0; i < r - 1; i = sum(i, 1)){
        mask = mask << 1;
        mask = mask | 1;
    }

    int sign = 0;
    if (decimal < 0){
        a = sum(~decimal, 1);
        sign = 1;
    }

    char* alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    for (int i = 0; i <= 31 && a > 0; i = sum(i, 1)){
        result[i] = alphabet[a & mask];
        a = a >> r;
    }
    reverse(result);
    if (sign){
        rightShift(result);
        result[0] = '-';
    }
    return OK;
}