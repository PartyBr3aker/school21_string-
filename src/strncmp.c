#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t numbr_of_symb) {
    int return_value;
    while (*str1 && numbr_of_symb && *str1 == *str2) {
        str1++;
        str2++;
        --numbr_of_symb;
    }
    if (numbr_of_symb == 0) {
        return_value = 0;
    } else {
        return_value = *str1 - *str2;
    }
    return return_value;
}
