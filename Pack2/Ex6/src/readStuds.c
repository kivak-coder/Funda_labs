#include "../include/functions.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Returncode read(Student ** students, FILE * inputFile, int * capacity, int * size) {
    if (students == NULL || capacity == NULL) {
        return NULL_POINTER;
    }
    if (*capacity == 0) {
        *capacity = 1;
    }
    
    unsigned int id0 = 0;
    int res = 0; 
    char name0[STUD_CAP];
    char surname0[STUD_CAP];
    char group0[GROUP_CAP];
    unsigned char scores0[SCORES_SIZE] = {0};
    Returncode returnCode;
    
    res = fscanf(inputFile, "%d %s %s %s %c %c %c %c %c", &id0, name0, surname0, group0, &scores0[0], &scores0[1], &scores0[2], &scores0[3], &scores0[4]);
    while (res != EOF) {

        if (res == EOF) {break;}
        if (res != 9) {return WRONG_STRUCT;}

        Student stud;

        if (*size == *capacity) {
            *capacity *= 2;
            Student * tmp = (Student*)realloc(*students, *capacity * sizeof(Student));
            if (!tmp) {
                return ALLOCATION_ERROR;
            }
            *students = tmp;
        }
        
        returnCode = parseId(&id0);
        if (returnCode == OK) {
            stud.id = id0;
        } else {
            return WRONG_STRUCT;
        }

        returnCode = parseNameSurname(name0);
        if (returnCode == OK) {
            strcpy(stud.name, name0);
        } else {
            return WRONG_STRUCT;
        }

        returnCode = parseNameSurname(surname0);
        if (returnCode == OK) {
            strcpy(stud.surname, surname0);
        } else {

            return WRONG_STRUCT;
        }

        returnCode = parseGroup(group0);
        if (returnCode == OK) {
            strcpy(stud.group, group0);
        } else {
            return WRONG_STRUCT;
        }

        returnCode = parseScores(scores0);
        if (returnCode == OK) {
            for (int i = 0; i < SCORES_SIZE; i++) {
                stud.scores[i] = scores0[i];
            }
        } else {
            return WRONG_STRUCT;
        }

        (*students)[*size] = stud;
        (*size)++;
        res = fscanf(inputFile, "%d %s %s %s %c %c %c %c %c", &id0, name0, surname0, group0, &scores0[0], &scores0[1], &scores0[2], &scores0[3], &scores0[4]);
    }
    return OK;

}