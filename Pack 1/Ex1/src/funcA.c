#include "../include/functions.h"


ReturnCode funcA(long int x, int *p){ //массив нужен блять!!! сука!!!!!

    if (x == 0){
        return DIVISION_BY_ZERO; 
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
// кратное число есть всегда - это само число
}