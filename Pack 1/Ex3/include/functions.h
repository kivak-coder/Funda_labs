#include <math.h>
#include <stdio.h>

typedef enum returnCode{
    WRONG_INPUT,
    WRONG_FLAG,
    ZERO,
    DOUBLES,
    NO_ROOTS,
    INFINITE_ROOTS,
    OK
} returnCode;

returnCode funcA(double eps, double a, double b, double c, double * x1, double * x2);
returnCode funcB(double a, double b, int * res);
returnCode funcC(double eps, double a, double b, double c, int * res);

returnCode toNum(char * arg, double * res);
returnCode flagsValidation(char * arg, char * flag);

