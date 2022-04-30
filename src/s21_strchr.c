#include "s21_string.h"
char *s21_strchr(const char *str, int c) {
    // инициализировать как s21null или можно просто нулем?
    const char *res = s21_NULL;
    for (s21_size_t len = 0; len < s21_strlen(str); len++) {
        if (str[len] == c) {res = &str[len];
        break;
        }
    }
    return (char*)res;
}

