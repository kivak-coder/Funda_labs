#include "include/tests.h"
#include <stdio.h>

int main() {
    test_roman();
    test_zeckendorf();
    test_number_systems();
    test_conversion();
    test_memory_dump();
    test_combined();
    test_edge_cases();
    test_file_output();
    test_performance();
    
    printf("=== All tests completed ===\n");
    return 0;
}