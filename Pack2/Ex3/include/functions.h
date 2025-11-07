#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

typedef enum ReturnCode {
    OK = 0,
    NO_ROMAN = -1,
    NULL_POINTER = -2,
    MEMORY_ALLOCATION_ERROR = -3,
    INVALID_DATA = -4,
    OVERFLOW = -5,
    WRITE_ERROR = -6,
    INVALID_SPECIFIER = -7,
} ReturnCode;

#define CAPACITY 20

ReturnCode RomanNums(int * n, char * str);
ReturnCode Zeckendorf(unsigned int a, char * str);
ReturnCode toNSys(int num, char * str, const int base, bool up);
ReturnCode toDecSys(char * str, const int base, char * resStr);
ReturnCode memDump(void * data, size_t size, char * resStr);
void reverseString(char *str);
ReturnCode overprint(void * stream, const char * format, va_list* arg, bool inString);
int oversprintf(char * string, const char * format, ...);
int overfprintf(FILE * file, const char * format, ...);
