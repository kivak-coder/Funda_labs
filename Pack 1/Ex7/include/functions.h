#include <stdio.h>


typedef enum ReturnCode {
    OVERFLOW,
    WRONG_SYMBOL,
    NULL_POINTER,
    OK,
} ReturnCode;

ReturnCode toDec(long int * num, char * str, const int * base);
ReturnCode parseString(char * str, FILE * OutFi);
ReturnCode FindMinSys(char * str, int * base);