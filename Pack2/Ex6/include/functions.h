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
Returncode find(Student * students, const void * toFind, Student * found, int * sizeStuds, int * sizeFound, int * capacityFound, Type type);
Returncode sort(Student * students, size_t * sizeStuds, Type type); 
Returncode print(FILE * file, Student * students, int * sizeStud);
Returncode parseId(unsigned int * ID);
Returncode parseNameSurname(char * name);
Returncode parseGroup(char * group);
Returncode parseScores(unsigned char * scores);
Returncode average(Student * students, int * sizeStuds, Student * foundStuds, double * avMax);
Returncode findType(char * userMsg, Type * type);