#include "../include/functions.h"


ReturnCode funcA(long int x, int *p){ 

    if (x == 0){
        return DIVISION_BY_ZERO; 
    }

    if (x > 100){
        return NO_DIVIDERS;
    }
    
    int num = 1;
    int res = x * num;

    while (res <= 100) { 
        *p = res;
        ++num;
        ++p;
        res = x * num;
    }
    *p = '\0';
    return OK;
}