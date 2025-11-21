#include "../include/functions.h"

int strLen(const char *str) {
    if (!str) {
        return 0;
    }
    int k = 0;
    while (str[k] != '\0') {
        k = sum(k, 1);
    }
    return k;
}

ReturnCode reverse(char* str){
    int i = 0;
    int b = sub(strLen(str), 1);
    while (i < b){
        char tmp = str[i];
        str[i] = str[b];
        str[b] = tmp;
        i = sum(i, 1);
        b = sub(b, 1);
    }
    return OK;
}

ReturnCode rightShift(char* str){
    int size = strLen(str);
    str[sum(size, 1)] = '\0';
    for (int i = size; i > 0; i = sub(i, 1)){
        str[i] = str[sub(i, 1)];
    }
    return OK;
}