#include "../include/functions.h"
#include <ctype.h>

ReturnCode parseArgs(int argc, char *argv[], char * flag, long int * x){
    char * p1 = argv[1];
    char * p2 = argv[2]; // pointer to the beggining of the arg

    if (*p2 == '-' || *p2 == '/'){
        ++p2;
        *flag = *p2;
    } else {
        return WRONG_ORDER;
    } 

    while (*p1){
        if (isdigit(*p1)){
            *x = 10 * (*x) + (*p1 - '0');
            ++p1;
        } else {
            return WRONG_TYPE;
        }
    }
    return OK;
}