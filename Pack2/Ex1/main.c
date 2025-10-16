#include "include/functions.h"
#include <stdio.h>

int main() {
    double a = 0.1;
    double b = 1.0 / 3.0;
    double c = 0.25;
    double d = 1.0 / 9.0;
    int base = 6;
    ReturnCode ReturnCode;

    ReturnCode = AreInfinite(4, base, a, b, c, d);
    return 0;
}