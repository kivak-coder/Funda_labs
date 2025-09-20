#include "../include/functions.h"
#include <limits.h>
#include <stdio.h>

ReturnCode funcF(long int x, unsigned long long int * res){

    for (size_t i = 1; i <= x; ++i){
        if (*res * i >= ULLONG_MAX){
            return OVERFLOW; 
        }
        *res *= i;
    }
    return OK;
}