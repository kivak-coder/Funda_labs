#include <stdbool.h>

#define EPS 1e-17

typedef enum ReturnCode {
    WRONG_PARTION,
    OK
} ReturnCode;

ReturnCode gcd(int a, int b, int * res);
ReturnCode DivToNumDenum(double a, int * num, int * denum);
ReturnCode IsInfinite(int num, int denum, int base, bool * isInf);
ReturnCode AreInfinite(int n, int base, ...);