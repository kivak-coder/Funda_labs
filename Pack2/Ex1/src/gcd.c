#include "../include/functions.h"

ReturnCode gcd(int a, int b, int * res) {
    if (a <= 0 || b <= 0) {
        return WRONG_DATA;
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    *res = a;
    return OK;
}