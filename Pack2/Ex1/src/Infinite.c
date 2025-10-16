#include "../include/functions.h"
#include <math.h>
#include <stdarg.h>

ReturnCode IsInfinite(int num, int denum, int base, bool *isInf) {
    int res = 1;
    int x;
    ReturnCode ReturnCode;
    ReturnCode = gcd(num, denum, &res);
    num /= res;
    denum /= res;
    while (1) {
        gcd(denum, base, &x);
        num *= x;
    }


    return OK;
}

ReturnCode AreInfinite(int n, int base, ...) {
    int denum = 0; int num = 0;
    bool isInf = false;
    ReturnCode returnCode;

    va_list arg;
    va_start(arg, base);

    for (int i = 0; i < n; ++i) {
        double a = va_arg(arg, double);

        if (a < EPS || fabs(a - EPS) > 1) {
            return WRONG_PARTION;
        } 

        returnCode = DivToNumDenum(a, &num, &denum); // cho

        returnCode = IsInfinite(num, denum, base, &isInf);
    }
    va_end(arg);

    return OK;
}