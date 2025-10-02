#include "../include/functions.h"
#include <ctype.h>
#include <stdio.h>


void toHex(int DecHum, char * HexNum){

    int len = 0;

    while (DecHum){
        int num = DecHum % 16;
        if (num > 9){
            HexNum[len] = num - 10 + 'A';
        } else {
            HexNum[len] = num + '0';
        }
        ++len;
        DecHum /= 16;
    }
    HexNum[len] = '\0';
    --len;

    for (int i = 0; i <= len / 2; ++i){
        char tmp = HexNum[i];
        HexNum[i] = HexNum[len - i];
        HexNum[len - i] = tmp;
    }
}

ReturnCode funcD(FILE *fi, FILE *out){
    char c;
    char num[7];
    while ((c = fgetc(fi)) != EOF){
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