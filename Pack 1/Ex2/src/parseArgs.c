#include "../include/functions.h"
#include <ctype.h>

ReturnCode parseArgs(char * arg, int * n){
    char * p = arg;

    while (*p){
        if (isdigit(*p)){
            *n = (*n) * 10 + (*p - '0');
            ++p;
        } else {
            return WRONG_TYPE;
        }
    }
    return OK;
}