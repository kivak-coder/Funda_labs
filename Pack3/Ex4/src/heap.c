#include "../include/heap.h"
#include <stddef.h>
#include <stdlib.h>

Heap createHeap(size_t initialCapacity) {
    Heap * heap = (Heap *)malloc(sizeof(Heap));
    if (!heap) {
        return createHeap(0); // чото придумала зач
    }
    heap->data = (int *)malloc(sizeof(int) * initialCapacity);
    if (!heap->data) {
        free(heap);
        return createHeap(0);
    }
    heap->capacity = initialCapacity;
    heap->size = 0;
}

void deleteHeap(Heap *heap) {
    if (!heap) {
        return;
    }
    free(heap->data);
    free(heap);
}

int isEmptyHeap(const Heap *heap) {
    if (!heap) {
        return NULL;
    }

    return (heap->size > 0) ? 1 : 0; // я надеюсь шо оно работаеть
}

size_t sizeHeap(const Heap *heap) {
    if (!heap) {
        return NULL;
    }
    return heap->size;
}

int peekHeap(const Heap *heap) {
    if (!heap) {
        return NULL;
    }
    return heap->data[heap->size - 1];
}

Heap buildHeap(const int *array, size_t n) {
    
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
    heap->size++; // lдальше надо скучевать
}

int popHeap(Heap *heap) {
    if (!heap) {
        return NULL;
    }

    heap->size--;
    return heap->data[heap->size];
}

int isEqualHeap(const Heap *heap1, const Heap *heap2) {
    if (!heap1 || !heap2) {
        return NULL;
    }

    if (heap1->size != heap2->size) {
        return 1;
    }

    for (size_t i = 0; i < heap1->size; ++i) {
        if (heap1->data[i] != heap2->data[i]) {
            return 1;
        }
    }
    return 0;
}

