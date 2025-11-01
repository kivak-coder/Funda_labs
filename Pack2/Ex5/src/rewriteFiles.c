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
        for (int i = 0; i < *spaces - 1; i++) {
            int out = fputs(wordsToWrite[i], outputFile); 
            if (out < 0) {return NULL_POINTER;}
        }
        fputc('\n', outputFile);
        return OK;
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
    int i = 0;
    bool More = false;


    WithoutLeadingSpaces(str, strRes); // добавить вывод о том шо пробелов нет и тогда сократится код выше
    WithoutFinishingSpaces(strRes, strRes2);

    if (strchr(strRes2, ' ') == NULL) { // слово сплошное
        char * ptr = strRes2;
        while (*ptr) {
            for (int i = 0; i < MAX_SIZE; ++i) {
                fputc(*ptr, Output);
                ++ptr;
            }
            fputc('\n',Output);
        }
        return OK;
    }

    if (strlen(strRes) <= MAX_SIZE) {
        fprintf(Output,"%s\n", strRes);
        return OK; // добавить проверку на успешность записи!!!

    } else {

        returnCode = SeparateToWords(strRes, words, &size);
        print(words, &size);

        for (int i = 0; i < size; ++i) { 

            if (LengthAll + strlen(words[i]) >= 80) { 

                More = true;
                WithoutFinishingSpaces(words[i - 1], wordsTowrite[spaces - 1]);

                printf("bilo: %lu, str: %s, stalo: %lu, str: %s,\n", strlen(words[i - 1]), words[i - 1], strlen(wordsTowrite[spaces - 1]), wordsTowrite[spaces - 1]);

                int delta = strlen(words[i - 1]) - strlen(wordsTowrite[spaces - 1]);
                least = MAX_SIZE - LengthAll;
                least += delta;

                printf("%i \n", least);
                n = least / (spaces - 1);
                least = least % (spaces - 1); 

                if (n * (spaces - 1) + LengthAll + least == 80) {
                    printf("YA HUI\n");
                }

                printf("least: %d, Lengthall: %i, n: %i\n", least, LengthAll, n);
                writeInFile(Output, wordsTowrite, &spaces, &n, &least, &More);
    
                for (int j = 0; j < spaces; j++) {
                    free(wordsTowrite[j]);
                }
                i--;
                spaces = 0;
                LengthAll = 0;
                More = false;


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
        if (LengthAll > 80) {
            More = true;
            WithoutFinishingSpaces(words[i - 1], wordsTowrite[spaces - 1]); 
            int delta = strlen(words[i - 1]) - strlen(wordsTowrite[spaces - 1]);
            least = MAX_SIZE - LengthAll;
            least += delta;

            printf("%i \n", least);
            n = least / (spaces - 1);
            least = least % (spaces - 1); 

            if (n * (spaces - 1) + LengthAll + least == 80) {
                printf("YA HUI\n");
            }

            writeInFile(Output, wordsTowrite, &spaces, &n, &least, &More);

        } else {
            writeInFile(Output, wordsTowrite, &spaces, &n, &least, &More);
           
        }
        
    } 

    for (int j = 0; j < spaces; j++) {
        free(wordsTowrite[j]);
    }
    
    return OK;
}
