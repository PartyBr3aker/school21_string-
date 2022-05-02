// Copyright 2022 shenatam
#include <check.h>
#include <string.h>

#include "../s21_string/s21_string.h"
// 1 функция. 1й тест
START_TEST(s21_memchr_test_1) {
    ck_assert_pstr_eq(s21_memchr("qwerty", 'e', 5), memchr("qwerty", 'e', 5));
}
END_TEST

// 1 функция. 2й тест
START_TEST(s21_memchr_test_2) {
    ck_assert_pstr_eq(s21_memchr("Hello world\n\0", ' ', 6),
                      memchr("Hello world\n\0", ' ', 6));
}
END_TEST

// 1 функция. 3й тест
START_TEST(s21_memchr_test_3) {
    ck_assert_pstr_eq(s21_memchr("a\n\0", 'g', 6), memchr("a\n\0", 'g', 6));
}
END_TEST

// 1 функция. 4й тест
START_TEST(s21_memchr_test_4) {
    ck_assert_pstr_eq(s21_memchr(" \n\0", ' ', 6), memchr(" \n\0", ' ', 6));
}
END_TEST

// 1 функция. 5й тест
START_TEST(s21_memchr_test_5) {
    ck_assert_pstr_eq(s21_memchr("\n\0", '\n', 6), memchr("\n\0", '\n', 6));
}
END_TEST

// 2 функция. 1й тест
START_TEST(s21_memcmp_test_1) {
    ck_assert_int_eq(s21_memcmp("Hello world\n\0", "Hello ", 6), memcmp("Hello world\n\0", "Hello ", 6));
}
END_TEST

// 2 функция. 2й тест
START_TEST(s21_memcmp_test_2) {
    ck_assert_int_eq(s21_memcmp("", "Hello ", 10), memcmp("", "Hello ", 10));
}
END_TEST

// 2 функция. 3й тест
START_TEST(s21_memcmp_test_3) {
    ck_assert_int_eq(s21_memcmp("Hello world\n\0", "Hello world\n\0", 13), memcmp("Hello world\n\0", "Hello world\n\0", 13));
}
END_TEST

// 2 функция. 4й тест
START_TEST(s21_memcmp_test_4) {
    ck_assert_int_eq(s21_memcmp("a\n\0", "a", 1), memcmp("a\n\0", "a", 1));
}
END_TEST

// 2 функция. 5й тест
START_TEST(s21_memcmp_test_5) {
    ck_assert_int_eq(s21_memcmp("", "", 1), memcmp("", "", 1));
}
END_TEST

// 3 функция. 1й тест
START_TEST(s21_memcpy_test_1) {
    char str[30] = "Hello world\n\0";
    char str1[30] = "Hello world\n\0";
    ck_assert_pstr_eq(s21_memcpy(str, "a\n\0", 2), memcpy(str1, "a\n\0", 2));
}
END_TEST

// 3 функция. 2й тест
START_TEST(s21_memcpy_test_2) {
    char str[30] = "Hello world\n\0";
    char str1[30] = "Hello world\n\0";
    ck_assert_pstr_eq(s21_memcpy(str, "Hello world\0", 6), memcpy(str1, "Hello world\0", 6));
}
END_TEST

// 3 функция. 3й тест
START_TEST(s21_memcpy_test_3) {
    char str[30] = "";
    char str1[30] = "";
    ck_assert_pstr_eq(s21_memcpy(str, "\n\0", 2), memcpy(str1, "\n\0", 2));
}
END_TEST

// 3 функция. 4й тест
START_TEST(s21_memcpy_test_4) {
    char str[30] = " \n\0";
    char str1[30] = " \n\0";
    ck_assert_pstr_eq(s21_memcpy(str, "\0", 1), memcpy(str1, "\0", 1));
}
END_TEST

// 3 функция. 5й тест
START_TEST(s21_memcpy_test_5) {
    char str[30] = " \n\0";
    char str1[30] = " \n\0";
    ck_assert_pstr_eq(s21_memcpy(str, " \n\0", 1), memcpy(str1, " \n\0", 1));
}
END_TEST

