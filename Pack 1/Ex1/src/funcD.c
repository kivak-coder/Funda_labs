#include "../include/functions.h"
#include <stdio.h>
#include <math.h>

void funcD(long int x){
    int Maxbase = 10;
    long long int res = 1;
    
    printf("\033[1m");
    for (int i = 0; i <= x; ++i){
        printf("%12d ", i);
    }
    printf("\n\033[0m"); 
    
    for (int a = 1; a <= Maxbase; ++a){
        printf("\033[1m%12d\033[0m ", a); 
        for (int i = 1; i <= x; ++i){
            res = pow(a, i);
            printf("%12lld ", res);
        }
        printf("\n");
    }
}