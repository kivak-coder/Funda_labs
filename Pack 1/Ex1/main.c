#include <stdio.h>
#include "include/functions.h"


int main(int argc, char * argv[]){

    if (argc != 3) {
        printf("Wrong input\n");
        return 1;
    }

    char flag;
    long int x = 0;
    ReturnCode return_code;

    return_code = parseArgs(argc, argv, &flag, &x);

    if (return_code != OK){
        if (return_code == WRONG_ORDER){
            printf("Wrong order of arguments\n");
            return -1;
        } 
        if (return_code == WRONG_TYPE){
            printf("Wrong type of argument\n");
            return -1;
        }
    }
    
    int isSimple = 1;
    long long int res = 1;
    char * hex[11];
    long long int res1 = 0;
    unsigned long long int powers[11][11];
    int multiple[100];
    int * p = NULL;
    int Maxbase = 10;
    
    switch (flag){
        case 'h':
            return_code = funcA(x, multiple);
            if (return_code == DIVISION_BY_ZERO){
                printf("Division by zero\n");
            } 
            if (return_code == NO_DIVIDERS){
                printf("The number is bigger than 100, no dividers\n");
            }
            if (return_code == OK) {
                int *p = multiple;
                while (*p){
                    printf("%d ", *p);
                    p++;
                }
            }
            break;

        case 'p':
            return_code = funcB(x, &isSimple);
            switch (isSimple){
                case -1:
                    printf("Number %ld is not composite and not prime\n", x);
                    break;
                
                case 0:
                    printf("Number %ld is composite\n", x);
                    break;
                
                case 1:
                    printf("Number %ld is prime\n", x);
                    break;    
            }
            break;
        
        case 's':
            return_code = funcC(x, *hex);
            printf("%s", *hex);
            break;
        
        case 'e':
            return_code = funcD(x, powers);
            if (return_code == OVERFLOW){
                printf("Input number should be less than 10!\n");
            } 
            if (return_code == DIVISION_BY_ZERO){
                printf("%ld\n", x);
            }
            if (return_code == OK) {
                printf("\033[1m");
                for (int i = 0; i <= x; ++i){
                    printf("%12d ", i);

                }
                printf("\n\033[0m");  

                for (int a = 1; a <= Maxbase; ++a){
                    printf("\033[1m%12d\033[0m ", a); 
                    for (int i = 1; i <= x; ++i){
                        printf("%12lld ", powers[i][a]);
                    }
                    printf("\n"); 
                }
            }
            break;

        case 'a':
            return_code = funcE(x, &res1);
            printf("%lld", res1);
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
            printf("Wrong flag!\n");
    return 0;

        }
    }