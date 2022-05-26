#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int main() {
    char str1[500];
    char str2[500];
    char format[] = "%1.1f";
    double val = 10.5;

    int num1 = s21_sprintf(str1, format, val);
    int num2 = sprintf(str2, format, val);

    //s21_sprintf(str1, format, val, val1, val2, val3, val4, val5);
    printf("!%s!%d\n", str1, num1);

    //sprintf(str2, format, val, val1, val2, val3, val4, val5);
    printf("!%s!%d\n", str2, num2);

    return 0;
}
