#include "../include/functions.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

ReturnCode readChar(void * stream, char * c, bool fromString, int * chars) {
    if (!stream || !c) {
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
    char specifier[100] = {0};


    while (*ptr) {
        printf("ptr: %c\n", *ptr);
        if (*ptr != '%') {

            returnCode = readChar(stream, &c, fromString, &chars);
            printf("char: %c\n", c);
            printf("ptr: %c\n", *ptr);
            if (returnCode != OK) {return returnCode;}

            if (c != *ptr) {
                printf("HUI\n");
                return READ_ERROR; // символы не совпали 
            } else {
                ++ptr;
            }

        } else { 
            ++ptr;  
            if (*ptr == 'R' && *(ptr + 1) == 'o') {

                ptr += 2;
                returnCode = readChar(stream, &c, fromString, &chars); 
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

        
            } else if (*ptr == 'Z' && *(ptr + 1) == 'r') {
                ptr += 2;
                returnCode = readChar(stream, &c, fromString, &chars); 
                if (returnCode != OK) {return returnCode;}

                while (*ptr != c && c != '\0') {
                    *ptrWrite = c;
                    ++ptrWrite;
                    returnCode = readChar(stream, &c, fromString, &chars);
                    if (returnCode != OK) {return returnCode;}
                }

               *ptrWrite = '\0';
                ptrWrite = buffer;

                returnCode = validateZeckendorf(buffer); 
                if (returnCode != OK) {return returnCode;}

                int * variable = va_arg(*args, int *);
                returnCode = Zeckendorf(buffer, variable); 
                if (returnCode != OK) {return returnCode;}

                variables++;

            } else if (*ptr == 'C' && (*(ptr + 1) == 'v' || *(ptr + 1) == 'V')) {
                ptr += 2;
                returnCode = readChar(stream, &c, fromString, &chars); 
                if (returnCode != OK) {return returnCode;}

                while (*ptr != c && c != '\0') {
                    *ptrWrite = c;
                    ++ptrWrite;
                    returnCode = readChar(stream, &c, fromString, &chars);
                    if (returnCode != OK) {return returnCode;}
                }

               *ptrWrite = '\0';
                ptrWrite = buffer; 

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

            } else {
                printf("ptr:%c\n", *ptr);
                char specifier[40] = {'%'};
                int len = 1;
                
                while (*ptr && !strchr("diufFeEgGxXoscpaA", *ptr)) {
                    specifier[len++] = *ptr++;
                    if (len >= 38) break;
                }
                
                if (!*ptr) return INVALID_DATA; 
                
                specifier[len++] = *ptr;
                specifier[len] = '\0';
                
                ++ptr;
                
                va_list args_copy;
                va_copy(args_copy, *args);
                
                int scanned = 0;
                if (!fromString) {
                    scanned = vfscanf((FILE*)stream, specifier, args_copy);
                } else {
                }
                va_end(args_copy);
                
                if (scanned <= 0) {
                    printf("A tut\n");
                    return READ_ERROR;
                } 
                for (int i = 0; i < scanned; i++) {
                    va_arg(*args, void*);
                }
                
                variables += scanned;
            }
        }
        ++ptr;
    }
    return variables;
}


int overfscanf(FILE * file, const char * format, ...) {
    int variables = 0;
    va_list args;
    va_start(args, format);
    variables = scan(file, format, &args, false);
    va_end(args);
    return variables;
}

int oversscanf(char * string, const char * format, ...) {
    int variables = 0;
    va_list args;
    va_start(args, format);
    variables = scan(string, format, &args, true);
    va_end(args);
    return variables;
}
