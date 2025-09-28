#include "../include/functions.h"

returnCode funcB(double a, double b, int * isMultiple){
    if (b == 0 || a == 0){
        return ZERO;
    }

    if ((long int)a != a || (long int)b != b){
        return DOUBLES;
    }      
 
    if ((long int)a % (long int) b == 0){
        *isMultiple = 1;
    } else {
        *isMultiple = 0;
    }
    return OK;
}



