#include <stdio.h>
#include <ctype.h>
#include "include/functions.h"


int main(int argc, char * argv[]){

    if (argc < 3) {
        printf("Wrong input");
        return 1;
    }

    char flag;
    long int x = 0;
    
    for (int i = 1; i < argc; ++i){


        char * p = argv[i]; // pointer to the beggining of the arg
        if ((*p == '-') || (*p == '/')){
            ++p;
            flag = *p;
            printf("Flag : %s\n", &flag);
        }

        if (isdigit(*p)){

            while (*p){
                x = 10 * x + (*p - '0');
                ++p;
            }
        }
    }


    switch (flag){
        case 'h':
            funcA(x);
            break;

        case 'p':
            funcB(x);
            break;
        
        case 's':
            funcC(x);
            break;
        
        case 'e':
            if (x > 10) {
                printf("X must be less then 10\n");
            } else if (x == 0) {
                printf("0 is not acceptable\n");
            } else {
                funcD(x);
            }  
            break;

        case 'a':
            funcE(x);
            break;
        
        case 'f':
            funcF(x);
            break;

        default:
            printf("Wrong flag!");
    }
    return 0;
}