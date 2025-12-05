#include "include/functions.h"
#include <stdio.h>

int main() {
    char buf[100] = "CVII -5";
    int res = 0; int res2 = 0; int res3 = 0; int res4 = 0; int res5; int res6 = 0; int res7 = 0; int res8 = 0; int res9 = 0;
    int result = oversscanf(buf, "%Ro %i", &res, &res2);
    printf("%i %i %i %i %i %i %i %i %i\n", res, res2, res3, res4, res5, res6, res7, res8, res9);
    printf("%i\n", result);
    return 0;
}