#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
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

ReturnCode RomanNums(int * n, char * str);
ReturnCode Zeckendorf(unsigned int a, char * str);
ReturnCode toNSys(int num, char * str, const int base, bool up);
ReturnCode toDecSys(char * str, const int base, char * resStr);
void reverseString(char *str);
ReturnCode overprint(void * stream, const char * format, va_list* arg, bool inString);
int oversprintf(FILE * string, const char * format, ...);
int overfprintf(FILE * string, const char * format, ...);
