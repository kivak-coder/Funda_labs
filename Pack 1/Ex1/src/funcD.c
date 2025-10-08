#include "../include/functions.h"
#include <math.h>

ReturnCode funcD(long int x, unsigned long long int (*powers)[11]){
    int Maxbase = 10;
    long long int res = 1;
    if (x == 0){
        return DIVISION_BY_ZERO;
    }

    if (x > 10){
        return OVERFLOW;
    }
    
    for (int a = 1; a <= Maxbase; ++a){
        for (int i = 1; i <= x; ++i){
            res = pow(a, i);
            powers[i][a] = res;
        }
    }
    return OK;
}