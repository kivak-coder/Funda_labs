#include "include/functions.h"
#include <stdio.h>

int main() {
    char buf[100] = "Num-2: 10101011101, Num-16: -256.NUM-36-ZXY number17: -bcd123 MCVI 1010111, I, 1011, CC";
    int res = 0; int res2 = 0; int res3 = 0; int res4 = 0; int res5; int res6 = 0; int res7 = 0; int res8 = 0; int res9 = 0;
    oversscanf(buf, "Num-2: %Cv, Num-16: %Cv.NUM-36%CV number17: %Cv %Ro %Zr, %Ro, %Zr, %Ro", &res, 2, &res2, 16, &res3, 36, &res4, 17, &res5, &res6, &res7, &res8, &res9);
    printf("%i %i %i %i %i %i %i %i %i\n", res, res2, res3, res4, res5, res6, res7, res8, res9);
    return 0;
}