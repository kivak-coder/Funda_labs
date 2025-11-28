#ifndef STACK_H
#define STACK_H
#include "linkedList.h"


typedef struct Stack {
    LinkedList * list;
    void(*func)(int n, ...); // указатель на функцию, которую мы сделали
} Stack;

#endif 