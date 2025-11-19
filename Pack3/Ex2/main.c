#include "include/vector.h"
#include <stdio.h>
#include <stdlib.h>

VECTOR_DEF(int);

int CopyFunc(int n){
    return n;
}
void DeleteFunc(int n) {
    n = 0;
}

void printMenu() {
    printf("\n=== МЕНЮ ВЕКТОРА ===\n");
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
}

void createVectorUI(Vector **vector) {
    if (*vector != NULL) {
        printf("Вектор уже существует! Сначала удалите его.\n");
        return;
    }
    
    size_t capacity;
    printf("Введите начальную емкость вектора: ");
    scanf("%zu", &capacity);
    
    *vector = createVector(capacity, CopyFunc, DeleteFunc);
    if (*vector != NULL) {
        printf("Вектор успешно создан с емкостью %zu\n", capacity);
    } else {
        printf("Ошибка при создании вектора!\n");
    }
}

void pushBackVectorUI(Vector *vector) {
    if (vector == NULL) {
        printf("Вектор не создан! Сначала создайте вектор.\n");
        return;
    }
    
    int value;
    printf("Введите значение для добавления: ");
    scanf("%d", &value);
    
    pushBackVector(vector, value);
    printf("Элемент %d добавлен в вектор\n", value);
}

void getAtVectorUI(Vector *vector) {
    if (vector == NULL) {
        printf("Вектор не создан! Сначала создайте вектор.\n");
        return;
    }
    
    if (vector->size == 0) {
        printf("Вектор пуст!\n");
        return;
    }
    
    size_t index;
    printf("Введите индекс элемента (0-%zu): ", vector->size - 1);
    scanf("%zu", &index);
    
    int value = getAtVector(vector, index);
    printf("Элемент по индексу %zu: %d\n", index, value);
}

void deleteAtVectorUI(Vector *vector) {
    if (vector == NULL) {
        printf("Вектор не создан! Сначала создайте вектор.\n");
        return;
    }
    
    if (vector->size == 0) {
        printf("Вектор пуст!\n");
        return;
    }
    
    size_t index;
    printf("Введите индекс элемента для удаления (0-%zu): ", vector->size - 1);
    scanf("%zu", &index);
    
    DeleteAtVector(vector, index);
    printf("Элемент по индексу %zu удален\n", index);
}

void showVectorInfo(Vector *vector) {
    if (vector == NULL) {
        printf("Вектор не создан!\n");
        return;
    }
    
    printf("Размер вектора: %zu\n", vector->size);
    printf("Емкость вектора: %zu\n", vector->capacity);
}

void showAllElements(Vector *vector) {
    if (vector == NULL) {
        printf("Вектор не создан!\n");
        return;
    }
    
    if (vector->size == 0) {
        printf("Вектор пуст!\n");
        return;
    }
    
    printf("Элементы вектора:\n");
    for (size_t i = 0; i < vector->size; i++) {
        printf("[%zu] = %d\n", i, vector->data[i]);
    }
}

void copyVectorUI(Vector **vector, Vector **vectorCopy) {
    if (*vector == NULL) {
        printf("Исходный вектор не создан!\n");
        return;
    }
    
    if (*vectorCopy != NULL) {
        printf("Копия уже существует! Сначала удалите ее.\n");
        return;
    }
    
    *vectorCopy = copyVectorNew(*vector);
    if (*vectorCopy != NULL) {
        printf("Копия вектора успешно создана\n");
    } else {
        printf("Ошибка при создании копии!\n");
    }
}

void compareVectorsUI(Vector *vector1, Vector *vector2) {
    if (vector1 == NULL || vector2 == NULL) {
        printf("Оба вектора должны быть созданы для сравнения!\n");
        return;
    }
    
    int result = isEqual(vector1, vector2);
    if (result) {
        printf("Векторы идентичны\n");
    } else {
        printf("Векторы различны\n");
    }
}

int main() {
    Vector *vector = NULL;
    Vector *vectorCopy = NULL;
    int choice;
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createVectorUI(&vector);
                break;
                
            case 2:
                pushBackVectorUI(vector);
                break;
                
            case 3:
                getAtVectorUI(vector);
                break;
                
            case 4:
                deleteAtVectorUI(vector);
                break;
                
            case 5:
                showVectorInfo(vector);
                break;
                
            case 6:
                showAllElements(vector);
                break;
                
            case 7:
                copyVectorUI(&vector, &vectorCopy);
                break;
                
            case 8:
                if (vector != NULL) {
                    deleteVector(vector);
                    vector = NULL;
                    printf("Вектор удален\n");
                } else {
                    printf("Вектор не создан!\n");
                }
                break;
                
            case 9:
                compareVectorsUI(vector, vectorCopy);
                break;
                
            case 0:
                printf("Выход из программы...\n");
                break;
                
            default:
                printf("Неверная команда! Попробуйте снова.\n");
                break;
        }
        
        // Очистка буфера ввода
        while (getchar() != '\n');
        
    } while (choice != 0);
    
    // Освобождение памяти перед выходом
    if (vector != NULL) {
        deleteVector(vector);
    }
    if (vectorCopy != NULL) {
        deleteVector(vectorCopy);
    }
    
    return 0;
}