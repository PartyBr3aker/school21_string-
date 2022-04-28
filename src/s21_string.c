#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len + 1;
} 

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char* destanation_char_ptr = (char*)dest;
    char* source_char_ptr = (char*)src;

    for (s21_size_t i = 0; i < n; ++i) {
        destanation_char_ptr[i] = source_char_ptr[i];
    }

    return dest;
}

int s21_strcmp(const char *str1, const char *str2) {
    s21_size_t c1 = 0;
    s21_size_t c2 = 0;

    do {
        c1 = *str1++;
        c2 = *str2++;
    } while (c1 == c2 && c1 && c2);

    return c1 - c2;
}

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t haystack_lenght = s21_strlen(haystack);
    s21_size_t needle_lenght = s21_strlen(needle);
    const char* result = S21_NULL;
    
    if (haystack_lenght < needle_lenght) {
        result = S21_NULL;
    } else if (haystack_lenght == needle_lenght && !s21_strcmp(haystack, needle)) {
        result = haystack;
    } else {
        for (s21_size_t i = 0; i < haystack_lenght - needle_lenght; ++i) {
            for (s21_size_t j = 0; j < needle_lenght && !result; ++j) {
                if (haystack[i + j] != needle[j]) {
                    result = S21_NULL;
                    break;
                } else if (j == needle - 1) {
                    result = haystack + i;
            }
        }
    }

    return result;

}