#include "include/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VECTOR_DEF(int);

int CopyFunc(int num){
    return num;
}

void DeleteFunc(int num) {
    num = 0;
    return;
}

int main() {
    Vector * vector = NULL;
    Vector * vectorCopy = NULL;
    int choice;
    
    do {
        printf("\n=== меню ===\n");
        printf("1. Создать вектор\n");
        printf("2. Добавить элемент\n");
        printf("3. Получить элемент по индексу\n");
        printf("4. Удалить элемент по индексу\n");
        printf("5. Показать размер и емкость\n");
        printf("6. Показать все элементы\n");
        printf("7. Создать копию вектора\n");
        printf("8. Удалить вектор\n");
        printf("0. Выход\n");
        printf("Выберите команду: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                if (vector != NULL) {
                    printf("Вектор уже существует! Сначала удалите его.\n");
                    break;
                }
                
                size_t capacity;
                printf("Введите начальную емкость вектора: ");
                scanf("%zu", &capacity);
                
                vector = createVector(capacity, CopyFunc, DeleteFunc);
                if (vector != NULL) {
                    printf("Вектор успешно создан\n");
                } else {
                    printf("Ошибка при создании вектора!\n");
                }
                break;
            }
                
            case 2: {
                if (vector == NULL) {
                    printf("Вектор не создан!\n");
                    break;
                }

                int value = 0;

                printf("Введите значение: ");
                scanf("%i", &value);
                
                pushBackVector(vector, value);
                printf("Элемент %d добавлен\n", value);
                break;
            }
                
            case 3: {
                if (vector == NULL) {
                    printf("Вектор не создан!\n");
                    break;
                }
                
                if (vector->size == 0) {
                    printf("Вектор пуст!\n");
                    break;
                }
                
                size_t index;
                printf("Введите индекс элемента (0-%zu): ", vector->size - 1);
                scanf("%zu", &index);
                
                int value = getAtVector(vector, index);
                printf("Элемент по индексу %zu: %i\n", index, value);
                break;
            }
                
            case 4: {
                if (vector == NULL) {
                    printf("Вектор не создан!\n");
                    break;
                }
                
                if (vector->size == 0) {
                    printf("Вектор пуст!\n");
                    break;
                }
                
                size_t index;
                printf("Введите индекс элемента для удаления (0-%zu): ", vector->size - 1);
                scanf("%zu", &index);
                
                DeleteAtVector(vector, index);
                printf("Элемент по индексу %zu удален\n", index);

                break;
            }
                
            case 5: {
                if (vector == NULL) {
                    printf("Вектор не создан!\n");
                    break;
                }
                printf("Размер вектора: %zu\n", vector->size);
                printf("Емкость вектора: %zu\n", vector->capacity);
                break;
            }
                
            case 6: {
                if (vector == NULL) {
                    printf("Вектор не создан!\n");
                    break;
                }
                
                if (vector->size == 0) {
                    printf("Вектор пуст!\n");
                    break;
                }
                
                printf("Элементы вектора:\n");
                for (size_t i = 0; i < vector->size; i++) {
                    printf("[%zu] = %i\n", i, vector->data[i]);
                }
                break;
            }
                
            case 7: {
                if (vector == NULL) {
                    printf("Исходный вектор не создан!\n");
                    break;
                }
                
                if (vectorCopy != NULL) {
                    printf("Копия уже существует! Сначала удалите ее.\n");
                    break;
                }
                
                vectorCopy = copyVectorNew(vector);
                if (vectorCopy != NULL) {
                    printf("Копия вектора успешно создана\n");
                } else {
                    printf("Ошибка при создании копии!\n");
                }
                break;
            }
                
            case 8: {
                if (vector != NULL) {
                    deleteVector(vector);
                    vector = NULL;
                    printf("Вектор удален\n");
                } else {
                    printf("Вектор не создан!\n");
                }
                break;
            }
                
            case 0:
                break;
                
            default:
                printf("Неверная команда!\n");
                break;
        }
        
        while (getchar() != '\n');
        
    } while (choice != 0);
    
    if (vector != NULL) {
        deleteVector(vector);
    }
    if (vectorCopy != NULL) {
        deleteVector(vectorCopy);
    }
    
    return 0;
}