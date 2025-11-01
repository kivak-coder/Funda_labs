#include <stdio.h>
#include <string.h>

typedef enum {
    OK,
    NULL_POINTER,
    NO_ROMANIAN
} ReturnCode;

void reverseString(char *str) {
    if (!str) return;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

ReturnCode RomanianNums(int *n, char *str) {
    if (!str) {
        return NULL_POINTER;
    }

    if (*n >= 4000 || *n <= 0) {
        return NO_ROMANIAN;
    }

    char strres[16] = {0};
    char *p = strres;

    const char *units[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const char *dozens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char *hundreds[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char *thousands[3] = {"M", "MM", "MMM"};

    int a = *n % 10;        // единицы
    int b = *n / 10 % 10;   // десятки
    int c = *n / 100 % 10;  // сотни
    int d = *n / 1000 % 10; // тысячи

    // Правильный порядок: начинаем с тысяч
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

    // Копируем результат в выходную строку
    strcpy(str, strres);
    return OK;
}

int main() {
    char str[16] = {0};
    int n = 234;
    RomanianNums(&n, str);
    printf("Римское число: %s\n", str); // Должно быть "CCXXXIV"
    return 0;
}