#include "../include/functions.h"
#include <stddef.h>
#include <stdio.h>

Returncode print(FILE * file, Student * students, int * sizeStud) {
    if (!students || !sizeStud) {
        return NULL_POINTER;
    }

    for (size_t i = 0; i < *sizeStud; ++i) {
        Student student = students[i];
        if (!fprintf(file, "student id: %u, name: %s, surname: %s, group: %s scores: ", student.id, student.name, student.surname, student.group)) {
            return ERROR;
        }
        for (int i = 0; i < SCORES_SIZE; ++i) {
            if (!fprintf(file, "%c ", student.scores[i])){
                return WRONG_STRUCT;
            }
        }
        fprintf(file, "\n");
    }
    return OK;
}