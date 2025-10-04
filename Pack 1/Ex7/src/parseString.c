#include "../include/functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

ReturnCode parseString(char *str, FILE * OutFi) {
    int base = 1;
    char * p = str;
    char num[BUFSIZ];
    long int numDec = 0;
    char * ptr = num;
    ReturnCode return_code;
    bool isNum = false;

    do {
        if (*p == '-' && ptr == num && isalnum(*(p + 1))) {
            *ptr = '-';
            ++ptr;
        }   

        if (isalnum(*p)) {
            if (!isNum) {
                if (*p == '0' && !isalnum(*(p + 1))) {
                    *ptr = '0';
                } 
                if (*p == '0' && *(p + 1) == '0') {
                    ++ptr;
                }
                if (*p == '0' && isalnum(*(p + 1))) {
                    isNum = true;
                }
            }
        }

        if (isalnum(*(p - 1)) && !isalnum(*p)) {
            *ptr = '\0';
            FindMinSys(num, &base);
            return_code = toDec(&numDec, num, &base);

            if (return_code == OVERFLOW) {
                fprintf(OutFi, "Number: %s, Min base: %d, Number in decimal system: Overflow!\n", num, base);

            } else {
                fprintf(OutFi, "Number: %s, Min base: %d, Number in decimal system: %ld\n", num, base, numDec);
            }

            base = 0;
            ptr = num;
            numDec = 0;
            isNum = false;
        }

        ++p;
    }  while (*p != '\n' && *p != '\0');

    if (ptr != num) {
        *ptr = '\0';
        FindMinSys(num, &base);
        return_code = toDec(&numDec, num, &base); 

        if (return_code == OVERFLOW) {
            fprintf(OutFi, "Number: %s, Min base: %d, Number in decimal system: Overflow!\n", num, base);
        } else {
            fprintf(OutFi, "Number: %s, Min base: %d, Number in decimal system: %ld\n", num, base, numDec);
        }
        
    }
            
   return OK;
}