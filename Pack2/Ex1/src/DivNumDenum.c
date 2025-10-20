#include "../include/functions.h"
#include <math.h>
#include <stdio.h>

ReturnCode DivToNumDenum(double a, double * num, double * denum) {
    printf("%f\n", a);
    int n = 0;
    *num = a;

    while ((int)*num != *num && n < 40) {
        printf("%f\n", *num);

        *num *= 10;
        n++;
    }
    *denum = pow(10, n);
    return OK;
}