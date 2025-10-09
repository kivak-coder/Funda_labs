#include "../include/functions.h"
#include <math.h>
#include <stdio.h>

ReturnCode trapezoidMethod(double eps, double a, double b, double * res, double (*func)(double)) {
    if (func == NULL || func == NULL) {
        return NULL_POINTER;
    }

    double h = b - a;
    double Integral = (b - a) * (func(a) + func(b)) / 2.0;
    double integralRes = 0;
    int n = 1;

    while (fabs(integralRes - Integral) >= eps) {
        Integral = integralRes;
        n *= 2;
        h /= 2;
        double sum = 0.0;

        for (int i = 1; i < n; i += 2) {
            double x = a + i * h;
            sum += func(x);
        }

        integralRes = Integral / 2 + h * sum;

    }

    *res = integralRes;
    return OK;
        
}