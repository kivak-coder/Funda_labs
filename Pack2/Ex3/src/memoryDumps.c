#include "../include/functions.h"
#include <stddef.h>
#include <stdio.h>

ReturnCode memDump(void * data, size_t size, char * resStr) {
    if (!data || !resStr) {
        return NULL_POINTER;
    }

    if (size <= 0) {
        return INVALID_DATA;
    }

    unsigned char * ptr = (unsigned char*)data;
    char * resPtr = resStr;

    for (int i = 0; i < size; ++i) {
        unsigned char value = *(ptr + i);

        for (int j = 7; j >= 0; --j) {
            *resPtr = ((value >> j) & 1) + '0';
            ++resPtr;
        }
        
        if (i != 7) {
            *resPtr = ' ';
            ++resPtr;  
        }
      
    }
    *resPtr = '\0';
    return OK;
}
