#include <stdlib.h>
#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
    s21_size_t length_src = s21_strlen(src);
    char reverse[length_src + 1];
    // Переворот строки
    for(s21_size_t i = 0; i < length_src; i++) {
        reverse[i] = src[length_src - 1 - i];
    }
    reverse[length_src] = '\0';
    // Длина начального сегмента, состоящего из заданных символов
    s21_size_t begin_segment = s21_strspn(src, trim_chars);
    // Длина конечного сегмента, состоящего из заданных символов
    s21_size_t end_segment = s21_strspn(reverse, trim_chars);
    s21_size_t length_out = 1;
    if (begin_segment != length_src) {
        length_out = length_src + 1 - begin_segment - end_segment;
    }
    // Итоговая строка
    char *out = (char *) malloc(length_out);
    if (out != S21_NULL) {
        for (s21_size_t i = 0; i < (length_out) ; i++) {
            out[i] = src[begin_segment + i];
        }
        out[length_out - 1] = '\0';
    }
    return out;
}
