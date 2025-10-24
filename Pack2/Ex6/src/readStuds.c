#include "../include/functions.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

Returncode read(Student * students, FILE * inputFile, int * capacity) {
    if (students == NULL || capacity == NULL) {
        return NULL_POINTER;
    }
    
    char str[BUFSIZ];
    unsigned int id0 = 0;
    int res = 0; int count = 0;
    char name0[STUD_CAP];
    char surname0[STUD_CAP];
    char group0[GROUP_CAP];
    unsigned char scores0[SCORES_SIZE] = {0};
    Returncode returnCode;
    
    while (count < *capacity) {
        printf("%d %d", count, *capacity);
        res = fscanf(inputFile, "%d %s %s %s %c %c %c %c %c", &id0, name0, surname0, group0, &scores0[0], &scores0[1], &scores0[2], &scores0[3], &scores0[4]);

        if (res == EOF) {break;}
        if (res != 9) {return WRONG_STRUCT;}

        Student stud;
        
        returnCode = parseId(&id0);
        if (returnCode == OK) {
            stud.id = id0;
        } else {
            printf("1");
            return WRONG_STRUCT;
        }

        returnCode = parseNameSurname(name0);
        if (returnCode == OK) {
            strcpy(stud.name, name0);
        } else {
            printf("2");
            return WRONG_STRUCT;
        }

        returnCode = parseNameSurname(surname0);
        if (returnCode == OK) {
            strcpy(stud.surname, surname0);
        } else {

            printf("3");
            return WRONG_STRUCT;
        }

        returnCode = parseGroup(group0);
        if (returnCode == OK) {
            strcpy(stud.group, group0);
        } else {
            printf("4");
            return WRONG_STRUCT;
        }

        returnCode = parseScores(scores0);
        if (returnCode == OK) {
            for (int i = 0; i < SCORES_SIZE; i++) {
                stud.scores[i] = scores0[i];
            }
        } else {
            printf("5");
            return WRONG_STRUCT;
        }

        students[count] = stud;
        count++;
        printf("%d %s %s %s %c %c %c %c %c\n", stud.id, stud.name, stud.surname, stud.group, stud.scores[0], stud.scores[1], stud.scores[2], stud.scores[3], stud.scores[4]);
    }
    return OK;

}