#include "../include/functions.h"
#include <stdio.h>
#include <string.h>

void test1() {
    printf("\n");
}

void test2() {
    printf("\n");
}

void test3() {
    printf("\n");
}

void test4() {
    printf("\n");
}

void test5() {
    printf("\n");
}

void test6() {
    printf("=== Test 6: overfprintf and oversprintf ===\n");
    
    char buffer[200];
    
    // Test oversprintf
    int result1 = oversprintf(buffer, "Roman: %Ro, Zeckendorf: %Zr, Fucking slave: %mi, sys: %to", 2023, 20, 1234, "abc56", 16);
    printf("oversprintf result: %s\n", buffer);
    
    // Test overfprintf
    printf("overfprintf result: ");
    overfprintf(stdout, "Base 16: %CV, Base 2: %Cv, just num: %i \n", 255, 16, 255, 2, 100);
    
    printf("\n");
}