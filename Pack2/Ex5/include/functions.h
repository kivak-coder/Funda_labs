#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef enum ReturnCode {
    UNKNOWN_SYMBOL,
    NULL_POINTER,
    FILE_ERROR,
    OK,
} ReturnCode;

#define MAX_SIZE 80


ReturnCode WithoutLeadingSpaces(char * str, char * strRes);
ReturnCode WithoutFinishingSpaces(char * str, char * strRes);
ReturnCode SeparateToWords(char * str, char ** words, int * size);
ReturnCode writeInFile(FILE * outputFile, char ** words, int * spaces, int * n, int * least, bool * More);
ReturnCode rewriteStrings(FILE * Output, char * str);
bool isReadable(char c);
void print(char ** words, int * size);



