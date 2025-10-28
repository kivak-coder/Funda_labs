#include "include/functions.h"
#include <stdio.h>

int main() {
    
    double a = 0.1;
    double b = 0.25;
    double c = 2.0 / 3.0;
    double d = 6.0 / 9.0;
    double e = 0.1234;
    double f = 0.125;
    double g = 1 / 27.0;
    double h = 1e-20;
    int base = 3;

    ReturnCode returnCode;

    returnCode = AreInfinite(8, base, a, b, c, d, e, f, g, h);

    if (returnCode != OK) {
        printf("ERROR!\n");
    }

    return 0;
}