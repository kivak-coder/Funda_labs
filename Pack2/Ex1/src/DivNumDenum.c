#include "../include/functions.h"
#include <math.h>

ReturnCode DivToNumDenum(double number, double * num, double * denum) {
    long long int a0 = 0, a1 = 1, b0 = 1, b1 = 0;
    double x = number;

    for (int i = 0; i < MAX_ITER; ++i) {
        long long int a = (long long int)floor(x);
        long long int temp = a1;
        a1 = a * a1 + a0;
        a0 = temp;

        temp = b1; 
        b1 = a * b1 + b0;
        b0 = temp;

        if (fabs(number - (double)a1 / (double)b1) < EPS) {
            break;
        }
        if (x - a < EPS) {
            break;
        }
        x = 1 / (x - a);
    }
    *num = a1;
    *denum = b1;

    return OK;
}