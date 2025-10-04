#include "../include/functions.h"
#include <ctype.h>
#include <stdio.h>

ReturnCode parseString(char *str, FILE * OutFi) {
    int base = 0;
    char * p = str;

    char num[BUFSIZ];
    long int numDec = 0;
    char * ptr = num;

   
    *ptr = *p;
    ++ptr;
    ++p;

    while (*p != '\n') {
        if (isalnum(*p)) {
            *ptr = *p; 
            printf("%c", *p);
        }
        ++ptr;

        if (isalnum(*(p - 1)) && !isalnum(*p)) {
            *ptr = 0;
            FindMinSys(num, &base);
            toDec(&numDec, num, &base);
            fprintf(OutFi, "Number: %s, Min base: %d, Number in decimal system: %ld\n", num, base, numDec);
            base = 0;
        }
        ++p;
    }
    return OK;
}