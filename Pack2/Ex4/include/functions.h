#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>


typedef enum ReturnCode {
    INVALID_DATA,
    NULL_POINTER,
    OVERFLOW,
    OK,
} ReturnCode;

#define CAPACITY 20

ReturnCode Romanian(char * str, int * res);
ReturnCode toDecSys(char * str, int * res, const int base);
ReturnCode Zeckendorf(char * str, int * res);