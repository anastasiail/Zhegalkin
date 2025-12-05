#ifndef ZHEGALKIN_H
#define ZHEGALKIN_H

// Проверка, что длина вектора - степень двойки
int is_correct_len(int n);

// Основная функция построения коэффициентов полинома Жегалкина
int build_zhegalkin(const int* vector, int len, int* result);

// Функция для вывода полинома в читаемом виде
void print_poly(const int* coeffs, int len);

// Функция запуска тестов
void run_tests(void);

#endif // ZHEGALKIN_H