#include "../include/functions.h"
#include <stddef.h>
#include <stdio.h>

Returncode print(FILE * file, Student * students, int * sizeStud) {
    if (!students || !sizeStud) {
        return NULL_POINTER;
    }
    
    for (int i = 0; i < *sizeStud; ++i) {
        Student student = students[i];
        fprintf(file, "id: %u\t name: %s\t surname: %s\t group: %s\t scores: ", student.id, student.name, student.surname, student.group);

        for (int i = 0; i < SCORES_SIZE; ++i) {
            if (!fprintf(file, "%c ", student.scores[i])) {
                return WRONG_STRUCT;
            }
        }
        fprintf(file, "\n");
    }
    return OK;
}