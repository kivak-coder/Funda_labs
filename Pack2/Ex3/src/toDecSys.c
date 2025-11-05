#include "../include/functions.h"

ReturnCode toDecSys(char * str, const int base, char * resStr) {
    if (!str || !resStr) {
        return NULL_POINTER;
    }

    if (base < 2 || base > 36) {
        return INVALID_DATA;
    }

    char * ptr = str;
    char * resPtr = resStr;
    int res = 0;

    if (str[0] == '-') {
        *resPtr = '-';
        ++ptr;
        ++resPtr;
    }

    while (*ptr) {

        if (res >= LONG_MAX / base) {
            return OVERFLOW;
        }

        if (!isalnum(*ptr)) {
            return INVALID_DATA;
        }

        if (isdigit(*ptr)) {
            res = res * (base) + (*ptr - '0');
        }

        if (isalpha(*ptr)) {
            res = res * (base) + (toupper(*ptr) - 'A' + 10);
        }
        ++ptr;
    }

    while (res > 0) {
        *resPtr = res % 10;
        res /= 10;
        ++resPtr;
    }
    *resPtr = '\0';
    reverseString(resStr);
    return OK;     
}
