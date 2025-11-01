#include "../include/functions.h"
#include <string.h>

ReturnCode RomanianNums(int *n, char *str) {

    const char * units[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const char * dozens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char * hundreds[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char * thousands[4] = {"M", "MM", "MMM"};

    int i = 0;
    char * p = str + strlen(str);
    while (*n > 0) {
        int num = *n % 10; 
        strcat(str,units[num - 1]); // ??
        *n /= 10;  
    }

    return OK;
}