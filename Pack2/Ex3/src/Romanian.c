#include "../include/functions.h"


ReturnCode RomanNums(int *n, char *str) {
    if (!str) {
        return NULL_POINTER;
    }

    if (*n >= 4000 || *n <= 0) {
        return NO_ROMANIAN;
    }

    char strres[16] = {0};
    char *p = strres;

    const char * units[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const char * dozens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char * hundreds[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char * thousands[3] = {"M", "MM", "MMM"};  // мб закинуть эти массивы в заголовочный?

    int a = *n % 10;        
    int b = *n / 10 % 10;   
    int c = *n / 100 % 10;  
    int d = *n / 1000 % 10; 

    if (d > 0) {
        strcpy(p, thousands[d - 1]);
        p += strlen(thousands[d - 1]);
    }

    if (c > 0) {
        strcpy(p, hundreds[c - 1]);
        p += strlen(hundreds[c - 1]);
    }

    if (b > 0) {
        strcpy(p, dozens[b - 1]);
        p += strlen(dozens[b - 1]);
    }

    if (a > 0) {
        strcpy(p, units[a - 1]);
    }

    strcpy(str, strres);
    return OK;
}
