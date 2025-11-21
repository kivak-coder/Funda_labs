#include <stddef.h>
#include <stdlib.h>

#ifndef VECTOR
#define VECTOR

#define VECTOR_DEF(VECTOR_TYPE)                                                \
                                                                               \
  typedef struct Vector {                                                      \
    VECTOR_TYPE *data;                                                         \
    size_t size;                                                               \
    size_t capacity;                                                           \
    VECTOR_TYPE (*CopyVoidPtr)(VECTOR_TYPE);                                   \
    void (*DeleteVoidPtr)(VECTOR_TYPE);                                        \
  } Vector;                                                                    \
                                                                               \
  Vector *createVector(size_t capacity, VECTOR_TYPE (*CopyFunc)(VECTOR_TYPE),  \
                       void (*DeleteFunc)(VECTOR_TYPE)) {                      \
    Vector *vector = (Vector *)malloc(sizeof(Vector));                         \
    if (!vector) {                                                             \
      return NULL;                                                             \
    }                                                                          \
    vector->data = (VECTOR_TYPE *)malloc(capacity * sizeof(VECTOR_TYPE));      \
    if (!vector->data) {                                                       \
      free(vector);                                                            \
      return NULL;                                                             \
    }                                                                          \
    vector->size = 0;                                                          \
    vector->capacity = capacity;                                               \
    vector->CopyVoidPtr = CopyFunc;                                            \
    vector->DeleteVoidPtr = DeleteFunc;                                        \
    return vector;                                                             \
  }                                                                            \
                                                                               \
  void eraseVector(Vector *vector) {                                           \
    if (!vector) {                                                             \
      return;                                                                  \
    }                                                                          \
    free(vector->data);                                                        \
    vector->size = 0;                                                          \
    vector->capacity = 0;                                                      \
  }                                                                            \
                                                                               \
  int isEqual(const Vector *vector1, const Vector *vector2) {                  \
    if (!vector1 || !vector2 || vector1->size != vector2->size) {              \
      return 0;                                                                \
    }                                                                          \
                                                                               \
    for (size_t i = 0; i < vector1->size; ++i) {                               \
      if (vector1->data[i] != vector2->data[i]) {                              \
        return 0;                                                              \
      }                                                                        \
    }                                                                          \
    return 1;                                                                  \
  }                                                                            \
                                                                               \
  void pushBackVector(Vector *vector, VECTOR_TYPE value) {                     \
    if (!vector) {                                                             \
      return;                                                                  \
    }                                                                          \
                                                                               \
    if (vector->size >= vector->capacity) {                                    \
      VECTOR_TYPE *tmp = (VECTOR_TYPE *)realloc(                               \
          vector->data, vector->capacity * 2 * sizeof(VECTOR_TYPE));           \
      if (!tmp) {                                                              \
        return;                                                                \
      }                                                                        \
      vector->capacity *= 2;                                                   \
      vector->data = tmp;                                                      \
    }                                                                          \
                                                                               \
    vector->data[vector->size] = value;                                        \
    vector->size++;                                                            \
  }                                                                            \
                                                                               \
  VECTOR_TYPE getAtVector(const Vector *vector, size_t index) {                \
    if (!vector || vector->size == 0) {                                        \
      return (VECTOR_TYPE)0;                                                   \
    }                                                                          \
    if (index >= vector->size) {                                               \
      return vector->data[vector->size - 1];                                   \
    }                                                                          \
    return vector->data[index];                                                \
  }                                                                            \
                                                                               \
  void deleteVector(Vector *vector) {                                          \
    if (!vector) {                                                             \
      return;                                                                  \
    }                                                                          \
    free(vector->data);                                                        \
    free(vector);                                                              \
  }                                                                            \
                                                                               \
  void copyVector(Vector *dest, const Vector *src) {                           \
    if (!dest || !src) {                                                       \
      return;                                                                  \
    }                                                                          \
    eraseVector(dest);                                                         \
    dest->data = (VECTOR_TYPE *)malloc(src->capacity * sizeof(VECTOR_TYPE));  \
    dest->size = src->size;                                                    \
    dest->capacity = src->capacity;                                            \
    for (size_t i = 0; i < src->size; ++i) {                                   \
      dest->data[i] = dest->CopyVoidPtr(src->data[i]);                         \
    }                                                                          \
  }                                                                            \
                                                                               \
  Vector *copyVectorNew(const Vector *src) {                                   \
    if (!src) {                                                                \
      return NULL;                                                             \
    }                                                                          \
    Vector *vector =                                                           \
        createVector(src->capacity, src->CopyVoidPtr, src->DeleteVoidPtr);     \
    for (size_t i = 0; i < src->size; ++i) {                                   \
      vector->data[i] = vector->CopyVoidPtr(src->data[i]);                     \
    }                                                                          \
    return vector;                                                             \
  }                                                                            \
                                                                               \
  void DeleteAtVector(Vector *vector, size_t index) {                          \
    if (!vector) {                                                             \
      return;                                                                  \
    }                                                                          \
    if (index >= vector->size) {                                               \
      index = vector->size - 1;                                                \
    }                                                                          \
    vector->DeleteVoidPtr(vector->data[index]);                                \
    for (size_t i = 0; i < vector->size - 1 - index; ++i) {                    \
      vector->data[index + i] = vector->data[index + i + 1];                   \
    }                                                                          \
    vector->size--;                                                            \
  }

#endif // VECTOR