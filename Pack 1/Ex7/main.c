#include <stdio.h>
#include <string.h>
#include "include/functions.h"

int main(int argc, char ** argv) {
    if (argc != 3){
        printf("Wrong number of arguments!\n");
        return 0;
    }

    if (strlen(argv[1]) > 255 || strlen(argv[2]) > 255) {
        printf("Too long name for a file!\n");
        return 0;
    }
    
    FILE * InFi = fopen(argv[1], "r");
    FILE * OutFi = fopen(argv[2], "w");

    if (InFi == NULL || OutFi == NULL) {
        printf("Error while opening files!\n");
        return 0;
    }

    printf("HERE!\n");
    char str[BUFSIZ];

    while (fgets(str, BUFSIZ, InFi) != NULL){
        parseString(str, OutFi);
    }

    fclose(InFi);
    fclose(OutFi);
    return 0;
}