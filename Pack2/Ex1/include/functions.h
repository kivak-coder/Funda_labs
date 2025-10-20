#include <stdbool.h>
#include <math.h>

#define EPS 1e-17

typedef enum ReturnCode {
    INFINITE,
    FINITE,
    WRONG_DATA,
    OK
} ReturnCode;

ReturnCode gcd(int a, int b, int * res);
ReturnCode DivToNumDenum(double a, double * num, double * denum);
ReturnCode IsInfinite(int num, int denum, int base, bool * isInf);
ReturnCode AreInfinite(int n, int base, ...);