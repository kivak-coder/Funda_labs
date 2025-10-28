#include "../include/functions.h"
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

Returncode print(FILE * file, Student * students, int * size) {
    printf("ABOB\n");
    printf("size: %i\n", *size);
    if (!students || !size || !file) {
        return NULL_POINTER;
    }
    
    for (int i = 0; i < *size; ++i) {
        Student student = students[i];
        int code = fprintf(file, "%u\t %s\t %s\t %s\t ", student.id, student.name, student.surname, student.group);
        if (code < 0) {
            printf("er: %s", strerror(errno));
            printf("IRIRIRI\n");
            return WRONG_STRUCT;
        }

        for (int j = 0; j < SCORES_SIZE; ++j) {
            if (!fprintf(file, "%c ", student.scores[j])) {
                return WRONG_STRUCT;
            }
        }
        fprintf(file, "\n");
    }
    return OK;
}