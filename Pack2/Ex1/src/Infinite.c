#include "../include/functions.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

ReturnCode IsInfinite(int num, int denum, int base) {
    if (denum == 0 || base < 0) {
        return WRONG_DATA;
    }

    int res = 1;
    ReturnCode ReturnCode;
    ReturnCode = gcd(num, denum, &res); // ищем НОД чтобы сократить дробь
    if (ReturnCode == WRONG_DATA) {
        return WRONG_DATA;
    } 
    if (ReturnCode == OK) {
        num /= res; // сокращаем дробь
        denum /= res;
    }

    int tempDenum = denum;
    ReturnCode = gcd(denum, base, &res);

    if (ReturnCode != OK) {
        return ReturnCode;
    }
    
    if (res == 1) {
        return INFINITE;;
    }

    for (int i = 2; i < denum; ++i) { 
        if (tempDenum % i == 0) {
            int tempBase = base;
            ReturnCode = gcd(i, tempBase, &res);

            if (ReturnCode != OK) {
                return ReturnCode;
            }

            if (res == 1) { // взаимно простые - дробь бесконечна
                return INFINITE;
            }
        }
        while (tempDenum % i == 0) { // убираем все такие делители
            tempDenum /= i;
        }

    }
    return FINITE;
}

ReturnCode AreInfinite(int n, int base, ...) {
    if (base < 2 || n < 1) {
        return WRONG_DATA;
    }

    double denum = 0; double num = 0;
    ReturnCode returnCode;

    va_list arg;
    va_start(arg, base);

    for (int i = 0; i < n; ++i) {
        double a = va_arg(arg, double);

        if (fabs(a) < EPS || fabs(a - EPS) > 1 || a < 0) {
            printf("Too small value!\n");
            continue;
        } 

        returnCode = DivToNumDenum(a, &num, &denum); 

        if (returnCode != OK) {
            return returnCode;
            continue;
        }

        returnCode = IsInfinite(num, denum, base);
        if (returnCode == INFINITE) {
            printf("The partion %.10f is INNFINITE in %d base.\n", a, base);
        }
        if (returnCode == FINITE) {
            printf("The partion %.10f is FINITE in %d base.\n", a, base);
        }
        if (returnCode == WRONG_DATA) {
            printf("Come across invalid data\n");
        }
    }
    va_end(arg);

    return OK;
}