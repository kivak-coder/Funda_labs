#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/functions.h"

int main(int argc, char * argv[]){
    if (argc != 2){
        printf("Wrong input!\n");
        return -1;
    }

    int T = 0; // requests
    ReturnCode return_code = parseArgs(argv[1],  &T);

    if (return_code == WRONG_TYPE){
        printf("Wrong type of argument!\n");
        return -1;
    }

    int size = BUFFER;
    long int * primes = (long int *)calloc(BUFFER, sizeof(long int)); // an array of all primes  

    if (primes == NULL){
        printf("Some mistake with allocation\n");
        return -1;
    }

    primes[0] = 2;
    primes[1] = 3;
    int count = 2; // индекс по которому будем писать в след раз

    if (return_code == OK){

        for (int i = 0; i < T; ++i){
            int n = 0;
            char ArgStr[12] = {0};

            scanf("%11s", ArgStr);
            
            char * p = ArgStr;
            return_code = parseArgs(p, &n);
            
            if (return_code == WRONG_TYPE || n <= 0){
                printf("Wrong type of input!\n");
                --i;
                continue;
            }

            return_code = PrimeN(n, &primes,  &size, &count);

            if (return_code == OVERFLOW){
                printf("Too big number!\n");
            }
            if (return_code == OK){
                printf("%d prime number is: %ld\n", n, primes[n - 1]);
            }

    } 
    }
    free(primes);
    return 0;
 
}