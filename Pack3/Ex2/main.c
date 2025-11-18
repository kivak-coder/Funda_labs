#include "include/vector.h"
#include <stdio.h>

VECTOR_DEF(int);

int CopyFunc(int n){
    return n;
}
void DeleteFunc(int n) {
    n = 0;
}

int main () {
    Vector * vector = createVector(10, CopyFunc, DeleteFunc);
    pushBackVector(vector, 5);
    printf("%i", getAtVector(vector,0));
}