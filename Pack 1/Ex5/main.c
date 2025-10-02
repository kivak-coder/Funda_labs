#include <linux/limits.h>
#include <stdio.h>
#include <string.h>
#include "include/functions.h"


int main(int argc, char * argv[]){
    if (argc != 4 && argc != 3){
        printf("Wrong number of args!\n");
        return 0;
    }

    char flag;
    bool isFile = false;
    ReturnCode return_code;
    char inputFile[BUFSIZ];
    char outputFile[BUFSIZ];


    return_code = flagsValidation(argv[1], &flag, &isFile);

    if (return_code == WRONG_FLAG){
        printf("Wrong flag!\n");
        return 0;
    }

    if (strlen(argv[2]) < BUFSIZ){
        strcpy(inputFile, argv[2]);
    } else {
        printf("Too big input filename!\n");
        return 0;
    }

    if (isFile && argc == 3){
        printf("Miss output filename!\n");
        return 0;
    }

    if (isFile){
        if (strlen(argv[3]) < BUFSIZ) {
            strcpy(outputFile, argv[3]);
        } else {
            printf("Too big output filename!\n");
            return 0;
        }

    } else {
        strcpy(inputFile, argv[2]);
        return_code = AddOut(inputFile, outputFile);
    }

    if (return_code == TOO_LONG){
        printf("Cannot add 'out_' to filename!\n");
        return 0;
    }

    FILE * InFi = fopen(inputFile, "r");
    FILE * OutFi = fopen(outputFile, "w");

    if (InFi == NULL){
        printf("Error while opening first file!\n");
        return 1;
    }

    if (OutFi == NULL){
        printf("Error while opening second file!\n");
        fclose(InFi);
        return 1;
    }

    switch (flag){
        case 'd':
            return_code = funcA(InFi, OutFi);
            break;

        case 'i':
            return_code = funcB(InFi, OutFi);
            break;

        case 's':
            return_code = funcC(InFi, OutFi);
            break;

        case 'a':
            return_code = funcD(InFi, OutFi);
            break;
    }
    
    fclose(InFi);
    fclose(OutFi);
    return 0;
}