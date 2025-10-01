#include "../include/functions.h"
#include <math.h>

ReturnCode funcB(long int x, int *isSimple){
    int n = sqrt(x);
    if ((x == 0) || (x == 1)){
        *isSimple = -1;
    } else {
    
    if (x % 2 == 0){
        *isSimple = 0;
        
    } else {
        for (int i = 3; i <= n; ++i){
        if ((x % i == 0) || (x % (x / i) == 0)){
            *isSimple = 0;
            break;
        }
    }
    }
    }
    return OK;
}