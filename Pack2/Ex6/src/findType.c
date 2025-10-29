#include "../include/functions.h"
#include <string.h>

Returncode findType(char * userMsg, Type * type) {
    Returncode returnCode;
    int flag = 0;
    
    char * ptr = strchr(userMsg, '\n');
    if (ptr) {
        *ptr = '\0';
    }

    if (strcmp(userMsg, "id") == 0) {
        flag = 1;
        *type = ID;
    }

    if (strcmp(userMsg, "name") == 0) {
        flag = 1;
        *type = NAME;
    }

    if (strcmp(userMsg, "surname") == 0) {
        flag = 1;
        *type = SURNAME;
    }

    if (strcmp(userMsg, "group") == 0) {
        flag = 1;
        *type = GROUP;
    }
    if (flag) {
        return OK;
    } else {
        return WRONG_STRUCT;
    }

}