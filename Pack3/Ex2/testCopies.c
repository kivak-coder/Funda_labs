#include "include/vector.h"
#include <stdio.h>
#include <string.h>

VECTOR_DEF(char *)

char* CopyFunc(char * str){
    return strdup(str);
}

void DeleteFunc(char * str) {
    free(str); 
}

void printVector(Vector *vec, const char *name) {
    printf("Вектор %s: ", name);
    if (vec == NULL) {
        printf("NULL\n");
        return;
    }
    printf("[размер: %zu, емкость: %zu] ", vec->size, vec->capacity);
    for (size_t i = 0; i < vec->size; i++) {
        printf("\"%s\" ", vec->data[i]);
    }
    printf("\n");
}

int main() {
    Vector *vector1 = createVector(10, CopyFunc, DeleteFunc);
    Vector *vector2 = createVector(5, CopyFunc, DeleteFunc);
    Vector *vector3 = NULL;

    // Добавляем элементы в первый вектор
    pushBackVector(vector1, "abob");
    pushBackVector(vector1, "babobc");
    pushBackVector(vector1, "test");

    // Добавляем элементы во второй вектор
    pushBackVector(vector2, "hello");
    pushBackVector(vector2, "world");

    printf("=== Исходные векторы ===\n");
    printVector(vector1, "vector1");
    printVector(vector2, "vector2");

    // Тестирование сравнения векторов
    printf("\n=== Тестирование сравнения ===\n");
    
    // Сравниваем разные векторы
    int result1 = isEqual(vector1, vector2);
    printf("vector1 == vector2: %s\n", result1 ? "true" : "false");

    // Создаем копию vector1 для сравнения
    vector3 = copyVectorNew(vector1);
    printf("Создана копия vector1 -> vector3\n");
    printVector(vector3, "vector3");

    // Сравниваем оригинал и копию
    int result2 = isEqual(vector1, vector3);
    printf("vector1 == vector3: %s\n", result2 ? "true" : "false");

    // Меняем vector3 и снова сравниваем
    printf("\nИзменяем vector3...\n");
    pushBackVector(vector3, "new_element");
    printVector(vector1, "vector1");
    printVector(vector3, "vector3");
    
    int result3 = isEqual(vector1, vector3);
    printf("vector1 == vector3 после изменения: %s\n", result3 ? "true" : "false");

    // Тестирование копирования в существующий вектор
    printf("\n=== Тестирование копирования в существующий вектор ===\n");
    printf("До копирования:\n");
    printVector(vector2, "vector2");
    
    // Копируем содержимое vector1 в vector2
    copyVector(vector2, vector1);
    printf("После copyVector(vector2, vector1):\n");
    printVector(vector1, "vector1");
    printVector(vector2, "vector2");
    
    // Проверяем, что они теперь равны
    int result4 = isEqual(vector1, vector2);
    printf("vector1 == vector2 после копирования: %s\n", result4 ? "true" : "false");

    // Тестирование создания новой копии
    printf("\n=== Тестирование создания новой копии ===\n");
    Vector *vector4 = copyVectorNew(vector1);
    printf("Создана новая копия vector1 -> vector4\n");
    printVector(vector4, "vector4");
    
    // Проверяем равенство
    int result5 = isEqual(vector1, vector4);
    printf("vector1 == vector4: %s\n", result5 ? "true" : "false");

    // Тестирование с пустыми векторами
    printf("\n=== Тестирование с пустыми векторами ===\n");
    Vector *emptyVector1 = createVector(5, CopyFunc, DeleteFunc);
    Vector *emptyVector2 = createVector(3, CopyFunc, DeleteFunc);
    
    int result6 = isEqual(emptyVector1, emptyVector2);
    printf("emptyVector1 == emptyVector2: %s\n", result6 ? "true" : "false");
    
    // Копируем пустой вектор
    copyVector(emptyVector2, vector1);
    printf("После copyVector(emptyVector2, vector1):\n");
    printVector(emptyVector2, "emptyVector2");

    // Тестирование граничных случаев
    printf("\n=== Граничные случаи ===\n");
    
    // Сравнение с NULL
    Vector *nullVector = NULL;
    // int result7 = isEqual(vector1, nullVector); // Это может вызвать ошибку
    printf("Сравнение с NULL не выполняется (потенциальная ошибка)\n");
    
    // Копирование NULL вектора
    // copyVector(vector1, nullVector); // Это может вызвать ошибку
    printf("Копирование NULL вектора не выполняется (потенциальная ошибка)\n");

    // Освобождение памяти
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