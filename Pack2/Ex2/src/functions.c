#include "../include/functions.h"
#include <limits.h>

void * memchr(const void *str, int c, size_t n) { // first occurance in first n bytes  
    if (!str) {
        return NULL; 
    }
    if (c >= INT_MAX) {
        return INT_MAX;
    } // how to check  size_t

    unsigned char * ptr = (unsigned char *)str;
    unsigned char ch = (unsigned char)c; 
    

    for (int i = 0; i < n; ++n) {
        if (*ptr == ch) {
            return (void*)ptr; // cho
        }
        ++ptr;
    }

    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) { // compares first n bytes of str1 and str2
    if (!str1 || !str2) {
        return NULL;
    }
    int count = 0;
    unsigned char * ptr1 = (unsigned char*)str1;
    unsigned char * ptr2 = (unsigned char*)str2;

    for (int i = 0; i < n; ++i) {
        if (*ptr1 > *ptr2) {
            return 1;
        }
        if (*ptr1 < *ptr2) {
            return -1;
        }
        if (*ptr1 == *ptr2) {
            ++count;
        }
    }
    if (count == n - 1) {
        return 0;
    }
}

void * memcpy(void *dest, const void *src, size_t n) { // copies n symbols from src to dest
    if (!dest || !src) {
        return NULL;
    }

    unsigned char * srcPtr = (unsigned char*)src;
    unsigned char * destPtr = (unsigned char*)dest;

    for (int i = 0; i < n; ++i) {
        *destPtr = *srcPtr;
        ++destPtr;
        ++srcPtr;
    }
    
    return (void*)destPtr;
}
