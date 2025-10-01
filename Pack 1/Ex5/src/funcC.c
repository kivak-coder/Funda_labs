#include "../include/functions.h"
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>


ReturnCode funcC(FILE *fi, FILE *out){
    char str[BUFSIZ];
    int count = 0;

    while (fgets(str, BUFSIZ, fi) != NULL){
        char * p = str;
        
        while (*p != '\n'){
            if (!isalpha(tolower(*p)) && !isdigit(tolower(*p)) && (tolower(*p)) != ' ' && (tolower(*p)) != '\t'){
                ++count;
            }
            ++p;
        }

        fprintf(out, "Count: %d\n", count);
        count = 0;
    }
    return OK;
}