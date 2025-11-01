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
    strcpy(strRes, ptr);
    return OK;
}


ReturnCode WithoutFinishingSpaces(char * str, char * resStr) {
    if (!str) {
        return NULL_POINTER;
    }

    char * ptr = str + strlen(str) - 1;

    while (!isReadable(*ptr)) {
        --ptr;
    }
    
    *(ptr + 1) = '\0';
    strcpy(resStr, str);
    return OK;
}