#include <stddef.h>
#include <stdlib.h>


typedef struct Heap {
    int * data;
    size_t size;
    size_t capacity;
} Heap;


Heap createHeap(size_t initialCapacity);
void deleteHeap(Heap *h);
int isEmptyHeap(const Heap *h);
size_t sizeHeap(const Heap *h);
int peekHeap(const Heap *h);
void pushHeap(Heap *h, int value);
int popHeap(Heap *h);
Heap buildHeap(const int *array, size_t n);
int isEqualHeap(const Heap *h1, const Heap *h2);