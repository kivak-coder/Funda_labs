#include "../include/functions.h"
#include <limits.h>

ReturnCode funcF(long int x, long long int * res){

    for (int i = 2; i <= x; ++i){
        if ((*res) * i < 0){
            return OVERFLOW; 
        } else {
            *res *= i;
        }
    }
    return OK;
}