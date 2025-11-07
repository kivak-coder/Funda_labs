#include "../include/functions.h"
#include <stdio.h>

void test_roman() {
    printf("=== Test 1: Roman numerals (%%Ro) ===\n");
    
    char buffer[200] = {0};
    int result = 0;
    
    // Базовые тесты
    result = oversprintf(buffer, "Basic: %Ro", 1);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Four: %Ro", 4);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Nine: %Ro", 9);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Граничные значения
    result = oversprintf(buffer, "Max basic: %Ro", 3999);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Year: %Ro", 2024);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Несколько римских чисел
    result = oversprintf(buffer, "Multiple: %Ro, %Ro, %Ro", 49, 94, 499);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Смешанные с стандартными спецификаторами
    result = oversprintf(buffer, "Mixed: %Ro (decimal: %d), %Ro (hex: 0x%x)", 255, 255, 100, 100);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Отрицательные числа (как обрабатываются?)
    result = oversprintf(buffer, "Negative: %Ro", -123);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    printf("\n");
}

void test_zeckendorf() {
    printf("=== Test 2: Zeckendorf representation (%%Zr) ===\n");
    
    char buffer[200] = {0};
    int result = 0;
    
    // Базовые тесты
    result = oversprintf(buffer, "Z1: %Zr", 1); // ABOB
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Z4: %Zr", 4);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Z10: %Zr", 10);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Z20: %Zr", 20);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Большие числа
    result = oversprintf(buffer, "Z100: %Zr", 100);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Несколько чисел Цекендорфа
    result = oversprintf(buffer, "Multiple Z: %Zr, %Zr, %Zr", 5, 15, 25);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    printf("\n");
}

void test_number_systems() {
    printf("=== Test 3: Number systems (%%Cv, %%CV) ===\n");
    
    char buffer[200] = {0};
    int result = 0;
    
    // Двоичная система
    result = oversprintf(buffer, "Binary: %Cv", 255, 2);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Восьмеричная система
    result = oversprintf(buffer, "Octal: %Cv", 255, 8);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Шестнадцатеричная система (нижний регистр)
    result = oversprintf(buffer, "Hex lower: %Cv", 255, 16);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Шестнадцатеричная система (верхний регистр)
    result = oversprintf(buffer, "Hex upper: %CV", 255, 16);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Системы с большими основаниями
    result = oversprintf(buffer, "Base 36 lower: %Cv", 35, 36);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Base 36 upper: %CV", 35, 36);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Невалидные основания
    result = oversprintf(buffer, "Invalid base 1: %Cv", 255, 1);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Invalid base 37: %Cv", 255, 37);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Отрицательные числа
    result = oversprintf(buffer, "Negative in hex: %Cv", -255, 16);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    printf("\n");
}

void test_conversion() {
    printf("=== Test 4: String to decimal (%%to, %%TO) ===\n");
    
    char buffer[200] = {0};
    int result = 0;
    
    // Из двоичной
    result = oversprintf(buffer, "Binary to dec: %to", "11111111", 2);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Из восьмеричной
    result = oversprintf(buffer, "Octal to dec: %to", "377", 8);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Из шестнадцатеричной (нижний регистр)
    result = oversprintf(buffer, "Hex lower to dec: %to", "ff", 16);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Из шестнадцатеричной (верхний регистр)
    result = oversprintf(buffer, "Hex upper to dec: %TO", "AAAB23", 16);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Из системы с основанием 36
    result = oversprintf(buffer, "Base36 to dec: %to", "z", 36);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Невалидные строки
    result = oversprintf(buffer, "Invalid hex: %to", "xyz", 16); // ABOB
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Invalid base: %to", "123", 37);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Пустая строка
    result = oversprintf(buffer, "Empty string: %to", "", 16);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    printf("\n");
}

void test_memory_dump() { // ABOOOOB
    printf("=== Test 5: Memory dump (%%mi, %%mu, %%md, %%mf) ===\n");
    
    char buffer[400] = {0};
    int result = 0;
    
    // Знаковый int
    int test_int = 1;
    result = oversprintf(buffer, "int 1: %mi", test_int);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    test_int = -1;
    result = oversprintf(buffer, "int -1: %mi", test_int);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Беззнаковый int
    unsigned int test_uint = 255;
    result = oversprintf(buffer, "uint 255: %mu", test_uint);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    test_uint = 4294967295U;
    result = oversprintf(buffer, "uint max: %mu", test_uint);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Double
    double test_double = 1.0;
    result = oversprintf(buffer, "double 1.0: %md", test_double);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    test_double = -3.14;
    result = oversprintf(buffer, "double -3.14: %md", test_double);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Float
    float test_float = 2.5f;
    result = oversprintf(buffer, "float 2.5: %mf", test_float);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    test_float = -0.5f;
    result = oversprintf(buffer, "float -0.5: %mf", test_float);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    printf("\n");
}

