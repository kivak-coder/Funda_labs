#include "../include/functions.h"

returnCode funcB(int a, int b, int * isMultiple){
    if (b == 0){
        return DIVISION_BY_ZERO;
    }

    if (a % b == 0){
        *isMultiple = 1;
    } else {
        *isMultiple = 0;
    }
    return OK;
}



