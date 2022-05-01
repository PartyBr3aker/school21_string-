#include <stdio.h>
#include "s21_string.h"

int main() {
    char a[10] = "1aBcDEFg";
    char *b = to_lower(a);
    printf("%s", b);
}