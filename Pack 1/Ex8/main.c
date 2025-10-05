#include "include/functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() {

    int base = 0;
    char str[BUFSIZ];
    char numS[10];
    long int max = 0;
    long int num = 0;
    long int numN = 0;
    int underZero = 1;
    ReturnCode returnCode;

    printf("Enter the base of the numeral sistem:");
    scanf("%s", str);
    returnCode = parseBase(str, &base);

    if (returnCode == WRONG_TYPE) {
        printf("Wrong symbols in base detected!\n");
        return 0;
    }
    if (returnCode == WRONG_BASE) {
        printf("Your base should be in [2...36]!\n");
        return 0;
    } 
    if (returnCode == OVERFLOW) {
        printf("Too big input. Overflow!\n");
    }
    
    printf("Enter your number:");
    scanf("%s", str);

    while (strcmp(str, "Stop") != 0) {
        returnCode = parseNum(str, &base, &underZero);
        if (returnCode == WRONG_NUM) {
            printf("Number in this numeric system should not contain such digits!\n");
            return 0;
        }
        if (returnCode == WRONG_TYPE) {
            printf("Wrong type symbols detected in number!\n");
            return 0;
        }
        
        toDecInt(str, base, &num);
        if (labs(num) > labs(max)) {
            max = num;
        }
        num = 0;  
        printf("Enter your number:");
        scanf("%s", str);      
    }
    printf("Max absolute number: %ld\n", max);
    for (int i = 9; i <= 36; i += 9) {
        char maxS[BUFSIZ];
        toNsistem(maxS, i, max);
        printf("%d-base: %s\n", i, maxS);
    }
    return 0;

}