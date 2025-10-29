#include "include/functions.h"
#include <linux/limits.h>
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
    FILE * inputFile;
    FILE * outputFile;


    strcpy(Input, argv[1]);
    strcpy(Output, argv[2]);

    inputFile = fopen(Input, "r");
    
    if (!inputFile) {
        printf("Error while opening an input file\n");
        return 0;
    }

    outputFile = fopen(Output, "w");
    if (!outputFile) {
        printf("Error while opening an output file\n");
        return 0;
    }

    int capacityAll = CAPACITY; int capacityFound = CAPACITY;
    int sizeAll = 0; int sizeFound = 0; int sizeAv = 0;

    char userMsg[MAX_INPUT]; 
    char data[MAX_INPUT];
    Type type;
    bool isFound = false;
    Returncode returnCode;
    double avMax = 0.0;
    char * endptr = NULL;

    Student * students = (Student*)malloc(capacityAll * sizeof(Student));

    if (!students) {
        printf("Some allocation error!\n");
        return 0;
    }
    
    returnCode = read(&students, inputFile, &capacityAll, &sizeAll);

    if (returnCode == WRONG_STRUCT) {
        printf("Wrong struct error!\n");
        return 0;
    }
    if (returnCode == NULL_POINTER) {
        printf("Come across a null pointer!\n");
        return 0;
    }
    
    printf("\033[1;36mDo you want to find someone? Enter STOP when you are done. Enter parameter to find at first.\033[0m\n");

    fgets(userMsg, MAX_INPUT - 1, stdin); 
    while (strcmp(userMsg, "STOP\n") != 0) { 
        returnCode = findType(userMsg,&type);

        if (returnCode != OK) {
            printf("Wrong input!\n");
            return 0;
        }
        printf("\033[1;36mEnter the data you want to find.\033[0m\n");
        fgets(data, MAX_INPUT, stdin);

        char * ptr = strchr(data, '\n');
        if (ptr) {
            *ptr = '\0';
        }
        unsigned int id = 0;
        switch (type) {
            case ID:
                id = strtol(data, &endptr, 10);
                if (endptr == (const char*)data) {
                    printf("Wrong input!\n");
                }
                if (*endptr != '\0') {
                    printf("Wrong input!\n");
                }
                returnCode = parseId(&id);
                break;

            case NAME:            
            case SURNAME:
                returnCode = parseNameSurname(data);
                break;

            case GROUP:
                returnCode = parseGroup(data);
                break;
        }
        

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
            printf("\033[1;36mDo you want to find someone? Enter STOP if you are done. Enter parameter to find at first.\033[0m\n");                
            free(found);
            fgets(userMsg, MAX_INPUT - 1, stdin); 
        }
    }

    printf("\033[1;36mDo you want to sort data? Enter the parameter (id/name/surname/group). Enter STOP if you are done.\033[0m\n");
    fgets(userMsg, MAX_INPUT - 1, stdin); 

while (strcmp(userMsg, "STOP\n") != 0) {

        returnCode = findType(userMsg,&type);
        if (returnCode != OK) {
            printf("Wrong data!\n");
            return 0;
        }
        returnCode = sort(students, &sizeAll, type);
        print(outputFile, students, &sizeAll);
        printf("Sorted\n");
        printf("\033[1;36mDo you want to sort data? Enter the parameter (id/name/surname/group). Enter STOP if you are done.\033[0m\n");
        fgets(userMsg, MAX_INPUT - 1, stdin); 

    }

    char answer;
    printf("\033[1;36mDo you want to print students with max average scores? (Y/N) \033[0m\n");
    scanf("%c", &answer);
    if (answer == 'N') {
        printf("See yor result in a file!\n");

    } else if (answer == 'Y') {
        Student * avStuds = (Student *)malloc(sizeAll * sizeof(Student));
        if (!avStuds) {
            printf("Allocation mistake!\n");
            return 0;
        }
        returnCode = average(students,&sizeAll, avStuds, &avMax, &sizeAv); 
        print(outputFile, avStuds, &sizeAv);
        printf("See yor result in a file!\n");
        free(avStuds);
    } else {
        printf("Wrong input\n");
    }

    free(students);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}