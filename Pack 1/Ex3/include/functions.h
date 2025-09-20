#include <stdio.h>

typedef enum returnCode{
    WRONG_NUMBER_OF_ARGS,
    WRONG_INPUT,
    WRONG_FLAG,
    DIVISION_BY_ZERO,
    NO_ROOTS,
    INFINITE_ROOTS,
    OK
} returnCode;

returnCode funcA(double eps, double a, double b, double c, double * coefs, double * roots);
returnCode funcB(int a, int b, int * res);
returnCode funcC(double eps, double a, double b, double c, int * res);

returnCode toNum(char * arg, double * res);
returnCode flagsValidation(char * argv[1], char * flag);

