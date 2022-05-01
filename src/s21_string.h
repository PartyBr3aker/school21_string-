#include <stdio.h>
#include <string.h>
typedef long unsigned s21_size_t;
#define S21_NULL 0

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
