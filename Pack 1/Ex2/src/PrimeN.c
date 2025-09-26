#include "../include/functions.h"
#include <math.h>
#include <limits.h>
#include <stdlib.h>



ReturnCode isPrime(int x){
    int lim = sqrt(x);
    if (x == 2){
        return PRIME;
    }
    if (x % 2 == 0){
        return COMPOSITE;
    } else {
        for (int i = 3; i <= lim; i+=2){
            if (x % i == 0){
                return COMPOSITE;
            }
        }
    }
    return PRIME;
}


ReturnCode PrimeN(long int n, long int ** primes, int * size, int * count){

    long int cur = (*primes)[*count - 1];
    int new_size = *size;

    if (n >= *size){

        while (new_size <= n){
            new_size *= 2;
        }

        long int * tmp = (long int *)realloc(*primes, (unsigned long)(new_size) * sizeof(long int));

        if (tmp == NULL){
            free(tmp);
            return ALLOCATION_MISTAKE;

        } else {
            for (int i = *size; i < new_size; i++) {
                tmp[i] = 0;
            }
            *primes = tmp;
        }
        *size = new_size;
    }
    
    if ((*primes)[n - 1] != 0){
        return OK;    

    } else {
        while (*count != n){
            cur += 2;
            if (isPrime(cur) == PRIME){
                (*primes)[*count] = cur;
                (*count)++;
            }

            if (cur >= LLONG_MAX - 2){
                return OVERFLOW;
            }
        } 
    }
    return OK;
}