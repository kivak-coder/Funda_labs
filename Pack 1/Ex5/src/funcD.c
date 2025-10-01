#include "../include/functions.h"
#include <ctype.h>
#include <stdio.h>


void toHex(int DecHum, char * HexNum){
    printf("ABOB");
    char str[7];
    char * p = str;
    int len = 1;
    *p = '\0';
    ++p;

    while (DecHum){
        int num = DecHum % 16;
        ++len;
        if (num > 9){
            *p = num - 10 + 'A';
        } else {
            *p = (*p - '0');
        }
        DecHum /= 16;
    }
    char * ptr = str;
    char * ptrFin = HexNum;
    ptr += len;

    while (ptr){
        *ptrFin = *ptr;
        ++ptrFin;
        --ptr; 
    }
}

ReturnCode funcD(FILE *fi, FILE *out){
    printf("ABOB");
    char c;
    char num[7];
    while ((c = fgetc(fi)) != EOF){
        printf("ABOB");
        if (!isdigit(c)){
            if (c == '\n' || c == ' ' || c == '\t'){
                fputc(c, out);
            } else {
                toHex((int)c, num);
                fprintf(out, "%s", num);
            }
        } else {
            fputc(c, out);
        }
    }
    return OK;
}