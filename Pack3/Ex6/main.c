#include "include/functions.h"
#include <stdio.h>

int main() {
    char str[100];
    fgets(str, 100, stdin);
    ReturnCode rerurnCode = checkBrackets(str);
    if (rerurnCode == OK) {
        printf("OK!");
    } else {
        printf("NOT OK!");
    }
}