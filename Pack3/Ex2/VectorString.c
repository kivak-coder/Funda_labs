#include "include/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VECTOR_DEF(char *);

char* CopyFunc(char * str){
    return strdup(str);
}

void DeleteFunc(char * str) {
    free(str);
}

int main() {
    Vector *vector = NULL;
    Vector *vectorCopy = NULL;
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
        printf("9. Сравнить с другим вектором\n");
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
                    printf("Вектор успешно создан с емкостью %zu\n", capacity);
                } else {
                    printf("Ошибка при создании вектора!\n");
                }
                break;
            }
                
            case 2: {
                if (vector == NULL) {
                    printf("Вектор не создан! Сначала создайте вектор.\n");
                    break;
                }
                
                char * value = malloc(100 * sizeof(char *));
                printf("Введите значение для добавления: ");
                scanf("%99s", value);

                value[strlen(value)] = '\0';
                
                pushBackVector(vector, value);
                printf("Элемент %s добавлен в вектор\n", value);
                break;
            }
                
            case 3: {
                if (vector == NULL) {
                    printf("Вектор не создан! Сначала создайте вектор.\n");
                    break;
                }
                
                if (vector->size == 0) {
                    printf("Вектор пуст!\n");
                    break;
                }
                
                size_t index;
                printf("Введите индекс элемента (0-%zu): ", vector->size - 1);
                scanf("%zu", &index);
                
                if (index < vector->size) {
                    char * value = getAtVector(vector, index);
                    printf("Элемент по индексу %zu: %s\n", index, value);
                } else {
                    printf("Неверный индекс!\n");
                }
                break;
            }
                
            case 4: {
                if (vector == NULL) {
                    printf("Вектор не создан! Сначала создайте вектор.\n");
                    break;
                }
                
                if (vector->size == 0) {
                    printf("Вектор пуст!\n");
                    break;
                }
                
                size_t index;
                printf("Введите индекс элемента для удаления (0-%zu): ", vector->size - 1);
                scanf("%zu", &index);
                
                if (index < vector->size) {
                    DeleteAtVector(vector, index);
                    printf("Элемент по индексу %zu удален\n", index);
                } else {
                    printf("Неверный индекс!\n");
                }
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
                    printf("[%zu] = %s\n", i, vector->data[i]);
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
                
            case 9: {
                if (vector == NULL || vectorCopy == NULL) {
                    printf("Оба вектора должны быть созданы для сравнения!\n");
                    break;
                }
                
                int result = isEqual(vector, vectorCopy);
                if (result) {
                    printf("Векторы идентичны\n");
                } else {
                    printf("Векторы различны\n");
                }
                break;
            }
                
            case 0:
                printf("Выход из программы...\n");
                break;
                
            default:
                printf("Неверная команда! Попробуйте снова.\n");
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