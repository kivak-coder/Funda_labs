#include "../include/linkedList.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


LinkedList * createList() {
    LinkedList * list = (LinkedList *)malloc(sizeof(LinkedList)); 
    if (!list) {
        return NULL;
    }
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void pushBackList(LinkedList *list, Liver *liver) {
    if (!list || !liver) {
        return;
    }
    Node * node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return;
    }

    node->liver = liver;
    node->next = NULL;
    node->prev = list->tail;

    ++list->size;
    list->tail = node;
}

void pushFrontList(LinkedList *list, Liver *liver) {
    if (!liver || !list) {
        return;
    }

    Node * node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return;
    }

    node->liver = liver;
    node->prev = list->tail->next = NULL; // мб убрать анал?
    node->next = list->head;

    list->head = node;
    ++list->size;
}

Liver * popBackList(LinkedList * list) {
    if (!list) {
        return NULL;
    }
    Liver * liver = list->tail->liver;

    list->tail = list->tail->prev;
    list->tail->next = list->head->prev; // чот явно не хватает

    return liver;
}

Liver * popFrontList(LinkedList * list) {
    if (!list) {
        return NULL;
    }
    Liver * liver = list->head->liver;  

    list->head = list->head->next;
    list->head->liver = list->head->next->liver;
    list->head->prev = list->tail->next;
    return liver;
}

Liver * getAtList(LinkedList * list, size_t index) {
    if (!list) {
        return NULL;
    }
    if (index > list->size) {
        index = list->size;
    }
    Node * node = list->head;

    for (size_t i = 0; i < index; ++i) {
        node = node->next;
    }
    return node->liver;
}

void DeleteAtList(LinkedList *list, size_t index) {
    if (!list) {
        return;
    }
    if (index > list->size) {
        index = list->size;
    }
    Node * node = list->head;

    for (size_t i = 0; i < index; ++i) {
        node = node->next; // то что надо получили?
    }
    deleteLiver(node->liver);
    node->prev = node->next;

}

void InsertAtList(LinkedList *list, size_t index, Liver *liver) {
    if  (!list) {
        return;
    }
    if (index > list->size) {
        index = list->size;
    }

    Node * node = list->head;
    for (size_t i = 0; i < index; ++i) {
        node = node->next; // то что надо получили?
    }

    Node * newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        return;
    }

    newNode->liver = liver;
    newNode->next = node;
    newNode->prev = node->prev;
    node->prev = newNode;
}

void eraseList(LinkedList *list) {
    if (!list) {
        return;
    }
    list->size = 0;
    Node * node = list->head;
    while (node != list->tail->next) {
        deleteLiver(node->liver);
        node = node->next;
    }
}

void deleteList(LinkedList *list) {
    if (!list) {
        return;
    }
    Node * node = list->head;
    while (node != list->tail->next) {
        deleteLiver(node->liver);
        node = node->next;
    }
    free(list);
}

int isEqualList(LinkedList *list1, LinkedList *list2) {
    if (!list1 || !list2) {
        return NULL;
    }

}