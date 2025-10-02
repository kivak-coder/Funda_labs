#include "../include/functions.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

ReturnCode flagsValidation(char *arg, char *flag, bool * IsFile){
    char * p = arg;

    if (*p == '-' || *p == '/') {

        if (strlen(arg) == 2) {
            *flag = *(p + 1);
            *IsFile = false;
        } else if (strlen(arg) == 3) {
            if (*(p + 1) == 'n') {
                *IsFile = true;
                *flag = *(p + 2);
            } else {
                return WRONG_FLAG;
            }
        } else {
            return WRONG_FLAG;
        }
    }

    switch (*flag) {
        case 'd':
        case 'i':
        case 's':
        case 'a':
            return OK;
        default:
            return WRONG_FLAG;
    }
}


ReturnCode AddOut(char * filename, char * outFile) {
    char out[] = "out_";
    if ((strlen(filename) + 4) >= BUFSIZ) {
        return TOO_LONG;
    }
    
    strcpy(outFile, out);
    strcat(outFile, filename);
    return OK;
}
