#include "../include/functions.h"
#include <math.h>
#include <stdio.h>

returnCode countRoots(double a, double b, double c, double * x1, double * x2){
    if (a == 0){
        double x1, x2 = -c / b;
    }
    if (a == 0 && b == 0){
        return NO_ROOTS;
    }
    double D = pow(b, 2) - 4 * a * c;
    if (D < 0){
        return NO_ROOTS;
    }

    *x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    *x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    return OK;
}

returnCode funcA(double eps, double a, double b, double c, double * coefs, double * roots){ // чо тут делать, если вызовов несколько???
    if (a == b == c == 0){
        printf("Infinity\n");
        return INFINITE_ROOTS;
    } 

    double x1 = 0;
    double x2 = 0;

    countRoots(a, b, c, &x1, &x2);
    if (fabs(x1 - x2) < eps){
        printf("For coefficients a: %f, b: %f, c: %f root is %f\n", a, b, c, x1);
    } else {
        printf("For coefficients a: %f, b: %f, c: %f roots are %f, %f\n", a, b, c, x1, x2);
    }

    countRoots(a, c, b, &x1, &x2);
    if (fabs(x1 - x2) < eps){
        printf("For coefficients a: %f, b: %f, c: %f root is %f\n", a, c, b, x1);
    } else {
        printf("For coefficients a: %f, b: %f, c: %f roots are %f, %f\n", a, c, b, x1, x2);
    }

    countRoots(b, a, c, &x1, &x2);
    if (fabs(x1 - x2) < eps){
        printf("For coefficients a: %f, b: %f, c: %f root is %f\n", b, a, c, x1);
    } else {
        printf("For coefficients a: %f, b: %f, c: %f roots are %f, %f\n", b, a, c, x1, x2);
    }

    countRoots(b, c, a, &x1, &x2);
    if (fabs(x1 - x2) < eps){
        printf("For coefficients a: %f, b: %f, c: %f root is %f\n", b, c, a, x1);
    } else {
        printf("For coefficients a: %f, b: %f, c: %f roots are %f, %f\n", b, c, a, x1, x2);
    }

    countRoots(c, a, b, &x1, &x2);
    if (fabs(x1 - x2) < eps){
        printf("For coefficients a: %f, b: %f, c: %f root is %f\n", c, a, b, x1);
    } else {
        printf("For coefficients a: %f, b: %f, c: %f roots are %f, %f\n", c, a, b, x1, x2);
    }

    countRoots(c, b, a, &x1, &x2);
    if (fabs(x1 - x2) < eps){
        printf("For coefficients a: %f, b: %f, c: %f root is %f\n", c, b, a, x1);
    } else {
        printf("For coefficients a: %f, b: %f, c: %f roots are %f, %f\n", c, b, a, x1, x2);
    }
}

