# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c99

# Пути к файлам
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# Исходные файлы
SRC = $(SRC_DIR)/zhegalkin.c
TEST_SRC = $(TEST_DIR)/test_zhegalkin.c

# Объектные файлы
OBJ = $(BUILD_DIR)/zhegalkin.o
TEST_OBJ = $(BUILD_DIR)/test_zhegalkin.o

# Исполняемые файлы
TEST_EXEC = $(BUILD_DIR)/test_zhegalkin

# Основная цель
all: test

# Создаем директорию build, если её нет
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Компиляция основной библиотеки
$(OBJ): $(SRC) $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция тестов
$(TEST_OBJ): $(TEST_SRC) $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Сборка тестового исполняемого файла
$(TEST_EXEC): $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Запуск тестов
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Очистка
clean:
	rm -rf $(BUILD_DIR)

# Файлы для сборки
.PHONY: all test clean
