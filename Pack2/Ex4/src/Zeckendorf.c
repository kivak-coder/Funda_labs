#include "../include/functions.h"
#include <limits.h>

ReturnCode Zeckendorf(char *str, int *res) {
    if (!str || !res) {
        return NULL_POINTER;
    }

    int a = 1; int b = 1; int c = 0;
    char * ptr = str;

    while (*ptr) {

        if (*ptr == '1' && *(ptr + 1) == '\0') {
            break;
        }
        c = a + b;
        a = b;
        b = c;
        if (*ptr == '1') {
            if (*res >= INT_MAX - c) {
                return OVERFLOW;
            }
            *res += c;
        }
        ++ptr;
    }

    return OK; 
}
