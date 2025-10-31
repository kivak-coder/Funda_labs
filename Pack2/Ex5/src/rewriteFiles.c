#include "../include/functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ReturnCode writeInFile(FILE * outputFile, char ** wordsToWrite, int * spaces, int * n, int * least) {
    if (!outputFile || !wordsToWrite) {
        return NULL_POINTER;
    }
    for (int i = 0; i < *spaces - 1; i++) {
        int out = fputs(wordsToWrite[i], outputFile); 
        printf("%s,", wordsToWrite[i]);

        if (out < 0) {return NULL_POINTER;}

        for (int j = 0; j < *n; ++j) {
            fputc(' ', outputFile);
        }

        if (*least > 0) {
            fputc(' ', outputFile);
            --(*least);
        }
    }
    fputs(wordsToWrite[*spaces - 1], outputFile);
    fputc('\n', outputFile);
    return OK;
}

ReturnCode rewriteStrings(FILE * Output, char * str) {
    char strRes[BUFSIZ];
    char * words[MAX_SIZE] = {0}; // массив указателей на строки
    char strRes2[BUFSIZ];
    int size = 0; // количество слов в массиве
    int LengthAll = 0; // общая длина строки (с пробелами)
    int spaces = 0; // количество промежутков между словами 
    int n = 0; // количество пробелов в промежутке
    int least = 0; // пробелы, которые невозможно распеределить в каждый промежуток
    ReturnCode returnCode;
    char * wordsTowrite[MAX_SIZE] = {0};

    // if (strchr(str, ' ') == NULL) { // сплошное слово
    //     char * ptr = str;
    //     while (*ptr) {
    //         for (int i = 0; i < MAX_SIZE; ++i) {
    //             fputc(*ptr, Output);
    //             ++ptr;
    //         }
    //         fputc('\n',Output);
    //     }
    //     return OK;
    // }

    WithoutLeadingSpaces(str, strRes); // добавить вывод о том шо пробелов нет и тогда сократится код выше
    WithoutFinishingSpaces(strRes, strRes2);

    if (strchr(strRes2, ' ') == NULL) { // слово сплошное
        char * ptr = str;
        while (*ptr) {
            for (int i = 0; i < MAX_SIZE; ++i) {
                fputc(*ptr, Output);
                ++ptr;
            }
            fputc('\n',Output);
        }
        return OK;
    }

    if (strlen(strRes2) <= MAX_SIZE) {
        fprintf(Output,"%s\n", strRes2);
        return OK; // добавить проверку на успешность записи!!!

    } else {

        returnCode = SeparateToWords(strRes2, words, &size);

        for (int i = 0; i < size; ++i) { 

            if (LengthAll + strlen(words[i]) >= 80) { 

                WithoutFinishingSpaces(words[i - 1], wordsTowrite[spaces - 1]); // а туда писать то можно
                strcpy(wordsTowrite[spaces - 1], strRes2);
                printf("bilo: %lu, str: %s, stalo: %lu, str: %s,\n", strlen(words[i - 1]), words[i - 1], strlen(wordsTowrite[spaces - 1]), wordsTowrite[i - 1]);

                int delta = strlen(words[i - 1]) - strlen(wordsTowrite[spaces - 1]);

                printf("%i \n", delta); 
                printf("Length: %i\n", LengthAll);
                LengthAll -= delta;

                while (MAX_SIZE - LengthAll > spaces) { 
                    ++n;
                    LengthAll += spaces;
                }

                least = MAX_SIZE - LengthAll; 
                writeInFile(Output, wordsTowrite, &spaces, &n, &least);
                least = 0; n = 1; spaces = 0; LengthAll = 0;
                i--;

            } else {
                LengthAll += strlen(words[i]);
                wordsTowrite[spaces] = (char *)malloc(strlen(words[i]) + 1);
                if (!wordsTowrite[spaces]) {return NULL_POINTER;}
                strcpy(wordsTowrite[spaces], words[i]);
                spaces++;
            }
        }
    }
    
    if (spaces > 0) {
        least = MAX_SIZE - LengthAll;
        writeInFile(Output, wordsTowrite, &spaces, &n, &least);
    }

    for (int i = 0; i < spaces; i++) {
        free(wordsTowrite[i]);
    }
    return OK;
}
