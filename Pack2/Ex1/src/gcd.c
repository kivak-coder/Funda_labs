#include "../include/functions.h"

ReturnCode gcd(int a, int b, int * res) {
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