#include "../include/functions.h"
#include <stdio.h>

void funcF(long int x){
    long long int res = 1;

    for (int i = 1; i <= x; ++i){
        res *= i;
    }

    printf("%lld", res);
}