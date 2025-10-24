#include "../include/functions.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Returncode find(Student * students, const void * toFind, Student * found, int * sizeStuds, int * sizeFound, int * capacityFound, Type type) {
    printf("ABOB\n");
    if (students == NULL || toFind == NULL || found == NULL || sizeFound == NULL || capacityFound == NULL  || sizeStuds == NULL) {
        return NULL_POINTER;
    }
    if (*sizeFound == 0 || *capacityFound == 0 || *sizeStuds == 0) {
        return WRONG_STRUCT; // not great
    }
    
    for (size_t i = 0; i < *sizeStuds; ++i) {
                printf("i-like: %zu\n", i);

        
        if (*sizeFound == *capacityFound) {
            *capacityFound *= 2;
            Student * tmp = (Student*)realloc(found, *capacityFound * sizeof(Student));
            if (!tmp) {
                return NULL_POINTER;
            }
            found = tmp;
        }

        switch (type) {
            case ID:
                if (students[i].id == *(unsigned int*)toFind) {
                    found[*sizeFound] = students[i];
                    (*sizeFound)++;
  
                }                  
                break;
            case NAME:
                if (strcmp(students[i].name, (char*)toFind) == 0) {
                    found[*sizeFound] = students[i];
                    (*sizeFound)++;

                }                    
                break;
            case SURNAME:
                if (strcmp(students[i].surname, (char*)toFind) == 0) {
                    found[*sizeFound] = students[i];
                    (*sizeFound)++;

                }                      
                break;          
            case GROUP:
                if (strcmp(students[i].group, (char*)toFind) == 0) {
                    found[*sizeFound] = students[i];
                    (*sizeFound)++;

                }                    
                break;
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
    return OK;
}
