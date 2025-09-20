#include "include/functions.h"
#include <stdio.h>

int main(int argc, char * argv[]){

    printf("%d\n", argc);

    if (argc != 6 && argc != 4){
        printf("Wrong input!\n");
        return 0;
    }

    char flag;
    double eps = 0;
    double a = 0;
    double b = 0;
    double c = 0;

    if (argc == 4){
        returnCode flags_return_code = flagsValidation(&argv[1],  &flag);
        if (flags_return_code == WRONG_FLAG){
            printf("Wrong flag!\n");
            return 0;
        }
        // } else if (flags_return_code == WRONG_INPUT){
        //     printf("Wrong input\n");
        //     return 0;
        // } 
        if (flags_return_code == OK){
            if (toNum(argv[2], &a) != OK){
                printf("Wrong input\n");
                return 0;
            }
            if (toNum(argv[3], &b) != OK){
                printf("Wrong input\n");
                return  0;
            }
            printf("a: %f, b: %f\n", a, b);
        }     
    }    


    if (argc == 6){
        returnCode flags_return_code = flagsValidation(&argv[1],  &flag);
        if (flags_return_code == WRONG_FLAG){
            printf("Wrong flag!\n");
            return 0;
        } else if (flags_return_code == WRONG_INPUT){
            printf("Wrong input\n");
            return 0;
        } 
        if (flags_return_code == OK){
            if (toNum(argv[2], &eps) == WRONG_INPUT){
                printf("Wrong input\n");
                return 0;
            }
            if (toNum(argv[3], &a) == WRONG_INPUT){
                printf("Wrong input\n");
                return  0;
            }
            if (toNum(argv[4], &b) == WRONG_INPUT){
                printf("Wrong input\n");
                return  0;
            }
            if (toNum(argv[5], &c) == WRONG_INPUT){
                printf("Wrong input\n");
                return  0;
            }
        }     
    }    

    returnCode return_code;
    int IsMultiple = 0;
    int isTriangle = 0;
    double coefs[18] = {};
    double roots[12] = {};
    
    switch (flag) {
        case 'q':
            printf("Eps: %f, a: %f, b: %f, c: %f \n", eps, a, b, c);
            funcA(eps, a, b, c, coefs, roots);
            break;

        case 'm':        
            printf("a: %f, b: %f\n", a, b);
            printf("a: %f, b: %f\n", a, b);
            return_code = funcB(a, b, &IsMultiple);
            if (return_code == DIVISION_BY_ZERO){
                printf("Division by zero\n");
            } else if (IsMultiple){
                printf("Number %f, is multiple to %f\n", a, b);
            } else if (IsMultiple == 0){
                printf("Number %f, is NOT multiple to %f\n", a, b);
            }
            break;
        
        case 't': 
            printf("Eps: %f, a: %f, b: %f, c: %f \n", eps, a, b, c);
            return_code = funcC(eps, a, b, c, &isTriangle);
            break;
    } 
}

