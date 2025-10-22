#include "../include/functions.h"
#include <stdio.h>

Returncode read(Student * students, FILE * inputFile, int * size) {
    if (students == NULL || size == NULL) {
        return NULL_POINTER;
    }
    return OK;
}