#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char* destanation_char_ptr = (char*)dest;
    char* source_char_ptr = (char*)src;

    for (s21_size_t i = 0; i < n; ++i) {
        destanation_char_ptr[i] = source_char_ptr[i];
    }

    return dest;
}
