#include "../include/functions.h"
#include <stdarg.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

ReturnCode overprint(void * stream, const char * format, va_list* arg, bool inString) {
    if (!stream || !format || !arg) {
        return NULL_POINTER;
    }

    int chars = 0;
    char buffer[BUFSIZ];
    ReturnCode returnCode;
    bool validFlag = false;
    const char * ptr = format;

    while (*ptr) {
        if (*ptr != '%') {
            if (inString) {
                ((char*)stream)[chars] = *ptr;
            } else {
                fputc(*ptr, stream);
            }
            chars++;

        } else {
            ++ptr;

            if (*ptr == 'R' && *(ptr + 1) == 'o') {
                int num = va_arg(*arg, int);
                returnCode = RomanNums(&num, buffer);

                if (returnCode != OK) {
                    return returnCode;
                }

                if (inString) {
                    vsprintf(buffer, format, *arg);
                } else {
                    fputs(buffer, (FILE*)stream);
                }
                
                ptr += 2;
                validFlag = true;

            } else if (*ptr == 'Z' && *(ptr + 1) == 'r') {
                int num = va_arg(*arg, int);
                returnCode = Zeckendorf(num, buffer);

                if (returnCode != OK) {
                    return returnCode;
                }

                if (inString) {
                    vsprintf(buffer, format, *arg);
                } else {
                    fputs(buffer, (FILE*)stream);
                }

                ptr += 2;
                validFlag = true;

            } else if (*ptr == 'C') {
                if (*(ptr + 1) == 'v') {
                    int num = va_arg(*arg, int);
                    const int base = va_arg(*arg, int); // здесь надо шобы автоматически оно было 10
                    returnCode = toNSys(num, buffer, base, false);

                    if (returnCode != OK) {
                        return returnCode;
                    }
                    if (inString) {
                        vsprintf(buffer, format, *arg);
                    } else {
                        fputs(buffer, (FILE*)stream);
                    }    

                    ptr += 2;
                    validFlag = true;
                }

                if (*(ptr + 1) == 'V') {
                    int num = va_arg(*arg, int);
                    const int base = va_arg(*arg, int); // здесь надо шобы автоматически оно было 10
                    returnCode = toNSys(num, buffer, base, true);

                    if (returnCode != OK) {
                        return returnCode;
                    }
                    if (inString) {
                        vsprintf(buffer, format, *arg);
                    } else {
                        fputs(buffer, (FILE*)stream);
                    }

                    ptr += 2;
                    validFlag = true;
                } 

            } else if ((*ptr == 't' && *(ptr + 1) == 'o') || (*ptr == 'T' && *(ptr + 1) == 'O')) {
                char * str = va_arg(*arg, char *);
                const int base = va_arg(*arg, int);
                returnCode = toDecSys(str, base, buffer);

                if (returnCode != OK) {
                    return returnCode;
                }

                if (inString) {
                    vsprintf(buffer, format, *arg);
                } else {
                    fputs(buffer, (FILE*)stream);
                }
                ptr += 2;

            } else if (*ptr == 'm') {
                if (*(ptr + 1) == 'i') {
                    int num = va_arg(*arg, int);
                }

                if (*(ptr + 1) == 'u') {
                    unsigned int num = va_arg(*arg, unsigned int);
                }

                if (*(ptr + 1) == 'd') {
                    double num = va_arg(*arg, double);
                }

                if (*(ptr + 1) == 'f') {
                    float num = va_arg(*arg, double); // а поч оно на флоат жаловалось
                }

            } else if (strchr("diufFeEgGxXoscpaA", *ptr)) {
                if (inString) {
                    vsprintf(buffer, format, *arg);
                } else {
                    vfprintf((FILE*)stream, format, *arg);
                }
 
            } else {
                return -1;
            }
        }
    }
    return chars; // как оно высчитывается в оригинальной функции?
}



int oversprintf(FILE * string, const char * format, ...) {
    va_list arg;
    va_start(arg, format);
    int chars = 0;
    chars = overprint(string, format, &arg, true);
    va_end(arg);
    return chars; // как оно высчитывается в оригинальной функции?
}

int overfprintf(FILE * file, const char * format, ...) {
    va_list arg;
    va_start(arg, format);
    int chars = 0;
    chars = overprint(file, format, &arg, true);
    va_end(arg);
    return chars; // как оно высчитывается в оригинальной функции?
}