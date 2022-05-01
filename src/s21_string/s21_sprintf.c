#include "s21_string.h"

//  c, d, i, f, s, u, %

// c - 

// 1
// c
// Символ
// Символ
// int CSpecificator(char* dest, char** end_of_string, char c, int width, int long_flag);
// Если width == -1, то значит спецификатора не было

// 2
// d
// Знаковое десятичное целое число
// Знаковое десятичное целое число
// int DSpecificator(char* dest, char** end_of_string, long long int number, int space_flag, int plus_flag, int minus_flag, int width, int precision);
// int UDSpecificator(char* dest, char** end_of_string, unsigned long long int number, int space_flag, int plus_flag, int minus_flag, int width, int precision);
// 6
// u
// Беззнаковое десятичное целое число
// Беззнаковое десятичное целое число
// К этому функции писать не надо, так как они в п.2

// 3
// i
// Знаковое десятичное целое число
// Знаковое целое число (может быть десятичным, восьмеричным или шестнадцатеричным)
// К этому функции писать не надо, так как они в п.2

// 4
// f
// Десятичное число с плавающей точкой
// Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)
// int FlSpecificator(char* dest, char** end_of_string, float number, int space_flag, int plus_flag, int minus_flag, int width, int precision);
// int LfSpecificator(char* dest, char** end_of_string, double number, int space_flag, int plus_flag, int minus_flag, int width, int precision); просто дабловский
// 5
// s
// Строка символов
// Строка символов
// int SSpecificator(char* dest, char** end_of_string, char* string, int minus_flag, int width, int long_flag);

// 7
// %
// Символ %
// Символ %


int sprintf(char *str, const char *format, ...) {
}
