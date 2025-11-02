#include "../include/functions.h"

ReturnCode Zeckendorf(char *str, int *res) {
    if (!str || !res) {
        return NULL_POINTER;
    }

    int capacity = CAPACITY; int size = 1;
    int a = 0; int b = 1; int c = 1;

    // unsigned int * fibonacci = (unsigned int *)calloc(sizeof(unsigned int), capacity);
    char * ptr = str;

    while (*ptr) {
        if (*ptr == '1' && *(ptr + 1) == '\0') {
            break;
        }
        c = a + b;
        a = b;
        b = c;
        if (*ptr == '1') {
            *res += c;
        }
        ++ptr;
    }

    return OK; 
}