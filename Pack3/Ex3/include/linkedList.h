#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "liver.h"
#include <stddef.h>

typedef struct Node {
    Liver * liver;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct LinkedList {
    struct Node * head;
    struct Node * tail;
    size_t size;
} LinkedList;

LinkedList * createList();
void eraseList(LinkedList * list); // сохраняем структуру
void deleteList(LinkedList * list); // стираем и очищаем ваще все
void pushBackList(LinkedList * list, Liver * liver);
void pushFrontList(LinkedList * list, Liver * liver);
Liver * popBackList(LinkedList * list);
Liver * popFrontList(LinkedList * list);
void InsertAtList(LinkedList * list, size_t index, Liver * liver);
void DeleteAtList(LinkedList * list, size_t index);
Liver * getAtList(LinkedList * list, size_t index);
int isEqualList(LinkedList * list1, LinkedList * list2);

#endif