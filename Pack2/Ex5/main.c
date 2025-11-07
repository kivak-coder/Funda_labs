#include "include/functions.h"
#include <stdio.h>


int main () {
    char InputFilename[256];
    char outputFilename[256];
    ReturnCode returnCode;

    printf("Enter input file:\n");
    scanf("%s", InputFilename);
    FILE * InputFile = fopen(InputFilename, "r");

    if (!InputFile) {
        printf("An error with opening input file! Enter right name.\n");
        return 0;
    }

    printf("Enter output file:\n");
    scanf("%s", outputFilename);
    FILE * OutputFile = fopen(outputFilename, "w");

    if (!OutputFile) {
        printf("An error with opening output file! Enter right name.\n");
        return 0;
    }
    char string[BUFSIZ] = {0};
    while (fgets(string, BUFSIZ, InputFile) != NULL) {
        rewriteStrings(OutputFile, string);
    }
    
    fclose(InputFile);
    fclose(OutputFile);
    return 0;

}