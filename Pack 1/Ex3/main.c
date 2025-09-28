#include "include/functions.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char * argv[]){

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

        returnCode flags_return_code = flagsValidation(argv[1],  &flag);
        if (flags_return_code == WRONG_FLAG){
            printf("Wrong flag!\n");
            return 0;
        }

        if (flags_return_code == WRONG_INPUT){
            printf("Wrong input\n");
            return 0;
        } 

        if (flags_return_code == OK){
            if (toNum(argv[2], &a) != OK){
                printf("Wrong input\n");
                return 0;
            }
            if (toNum(argv[3], &b) != OK){
                printf("Wrong input\n");
                return  0;
            }
        }     
    }    


    if (argc == 6){

        returnCode flags_return_code = flagsValidation(argv[1],  &flag);
        if (flags_return_code == WRONG_FLAG){
            printf("Wrong flag!\n");
            return 0;
        } 
        if (flags_return_code == WRONG_INPUT){
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
    bool repeatedCoefs1 = false;
    bool repeatedCoefs2 = false;
    bool repeatedCoefs3 = false;
    double coefs[3] = {0};
    coefs[0] = a;
    coefs[1] = b;
    coefs[2] = c;
    double x1;
    double x2;
 
    switch (flag) {
        case 'q':
            for (size_t i = 0; i <= 2; ++i){
                for (size_t j = 0; j <= 2; ++j){
                    if (i == j) {continue;}
                        for (size_t k = 0; k <= 2; ++k){
                            if (j == k) {continue;}
                            if (i == k) {continue;}

                            if (coefs[i] == coefs[j]){
                                if (!repeatedCoefs1) {
                                repeatedCoefs1 = true;
                                } else {
                                    continue;
                                }
                            }

                            if (coefs[i] == coefs[k]){
                                if (!repeatedCoefs2){
                                    repeatedCoefs2 = true;
                                } else {
                                    continue;
                                }
                            }

                            if (coefs[j] == coefs[k]){
                                if (!repeatedCoefs3){
                                    repeatedCoefs3 = true;
                                } else {
                                    continue;
                                }
                            }

                            returnCode return_code = funcA(coefs[i], coefs[j], coefs[k], eps, &x1, &x2);

                            if (return_code == NO_ROOTS){
                                printf("For coefficients %f, %f, %f there are NO ROOTS\n", coefs[i], coefs[j], coefs[k]);
                            }
                            if (return_code == INFINITE_ROOTS){
                               printf("For coefficients %f, %f, %f there are INFINITE ROOTS\n", coefs[i], coefs[j], coefs[k]); 
                               return 0;
                            }
                            if (return_code == OK){
                                if (fabs(x1 - x2) < eps){
                                    printf("For coefficients %f, %f, %f root is %f \n", coefs[i], coefs[j], coefs[k], x1);
                                } else {
                                    printf("For coefficients %f, %f, %f roots are %f %f\n", coefs[i], coefs[j], coefs[k], x1, x2);   
                                }
                            }
                        }
                }
            }
            break;

        case 'm':  
            return_code = funcB(a, b, &IsMultiple);

            if (return_code == ZERO){
                printf(" Zero is restricted to this flag!\n");
                return 0;
            } 
            if (return_code == DOUBLES){
                printf("Double numbers are restricted to this flag!\n");
                return 0;
            }

            if (IsMultiple){
                printf("Number %f is multiple to %f\n", a, b);
            } else {
                printf("Number %f is NOT multiple to %f\n", a, b);
            }
            break;
        
        case 't': 
            if (a <= 0 || b <= 0 || c <= 0){
                printf("Negative numbers and zero can`t be the sides of a triangle!\n");
                return 0;
            }

            return_code = funcC(eps, a, b, c, &isTriangle);
            if (isTriangle){
                printf("YES it could be a triangle\n");
            } else {
                printf("NO it could not be a triangle\n");
            }
            break;
        } 
    }

