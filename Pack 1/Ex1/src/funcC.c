#include "../include/functions.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>

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

void funcC(long int x){
    if (x == 0){
        printf("%ld", x);
        return;
    }

    int size = log10(x) + 2;
    char num[size];
    char * p = num + size - 1;
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

    char * beg = num;
    while (*beg != '\0'){
        if (isHex(*beg)){
        printf("%c", *beg);
    } 
    ++beg;
    }
    
}