#include "../include/functions.h"
#include <ctype.h>

ReturnCode parseArgs(int argc, char **argv, char * flag, long int * x){
    char * p1 = argv[1];
    char * p2 = argv[2]; // pointer to the beggining of the arg
    if (*p1 == '-' || *p1 == '/'){
        flag = (p1 + 1);
    } else {
        return WRONG_ORDER;
    } 

    if (isdigit(*p2)){
        while (*p2){
            if (*p2 == ',' || *p2 == '.'){
                return WRONG_TYPE;
            }
            *x = 10 * (*x) + (*p2 - '0');
            ++p2;
        }
    } else {
        return WRONG_TYPE;
    }
    return OK;
}