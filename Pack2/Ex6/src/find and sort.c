#include "../include/functions.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


Returncode find(Student * students, const void * toFind, Student * found, size_t * sizeStuds, size_t * sizeFound, size_t * capacityFound, Type type) {
    if (students == NULL || toFind == NULL || found == NULL || sizeFound == NULL || capacityFound == NULL  || sizeStuds == NULL) {
        return NULL_POINTER;
    }
    // переместить проверку на вместимость в цикл!!!!!!!!!!!!!
    if (*sizeFound == 0 || *capacityFound == 0 || *sizeStuds == 0) {
        return WRONG_STRUCT; // not great
    }
    if (*sizeFound == *capacityFound) {
        *capacityFound *= 2;
        Student * foundId = (Student*)realloc(found, *capacityFound * sizeof(Student));
        if (!found) {
            return NULL;
        }
    }

    for (size_t i = 0; i < *sizeStuds; ++i) {
        switch (type) {
            case ID:
                if (students[i].id == *(unsigned int*)toFind) {
                    found[i] = students[i];
                    *sizeFound++;
                    break;
                }
            case NAME:
                if (strcmp(students[i].name, (char*)toFind) == 0) {
                    found[i] = students[i];
                    *sizeFound++;
                    break;
                }
            case SURNAME:
                if (strcmp(students[i].surname, (char*)toFind) == 0) {
                    found[i] = students[i];
                    *sizeFound++;
                    break;
                }            
            case GROUP:
                if (strcmp(students[i].group, (char*)toFind) == 0) {
                    found[i] = students[i];
                    *sizeFound++;
                    break;
                }
        }
    }
    
    return OK;
}


int compId(const void * id1, const void * id2) {
    return (unsigned int*)id1 - (unsigned int*)id2;
}

int compNameGroup(const void * string1, const void * string2) {
    return strcmp((char*)string1, (char*)string2);
}

Returncode sort(Student * students, size_t * sizeStud, Type type) {
    switch (type) {
        case NAME:
        case SURNAME:
        case GROUP:
            qsort(students, (size_t)sizeStud, sizeof(Student), compNameGroup); // qsort returns nothing
            break;
        default:
            qsort(students, (size_t)sizeStud, sizeof(Student),compId);
    }
}
