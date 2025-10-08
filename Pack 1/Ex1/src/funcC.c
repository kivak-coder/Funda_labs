#include "../include/functions.h"
#include <ctype.h>
#include <math.h>

int isHex(char a){
    int flag = 0;
    if (isdigit(a)){
        flag = 1;
    } else {
        if (a == 'A' || a == 'B' || a == 'C' || a == 'D' || a == 'E' || a == 'F' )
        {
            flag = 1;
        }
    }
    return flag;
}

ReturnCode funcC(long int x, char * hex){
    if (x == 0){
        *hex = '0';
        *(hex + 1) = '\0';
        return OK;
    }

    int size = log10(x) / log10(16) + 2;
    char * p = hex + size - 1;
    *p = '\0';
    p--;

    while (x){
        int digit = x % 16;
        if (digit > 9){
            *p = digit - 10 + 'A';
        } else {
            *p = digit + '0';
        }
        x /= 16;
        p--;
    }
    return OK;
    
}