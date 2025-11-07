#include "../include/functions.h"
#include <stdarg.h>
#include <stdio.h>

ReturnCode readChar(void * stream, char * c, bool fromString, int * chars) {
    if (!stream || !c || !fromString) {
        return NULL_POINTER;
    }

    if (fromString) {
        *c = ((char*)stream)[*chars];
    } else {
        *c = fgetc((FILE*)stream);
        if (*c == EOF) {return READ_ERROR;}
    }
    return OK;
}

ReturnCode scan(void * stream, const char * format, va_list * args, bool fromString) {
    if (!stream || !format || !args) {
        return NULL_POINTER;
    }

    const char * ptr = format;
    ReturnCode returnCode;
    char c;
    int chars = 0; int res = 0;
    va_list arg_copy;
    char buffer[BUFSIZ];

    while (*ptr) {
        if (*ptr != '%') {

            returnCode = readChar(stream, &c, fromString, &chars);
            if (returnCode != OK) {return returnCode;}

            if (c != *ptr) {
                return READ_ERROR; // символы не совпали совсем ((
            } else {
                ++ptr;
                ++chars;
            }

        } else {
            if (*ptr == 'R' && *(ptr + 1) == 'o') {
                

            } else if (*ptr == 'Z' && *(ptr + 1) == 'r') {
             

            } else if (*ptr == 'C' && (*(ptr + 1) == 'v' || *(ptr + 1) == 'V')) {
                void * variable = va_arg(*args, void *);

                

            } else {
                // стандартные
            }

        }
    }
    return chars;

}
