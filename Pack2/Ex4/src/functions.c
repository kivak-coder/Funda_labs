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
    int variables = 0; int res = 0; int chars = 0;
    va_list arg_copy;
    char buffer[BUFSIZ] = {0};
    char * ptrWrite = buffer;

    while (*ptr) {

        if (*ptr != '%') {

            returnCode = readChar(stream, &c, fromString, &chars);
            // printf("char: %c\n", c);
            // printf("ptr: %c\n", *ptr);
            if (returnCode != OK) {return returnCode;}

            if (c != *ptr) {
                return READ_ERROR; // символы не совпали 
            } else {
                ++ptr;
            }

        } else { 
            ++ptr;  // пропускаем процентик                    

            if (*ptr == 'R' && *(ptr + 1) == 'o') {

                ptr += 2;
                returnCode = readChar(stream, &c, fromString, &chars); // он не меняет чарс если чо (уже меняет)
                if (returnCode != OK) {return returnCode;}

                while (*ptr != c && c != '\0') {
                    printf("c: %c\n", c);
                    *ptrWrite = c;
                    ++ptrWrite;
                    returnCode = readChar(stream, &c, fromString, &chars);
                    if (returnCode != OK) {return returnCode;}
                }

               *ptrWrite = '\0';
                ptrWrite = buffer;
                returnCode = validateRoman(buffer); 
                if (returnCode != OK) {return returnCode;}

                int * variable = va_arg(*args, int *);
                returnCode = Roman(buffer, variable); 
                if (returnCode != OK) {return returnCode;}

                variables++;
                ++ptr;
        
            } else if (*ptr == 'Z' && *(ptr + 1) == 'r') {
                ptr += 2;
                returnCode = readChar(stream, &c, fromString, &chars); // он меняет чарс если чо 

                if (returnCode != OK) {return returnCode;}

                while (*ptr != c && c != '\0') {
                    *ptrWrite = c;
                    ++ptrWrite;
                    returnCode = readChar(stream, &c, fromString, &chars);
                    if (returnCode != OK) {return returnCode;}
                }

               *ptrWrite = '\0';
                printf("%s\n", buffer);
                ptrWrite = buffer;

                returnCode = validateZeckendorf(buffer); 
                if (returnCode != OK) {return returnCode;}

                int * variable = va_arg(*args, int *);
                returnCode = Zeckendorf(buffer, variable); 
                printf("%i\n", *variable);
                if (returnCode != OK) {return returnCode;}

                variables++;
                ++ptr;

            } else if (*ptr == 'C' && (*(ptr + 1) == 'v' || *(ptr + 1) == 'V')) {
                ptr += 2;
                returnCode = readChar(stream, &c, fromString, &chars); // он меняет чарс если чо 

                if (returnCode != OK) {return returnCode;}

                while (*ptr != c && c != '\0') {
                    *ptrWrite = c;
                    ++ptrWrite;
                    returnCode = readChar(stream, &c, fromString, &chars);
                    if (returnCode != OK) {return returnCode;}
                }

               *ptrWrite = '\0';
                ptrWrite = buffer; 
                // дальше считываем основание системы счисения

                int * variable = va_arg(*args, int *);
                int base = va_arg(*args, int);

                if (base > 36 || base < 2) {
                    return INVALID_DATA;
                }

                returnCode = validateNumInBase(buffer, base); 
                if (returnCode != OK) {return returnCode;}

                returnCode = toDecSys(buffer, variable, base); 
                if (returnCode != OK) {return returnCode;}

                variables++;
                ++ptr;

            } else {
            return READ_ERROR;
            }
        }
    }
    return variables;
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
