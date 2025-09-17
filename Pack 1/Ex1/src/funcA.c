#include "../include/functions.h"
#include <stdio.h>


void funcA(long int x){

    if (x == 0){
        printf("Division by zero\n");
        return; 
    }
    int num = 1;

    int res = x * num;

    while (res <= 100) { 
        printf("%d ", res);
        ++num;
        res = x * num;
    }
// кратное число есть всегда - это само число
}