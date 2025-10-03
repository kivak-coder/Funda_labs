#include "../include/functions.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

ReturnCode toDecInt(char *str, const int base, long *num) {
    char * ptr = str;
    int underZero = 1;
    if (str[0] == '-') {
        underZero = -1;
        ++ptr;
    }

    while (*ptr) {
        if (isdigit(*ptr)) {
            if (*num > LLONG_MAX / base) {
                return OVERFLOW; 
            }
            *num = (*num) * base + (*ptr - '0');
        } else {
            *num = (*num) * base + (toupper(*ptr) - 'A' + 10);
        }
        ++ptr;
    }
    *num *= underZero;
    return OK;
}

ReturnCode toNsistem(char *str, const int base, long *num) {
    int digit = 0;
    int len = 0;
    if (*num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return OK;
    }

    if (*num < 0) {
        str[0] = '-';
        ++len;  
    }

    long tempNum = labs(*num);
    while (tempNum) {
        if (len > BUFSIZ - 1) {
            return OVERFLOW;
        }
        digit = tempNum % base;
        if (digit > 9) {
            str[len] = digit - 10 + 'A';
        } else {
            str[len] = digit + '0';
        }
        ++len; 
        tempNum /= base;
    }
    str[len] = '\0';
    --len;

    for (int i = 0; i <= len / 2; ++i) {
        if (str[i] == '-') {
            continue;
        }
        char tmp = str[i];
        str[i] = str[len - i];
        str[len - i] = tmp;
    }
    return OK;
}