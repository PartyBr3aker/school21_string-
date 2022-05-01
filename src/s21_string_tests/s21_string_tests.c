#include "s21_string.h"
#include <string.h>
#include <check.h>
// 1 функция. 1й тест
START_TEST(s21_memchr_test_1) {
    ck_assert_pstr_eq(s21_memchr("qwerty", 'e', 5), memchr("qwerty", 'e', 5));
} END_TEST

// 1 функция. 2й тест
START_TEST(s21_memchr_test_2) {
    ck_assert_pstr_eq(s21_memchr("Hello world\n\0", ' ', 6), memchr("Hello world\n\0", ' ', 6));
} END_TEST

// 1 функция. 3й тест
START_TEST(s21_memchr_test_3) {
    ck_assert_pstr_eq(s21_memchr("a\n\0", 'g', 6), memchr("a\n\0", 'g', 6));
} END_TEST

// 1 функция. 4й тест
START_TEST(s21_memchr_test_4) {
    ck_assert_pstr_eq(s21_memchr(" \n\0", ' ', 6), memchr(" \n\0", ' ', 6));
} END_TEST

// 1 функция. 5й тест
START_TEST(s21_memchr_test_5) {
    ck_assert_pstr_eq(s21_memchr("\n\0", '\n', 6), memchr("\n\0", '\n', 6));
} END_TEST

// 6 функция. 1й тест
START_TEST(s21_strcat_test_1) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcat(str, "hello"), strcat(str1, "hello"));
} END_TEST

// 6 функция. 2й тест
START_TEST(s21_strcat_test_2) {
    char str[50] = "wsddqd";
    char str1[50] = "wsddqd";
    ck_assert_pstr_eq(s21_strcat(str, "Hello world\0"), strcat(str1, "Hello world\0"));
} END_TEST

// 6 функция. 3й тест
START_TEST(s21_strcat_test_3) {
    char str[50] = "\0";
    char str1[50] = "\0";
    ck_assert_pstr_eq(s21_strcat(str, "a\n\0"), strcat(str1, "a\n\0"));
} END_TEST

// 6 функция. 4й тест
START_TEST(s21_strcat_test_4) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcat(str, "Hello world\n\0"), strcat(str1, "Hello world\n\0"));
} END_TEST

// 6 функция. 5й тест
START_TEST(s21_strcat_test_5) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcat(str, "    "), strcat(str1, "    "));
} END_TEST

// 11 функция. 1й тест
START_TEST(s21_strcpy_test_1) {
    char str[50] = "Hello";
    char str1[50] = "Hello";
    ck_assert_pstr_eq(s21_strcpy(str, "    "), strcpy(str1, "    "));
} END_TEST

// 11 функция. 2й тест
START_TEST(s21_strcpy_test_2) {
    char str[50] = "";
    char str1[50] = "";
    ck_assert_pstr_eq(s21_strcpy(str, "Hello world\n\0"), strcpy(str1, "Hello world\n\0"));
} END_TEST

// 11 функция. 3й тест
START_TEST(s21_strcpy_test_3) {
    char str[50] = "a\n\0";
    char str1[50] = "a\n\0";
    ck_assert_pstr_eq(s21_strcpy(str, " \n\0"), strcpy(str1, " \n\0"));
} END_TEST

// 11 функция. 4й тест
START_TEST(s21_strcpy_test_4) {
    char str[50] = "Hel   lo";
    char str1[50] = "Hel   lo";
    ck_assert_pstr_eq(s21_strcpy(str, "a\n\0"), strcpy(str1, "a\n\0"));
} END_TEST

// 11 функция. 5й тест
START_TEST(s21_strcpy_test_5) {
    char str[50] = "Hello world\n\0";
    char str1[50] = "Hello world\n\0";
    ck_assert_pstr_eq(s21_strcpy(str, "\n\0"), strcpy(str1, "\n\0"));
} END_TEST

// 16 функция. 1й тест
START_TEST(s21_strpbrk_test_1) {
    ck_assert_pstr_eq(s21_strpbrk("qwe", "yfgbgbdw"), strpbrk("qwe", "yfgbgbdw"));
} END_TEST

// 16 функция. 2й тест
START_TEST(s21_strpbrk_test_2) {
    ck_assert_pstr_eq(s21_strpbrk("Hello world\n\0", ""), strpbrk("qwe", ""));
} END_TEST

// 16 функция. 3й тест
START_TEST(s21_strpbrk_test_3) {
    ck_assert_pstr_eq(s21_strpbrk("\n\0", "yfgbg\nbdw"), strpbrk("\n\0", "yfgbg\nbdw"));
} END_TEST

// 16 функция. 4й тест
START_TEST(s21_strpbrk_test_4) {
    ck_assert_pstr_eq(s21_strpbrk("Hello world\0", "dlrow olleH"), strpbrk("Hello world\0", "dlrow olleH"));
} END_TEST

// 16 функция. 5й тест
START_TEST(s21_strpbrk_test_5) {
    ck_assert_pstr_eq(s21_strpbrk(" q q q", "fjfeoijoiwef "), strpbrk(" q q q", "fjfeoijoiwef "));
} END_TEST

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

// 11 функция. Набор тестов
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
    s21_string_tests(s21_memchr_suite());  // 1
    s21_string_tests(s21_strcat_suite());  // 6
    s21_string_tests(s21_strcpy_suite());  // 11
    s21_string_tests(s21_strpbrk_suite());  // 16
}
