#ifndef LIVER_H
#define LIVER_H

#include <stddef.h>


typedef struct Liver {
    const unsigned int ID;
    char * surname;
    char * name;
    char * patronymic; // а скок памяти то, а? выделить!
    char * birthday;
    char sex;
    double avIncome;
} Liver;


Liver * createLiver(size_t count, ...); // в аргументы передаем данные для полей в порядке, как в структуре
void deleteLiver(Liver * liver);
void updateLiver(Liver * liver, size_t count, ...); // поменять аргументы

#endif