// 4 функция. 1й тест
START_TEST(s21_memmove_test_1) {
    char str[30] = "Hello world\n\0";
    char str1[30] = "Hello world\n\0";
    ck_assert_pstr_eq(s21_memmove(str, "a\n\0", 2), memmove(str1, "a\n\0", 2));
}
END_TEST

// 4 функция. 2й тест
START_TEST(s21_memmove_test_2) {
    char str[30] = "Hello world\n\0";
    char str1[30] = "Hello world\n\0";
    ck_assert_pstr_eq(s21_memmove(str, "Hello world\0", 6), memmove(str1, "Hello world\0", 6));
}
END_TEST

// 4 функция. 3й тест
START_TEST(s21_memmove_test_3) {
    char str[30] = "";
    char str1[30] = "";
    ck_assert_pstr_eq(s21_memmove(str, "\n\0", 2), memmove(str1, "\n\0", 2));
}
END_TEST

// 4 функция. 4й тест
START_TEST(s21_memmove_test_4) {
    char str[30] = "\n\0dfghjkl;";
    char str1[30] = "\n\0dfghjkl;";
    ck_assert_pstr_eq(s21_memmove(str, "\0", 0), memmove(str1, "\0", 0));
}
END_TEST

// 4 функция. 5й тест
START_TEST(s21_memmove_test_5) {
    char str[30] = " \n\0";
    char str1[30] = " \n\0";
    ck_assert_pstr_eq(s21_memmove(str, " \n\0", 1), memmove(str1, " \n\0", 1));
}
END_TEST

// // 5 функция. 1й тест
// START_TEST(s21_memset_test_1) {
//     ck_assert_pstr_eq(s21_memset("qwerty", 'e', 5), memset("qwerty", 'e', 5));
// }
// END_TEST

// // 5 функция. 2й тест
// START_TEST(s21_memset_test_2) {
//     ck_assert_pstr_eq(s21_memset("qwerty", 'e', 0), memset("qwerty", 'e', 0));
// }
// END_TEST

// // 5 функция. 3й тест
// START_TEST(s21_memset_test_3) {
//     ck_assert_pstr_eq(s21_memset("Hello world\n\0", '\n', 7), memset("Hello world\n\0", '\n', 7));
// }
// END_TEST

// // 5 функция. 4й тест
// START_TEST(s21_memset_test_4) {
//     ck_assert_pstr_eq(s21_memset("a\n\0", ' ', 5), memset("a\n\0", ' ', 2));
// }
// END_TEST

// // 5 функция. 5й тест
// START_TEST(s21_memset_test_5) {
//     ck_assert_pstr_eq(s21_memset("\0", 'e', 1), memset("\0", 'e', 1));
// }
// END_TEST

// 6 функция. 1й тест
START_TEST(s21_strcat_test_1) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcat(str, "hello"), strcat(str1, "hello"));
}
END_TEST

// 6 функция. 2й тест
START_TEST(s21_strcat_test_2) {
    char str[50] = "wsddqd";
    char str1[50] = "wsddqd";
    ck_assert_pstr_eq(s21_strcat(str, "Hello world\0"),
                      strcat(str1, "Hello world\0"));
}
END_TEST

// 6 функция. 3й тест
START_TEST(s21_strcat_test_3) {
    char str[50] = "\0";
    char str1[50] = "\0";
    ck_assert_pstr_eq(s21_strcat(str, "a\n\0"), strcat(str1, "a\n\0"));
}
END_TEST

// 6 функция. 4й тест
START_TEST(s21_strcat_test_4) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcat(str, "Hello world\n\0"),
                      strcat(str1, "Hello world\n\0"));
}
END_TEST

// 6 функция. 5й тест
START_TEST(s21_strcat_test_5) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcat(str, "    "), strcat(str1, "    "));
}
END_TEST

