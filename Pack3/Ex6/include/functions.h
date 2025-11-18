#include "stack.h"

#define CLOSING_BRACKETS ")]}>"
#define OPENING_BRACKETS "([{<"

typedef enum ReturnCode {
    NULL_POINTER, 
    NOT_BRACKET,
    NOT_BALANCED,
    OK
} ReturnCode;

ReturnCode isClosing(const char * bracket);
ReturnCode isOpening(const char * bracket);
ReturnCode checkBrackets(const char *str);