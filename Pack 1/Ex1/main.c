#include <math.h>
#include <stdio.h>
#include "include/functions.h"


int main(int argc, char * argv[]){

    if (argc < 3) {
        printf("Wrong input");
        return 1;
    }

    char flag;
    long int x = 0;
    ReturnCode return_code;
    return_code = parseArgs(argc, argv, &flag, &x);
    if (return_code != OK){
        if (return_code == WRONG_ORDER){
            printf("Wrong order of arguments\n");
        } 
        if (return_code == WRONG_TYPE){
            printf("Wrong type of argument\n");
        }
    }
    
    int isSimple = 1;
    long long int res;
    int n = log10(x) + 2;
    char * hex[n];
    long long int res1 = 0;
    long long int powers[10][10];
    int multiple[100];


    
    switch (flag){
        case 'h':
            int *p = multiple;
            return_code = funcA(x, p);
            if (return_code == DIVISION_BY_ZERO){
                printf("Division by zero\n");
            } else {
                int *p = multiple;
                while (*p){
                    printf("%d ", *p);
                }
            }
            break;

        case 'p':
            return_code = funcB(x, &isSimple);
            switch (isSimple){
                case -1:
                    printf("Number %ld is not composite and not simple\n", x);
                    break;
                
                case 0:
                    printf("Number %ld is composite\n", x);
                    break;
                
                case 1:
                    printf("Number %ld is simple\n", x);
                    break;    
            }
            break;
        
        case 's':
            return_code = funcC(x, *hex);
            printf("%s", *hex);
            break;
        
        case 'e':
            if (x > 10) {
                printf("X must be less then 10\n");
            } else if (x == 0) {
                printf("0 is not acceptable\n");
            } else {
                funcD(x, &powers);
            }  
            break;

        case 'a':
            return_code = funcE(x, &res1);
            break;
        
        case 'f':
            return_code = funcF(x, &res);

            if (return_code == OK){
                printf("%lld", res);
                break;
            } 
            if (return_code == OVERFLOW){
                printf("Too big input for factorial\n");
                break;
            }
           
        default:
            printf("Wrong flag!");
    }
    return 0;
}