// 7 функция. 1й тест
START_TEST(s21_strncat_test_1) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strncat(str, "    ", 3), strncat(str1, "    ", 3));
}
END_TEST

// 7 функция. 2й тест
START_TEST(s21_strncat_test_2) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strncat(str, "Hello world\n\0", 12), strncat(str1, "Hello world\n\0", 12));
}
END_TEST

// 7 функция. 3й тест
START_TEST(s21_strncat_test_3) {
    char str[50] = "\0";
    char str1[50] = "\0";
    ck_assert_pstr_eq(s21_strncat(str, "a\n\0", 2), strncat(str1, "a\n\0", 2));
}
END_TEST

// 7 функция. 4й тест
START_TEST(s21_strncat_test_4) {
    char str[50] = "wsddqd";
    char str1[50] = "wsddqd";
    ck_assert_pstr_eq(s21_strncat(str, "\n\n\0", 2), strncat(str1, "\n\n\0", 2));
}
END_TEST

// 7 функция. 5й тест
START_TEST(s21_strncat_test_5) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strncat(str, "\0", 1), strncat(str1, "\0", 1));
}
END_TEST

// 8 функция. 1й тест
START_TEST(s21_strchr_test_1) {
    ck_assert_pstr_eq(s21_strchr("Hello world\n", ' '), strchr("Hello world\n", ' '));
}
END_TEST

// 8 функция. 2й тест
START_TEST(s21_strchr_test_2) {
    ck_assert_pstr_eq(s21_strchr("a\n\0", '\n'), strchr("a\n\0", '\n'));
}
END_TEST

// 8 функция. 3й тест
START_TEST(s21_strchr_test_3) {
    ck_assert_pstr_eq(s21_strchr(" \n\0", '1'), strchr(" \n\0", '1'));
}
END_TEST

// 8 функция. 4й тест
START_TEST(s21_strchr_test_4) {
    ck_assert_pstr_eq(s21_strchr("Hello world\n", '\n'), strchr("Hello world\n", '\n'));
}
END_TEST

// 8 функция. 5й тест
START_TEST(s21_strchr_test_5) {
    ck_assert_pstr_eq(s21_strchr("\0", '\0'), strchr("\0", '\0'));
}
END_TEST

// 9 функция. 1й тест
START_TEST(s21_strcmp_test_1) {
    ck_assert_int_eq(s21_strcmp("Hello world\n\0", "Hello world\n\0"), strcmp("Hello world\n\0", "Hello world\n\0"));
}
END_TEST

// 9 функция. 2й тест
START_TEST(s21_strcmp_test_2) {
    ck_assert_int_eq(s21_strcmp("a\n\0", "a\n\0"), strcmp("a\n\0", "a\n\0"));
}
END_TEST

// 9 функция. 3й тест
START_TEST(s21_strcmp_test_3) {
    ck_assert_int_eq(s21_strcmp(" \n\0", " \n\0"), strcmp(" \n\0", " \n\0"));
}
END_TEST

// 9 функция. 4й тест
START_TEST(s21_strcmp_test_4) {
    ck_assert_int_eq(s21_strcmp("\n\0", "\n\0"), strcmp("\n\0", "\n\0"));
}
END_TEST

// 9 функция. 5й тест
START_TEST(s21_strcmp_test_5) {
    ck_assert_int_eq(s21_strcmp("\0", "\0"), strcmp("\0", "\0"));
}
END_TEST

// 10 функция. 1й тест
START_TEST(s21_strncmp_test_1) {
    ck_assert_int_eq(s21_strncmp("Hello world\n\0", "Hello world\n\0", 12), strncmp("Hello world\n\0", "Hello world\n\0", 12));
}
END_TEST

// 10 функция. 2й тест
START_TEST(s21_strncmp_test_2) {
    ck_assert_int_eq(s21_strncmp("a\n\0", "a\n\0", 2), strncmp("a\n\0", "a\n\0", 2));
}
END_TEST

