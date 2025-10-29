#include "../include/rewriteFiles.h"
#include <stdio.h>
#include <string.h>

ReturnCode WithoutLeadingSpaces(char * str, char * strRes) {
    if (!str || !strRes) {
        return NULL_POINTER;
    }

    char * ptr = str;   // добавить обработку ошибок!!!!
    while (*ptr == ' ' || *ptr == '\t') {
        ++ptr;
    }
    strcpy(strRes, ptr);
    return OK;
}

bool isReadable(char c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return false;
    }
    return true;
}

ReturnCode WithoutFinishingSpaces(char * str) {
    if (!str) {
        return NULL_POINTER;
    }

    char * ptr = strchr(str, '\n');  // может вернуть null!!!
    while (!isReadable(*ptr)) {
        --ptr;
    }
    *ptr = '\0';
    return OK;
}

ReturnCode SeparateToWords(char * str, char ** words, int * size, int * len) {
    if (!str || !words || !size) {
        return NULL_POINTER;
    }
    char * ptrPrev = str;
    char * ptrCur = str + 1;
    char buf[MAX_SIZE]; 
    char * ptrBuf = buf;
    while (*ptrCur) {
        if (isReadable(*ptrCur) && !isReadable(*ptrPrev)) {
            strcpy(words[*size], buf);
            ++*size;
        } else {
            *ptrBuf = *ptrPrev;
            ++ptrBuf;
            ++len;
        }
        ++ptrCur;
        ++ptrPrev;
    }
    return OK;
}

ReturnCode writeInFile(FILE * outputFile, char ** words, int * spaces, int * n, int * least) {\
    if (!outputFile || !words) {
        return NULL_POINTER;
    }
    for (int i = 0; i <= *spaces; i++) {
        fputs(words[i], outputFile);
        for (int j = 0; j < *n; ++j) {
            fputc(' ', outputFile);
        }
        if (*least > 0) {
            fputc(' ',outputFile);
            --(*least);
        }
    }
    return OK;
}

ReturnCode rewriteStrings(FILE * Output, char * str) {
    char strRes[BUFSIZ];
    char * words[MAX_SIZE]; // массив указателей на строки
    int size = 0; // количество слов в массиве
    int LengthAll = 0; // общая длина строки (с пробелами)
    int spaces = 0; // количество промежутков между словами 
    int n = 1; // количество пробелов в промежутке
    int least = 0; // пробелы, которые невозможно распеределить в каждый промежуток
    ReturnCode returnCode;
    char * wordsTowrite[MAX_SIZE];

    fgets(str, BUFSIZ, Output);
    WithoutLeadingSpaces(str, strRes);
    WithoutFinishingSpaces(strRes);

    if (strlen(strRes) <= MAX_SIZE) {
        fprintf(Output,"%s\n", strRes); // добавить проверку на успешность записи!!!
    } else {

        returnCode = SeparateToWords(strRes, words, &size, &LengthAll);

        for (int i = 0; i < size; ++i) { 
            if (LengthAll + strlen(words[i]) + 1 > 80) { // мб равно??
                while (MAX_SIZE - LengthAll - 1 > spaces) { // -1 ибо в послднем слове есть один лищний пробел
                    ++n;
                    LengthAll += spaces;
                }

                least = MAX_SIZE - LengthAll; // мб надо -1??
                writeInFile(Output, wordsTowrite, &spaces, &n, &least);
                least = 0; n = 1; spaces = 0; LengthAll = 0;
            } else {
                LengthAll += strlen(words[i]) + 1;
                spaces++;
                wordsTowrite[spaces] = words[i];
            }
        }
    }
    return OK;
}

     