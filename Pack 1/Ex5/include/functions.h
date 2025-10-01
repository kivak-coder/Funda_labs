#include <stdio.h>
#include <stdbool.h>


typedef enum ReturnCode{
    WRONG_FLAG,
    WRONG_FILENAME,
    TOO_LONG,
    OK,
}ReturnCode;

ReturnCode funcA(FILE * fi, FILE * out);
ReturnCode funcB(FILE * fi, FILE * out);
ReturnCode funcC(FILE * fi, FILE * out);
ReturnCode funcD(FILE * fi, FILE * out);

ReturnCode flagsValidation(char * arg, char * flag, bool * isFile);
ReturnCode AddOut(char * filename, char * outFile);