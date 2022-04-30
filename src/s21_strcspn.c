#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    // делаем ли проверку на нулевые строки подаваемые в функцию?
    // if((str1 == NULL) || (str2 == NULL))
    //     return len;
    while (*str1) {
        //  проверяем, входит ли символ str1 в перечень символов str2
        if (s21_strchr(str2, *str1)) {break;
        } else {
            str1++;
            len++;
        }
    }
    return len;
}

