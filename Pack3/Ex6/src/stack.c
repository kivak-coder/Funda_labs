#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack * createStack() {
    Stack * stack = (Stack * )malloc(sizeof(Stack));
    if (!stack) {
        return NULL;
    }
    stack->data = (char *)malloc(CAPACITY * sizeof(char));
    if (!stack->data) {
        free(stack);
        return NULL;
    }
    stack->size = 0;
    stack->capacity = CAPACITY;
    return stack;
}

bool isEmpty(Stack *stack) {
    if (!stack) {
        return true;
    }
    return stack->size == 0;
}

void deleteStack(Stack * stack) {
    if (!stack) {
        return;
    }
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack->data);
    free(stack);
}

void pop(Stack *stack) {
    if (!stack) {
        return;
    }
    if (!isEmpty(stack)) {
        stack->size--;
    }
    return;
}

char * peek(Stack * stack) {
    if (!stack) {
        return NULL;
    }

    if (!isEmpty(stack)) {
        return &stack->data[stack->size - 1];
    } 
    return  NULL;
}

void push(Stack * stack, char c) {
    if (!stack) {
        return;
    }

    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        char * tmp = (char *)realloc(stack->data, stack->capacity * sizeof(char));
        if (!tmp) {
            return;
        }
        stack->data = tmp;
    }

    stack->data[stack->size] = c;
    stack->size++;
}

