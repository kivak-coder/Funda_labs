#include "include/vector.h"
#include <stdio.h>
#include <string.h>

VECTOR_DEF(int)

int CopyFunc(int num){
    return num;
}

void DeleteFunc(int num) {
    num = 0; 
    return;
}

void printVector(Vector *vec, const char *name) {
    printf("Вектор %s: ", name);
    if (vec == NULL) {
        printf("NULL\n");
        return;
    }
    printf("[размер: %zu, емкость: %zu] ", vec->size, vec->capacity);
    for (size_t i = 0; i < vec->size; i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
}

int main() {
    Vector *vector1 = createVector(10, CopyFunc, DeleteFunc);
    Vector *vector2 = createVector(5, CopyFunc, DeleteFunc);
    Vector *vector3 = NULL;

    pushBackVector(vector1, 1234);
    pushBackVector(vector1, -129492);
    pushBackVector(vector1, 5509);

    pushBackVector(vector2, 3231);
    pushBackVector(vector2, 747302);

    printf("=== Исходные векторы ===\n");
    printVector(vector1, "vector1");
    printVector(vector2, "vector2");

    printf("\n=== Тестирование сравнения ===\n");
    
    int result1 = isEqual(vector1, vector2);
    printf("vector1 == vector2: %s\n", result1 ? "true" : "false");

    vector3 = copyVectorNew(vector1);
    printf("Создана копия vector1 -> vector3\n");
    printVector(vector3, "vector3");

    int result2 = isEqual(vector1, vector3);
    printf("vector1 == vector3: %s\n", result2 ? "true" : "false");

    printf("\nИзменяем vector3...\n");
    pushBackVector(vector3, 90678);
    printVector(vector1, "vector1");
    printVector(vector3, "vector3");
    
    int result3 = isEqual(vector1, vector3);
    printf("vector1 == vector3 после изменения: %s\n", result3 ? "true" : "false");

    printf("\n=== Тестирование копирования в существующий вектор ===\n");
    printf("До копирования:\n");
    printVector(vector2, "vector2");
    
    copyVector(vector2, vector1);
    printf("После copyVector(vector2, vector1):\n");
    printVector(vector1, "vector1");
    printVector(vector2, "vector2");
    
    int result4 = isEqual(vector1, vector2);
    printf("vector1 == vector2 после копирования: %s\n", result4 ? "true" : "false");

    printf("\n=== Тестирование создания новой копии ===\n");
    Vector *vector4 = copyVectorNew(vector1);
    printf("Создана новая копия vector1 -> vector4\n");
    printVector(vector4, "vector4");
    
    int result5 = isEqual(vector1, vector4);
    printf("vector1 == vector4: %s\n", result5 ? "true" : "false");

    printf("\n=== Тестирование с пустыми векторами ===\n");
    Vector *emptyVector1 = createVector(5, CopyFunc, DeleteFunc);
    Vector *emptyVector2 = createVector(3, CopyFunc, DeleteFunc);
    
    int result6 = isEqual(emptyVector1, emptyVector2);
    printf("emptyVector1 == emptyVector2: %s\n", result6 ? "true" : "false");
    
    copyVector(emptyVector2, vector1);
    printf("После copyVector(emptyVector2, vector1):\n");
    printVector(emptyVector2, "emptyVector2");

    
    printf("\n=== Освобождение памяти ===\n");
    deleteVector(vector1);
    deleteVector(vector2);
    deleteVector(vector3);
    deleteVector(vector4);
    deleteVector(emptyVector1);
    deleteVector(emptyVector2);
    
    printf("Все векторы удалены\n");

    return 0;
}