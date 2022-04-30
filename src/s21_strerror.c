#include "s21_string.h"
#include <stdio.h>

int GetNumberLenght(int number) {
    int result = 0;

    number = number >= 0 ? number : -number;
    while (number > 0) {
        result++;
        number /= 10;
    }
    return result;
}

void ErrorToString(int errnum) {
    const static int start_index = 15;
    int errnum_length = GetNumberLenght(errnum);
    int i = start_index + errnum_length - 1;
    int negative_flag = errnum < 0;

    if (negative_flag) {
        unknown_error[start_index] = '-';
        i++;
        errnum = -errnum;
    }

    for (; i > (negative_flag ? start_index : start_index - 1); --i) {
        unknown_error[i] = '0' + errnum % 10;
        errnum /= 10;
    }
    unknown_error[start_index + errnum_length + negative_flag + 1] = 0;
    return;
}

char *s21_strerror(int errnum) {
    char* result;
    if (errnum >= 0 && errnum <= 106) {
        result = _errors[errnum];
    } else {
        ErrorToString(errnum);
        result = unknown_error;
    }
    return result;
}

int main() {
    for (int i = -12; i < 200; ++i )
    printf("%s\n", s21_strerror(i));
    return 0;
}