#include <stdbool.h>

typedef struct Stack {
    char * data;
    int size;
    int capacity;  
} Stack;

#define CAPACITY 20

Stack * createStack();
void deleteStack(Stack * stack);
void pop(Stack * stack);
void push(Stack * stack, char c);
char * peek(Stack * stack);
bool isEmpty(Stack * stack);
void printStack(Stack * stack);

