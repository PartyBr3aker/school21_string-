#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *result = S21_NULL;
    char *string = (char *)(str);
    for (s21_size_t i = 0; i < n && !result; ++i) {
        if (string[i] == c) result = (void *)&string[i];
    }
    return result;
}
