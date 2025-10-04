#include "../include/functions.h"
#include <ctype.h>

ReturnCode FindMinSys(char *str, int *base) {
    char * p = str;
    int digit = 0;

    while (*p) {
        if (isdigit(*p)) {
            digit = *p - '0';
        }
        if (isalpha(*p)) {
            digit = toupper(*p) - 'A' + 10;
        }
        
        if (digit > *base) {
            *base = digit;
        }
        ++p;
    }
    *base += 1;
    return OK;
}