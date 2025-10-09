#include "../include/functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>



ReturnCode withoutZeros(char ** p, bool * isNum) {
    if (!p || !isNum) {
        return NULL_POINTER;
    }
    if (isalnum(**p) && **p != '0') {
        *isNum = true;
        return OK;
    }

    while (**p == '0') {
        ++*p;
        if (isalnum(**p) && **p != '0') {
            *isNum = true;
            return OK;
        }
        if (!isalnum(**p)) {
            *isNum = false;
            return OK;
        }
    }
    return OK;
}

ReturnCode parseString(char *str, FILE * OutFi) {
    if (!str || !OutFi) {
        return NULL_POINTER;
    }

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
            ++p;
        }  

        if (ptr == num || num[0] == '-') {
            return_code = withoutZeros(&p, &isNum);
            if (return_code == NULL_POINTER) {
                return NULL_POINTER;
            }
        }

        if (isNum) {
            if (isalnum(*p) && *p != 0) {
                *ptr = *p;
                ++ptr;
            }

        } else {
            if (isalnum(*(p - 1))) {
                *ptr = '0';
                ++ptr;
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

            base = 1;
            ptr = num;
            numDec = 0;
        }
        ++p;

    }  while (*p != '\n' && *p != '\0');

    if (ptr != num) {
        *ptr = '\0';
        FindMinSys(num, &base);
        return_code = toDec(&numDec, num, &base); 

        if (return_code == NULL_POINTER) {
            return NULL_POINTER;
        }

        if (return_code == OVERFLOW) {
            fprintf(OutFi, "Number: %s, Min base: %d, Number in decimal system: Overflow!\n", num, base);
        } else {
            fprintf(OutFi, "Number: %s, Min base: %d, Number in decimal system: %ld\n", num, base, numDec);
        }   
    }
         
   return OK;
}