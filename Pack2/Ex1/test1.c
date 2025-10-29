#include "include/functions.h"
#include <stdio.h>

int main() {
    
    double a = 0.1;
    double b = 0.25;
    double c = 2.0 / 16.0;
    double d = 5.0 / 256.0;
    double e = 0.00000256;
    double f = 0.125;
    double g = 5 / 7.0;
    double h = 1e-20;
    int base = 16;
    int n = 8;

    ReturnCode returnCode;

    returnCode = AreInfinite(n, base, a, b, c, d, e, f, g, h);

    if (returnCode != OK) {
        printf("ERROR!\n");
    }

    return 0;
}