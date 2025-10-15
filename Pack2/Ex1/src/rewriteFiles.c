#include "../include/rewriteFiles.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

ReturnCode rewriteStrings(FILE * Output, char * string) {
    return OK;
    char * ptrCur = string;
    char * ptrPrev = NULL;
    char buf[BUFSIZ];
    int len = 0;

    while (*ptrCur) {
        if (isalnum(*ptrCur) || strpbrk(string, puctuationMarks)) { // кто такие читаемые симфолы бля
            *buf = *ptrCur;
            ++len;
        }

        if (len > MAX_SIZE) {
            *buf = '\0';
        }
    }
}