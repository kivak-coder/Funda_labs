#include "../include/functions.h"
#include <stdio.h>
#include <stdlib.h>


ReturnCode getRoman(char c, RomanNum * num) {
    switch (c) {
        case 'I':
            *num = I;
            break;

        case 'V':        
            *num = V;
            break;

        case 'X':
            *num = X;
            break;

        case 'L':
            *num = L;
            break;

        case 'C':
            *num = C;
            break;

        case 'D':
            *num = D;
            break;

        case 'M':
            *num = M;
            break;

        default:
            return INVALID_DATA;
    }
    return OK;
}

ReturnCode Roman(char *str, int *res) {
    if (!res || !str) {
        return NULL_POINTER;
    } // добавить проверку на переполнение!

    char * ptrPrev = str;
    char * ptrCur = str + 1;
    RomanNum roman1;
    RomanNum roman2; 
    ReturnCode returnCode;

    while (*ptrCur) {
        returnCode = getRoman(*ptrPrev, &roman1);
        if (returnCode != OK) {
            return returnCode;
        }

        returnCode = getRoman(*ptrCur, &roman2);
        if (returnCode != OK) {
            return returnCode;
        }
        
        if (roman1 >= roman2) {
            *res += roman1;
        } else {
            *res -= roman1;
        }

        ++ptrCur;
        ++ptrPrev;
    }

    returnCode = getRoman(*ptrPrev, &roman1);
        if (returnCode != OK) {
            return returnCode;
        }
        
        if (roman1 >= roman2) {
            *res += roman1;
        } else {
            *res -= roman1;
        }

        printf("%i\n", *res);

    return OK;
}

