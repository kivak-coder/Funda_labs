#include "include/functions.h"
#include <stdio.h>

int main() {
    double a = 0.1;
    double b = 0.000456;
    double c = 1.0 / 4.0;
    double d = 255 / 256.0;
    int base = 6;
    ReturnCode returnCode;

    double num;
    double denum;
    returnCode = DivToNumDenum(c, &num, &denum);
    printf("num :%f, denum: %f \n", num, denum);
    returnCode = AreInfinite(4, 8, a, b, c, d);

    return 0;
}