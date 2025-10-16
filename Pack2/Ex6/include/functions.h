#include "student.h"

typedef enum Returncode {
    OK,
    WRONG_STRUCT,
} Returncode;

Returncode search(Student * massive);
Returncode sort(Student * massive); // add comparer
Returncode parseStudent(Student * stud);