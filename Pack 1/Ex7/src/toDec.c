#include "../include/functions.h"
#include <ctype.h>
#include <limits.h>

ReturnCode toDec(long int *num, char *str, const int *base){
    char * p = str;
    while (*p) { 
        if (*num >= LONG_MAX / *base) {
            return OVERFLOW;
        }
        if (isdigit(*p)) {
            *num = *num * (*base) + (*p - '0');
        }
        if (isalpha(*p)) {
            *num = *num * (*base) + (toupper(*p) - 'A' + 10);
        }
        ++p;
    }
    if (str[0] == '-') {
        *num *= (-1);
    }
    return OK;
}