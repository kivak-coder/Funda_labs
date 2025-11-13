#include "include/functions.h"
#include <stdio.h>

int main() {
    char buf[10] = "MMXXVI";
    int res = 0; int res2 = 0;
    oversscanf(buf, "%Ro", &res);
    printf("%i\n", res);
    return 0;
}