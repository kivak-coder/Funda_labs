#include "include/functions.h"
#include <string.h>
#include <stdio.h>


int main(){

    int base = 0;
    char str[100];
    char numS[10];
    char maxS[10];
    long int max = 0;
    long int num = 0;
    long int numN = 0;

    printf("Enter the base of the numeral sistem:");
    // scanf("%s", str);
    scanf("%d", &base);

    printf("Enter your number:");
    scanf("%s", str);
    while (strcmp(str, "Stop") != 0){
    
        toDecInt(str, base, &num);
        printf("%ld\n", num);
        if (num > max){
            max = num;
            strcpy(maxS, str);
        }
        num = 0;  
        printf("Enter your number:");
        scanf("%s", str);      
    }

    printf("%s\n", maxS);
    // printf("%ld\n", max);
    numN = max;
    for (int i = 9; i <= 36; i += 9){
        printf("%d\n", i);
        toNsistem(maxS, i, &numN);
        printf("%d-base: %s", i, maxS);
    }
    return 0;

}