#include <stdio.h>
#include "zhegalkin.h"

void run_tests() {
    int success;
    int result[8];

    printf("\nТест 1: конъюнкция\n");
    int input_and[] = {0, 0, 0, 1};
    success = build_zhegalkin(input_and, 4, result);
    if (success && result[0]==0 && result[3]==1) {
        printf("Верно\n");
        print_poly(result, 4);
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 2: xor\n");
    int input_xor[] = {0, 1, 1, 0};
    success = build_zhegalkin(input_xor, 4, result);
    if (success && result[1]==1 && result[2]==1 && result[3]==0) {
        printf("Верно\n");
        print_poly(result, 4);
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 3: константа 1\n");
    int input_one[] = {1, 1};
    success = build_zhegalkin(input_one, 2, result);
    if (success && result[0]==1 && result[1]==0) {
        printf("Верно\n");
        print_poly(result, 2);
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 4: некорректная длина\n");
    success = build_zhegalkin(input_and, 3, result);
    if (!success) {
        printf("Верно\n");
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 5: константа 0\n");
    success = build_zhegalkin(input_and, 0, result);
    if (!success) {
        printf("Верно\n");
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 6: нулевой указатель на вектор\n");
    success = build_zhegalkin(NULL, 4, result);
    if (!success) {
        printf("Верно\n");
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 7: нулевой указатель на результат\n");
    success = build_zhegalkin(input_and, 4, NULL);
    if (!success) {
        printf("Верно\n");
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 8: Мажоритарная функция\n");
    int input_majority[] = {0, 0, 0, 1, 0, 1, 1, 1};
    success = build_zhegalkin(input_majority, 8, result);
    if (success) {
        printf("Верно\n");
        print_poly(result, 8);
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 9: константа 1 для 4 переменных\n");
    int input_all_ones[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int result_large[16];
    success = build_zhegalkin(input_all_ones, 16, result_large);
    if (success) {
        printf("Верно\n");
        print_poly(result_large, 16);
    } else {
        printf("Неверно\n");
    }

    printf("\nТест 10: сложная функция 4 переменных\n");
    int input_complex[] = {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};
    success = build_zhegalkin(input_complex, 16, result_large);
    if (success) {
        printf("Верно\n");
        print_poly(result_large, 16);
    } else {
        printf("Неверно\n");
    }
}

int main() {
    run_tests();
    return 0;
}