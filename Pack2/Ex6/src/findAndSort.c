#include "../include/functions.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


Returncode find(Student * students, const void * toFind, Student ** found, int * sizeStuds, int * sizeFound, int * capacityFound, Type type, bool * isFound) {
    
    if (students == NULL || toFind == NULL || found == NULL || sizeFound == NULL || capacityFound == NULL  || sizeStuds == NULL) {
        return NULL_POINTER;
    }
    if (*capacityFound == 0) {
        return WRONG_STRUCT; 
    }
    
    long int id = 0;
    bool foundSmth = false;
    
    if (*capacityFound == 0) {
        *capacityFound = 1; 
    }

    if (type == ID) {
        char * endptr;
        id = strtol(toFind, &endptr, 10);
        if (endptr == (const char*)toFind) {
            return WRONG_STRUCT; 
        }
        if (*endptr != '\0') {
            return WRONG_STRUCT; 
        }
    }

    for (int i = 0; i < *sizeStuds; ++i) {

        if (*sizeFound == *capacityFound) {
            *capacityFound *= 2;
            Student * tmp = (Student*)realloc(*found, *capacityFound * sizeof(Student));
            if (!tmp) {
                return NULL_POINTER;
            }
            *found = tmp;
        }

        switch (type) {
            case ID:
                if (students[i].id == id) {
                    foundSmth = true;
                    *isFound = true;
                }                  
                break;
            case NAME:
                if (strcmp(students[i].name, (char*)toFind) == 0) {
                    foundSmth = true;
                    *isFound = true;
                }                    
                break;
            case SURNAME:
                if (strcmp(students[i].surname, (char*)toFind) == 0) {
                    foundSmth = true;
                    *isFound = true;
                }                      
                break;          
            case GROUP:
                if (strcmp(students[i].group, (char*)toFind) == 0) {
                    foundSmth = true;
                    *isFound = true;
                }                    
                break;
        }
        if (foundSmth) {
            (*found)[*sizeFound] = students[i];
            (*sizeFound)++;
            foundSmth = false; 
        }
    }
    
    return OK;
}


int compId(const void * student1, const void * student2) {
    Student * stud1 = (Student*) student1;
    Student * stud2 = (Student*) student2;
    return ((stud1->id > stud2->id) - (stud1->id < stud2->id));
}

int compName(const void * student1, const void * student2) {
    Student * stud1 = (Student*) student1;
    Student * stud2 = (Student*) student2;
    return (strcmp(stud1->name, stud2->name));
}
int compSurname(const void * student1, const void * student2) {
    Student * stud1 = (Student*) student1;
    Student * stud2 = (Student*) student2;
    return (strcmp(stud1->surname, stud2->surname));
}

int compGroup(const void * student1, const void * student2) {
    Student * stud1 = (Student*) student1;
    Student * stud2 = (Student*) student2;
    return (strcmp(stud1->group, stud2->group));
}

Returncode sort(Student * students, int * sizeStud, Type type) {
    switch (type) {
        case NAME:
            qsort(students, *sizeStud, sizeof(Student), compName);
            break;
        case SURNAME:
            qsort(students, *sizeStud, sizeof(Student), compSurname);
            break;
        case GROUP:
            qsort(students, *sizeStud, sizeof(Student), compGroup);
            break;
        case ID:
            qsort(students, *sizeStud, sizeof(Student), compId);
            break;
    }
    return OK;
}
