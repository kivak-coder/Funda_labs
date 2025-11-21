#include "../include/functions.h"
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
    if (!stack) {
        return NULL_POINTER;
    }

    while (*ptr != '\0') {

        ReturnCode returnCodeOpening = isOpening(ptr);
        ReturnCode returnCodeClosing = isClosing(ptr);

        if (returnCodeOpening == NULL_POINTER || returnCodeClosing == NULL_POINTER) {
            return NULL_POINTER;
        }

        if (returnCodeOpening == NOT_BRACKET && returnCodeClosing == NOT_BRACKET) {
            ++ptr;

        } else {
            if (returnCodeOpening == OK) {
                push(stack, *ptr);
                ++ptr;

            } else if (returnCodeClosing == OK) {
                
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
    deleteStack(stack);
    return OK;
}