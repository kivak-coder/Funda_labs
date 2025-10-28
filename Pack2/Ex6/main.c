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

    int capacityAll = 1; int capacityFound = 1; int capacityAv = 1;
    int sizeAll = 0; int sizeFound = 0; int sizeAv = 0;

    char userMsg[100]; // уберите сто!!!!!!!
    char data[100];
    Type type;
    bool isFound = false;
    Returncode returnCode;
    double avMax = 0.0;


    capacityAll = 6;

    // while (capacity <= 0) {
    //     printf("Wrong capacity!\n");
    //     scanf("%d", &capacity);
    // }

    Student * students = (Student*)malloc(capacityAll * sizeof(Student));

    if (!students) {
        printf("Some allocation mistake!\n");
        return 0;
    }
    
    returnCode = read(students, inputFile, &capacityAll, &sizeAll);
    printf("Size: %d\n", sizeAll);
    if (returnCode == WRONG_STRUCT) {
        printf("Wrong struct mistake!\n");
        return 0;
    }
    if (returnCode == NULL_POINTER) {
        printf("Come across a null pointer!\n");
        return 0;
    }
    // print(outputFile, students, &sizeAll);

    printf("Do you want to find someone? Enter STOP if you are done. Enter parameter to find at first.\n");
    fgets(userMsg, 99, stdin); 
    while (strcmp(userMsg, "STOP\n") != 0) { //
        // fgets(userMsg, 99, stdin);
        returnCode = findType(userMsg,&type);

        if (returnCode != OK) {
            printf("Wrong data!\n");
            return 0;
        }

        printf("Enter the data you want to find.\n");
        fgets(data, 99, stdin);

        char * ptr = strchr(data, '\n');
        if (ptr) {
            *ptr = '\0';
        }

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
            Student * found = (Student*)malloc(capacityFound * sizeof(Student));
            if (!found) {
                printf("Allocation mistake\n");
                return 0;
            }
            find(students, data, &found, &sizeAll, &sizeFound, &capacityFound, type, &isFound);                


            if (isFound) {
                printf("Found %i people with this parameter\n", sizeFound);
                print(outputFile, found,&sizeFound);
                isFound = false;
                sizeFound = 0;
            } else {
                printf("Could not find anyone\n");
            }
            printf("Do you want to find someone? Enter STOP if you are done. Enter parameter to find at first.\n");

        }

    }
    printf("Do you want to sort data? Enter the parameter (ID/NAME/SURNAME/GROUP). Enter STOP when you are done.\n");

    while (strcmp(userMsg, "STOP") != 0) {
        scanf("%s", userMsg);
        returnCode = findType(userMsg,&type);

        if (returnCode != OK) {
            printf("Wrong data!\n");
            return 0;
        }
        returnCode = sort(students, &sizeAll, type);
        print(outputFile, students, &sizeAll);
    }
    char answer;
    printf("Do you want to print students with max average scores? (Y/N) \n");
    scanf("%c", &answer);
    if (answer == 'N') {
        printf("See yor result in a file!\n");
    } 
    if (answer == 'Y') {
        Student * avStuds = (Student *)malloc(sizeAll * sizeof(Student));
        returnCode = average(students,&sizeAll, avStuds, &avMax, &sizeAv); // maybe double pointer??
        print(outputFile, avStuds, &sizeAv);
    }
    // free(found); // а чо надо то писать??
    free(students);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}