#include <stdio.h>

typedef enum ReturnCode {
    UNKNOWN_SYMBOL,
    OK,
}ReturnCode;

#define MAX_SIZE 80
// #define puctuationMarks ",.-:;!?"

ReturnCode rewriteStrings(FILE * Output, char ** string);