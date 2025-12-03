#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


typedef enum ReturnCode {
    INVALID_DATA = -1,
    NULL_POINTER = -2,
    OVERFLOW = -3,
    READ_ERROR = -4,
    OK = 0,
} ReturnCode;

typedef enum RomanNum {
    I = 1, 
    V = 5, 
    X = 10, 
    L = 50, 
    C = 100,
    D = 500,
    M = 1000
} RomanNum;

ReturnCode Roman(char * str, int * res);
ReturnCode toDecSys(char * str, int * res, const int base);
ReturnCode Zeckendorf(char * str, int * res);

ReturnCode validateZeckendorf(char * str);
ReturnCode validateRoman(char * str);
bool isRoman(char c);
ReturnCode validateNumInBase(char * str, const int base);
int overfscanf(FILE * file, const char * format, ...);
int oversscanf(char * string, const char *format, ...);