// 10 функция. 3й тест
START_TEST(s21_strncmp_test_3) {
    ck_assert_int_eq(s21_strncmp(" \n\0", " \n\0", 2), strncmp(" \n\0", " \n\0", 2));
}
END_TEST

// 10 функция. 4й тест
START_TEST(s21_strncmp_test_4) {
    ck_assert_int_eq(s21_strncmp("\n\0", "\n\0", 1), strncmp("\n\0", "\n\0", 1));
}
END_TEST

// 10 функция. 5й тест
START_TEST(s21_strncmp_test_5) {
    ck_assert_int_eq(s21_strncmp("\0", "\0", 0), strncmp("\0", "\0", 0));
}
END_TEST

// 11 функция. 1й тест
START_TEST(s21_strcpy_test_1) {
    char str[50] = "Hello";
    char str1[50] = "Hello";
    ck_assert_pstr_eq(s21_strcpy(str, "    "), strcpy(str1, "    "));
}
END_TEST

// 11 функция. 2й тест
START_TEST(s21_strcpy_test_2) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcpy(str, "Hello world\n\0"),
                      strcpy(str1, "Hello world\n\0"));
}
END_TEST

// 11 функция. 3й тест
START_TEST(s21_strcpy_test_3) {
    char str[50] = "a\n\0";
    char str1[50] = "a\n\0";
    ck_assert_pstr_eq(s21_strcpy(str, " \n\0"), strcpy(str1, " \n\0"));
}
END_TEST

// 11 функция. 4й тест
START_TEST(s21_strcpy_test_4) {
    char str[50] = "Hel   lo";
    char str1[50] = "Hel   lo";
    ck_assert_pstr_eq(s21_strcpy(str, "a\n\0"), strcpy(str1, "a\n\0"));
}
END_TEST

// 11 функция. 5й тест
START_TEST(s21_strcpy_test_5) {
    char str[50] = "Hello world\n\0";
    char str1[50] = "Hello world\n\0";
    ck_assert_pstr_eq(s21_strcpy(str, "\n\0"), strcpy(str1, "\n\0"));
}
END_TEST

// 12 функция. 1й тест
START_TEST(s21_strncpy_test_1) {
    char str[50] = "Hello";
    char str1[50] = "Hello";
    ck_assert_pstr_eq(s21_strncpy(str, "    ", 10), strncpy(str1, "    ", 10));
}
END_TEST

// 12 функция. 2й тест
START_TEST(s21_strncpy_test_2) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strncpy(str, "Hello world\n\0", 15),
                      strncpy(str1, "Hello world\n\0", 15));
}
END_TEST

// 12 функция. 3й тест
START_TEST(s21_strncpy_test_3) {
    char str[50] = "a\n\0";
    char str1[50] = "a\n\0";
    ck_assert_pstr_eq(s21_strncpy(str, " \n\0", 5), strncpy(str1, " \n\0", 5));
}
END_TEST

// 12 функция. 4й тест
START_TEST(s21_strncpy_test_4) {
    char str[50] = "Hel   lo";
    char str1[50] = "Hel   lo";
    ck_assert_pstr_eq(s21_strncpy(str, "a\n\0", 10), strncpy(str1, "a\n\0", 10));
}
END_TEST

// 12 функция. 5й тест
START_TEST(s21_strncpy_test_5) {
    char str[50] = "Hello world\n\0";
    char str1[50] = "Hello world\n\0";
    ck_assert_pstr_eq(s21_strncpy(str, "\n\0", 15), strncpy(str1, "\n\0", 15));
}
END_TEST

// 13 функция. 1й тест
START_TEST(s21_strcspn_test_1) {
    ck_assert_int_eq(s21_strcspn("Hello world\n\0", "world\n\0"), strcspn("Hello world\n\0", "world\n\0"));
}
END_TEST

// 13 функция. 2й тест
START_TEST(s21_strcspn_test_2) {
    ck_assert_int_eq(s21_strcspn("", "\0"), strcspn("", "\0"));
}
END_TEST

