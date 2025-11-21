#include "include/functions.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char result[34] = {0};
    char msg[34] = {0};
    char *ptr = NULL;
    long int num = 0; int r = 0;
    ReturnCode returnCode;

    printf("Enter number: (type 'stop' to exit): ");
    while (fgets(msg, sizeof(msg), stdin) != NULL) {

        if (strncmp(msg, "stop", 4) == 0) {
            break;
        }

        num = strtol(msg, &ptr, 10);
        if (ptr == msg) {
            printf("Invalid number!\n");
            printf("Enter number: ");
            continue;
        }
        if (num == LONG_MAX || num == LONG_MIN) {
            printf("Overflow!\n");
            break;
        }

        printf("Enter base (1-5): ");
        if (scanf("%d", &r) != 1) {
            printf("Invalid format!\n");
            break;
        }
        
        if (r < 1 || r > 5) {
            printf("Base must be between 1 and 5!\n");
            break;
        }

        while (getchar() != '\n');
        memset(result, 0, sizeof(result));
        ptr = NULL;

        returnCode = convertToBase(num, result, r);
        if (returnCode == OK) {
            printf("%ld in 2 ** %d base is %s\n\n", num, r, result);
        } else {
            printf("Error during conversion!\n\n");
        }

        printf("Enter number: ");
    }
    return 0;
}