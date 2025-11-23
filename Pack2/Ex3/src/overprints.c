#include "../include/functions.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


ReturnCode print(void * stream, char * buffer, int * chars, bool inString) {
    if (!stream || !buffer || !chars) {
        return NULL_POINTER;
    }

    int len = strlen(buffer);

    if (inString) {
        if (!strcpy(((char*)stream) + *chars, buffer)) {return WRITE_ERROR;}
    } else {
        if (fputs(buffer, (FILE*)stream) == EOF) {return WRITE_ERROR;};
    }
    *chars += len;
    return OK;
                
}

ReturnCode overprint(void * stream, const char * format, va_list* arg, bool inString) {
    if (!stream || !format || !arg) {
        return NULL_POINTER;
    }

    int chars = 0; int base = 10;
    char buffer[BUFSIZ] = {0};
    char specifier[32] = {'%'};
    ReturnCode returnCode;
    const char * ptr = format;
    bool up;
    va_list args_copy;

    while (*ptr) {
        if (*ptr != '%') {

            if (inString) {
                ((char*)stream)[chars] = *ptr;
            } else {
                fputc(*ptr, stream);
            }
            chars++;
            ptr++;
            continue;

        } else {
            ++ptr;

            if (*ptr == 'R' && *(ptr + 1) == 'o') {

                int num = va_arg(*arg, int);
                returnCode = RomanNums(&num, buffer);

                if (returnCode != OK) {
                    return returnCode;
                }

                returnCode = print(stream, buffer, &chars, inString);

                if (returnCode != OK) {
                    return returnCode;
                }
                
                ptr += 2;

            } else if (*ptr == 'Z' && *(ptr + 1) == 'r') {
                int num = va_arg(*arg, int);
                returnCode = Zeckendorf(num, buffer);

                if (returnCode != OK) {
                    return returnCode;
                }

                returnCode = print(stream, buffer, &chars, inString);

                if (returnCode != OK) {
                    return returnCode;
                }
                
                ptr += 2;

            } else if (*ptr == 'C') {
                if (*(ptr + 1) == 'v' || *(ptr + 1) == 'V') {
                    int num = va_arg(*arg, int);
                    va_list args_copy;
                    va_copy(args_copy, *arg);
                    
                    if (va_arg(args_copy, int)) {  
                        base = va_arg(*arg, int);  
                    } else {
                        base = 10;  
                    }
                    va_end(args_copy);

                    up = *(ptr + 1) == 'V'; 
                    returnCode = toNSys(num, buffer, base, up);
                    if (returnCode != OK) {
                        return returnCode;
                    }

                    returnCode = print(stream, buffer, &chars, inString);
                    if (returnCode != OK) {
                        return returnCode;
                    }
                    
                    ptr += 2;
                }

            } else if ((*ptr == 't' && *(ptr + 1) == 'o') || (*ptr == 'T' && *(ptr + 1) == 'O')) {
                char * str = va_arg(*arg, char *);
                va_list args_copy;
                va_copy(args_copy, *arg);
                
                if (va_arg(args_copy, int)) {  
                    base = va_arg(*arg, int);  
                } else {
                    base = 10;  
                }
                va_end(args_copy);
                returnCode = toDecSys(str, base, buffer);

                if (returnCode != OK) {
                    return returnCode;
                }
                returnCode = print(stream, buffer, &chars, inString);

                if (returnCode != OK) {
                    return returnCode;
                }
                
                ptr += 2;

            } else if (*ptr == 'm') {
                if (*(ptr + 1) == 'i') {
                    int num = va_arg(*arg, int);

                    returnCode = memDump(&num, sizeof(int), buffer);
                    if (returnCode != OK) {return returnCode;}

                    returnCode = print(stream, buffer, &chars, inString);
                    if (returnCode != OK) {return returnCode;}

                }

                if (*(ptr + 1) == 'u') {
                    unsigned int num = va_arg(*arg, unsigned int);

                    returnCode = memDump(&num, sizeof(unsigned int), buffer);
                    if (returnCode != OK) {return returnCode;}

                    returnCode = print(stream, buffer, &chars, inString);
                    if (returnCode != OK) {return returnCode;}

                }

                if (*(ptr + 1) == 'd') {
                    double num = va_arg(*arg, double);

                    returnCode = memDump(&num, sizeof(double), buffer);
                    if (returnCode != OK) {return returnCode;}

                    returnCode = print(stream, buffer, &chars, inString);
                    if (returnCode != OK) {return returnCode;}

                }

                if (*(ptr + 1) == 'f') {
                    float num = va_arg(*arg, double);

                    returnCode = memDump(&num, sizeof(float), buffer);
                    if (returnCode != OK) {return returnCode;}

                    returnCode = print(stream, buffer, &chars, inString);
                    if (returnCode != OK) {return returnCode;}

                }
                ptr += 2;

            } else {
                int len = 1;

                while (*ptr && !strchr("diouxXeEfFgGaAcspn", *ptr)) {
                    specifier[len] = *ptr;
                    ++ptr; ++len;

                }
                if (strchr("diouxXeEfFgGaAcspn", *ptr)) {
                    specifier[len] = *ptr;
                    ++len;
                }
                specifier[len] = '\0';

                int written = -1;
                va_copy(args_copy, *arg);

                if (inString) {
                    written = vsnprintf((char*)stream + chars, BUFSIZ - chars, specifier, *arg);
                } else {
                    written = vfprintf((FILE*)stream, specifier, *arg);
                }

                va_end(args_copy);
                if (written < 0) {return WRITE_ERROR;}
                chars += written;
                ptr++;

            }
        }
    }

    if (inString) {                
        ((char*)stream)[chars] = '\0';
    }

    return chars; 
}

int oversprintf(char * string, const char * format, ...) {
    va_list arg;
    va_start(arg, format);
    int chars = 0;
    chars = overprint(string, format, &arg, true);
    va_end(arg);

    return chars; 
}

int overfprintf(FILE * file, const char * format, ...) {
    va_list arg;
    va_start(arg, format);
    int chars = 0;
    chars = overprint(file, format, &arg, false);
    va_end(arg);

    return chars; 
}