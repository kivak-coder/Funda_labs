#include "../include/functions.h"
#include <ctype.h>
#include <limits.h>

ReturnCode toDec(long int *num, char *str, const int *base){
    char * p = str;

    while (*p) { 
        if (*num > LLONG_MAX / *base) {
            return OVERFLOW;
        }
        if (isdigit(*p)) {
            *num = *num * (*base) + (*p - '0');
        }
        if (isalpha(*p)) {
            *num = *num * (*base) + (*p - 'A' + 10);
        } 
        else {
            return WRONG_SYMBOL;
        }
        ++p;
    }
    return OK;
}