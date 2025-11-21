#include "../include/functions.h"

int sum(int a, int b){
    int carry = 0;
    while (b != 0){
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int sub(int a, int b) {
    int borrow = 0;

    while (b != 0) {
        borrow = ((~a) & b);
        a = a ^ b;
        b = (borrow << 1);
    }
    return a;
}