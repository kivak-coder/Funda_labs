#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>



typedef enum ReturnCode {
    OK,
    NO_ROMANIAN,
    NULL_POINTER,
    MEMORY_ALLOCATION_ERROR,
    INVALID_DATA,
    OVERFLOW,
} ReturnCode;

#define CAPACITY 20

ReturnCode RomanianNums(int * n, char * str);