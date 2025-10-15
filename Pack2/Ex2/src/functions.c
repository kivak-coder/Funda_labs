#include "../include/functions.h"
#include "../include/errors_macro.h"
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void * memchr(const void *str, int c, size_t n) { // first occurance in first n bytes  
    if (n > strlen(str)) {
        n = strlen(str);
    }

    if (str == NULL) {
        return NULL; 
    }

    unsigned char * ptr = (unsigned char *)str;
    unsigned char ch = (unsigned char)c; 
    
    for (int i = 0; i < n; ++i) {
        if (*ptr == ch) {
            return (void*)ptr; 
        }
        ++ptr;
    }

    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) { // compares first n bytes of str1 and str2
   if (str1 == NULL || str2 == NULL) {
        return NULL;
    }
    const char * ptr1 = str1;
    const char * ptr2 = str2;
    int i = 1; int count = 0;

    while (i <= n) {
        if (*ptr1 > *ptr2) {
            return 1;
        }
        if (*ptr1 < *ptr2) {
            return -1;
        }
        if (*ptr1 == *ptr2) {
            ++count;
        }
        ++i; 
        ++ptr1;
        ++ptr2;
    }
    if (count == n) {
        return 0;
    }
}


void * memcpy(void *dest, const void *src, size_t n) { // copies n symbols from src to dest
    if (dest == NULL|| src == NULL) {
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


void *memset(void *str, int c, size_t n) { // copies c into first n symbols of str
    if (str == NULL) {
        return NULL;
    }

    if (n >= strlen(str) && strlen(str) != 0) {
        n = strlen(str);
    }

    unsigned char * ptr = (unsigned char *) str;
    unsigned char ch = (unsigned char) c;

    for (int i = 0; i < n; ++i) {
        *ptr = ch;
        ++ptr;
    }
    return (void*)ptr; // cho vozvrashat?
}

char *strncat(char *dest, const char *src, size_t n) { // adds string src in the end of dest 
    if (dest == NULL || src == NULL) {
        return NULL;
    } 
    if (n > strlen(src)) {
        n = strlen(src);
    }

    const char * ptrSrc = src;
    int len = strlen(dest);

    for (int i = len; i < n + len; ++i) {
        dest[i] = *ptrSrc;
        ++ptrSrc;
    }
    return dest;
}

char *strchr(const char *str, int c) { //first occurance of c in str
    if (str == NULL) {
        return NULL;
    }

    unsigned char ch = (unsigned char)c;
    const char * p = str;

    while (*p) {
        if (*p == c) {
            return (char*)p; 
        }
        ++p;
    }
    return NULL;
}

int strncmp(const char *str1, const char *str2, size_t n) { // compares not more than n first bytes of str1 and str2
   if (str1 == NULL || str2 == NULL) {
        return NULL;
    }
    const char * ptr1 = str1;
    const char * ptr2 = str2;
    int i = 1; int count = 0;

    while (*ptr1 && *ptr2 && i <= n) {
        if (*ptr1 > *ptr2) {
            return 1;
        }
        if (*ptr1 < *ptr2) {
            return -1;
        }
        if (*ptr1 == *ptr2) {
            ++count;
        }
        ++i; 
        ++ptr1;
        ++ptr2;
    }
    if (count == n) {
        return 0;
    }
}

char *strncpy(char *dest, const char *src, size_t n) { // copies up to n symbols from src to dest
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    if (n >= strlen(src) && n >= strlen(dest)) {
        if (strlen(src) > strlen(dest) && strlen(dest) != 0) {
            n = strlen(dest);
        } else {
            n = strlen(dest);
        }
    }

    char * ptrDest = dest;
    const char * ptrSrc = src;

    for (int i = 0; i < n; ++i) {
        *ptrDest = *ptrSrc;
        ++ptrDest;
        ++ptrSrc;
    }
    return ptrDest;
}

size_t strcspn(const char *str1, const char *str2) { // counts lengths of str1 that contains symbols that are not in str2
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    const char * ptr = str1;
    size_t count = 0;
    bool WasIn = false;
    while (*ptr) {
        if (!strchr(str2, *ptr)) {
            WasIn = true;
            ++count;
        } else {
            if (WasIn) {
                return count;
            }
        }
        ++ptr;
    }
    return count;
}

char *strerror(int errnum) { // ...
    if (errnum < 0 || errnum > MAX_ERRNO) {
        return "Unknown error";
    }
    const char *msg = ERROR_MESSAGES[errnum];
    return (char*)msg;
}

size_t strlen(const char *str) { // counts length of str (without 0)
    if (str == NULL) {
        return NULL;
    }

    size_t len = 0;
    const char * ptr = str;
    while (*ptr) {
        ++len;
        ++ptr;
    }
    return len;
}

char *strpbrk(const char *str1, const char *str2) { // finds first symbol in str1 that responds any symbol in str2
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }
    const char * ptr = str1;

    while (*ptr) {
        if (strchr(str2, *ptr)){
            return (char*)ptr; 
        }
        ++ptr;
    }
    return NULL;
}

char *strrchr(const char *str, int c) { // last occurance of c in str
    if (str == NULL) {
        return NULL;
    }
    unsigned char ch = (unsigned char)c;
    const char * p = str + strlen(str) - 1; // pointer to the end

    for (int i = strlen(str) - 1; i >= 0; ++i) {
        if (*p == c) {
            return (char*)p;
        } 
        --p;
    }
    return NULL;
}

char *strstr(const char *haystack, const char *needle) { // first occurance of needle (without 0) that appears in haystack
    if (haystack == NULL || needle == NULL) { 
        return NULL;
    }
    if (strlen(needle) > strlen(haystack)) {
        return NULL; 
    }
    if (strlen(needle) == strlen(haystack) && strncmp(haystack, needle, strlen(needle))) {
        return (char*)haystack;
    }

    const char * ptrHay = haystack;
    const char * ptrNeedle = needle;
    *((char*)(ptrNeedle + strlen(needle))) = 0;
    int count = 0;

    while (*ptrHay) {
        if (*ptrHay == *ptrNeedle) {
            ++ptrNeedle;
        } else {
            ptrNeedle = needle;
            if (*ptrHay == *ptrNeedle) {
                ++ptrNeedle;
            }
        }
        if (*ptrNeedle == '\0') {
            ptrHay -= (strlen(needle) - 1);
            return (char*)ptrHay;
        }
        ++ptrHay;  
    }
    return NULL;
}

bool isToken(int c, const char *delim) {
    const char *ptr = delim;
    while (*ptr) {
        if (*ptr == c) {
            return true;
        }
        ++ptr;
    }
    return false;
}

char *strtok(char *str, const char *delim) {
    static char *ptrSave = NULL;
    char *tokenStart;

    if (str == NULL) {
        if (ptrSave == NULL) return NULL;
        str = ptrSave;
    }

    while (*str != '\0' && isToken(*str, delim)) {
        str++;
    }

    if (*str == '\0') {
        ptrSave = NULL;
        return NULL;
    }

    tokenStart = str;

    while (*str != '\0') {
        if (isToken(*str, delim)) {
            *str = '\0';
            ptrSave = str + 1;
            return tokenStart;
        }
        str++;
    }

    ptrSave = NULL;
    return tokenStart;
}





