// WithoutSpaces.c
#include "../include/functions.h"
#include <string.h>

ReturnCode WithoutLeadingSpaces(char * str, char * strRes) {
    if (!str || !strRes) {
        return NULL_POINTER;
    }

    char * ptr = str;
    while (*ptr == ' ' || *ptr == '\t') {
        ++ptr;
    }
    
    size_t len = strlen(ptr);
    if (len >= BUFSIZ) {
        len = BUFSIZ - 1;
    }
    strncpy(strRes, ptr, len);
    strRes[len] = '\0';
    
    return OK;
}

ReturnCode WithoutFinishingSpaces(char * str, char * strRes) {
    if (!str || !strRes) {
        return NULL_POINTER;
    }

    size_t len = strlen(str);
    if (len == 0) {
        strRes[0] = '\0';
        return OK;
    }

    int lastReadable = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (isReadable(str[i])) {
            lastReadable = i;
            break;
        }
    }

    if (lastReadable == -1) {
        strRes[0] = '\0';
    } else {
        strncpy(strRes, str, lastReadable + 1);
        strRes[lastReadable + 1] = '\0';
    }
    
    return OK;
}