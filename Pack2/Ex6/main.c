#include "include/functions.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    if (argc == 1) {
        printf("Too few args\n");
        return 0;
    }

    char Input[FILENAME_MAX];
    Returncode returnCode;

    FILE * inputFile = fopen(Input, "r");
    if (!inputFile) {
        printf("Error while opening an input file\n");
        return 0;
    }

    if (argc == 3) {
        char Output[FILENAME_MAX];
        strcpy(Output, argv[2]);
        FILE * outputFile = fopen(Output, "w");
        if (!outputFile) {
            printf("Error while opening an output file\n");
        }
    }
    Student * students[STUD_SIZ];
    returnCode = read(*students, inputFile);


    return 0;
}