// 13 функция. 3й тест
START_TEST(s21_strcspn_test_3) {
    ck_assert_int_eq(s21_strcspn("a\n\0", "a\n\0"), strcspn("a\n\0", "a\n\0"));
}
END_TEST

// 13 функция. 4й тест
START_TEST(s21_strcspn_test_4) {
    ck_assert_int_eq(s21_strcspn("\n\0", "\0"), strcspn("\n\0", "\0"));
}
END_TEST

// 13 функция. 5й тест
START_TEST(s21_strcspn_test_5) {
    ck_assert_int_eq(s21_strcspn("\0", ""), strcspn("\0", ""));
}
END_TEST

// 14 функция. 1й тест
START_TEST(s21_strerror_test_1) {
    ck_assert_pstr_eq(s21_strerror(5), strerror(5));
}
END_TEST

// 14 функция. 2й тест
START_TEST(s21_strerror_test_2) {
    ck_assert_pstr_eq(s21_strerror(-56), strerror(-56));
}
END_TEST

// 14 функция. 3й тест
START_TEST(s21_strerror_test_3) {
    ck_assert_pstr_eq(s21_strerror(123), strerror(123));
}
END_TEST

// 14 функция. 4й тест
START_TEST(s21_strerror_test_4) {
    ck_assert_pstr_eq(s21_strerror(500), strerror(500));
}
END_TEST

// 14 функция. 5й тест
START_TEST(s21_strerror_test_5) {
    ck_assert_pstr_eq(s21_strerror(88), strerror(88));
}
END_TEST

// 15 функция. 1й тест
START_TEST(s21_strlen_test_1) {
    ck_assert_int_eq(s21_strlen("Hello world\n\0"), strlen("Hello world\n\0"));
}
END_TEST

// 15 функция. 2й тест
START_TEST(s21_strlen_test_2) {
    ck_assert_int_eq(s21_strlen("\n\0"), strlen("\n\0"));
}
END_TEST

// 15 функция. 3й тест
START_TEST(s21_strlen_test_3) {
    ck_assert_int_eq(s21_strlen(" \0"), strlen(" \0"));
}
END_TEST

// 15 функция. 4й тест
START_TEST(s21_strlen_test_4) {
    ck_assert_int_eq(s21_strlen(" \n\0"), strlen(" \n\0"));
}
END_TEST

// 15 функция. 5й тест
START_TEST(s21_strlen_test_5) {
    ck_assert_int_eq(s21_strlen("a\n\0"), strlen("a\n\0"));
}
END_TEST

// 16 функция. 1й тест
START_TEST(s21_strpbrk_test_1) {
    ck_assert_pstr_eq(s21_strpbrk("qwe", "yfgbgbdw"),
                      strpbrk("qwe", "yfgbgbdw"));
}
END_TEST

// 16 функция. 2й тест
START_TEST(s21_strpbrk_test_2) {
    ck_assert_pstr_eq(s21_strpbrk("Hello world\n\0", ""), strpbrk("Hello world\n\0", ""));
}
END_TEST

// 16 функция. 3й тест
START_TEST(s21_strpbrk_test_3) {
    ck_assert_pstr_eq(s21_strpbrk("\n\0", "yfgbg\nbdw"),
                      strpbrk("\n\0", "yfgbg\nbdw"));
}
END_TEST

// 16 функция. 4й тест
START_TEST(s21_strpbrk_test_4) {
    ck_assert_pstr_eq(s21_strpbrk("Hello world\0", "dlrow olleH"),
                      strpbrk("Hello world\0", "dlrow olleH"));
}
END_TEST

// 16 функция. 5й тест
START_TEST(s21_strpbrk_test_5) {
    ck_assert_pstr_eq(s21_strpbrk(" q q q", "fjfeoijoiwef "),
                      strpbrk(" q q q", "fjfeoijoiwef "));
}
END_TEST

// 17 функция. 1й тест
START_TEST(s21_strrchr_test_1) {
    ck_assert_pstr_eq(s21_strrchr("qweeeer", 'e'),
                      strrchr("qweeeer", 'e'));
}
END_TEST

