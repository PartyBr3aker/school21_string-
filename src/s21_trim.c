#include "s21_string.h"
#include <stdlib.h>

void *s21_trim(const char *src, const char *trim_chars) {
    s21_size_t length = s21_strlen(src);
    char *out = (char *) malloc(length + 1);
    if (out != S21_NULL) {
        // Длина начального сегмента, состоящего из заданных символов
        s21_size_t begin_segment = s21_strspn(src, trim_chars);
        // Переворот строки
        for(s21_size_t i = 0; i < length; i++) {
            out[i] = src[length - 1 - i];
        }
        // Длина конечного сегмента, состоящего из заданных символов
        s21_size_t end_segment = s21_strspn(out, trim_chars);
        // Запись обрезанной строки
        for (s21_size_t i = 0; i < (length + 1 - begin_segment - end_segment); i++) {
            out[i] = src[begin_segment + i];
            if (i == (length - begin_segment - end_segment)) {
                out[i] = '\0';
            }
        }
    }
    return out;
}
