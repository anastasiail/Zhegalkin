#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zhegalkin.h"

// Проверка, что длина вектора - степень двойки
int is_correct_len(int n) {
    if (n <= 0) return 0;
    while (n > 1) {
        if (n % 2 != 0) return 0;
        n /= 2;
    }
    return 1;
}

int build_zhegalkin(const int* vector, int len, int* result) {
    if (vector == NULL || result == NULL) {
        printf("Ошибка: нулевой указатель\n");
        return 0;
    }
    
    if (len <= 0) {
        printf("Ошибка: длина < 1\n");
        return 0;
    }
    
    if (!is_correct_len(len)) {
        printf("Ошибка: длина (%d) должна быть степенью 2\n", len);
        return 0;
    }

    // Создаем копию данных, так как метод треугольника разрушает исходный массив
    int* temp = (int*)malloc(len * sizeof(int));
    memcpy(temp, vector, len * sizeof(int));

    for (int i = 0; i < len; i++) {
        result[i] = temp[0]; // Первый элемент треугольника - коэффициент
        
        for (int j = 0; j < len - 1 - i; j++) { // xor для следующего этапа
            temp[j] = temp[j] ^ temp[j + 1];
        }
    }

    free(temp);
    return 1;
}

void print_poly(const int* coeffs, int len) {
    int printed_any = 0;
    
    // Определяем количество переменных (log2 от len)
    int num_vars = 0;
    int temp_len = len;
    while (temp_len > 1) {
        temp_len >>= 1;
        num_vars++;
    }

    printf("Полином Жегалкина: ");
    for (int i = 0; i < len; i++) {
        if (coeffs[i] == 1) {
            if (printed_any) { // Флаг, нужно ли ставить +
                printf(" + ");
            }
            
            if (i == 0) {
                printf("1"); // Константа
            } else {
                int printed_var = 0;
                for (int bit = 0; bit < num_vars; bit++) {
                    int mask = 1 << (num_vars - 1 - bit); // Проверяем, входит ли переменная в конъюнкцию
                    if (i & mask) {
                        if (printed_var) printf("*");
                        printf("x%d", bit + 1);
                        printed_var = 1;
                    }
                }
            }
            printed_any = 1;
        }
    }
    
    if (!printed_any) {
        printf("0"); // Константа
    }
    printf("\n");
}