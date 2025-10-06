#include <stdio.h>

typedef enum ReturnCode{
    OVERFLOW,
    WRONG_TYPE,
    WRONG_ORDER,
    OK,
    DIVISION_BY_ZERO,
    NO_DIVIDERS,
} ReturnCode;


ReturnCode funcA(long int x, int * p);
ReturnCode funcB(long int x, int * res);
ReturnCode funcC(long int x, char * hex);
ReturnCode funcD(long int x, unsigned long long int (*powers)[11]);
ReturnCode funcE(long int x, long long int * res);
ReturnCode funcF(long int x, long long int * res);
ReturnCode parseArgs(int argc, char ** argv, char * flag, long int * x);