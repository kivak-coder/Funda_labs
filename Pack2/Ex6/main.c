#include "include/functions.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    if (argc == 1) {
        printf("Too few args\n");
        return 0;
    }

    char Input[FILENAME_MAX];    
    char Output[FILENAME_MAX];

    Returncode returnCode;
    strcpy(Input, argv[1]);
    strcpy(Output, argv[2]);

    FILE * inputFile = fopen(Input, "r");
    
    if (!inputFile) {
        printf("Error while opening an input file\n");
        return 0;
    }
    FILE * outputFile = fopen(Output, "w");
    if (!outputFile) {
        printf("Error while opening an output file\n");
    }

    int capacity = 0;
    printf("How many students do you enter?\n");
    scanf("%d", &capacity);

    // while (capacity <= 0) {
    //     printf("Wrong capacity!\n");
    //     scanf("%d", &capacity);
    // }

    Student * students = (Student*)malloc(capacity * sizeof(Student));

    if (!students) {
        printf("Some allocation mistake!\n");
        return 0;
    }
    
    returnCode = read(students, inputFile, &capacity);
    if (returnCode == WRONG_STRUCT) {
        printf("Wrong struct mistake!\n");
        return 0;
    }
    if (returnCode == NULL_POINTER) {
        printf("Come across a null pointer!\n");
        return 0;
    }
    printf("HETERTETR\n");
    print(outputFile, students, &capacity);
    char userMsg[100];
    char data[100];
    Type type;

    printf("Do you want to find someone? Enter STOP if you are done. Enter parameter to find at first.\n");
    while (strcmp(userMsg, "STOP") != 0) {
        scanf("%s", userMsg);
        returnCode = findType(userMsg,&type);

        if (returnCode != OK) {
            printf("Wrong data!\n");
            return 0;
        }

        printf("Enter the data you want to find.\n");
        scanf("%s", data);

        switch (type) {
            case ID:
                returnCode = parseId(data);
                break;

            case NAME:            
            case SURNAME:
                returnCode = parseNameSurname(data);
                break;

            case GROUP:
                returnCode = parseGroup(data);
                break;
        }
        printf("ALRIGHT\n");

        if (returnCode == OK) {
            Student * found = (Student*)malloc(capacity * sizeof(Student));
            if (!found) {
                printf("Allocation mistake\n");
                return 0;
            }
            int sizeFound = 0;
            find(students, data , found, &capacity, &sizeFound, &capacity, type);
            print(outputFile, found,&capacity);
        }

    }




    free(students);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}