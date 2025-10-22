#include "../include/functions.h"
#include <ctype.h>

Returncode parseId(unsigned int * ID) {
    if (ID <= 0) {
        return WRONG_STRUCT;
    }
    return OK;
}

Returncode parseNameSurname(char * name) {
    if (!name) {
        return WRONG_STRUCT;
    }

    char * ptr = name;
    int isWrong = -1;
    while (*ptr) {
        if (!isalpha(*ptr)) {
            isWrong = 1;
            break;
        }
    }

    if (isWrong) {
        return WRONG_STRUCT;
    }
    return OK;
}

Returncode parseGroup(char * group) {
    if (!group) {
        return WRONG_STRUCT;
    }
    char * ptr = group;
    int isWrong = -1;
    while (*ptr) {
        if (!isalnum(*ptr)) {
            isWrong = 1;
            break;
        }
    }

    if (isWrong) {
        return WRONG_STRUCT;
    } 
    return OK;
}

Returncode parseScores(unsigned char * scores) {
    if (!scores) {
        return WRONG_STRUCT;
    }
    return OK;
}