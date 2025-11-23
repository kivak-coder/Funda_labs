#include "include/tests.h"
#include <stdio.h>
#include "include/functions.h"

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

    char str2[BUFSIZ] = {};
    FILE * file = fopen("1.txt", "w");
    oversprintf(str2, "base 32: %to, roman: %Ro, %i, memory: %mu, %Cv, double: %f\n", "32", 32, 1024, -5, 100025, 35879, 17, 10.3829);
    printf("%s\n", str2);
    overfprintf(file, "base 32: %to, roman: %Ro, %i, memory: %mu, %Cv, double: %f\n", "32", 32, 1024, -5, 100025, 35879, 17, 10.3829);
    overfprintf(file, "%f", 23.3728328);
    printf("=== All tests completed ===\n");
    return 0;
}