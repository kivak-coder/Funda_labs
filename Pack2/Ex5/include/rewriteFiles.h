#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef enum ReturnCode {
    UNKNOWN_SYMBOL,
    NULL_POINTER,
    OK,
} ReturnCode;

#define MAX_SIZE 80


ReturnCode WithoutLeadingSpaces(char * str, char * strRes);
ReturnCode WithoutFinishingSpaces(char * str);
ReturnCode SeparateToWords(char * str, char ** words, int * size, int * len);
ReturnCode writeInFile(FILE * outputFile, char ** words, int * spaces, int * n, int * least);
ReturnCode rewriteStrings(FILE * Output, char * str);


