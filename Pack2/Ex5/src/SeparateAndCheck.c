#include "../include/functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


bool isReadable(char c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return false;
    }
    return true;
}

ReturnCode SeparateToWords(char * str, char ** words, int * size) {
    if (!str || !words || !size) {
        return NULL_POINTER;
    }

    char * ptrPrev = str;
    char * ptrCur = str + 1;
    char buf[BUFSIZ] = {0}; 
    char * ptrBuf = buf;
    int len = 0;

    while (*ptrCur) {
        if (isReadable(*ptrCur) && !isReadable(*ptrPrev)) {
            *ptrBuf = *ptrPrev;
            ++len;
            ++ptrBuf;
            *ptrBuf = '\0';
            words[*size] = (char * )malloc(len + 1);

            if (!words[*size]) return NULL_POINTER;

            strcpy((words)[*size],buf); 
            ptrBuf = buf;
            ++(*size);
            len = 0;

        } else {
            *ptrBuf = *ptrPrev;
            ++ptrBuf;
            ++len;
        }
        ++ptrCur;
        ++ptrPrev;
    }

    if (ptrBuf != buf) {
        *ptrBuf = *ptrPrev;
        ++ptrBuf;
        *ptrBuf = *ptrCur;
        ++ptrBuf;
        *ptrBuf = '\0';
        len += 2;

        words[*size] = (char * )malloc(len + 1);
        if (!words[*size]) {return NULL_POINTER;}
        strcpy(words[*size],buf);
        ptrBuf = buf;
        ++(*size);
    }
    return OK;
}
