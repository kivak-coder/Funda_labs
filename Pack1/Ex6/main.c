#include "include/functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) {
    if (argc != 2) {
        printf("Wrong number of args!\n");
        return 0;
    }

    char * str[BUFSIZ];
    double eps = strtod(argv[1], str);
    if (!eps) {
        printf("Something went wrong\n");
        return 0;
    } 
    if (eps < 0) {
        printf("Epsilon must be positive!\n");
        return 0;
    }

    double a = 0;
    double b = 1;
    double res = 0;
    ReturnCode return_code;

    double (*functions[4])(double) = {FuncA, FuncB, FuncC, FuncD};

    for (int i = 1; i < 5; ++i) {
        return_code = trapezoidMethod(eps, a, b, &res, functions[i - 1]);
        if (return_code == OK) {
            printf("Integral %i: %f\n", i, res);
        }
        if (return_code == NULL_POINTER) {
            printf("Come across a null poiter\n");
        }
    }
    return 0;

}