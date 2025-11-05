#include "../include/functions.h"
#include <stdio.h>
#include <string.h>

void test1() {
    printf("=== Test 1: Roman Numerals ===\n");
    
    char buffer[100];
    int test_cases[] = {1, 4, 9, 49, 99, 449, 999, 1987, 2023};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_cases; i++) {
        ReturnCode result = RomanNums(&test_cases[i], buffer);
        if (result == OK) {
            printf("%d = %s\n", test_cases[i], buffer);
        } else {
            printf("%d = ERROR: %d\n", test_cases[i], result);
        }
    }
    printf("\n");
}

void test2() {
    printf("=== Test 2: Zeckendorf Representation ===\n");
    
    char buffer[100];
    unsigned int test_cases[] = {1, 2, 3, 4, 5, 10, 20, 50, 100};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_cases; i++) {
        ReturnCode result = Zeckendorf(test_cases[i], buffer);
        if (result == OK) {
            printf("%u = %s\n", test_cases[i], buffer);
        } else {
            printf("%u = ERROR: %d\n", test_cases[i], result);
        }
    }
    printf("\n");
}

void test3() {
    printf("=== Test 3: Number System Conversion ===\n");
    
    char buffer[100];
    int numbers[] = {10, -10, 255, -255, 1024};
    int bases[] = {2, 8, 10, 16, 36};
    int num_numbers = sizeof(numbers) / sizeof(numbers[0]);
    int num_bases = sizeof(bases) / sizeof(bases[0]);
    
    for (int i = 0; i < num_numbers; i++) {
        for (int j = 0; j < num_bases; j++) {
            ReturnCode result = toNSys(numbers[i], buffer, bases[j], false);
            if (result == OK) {
                printf("%d in base %d = %s\n", numbers[i], bases[j], buffer);
            } else {
                printf("%d in base %d = ERROR: %d\n", numbers[i], bases[j], result);
            }
        }
    }
    printf("\n");
}

void test4() {
    printf("=== Test 4: Decimal Conversion ===\n");
    
    char input[] = "FF";
    char output[100];
    int bases[] = {2, 8, 16, 10};
    int num_bases = sizeof(bases) / sizeof(bases[0]);
    
    for (int i = 0; i < num_bases; i++) {
        ReturnCode result = toDecSys(input, bases[i], output);
        if (result == OK) {
            printf("\"%s\" in base %d = %s (decimal)\n", input, bases[i], output);
        } else {
            printf("\"%s\" in base %d = ERROR: %d\n", input, bases[i], result);
        }
    }
    printf("\n");
}

void test5() {
    printf("=== Test 5: String Reversal ===\n");
    
    char test_strings[][50] = {"hello", "12345", "a", ""};
    int num_strings = sizeof(test_strings) / sizeof(test_strings[0]);
    
    for (int i = 0; i < num_strings; i++) {
        char buffer[50];
        strcpy(buffer, test_strings[i]);
        reverseString(buffer);
        printf("\"%s\" reversed = \"%s\"\n", test_strings[i], buffer);
    }
    printf("\n");
}

void test6() {
    printf("=== Test 6: overfprintf and oversprintf ===\n");
    
    char buffer[200];
    
    // Test oversprintf
    int result1 = oversprintf(buffer, "Roman: %Ro, Zeckendorf: %Zr", 2023, 20);
    printf("oversprintf result: %s\n", buffer);
    
    // Test overfprintf
    printf("overfprintf result: ");
    overfprintf(stdout, "Base 16: %Cv, Base 2: %Cv\n", 255, 16, 255, 2);
    
    printf("\n");
}