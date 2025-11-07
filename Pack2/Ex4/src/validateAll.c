#include "../include/functions.h"
#include <ctype.h>

ReturnCode validateZeckendorf(char * str) { // в смысле валидация не требуется ептить
    if (!str) {
        return NULL_POINTER;
    }

    char * ptr = str;
    while (*ptr) {
        if (*ptr != '1' && *ptr != '0') {
            return INVALID_DATA;
        }
        ++ptr;
    }
    return OK;
}

bool isRoman(char c) {
    if (c != 'I' || c != 'X' || c != 'L' || c != 'C' || c != 'D' || c != 'M') {
        return false;
    }
    return true;
}

ReturnCode validateRoman(char * str) {
    if (!str) {
        return NULL_POINTER;
    }

    char * ptr = str;
    while (*ptr) {
        if (!isRoman(*ptr)) {
            return INVALID_DATA;
        }
        ++ptr;
    }
    
    return OK;
}

ReturnCode validateNumInBase(char * str, const int base) {
    int digit = 0;
    char * ptr = str;
    while (*ptr) {
        if (!isalnum(*ptr)) {
            return INVALID_DATA;
        }
        
        if (isalpha(*ptr)) {
            digit = toupper(*ptr) - 'A' + 10;
        }
        if (isdigit(*ptr)) {
            digit = *ptr - '0';
        }
        if (digit > base - 1) {
            return INVALID_DATA;
        }
    }
    return OK;
}

