#include "../include/functions.h"
#include <stdio.h>

void funcE(long int x){
    long long int res = 0;
    for (size_t i = 1; i <= x; ++i){
        res += i;
    }
    printf("%lld", res);
}