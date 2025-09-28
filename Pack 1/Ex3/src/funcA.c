#include "../include/functions.h"
#include <math.h>
#include <stddef.h>

returnCode funcA(const double a, const double b, const double c, const double eps, double * x1, double * x2){

    if (fabs(a) < eps && fabs(b) < eps && fabs(c) < eps){
        return INFINITE_ROOTS;
    } 

    if (fabs(a) < eps){
        *x1= -c / b;
        *x2 = -c / b;
        return OK;
    }

    if (fabs(a) < eps && fabs(b) < eps){
        return NO_ROOTS;
    }

    if (fabs(a) < eps && fabs(c) < eps){
        *x1 = 0;
        *x2 = 0;
        return OK;
    }

    double D = pow(b, 2) - 4 * a * c;

    if (D < 0){
        return NO_ROOTS;
    }

    *x1 = (-b + sqrt(D)) / (2 * a);
    *x2 = (-b - sqrt(D)) / (2 * a);
    return OK;
}

