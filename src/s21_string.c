#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len + 1;
} 

// 2. Compares the first n bytes of str1 and str2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int compare = 0;
    // Посимвольное сравнение с досрочным выходом, если есть отличие
    for (int i = 0; i < n && compare == 0; i++) {
        compare = *((char*)str1 + i) - *((char*)str2 + i);
    }
    return compare;
}

// 7. Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *out = dest;
    // Перестановка указателя в конец строки dest
    dest = dest + s21_strlen(dest) - 1;
    // Доп. условие выхода при досрочном окончании строки src
    while (n > 0 && *src != 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    // Завершение строки спец символом
    *dest = '\0';
    return out;
}

// 12. Copies up to n characters from the string pointed to, by src to dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    char *out = dest;
    while (n > 0 && *src != 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    return out;
}