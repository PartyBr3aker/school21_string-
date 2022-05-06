#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

int main() {
    int a = 0;
    char* str = (char*)malloc(sizeof(char) * 150);
    s21_sprintf(str, "1212 %d %d", 21, 23);
    printf("%s", str);
    return 0;
}