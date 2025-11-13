#include "../include/functions.h"
#include <stdarg.h>
#include <stdio.h>

ReturnCode readChar(void * stream, char * c, bool fromString, int * chars) {
    if (!stream || !c || !fromString) {
        return NULL_POINTER;
    }

    if (fromString) {
        *c = ((char*)stream)[*chars];
        ++(*chars);
    } else {
        *c = fgetc((FILE*)stream);
        ++(*chars);
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
    int variables = 0; int res = 0; int chars;
    va_list arg_copy;
    char buffer[BUFSIZ] = {0};
    char * ptrWrite = buffer;

    while (*ptr) {
        printf("%c\n", *ptr);

        if (*ptr != '%') {

            returnCode = readChar(stream, &c, fromString, &chars);
            if (returnCode != OK) {return returnCode;}

            if (c != *ptr) {
                return READ_ERROR; // символы не совпали 
            } else {
                ++ptr;
                ++chars;
            }

        } else { 
            ++ptr;  // пропускаем процентик                    

            if (*ptr == 'R' && *(ptr + 1) == 'o') {
                printf("AAAAAAAAAAa\n");

                returnCode = readChar(stream, &c, fromString, &chars); // он не меняет чарс если чо (уже меняет)
                printf("C: %c\n", c);
                if (returnCode != OK) {return returnCode;}

                while (isRoman(c)) {
                    *ptrWrite = c;
                    ++ptrWrite;
                    returnCode = readChar(stream, &c, fromString, &chars);
                    printf("C: %c\n", c);
                }

               *ptrWrite = '\0';
                ptrWrite = buffer;
                printf("buf: %s", buffer);
                validateRoman(buffer); // добавить проверку норм не норм ваще
                int * variable = va_arg(*args, int *);
                returnCode = Roman(buffer, variable); //  добавить проверку
                if (returnCode != OK) {return returnCode;}
                variables++;
                ptr += 2;
            } else {
                return READ_ERROR;
            }
        
            // } else if (*ptr == 'Z' && *(ptr + 1) == 'r') {
             

            // } else if (*ptr == 'C' && (*(ptr + 1) == 'v' || *(ptr + 1) == 'V')) {

                

            // } else {
            //     // стандартные
            // }

        }
    }
    return chars;

}


int overfscanf(FILE * file, const char * format, ...) {
    int chars = 0;
    va_list args;
    va_start(args, format);
    chars = scan(file, format, &args, false);
    va_end(args);
    return chars;
}

int oversscanf(char * string, const char * format, ...) {
    int chars = 0;
    va_list args;
    va_start(args, format);
    chars = scan(string, format, &args, true);
    va_end(args);
    return chars;
}
