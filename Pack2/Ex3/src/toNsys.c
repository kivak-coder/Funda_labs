#include "../include/functions.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    if (!str) return;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

ReturnCode toNSys(int num, char * str, const int base, bool up) {
    if (!num || !str) {
        return NULL_POINTER;
    }

    if (base > 36 || base < 2) {
        return INVALID_DATA;
    }

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return OK;
    }

    char * ptr = str;
    int digit = 0;
    bool isNegative = false;

        
    if (num < 0) {
        isNegative = true;
        num *= -1;
    }

    while (num > 0) {

        digit = num % base;
        if (digit > 9) {
            if (up) {
                *ptr = digit - 10 + 'A'; 
            } else {
                *ptr = digit - 10 + 'a';
            }
        } else {
            *ptr = digit + '0';
        }

        ++ptr;
        num /= base;
    }
    if (isNegative) {
        *ptr = '-';
        ++ptr;
    }
    
    *ptr = '\0';
    reverseString(str);
    return OK;
}

int main() {
    int n = -12345;
    char str[10];
    toNSys(n, str, 36, true);
    printf("%i ", n);
    printf("%s\n", str);
    return 0;
}