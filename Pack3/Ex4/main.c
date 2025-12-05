#include <stdio.h>
#include <stdlib.h>
#include "include/heap.h"

int main() {
    Heap heap = createHeap(0);
    int choice, value, result;
    size_t size;
    
    printf("=== Меню работы с кучей ===\n");
    
    do {
        printf("\nВыберите действие:\n");
        printf("1. Создать новую кучу\n");
        printf("2. Добавить элемент\n");
        printf("3. Извлечь верхний элемент\n");
        printf("4. Просмотреть верхний элемент\n");
        printf("5. Проверить пустоту кучи\n");
        printf("6. Получить размер кучи\n");
        printf("7. Вывести кучу\n");
        printf("8. Построить кучу из массива\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                printf("Введите начальную емкость: ");
                scanf("%zu", &size);
                deleteHeap(&heap); 
                heap = createHeap(size);
                if (heap.data) {
                    printf("Куча создана успешно\n");
                } else {
                    printf("Ошибка создания кучи\n");
                }
                break;
            }
            
            case 2: {
                printf("Введите значение для добавления: ");
                scanf("%d", &value);
                pushHeap(&heap, value);
                printf("Элемент %d добавлен в кучу\n", value);
                break;
            }
            
            case 3: {
                result = popHeap(&heap);
                if (result != -1) {
                    printf("Извлечен элемент: %d\n", result);
                }
                break;
            }
            
            case 4: {
                result = peekHeap(&heap);
                if (result != -1) {
                    printf("Верхний элемент: %d\n", result);
                } 
                break;
            }
            
            case 5: {
                result = isEmptyHeap(&heap);
                if (result) {
                    printf("Куча пуста\n");
                } else if (result == 0) {
                    printf("Куча не пуста\n");
                } else {
                    printf("Ошибка\n");
                }
                break;
            }
            
            case 6: {
                size = sizeHeap(&heap);
                printf("Размер кучи: %zu\n", size);
                break;
            }
            
            case 7: {
                printHeap(&heap);
                break;
            }
            
            case 8: {
                printf("Введите количество элементов: ");
                scanf("%zu", &size);
                if (size > 0) {
                    int *array = (int*)malloc(sizeof(int) * size);
                    if (array) {
                        printf("Введите %zu элементов: ", size);
                        for (size_t i = 0; i < size; i++) {
                            scanf("%d", &array[i]);
                        }
                        deleteHeap(&heap);
                        heap = buildHeap(array, size);
                        free(array);
                        printf("Куча построена из массива\n");
                    } else {
                        printf("Ошибка выделения памяти\n");
                    }
                }
                break;
            }
            
            case 0: {
                break;
            }
            
            default: {
                printf("Неверный выбор\n");
                break;
            }
        }
        
    } while (choice != 0);
    
    deleteHeap(&heap);
    return 0;
}