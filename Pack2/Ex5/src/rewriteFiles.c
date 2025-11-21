#include "../include/functions.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ReturnCode writeInFile(FILE * outputFile, char ** wordsToWrite, int * spaces, int * n, int * least, bool * More) {
    if (!outputFile || !wordsToWrite) {
        return NULL_POINTER;
    }

    if (!(*More)) {
        for (int i = 0; i < *spaces; i++) {
            if (fputs(wordsToWrite[i], outputFile) < 0) {return WRITE_ERROR;} 
        }
        
        if (fputc('\n', outputFile) == EOF) {
            return WRITE_ERROR;
        }
        return OK;
    } 

    for (int i = 0; i < *spaces - 1; i++) {
        if (fputs(wordsToWrite[i], outputFile) < 0) {return WRITE_ERROR;}

        for (int j = 0; j < *n; ++j) {
            if (fputc(' ', outputFile) == EOF) {
                return WRITE_ERROR;
            }
        }

        if (*least > 0) {
            if (fputc(' ', outputFile) == EOF) {
                return WRITE_ERROR;
            }
            --(*least);
        }
    }

    if (fputs(wordsToWrite[*spaces - 1], outputFile) < 0) {return WRITE_ERROR;}
    if (fputc('\n', outputFile) == EOF) {return WRITE_ERROR;}
    return OK;
}

ReturnCode rewriteStrings(FILE * Output, char * str) {
    char strRes[BUFSIZ] = {0};
    char strRes2[BUFSIZ] = {0};

    char * words[MAX_SIZE] = {0}; 
    char * wordsTowrite[MAX_SIZE] = {0};

    int size = 0; int LengthAll = 0; 
    int spaces = 0; int n = 0; int least = 0; 
    int i = 0;
    ReturnCode returnCode;
    bool More = false;

    returnCode = WithoutLeadingSpaces(str, strRes);
    if (returnCode != OK) {return returnCode;}

    returnCode = WithoutFinishingSpaces(strRes, strRes2);
    if (returnCode != OK) {return returnCode;}

    if (strlen(strRes2) == 0) {
        fputc('\n',Output);
        return OK;
    }

    if (strlen(strRes2) <= MAX_SIZE) {

        if (fprintf(Output,"%s\n", strRes2) < 0) {
            return WRITE_ERROR;
        }
        return OK; 

    } else {

        if (strchr(strRes2, ' ') == NULL) { // слово сплошное
            char * ptr = strRes2;
            int i = 0;

            while (*ptr) {
                if (i < MAX_SIZE) {
                    if (fputc(*ptr, Output) == EOF) {
                        return WRITE_ERROR;
                    }
                    ++ptr;
                    ++i;

                } else {
                    if (fputc('\n',Output) == EOF) {
                        return WRITE_ERROR;
                    }
                    i = 0;
                }
            }
            if (fputc('\n',Output) == EOF) {return WRITE_ERROR;};
            return OK;
        }

        returnCode = SeparateToWords(strRes2, words, &size);
        if (returnCode != OK) {return returnCode;}

        for (int i = 0; i < size; ++i) { 

            if (LengthAll + strlen(words[i]) >= 80) { 
                More = true;

                returnCode = WithoutFinishingSpaces(words[i - 1], wordsTowrite[spaces - 1]);
                if (returnCode != OK) {return returnCode;}

                int delta = strlen(words[i - 1]) - strlen(wordsTowrite[spaces - 1]);
                least = MAX_SIZE - LengthAll;
                least += delta;

                n = least / (spaces - 1);
                least = least % (spaces - 1); 

                returnCode = writeInFile(Output, wordsTowrite, &spaces, &n, &least, &More);
                if (returnCode != OK) {return returnCode;}
    
                for (int j = 0; j < spaces; j++) {
                    free(wordsTowrite[j]);
                }

                i--;
                spaces = 0;
                LengthAll = 0;
                More = false;

            } else {
                wordsTowrite[spaces] = (char *)malloc(strlen(words[i]) + 1);
                if (!wordsTowrite[spaces]) {return NULL_POINTER;}
                strcpy(wordsTowrite[spaces], words[i]);
                spaces++;
                LengthAll += strlen(words[i]);
            }
        }
    }
    
    if (spaces > 0) {
        if (LengthAll > 80) {
            More = true;

            returnCode = WithoutFinishingSpaces(words[i - 1], wordsTowrite[spaces - 1]); 
            if (returnCode != OK) {return returnCode;}

            int delta = strlen(words[i - 1]) - strlen(wordsTowrite[spaces - 1]);
            least = MAX_SIZE - LengthAll;
            least += delta;
            n = least / (spaces - 1);
            least = least % (spaces - 1); 

            returnCode = writeInFile(Output, wordsTowrite, &spaces, &n, &least, &More);
            if (returnCode != OK) {return returnCode;}

        } else {
            returnCode = writeInFile(Output, wordsTowrite, &spaces, &n, &least, &More);
            if (returnCode != OK) {return returnCode;}
        } 
    } 

    for (int j = 0; j < size; j++) {
        free(words[j]); 
    }
        
    return OK;
}
