#include "../include/functions.h"
#include <string.h>

Returncode findType(char * userMsg, Type * type) {
    Returncode returnCode;
    int flag = 0;
    
    char * ptr = strchr(userMsg, '\n');
    if (ptr) {
        *ptr = '\0';
    }

    if (strcmp(userMsg, "ID") == 0) {
        flag = 1;
        *type = ID;
    }

    if (strcmp(userMsg, "NAME") == 0) {
        flag = 1;
        *type = NAME;
    }

    if (strcmp(userMsg, "SURNAME") == 0) {
        flag = 1;
        *type = SURNAME;
    }

    if (strcmp(userMsg, "GROUP") == 0) {
        flag = 1;
        *type = GROUP;
    }
    if (flag) {
        return OK;
    } else {
        return WRONG_STRUCT;
    }

}