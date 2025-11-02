#include "../include/functions.h"
#include <limits.h>
#include <ctype.h>

ReturnCode toDecSys(char *str, int *res, const int base) {
    if (!str || !res) {
        return NULL_POINTER;
    }

    if (base < 2 || base > 36) {
        return INVALID_DATA;
    }

    char * ptr = str;
    bool isNegative = false;

    if (str[0] == '-') {
        isNegative = true;
        ++ptr;
    }

    while (*ptr) {

        if (*res >= LONG_MAX / base) {
            return OVERFLOW;
        }

        if (!isalnum(*ptr)) {
            return INVALID_DATA;
        }

        if (isdigit(*ptr)) {
            *res = *res * (base) + (*ptr - '0');
        }

        if (isalpha(*ptr)) {
            *res = *res * (base) + (toupper(*ptr) - 'A' + 10);
        }
        ++ptr;
    }

    if (isNegative) {*res *= -1;}
    return OK;     

}