// 17 функция. 2й тест
START_TEST(s21_strrchr_test_2) {
    ck_assert_pstr_eq(s21_strrchr("Hello world\n\0", 'o'), strrchr("Hello world\n\0", 'o'));
}
END_TEST

// 17 функция. 3й тест
START_TEST(s21_strrchr_test_3) {
    ck_assert_pstr_eq(s21_strrchr("\n\0", ' '),
                      strrchr("\n\0", ' '));
}
END_TEST

// 17 функция. 4й тест
START_TEST(s21_strrchr_test_4) {
    ck_assert_pstr_eq(s21_strrchr("Hello world\0", '\0'),
                      strrchr("Hello world\0", '\0'));
}
END_TEST

// 17 функция. 5й тест
START_TEST(s21_strrchr_test_5) {
    ck_assert_pstr_eq(s21_strrchr(" q q q", 'q'),
                      strrchr(" q q q", 'q'));
}
END_TEST

// 18 функция. 1й тест
START_TEST(s21_strspn_test_1) {
    ck_assert_int_eq(s21_strspn("Hello world\n\0", "Hello"), strspn("Hello world\n\0", "Hello"));
}
END_TEST

// 18 функция. 2й тест
START_TEST(s21_strspn_test_2) {
    ck_assert_int_eq(s21_strspn("", "Hello"), strspn("", "Hello"));
}
END_TEST

// 18 функция. 3й тест
START_TEST(s21_strspn_test_3) {
    ck_assert_int_eq(s21_strspn("\n\0", "\n"), strspn("\n\0", "\n"));
}
END_TEST

// 18 функция. 4й тест
START_TEST(s21_strspn_test_4) {
    ck_assert_int_eq(s21_strspn("\0", ""), strspn("\0", ""));
}
END_TEST

// 18 функция. 5й тест
START_TEST(s21_strspn_test_5) {
    ck_assert_int_eq(s21_strspn("a\n\0", "a"), strspn("a\n\0", "a"));
}
END_TEST

// 19 функция. 1й тест
START_TEST(s21_strstr_test_1) {
    ck_assert_pstr_eq(s21_strstr("a\n\0", "a"), strstr("a\n\0", "a"));
}
END_TEST

// 19 функция. 2й тест
START_TEST(s21_strstr_test_2) {
    ck_assert_pstr_eq(s21_strstr("asdqefvbqeb", "qe"), strstr("asdqefvbqeb", "qe"));
}
END_TEST

// 19 функция. 3й тест
START_TEST(s21_strstr_test_3) {
    ck_assert_pstr_eq(s21_strstr("", "a"), strstr("", "a"));
}
END_TEST

// 19 функция. 4й тест
START_TEST(s21_strstr_test_4) {
    ck_assert_pstr_eq(s21_strstr("aa\naa\n\0", "\n"), strstr("aa\naa\n\0", "\n"));
}
END_TEST

// 19 функция. 5й тест
START_TEST(s21_strstr_test_5) {
    ck_assert_pstr_eq(s21_strstr("a\n\0", ""), strstr("a\n\0", ""));
}
END_TEST

// 1 функция. Набор тестов
Suite *s21_memchr_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memchr");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_memchr_test_1);
    tcase_add_test(tc_core, s21_memchr_test_2);
    tcase_add_test(tc_core, s21_memchr_test_3);
    tcase_add_test(tc_core, s21_memchr_test_4);
    tcase_add_test(tc_core, s21_memchr_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 2 функция. Набор тестов
Suite *s21_memcmp_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memcmp");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_memcmp_test_1);
    tcase_add_test(tc_core, s21_memcmp_test_2);
    tcase_add_test(tc_core, s21_memcmp_test_3);
    tcase_add_test(tc_core, s21_memcmp_test_4);
    tcase_add_test(tc_core, s21_memcmp_test_5);
    
    suite_add_tcase(s, tc_core);

    return s;
}

