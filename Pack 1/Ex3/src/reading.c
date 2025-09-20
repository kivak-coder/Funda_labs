#include <ctype.h>
#include <math.h>
#include "../include/functions.h"


returnCode toNum(char *arg, double * res){
    long int x = 0;
    double y = 0.0;
    int isDouble = 0;
    char * p = arg;

    if (!isDouble){
        while (*p){
            if (*p == ',' || *p == '.'){
                isDouble = 1;
                ++p;
                break;
            }
            if (isdigit(*p)){
                x = 10 * x + (*p - '0');
                ++p;
            } else {
                return WRONG_INPUT;
            }
            
        }  
    }

    if (isDouble){
        int n = 0;
        while (*p){
            if (isdigit(*p)){
                y = y * 10 + (*p - '0');
                ++n;
                p++;
            } else {
                return WRONG_INPUT;
            }
        }

    y = y / pow(10, n);
    *res = x + y;
    } else {
        *res = x;
    }
    return OK;

}

returnCode flagsValidation(char *argv[1], char * flag){

        char * p = argv[1];
        if ((*p == '-' || *p == '/')){
            *flag = *(p + 1);
            printf("Flag: %c", *flag);
        switch (*flag){
            case 'm':
            case 'q':
            case 't':
                return OK;
            default:
                return WRONG_FLAG;
        }
        } 
}