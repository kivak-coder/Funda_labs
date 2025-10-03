#include "../include/functions.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

ReturnCode parseBase(char *str, int *base){
    char * p;
    long result = strtol(str, &p, 10);

    if (*p != '\0') { // чото тут с условием не так оч сина 
        return WRONG_TYPE;
    }
    if (result == LONG_MAX || result == LONG_MIN){
        return OVERFLOW;
    }
    *base = result;
    if (*base < 2 || *base > 36) {
        return WRONG_BASE;
    }
    return OK;
}


ReturnCode parseNum(char *str, const int *base){
    char * p = str;
    int num = 0;

    while (*p) {
        if (isalnum(*p)){
            if (isdigit(*p)) {
                num = *p - '0';
            }
            if (isalpha(*p)) {
                num = tolower(*p) - 'a' + 10; 
            }
            if (num >= *base){
                return WRONG_NUM;
            }
        }
        ++p;
    }
    return OK;
}