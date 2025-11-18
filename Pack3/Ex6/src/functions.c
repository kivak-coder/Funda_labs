#include "../include/functions.h"
#include <stdio.h>
#include <string.h>

ReturnCode isClosing(const char *bracket) {
    if (!bracket) {
        return NULL_POINTER;
    }

    if (strchr(CLOSING_BRACKETS, *bracket)) {
        return OK;
    } 
    return  NOT_BRACKET;
}

ReturnCode isOpening(const char *bracket) {
    if (!bracket) {
        return NULL_POINTER;
    }

    if (strchr(OPENING_BRACKETS, *bracket)) {
        return OK;
    }
    return NOT_BRACKET;
}

ReturnCode checkBrackets(const char * str){
    if (!str) {
        return NULL_POINTER;
    }

    const char * ptr = str;
    Stack * stack = createStack();

    while (*ptr != '\0') {
        if (isClosing(ptr) == NOT_BRACKET && isOpening(ptr) == NOT_BRACKET) {
            ++ptr;
        } else {
            if (isOpening(ptr) == OK) {
                push(stack, *ptr);
                ++ptr;
            } else if (isClosing(ptr) == OK) {
                if (isEmpty(stack)) {
                    deleteStack(stack);
                    return NOT_BALANCED;
                } 

                char * bracket = peek(stack);
                int i1 = strchr(CLOSING_BRACKETS, *ptr) - CLOSING_BRACKETS;
                int i2 = strchr(OPENING_BRACKETS, *bracket) - OPENING_BRACKETS;
                if (i1 == i2) { 
                    pop(stack);
                    ++ptr;
                } else {
                    deleteStack(stack);
                    return NOT_BALANCED;
                }
            }
        }
    }
    if (!isEmpty(stack)) {
        deleteStack(stack);
        return NOT_BALANCED;
    }
    return OK;
}