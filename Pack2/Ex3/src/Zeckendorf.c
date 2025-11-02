#include "../include/functions.h"

ReturnCode Zeckendorf(unsigned int a, char * str) {
    if (!str) {
        return NULL_POINTER;
    }

    int capacity = CAPACITY;
    int size = 1;
    int count = 1; 

    unsigned int * fibonacci = (unsigned int *)calloc(sizeof(unsigned int), capacity); 

    if (!fibonacci) {return MEMORY_ALLOCATION_ERROR;}
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    while (a > fibonacci[size]) { // заполняем числами фибоначчи до первого числа больше а

        ++size;

        if (size >= capacity) {
            capacity *= 2;
            unsigned int * tmp = (unsigned int *)realloc(fibonacci, capacity * sizeof(unsigned int)); 

            if (!tmp) {
                free(fibonacci);
                return MEMORY_ALLOCATION_ERROR;
            }

            fibonacci = tmp;
        }

        fibonacci[size] = fibonacci[size - 1] + fibonacci[size - 2];
    }

    ++size;
    fibonacci[size] = fibonacci[size - 1] + fibonacci[size - 2];

    for (int i = 0; i < size - 2; ++i) {
        str[i] = '0';
    }

    str[size - 3] = '1';
    str[size - 2] = '\0';


    while (a > 0) {

        for (int i = size - 1; i > 0; i--) {
            if (fibonacci[i] <= a && fibonacci[i + 1] > a) {
                count = i;
                str[count - 2] = '1';  // отмечаем единичками встреченные числа фибоначчи
                break;
            }
        }

        a -= fibonacci[count];
        size = count;
    }

    free(fibonacci);
    return OK;

}  // а тут все нормально с валидациями????????????
