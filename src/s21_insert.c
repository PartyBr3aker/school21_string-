#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    s21_size_t length = s21_strlen(str) + s21_strlen(src);
    char *out = (char *)malloc(length + 1);
    if (out != S21_NULL) {
        for (s21_size_t i = 0; i < length; i++) {
            // Вставка строки str
            if (i >= start_index - 1 && *str) {
                out[i] = *str;
                str++;
                // Вставка основной строки src
            } else {
                out[i] = *src;
                src++;
            }
        }
        out[length] = '\0';
    }
    return out;
}
