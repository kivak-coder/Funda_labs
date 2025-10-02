#include "../include/functions.h"
#include <ctype.h>
#include <stdio.h>

ReturnCode funcA(FILE *fi, FILE * out){
    char c;
    while ((c = fgetc(fi)) != EOF){
        if (!isdigit(c)){
            fputc(c, out);
        } else {
            fputc(' ', out);
        }
    }
    return OK;
} 