// 3 функция. Набор тестов
Suite *s21_memcpy_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memcpy");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_memcpy_test_1);
    tcase_add_test(tc_core, s21_memcpy_test_2);
    tcase_add_test(tc_core, s21_memcpy_test_3);
    tcase_add_test(tc_core, s21_memcpy_test_4);
    tcase_add_test(tc_core, s21_memcpy_test_5);
    
    suite_add_tcase(s, tc_core);

    return s;
}

// 4 функция. Набор тестов
Suite *s21_memmove_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("memmove");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_memmove_test_1);
    tcase_add_test(tc_core, s21_memmove_test_2);
    tcase_add_test(tc_core, s21_memmove_test_3);
    tcase_add_test(tc_core, s21_memmove_test_4);
    tcase_add_test(tc_core, s21_memmove_test_5);
    
    suite_add_tcase(s, tc_core);

    return s;
}

// // 5 функция. Набор тестов
// Suite *s21_memset_suite(void) {
//     Suite *s;
//     TCase *tc_core;

//     s = suite_create("memset");
//     tc_core = tcase_create("Core");

//     tcase_add_test(tc_core, s21_memset_test_1);
//     tcase_add_test(tc_core, s21_memset_test_2);
//     tcase_add_test(tc_core, s21_memset_test_3);
//     tcase_add_test(tc_core, s21_memset_test_4);
//     tcase_add_test(tc_core, s21_memset_test_5);
    
//     suite_add_tcase(s, tc_core);

//     return s;
// }

