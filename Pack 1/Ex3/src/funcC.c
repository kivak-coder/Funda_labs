#include "../include/functions.h"
#include <math.h>

returnCode funcC(double eps, double a, double b, double c, int * res){ 
    int flag = 0;
    
    double c0 = pow(a, 2) + pow(b, 2);
    if (fabs(sqrt(c0) - c) < eps){
        flag = 1;
    }

    double b0 = pow(a, 2) + pow(c, 2);
    if (fabs(sqrt(b0) - b) < eps){
        flag = 1;
    }

    double a0 = pow(b, 2) + pow(c, 2);
    if (fabs(sqrt(a0) - a) < eps){
        flag = 1;
    }

    *res = flag;
    return OK;
}