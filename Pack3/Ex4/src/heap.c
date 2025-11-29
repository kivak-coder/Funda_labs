#include "../include/heap.h"
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Heap createHeap(size_t initialCapacity) {
    Heap heap;
    heap.data = NULL;
    heap.capacity = 0;
    heap.size = 0;
    
    if (initialCapacity > 0) {
        heap.data = (int *)malloc(sizeof(int) * initialCapacity);
        if (heap.data) {
            heap.capacity = initialCapacity;
        }
    }
    return heap;
}

void deleteHeap(Heap *heap) {
    if (!heap) {
        return;
    }
    free(heap->data);
    heap->data = NULL;
}

int isEmptyHeap(const Heap *heap) {
    if (!heap) {
        return -1;
    }

    return (heap->size > 0) ? 0 : 1; 
}

size_t sizeHeap(const Heap *heap) {
    if (!heap) {
        return 0;
    }
    return heap->size;
}

int peekHeap(const Heap *heap) {
    if (!heap) {
        return -1;
    }
    if (!isEmptyHeap(heap)) {
        return heap->data[0];
    } else {
        return -1;
    }
}

Heap buildHeap(const int *array, size_t n) {    

    Heap heap = createHeap(n);
    for (size_t i = 0; i < n; ++i) {
        heap.data[i] = array[i];
    }

    heap.size = n;

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapifyDown(&heap, i);
    }
    return heap;
}
void pushHeap(Heap *heap, int value) {
    if (!heap) {
        return;
    }
    
    if (heap->size >= heap->capacity) {
        int * tmp = (int *)realloc(heap->data, sizeof(int) * heap->capacity * 2);
        if (!tmp) {
            return;
        }
        heap->data = tmp;
        heap->capacity *= 2;
    }

    heap->data[heap->size] = value;
    heap->size++; 
    heapifyUp(heap, heap->size - 1);
}

int popHeap(Heap *heap) {
    if (!heap) {
        return -1;
    }
    if (!isEmptyHeap(heap)) {
        int value = heap->data[0];
        heap->size--;
        heap->data[0] = heap->data[heap->size];
        heapifyDown(heap, 0);
        return value; 
    } else {
        return -1;
    }
    
}

int isEqualHeap(const Heap *heap1, const Heap *heap2) {
    if (!heap1 || !heap2) {
        return -1;
    }

    if (heap1->size != heap2->size) {
        return 0;
    }

    for (size_t i = 0; i < heap1->size; ++i) {
        if (heap1->data[i] != heap2->data[i]) {
            return 0;
        }
    }
    return 1;
}


void heapifyDown(Heap *heap, size_t index) {
    if (!heap) {
        return;
    }

    if (index > heap->size) {
        return;
    }

    int left = 0; int right = 0; int parent = 0; int tmp = 0;

    while (index <= heap->size / 2 - 1) {
        parent = index;
        left = 2 * index + 1;
        right = 2 * index + 2;

        if (heap->data[left] < heap->data[parent] && heap->data[left] < heap->data[right]) {
            tmp = heap->data[parent];
            heap->data[parent] = heap->data[left];
            heap->data[left] = tmp;
            index = left;

        } else if (heap->data[right] < heap->data[parent] && heap->data[right] < heap->data[left]) {
            tmp = heap->data[parent];
            heap->data[parent] = heap->data[right];
            heap->data[right] = tmp;
            index = right;

        } else {
            break;
        }
    } 
}

void heapifyUp(Heap * heap, size_t index) {
    if (!heap) {
        return;
    }

    if (index >= heap->size) {
        return;
    }

    int parent = 0; int child = 0; int tmp = 0;
    while (index > 0) {
        child = index;
        parent = (index - 1) / 2;

        if (heap->data[parent] > heap->data[child]) {
            tmp = heap->data[parent];
            heap->data[parent] = heap->data[child];
            heap->data[child] = tmp;
            index = parent;

        } else {
            break;
        }
    }
}

void printHeap(Heap * heap) {
    if (!heap) {
        return;
    }

    int arrows = 1;
    size_t elemsPrinted = 0;

    while (elemsPrinted < heap->size) {
        for (int i = 0; i < arrows; ++i) {
            printf("->");
        }
        printf(" %i", heap->data[elemsPrinted]);
        if (elemsPrinted == pow(2, (arrows)) - 2) {
            arrows++;
        }
        elemsPrinted++;
        printf("\n");


    }
}

