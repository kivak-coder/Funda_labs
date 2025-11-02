#include "../include/functions.h"

ReturnCode validateZeckendorf(char * str) {
    if (!str) {
        return NULL_POINTER;
    }

    char * ptr = str;
    while (*ptr) {
        if (*ptr != '1' && *ptr != '0') {
            return INVALID_DATA;
        }
        ++ptr;
    }
    return OK;
}

