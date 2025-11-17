#ifndef VECTOR

#define VECTOR_DEF(VECTOR_TYPE)   \
                                  \
typedef struct Vector {           \
    VECTOR_TYPE * data;   \
    size_t size; \
    size_t capacity; \
    VECTOR_TYPE (*CopyVoidPtr) (VECTOR_TYPE); \
    void (*DeleteVoidPtr)(VECTOR_TYPE); \
} Vector;      \
\
Vector * createVector(size_t capacity, VECTOR_TYPE (*CopyFunc)(VECTOR_TYPE), void (*DeleteFunc)(VECTOR_TYPE)) { \
    Vector * vector = Vector * (malloc(sizeof(Vector))); \
    if (!vector) { \
        return NULL; \
    } \
    vector->data =  (VECTOR_TYPE*)malloc(capacity * sizeof(VECTOR_TYPE)); \
    if (!vector->data) { \
        return NULL; \
    } \
    vector->size = 0; \
    vector->capacity = capacity; \
} \
\
\
void eraseVector(Vector * vector) { \
    if (!vector) { \
        return;  \
    } \
    free(vector->data); \
    vector->size = 0; \
} \
\
\
int isEqual(const Vector * vector1, const Vector * vector2) { \
    if (!vector1 || !vector2) { \
        return NULL; \
    } \
    \
    if (vector1->size > vector2->size) { \
        return 1; \
    }\
} \
\
void copyVector(Vector * dest, const Vector * src); \
Vector * copyVectorNew(const Vector * src); \
void pushBackVector(Vector * vector, VECTOR_TYPE value); \
void DeleteAtVector(Vector * vector, size_t index); \
\
VECTOR_TYPE getAtVector(const Vector * vector, size_t index) { \
    if (!vector) { \
        return NULL; \
    } \
    if (index >= vector->size) { \
        return vector->data[vector->size]; \
    } \
    return vector->data[index]; \
} \
\
void deleteVector(Vector * vector) { \
    if (!vector) { \
        return; \
    } \
    free(vector->data); \
    free(vector);\
} \

#endif 