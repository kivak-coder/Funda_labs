#include "../include/functions.h"

void print(char ** words, int * size) {
    for (int i = 0; i < *size; ++i) {
        printf("i: %i, word: %s,\n", i, words[i]);
    }
}