// 6 функция. Набор тестов
Suite *s21_strcat_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strcat");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strcat_test_1);
    tcase_add_test(tc_core, s21_strcat_test_2);
    tcase_add_test(tc_core, s21_strcat_test_3);
    tcase_add_test(tc_core, s21_strcat_test_4);
    tcase_add_test(tc_core, s21_strcat_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 7 функция. Набор тестов
Suite *s21_strncat_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strncat");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strncat_test_1);
    tcase_add_test(tc_core, s21_strncat_test_2);
    tcase_add_test(tc_core, s21_strncat_test_3);
    tcase_add_test(tc_core, s21_strncat_test_4);
    tcase_add_test(tc_core, s21_strncat_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 8 функция. Набор тестов
Suite *s21_strchr_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strchr");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strchr_test_1);
    tcase_add_test(tc_core, s21_strchr_test_2);
    tcase_add_test(tc_core, s21_strchr_test_3);
    tcase_add_test(tc_core, s21_strchr_test_4);
    tcase_add_test(tc_core, s21_strchr_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 9 функция. Набор тестов
Suite *s21_strcmp_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strcmp");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strcmp_test_1);
    tcase_add_test(tc_core, s21_strcmp_test_2);
    tcase_add_test(tc_core, s21_strcmp_test_3);
    tcase_add_test(tc_core, s21_strcmp_test_4);
    tcase_add_test(tc_core, s21_strcmp_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 10 функция. Набор тестов
Suite *s21_strncmp_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strncmp");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strncmp_test_1);
    tcase_add_test(tc_core, s21_strncmp_test_2);
    tcase_add_test(tc_core, s21_strncmp_test_3);
    tcase_add_test(tc_core, s21_strncmp_test_4);
    tcase_add_test(tc_core, s21_strncmp_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 11 функция. Набор тестов
Suite *s21_strcpy_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strcpy");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strcpy_test_1);
    tcase_add_test(tc_core, s21_strcpy_test_2);
    tcase_add_test(tc_core, s21_strcpy_test_3);
    tcase_add_test(tc_core, s21_strcpy_test_4);
    tcase_add_test(tc_core, s21_strcpy_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 12 функция. Набор тестов
Suite *s21_strncpy_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strncpy");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strncpy_test_1);
    tcase_add_test(tc_core, s21_strncpy_test_2);
    tcase_add_test(tc_core, s21_strncpy_test_3);
    tcase_add_test(tc_core, s21_strncpy_test_4);
    tcase_add_test(tc_core, s21_strncpy_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 13 функция. Набор тестов
Suite *s21_strcspn_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strcspn");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strcspn_test_1);
    tcase_add_test(tc_core, s21_strcspn_test_2);
    tcase_add_test(tc_core, s21_strcspn_test_3);
    tcase_add_test(tc_core, s21_strcspn_test_4);
    tcase_add_test(tc_core, s21_strcspn_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 14 функция. Набор тестов
Suite *s21_strerror_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strerror");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strerror_test_1);
    tcase_add_test(tc_core, s21_strerror_test_2);
    tcase_add_test(tc_core, s21_strerror_test_3);
    tcase_add_test(tc_core, s21_strerror_test_4);
    tcase_add_test(tc_core, s21_strerror_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 15 функция. Набор тестов
Suite *s21_strlen_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strlen");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strlen_test_1);
    tcase_add_test(tc_core, s21_strlen_test_2);
    tcase_add_test(tc_core, s21_strlen_test_3);
    tcase_add_test(tc_core, s21_strlen_test_4);
    tcase_add_test(tc_core, s21_strlen_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 16 функция. Набор тестов
Suite *s21_strpbrk_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strpbrk");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strpbrk_test_1);
    tcase_add_test(tc_core, s21_strpbrk_test_2);
    tcase_add_test(tc_core, s21_strpbrk_test_3);
    tcase_add_test(tc_core, s21_strpbrk_test_4);
    tcase_add_test(tc_core, s21_strpbrk_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 17 функция. Набор тестов
Suite *s21_strrchr_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strrchr");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strrchr_test_1);
    tcase_add_test(tc_core, s21_strrchr_test_2);
    tcase_add_test(tc_core, s21_strrchr_test_3);
    tcase_add_test(tc_core, s21_strrchr_test_4);
    tcase_add_test(tc_core, s21_strrchr_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 18 функция. Набор тестов
Suite *s21_strspn_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strspn");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strspn_test_1);
    tcase_add_test(tc_core, s21_strspn_test_2);
    tcase_add_test(tc_core, s21_strspn_test_3);
    tcase_add_test(tc_core, s21_strspn_test_4);
    tcase_add_test(tc_core, s21_strspn_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

// 19 функция. Набор тестов
Suite *s21_strstr_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("strstr");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_strstr_test_1);
    tcase_add_test(tc_core, s21_strstr_test_2);
    tcase_add_test(tc_core, s21_strstr_test_3);
    tcase_add_test(tc_core, s21_strstr_test_4);
    tcase_add_test(tc_core, s21_strstr_test_5);

    suite_add_tcase(s, tc_core);

    return s;
}

int s21_string_tests(Suite *s) {
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? 0 : 1;
}

int main(void) {
    s21_string_tests(s21_memchr_suite());   // 1
    s21_string_tests(s21_memcmp_suite());   // 2
    s21_string_tests(s21_memcpy_suite());   // 3
    s21_string_tests(s21_memmove_suite());  // 4
    // s21_string_tests(s21_memset_suite());   // 5
    s21_string_tests(s21_strcat_suite());   // 6
    s21_string_tests(s21_strncat_suite());  // 7
    s21_string_tests(s21_strchr_suite());   // 8
    s21_string_tests(s21_strcmp_suite());   // 9
    s21_string_tests(s21_strncmp_suite());  // 10
    s21_string_tests(s21_strcpy_suite());   // 11
    s21_string_tests(s21_strncpy_suite());  // 12
    s21_string_tests(s21_strcspn_suite());  // 13
    s21_string_tests(s21_strerror_suite()); // 14
    s21_string_tests(s21_strlen_suite());   // 15
    s21_string_tests(s21_strpbrk_suite());  // 16
    s21_string_tests(s21_strrchr_suite());  // 17
    s21_string_tests(s21_strspn_suite());   // 18
    s21_string_tests(s21_strstr_suite());   // 19
}
