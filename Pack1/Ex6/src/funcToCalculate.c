#include "../include/functions.h"
#include <math.h>

double FuncA(double x) {
    if (x <= 1e-17) {
        return 1.0;
    }
    return log(1 + x) / x;
}

double FuncB(double x) {
    return exp((-1) * x * x / 2);
}

double FuncC(double x) {
    if (x >= 1.0 - 1e-17) {
        x = 1.0 - 1e-17;
    }
    return -log(1 - x);
}

double FuncD(double x) {
    if (x <= 1e-17) {
        return 1.0;
    }
    return pow(x, x);
}   