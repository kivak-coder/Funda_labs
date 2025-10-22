#include "student.h"
#include <stddef.h>
#include <stdio.h>

typedef enum Returncode {
    OK,
    WRONG_STRUCT,
    NULL_POINTER,
    ERROR
} Returncode;

typedef enum Type {
    ID,
    NAME, 
    SURNAME, 
    GROUP
} Type;

#define EPS 1e15

Returncode read(Student * students, FILE * file, int * size);
Returncode find(Student * students, const void * toFind, Student * found, size_t * sizeStuds, size_t * sizeFound, size_t * capacityFound, Type type);
Returncode sort(Student * students, size_t * sizeStuds, Type type); 
Returncode parseStudent(Student * students);
Returncode print(FILE * file, Student * students, size_t * sizeStud);