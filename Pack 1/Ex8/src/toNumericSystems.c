#include "../include/functions.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

ReturnCode toDecInt(char *str, const int base, long *num){
    char * ptr = str;
    while (*ptr){
        if (isdigit(*ptr)){
            *num = (*num) * base + (*ptr - '0');
        } else {
            *num = (*num) * base + (*ptr - 'A' + 10);
        }
        ++ptr;
    }
    return OK;
}

ReturnCode toNsistem(char *str, const int base, long *num){
    char strS[strlen(str)];
    char * p = strS;
    char * ptr = str;
    *p = '\0';
    int digit = 0;
    ++p;  
    
    
    while (*num){
        digit = *num % base;
        if (digit > 9){
            *p = digit - 10 + 'A';
        } else {
            *p = digit;
        }
        ++p;
        printf("%s\n", strS);
    }

    while (*p){
        *ptr = *p;
        ++ptr;
        --p;
    }
    *ptr = '\0';
    return OK;
}