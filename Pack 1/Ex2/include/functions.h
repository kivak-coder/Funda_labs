#define BUFFER 10

typedef enum ReturnCode {
    OK, 
    WRONG_TYPE,
    PRIME,
    COMPOSITE,
    OVERFLOW,
    ALLOCATION_MISTAKE,
} ReturnCode;

ReturnCode parseArgs(char * arg, int * n);
ReturnCode PrimeN(long int x, long int ** primes, int * size, int * count);