void test_combined() {
    printf("=== Test 6: Combined specifiers ===\n");
    
    char buffer[400] = {0};
    int result = 0;
    
    // Комбинация пользовательских спецификаторов
    result = oversprintf(buffer, "Combined: %Ro | %Zr | %Cv | %CV", 
                        2023, 20, 255, 16, 255, 16);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Комбинация с преобразованием 
    result = oversprintf(buffer, "Conversion: %to (hex) = %d (dec) | %TO (HEX) = %d", 
                        "ff", 16, 255, "FF", 16, 255);
    printf("res: %i, buffer: %s\n", result, buffer); // ABOB
    
    // Комбинация с дампом памяти
    int test_val = 305419896; // 0x12345678
    result = oversprintf(buffer, "Memory: %mi (signed) = %mu (unsigned)", test_val, test_val);
    printf("res: %i, buffer: %s\n", result, buffer); // ABOB
    
    // Смесь пользовательских и стандартных
    result = oversprintf(buffer, "Mixed: Roman %Ro, Hex 0x%x, Zeck %Zr, String '%s'", 
                        49, 255, 15, "test");
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Комплексная строка с форматированием
    result = oversprintf(buffer, "Complex: %10.2f | %-10s | %05d | %Ro", 
                        3.14159, "test", 42, 1999);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    printf("\n");
}

void test_edge_cases() {
    printf("=== Test 7: Edge cases and errors ===\n");
    
    char buffer[200] = {0};
    int result = 0;
    
    // Нулевые значения
    result = oversprintf(buffer, "Zero Roman: %Ro", 0);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    result = oversprintf(buffer, "Zero Zeck: %Zr", 0);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Очень большие числа
    result = oversprintf(buffer, "Large Roman: %Ro", 5000);
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Отрицательные для беззнаковых
    result = oversprintf(buffer, "Negative uint: %mu", -1); // ABOB
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Неправильное количество аргументов
    result = oversprintf(buffer, "Missing arg: %Cv", 255); // нет основания ABOB
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Спецификаторы без процента
    result = oversprintf(buffer, "Normal text without specifiers");
    printf("res: %i, buffer: %s\n", result, buffer);
    
    // Только стандартные спецификаторы
    result = oversprintf(buffer, "Standard only: %d %f %s %c", 42, 3.14, "hello", 'X');
    printf("res: %i, buffer: %s\n", result, buffer);
    
    printf("\n");
}

void test_file_output() {
    printf("=== Test 8: File output (overfprintf) ===\n");
    
    // Тестирование вывода в файл
    FILE* file = fopen("test_output.txt", "w");
    if (file) {
        int result = 0;
        
        result = overfprintf(file, "=== Testing overfprintf ===\n");
        result = overfprintf(file, "Roman: %Ro\n", 49);
        result = overfprintf(file, "Zeckendorf: %Zr\n", 20);
        result = overfprintf(file, "Hex: %Cv\n", 255, 16);
        result = overfprintf(file, "Memory dump: %mi\n", 305419896);
        result = overfprintf(file, "Mixed: %Ro in hex is 0x%x\n", 255, 255);
        
        fclose(file);
        printf("File output written to test_output.txt\n");
    } else {
        printf("Failed to open file for writing\n");
    }
    
    printf("Stdout test: ");
    overfprintf(stdout, "Stdout: %Ro | %Zr | %Cv\n", 99, 10, 42, 2);
    
    printf("\n");
}

void test_performance() {
    printf("=== Test 9: Performance and stress ===\n");
    
    char buffer[200] = {0};
    int iterations = 1000;
    
    printf("Running %d iterations...\n", iterations);
    
    for (int i = 0; i < iterations; i++) {
        oversprintf(buffer, "Iteration %d: %Ro %Zr %Cv", 
                    i, i % 1000, i % 50, i, 16);
    }
    
    printf("Performance test completed\n");
    printf("Last result: %s\n", buffer);
    
    printf("\n");
}

