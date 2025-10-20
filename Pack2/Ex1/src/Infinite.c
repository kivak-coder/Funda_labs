#include "../include/functions.h"
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

ReturnCode IsInfinite(int num, int denum, int base, bool *isInf) {
    int res = 1;
    int x;
    ReturnCode ReturnCode;
    ReturnCode = gcd(num, denum, &res); // ищем НОД чтобы сократить дробь
    if (ReturnCode == WRONG_DATA) {
        return WRONG_DATA;
    } 
    if (ReturnCode == OK) {
        num /= res; // сокращаем дробь
        denum /= res;
    }

    ReturnCode = gcd(denum, base, &res); // ищем НОД у знаменателя и основания новой СС
    if (ReturnCode == WRONG_DATA) {
        return WRONG_DATA;
    } 
    if (ReturnCode == OK) {
        if (res == 1) { // если взаимно простые - дробь бесконечна
            return INFINITE;
        } else {
            if (denum / res == 1 || base / res == 1) {
                return FINITE;
            } else {
                return INFINITE;
            }
        }  
    }
    return OK;
}

ReturnCode AreInfinite(int n, int base, ...) {
    double denum = 0; double num = 0;
    bool isInf = false;
    ReturnCode returnCode;

    va_list arg;
    va_start(arg, base);

    for (int i = 0; i < n; ++i) {
        double a = va_arg(arg, double);

        if (a < EPS || fabs(a - EPS) > 1) {
            return WRONG_DATA;
        } 

        returnCode = DivToNumDenum(a, &num, &denum); // cho

        returnCode = IsInfinite(num, denum, base, &isInf);
        if (returnCode == INFINITE) {
            printf("The partion %.10f is INNFINITE in %d base.\n", a, base);
        }
        if (returnCode == FINITE) {
            printf("The partion %.10f is FINITE in %d base.\n", a, base);
        }
    }
    va_end(arg);

    return OK;
}