#include "include/tests.h"
#include <stdio.h>

int main() {
    printf("Starting all tests...\n\n");
    
    test1();  // Roman numerals
    test2();  // Zeckendorf representation  
    test3();  // Number system conversion
    test4();  // Decimal conversion
    test5();  // String reversal
    test6();  // overfprintf and oversprintf
    
    printf("All tests completed.\n");
    return 0;
}