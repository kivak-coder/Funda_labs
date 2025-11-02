#include "../include/functions.h"
#include <__stdarg_va_list.h>
#include <stdarg.h>
#include <stdio.h>

int overfprintf(FILE * file, const char * format, ...) {
    va_list arg;
    va_start(arg, format);
    return OK;
}