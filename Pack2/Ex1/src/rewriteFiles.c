#include "../include/rewriteFiles.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

ReturnCode rewriteStrings(FILE * Output, char ** string) {
    if (*string == NULL) {
        return NULL;
    }
    char * ptrCur = string;
    char * ptrPrev = NULL;
    char buf[BUFSIZ];
    int len = 0;
    if (strlen(*string) < MAX_SIZE) {
        fprintf(Output, "%s", *string);
        return OK;
    }

    while (*ptrCur) {
        if (isalnum(*ptrCur)) {
            *buf = *ptrCur;
            ++len;
        }

        if (len > MAX_SIZE) {
            *buf = '\0';
        }
    }
    return OK;
}