#include "../include/functions.h"
#include <stdio.h>

ReturnCode funcE(long int x, long long int * res){
    for (size_t i = 1; i <= x; ++i){
        *res += i;
    }
    return OK;
}