#include "s21_string.h"
#include <stdlib.h>

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    s21_size_t length = s21_strlen(str) + s21_strlen(src);
    char *out = (char *) malloc(length + 1);
    if (out != S21_NULL) {
        for (s21_size_t i = 0; i < start_index - 1; i++) {
            out[i] = src[i];
        }
        for (s21_size_t i = start_index - 1; i < length; i++) {
            out[i] = str[i - start_index + 1];
        }
        out[length] = '\0';
    }
    return out;
}
