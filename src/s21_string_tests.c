#include <check.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>
#include "s21_string.h"

#define BUFF_SIZE 512

Suite *suite_sprintf(void);
Suite *suite_insert(void);
Suite *suite_memchr(void);
Suite *suite_memcmp(void);
Suite *suite_memcpy(void);
Suite *suite_memmove(void);
Suite *suite_memset(void);
Suite *suite_strcat(void);
Suite *suite_strchr(void);
Suite *suite_strcmp(void);
Suite *suite_strcpy(void);
Suite *suite_strcspn(void);
Suite *suite_strerror(void);
Suite *suite_strlen(void);
Suite *suite_strncat(void);
Suite *suite_strncmp(void);
Suite *suite_strncpy(void);
Suite *suite_strpbrk(void);
Suite *suite_strrchr(void);
Suite *suite_strspn(void);
Suite *suite_strstr(void);
Suite *suite_strtok(void);
Suite *suite_to_upper(void);
Suite *suite_to_lower(void);
Suite *suite_trim(void);

void run_tests(void);
void run_testcase(Suite *testcase);
int main(void) {
    run_tests();

    return 0;
}

// START_TEST(atoi_test1) {
//     char src[] = "  +123123123";
//     ck_assert_int_eq(atoi(src),
//                      s21_atoi(src));
// } END_TEST

// Suite *suite_atoi(void) {
//     Suite *s = suite_create("suite_atoi");
//     TCase *tc = tcase_create("atoi_tc");

//     tcase_add_test(tc, atoi_test1);

//     suite_add_tcase(s, tc);
//     return s;
// }

START_TEST(insert_test1) {
    char src[] = "Shlepa";
    char str[] = "I love my . He is very kind!";
    s21_size_t index = 10;
    char expected[] = "I love my Shlepa. He is very kind!";
    char *got = (char *)s21_insert(str, src, index);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(insert_test2) {
    char src[] = "Hello, ";
    char str[] = "Aboba!";
    s21_size_t index = 0;
    char expected[] = "Hello, Aboba!";
    char *got = (char *)s21_insert(str, src, index);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(insert_test3) {
    char src[] = "";
    char str[] = "";
    s21_size_t index = 100;
    char *expected = S21_NULL;
    char *got = (char *)s21_insert(str, src, index);
    ck_assert_ptr_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(insert_test4) {
    char *src = NULL;
    char *str = NULL;
    s21_size_t index = 100;
    char *expected = NULL;
    char *got = (char *)s21_insert(str, src, index);
    ck_assert_ptr_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(insert_test5) {
    char src[] = "Monkey";
    char str[] = "Space  ";
    s21_size_t index = 6;
    char expected[] = "Space Monkey ";
    char *got = (char *)s21_insert(str, src, index);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

Suite *suite_insert(void) {
    Suite *s = suite_create("suite_insert");
    TCase *tc = tcase_create("insert_tc");

    tcase_add_test(tc, insert_test1);
    tcase_add_test(tc, insert_test2);
    tcase_add_test(tc, insert_test3);
    tcase_add_test(tc, insert_test4);
    tcase_add_test(tc, insert_test5);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty_str) {
    s21_size_t n_byte = 0;
    char str[10] = "";
    int find_byte = '\0';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_zero_in_string) {
    s21_size_t n_byte = 7;
    char str[10] = "string";
    int find_byte = '\0';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_simbol_in_string_in_start) {
    s21_size_t n_byte = 6;
    char str[10] = "Atring";
    int find_byte = 'A';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_simbol_in_string_in_end) {
    s21_size_t n_byte = 7;
    char str[10] = "StringA";
    int find_byte = 'A';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_num_in_string_in_mid) {
    s21_size_t n_byte = 15;
    char str[16] = "Str55333222ingA";
    int find_byte = '3';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_num_in_array_num) {
    int array[] = {1, 2, 3, 127, 5, 99, 100};
    s21_size_t n_byte = sizeof(int) * 7;
    int find_byte = 127;

    ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                     memchr(array, find_byte, n_byte));
} END_TEST


START_TEST(find_float_in_array) {
    float array[] = {1, 2, 3, 666, 5, 99, 100};
    s21_size_t n_byte = sizeof(float) * 7;
    int find_byte = 666;

    ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                     memchr(array, find_byte, n_byte));
} END_TEST

START_TEST(easy_test_string) {
    s21_size_t n_byte = 5;
    char str[10] = "aboba";
    int find_byte = 'c';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

Suite *suite_memchr(void) {
    Suite *s = suite_create("suite_memchr");
    TCase *tc = tcase_create("memchr_tc");

    tcase_add_test(tc, empty_str);
    tcase_add_test(tc, find_zero_in_string);
    tcase_add_test(tc, find_simbol_in_string_in_start);
    tcase_add_test(tc, find_simbol_in_string_in_end);
    tcase_add_test(tc, find_num_in_string_in_mid);
    tcase_add_test(tc, find_num_in_array_num);
    tcase_add_test(tc, find_float_in_array);
    tcase_add_test(tc, easy_test_string); 

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(zero_byte1) {
    char str1[] = "aboba";
    char str2[] = "aboba";
    int n = 0;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(first_byte_in_string) {
    char str1[] = "aboba";
    char str2[] = "aboba";
    int n = 3;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(register_test) {
    char str1[] = "aboba";
    char str2[] = "Aboba";
    int n = 1;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST


START_TEST(zero_byte_in_num) {
    char str1[] = "1";
    char str2[] = "1";
    int n = 0;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(first_byte_in_num) {
    char str1[] = "1";
    char str2[] = "1234";
    int n = 1;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(two_byte_in_num) {
    char str1[] = "1234";
    char str2[] = "1234";
    int n = 2;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(two_byte_long_two_num) {
    char str1[] = "13";
    char str2[] = "1234";
    int n = 2;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(two_byte_long_first_num) {
    char str1[] = "134567";
    char str2[] = "1234";
    int n = 2;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(eq_long_string) {
    char str1[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
    char str2[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
    int n = 71;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

START_TEST(not_eq_long_string) {
    char str1[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
    char str2[] = "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";
    int n = 71;

    ck_assert_int_eq(
            s21_memcmp(str1, str2, n),
            memcmp(str1, str2, n));
} END_TEST

Suite *suite_memcmp(void) {
    Suite *s = suite_create("suite_memcmp");
    TCase *tc = tcase_create("memcmp_tc");

    tcase_add_test(tc, zero_byte1);
    tcase_add_test(tc, first_byte_in_string);
    tcase_add_test(tc, register_test);
    tcase_add_test(tc, zero_byte_in_num);
    tcase_add_test(tc, first_byte_in_num);
    tcase_add_test(tc, two_byte_in_num);
    tcase_add_test(tc, two_byte_long_two_num);
    tcase_add_test(tc, two_byte_long_first_num);
    tcase_add_test(tc, eq_long_string);
    tcase_add_test(tc, not_eq_long_string);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(hate_test) {
    char src[] = "i hate memcmp";
    s21_size_t kByte = 12;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(zero_test_string1) {
    char src[] = "aboba";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(any_empty1) {
    char src[] = "";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(zero_test_string_with_register1) {
    char src[] = "I hate memcmp";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(zero_test_num1) {
    char src[] = "123";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string1) {
    char src[] = "aboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string_with_register1) {
    char src[] = "Zboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(one_byte_num1) {
    char src[] = "09";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(basic_long_string1) {
    char src[] = "abobasdafoijasdofjas asdopij";
    s21_size_t kByte = 28;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register1) {
    char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
    s21_size_t kByte = 36;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num1) {
    char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 53;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num_and_simbol1) {
    char src[] = "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 71;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


Suite *suite_memcpy(void) {
    Suite *s = suite_create("suite_memcpy");
    TCase *tc = tcase_create("memcpy_tc");

    tcase_add_test(tc, hate_test);
    tcase_add_test(tc, zero_test_string1);
    tcase_add_test(tc, any_empty1);
    tcase_add_test(tc, zero_test_string_with_register1);
    tcase_add_test(tc, zero_test_num1);
    tcase_add_test(tc, one_byte_string1);
    tcase_add_test(tc, one_byte_string_with_register1);
    tcase_add_test(tc, one_byte_num1);
    tcase_add_test(tc, basic_long_string1);
    tcase_add_test(tc, long_string_with_register1);
    tcase_add_test(tc, long_string_with_register_and_num1);
    tcase_add_test(tc, long_string_with_register_and_num_and_simbol1);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty_dest_and_src) {
    char src[200] = "";
    char src2[200] = "";
    s21_size_t copy_kByte = 0;

    char *res = src;
    char *expected = src2;
    s21_size_t check_kByte = 0;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(empty_dest) {
    char src[200] = "123SDFAZ`ESFsdfsdf";
    char src2[200] = "123SDFAZ`ESFsdfsdf";
    s21_size_t copy_kByte = 10;

    char res[200] = "";
    char expected[200] = "";
    s21_size_t check_kByte = 10;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST


START_TEST(empty_src1) {
    char src[200] = "";
    char src2[200] = "";
    s21_size_t copy_kByte = 0;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 13;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(write_in_left) {
    char src[200] = "Hate";
    char src2[200] = "Hate";
    s21_size_t copy_kByte = 4;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 17;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(write_in_right) {
    char src[200] = "Hate";
    char src2[200] = "Hate";
    s21_size_t copy_kByte = 4;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 17;

    s21_memmove(res + 13, src, copy_kByte);
    memmove(expected + 13, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(write_in_mid) {
    char src[200] = "Hate";
    char src2[200] = "Hate";
    s21_size_t copy_kByte = 4;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 17;

    s21_memmove(res + 5, src, copy_kByte);
    memmove(expected + 5, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(overlap_write_in_left) {
    char src[200] = "I HATE memmove!!!";
    char src2[200] = "I HATE memmove!!!";
    s21_size_t copy_kByte = 17;

    char *res = src;
    char *expected = src2;
    s21_size_t check_kByte = 34;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(overlap_write_in_right) {
    char src[200] = "I HATE memmove!!!";
    char src2[200] = "I HATE memmove!!!";
    s21_size_t copy_kByte = 17;

    char *res = src + 17;
    char *expected = src2 + 17;
    s21_size_t check_kByte = 34;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(overlap_write_in_mid) {
    char src[200] = "I HATE memmove!!!";
    char src2[200] = "I HATE memmove!!!";
    s21_size_t copy_kByte = 17;

    char *res = src + 5;
    char *expected = src2 + 5;
    s21_size_t check_kByte = 34;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST


START_TEST(zero_test_string) {
    char src[] = "aboba";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(any_empty) {
    char src[] = "";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(zero_test_string_with_register) {
    char src[] = "I hate memcmp";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(zero_test_num) {
    char src[] = "123";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string) {
    char src[] = "aboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string_with_register) {
    char src[] = "Zboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(one_byte_num) {
    char src[] = "09";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(basic_long_string) {
    char src[] = "abobasdafoijasdofjas asdopij";
    s21_size_t kByte = 28;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register) {
    char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
    s21_size_t kByte = 36;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num) {
    char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 53;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num_and_simbol) {
    char src[] = "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 71;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(ints) {
    int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21_size_t kByte = 4;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(floats) {
    float src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21_size_t kByte = 8;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_doubels) {
    long double src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21_size_t kByte = 16;
    char res[kByte + 8];
    char expected[kByte + 8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST



Suite *suite_memmove(void) {
    Suite *s = suite_create("suite_memmove");
    TCase *tc = tcase_create("memmove_tc");

    tcase_add_test(tc, empty_dest_and_src);
    tcase_add_test(tc, empty_dest);
    tcase_add_test(tc, empty_src1);
    tcase_add_test(tc, write_in_left);
    tcase_add_test(tc, write_in_right);
    tcase_add_test(tc, write_in_mid);
    tcase_add_test(tc, overlap_write_in_left);
    tcase_add_test(tc, overlap_write_in_right);
    tcase_add_test(tc, overlap_write_in_mid);

    // Old teste
    tcase_add_test(tc, zero_test_string);
    tcase_add_test(tc, any_empty);
    tcase_add_test(tc, zero_test_string_with_register);
    tcase_add_test(tc, zero_test_num);
    tcase_add_test(tc, one_byte_string);
    tcase_add_test(tc, one_byte_string_with_register);
    tcase_add_test(tc, one_byte_num);
    tcase_add_test(tc, basic_long_string);
    tcase_add_test(tc, long_string_with_register);
    tcase_add_test(tc, long_string_with_register_and_num);
    tcase_add_test(tc, long_string_with_register_and_num_and_simbol);
    tcase_add_test(tc, ints);
    tcase_add_test(tc, floats);
    tcase_add_test(tc, long_doubels);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(aboba_test) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(zero_byte2) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 0;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(empty1) {
    char res[] = "";
    char expected[] = "";
    char replace = '\0';
    s21_size_t n_byte = 0;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(replace_on_register_sim) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'A';
    s21_size_t n_byte = 3;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(replace_on_register_num) {
    char res[] = "a1obA";
    char expected[] = "a1obA";
    char replace = '1';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(long_string) {
    char res[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char expected[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char replace = '1';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_memset(void) {
    Suite *s = suite_create("suite_memset");
    TCase *tc = tcase_create("memset_tc");

    tcase_add_test(tc, aboba_test);
    tcase_add_test(tc, zero_byte2);
    tcase_add_test(tc, empty1);
    tcase_add_test(tc, replace_on_register_sim);
    tcase_add_test(tc, replace_on_register_num);
    tcase_add_test(tc, long_string);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(simple_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple value %d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%5d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+12d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(padding_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%012i";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(star_width_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%0*d";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                      sprintf(str2, format, 5, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(star_precision_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%0.*i";
//     int val = 69;
//     ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                      sprintf(str2, format, 5, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(many_flags_many_ints) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char format[] = "%0.*i %d %4.*i %013d %d";
//     int val = 69;
//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
//         sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(flags_long_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+5.31li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(flags_short_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-16.9hi";
//     short int val = 6958;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(flags_another_long_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%0.*ld";
//     long val = 8581385185;
//     ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
//                      sprintf(str2, format, 5, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(zero_precision_zero_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% 5.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
                     sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(octal_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%15o";
//     int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(octal_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-16o";
//     int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(octal_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.51o";
//     int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(octal_many_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%-5.51o";
//     int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(octal_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%o";
//     ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(octal_hash) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#o";
//     int val = 57175;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(octal_short) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%hd";
//     short int val = 14140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(octal_long) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%lo";
//     long int val = 949149114140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(octal_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%lo, %o, %ho, %.5o, %5.o";
//     long int val = 949149114140;
//     ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
//                      sprintf(str2, format, val, (unsigned)14,
//                              (unsigned short)1441, (unsigned)14414,
//                              (unsigned)9681));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(octal) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%lo";
//     long int val = 84518;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(unsigned_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    ck_assert_int_eq(s21_sprintf(str1, format, 0),
                     sprintf(str2, format, (unsigned)0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(hex_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%5x";
//     unsigned val = 858158158;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(hex_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#-10x";
//     unsigned val = 858158158;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.15x";
//     unsigned val = 858158158;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#-10x%x%X%#x%#X%5.5x";
//     unsigned val = 858158158;
//     ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
//                      sprintf(str2, format, val, val, val, val, val, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_many_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#-5.10x";
//     unsigned val = 858158158;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#x";
//     unsigned val = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#x";
//     unsigned val = 18571;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_short) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#hx";
//     unsigned short val = 12352;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_long) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#lx";
//     unsigned long val = 18571757371571;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(hex_one_longer_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#2x";
//     unsigned val = 1;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(hex_two_longer_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%#30x";
//     unsigned val = 1;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%c";
    char val = 'X';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% -5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                     sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.15s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-15.9s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s%s%s%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                     sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(ptr) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%p";
//     ck_assert_int_eq(s21_sprintf(str1, format, format),
//                      sprintf(str2, format, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(ptr_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%15p";
//     ck_assert_int_eq(s21_sprintf(str1, format, format),
//                      sprintf(str2, format, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(ptr_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%.5p";
//     ck_assert_int_eq(s21_sprintf(str1, format, format),
//                      sprintf(str2, format, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(null_ptr) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "%p";
//     char *ptr = NULL;
//     ck_assert_int_eq(s21_sprintf(str1, format, ptr),
//                      sprintf(str2, format, ptr));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(string_width_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(n_specifier) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     int ret = 0;
//     char *format = "Hello, my sexy little aboba abobushka abobina %n";
//     ck_assert_int_eq(s21_sprintf(str1, format, &ret),
//                      sprintf(str2, format, &ret));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%Lf";
//     long double val = 513515.131513515151351;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%10Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_precision_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.0Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(float_precision_empty) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(float_precision_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.15Lf";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(float_precision_huge_negative) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.15Lf";
//     long double val = -15.35581134;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(float_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%Lf";
//     long double val = 72537572375.1431341;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(float_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "% f";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(float_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "% .0f %.lf %Lf %f %lf %Lf";
//     float val = 0;
//     double val1 = 0;
//     long double val2 = 3515315.153151;
//     float val3 = 5.5;
//     double val4 = 9851.51351;
//     long double val5 = 95919539159.53151351131;
//     ck_assert_int_eq(
//         s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
//         sprintf(str2, format, val, val1, val2, val3, val4, val5));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.17Le";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_precision_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.0Le";
//     long double val = 15.35;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(e_precision_empty) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.Le";
//     long double val = 15.000009121;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_precision_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.15Le";
//     long double val = 0.000000000000000123;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(e_precision_huge_negative) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.15Le";
//     long double val = -15.35581134;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(e_huge) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%Le";
//     long double val = 72537572375.1431341;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%015E";
//     float val = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_width) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%15e";
//     float val = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "% .0e %.le %Le %e %le %Le";
//     float val = 0;
//     double val1 = 0;
//     long double val2 = 3515315.153151;
//     float val3 = 5.5;
//     double val4 = 0.094913941;
//     long double val5 = 95919539159.53151351131;
//     ck_assert_int_eq(
//         s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
//         sprintf(str2, format, val, val1, val2, val3, val4, val5));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(E_int) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%.17LE";
//     long double val = 4134121;
//     ck_assert_int_eq(s21_sprintf(str1, format, val),
//                      sprintf(str2, format, val));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(all_empty1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                     sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                     sprintf(str2, "%s", "Drop Sega PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
        sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                     sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                     sprintf(str2, "%f", 0.0001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
        sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                     sprintf(str2, "%u", (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                     sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                             (unsigned)666, (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
                     sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                     sprintf(str2, "%-8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
        sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
// START_TEST(test_one_hex_lower) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
//                      sprintf(str2, "%x", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
//                      sprintf(str2, "%x", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_upper) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
//                      sprintf(str2, "%X", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
//                      sprintf(str2, "%X", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_lower) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
//         sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_upper) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
//         sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
// START_TEST(test_one_hex_lower_with_alignment_left) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
//                      sprintf(str2, "%-3x", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
//                      sprintf(str2, "%-3x", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_lower_with_alignment_right) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
//                      sprintf(str2, "%13x", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
//                      sprintf(str2, "%13x", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_upper_with_alignment_left) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
//                      sprintf(str2, "%-60X", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
//                      sprintf(str2, "%-60X", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_upper_with_alignment_right) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
//                      sprintf(str2, "%7X", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
//                      sprintf(str2, "%7X", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_lower_with_alignment) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
//         sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_upper_with_alignment) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     ck_assert_int_eq(
//         s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
//         sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
// START_TEST(test_one_hex_with_hashtag) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
//                      sprintf(str2, "%#x", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
//                      sprintf(str2, "%#x", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_upper_with_hashtag) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
//                      sprintf(str2, "%#X", (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
//                      sprintf(str2, "%#X", INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535,
//                                  -13, -0, 123213123),
//                      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13,
//                              -0, 123213123));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535,
//                                  -13, -0, 123213123),
//                      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13,
//                              -0, 123213123));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
// START_TEST(test_one_hex_lower_with_width_star) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
//                      sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);

//     ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
//                      sprintf(str2, "%*x", 11, 0));
//     ck_assert_str_eq(str1, str2);

//     ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
//                      sprintf(str2, "%*x", 11, INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_upper_with_width_star) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
//                      sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
//     ck_assert_str_eq(str1, str2);

//     ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
//                      sprintf(str2, "%*X", 11, 0));
//     ck_assert_str_eq(str1, str2);

//     ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
//                      sprintf(str2, "%*X", 11, INT32_MAX));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0,
//                                  -1, 199, -123978, 3, -1251),
//                      sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
//                              199, -123978, 3, -1251));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_upper_with_width_star) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0,
//                                  -1, 199, -123978, 3, -1251),
//                      sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
//                              199, -123978, 3, -1251));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
// START_TEST(test_one_hex_lower_with_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     int a = s21_sprintf(str1, "%*.6x", 11, 0);
//     int b = sprintf(str2, "%*.6x", 11, 0);
//     ck_assert_int_eq(a, b);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_upper_with_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
//     int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
//     ck_assert_int_eq(a, b);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_lower_with_precision_and_other) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     int a = s21_sprintf(
//         str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
//         4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
//     int b = sprintf(
//         str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
//         4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
//     ck_assert_int_eq(a, b);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_many_hex_upper_with_precision_and_other) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(
//         s21_sprintf(str1,
//                     "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
//                     -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
//                     41, -41, 33),
//         sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
//                 -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
//                 -41, 33));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
// START_TEST(test_one_hex_lower_with_length) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
//                      sprintf(str2, "%hx", (unsigned short)-11));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
//                      sprintf(str2, "%hx", (unsigned short)0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
//                      sprintf(str2, "%hx", (unsigned short)11));
//     ck_assert_str_eq(str1, str2);
//     long unsigned int val = INT32_MAX;
//     ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
//     ck_assert_str_eq(str1, str2);
//     long unsigned int v = 0;
//     ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_one_hex_upper_with_length) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
//                      sprintf(str2, "%hx", (unsigned short)-11));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
//                      sprintf(str2, "%hx", (unsigned short)0));
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
//                      sprintf(str2, "%hx", (unsigned short)11));
//     ck_assert_str_eq(str1, str2);
//     long unsigned int val = INT32_MAX;
//     ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
//     ck_assert_str_eq(str1, str2);
//     long unsigned int v = 0;
//     ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%10ld";

    ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%1.1f";

    ck_assert_int_eq(s21_sprintf(str1, format, 1.1),
                     sprintf(str2, format, 1.1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%8.3c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+5.5d aboba";

    int val = 10000;
    int a = s21_sprintf(str1, format, val);
    int b = sprintf(str2, format, val);
    ck_assert_int_eq(a, b);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.7f";

    ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                     sprintf(str2, format, 11.123456));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.4s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                     sprintf(str2, format, "aboba floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%6.6u";

    ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                     sprintf(str2, format, 12341151));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%li%ld%lu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                     sprintf(str2, format, 666666666666, 777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%hi%hd%hu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                     sprintf(str2, format, 666, -777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf11) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+li%+lu%+d%+lf";

    ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                     sprintf(str2, format, -123, 321, -5555, -1213.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_sprintf12) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
//     long double k = 333.33213;

//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
//         sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf14) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf15) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf16) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf17) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                     sprintf(str2, format, "aboba likes floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf18) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s% c";

    ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                     sprintf(str2, format, "", 'f'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf19) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%210s";

    ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                     sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf20) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-115s";

    ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                     sprintf(str2, format, "Nick her"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf24) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                    "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
        sprintf(str2, format, 'f', 21, 42, 666.666,
                "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf25) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                     sprintf(str2, format, 121.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_sprintf26) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf27) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%%%%%%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf28) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     int n1;
//     int n2;
//     int a = s21_sprintf(str1, "%d%n", 123, &n1);
//     int b = sprintf(str2, "%d%n", 123, &n2);

//     ck_assert_int_eq(a, b);
//     ck_assert_int_eq(n1, n2);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf29) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                     sprintf(str2, format, 111.111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf30) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.1d";

    ck_assert_int_eq(s21_sprintf(str1, format, 111),
                     sprintf(str2, format, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_sprintf31) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%e";
//     double x = 111;
//     ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf32) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%e%e%e%e";

//     ck_assert_int_eq(
//         s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
//         sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf33) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%Le";
//     long double x = 122.1231;

//     ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf35) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.10e";

//     ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
//                      sprintf(str2, format, 111.184314818));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf36) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%5.3e%3.2e%lf";

//     ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
//                      sprintf(str2, format, 0.000111, 111.555, 1.999));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf37) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%E";

//     ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
//                      sprintf(str2, format, 0.666666));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf38) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%E%E%E";

//     ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
//                      sprintf(str2, format, 0.0000999, 111.9999, 6.666));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf39) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%e ABOBA %Lf %Lf %Le";
//     long double c = 848181;
//     long double a = 0.00000001;
//     long double b = 1111111.11;
//     ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
//                      sprintf(str2, format, 123.123, a, b, c));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf40) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%#e Floppa %#E%#f";

//     ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
//                      sprintf(str2, format, 123.111, 0.0000999, 0.555));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf41) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.Lf";
//     long double a = 7.9418438184;

//     ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf42) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%#5p";
//     int a = 5;
//     ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf43) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.5o";

//     ck_assert_int_eq(s21_sprintf(str1, format, 12345),
//                      sprintf(str2, format, 12345));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf44) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%#5lX";
//     long hex = 314818438141;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_trailing_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%g";
//     double hex = 0.50300;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_large) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%g";
//     double hex = 5131.43141;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_small) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%g";
//     double hex = 0.123000;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_precision) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.5g";
//     double hex = 0.123000;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_precision_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.0g";
//     double hex = 0.123000;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_precision_missing) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.g";
//     double hex = 0.123000;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_many_zeroes_in_front) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.g";
//     double hex = 0.0004;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_one_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%g";
//     double hex = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_zero) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%.5g";
//     double hex = 0;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_mantiss) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%g";
//     double hex = 0.0000005;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_mantiss_flags) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%5.8g";
//     double hex = 0.0000005;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_short_no_mantiss) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%g";
//     double hex = 0.005;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(LG) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%LG";
//     long double hex = 0.000005;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_many) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%LG %g %G %Lg %.5g";
//     long double hex = 0.000005;
//     double hex1 = 41.1341;
//     double hex2 = 848.9000;
//     long double hex3 = 0.0843;
//     double hex4 = 0.0005;
//     double hex5 = 0.8481481;
//     ck_assert_int_eq(
//         s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
//         sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(wide_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %lc";
//     unsigned long w = L'汉';
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }

// START_TEST(width_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %5c";
//     char w = 'c';
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// START_TEST(minus_wide_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %-5lc";
//     unsigned long w = L'森';
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %ls";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string1) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %5.12ls";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string2) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %120ls ABOBA";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string3) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %-43ls";
//     wchar_t w[] = L"森我爱菠萝";
//     int a = s21_sprintf(str1, format, w);
//     int b = sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
//     ck_assert_int_eq(a, b);
// }
// END_TEST

START_TEST(bebasik__1) {
char boba1_s21[10000];
char boba1[10000];
ck_assert_int_eq(s21_sprintf(boba1_s21, "%+.5hd1%+.4hd9%+f`% 9.1f%-ui%-9u% 1.3i%-9fw%+hi%+4.10hi@% 3d8r%-8u% 9hiq%+8.3hd%-1c%+1hdzh%-10hu`3cb%+6.6f%-.9hi%+.2f3d2=%+10.5fz9p", -13678, -28807, -17185.94659755372, 9566.758295974045, 356493, -995829, 936622, 1999.6862417860298, 29118, -284, 665519, 98446, 28694, 21966, '^', -22331, -9108, -6802.643116886599, 5079, 0.005560822282801858, 4988.289766287002),
sprintf(boba1, "%+.5hd1%+.4hd9%+f`% 9.1f%-ui%-9u% 1.3i%-9fw%+hi%+4.10hi@% 3d8r%-8u% 9hiq%+8.3hd%-1c%+1hdzh%-10hu`3cb%+6.6f%-.9hi%+.2f3d2=%+10.5fz9p", -13678, -28807, -17185.94659755372, 9566.758295974045, 356493, -995829, 936622, 1999.6862417860298, 29118, -284, 665519, 98446, 28694, 21966, '^', -22331, -9108, -6802.643116886599, 5079, 0.005560822282801858, 4988.289766287002));
ck_assert_str_eq(boba1_s21, boba1);
}
END_TEST

START_TEST(bebasik__2) {
char boba2_s21[10000];
char boba2[10000];
ck_assert_int_eq(s21_sprintf(boba2_s21, "%+d)u% hi% .7i%+.7f%+8.1dk% 3f)b3%+4d% dj% 9d2f%-u% 5.8fs)l%+.10i%+5.5hic% 6.5hi=eq5%-8.0i%+.0hd%+.9hixeft*.p% .3d", 636450, -10422, 628519, -3757.590948645235, 434197, 6115.615725620131, 363433, -586279, -772846, 520607, 12618.75936432819, -303993, -26833, 5367, 182050, -24122, 26637, -576561),
sprintf(boba2, "%+d)u% hi% .7i%+.7f%+8.1dk% 3f)b3%+4d% dj% 9d2f%-u% 5.8fs)l%+.10i%+5.5hic% 6.5hi=eq5%-8.0i%+.0hd%+.9hixeft*.p% .3d", 636450, -10422, 628519, -3757.590948645235, 434197, 6115.615725620131, 363433, -586279, -772846, 520607, 12618.75936432819, -303993, -26833, 5367, 182050, -24122, 26637, -576561));
ck_assert_str_eq(boba2_s21, boba2);
}
END_TEST

START_TEST(bebasik__3) {
char boba3_s21[10000];
char boba3[10000];
ck_assert_int_eq(s21_sprintf(boba3_s21, "%+7d&s%-10.8d%+8.8i%-u% hi% 7.4hiky% 8i%-8c$", 404790, -818289, -261097, -815101, -23349, -22681, -526198, 'c'),
sprintf(boba3, "%+7d&s%-10.8d%+8.8i%-u% hi% 7.4hiky% 8i%-8c$", 404790, -818289, -261097, -815101, -23349, -22681, -526198, 'c'));
ck_assert_str_eq(boba3_s21, boba3);
}
END_TEST

START_TEST(bebasik__4) {
char boba4_s21[10000];
char boba4[10000];
ck_assert_int_eq(s21_sprintf(boba4_s21, "%-.2f%+9d% 9hi9@wiy% .4d%+6hi%-2hi% 1hd% 8hdt%+.4i% 3hd#h%-9.3i", -138.15714804417834, 916637, -13928, 171143, -15798, -22799, -20726, 15922, -566334, 3433, 924150),
sprintf(boba4, "%-.2f%+9d% 9hi9@wiy% .4d%+6hi%-2hi% 1hd% 8hdt%+.4i% 3hd#h%-9.3i", -138.15714804417834, 916637, -13928, 171143, -15798, -22799, -20726, 15922, -566334, 3433, 924150));
ck_assert_str_eq(boba4_s21, boba4);
}
END_TEST

START_TEST(bebasik__5) {
char boba5_s21[10000];
char boba5[10000];
ck_assert_int_eq(s21_sprintf(boba5_s21, "% 5i%+7.1hd%+7.6hi%-hu%+3.3hi% 2f% hd.%-6.7d%+10hi9%-10su9%-1.1su%-hu%-d@98% i(u%-hd", 59252, -6551, 17631, 19632, 13171, 8932.691181166485, 30909, 797407, 26660, "[ttm", "=.-&r,zfgb8^2qsz", 992, 138772, 952464, 28205),
sprintf(boba5, "% 5i%+7.1hd%+7.6hi%-hu%+3.3hi% 2f% hd.%-6.7d%+10hi9%-10su9%-1.1su%-hu%-d@98% i(u%-hd", 59252, -6551, 17631, 19632, 13171, 8932.691181166485, 30909, 797407, 26660, "[ttm", "=.-&r,zfgb8^2qsz", 992, 138772, 952464, 28205));
ck_assert_str_eq(boba5_s21, boba5);
}
END_TEST

START_TEST(bebasik__6) {
char boba6_s21[10000];
char boba6[10000];
ck_assert_int_eq(s21_sprintf(boba6_s21, "%-10.7u", 958955),
sprintf(boba6, "%-10.7u", 958955));
ck_assert_str_eq(boba6_s21, boba6);
}
END_TEST

START_TEST(bebasik__7) {
char boba7_s21[10000];
char boba7[10000];
ck_assert_int_eq(s21_sprintf(boba7_s21, "%+5.8fm$%+1hd/hs% f`i%-c,%+9.4hi`=r%-7hu%+5hi/%-hi", -4413.187962226032, -13519, -2090.66711055001, 'v', 1450, 13828, 15659, 19479),
sprintf(boba7, "%+5.8fm$%+1hd/hs% f`i%-c,%+9.4hi`=r%-7hu%+5hi/%-hi", -4413.187962226032, -13519, -2090.66711055001, 'v', 1450, 13828, 15659, 19479));
ck_assert_str_eq(boba7_s21, boba7);
}
END_TEST

START_TEST(bebasik__8) {
char boba8_s21[10000];
char boba8[10000];
ck_assert_int_eq(s21_sprintf(boba8_s21, "%-4.0hd#%-5c% 6.4d^t%+.1fq% 9d% hd%-.6hi%+2.0i% .4hdkn*%-7hd%-hi", -17222, 'h', 140980, -2154.360899926427, -188326, -11112, -3127, -231668, -19263, 17681, 11974),
sprintf(boba8, "%-4.0hd#%-5c% 6.4d^t%+.1fq% 9d% hd%-.6hi%+2.0i% .4hdkn*%-7hd%-hi", -17222, 'h', 140980, -2154.360899926427, -188326, -11112, -3127, -231668, -19263, 17681, 11974));
ck_assert_str_eq(boba8_s21, boba8);
}
END_TEST

START_TEST(bebasik__9) {
char boba9_s21[10000];
char boba9[10000];
ck_assert_int_eq(s21_sprintf(boba9_s21, "%+6dl=9`%+5.5d)756%-3s%+1i% hde%+8.6i% f% f%-6.3f% hi%+.5hd/&9%+4hd% 7hd%-uu% hdv5% 3hi% hi% 9.3hio&u%-6.2hu% 4inu2pi", 390041, -334170, "n=ylxd11", -982621, -30820, -518587, -143.13387190455714, 9514.508313795237, 8192.061981217934, 2295, -20223, 13386, 6512, 611340, -21540, 23380, -16870, 2764, -6235, -476180),
sprintf(boba9, "%+6dl=9`%+5.5d)756%-3s%+1i% hde%+8.6i% f% f%-6.3f% hi%+.5hd/&9%+4hd% 7hd%-uu% hdv5% 3hi% hi% 9.3hio&u%-6.2hu% 4inu2pi", 390041, -334170, "n=ylxd11", -982621, -30820, -518587, -143.13387190455714, 9514.508313795237, 8192.061981217934, 2295, -20223, 13386, 6512, 611340, -21540, 23380, -16870, 2764, -6235, -476180));
ck_assert_str_eq(boba9_s21, boba9);
}
END_TEST

START_TEST(bebasik__10) {
char boba10_s21[10000];
char boba10[10000];
ck_assert_int_eq(s21_sprintf(boba10_s21, "%+.0hi% .7hdb%-2.5hi%+d%-8hi=yizq%+fn;l6%+.5fd@% .3hd6ofo%+6.5hd%+1.0hdj% i% 6.0f%-4.5u5% .1hd%-5up%+5dr/=%+9.8hdsa%+7.7hd%-.9hd1% dl% .4hdk^", 15243, -4788, -26523, -524347, 17900, 10891.456959255684, 1687.4634152201197, 15882, -9415, 4767, 161988, 8685.3523286604, -439445, -15946, -866832, -493781, 536, -14152, 12439, -323464, 10913),
sprintf(boba10, "%+.0hi% .7hdb%-2.5hi%+d%-8hi=yizq%+fn;l6%+.5fd@% .3hd6ofo%+6.5hd%+1.0hdj% i% 6.0f%-4.5u5% .1hd%-5up%+5dr/=%+9.8hdsa%+7.7hd%-.9hd1% dl% .4hdk^", 15243, -4788, -26523, -524347, 17900, 10891.456959255684, 1687.4634152201197, 15882, -9415, 4767, 161988, 8685.3523286604, -439445, -15946, -866832, -493781, 536, -14152, 12439, -323464, 10913));
ck_assert_str_eq(boba10_s21, boba10);
}
END_TEST

START_TEST(bebasik__11) {
char boba11_s21[10000];
char boba11[10000];
ck_assert_int_eq(s21_sprintf(boba11_s21, "% hdc%-.6f)i%-7.5hud#% i%-hd%-hd%-fh%-.9s.% 6hi@sm^p% 10hd@%+7.7hi!% 3hd%+5.1hd", -14087, 17371.74766677995, -1488, -794247, 21748, -20377, 17155.82359664961, "so20-/0a^thcrs`(6e-5[l0=&", 15568, 17303, -1555, 18121, 3367),
sprintf(boba11, "% hdc%-.6f)i%-7.5hud#% i%-hd%-hd%-fh%-.9s.% 6hi@sm^p% 10hd@%+7.7hi!% 3hd%+5.1hd", -14087, 17371.74766677995, -1488, -794247, 21748, -20377, 17155.82359664961, "so20-/0a^thcrs`(6e-5[l0=&", 15568, 17303, -1555, 18121, 3367));
ck_assert_str_eq(boba11_s21, boba11);
}
END_TEST

START_TEST(bebasik__12) {
char boba12_s21[10000];
char boba12[10000];
ck_assert_int_eq(s21_sprintf(boba12_s21, "% 6f", -21815.87435087119),
sprintf(boba12, "% 6f", -21815.87435087119));
ck_assert_str_eq(boba12_s21, boba12);
}
END_TEST

START_TEST(bebasik__13) {
char boba13_s21[10000];
char boba13[10000];
ck_assert_int_eq(s21_sprintf(boba13_s21, "% 7.5hd6% 6.8d%+3.4i/7/#%-f%-.7i%+.9f0lt%+hdh8%-.7u% 6hi$% 2.6hd/#(%-2hu", 2867, -245274, 28296, 805.144238490317, -582138, 1452.0571728238342, -27081, 693404, -13664, 17442, -1519),
sprintf(boba13, "% 7.5hd6% 6.8d%+3.4i/7/#%-f%-.7i%+.9f0lt%+hdh8%-.7u% 6hi$% 2.6hd/#(%-2hu", 2867, -245274, 28296, 805.144238490317, -582138, 1452.0571728238342, -27081, 693404, -13664, 17442, -1519));
ck_assert_str_eq(boba13_s21, boba13);
}
END_TEST

START_TEST(bebasik__14) {
char boba14_s21[10000];
char boba14[10000];
ck_assert_int_eq(s21_sprintf(boba14_s21, "%-.7hdr%+hi%+d[n)%+.9hi% .9ik*ss% .6f% 10.5hdp% 10.0hib(d%-.6u(c%-9ia% 4d7f-% 8hi% 4.6hd$h% .3hi2g%-3iv%-2ct%-.1u%-5.10szc% 2.9hio%-.7hu% 10f6*%+1hi", -29288, 23749, -558618, 28784, 468733, 9782.792977496068, 17026, 23446, 912467, 288678, -129901, -15607, 24137, 8395, -176167, 'e', -114762, "", -28285, 17876, -19778.511459629197, 18500),
sprintf(boba14, "%-.7hdr%+hi%+d[n)%+.9hi% .9ik*ss% .6f% 10.5hdp% 10.0hib(d%-.6u(c%-9ia% 4d7f-% 8hi% 4.6hd$h% .3hi2g%-3iv%-2ct%-.1u%-5.10szc% 2.9hio%-.7hu% 10f6*%+1hi", -29288, 23749, -558618, 28784, 468733, 9782.792977496068, 17026, 23446, 912467, 288678, -129901, -15607, 24137, 8395, -176167, 'e', -114762, "", -28285, 17876, -19778.511459629197, 18500));
ck_assert_str_eq(boba14_s21, boba14);
}
END_TEST

START_TEST(bebasik__15) {
char boba15_s21[10000];
char boba15[10000];
ck_assert_int_eq(s21_sprintf(boba15_s21, "%-.1hdc^% f%+7hi% .1hi!zj%+3.3hi#0% 3.5i!%+2.5f5% .5hd/a%+1hi% fhm[l`% i%+.8hid*% it(%-2c% f%-8.1hi(2% 2.0fn%+6.1df%+.3ih%-8.4d%+.6hi&%+.4d`e", -2843, 20116.827049819138, -14215, -329, 13962, -533189, 8989.489387369613, 22327, -2249, 1204.4130398029229, -436452, -19504, 604692, 'o', -8936.334013876425, 19567, -17531.528350019722, 210039, 988752, 453843, -27537, -561424),
sprintf(boba15, "%-.1hdc^% f%+7hi% .1hi!zj%+3.3hi#0% 3.5i!%+2.5f5% .5hd/a%+1hi% fhm[l`% i%+.8hid*% it(%-2c% f%-8.1hi(2% 2.0fn%+6.1df%+.3ih%-8.4d%+.6hi&%+.4d`e", -2843, 20116.827049819138, -14215, -329, 13962, -533189, 8989.489387369613, 22327, -2249, 1204.4130398029229, -436452, -19504, 604692, 'o', -8936.334013876425, 19567, -17531.528350019722, 210039, 988752, 453843, -27537, -561424));
ck_assert_str_eq(boba15_s21, boba15);
}
END_TEST

START_TEST(bebasik__16) {
char boba16_s21[10000];
char boba16[10000];
ck_assert_int_eq(s21_sprintf(boba16_s21, "%-.5s%+2.5f% d5% 6f% 5hd50% hdz%-3.10f%-.4s5% 4hd% hd%+3hi.u=% hda% 9hd%+.9i%-hu7x%-da", "`nhe!583r6i##`eb^^r3)6kh3", -1516.2480754747157, 254374, -8485.118448155232, -21536, 18075, 5058.025782330453, "q3q*mh[f$/4`nj,zu2s7)q7vpio", 31650, -24198, -27967, 2496, -12840, -168188, -22845, 388002),
sprintf(boba16, "%-.5s%+2.5f% d5% 6f% 5hd50% hdz%-3.10f%-.4s5% 4hd% hd%+3hi.u=% hda% 9hd%+.9i%-hu7x%-da", "`nhe!583r6i##`eb^^r3)6kh3", -1516.2480754747157, 254374, -8485.118448155232, -21536, 18075, 5058.025782330453, "q3q*mh[f$/4`nj,zu2s7)q7vpio", 31650, -24198, -27967, 2496, -12840, -168188, -22845, 388002));
ck_assert_str_eq(boba16_s21, boba16);
}
END_TEST

START_TEST(bebasik__17) {
char boba17_s21[10000];
char boba17[10000];
ck_assert_int_eq(s21_sprintf(boba17_s21, "% 9f% 8hdm,%-9.10hi%-.0hu`;%+5.2hd%+9.5hd% 5d% it%+hi%-s%+.1hic", 21948.025480954424, -26576, 20564, 12509, -30784, 30961, -472170, 545147, -15398, "uj(*m!t3ojz,^d1l0u750@jb$ndl", -5594),
sprintf(boba17, "% 9f% 8hdm,%-9.10hi%-.0hu`;%+5.2hd%+9.5hd% 5d% it%+hi%-s%+.1hic", 21948.025480954424, -26576, 20564, 12509, -30784, 30961, -472170, 545147, -15398, "uj(*m!t3ojz,^d1l0u750@jb$ndl", -5594));
ck_assert_str_eq(boba17_s21, boba17);
}
END_TEST

START_TEST(bebasik__18) {
char boba18_s21[10000];
char boba18[10000];
ck_assert_int_eq(s21_sprintf(boba18_s21, "% f7% 5i% 9.0d% higiuy4)fb&4% .7hi% f", 18722.273791108084, 908551, -427242, 17908, 12976, -2978.3695460796857),
sprintf(boba18, "% f7% 5i% 9.0d% higiuy4)fb&4% .7hi% f", 18722.273791108084, 908551, -427242, 17908, 12976, -2978.3695460796857));
ck_assert_str_eq(boba18_s21, boba18);
}
END_TEST

START_TEST(bebasik__19) {
char boba19_s21[10000];
char boba19[10000];
ck_assert_int_eq(s21_sprintf(boba19_s21, "%-3hi", -16381),
sprintf(boba19, "%-3hi", -16381));
ck_assert_str_eq(boba19_s21, boba19);
}
END_TEST

START_TEST(bebasik__20) {
char boba20_s21[10000];
char boba20[10000];
ck_assert_int_eq(s21_sprintf(boba20_s21, "%-4hik% .1hiq%+hd% hd%+.2hd)%-s%+1i%-2ink%+2i&j%+9.8im&.%-.6s% 1hd%+.10d0%+hi;-0%-hd%-8hd3@%+.5du0#i% 6hd%-8hu", -7639, 8517, 513, -3821, -6618, "95buzz9lxoglmx&5he-q6`.08", 79577, -398331, 142007, -843965, "r*sz2=eh[c`", 9881, 478513, 20395, 8303, -27074, 693329, 24730, -23339),
sprintf(boba20, "%-4hik% .1hiq%+hd% hd%+.2hd)%-s%+1i%-2ink%+2i&j%+9.8im&.%-.6s% 1hd%+.10d0%+hi;-0%-hd%-8hd3@%+.5du0#i% 6hd%-8hu", -7639, 8517, 513, -3821, -6618, "95buzz9lxoglmx&5he-q6`.08", 79577, -398331, 142007, -843965, "r*sz2=eh[c`", 9881, 478513, 20395, 8303, -27074, 693329, 24730, -23339));
ck_assert_str_eq(boba20_s21, boba20);
}
END_TEST

START_TEST(bebasik__21) {
char boba21_s21[10000];
char boba21[10000];
ck_assert_int_eq(s21_sprintf(boba21_s21, "% 3d&&%-hd)!m%-hi;%+9.7hi%+.9hd)% hi1%-1hi)% i6% .1hd`%+6.1f!%+10i$b%+db%-.4f% hd9k% 9.1hi!*;%-4.9idp% 4hd3% 9fi5%+8da6% i", 957690, 20464, -11565, -16677, -8208, -21893, -8036, -630468, -26068, 290.0088969605191, -291820, 893876, -2499.0717439404684, 3200, -31946, -94273, -26813, 18689.527152627885, -644262, -194790),
sprintf(boba21, "% 3d&&%-hd)!m%-hi;%+9.7hi%+.9hd)% hi1%-1hi)% i6% .1hd`%+6.1f!%+10i$b%+db%-.4f% hd9k% 9.1hi!*;%-4.9idp% 4hd3% 9fi5%+8da6% i", 957690, 20464, -11565, -16677, -8208, -21893, -8036, -630468, -26068, 290.0088969605191, -291820, 893876, -2499.0717439404684, 3200, -31946, -94273, -26813, 18689.527152627885, -644262, -194790));
ck_assert_str_eq(boba21_s21, boba21);
}
END_TEST

START_TEST(bebasik__22) {
char boba22_s21[10000];
char boba22[10000];
ck_assert_int_eq(s21_sprintf(boba22_s21, "%+1.2d%-.9hd%+.1inw%+.10hd%+7ii% .6dki8%-d%+8.3i5i0%+4hd%+hd3%-8hu% f8f%-c;% hdo$", 979148, 21657, 306928, -13120, -695285, -594562, 998664, -306342, 20626, -1558, 29321, -6180.3819247887495, 'l', -15504),
sprintf(boba22, "%+1.2d%-.9hd%+.1inw%+.10hd%+7ii% .6dki8%-d%+8.3i5i0%+4hd%+hd3%-8hu% f8f%-c;% hdo$", 979148, 21657, 306928, -13120, -695285, -594562, 998664, -306342, 20626, -1558, 29321, -6180.3819247887495, 'l', -15504));
ck_assert_str_eq(boba22_s21, boba22);
}
END_TEST

START_TEST(bebasik__23) {
char boba23_s21[10000];
char boba23[10000];
ck_assert_int_eq(s21_sprintf(boba23_s21, "%-.1hi%+8fl%+.3f%+7.7d%-10hu%+iy% .10i;%+3i-,%-10s% 7f[6u!", -5533, 9479.885175583799, -1468.8818953529096, -446182, 13901, 942300, 351686, 420823, "fbg..x`m", 5675.450475211219),
sprintf(boba23, "%-.1hi%+8fl%+.3f%+7.7d%-10hu%+iy% .10i;%+3i-,%-10s% 7f[6u!", -5533, 9479.885175583799, -1468.8818953529096, -446182, 13901, 942300, 351686, 420823, "fbg..x`m", 5675.450475211219));
ck_assert_str_eq(boba23_s21, boba23);
}
END_TEST

START_TEST(bebasik__24) {
char boba24_s21[10000];
char boba24[10000];
ck_assert_int_eq(s21_sprintf(boba24_s21, "%+3.1hd%-s/4%+is`=", 28424, "4([6*=@ale.", -683563),
sprintf(boba24, "%+3.1hd%-s/4%+is`=", 28424, "4([6*=@ale.", -683563));
ck_assert_str_eq(boba24_s21, boba24);
}
END_TEST

START_TEST(bebasik__25) {
char boba25_s21[10000];
char boba25[10000];
ck_assert_int_eq(s21_sprintf(boba25_s21, "%+.5hi%-s*u0% 4hd% i", -30113, "l94ew;g!2f#jop7wt", 20634, -874484),
sprintf(boba25, "%+.5hi%-s*u0% 4hd% i", -30113, "l94ew;g!2f#jop7wt", 20634, -874484));
ck_assert_str_eq(boba25_s21, boba25);
}
END_TEST

START_TEST(bebasik__26) {
char boba26_s21[10000];
char boba26[10000];
ck_assert_int_eq(s21_sprintf(boba26_s21, "%+9.7d% hi7b%-.4hu[n% 9.7i%-6.4dm% hi% .9hix%+2f%+6d%+7hiv^sh% .3f=% .7hidy4-59%-.10d% 3hdg%+hd5% f% .6i37j% d", 441804, -6717, 17985, 606175, -943104, 8928, 25641, 4223.427843755521, 680417, -25892, -547.5500616130977, -17184, -568807, -27915, 17424, 936.36392912129, 721308, 262629),
sprintf(boba26, "%+9.7d% hi7b%-.4hu[n% 9.7i%-6.4dm% hi% .9hix%+2f%+6d%+7hiv^sh% .3f=% .7hidy4-59%-.10d% 3hdg%+hd5% f% .6i37j% d", 441804, -6717, 17985, 606175, -943104, 8928, 25641, 4223.427843755521, 680417, -25892, -547.5500616130977, -17184, -568807, -27915, 17424, 936.36392912129, 721308, 262629));
ck_assert_str_eq(boba26_s21, boba26);
}
END_TEST

START_TEST(bebasik__27) {
char boba27_s21[10000];
char boba27[10000];
ck_assert_int_eq(s21_sprintf(boba27_s21, "%-hi% 3.0f%+6hi9s%-5.7u%-.10f%+10hi% 3ii% hin%+1hi%-.5sw=a", 19408, -4012.6766380324448, -2802, 471500, 20786.717736649534, 18332, -859582, 20245, 14027, "y4(i1tgxb2b;*kma)8"),
sprintf(boba27, "%-hi% 3.0f%+6hi9s%-5.7u%-.10f%+10hi% 3ii% hin%+1hi%-.5sw=a", 19408, -4012.6766380324448, -2802, 471500, 20786.717736649534, 18332, -859582, 20245, 14027, "y4(i1tgxb2b;*kma)8"));
ck_assert_str_eq(boba27_s21, boba27);
}
END_TEST

START_TEST(bebasik__28) {
char boba28_s21[10000];
char boba28[10000];
ck_assert_int_eq(s21_sprintf(boba28_s21, "%+.7d!tg%-7hu1% 2.6i% 8.9f`$@%+.10i% 5.3i% 3f%+.0d% hiq4%+.5hd% 5hd", 251549, -9512, 767041, -17542.45977110538, -778626, 364774, 3852.896303686773, -247453, 19353, -25767, 27419),
sprintf(boba28, "%+.7d!tg%-7hu1% 2.6i% 8.9f`$@%+.10i% 5.3i% 3f%+.0d% hiq4%+.5hd% 5hd", 251549, -9512, 767041, -17542.45977110538, -778626, 364774, 3852.896303686773, -247453, 19353, -25767, 27419));
ck_assert_str_eq(boba28_s21, boba28);
}
END_TEST

START_TEST(bebasik__29) {
char boba29_s21[10000];
char boba29[10000];
ck_assert_int_eq(s21_sprintf(boba29_s21, "%+i%+8.2i&%+hd%-hi% 10.3hdl%+7.2f%-6c%+1.1hdig^5d% 8.1f;%-8u-/&% hi% 7i% 5hi% .8f% .6d-s%-hd", 121575, 856026, -18254, 29266, -31759, -5899.078910422103, '0', -13207, -9738.307057128894, -360328, 29239, 164442, -17491, 10035.298583435575, -457107, -24010),
sprintf(boba29, "%+i%+8.2i&%+hd%-hi% 10.3hdl%+7.2f%-6c%+1.1hdig^5d% 8.1f;%-8u-/&% hi% 7i% 5hi% .8f% .6d-s%-hd", 121575, 856026, -18254, 29266, -31759, -5899.078910422103, '0', -13207, -9738.307057128894, -360328, 29239, 164442, -17491, 10035.298583435575, -457107, -24010));
ck_assert_str_eq(boba29_s21, boba29);
}
END_TEST

START_TEST(bebasik__30) {
char boba30_s21[10000];
char boba30[10000];
ck_assert_int_eq(s21_sprintf(boba30_s21, "% .10hd%+i`o% .10d% .7i*%+.9hi36% .8hik6%+4i%+9hi=", 24448, 679543, -352959, -289629, -27648, 8793, 373477, 15366),
sprintf(boba30, "% .10hd%+i`o% .10d% .7i*%+.9hi36% .8hik6%+4i%+9hi=", 24448, 679543, -352959, -289629, -27648, 8793, 373477, 15366));
ck_assert_str_eq(boba30_s21, boba30);
}
END_TEST

START_TEST(bebasik__31) {
char boba31_s21[10000];
char boba31[10000];
ck_assert_int_eq(s21_sprintf(boba31_s21, "%+3hi5% .1hi%-.5hi%-6.5u%+hd7q% .0f%+d% .8fv^%-hd% 8.8d", -8318, -15841, 13438, 537899, -16770, 23909.07900042163, 392501, 13548.21297158123, 22263, 482675),
sprintf(boba31, "%+3hi5% .1hi%-.5hi%-6.5u%+hd7q% .0f%+d% .8fv^%-hd% 8.8d", -8318, -15841, 13438, 537899, -16770, 23909.07900042163, 392501, 13548.21297158123, 22263, 482675));
ck_assert_str_eq(boba31_s21, boba31);
}
END_TEST

START_TEST(bebasik__32) {
char boba32_s21[10000];
char boba32[10000];
ck_assert_int_eq(s21_sprintf(boba32_s21, "%+2.4hd%+8hd%-hio%+.7fhq4% fw% hi% 5.0hid%-.1fq%+.2hd%-6hi)$%+10.0i% .2hil%-4.10hd6p`% hd%-10dhj", -7983, -24540, 7500, 19213.493377404564, -5849.071243128864, -30477, 5985, 615.6090282172762, 27370, 20279, 66599, 5165, -12516, -30218, -381783),
sprintf(boba32, "%+2.4hd%+8hd%-hio%+.7fhq4% fw% hi% 5.0hid%-.1fq%+.2hd%-6hi)$%+10.0i% .2hil%-4.10hd6p`% hd%-10dhj", -7983, -24540, 7500, 19213.493377404564, -5849.071243128864, -30477, 5985, 615.6090282172762, 27370, 20279, 66599, 5165, -12516, -30218, -381783));
ck_assert_str_eq(boba32_s21, boba32);
}
END_TEST

START_TEST(bebasik__33) {
char boba33_s21[10000];
char boba33[10000];
ck_assert_int_eq(s21_sprintf(boba33_s21, "%+.0f%-1i", 10621.729337592731, -490180),
sprintf(boba33, "%+.0f%-1i", 10621.729337592731, -490180));
ck_assert_str_eq(boba33_s21, boba33);
}
END_TEST

START_TEST(bebasik__34) {
char boba34_s21[10000];
char boba34[10000];
ck_assert_int_eq(s21_sprintf(boba34_s21, "% hi7%-hdh`%-hi%-1.4d% 4hiwd;% .6d%-9i%+.0hi% .9i%-7.8hd37%-5.5hi)%+i-% 9.9i!y%-.8hi&)g`%+hd% .8hi5i,%-9.1hu%-8.0d*%-7.7uak% .9hd", 29937, -4858, -4718, -893513, -18948, -724807, 496600, 13143, 672339, 6163, -3104, 845150, 800048, 12257, 6331, -20207, -1490, 7659, 235879, -12201),
sprintf(boba34, "% hi7%-hdh`%-hi%-1.4d% 4hiwd;% .6d%-9i%+.0hi% .9i%-7.8hd37%-5.5hi)%+i-% 9.9i!y%-.8hi&)g`%+hd% .8hi5i,%-9.1hu%-8.0d*%-7.7uak% .9hd", 29937, -4858, -4718, -893513, -18948, -724807, 496600, 13143, 672339, 6163, -3104, 845150, 800048, 12257, 6331, -20207, -1490, 7659, 235879, -12201));
ck_assert_str_eq(boba34_s21, boba34);
}
END_TEST

START_TEST(bebasik__35) {
char boba35_s21[10000];
char boba35[10000];
ck_assert_int_eq(s21_sprintf(boba35_s21, "%-.1f%-.9fbqk%-1hi%+.3hix%-9f%+.8ij`%+hi%+8.10hi% .1fp%-hi% 2.8hi;%+iy4j%+6.10hdr7%-i%-10.7d%+5hi#% hd% 10f%+hi#@3=%+ii%-.3d%-9.2hi% 3.3hd%-.2hd(8z", 2052.1754707361915, 16096.716196275911, -7085, -10297, -14330.060785361586, 312343, 11981, 25422, -3654.7446697154974, -6976, 28515, -534834, -31766, 442098, -760611, -16622, 2437, 13088.457205918108, -31459, 962270, -205482, 8803, -17498, -17216),
sprintf(boba35, "%-.1f%-.9fbqk%-1hi%+.3hix%-9f%+.8ij`%+hi%+8.10hi% .1fp%-hi% 2.8hi;%+iy4j%+6.10hdr7%-i%-10.7d%+5hi#% hd% 10f%+hi#@3=%+ii%-.3d%-9.2hi% 3.3hd%-.2hd(8z", 2052.1754707361915, 16096.716196275911, -7085, -10297, -14330.060785361586, 312343, 11981, 25422, -3654.7446697154974, -6976, 28515, -534834, -31766, 442098, -760611, -16622, 2437, 13088.457205918108, -31459, 962270, -205482, 8803, -17498, -17216));
ck_assert_str_eq(boba35_s21, boba35);
}
END_TEST

START_TEST(bebasik__36) {
char boba36_s21[10000];
char boba36[10000];
ck_assert_int_eq(s21_sprintf(boba36_s21, "%-hi% 6i%+6id%-6f%-hi%+7.10hd%+4.6hi", -14349, -797180, 115969, -2174.7669399947827, 21392, 23940, 1429),
sprintf(boba36, "%-hi% 6i%+6id%-6f%-hi%+7.10hd%+4.6hi", -14349, -797180, 115969, -2174.7669399947827, 21392, 23940, 1429));
ck_assert_str_eq(boba36_s21, boba36);
}
END_TEST

START_TEST(bebasik__37) {
char boba37_s21[10000];
char boba37[10000];
ck_assert_int_eq(s21_sprintf(boba37_s21, "% .2hdiwh%-8c% 7hd.6%+3f*j% hde%+.1i`%+2hd02% f", -25138, '$', -28068, 2717.595336608615, -6042, 442595, -5873, 18217.6597148531),
sprintf(boba37, "% .2hdiwh%-8c% 7hd.6%+3f*j% hde%+.1i`%+2hd02% f", -25138, '$', -28068, 2717.595336608615, -6042, 442595, -5873, 18217.6597148531));
ck_assert_str_eq(boba37_s21, boba37);
}
END_TEST

START_TEST(bebasik__38) {
char boba38_s21[10000];
char boba38[10000];
ck_assert_int_eq(s21_sprintf(boba38_s21, "%-5.3hu%+7.6fo%+5.2hde% 9d% 8hd%-2sq% hi%-10i% 6f%-.6hu%+hd3%+2.0fxe;% 10.1d`,q*", 17393, 5496.908697572311, -1012, 655788, -14486, "&cp", -21932, -160729, 27756.26659504407, -27102, 18581, -1800.2991806191906, -602533),
sprintf(boba38, "%-5.3hu%+7.6fo%+5.2hde% 9d% 8hd%-2sq% hi%-10i% 6f%-.6hu%+hd3%+2.0fxe;% 10.1d`,q*", 17393, 5496.908697572311, -1012, 655788, -14486, "&cp", -21932, -160729, 27756.26659504407, -27102, 18581, -1800.2991806191906, -602533));
ck_assert_str_eq(boba38_s21, boba38);
}
END_TEST

START_TEST(bebasik__39) {
char boba39_s21[10000];
char boba39[10000];
ck_assert_int_eq(s21_sprintf(boba39_s21, "%-3d%+.0fb%+hi%+7hi^", -375422, 15.344805482707699, 18140, -29996),
sprintf(boba39, "%-3d%+.0fb%+hi%+7hi^", -375422, 15.344805482707699, 18140, -29996));
ck_assert_str_eq(boba39_s21, boba39);
}
END_TEST

START_TEST(bebasik__40) {
char boba40_s21[10000];
char boba40[10000];
ck_assert_int_eq(s21_sprintf(boba40_s21, "%+7.10fyi", 3285.2287386807134),
sprintf(boba40, "%+7.10fyi", 3285.2287386807134));
ck_assert_str_eq(boba40_s21, boba40);
}
END_TEST

START_TEST(bebasik__41) {
char boba41_s21[10000];
char boba41[10000];
ck_assert_int_eq(s21_sprintf(boba41_s21, "%+8i1% .1hd% .9hdg2i&/%-7.6f%+4.9f/bbj%+4f% 7.8hd% .5hdk3x=%-hi%-d% .6hi%-.1hu%+8.8i%+7.1hi1%+f[29f%-7d*%+i%+2.7hd;76%-1f%-.3d-% 4d*w&rsy% i%+7hi", 46773, 7593, 20033, -16640.22723332843, -6502.78904452315, 300.8716318375931, 828, -15098, -10154, 224905, 27184, 16734, 980393, 7016, 9801.275576490332, 964963, -812498, 10470, 14687.647445627152, -3926, -740828, -66609, -12126),
sprintf(boba41, "%+8i1% .1hd% .9hdg2i&/%-7.6f%+4.9f/bbj%+4f% 7.8hd% .5hdk3x=%-hi%-d% .6hi%-.1hu%+8.8i%+7.1hi1%+f[29f%-7d*%+i%+2.7hd;76%-1f%-.3d-% 4d*w&rsy% i%+7hi", 46773, 7593, 20033, -16640.22723332843, -6502.78904452315, 300.8716318375931, 828, -15098, -10154, 224905, 27184, 16734, 980393, 7016, 9801.275576490332, 964963, -812498, 10470, 14687.647445627152, -3926, -740828, -66609, -12126));
ck_assert_str_eq(boba41_s21, boba41);
}
END_TEST

START_TEST(bebasik__42) {
char boba42_s21[10000];
char boba42[10000];
ck_assert_int_eq(s21_sprintf(boba42_s21, "%-9.4hu%-5hi(=b&t%-6c.24)k;;%+hiuv% 9.4i%+6.10hic3% 9iz=%-.5i% .8d", 20141, 6775, '.', 27722, 472753, -20633, -334003, -938416, -210149),
sprintf(boba42, "%-9.4hu%-5hi(=b&t%-6c.24)k;;%+hiuv% 9.4i%+6.10hic3% 9iz=%-.5i% .8d", 20141, 6775, '.', 27722, 472753, -20633, -334003, -938416, -210149));
ck_assert_str_eq(boba42_s21, boba42);
}
END_TEST

START_TEST(bebasik__43) {
char boba43_s21[10000];
char boba43[10000];
ck_assert_int_eq(s21_sprintf(boba43_s21, "%+.1hiz^%-.4u%+1hi%-f%+hir%+5hdl% 2hd%+.2f% 10i%+.1hiol8%-.10s%-.8i% d%+.4hd%-.1i%-8hu% hiuq%+10.9d%+.9hd3% .4f%-5f%-5.8hu%+.0f", 21272, -489553, 17462, 2977.0593236428335, -23812, 17445, 22737, 5443.1147446479645, 153973, 29280, "se7^&hef`gtqlk*j", -363176, 684012, 4229, -577367, 1595, 24946, 780460, -26640, 11205.45089500395, -15453.311921676504, -16667, 5020.373652825655),
sprintf(boba43, "%+.1hiz^%-.4u%+1hi%-f%+hir%+5hdl% 2hd%+.2f% 10i%+.1hiol8%-.10s%-.8i% d%+.4hd%-.1i%-8hu% hiuq%+10.9d%+.9hd3% .4f%-5f%-5.8hu%+.0f", 21272, -489553, 17462, 2977.0593236428335, -23812, 17445, 22737, 5443.1147446479645, 153973, 29280, "se7^&hef`gtqlk*j", -363176, 684012, 4229, -577367, 1595, 24946, 780460, -26640, 11205.45089500395, -15453.311921676504, -16667, 5020.373652825655));
ck_assert_str_eq(boba43_s21, boba43);
}
END_TEST

START_TEST(bebasik__44) {
char boba44_s21[10000];
char boba44[10000];
ck_assert_int_eq(s21_sprintf(boba44_s21, "%-.4hu%-f&%+1hd% 6i/%-.10f%-9hd%+10.8i%-1.1hi..% 1hd%-hi%-un!%+.1hd% d5%+1.2f52&#[%-.4hdd%-.1hima;p% .3fv/-.r%+hd8tz", 31584, 1714.2120420590884, -24647, 704638, 5.8505450181248015, 11168, 47527, 5988, 6119, 6825, -825491, -686, -897798, -26156.545041511814, 3616, -3115, 8149.539090239847, 6554),
sprintf(boba44, "%-.4hu%-f&%+1hd% 6i/%-.10f%-9hd%+10.8i%-1.1hi..% 1hd%-hi%-un!%+.1hd% d5%+1.2f52&#[%-.4hdd%-.1hima;p% .3fv/-.r%+hd8tz", 31584, 1714.2120420590884, -24647, 704638, 5.8505450181248015, 11168, 47527, 5988, 6119, 6825, -825491, -686, -897798, -26156.545041511814, 3616, -3115, 8149.539090239847, 6554));
ck_assert_str_eq(boba44_s21, boba44);
}
END_TEST

START_TEST(bebasik__45) {
char boba45_s21[10000];
char boba45[10000];
ck_assert_int_eq(s21_sprintf(boba45_s21, "% dr2%+.4hi%+4.7hi)% .1hioec", 840379, -180, -28582, -19779),
sprintf(boba45, "% dr2%+.4hi%+4.7hi)% .1hioec", 840379, -180, -28582, -19779));
ck_assert_str_eq(boba45_s21, boba45);
}
END_TEST

START_TEST(bebasik__46) {
char boba46_s21[10000];
char boba46[10000];
ck_assert_int_eq(s21_sprintf(boba46_s21, "%-.7i%+.10hdy[% 4d;^% 8.9dw%-hul-%+1.3hi%+8i%-hu% hig%-6i%+7.5d.2%+.10i%-7hd.%+8d% 4f6%-8c%+4.0hiwzhs%+.4hia;)", -465047, 4629, -547424, -811280, -10534, -28066, 379208, -29934, -12315, -758709, -240308, -257233, 13868, 490646, -2044.948066941922, '0', -2712, -14489),
sprintf(boba46, "%-.7i%+.10hdy[% 4d;^% 8.9dw%-hul-%+1.3hi%+8i%-hu% hig%-6i%+7.5d.2%+.10i%-7hd.%+8d% 4f6%-8c%+4.0hiwzhs%+.4hia;)", -465047, 4629, -547424, -811280, -10534, -28066, 379208, -29934, -12315, -758709, -240308, -257233, 13868, 490646, -2044.948066941922, '0', -2712, -14489));
ck_assert_str_eq(boba46_s21, boba46);
}
END_TEST

START_TEST(bebasik__47) {
char boba47_s21[10000];
char boba47[10000];
ck_assert_int_eq(s21_sprintf(boba47_s21, "%-so%-hu(*f&%+7.1hdh%+9.0is% hd%-3.2hu%+dh&%+2.5i% hi%-.2hi% hi", "jub5ufv,k-8&@$kn*a.j*3", 26717, 11213, -411712, 21566, 142, -842255, -150844, 6019, -2431, 4589),
sprintf(boba47, "%-so%-hu(*f&%+7.1hdh%+9.0is% hd%-3.2hu%+dh&%+2.5i% hi%-.2hi% hi", "jub5ufv,k-8&@$kn*a.j*3", 26717, 11213, -411712, 21566, 142, -842255, -150844, 6019, -2431, 4589));
ck_assert_str_eq(boba47_s21, boba47);
}
END_TEST

START_TEST(bebasik__48) {
char boba48_s21[10000];
char boba48[10000];
ck_assert_int_eq(s21_sprintf(boba48_s21, "%+.3d% .4hi@% .0dc%+.3i3[%+.3hi% 9hii4,q%-3.2u", -15748, -25262, 195764, -96859, -5247, -2518, 185132),
sprintf(boba48, "%+.3d% .4hi@% .0dc%+.3i3[%+.3hi% 9hii4,q%-3.2u", -15748, -25262, 195764, -96859, -5247, -2518, 185132));
ck_assert_str_eq(boba48_s21, boba48);
}
END_TEST

START_TEST(bebasik__49) {
char boba49_s21[10000];
char boba49[10000];
ck_assert_int_eq(s21_sprintf(boba49_s21, "%-.10hi^;o%+5if%+10.7hi% .2d% .3izwa% dp%+6dj% 2.2d% 7.7hd[[%-hia%-6d$h6z% hi%-5.8hd%+8.2hi% hib%+.9hdz%+.6hd.*k% hi64e% 1.10i8/%+6.1hichl%-.7hu", -15882, 248415, 10800, 315743, -825759, 529029, -989566, -771551, 3357, 31776, -531494, 26439, 1946, -19402, -30939, 10019, 24991, 18040, -965768, 6960, -8119),
sprintf(boba49, "%-.10hi^;o%+5if%+10.7hi% .2d% .3izwa% dp%+6dj% 2.2d% 7.7hd[[%-hia%-6d$h6z% hi%-5.8hd%+8.2hi% hib%+.9hdz%+.6hd.*k% hi64e% 1.10i8/%+6.1hichl%-.7hu", -15882, 248415, 10800, 315743, -825759, 529029, -989566, -771551, 3357, 31776, -531494, 26439, 1946, -19402, -30939, 10019, 24991, 18040, -965768, 6960, -8119));
ck_assert_str_eq(boba49_s21, boba49);
}
END_TEST

START_TEST(bebasik__50) {
char boba50_s21[10000];
char boba50[10000];
ck_assert_int_eq(s21_sprintf(boba50_s21, "% hi^%+9.3hdz%+6.8f%-u%-.4i%-8.9d%-10.9hi% 5.1hdhbo%-.10dk9%+d!i% hi%-.7s%+hi% hi%-c=i% .1f% hi%+4.2hidt1% .2iq%-c", -31884, 24467, 13157.0827720297, 348821, 598972, 401111, -28686, -2506, 981311, -328781, -20181, "yy);xu=^6nyec4", -530, 26792, '4', -8812.325612036888, -21899, -20855, -56202, 't'),
sprintf(boba50, "% hi^%+9.3hdz%+6.8f%-u%-.4i%-8.9d%-10.9hi% 5.1hdhbo%-.10dk9%+d!i% hi%-.7s%+hi% hi%-c=i% .1f% hi%+4.2hidt1% .2iq%-c", -31884, 24467, 13157.0827720297, 348821, 598972, 401111, -28686, -2506, 981311, -328781, -20181, "yy);xu=^6nyec4", -530, 26792, '4', -8812.325612036888, -21899, -20855, -56202, 't'));
ck_assert_str_eq(boba50_s21, boba50);
}
END_TEST

START_TEST(bebasik__51) {
char boba51_s21[10000];
char boba51[10000];
ck_assert_int_eq(s21_sprintf(boba51_s21, "%+9.5id3%-.10hu% ig% 8d(%+i.6rj% 4.10i-g% 3.5hd", -736382, 19391, 810900, -599844, 390965, 621451, 1848),
sprintf(boba51, "%+9.5id3%-.10hu% ig% 8d(%+i.6rj% 4.10i-g% 3.5hd", -736382, 19391, 810900, -599844, 390965, 621451, 1848));
ck_assert_str_eq(boba51_s21, boba51);
}
END_TEST

START_TEST(bebasik__52) {
char boba52_s21[10000];
char boba52[10000];
ck_assert_int_eq(s21_sprintf(boba52_s21, "%+3.9i!u%-.0hi%+7hd% 8hd`% f% 5.2hd[%+.1f%+7.2hd% hiy%+.6hi%+.7fks2%+.8i7% .5hi[&8t9", -592696, 15144, 28283, -21093, 523.4438562280984, -18224, 56.762098768336344, -25863, -31873, -26112, 1168.5435669935882, 398698, 14762),
sprintf(boba52, "%+3.9i!u%-.0hi%+7hd% 8hd`% f% 5.2hd[%+.1f%+7.2hd% hiy%+.6hi%+.7fks2%+.8i7% .5hi[&8t9", -592696, 15144, 28283, -21093, 523.4438562280984, -18224, 56.762098768336344, -25863, -31873, -26112, 1168.5435669935882, 398698, 14762));
ck_assert_str_eq(boba52_s21, boba52);
}
END_TEST

START_TEST(bebasik__53) {
char boba53_s21[10000];
char boba53[10000];
ck_assert_int_eq(s21_sprintf(boba53_s21, "% d2w%-.6s% .4hi7%-3.0hd%-dyh$%-7s%+.5i%-2.0hd%+6.7d%-u% dts6% d% .1f%+9.3i%+.4i$f% hi^%-.1u%+7.1hdtkh[% f7", 71863, "[.", 30189, -9414, 309405, "61gfv/4g=e0nos", 759905, 19858, -600964, 167880, 508964, 523620, 4264.76761263375, -566897, 293887, 13485, -20754, -16397, 4285.389260292771),
sprintf(boba53, "% d2w%-.6s% .4hi7%-3.0hd%-dyh$%-7s%+.5i%-2.0hd%+6.7d%-u% dts6% d% .1f%+9.3i%+.4i$f% hi^%-.1u%+7.1hdtkh[% f7", 71863, "[.", 30189, -9414, 309405, "61gfv/4g=e0nos", 759905, 19858, -600964, 167880, 508964, 523620, 4264.76761263375, -566897, 293887, 13485, -20754, -16397, 4285.389260292771));
ck_assert_str_eq(boba53_s21, boba53);
}
END_TEST

START_TEST(bebasik__54) {
char boba54_s21[10000];
char boba54[10000];
ck_assert_int_eq(s21_sprintf(boba54_s21, "% 7.3i% .5hd%-c%+.5hdepv%-hi%+1ia% 8i%-.8u!6d8% 2ft#,j%-10.3hi%+7.10hi%-10f%+9.2hi%+hi% 5.7hdh% 10.6hd%+7i% hi3i%-2f;qzp;%+5fy2jy% .1d", -452632, -7930, 'l', 17150, -28714, -539880, -300614, 6817, 4175.465817961624, 13280, 12509, 1386.998103391888, -27058, -10096, -29485, 667, 167268, -10191, 15899.455767380596, 21900.519928170073, 357327),
sprintf(boba54, "% 7.3i% .5hd%-c%+.5hdepv%-hi%+1ia% 8i%-.8u!6d8% 2ft#,j%-10.3hi%+7.10hi%-10f%+9.2hi%+hi% 5.7hdh% 10.6hd%+7i% hi3i%-2f;qzp;%+5fy2jy% .1d", -452632, -7930, 'l', 17150, -28714, -539880, -300614, 6817, 4175.465817961624, 13280, 12509, 1386.998103391888, -27058, -10096, -29485, 667, 167268, -10191, 15899.455767380596, 21900.519928170073, 357327));
ck_assert_str_eq(boba54_s21, boba54);
}
END_TEST

START_TEST(bebasik__55) {
char boba55_s21[10000];
char boba55[10000];
ck_assert_int_eq(s21_sprintf(boba55_s21, "%-.5hd%-.4i=% 9.7ig#f%+7.2djw%+.7hi% .5hd%-fr,", 15150, -109940, 484641, -5084, -11318, 31815, -5966.80758262306),
sprintf(boba55, "%-.5hd%-.4i=% 9.7ig#f%+7.2djw%+.7hi% .5hd%-fr,", 15150, -109940, 484641, -5084, -11318, 31815, -5966.80758262306));
ck_assert_str_eq(boba55_s21, boba55);
}
END_TEST

START_TEST(bebasik__56) {
char boba56_s21[10000];
char boba56[10000];
ck_assert_int_eq(s21_sprintf(boba56_s21, "%+d%+5d%+1.4hie%-huuy% 6d[%-1.6hi[%-2.0hd%+.3d%+7.9dls% f%-.4d7%+6himl8*j9=% .10hi% 10d", 556097, -215551, 10555, 25009, 582103, -2922, -5518, 420453, -321656, -129.65898173583864, -83332, -15150, 5485, -100298),
sprintf(boba56, "%+d%+5d%+1.4hie%-huuy% 6d[%-1.6hi[%-2.0hd%+.3d%+7.9dls% f%-.4d7%+6himl8*j9=% .10hi% 10d", 556097, -215551, 10555, 25009, 582103, -2922, -5518, 420453, -321656, -129.65898173583864, -83332, -15150, 5485, -100298));
ck_assert_str_eq(boba56_s21, boba56);
}
END_TEST

START_TEST(bebasik__57) {
char boba57_s21[10000];
char boba57[10000];
ck_assert_int_eq(s21_sprintf(boba57_s21, "% d02v2%+il(% .8hdm(y*;^u!% hd% f% d7c&=%+8.7dg%-.4hi&% 8.3i08,", -173733, -365665, -2193, -30739, 22584.99626611881, -124066, 128816, 3026, 476620),
sprintf(boba57, "% d02v2%+il(% .8hdm(y*;^u!% hd% f% d7c&=%+8.7dg%-.4hi&% 8.3i08,", -173733, -365665, -2193, -30739, 22584.99626611881, -124066, 128816, 3026, 476620));
ck_assert_str_eq(boba57_s21, boba57);
}
END_TEST

START_TEST(bebasik__58) {
char boba58_s21[10000];
char boba58[10000];
ck_assert_int_eq(s21_sprintf(boba58_s21, "%+.10f5h%-9du)&%+4.8dit% 5.6d% .8f=%-6s% hd% 9.6i5%+hdm", -116.41585259749517, 370176, 117525, 95599, -8995.573703347578, "71yy!rpm)prenuonh-1x", -5259, -282459, 21676),
sprintf(boba58, "%+.10f5h%-9du)&%+4.8dit% 5.6d% .8f=%-6s% hd% 9.6i5%+hdm", -116.41585259749517, 370176, 117525, 95599, -8995.573703347578, "71yy!rpm)prenuonh-1x", -5259, -282459, 21676));
ck_assert_str_eq(boba58_s21, boba58);
}
END_TEST

START_TEST(bebasik__59) {
char boba59_s21[10000];
char boba59[10000];
ck_assert_int_eq(s21_sprintf(boba59_s21, "% 3.6fg/1fu.% .2d%+.7hi% hd)%-10hir%-7huz3a% .5hdk)%-hi%+6.3hdu,4=", 24737.8342099694, -416832, 25631, -25696, 12948, 181, 6799, -1206, 19682),
sprintf(boba59, "% 3.6fg/1fu.% .2d%+.7hi% hd)%-10hir%-7huz3a% .5hdk)%-hi%+6.3hdu,4=", 24737.8342099694, -416832, 25631, -25696, 12948, 181, 6799, -1206, 19682));
ck_assert_str_eq(boba59_s21, boba59);
}
END_TEST

START_TEST(bebasik__60) {
char boba60_s21[10000];
char boba60[10000];
ck_assert_int_eq(s21_sprintf(boba60_s21, "%-1hd%-10ddl1%+9.8hdv;%+7.6hd%+6.7ic-2k%-5.1hu,0^% 9hdi%-.0hu-vx#% hi3=%+hd%+.8fwh%+3i%+.5i%-2hu%-2hu*[", 27617, -972386, -9267, 3118, -378054, -5605, 31254, -5199, 24542, -11858, -8481.911796429018, 550849, 732270, 10736, 17039),
sprintf(boba60, "%-1hd%-10ddl1%+9.8hdv;%+7.6hd%+6.7ic-2k%-5.1hu,0^% 9hdi%-.0hu-vx#% hi3=%+hd%+.8fwh%+3i%+.5i%-2hu%-2hu*[", 27617, -972386, -9267, 3118, -378054, -5605, 31254, -5199, 24542, -11858, -8481.911796429018, 550849, 732270, 10736, 17039));
ck_assert_str_eq(boba60_s21, boba60);
}
END_TEST

START_TEST(bebasik__61) {
char boba61_s21[10000];
char boba61[10000];
ck_assert_int_eq(s21_sprintf(boba61_s21, "%-3hdoy% .8hdt% 6.2hi%+8hd%+f%+3.5hdude#9% f%+hi)% 6.3hdcb*", 181, 11444, 30772, 19110, -2587.803159455609, -12629, 11788.951347266398, -26623, -28243),
sprintf(boba61, "%-3hdoy% .8hdt% 6.2hi%+8hd%+f%+3.5hdude#9% f%+hi)% 6.3hdcb*", 181, 11444, 30772, 19110, -2587.803159455609, -12629, 11788.951347266398, -26623, -28243));
ck_assert_str_eq(boba61_s21, boba61);
}
END_TEST

START_TEST(bebasik__62) {
char boba62_s21[10000];
char boba62[10000];
ck_assert_int_eq(s21_sprintf(boba62_s21, "%+dw&%-3.0u% .4f%+.9hiqe%-.0hi%+5.4f#3%+hi9", 950834, 474126, -10643.9488666668, -14616, 3503, 2302.8129787596517, -20782),
sprintf(boba62, "%+dw&%-3.0u% .4f%+.9hiqe%-.0hi%+5.4f#3%+hi9", 950834, 474126, -10643.9488666668, -14616, 3503, 2302.8129787596517, -20782));
ck_assert_str_eq(boba62_s21, boba62);
}
END_TEST

START_TEST(bebasik__63) {
char boba63_s21[10000];
char boba63[10000];
ck_assert_int_eq(s21_sprintf(boba63_s21, "%+.4f4s)v%+.7hd%+.10hd%+hd!%-1.2hd/t%+3d7%+.10d% 2d^% 10.4d% .5hi-%+10in%-.4f-%-5.2f%-ie%+.9i%-.2ss%+3.8d% .1hd%+ikbdsn%-.5hu3t/#% hi", 2958.4105478429155, -20129, -19645, -7487, -3345, 43277, -14555, -589281, 483914, 29175, -515540, 21355.965728073068, 15470.228716063679, -507798, -883961, "aj^69j((iva)l#7=*", -127590, -20446, -375134, 18257, 30377),
sprintf(boba63, "%+.4f4s)v%+.7hd%+.10hd%+hd!%-1.2hd/t%+3d7%+.10d% 2d^% 10.4d% .5hi-%+10in%-.4f-%-5.2f%-ie%+.9i%-.2ss%+3.8d% .1hd%+ikbdsn%-.5hu3t/#% hi", 2958.4105478429155, -20129, -19645, -7487, -3345, 43277, -14555, -589281, 483914, 29175, -515540, 21355.965728073068, 15470.228716063679, -507798, -883961, "aj^69j((iva)l#7=*", -127590, -20446, -375134, 18257, 30377));
ck_assert_str_eq(boba63_s21, boba63);
}
END_TEST

START_TEST(bebasik__64) {
char boba64_s21[10000];
char boba64[10000];
ck_assert_int_eq(s21_sprintf(boba64_s21, "%-.5f% 3hi%-1i% .5hd%+5.8d%+6db%-.7hd!o%+9f%-8huy%+hd.%+9f%+10i%+hd% .1hd%-7.3hi", 745.2688055080065, 273, -361499, 28598, -918722, 975498, 22037, -8062.209944745395, -637, 21555, 1382.5447540192022, 909567, 21474, -7353, 17064),
sprintf(boba64, "%-.5f% 3hi%-1i% .5hd%+5.8d%+6db%-.7hd!o%+9f%-8huy%+hd.%+9f%+10i%+hd% .1hd%-7.3hi", 745.2688055080065, 273, -361499, 28598, -918722, 975498, 22037, -8062.209944745395, -637, 21555, 1382.5447540192022, 909567, 21474, -7353, 17064));
ck_assert_str_eq(boba64_s21, boba64);
}
END_TEST

START_TEST(bebasik__65) {
char boba65_s21[10000];
char boba65[10000];
ck_assert_int_eq(s21_sprintf(boba65_s21, "%+10d%+.4hd%+hi% 3.8hi.%-7s6c%-3hd8=%-10hd%+3d% f", 885405, 13543, -855, -333, "l&es2v5ft/zpcrkn9@", -26991, -10333, 272863, -10337.734416704707),
sprintf(boba65, "%+10d%+.4hd%+hi% 3.8hi.%-7s6c%-3hd8=%-10hd%+3d% f", 885405, 13543, -855, -333, "l&es2v5ft/zpcrkn9@", -26991, -10333, 272863, -10337.734416704707));
ck_assert_str_eq(boba65_s21, boba65);
}
END_TEST

START_TEST(bebasik__66) {
char boba66_s21[10000];
char boba66[10000];
ck_assert_int_eq(s21_sprintf(boba66_s21, "% 8.4i!% .4d%-.3hds`%+4d%+hi1%+9hd%+hd&%+4d%+8hdn%-huj7m% 3.4hi.v%-8.8hi%+hda% 9f$6%-.5hi%+.8d2% hd%+.10hi%-5hi*z% 8f^-%-9hi", 592756, 229443, -18907, -223612, -30746, -25954, -27492, 916692, 9441, 16070, -8604, -29845, 17273, 5994.319540035705, 4490, -600774, 15504, 3180, 31013, -5486.734943041114, -447),
sprintf(boba66, "% 8.4i!% .4d%-.3hds`%+4d%+hi1%+9hd%+hd&%+4d%+8hdn%-huj7m% 3.4hi.v%-8.8hi%+hda% 9f$6%-.5hi%+.8d2% hd%+.10hi%-5hi*z% 8f^-%-9hi", 592756, 229443, -18907, -223612, -30746, -25954, -27492, 916692, 9441, 16070, -8604, -29845, 17273, 5994.319540035705, 4490, -600774, 15504, 3180, 31013, -5486.734943041114, -447));
ck_assert_str_eq(boba66_s21, boba66);
}
END_TEST

START_TEST(bebasik__67) {
char boba67_s21[10000];
char boba67[10000];
ck_assert_int_eq(s21_sprintf(boba67_s21, "% hirf6e% hi% 1.5hd/s%-6hi%-.5i[%-5.4f%-hu%+3.10hdz% 8hdeqb#y%+10hd1% 2.1i@%-10hu%+3.5hig%-8hi;y% d%-c%-7d% 9.0f%-.2hu%+.5hi", 25665, -15651, 15438, -2719, -242292, 18441.677469348244, 755, 14476, 22143, 25776, -107289, -7074, 19728, -12760, 380161, '/', -157067, -7506.659546867855, -6609, -12173),
sprintf(boba67, "% hirf6e% hi% 1.5hd/s%-6hi%-.5i[%-5.4f%-hu%+3.10hdz% 8hdeqb#y%+10hd1% 2.1i@%-10hu%+3.5hig%-8hi;y% d%-c%-7d% 9.0f%-.2hu%+.5hi", 25665, -15651, 15438, -2719, -242292, 18441.677469348244, 755, 14476, 22143, 25776, -107289, -7074, 19728, -12760, 380161, '/', -157067, -7506.659546867855, -6609, -12173));
ck_assert_str_eq(boba67_s21, boba67);
}
END_TEST

START_TEST(bebasik__68) {
char boba68_s21[10000];
char boba68[10000];
ck_assert_int_eq(s21_sprintf(boba68_s21, "%-1sx% .7hi% .2d% i=% 1.9d% hi%-hu12ucy%-d%+hd%+2.3d% 2.9hd%-6dz% 10f-f%-3.1f^/%+.6hd,8kq%+9hd%-7.1uao% 2.9hi% 2d", ",3onw$$)-drm-", -12938, -638569, 932082, 355910, 31201, -22718, -268001, -12478, 995684, -17010, 320060, 1983.7664962345993, 4090.4943611547037, -12028, -3763, 577224, 29442, -661180),
sprintf(boba68, "%-1sx% .7hi% .2d% i=% 1.9d% hi%-hu12ucy%-d%+hd%+2.3d% 2.9hd%-6dz% 10f-f%-3.1f^/%+.6hd,8kq%+9hd%-7.1uao% 2.9hi% 2d", ",3onw$$)-drm-", -12938, -638569, 932082, 355910, 31201, -22718, -268001, -12478, 995684, -17010, 320060, 1983.7664962345993, 4090.4943611547037, -12028, -3763, 577224, 29442, -661180));
ck_assert_str_eq(boba68_s21, boba68);
}
END_TEST

START_TEST(bebasik__69) {
char boba69_s21[10000];
char boba69[10000];
ck_assert_int_eq(s21_sprintf(boba69_s21, "%+d%+2.0dfw-%+.8d% .0fw%+5hd% 3.10d`% 5hi% hi9o-%+.6hi% 2f8(=%+8hdp,%+2i%+hi3;%-9.3hio%-2im3s% .10dk,!j&/k-%-3.3hu4cf%+7hi[3%-5.1hd%+10hd% 6hik&n% i%-1.10hi1", -809115, -679095, -630274, -572.4829844796145, -31498, 820829, 23758, -18464, -29132, -1056.6388205650244, 8014, 65329, -20591, -30377, -624659, -847656, -23902, -23917, 2468, -21156, 21051, -28723, 7768),
sprintf(boba69, "%+d%+2.0dfw-%+.8d% .0fw%+5hd% 3.10d`% 5hi% hi9o-%+.6hi% 2f8(=%+8hdp,%+2i%+hi3;%-9.3hio%-2im3s% .10dk,!j&/k-%-3.3hu4cf%+7hi[3%-5.1hd%+10hd% 6hik&n% i%-1.10hi1", -809115, -679095, -630274, -572.4829844796145, -31498, 820829, 23758, -18464, -29132, -1056.6388205650244, 8014, 65329, -20591, -30377, -624659, -847656, -23902, -23917, 2468, -21156, 21051, -28723, 7768));
ck_assert_str_eq(boba69_s21, boba69);
}
END_TEST

START_TEST(bebasik__70) {
char boba70_s21[10000];
char boba70[10000];
ck_assert_int_eq(s21_sprintf(boba70_s21, "%-c$dt*5%-.1hdz^n%+1hi*% hd9%+8.0i%+.7dc^%-hd%-.4hd%+1f%-hd)%-hi% 5.0d-", 'w', 13731, 12405, 27479, -353609, -913189, -24740, -7261, -1695.3899114747135, 26566, 1215, -639235),
sprintf(boba70, "%-c$dt*5%-.1hdz^n%+1hi*% hd9%+8.0i%+.7dc^%-hd%-.4hd%+1f%-hd)%-hi% 5.0d-", 'w', 13731, 12405, 27479, -353609, -913189, -24740, -7261, -1695.3899114747135, 26566, 1215, -639235));
ck_assert_str_eq(boba70_s21, boba70);
}
END_TEST

START_TEST(bebasik__71) {
char boba71_s21[10000];
char boba71[10000];
ck_assert_int_eq(s21_sprintf(boba71_s21, "% 2.1hi%-hu% 2.8d% dnhk[d%-4.0fc;%+hd%+9his9%+.2hd%-f%+2hio%+10dmb% .5hi%-3.0hd0h8w% .3i[%+hd)% 3.9hd% .9fb%+6.0i%-6hd#a%-3hd%+5i%-7s%-.2u% 5.6hd[", 25857, 31101, 622385, -996248, -19796.36488075132, 3065, 4215, -5884, 14372.97508153503, -23450, -825728, -2508, 4927, -734993, 14729, 11369, 20290.97921701698, 30374, 31582, -20336, 9601, "ug/m2r0k,a7u#;*$$j7n;u", -309842, -474),
sprintf(boba71, "% 2.1hi%-hu% 2.8d% dnhk[d%-4.0fc;%+hd%+9his9%+.2hd%-f%+2hio%+10dmb% .5hi%-3.0hd0h8w% .3i[%+hd)% 3.9hd% .9fb%+6.0i%-6hd#a%-3hd%+5i%-7s%-.2u% 5.6hd[", 25857, 31101, 622385, -996248, -19796.36488075132, 3065, 4215, -5884, 14372.97508153503, -23450, -825728, -2508, 4927, -734993, 14729, 11369, 20290.97921701698, 30374, 31582, -20336, 9601, "ug/m2r0k,a7u#;*$$j7n;u", -309842, -474));
ck_assert_str_eq(boba71_s21, boba71);
}
END_TEST

START_TEST(bebasik__72) {
char boba72_s21[10000];
char boba72[10000];
ck_assert_int_eq(s21_sprintf(boba72_s21, "%+2hd%-f8-vx% hd%-hd3% .7hd%+.10hd$7-%-2hd`%-4.5hd%-1c%-5.2hu% .8hd%-1d%-8.3hi%-8hu%+hd4m% 5.1d% .2hi%+9d% 4.9hi%-.1dr", 27248, -20550.501186548157, -21563, 19109, -1438, -15293, 14480, -16961, ',', 27075, -30739, 144089, 15189, -12284, -28930, -725600, 18643, 952567, 29563, -687827),
sprintf(boba72, "%+2hd%-f8-vx% hd%-hd3% .7hd%+.10hd$7-%-2hd`%-4.5hd%-1c%-5.2hu% .8hd%-1d%-8.3hi%-8hu%+hd4m% 5.1d% .2hi%+9d% 4.9hi%-.1dr", 27248, -20550.501186548157, -21563, 19109, -1438, -15293, 14480, -16961, ',', 27075, -30739, 144089, 15189, -12284, -28930, -725600, 18643, 952567, 29563, -687827));
ck_assert_str_eq(boba72_s21, boba72);
}
END_TEST

START_TEST(bebasik__73) {
char boba73_s21[10000];
char boba73[10000];
ck_assert_int_eq(s21_sprintf(boba73_s21, "% dx;#%+1.9hi% 7hi%+hi70@% 1hi% f%+3hi% .6hd%-.7huo%-4.2u(mvvy% .0hd/0% 6hd%-.3hdz% f/%+f% hd% 2f4eob% hd%+hd^%-10.0hi$#%+hd9%-4hipo;5", 324695, 21023, -26693, 18171, 15229, 49.55384700930906, 10885, -18641, 7850, 200931, 5641, 6117, 20478, -2239.094371104838, -231.2940535554248, 27828, -5194.230934033424, -2927, 31840, 26648, 8314, -6406),
sprintf(boba73, "% dx;#%+1.9hi% 7hi%+hi70@% 1hi% f%+3hi% .6hd%-.7huo%-4.2u(mvvy% .0hd/0% 6hd%-.3hdz% f/%+f% hd% 2f4eob% hd%+hd^%-10.0hi$#%+hd9%-4hipo;5", 324695, 21023, -26693, 18171, 15229, 49.55384700930906, 10885, -18641, 7850, 200931, 5641, 6117, 20478, -2239.094371104838, -231.2940535554248, 27828, -5194.230934033424, -2927, 31840, 26648, 8314, -6406));
ck_assert_str_eq(boba73_s21, boba73);
}
END_TEST

START_TEST(bebasik__74) {
char boba74_s21[10000];
char boba74[10000];
ck_assert_int_eq(s21_sprintf(boba74_s21, "%+3.10hi%+.0hi% .7d0ane% hi4%-u`*% 2hd%-2.4hd)cg2%-2cmj=m%-9d0% .7hi8%+7.3hi% hi%+hd!f% 9hdrq-%-.6f%-.10hi%+9d%-.0dq%-8fh7% hd%-.0ss", 3407, -24377, 422023, -16004, -295064, 24784, 7287, '@', 446565, -8372, 12426, 9179, 26836, 16091, 23560.240750559376, -16322, -971827, -636618, 54.95316047541134, -30499, "xgh1z.n#.=g9^v@zs`tc."),
sprintf(boba74, "%+3.10hi%+.0hi% .7d0ane% hi4%-u`*% 2hd%-2.4hd)cg2%-2cmj=m%-9d0% .7hi8%+7.3hi% hi%+hd!f% 9hdrq-%-.6f%-.10hi%+9d%-.0dq%-8fh7% hd%-.0ss", 3407, -24377, 422023, -16004, -295064, 24784, 7287, '@', 446565, -8372, 12426, 9179, 26836, 16091, 23560.240750559376, -16322, -971827, -636618, 54.95316047541134, -30499, "xgh1z.n#.=g9^v@zs`tc."));
ck_assert_str_eq(boba74_s21, boba74);
}
END_TEST

START_TEST(bebasik__75) {
char boba75_s21[10000];
char boba75[10000];
ck_assert_int_eq(s21_sprintf(boba75_s21, "%+2hi1%+hi% 5.9hi`!% 7.10f% 7f%+3.7f21w% ie#@;", -29289, 15088, -11393, 3955.961948048896, -2092.820935602517, -21712.643097159005, -425962),
sprintf(boba75, "%+2hi1%+hi% 5.9hi`!% 7.10f% 7f%+3.7f21w% ie#@;", -29289, 15088, -11393, 3955.961948048896, -2092.820935602517, -21712.643097159005, -425962));
ck_assert_str_eq(boba75_s21, boba75);
}
END_TEST

START_TEST(bebasik__76) {
char boba76_s21[10000];
char boba76[10000];
ck_assert_int_eq(s21_sprintf(boba76_s21, "%+d1%+.5f.`=%-.10hdw", 273889, -1971.8773378832952, 14877),
sprintf(boba76, "%+d1%+.5f.`=%-.10hdw", 273889, -1971.8773378832952, 14877));
ck_assert_str_eq(boba76_s21, boba76);
}
END_TEST

START_TEST(bebasik__77) {
char boba77_s21[10000];
char boba77[10000];
ck_assert_int_eq(s21_sprintf(boba77_s21, "% 8f%-hi%-him%-3hub% 7.3hd% d%-9.2f%-hd%-.3hdb% f%+hiu-% d@*%+9hi%+f% .9hi", -809.8740020795059, -28917, -6329, 26699, -23365, -220819, 3142.3917710314718, 24798, 26398, 22273.667458320306, -28915, -708649, 1741, -26526.66382657998, -25577),
sprintf(boba77, "% 8f%-hi%-him%-3hub% 7.3hd% d%-9.2f%-hd%-.3hdb% f%+hiu-% d@*%+9hi%+f% .9hi", -809.8740020795059, -28917, -6329, 26699, -23365, -220819, 3142.3917710314718, 24798, 26398, 22273.667458320306, -28915, -708649, 1741, -26526.66382657998, -25577));
ck_assert_str_eq(boba77_s21, boba77);
}
END_TEST

START_TEST(bebasik__78) {
char boba78_s21[10000];
char boba78[10000];
ck_assert_int_eq(s21_sprintf(boba78_s21, "%+9f-%+i% 7hi%-.5hi`5% 3i% i% 6.4hd%+3i%-.8dz% hi,", 11226.043844620173, -886742, -7217, -186, -405431, -627063, -8303, -98526, 634628, -5243),
sprintf(boba78, "%+9f-%+i% 7hi%-.5hi`5% 3i% i% 6.4hd%+3i%-.8dz% hi,", 11226.043844620173, -886742, -7217, -186, -405431, -627063, -8303, -98526, 634628, -5243));
ck_assert_str_eq(boba78_s21, boba78);
}
END_TEST

START_TEST(bebasik__79) {
char boba79_s21[10000];
char boba79[10000];
ck_assert_int_eq(s21_sprintf(boba79_s21, "% .10hd*%+5.1i6% .5f%+10hd% 1hi%-1.1hi% 8.7d!2;%+8.1d%-.3hda% 5.10i%+4.3i%-10hi%+hi!%-5.6hdb% 9f)[z% i%+3.0hi`(% .8ddfn&%-5.5hu", -8999, -930626, 11134.628312975818, 16716, -21346, -26349, 903544, -366112, -5558, 352994, 814784, 511, 28230, -13371, 500.62015821668655, 149088, 1240, -58557, 22879),
sprintf(boba79, "% .10hd*%+5.1i6% .5f%+10hd% 1hi%-1.1hi% 8.7d!2;%+8.1d%-.3hda% 5.10i%+4.3i%-10hi%+hi!%-5.6hdb% 9f)[z% i%+3.0hi`(% .8ddfn&%-5.5hu", -8999, -930626, 11134.628312975818, 16716, -21346, -26349, 903544, -366112, -5558, 352994, 814784, 511, 28230, -13371, 500.62015821668655, 149088, 1240, -58557, 22879));
ck_assert_str_eq(boba79_s21, boba79);
}
END_TEST

START_TEST(bebasik__80) {
char boba80_s21[10000];
char boba80[10000];
ck_assert_int_eq(s21_sprintf(boba80_s21, "%-.5so%+d% 6.6hd9512)0ml%-6hu2", "hq&&-$gi2x3", 411685, 9626, 31567),
sprintf(boba80, "%-.5so%+d% 6.6hd9512)0ml%-6hu2", "hq&&-$gi2x3", 411685, 9626, 31567));
ck_assert_str_eq(boba80_s21, boba80);
}
END_TEST

START_TEST(bebasik__81) {
char boba81_s21[10000];
char boba81[10000];
ck_assert_int_eq(s21_sprintf(boba81_s21, "%+7.0f`(% 7.0hd% hd$%+3hd%-hi%+d%-fk% 5.5hd%+3.10hd%-.2hi#rh% 1.8hi%-9io%-.0iplu%+.3hi% .6hi%-6hu% 10.3i;`", -7453.491833044842, 13550, 20762, -26688, 8920, -938574, 8954.885375430988, 31101, -7067, -22602, 23121, 426856, -923119, -7187, -11304, -821, 279324),
sprintf(boba81, "%+7.0f`(% 7.0hd% hd$%+3hd%-hi%+d%-fk% 5.5hd%+3.10hd%-.2hi#rh% 1.8hi%-9io%-.0iplu%+.3hi% .6hi%-6hu% 10.3i;`", -7453.491833044842, 13550, 20762, -26688, 8920, -938574, 8954.885375430988, 31101, -7067, -22602, 23121, 426856, -923119, -7187, -11304, -821, 279324));
ck_assert_str_eq(boba81_s21, boba81);
}
END_TEST

START_TEST(bebasik__82) {
char boba82_s21[10000];
char boba82[10000];
ck_assert_int_eq(s21_sprintf(boba82_s21, "%+1hir`%-hd% f%+.8hd% 1hd%-s%+f4/1", 23492, -2834, -7061.774044479174, -28896, -5013, "/.;dq&k(qq1v7j&n!8dw7o9u`j0*", 17586.7086791474),
sprintf(boba82, "%+1hir`%-hd% f%+.8hd% 1hd%-s%+f4/1", 23492, -2834, -7061.774044479174, -28896, -5013, "/.;dq&k(qq1v7j&n!8dw7o9u`j0*", 17586.7086791474));
ck_assert_str_eq(boba82_s21, boba82);
}
END_TEST

START_TEST(bebasik__83) {
char boba83_s21[10000];
char boba83[10000];
ck_assert_int_eq(s21_sprintf(boba83_s21, "% .6f%-6d%+2.9fn2% d%+.5fm%+6.5ih%+.5ive% 9hd% 8d%-6u^%+6.7hd[5", -19426.812099904368, -557368, 1491.4452402774423, 668318, -4886.467209521433, -432854, -39606, -8138, 481682, 517589, 27927),
sprintf(boba83, "% .6f%-6d%+2.9fn2% d%+.5fm%+6.5ih%+.5ive% 9hd% 8d%-6u^%+6.7hd[5", -19426.812099904368, -557368, 1491.4452402774423, 668318, -4886.467209521433, -432854, -39606, -8138, 481682, 517589, 27927));
ck_assert_str_eq(boba83_s21, boba83);
}
END_TEST

START_TEST(bebasik__84) {
char boba84_s21[10000];
char boba84[10000];
ck_assert_int_eq(s21_sprintf(boba84_s21, "%+.8f%+4i% 1hdey% 9i% hi;g%-2hi%-.0f=p%+i%+.7f% 7.1ij%-.1s%+7.7d%-4dx%+2i*=7", 1513.3413543896052, 341096, -30918, -668701, 19889, 13383, -14865.89983465888, -307238, -1858.601743508791, -490453, "0egw9ossd0m,b()5k6a", 130367, 990692, 941409),
sprintf(boba84, "%+.8f%+4i% 1hdey% 9i% hi;g%-2hi%-.0f=p%+i%+.7f% 7.1ij%-.1s%+7.7d%-4dx%+2i*=7", 1513.3413543896052, 341096, -30918, -668701, 19889, 13383, -14865.89983465888, -307238, -1858.601743508791, -490453, "0egw9ossd0m,b()5k6a", 130367, 990692, 941409));
ck_assert_str_eq(boba84_s21, boba84);
}
END_TEST

START_TEST(bebasik__85) {
char boba85_s21[10000];
char boba85[10000];
ck_assert_int_eq(s21_sprintf(boba85_s21, "%+.1hi% hd5%-5.7hitdd%-5hd%+d,r(@%-6hi%-8.5hij%-5.10iu@r%-.10hd(lok5)%-.8hdj)c%+4hih&*q%-hi% 9.5hd% .8hi.i1%+hi%+5d% 4hig%+hist%+10hd%+10.6f%-.5hd% hd#", -7630, -10639, -2328, 22493, -65268, 25177, 17723, 791535, 2834, 30843, 15038, -23628, -9087, -31370, -21092, 205556, -21218, -14064, -13249, 712.906532862939, 5486, -17075),
sprintf(boba85, "%+.1hi% hd5%-5.7hitdd%-5hd%+d,r(@%-6hi%-8.5hij%-5.10iu@r%-.10hd(lok5)%-.8hdj)c%+4hih&*q%-hi% 9.5hd% .8hi.i1%+hi%+5d% 4hig%+hist%+10hd%+10.6f%-.5hd% hd#", -7630, -10639, -2328, 22493, -65268, 25177, 17723, 791535, 2834, 30843, 15038, -23628, -9087, -31370, -21092, 205556, -21218, -14064, -13249, 712.906532862939, 5486, -17075));
ck_assert_str_eq(boba85_s21, boba85);
}
END_TEST

START_TEST(bebasik__86) {
char boba86_s21[10000];
char boba86[10000];
ck_assert_int_eq(s21_sprintf(boba86_s21, "% i% 4hd2%-dr7%-.4fo^ur8kif^% 8.2hi% hd%+hi% 10.6i%+9.3hd% 2hi%+3.7hi%+.4hi%+.9hiu@ia%+1.10i/r% is%-.2hi7!aji%+10.9hi%+4.7hiey3%-.4his%+2.4hip&j%+.1hd%+.0hic", -531167, -15567, 714149, 25047.839249483415, 26129, 9902, -25994, 853683, -24237, 26582, 22146, -12935, 13076, -934341, -72336, 12832, 24556, 7081, -1717, 6150, 3194, -23199),
sprintf(boba86, "% i% 4hd2%-dr7%-.4fo^ur8kif^% 8.2hi% hd%+hi% 10.6i%+9.3hd% 2hi%+3.7hi%+.4hi%+.9hiu@ia%+1.10i/r% is%-.2hi7!aji%+10.9hi%+4.7hiey3%-.4his%+2.4hip&j%+.1hd%+.0hic", -531167, -15567, 714149, 25047.839249483415, 26129, 9902, -25994, 853683, -24237, 26582, 22146, -12935, 13076, -934341, -72336, 12832, 24556, 7081, -1717, 6150, 3194, -23199));
ck_assert_str_eq(boba86_s21, boba86);
}
END_TEST

START_TEST(bebasik__87) {
char boba87_s21[10000];
char boba87[10000];
ck_assert_int_eq(s21_sprintf(boba87_s21, "%+1.0f%-3c%+d&m8%+is9m.,u%+8i[@% 1ip%-ir%-6hi2%+hi%-4.2hi% 1.9i%-9u%-s%-hdu%-.3hu% fyb% 8fp7%-7.6f0a", 18097.794162350325, 'y', 755787, -572109, 923980, 175253, 981268, 1406, -24602, 20717, -94982, -717430, "@*k", 15185, -21928, -21219.83852444426, -17373.795730306352, 2303.194423439862),
sprintf(boba87, "%+1.0f%-3c%+d&m8%+is9m.,u%+8i[@% 1ip%-ir%-6hi2%+hi%-4.2hi% 1.9i%-9u%-s%-hdu%-.3hu% fyb% 8fp7%-7.6f0a", 18097.794162350325, 'y', 755787, -572109, 923980, 175253, 981268, 1406, -24602, 20717, -94982, -717430, "@*k", 15185, -21928, -21219.83852444426, -17373.795730306352, 2303.194423439862));
ck_assert_str_eq(boba87_s21, boba87);
}
END_TEST

START_TEST(bebasik__88) {
char boba88_s21[10000];
char boba88[10000];
ck_assert_int_eq(s21_sprintf(boba88_s21, "%-5hd%+.7hd%-c% .1hi5%+4.2hi$[1%-8.7huc% .6hirys%-8u% i%-hif%+5ibe% .6hi% hd%-hu%+hd%-10.8d#% hir%-9hd0% 10d%+f%-5hig(,.dk%-6s%+8.3f^2,7% f1/[wf", 22190, -23296, '`', 24450, 17973, -91, 16784, 827592, -501279, -20467, 65230, 2181, 14054, 15701, 13453, 608824, -20773, -23135, -770117, -24449.242032139522, 6687, ")km-$69*0fgpl/d6,cx*hv!b", 15.783772896043935, 1407.1892870082636),
sprintf(boba88, "%-5hd%+.7hd%-c% .1hi5%+4.2hi$[1%-8.7huc% .6hirys%-8u% i%-hif%+5ibe% .6hi% hd%-hu%+hd%-10.8d#% hir%-9hd0% 10d%+f%-5hig(,.dk%-6s%+8.3f^2,7% f1/[wf", 22190, -23296, '`', 24450, 17973, -91, 16784, 827592, -501279, -20467, 65230, 2181, 14054, 15701, 13453, 608824, -20773, -23135, -770117, -24449.242032139522, 6687, ")km-$69*0fgpl/d6,cx*hv!b", 15.783772896043935, 1407.1892870082636));
ck_assert_str_eq(boba88_s21, boba88);
}
END_TEST

START_TEST(bebasik__89) {
char boba89_s21[10000];
char boba89[10000];
ck_assert_int_eq(s21_sprintf(boba89_s21, "%+1hd)k,.a% .3hdo%+5.10hix;)%+4d% .7i%+hi5u%-.6u%+3dq%-7s% 7.10hi% 5d%-d%+.4hirhk% .2hd0i^%-4.5hd% 7.0hd%+5dx!s", -12306, -14397, -11093, 606169, -912963, -14370, 547179, -422863, "^8ah[!", -27839, 628199, -982778, -26016, 1759, -15819, 7196, -889157),
sprintf(boba89, "%+1hd)k,.a% .3hdo%+5.10hix;)%+4d% .7i%+hi5u%-.6u%+3dq%-7s% 7.10hi% 5d%-d%+.4hirhk% .2hd0i^%-4.5hd% 7.0hd%+5dx!s", -12306, -14397, -11093, 606169, -912963, -14370, 547179, -422863, "^8ah[!", -27839, 628199, -982778, -26016, 1759, -15819, 7196, -889157));
ck_assert_str_eq(boba89_s21, boba89);
}
END_TEST

START_TEST(bebasik__90) {
char boba90_s21[10000];
char boba90[10000];
ck_assert_int_eq(s21_sprintf(boba90_s21, "%+5.4hi6#%-3.0u^% .3hi[k% hd-%+hdxmw%+.0hd%-3f% .10d% 9.10hd@%+5.6ia% 7.3hi9=n% hib% 8hi-8%-.0f% .0i% 4hd%-5c%+10.8i%+3i%-io%-2uu#", 12811, 800834, 23118, 13239, -13963, -1174, 6661.227611089721, 901837, 26597, -575259, 23894, -18412, -4405, -18686.22888044884, 709155, -26885, 'o', 369315, -783530, 693275, 61183),
sprintf(boba90, "%+5.4hi6#%-3.0u^% .3hi[k% hd-%+hdxmw%+.0hd%-3f% .10d% 9.10hd@%+5.6ia% 7.3hi9=n% hib% 8hi-8%-.0f% .0i% 4hd%-5c%+10.8i%+3i%-io%-2uu#", 12811, 800834, 23118, 13239, -13963, -1174, 6661.227611089721, 901837, 26597, -575259, 23894, -18412, -4405, -18686.22888044884, 709155, -26885, 'o', 369315, -783530, 693275, 61183));
ck_assert_str_eq(boba90_s21, boba90);
}
END_TEST

START_TEST(bebasik__91) {
char boba91_s21[10000];
char boba91[10000];
ck_assert_int_eq(s21_sprintf(boba91_s21, "%+1.6hi`%+hd,cc%-.7fn%-.10d;%-i% hd% hi%-hi%-.6s%+5.5hd% i%+5d%-5.4hu%-3hi%+d% hio@)31wa", 20567, -1775, -4998.3560516316775, -909248, -372872, 26683, 25039, 31072, "bd93pbuyp`33y[i[.g,", -28189, -790144, -623038, -5658, 7873, 687899, 17063),
sprintf(boba91, "%+1.6hi`%+hd,cc%-.7fn%-.10d;%-i% hd% hi%-hi%-.6s%+5.5hd% i%+5d%-5.4hu%-3hi%+d% hio@)31wa", 20567, -1775, -4998.3560516316775, -909248, -372872, 26683, 25039, 31072, "bd93pbuyp`33y[i[.g,", -28189, -790144, -623038, -5658, 7873, 687899, 17063));
ck_assert_str_eq(boba91_s21, boba91);
}
END_TEST

START_TEST(bebasik__92) {
char boba92_s21[10000];
char boba92[10000];
ck_assert_int_eq(s21_sprintf(boba92_s21, "%-.1hia97-w;%-.8hu6%+4.3i[w%-d9bj%-5uv%+hi% 6.2i% 3hi&%+9.6f%-9.6i%-8i", 2207, 1889, 728954, -949859, -792169, -12325, -543898, -9713, -27211.720057658626, 461463, -558834),
sprintf(boba92, "%-.1hia97-w;%-.8hu6%+4.3i[w%-d9bj%-5uv%+hi% 6.2i% 3hi&%+9.6f%-9.6i%-8i", 2207, 1889, 728954, -949859, -792169, -12325, -543898, -9713, -27211.720057658626, 461463, -558834));
ck_assert_str_eq(boba92_s21, boba92);
}
END_TEST

START_TEST(bebasik__93) {
char boba93_s21[10000];
char boba93[10000];
ck_assert_int_eq(s21_sprintf(boba93_s21, "%-him50d%+10hd% .9f%-.0hu%+5dw%-hi%-.2s%-.9s8m% 4d^6*g% ia.%-.7hu%+10.7d%+hd%-.0d%+hd%+iwo5%+i3,`", 26092, 14575, -6944.714981488643, -14778, -808565, 26131, "b,&-bi#s!7^z.bi*jp", "o#88lb!l*h", -133228, -313343, 2018, -750704, -25497, 247905, -2473, 437357, -984895),
sprintf(boba93, "%-him50d%+10hd% .9f%-.0hu%+5dw%-hi%-.2s%-.9s8m% 4d^6*g% ia.%-.7hu%+10.7d%+hd%-.0d%+hd%+iwo5%+i3,`", 26092, 14575, -6944.714981488643, -14778, -808565, 26131, "b,&-bi#s!7^z.bi*jp", "o#88lb!l*h", -133228, -313343, 2018, -750704, -25497, 247905, -2473, 437357, -984895));
ck_assert_str_eq(boba93_s21, boba93);
}
END_TEST

START_TEST(bebasik__94) {
char boba94_s21[10000];
char boba94[10000];
ck_assert_int_eq(s21_sprintf(boba94_s21, "%-2.1u%+2hd/", -375998, 13106),
sprintf(boba94, "%-2.1u%+2hd/", -375998, 13106));
ck_assert_str_eq(boba94_s21, boba94);
}
END_TEST

START_TEST(bebasik__95) {
char boba95_s21[10000];
char boba95[10000];
ck_assert_int_eq(s21_sprintf(boba95_s21, "%+8.9hi(%+i=% .1d%-8.1uvx)%-.7f%-9hu%-.4hi%-.2hu.$ym%-.10uh=%+.6hd!", -27709, -127713, -420225, -816989, 4996.879161138565, 28624, 16281, -2505, -434881, -27781),
sprintf(boba95, "%+8.9hi(%+i=% .1d%-8.1uvx)%-.7f%-9hu%-.4hi%-.2hu.$ym%-.10uh=%+.6hd!", -27709, -127713, -420225, -816989, 4996.879161138565, 28624, 16281, -2505, -434881, -27781));
ck_assert_str_eq(boba95_s21, boba95);
}
END_TEST

START_TEST(bebasik__96) {
char boba96_s21[10000];
char boba96[10000];
ck_assert_int_eq(s21_sprintf(boba96_s21, "%+.8d;f7x% 1.6hd0z%+i%+.8hi`% hd$% .10f66", 778516, 30522, -154463, -549, 30172, -4128.39243270629),
sprintf(boba96, "%+.8d;f7x% 1.6hd0z%+i%+.8hi`% hd$% .10f66", 778516, 30522, -154463, -549, 30172, -4128.39243270629));
ck_assert_str_eq(boba96_s21, boba96);
}
END_TEST

START_TEST(bebasik__97) {
char boba97_s21[10000];
char boba97[10000];
ck_assert_int_eq(s21_sprintf(boba97_s21, "%-.6i%+d%-5s", 722898, 76729, "=opl&vhtg)*zl^54"),
sprintf(boba97, "%-.6i%+d%-5s", 722898, 76729, "=opl&vhtg)*zl^54"));
ck_assert_str_eq(boba97_s21, boba97);
}
END_TEST

START_TEST(bebasik__98) {
char boba98_s21[10000];
char boba98[10000];
ck_assert_int_eq(s21_sprintf(boba98_s21, "% hi%+9dc((0%+3d%+4hd$)%-7hi%+3.3ijs=", 24319, -359727, -489889, -26944, 13729, -991872),
sprintf(boba98, "% hi%+9dc((0%+3d%+4hd$)%-7hi%+3.3ijs=", 24319, -359727, -489889, -26944, 13729, -991872));
ck_assert_str_eq(boba98_s21, boba98);
}
END_TEST

START_TEST(bebasik__99) {
char boba99_s21[10000];
char boba99[10000];
ck_assert_int_eq(s21_sprintf(boba99_s21, "% iu(% f%+d%+10hd%-10.7u% 10hd% f%-.9s%+9.6hi3)egw#%-f&% .4d[%+hd% 8.1hikrlh1%-i%-.0huzqo% 6hi%+.1hd", 572008, -6796.304125928208, 743263, 3716, -956054, 12608, -7870.438006683553, "i$", 14478, -6477.359160163775, -984947, -29983, -24247, -543728, 15227, 21440, 17067),
sprintf(boba99, "% iu(% f%+d%+10hd%-10.7u% 10hd% f%-.9s%+9.6hi3)egw#%-f&% .4d[%+hd% 8.1hikrlh1%-i%-.0huzqo% 6hi%+.1hd", 572008, -6796.304125928208, 743263, 3716, -956054, 12608, -7870.438006683553, "i$", 14478, -6477.359160163775, -984947, -29983, -24247, -543728, 15227, 21440, 17067));
ck_assert_str_eq(boba99_s21, boba99);
}
END_TEST

START_TEST(bebasik__100) {
char boba100_s21[10000];
char boba100[10000];
ck_assert_int_eq(s21_sprintf(boba100_s21, "% 10.3hdb%-7hum%-.1hddw%+5.6hi%+.3hibn5%+2.2f% 8.9d%+7hi%-.5uk%+if`%+2.5dzr%+.0f%-5.5hu%-s%-4hd", 26259, 29821, -12789, -3695, -2715, -19240.74715595902, 831492, -8163, 627605, 312051, 156152, 7879.448130337436, -27615, "q[kpw!/o0a[&2)qg9;q;u`px", 7879),
sprintf(boba100, "% 10.3hdb%-7hum%-.1hddw%+5.6hi%+.3hibn5%+2.2f% 8.9d%+7hi%-.5uk%+if`%+2.5dzr%+.0f%-5.5hu%-s%-4hd", 26259, 29821, -12789, -3695, -2715, -19240.74715595902, 831492, -8163, 627605, 312051, 156152, 7879.448130337436, -27615, "q[kpw!/o0a[&2)qg9;q;u`px", 7879));
ck_assert_str_eq(boba100_s21, boba100);
}
END_TEST

START_TEST(bebasik__101) {
char boba101_s21[10000];
char boba101[10000];
ck_assert_int_eq(s21_sprintf(boba101_s21, "% .5hi=)%-.4hijf%-2hu%+1i%-.2hut6l%-.6s-*%+1hi%-10hu% 6d% .1ij=%+10hiu%+7.2i%+de% hi%+6i", -27574, -12164, 11719, 622214, 27125, ")@#,$y8;;,22s)gafj5", 21426, -30508, 512556, -200808, -21571, 319031, 893621, -31791, -521893),
sprintf(boba101, "% .5hi=)%-.4hijf%-2hu%+1i%-.2hut6l%-.6s-*%+1hi%-10hu% 6d% .1ij=%+10hiu%+7.2i%+de% hi%+6i", -27574, -12164, 11719, 622214, 27125, ")@#,$y8;;,22s)gafj5", 21426, -30508, 512556, -200808, -21571, 319031, 893621, -31791, -521893));
ck_assert_str_eq(boba101_s21, boba101);
}
END_TEST

START_TEST(bebasik__102) {
char boba102_s21[10000];
char boba102[10000];
ck_assert_int_eq(s21_sprintf(boba102_s21, "%+.8hi%+.2higtg% 6dh%+.7hd% .10i%-5.8hu%-.4hd[%-.4u%+fopzs% 1.4hin%+1.5il*% d% .8hd%+4hi% .0ix)% .5hd9j.`%-9.9hu% hd%-3.6hd%+4.0f*&", 3367, -30625, -609543, 27299, 730431, 27800, -25834, -929099, 21634.256387490703, 22406, -209893, 740519, -1752, 3511, 50656, 24823, -13255, 6078, -28317, 4896.2227856787085),
sprintf(boba102, "%+.8hi%+.2higtg% 6dh%+.7hd% .10i%-5.8hu%-.4hd[%-.4u%+fopzs% 1.4hin%+1.5il*% d% .8hd%+4hi% .0ix)% .5hd9j.`%-9.9hu% hd%-3.6hd%+4.0f*&", 3367, -30625, -609543, 27299, 730431, 27800, -25834, -929099, 21634.256387490703, 22406, -209893, 740519, -1752, 3511, 50656, 24823, -13255, 6078, -28317, 4896.2227856787085));
ck_assert_str_eq(boba102_s21, boba102);
}
END_TEST

START_TEST(bebasik__103) {
char boba103_s21[10000];
char boba103[10000];
ck_assert_int_eq(s21_sprintf(boba103_s21, "%+1hd%+8hd%+hix%+.4d7p%+.4hi", -11042, -21229, 6808, 582204, 27672),
sprintf(boba103, "%+1hd%+8hd%+hix%+.4d7p%+.4hi", -11042, -21229, 6808, 582204, 27672));
ck_assert_str_eq(boba103_s21, boba103);
}
END_TEST

START_TEST(bebasik__104) {
char boba104_s21[10000];
char boba104[10000];
ck_assert_int_eq(s21_sprintf(boba104_s21, "%+.6f2%+7d%+6hi%-6.6d^%+10hi% .2hdp% 5i%-.7hi(%-.5fi% 5.9hd% hid% 10hd9%-2.3hd%-cq%+1i%+f%+6.6dv4%+f%-hi&%-2.9fb[c%+him%-5.9hu", -17397.664214017466, -826415, -8739, -482467, -10227, 25239, -832791, 16485, -20526.585390696262, -28938, 3550, -5512, -26819, 'e', 531990, -4691.978498458463, -45782, -12856.838617427786, -27331, -4868.019197715373, -18984, -19145),
sprintf(boba104, "%+.6f2%+7d%+6hi%-6.6d^%+10hi% .2hdp% 5i%-.7hi(%-.5fi% 5.9hd% hid% 10hd9%-2.3hd%-cq%+1i%+f%+6.6dv4%+f%-hi&%-2.9fb[c%+him%-5.9hu", -17397.664214017466, -826415, -8739, -482467, -10227, 25239, -832791, 16485, -20526.585390696262, -28938, 3550, -5512, -26819, 'e', 531990, -4691.978498458463, -45782, -12856.838617427786, -27331, -4868.019197715373, -18984, -19145));
ck_assert_str_eq(boba104_s21, boba104);
}
END_TEST

START_TEST(bebasik__105) {
char boba105_s21[10000];
char boba105[10000];
ck_assert_int_eq(s21_sprintf(boba105_s21, "% 6.2futv% .4hi7%+hi=% 5hii3%+.4hd!", 615.8533845672663, 11142, 2660, -16033, 30857),
sprintf(boba105, "% 6.2futv% .4hi7%+hi=% 5hii3%+.4hd!", 615.8533845672663, 11142, 2660, -16033, 30857));
ck_assert_str_eq(boba105_s21, boba105);
}
END_TEST

START_TEST(bebasik__106) {
char boba106_s21[10000];
char boba106[10000];
ck_assert_int_eq(s21_sprintf(boba106_s21, "%-hu", 20446),
sprintf(boba106, "%-hu", 20446));
ck_assert_str_eq(boba106_s21, boba106);
}
END_TEST

START_TEST(bebasik__107) {
char boba107_s21[10000];
char boba107[10000];
ck_assert_int_eq(s21_sprintf(boba107_s21, "% hi%-1hugy%+7hi#j%+9hiom%-s%+f%+hi% 8hi%-1c% 9hi%+.3f9o&% 7.8hi%+.7hi;9g% 9f%-.10hi63%-9.4hdi6%-5hi", -16777, -9827, -575, 16963, "h9f&5[ax79m/ph14z(", 7567.170509466131, -293, -24335, '!', -21392, 13895.742805160315, 31531, 5505, -9618.29716713469, -1236, 15691, 960),
sprintf(boba107, "% hi%-1hugy%+7hi#j%+9hiom%-s%+f%+hi% 8hi%-1c% 9hi%+.3f9o&% 7.8hi%+.7hi;9g% 9f%-.10hi63%-9.4hdi6%-5hi", -16777, -9827, -575, 16963, "h9f&5[ax79m/ph14z(", 7567.170509466131, -293, -24335, '!', -21392, 13895.742805160315, 31531, 5505, -9618.29716713469, -1236, 15691, 960));
ck_assert_str_eq(boba107_s21, boba107);
}
END_TEST

START_TEST(bebasik__108) {
char boba108_s21[10000];
char boba108[10000];
ck_assert_int_eq(s21_sprintf(boba108_s21, "%-i/% f% .8hd[%+6hd*[1c%+.2f7#%+.3f9q*%-.3u% hi%-d%+.2dp%+i%-8.9s9%-6.7u", 817751, -21211.912208322086, 7445, 15951, -22510.941999754185, 631.0331105213462, 403523, 2845, 547406, 387269, 861142, "xx5@9", -318388),
sprintf(boba108, "%-i/% f% .8hd[%+6hd*[1c%+.2f7#%+.3f9q*%-.3u% hi%-d%+.2dp%+i%-8.9s9%-6.7u", 817751, -21211.912208322086, 7445, 15951, -22510.941999754185, 631.0331105213462, 403523, 2845, 547406, 387269, 861142, "xx5@9", -318388));
ck_assert_str_eq(boba108_s21, boba108);
}
END_TEST

START_TEST(bebasik__109) {
char boba109_s21[10000];
char boba109[10000];
ck_assert_int_eq(s21_sprintf(boba109_s21, "%-hd%+4.6hi)% .6ipk1;m% 4hd%-2.6hi0%-c^% hiq", -6019, 13652, 336362, -13300, 18600, '9', 21469),
sprintf(boba109, "%-hd%+4.6hi)% .6ipk1;m% 4hd%-2.6hi0%-c^% hiq", -6019, 13652, 336362, -13300, 18600, '9', 21469));
ck_assert_str_eq(boba109_s21, boba109);
}
END_TEST

START_TEST(bebasik__110) {
char boba110_s21[10000];
char boba110[10000];
ck_assert_int_eq(s21_sprintf(boba110_s21, "%+7.2hi% 9i% .2d06%+7dnp% 3.1hi% .5d%+9.5f% 8hd%-5hi%+f!%-3.4u[[/g%+2hi;q%-4hi%-dm3%-s%-6.1s%+f.%-.8iidg%-.5hiw%+5hde%-.4i%-.3hu@/38", 15771, 271414, -891599, 506428, -2137, 62870, -26640.192199674795, 18456, 11579, 53.82275998133366, -779777, 7647, -9651, 553580, "6fqxk6d2(.9;)4db(", "4`4p,0w2", 9215.914599442767, -18993, -23302, -31728, 61522, 18264),
sprintf(boba110, "%+7.2hi% 9i% .2d06%+7dnp% 3.1hi% .5d%+9.5f% 8hd%-5hi%+f!%-3.4u[[/g%+2hi;q%-4hi%-dm3%-s%-6.1s%+f.%-.8iidg%-.5hiw%+5hde%-.4i%-.3hu@/38", 15771, 271414, -891599, 506428, -2137, 62870, -26640.192199674795, 18456, 11579, 53.82275998133366, -779777, 7647, -9651, 553580, "6fqxk6d2(.9;)4db(", "4`4p,0w2", 9215.914599442767, -18993, -23302, -31728, 61522, 18264));
ck_assert_str_eq(boba110_s21, boba110);
}
END_TEST

START_TEST(bebasik__111) {
char boba111_s21[10000];
char boba111[10000];
ck_assert_int_eq(s21_sprintf(boba111_s21, "%+3.6f6%+hipwj% .1hit-% .8i%+hi(/u4%-.0hie%+d1%-d%+9.5hd`", 3999.9845936611846, -22817, 29022, 244832, -28796, 31584, -847607, -434103, -27773),
sprintf(boba111, "%+3.6f6%+hipwj% .1hit-% .8i%+hi(/u4%-.0hie%+d1%-d%+9.5hd`", 3999.9845936611846, -22817, 29022, 244832, -28796, 31584, -847607, -434103, -27773));
ck_assert_str_eq(boba111_s21, boba111);
}
END_TEST

START_TEST(bebasik__112) {
char boba112_s21[10000];
char boba112[10000];
ck_assert_int_eq(s21_sprintf(boba112_s21, "% .3i%+3.0hi%-2hds(x% 2.9hi#%+.10i% 8.2hi`%+.1hi% i/0%+6.8hi%-2iv% .7f%-hir*%-1.8hu*j7b%-10.1s% 4hd%-6.5hu0%-hd% 2.0i%-3hu%-hd3%-6.9him!% hi%-hdi1s,*=6%+.8his", 887465, 25802, -17492, -31357, 150906, -31187, 2420, 95305, 6339, 511688, 552.9638769764153, 15522, 18574, "h4u&7k2rq9@vq`()f", 14869, -20898, -27537, 779040, 6731, -26978, -30700, 26512, 30127, -12075),
sprintf(boba112, "% .3i%+3.0hi%-2hds(x% 2.9hi#%+.10i% 8.2hi`%+.1hi% i/0%+6.8hi%-2iv% .7f%-hir*%-1.8hu*j7b%-10.1s% 4hd%-6.5hu0%-hd% 2.0i%-3hu%-hd3%-6.9him!% hi%-hdi1s,*=6%+.8his", 887465, 25802, -17492, -31357, 150906, -31187, 2420, 95305, 6339, 511688, 552.9638769764153, 15522, 18574, "h4u&7k2rq9@vq`()f", 14869, -20898, -27537, 779040, 6731, -26978, -30700, 26512, 30127, -12075));
ck_assert_str_eq(boba112_s21, boba112);
}
END_TEST

START_TEST(bebasik__113) {
char boba113_s21[10000];
char boba113[10000];
ck_assert_int_eq(s21_sprintf(boba113_s21, "%+.0hib%+4.3hd% .8f% .9hdvqg%+.2hd%-.3hd%+4d% .10hie%+f%-.6i%-4hu2/%-hd!2;%-7hu(% 7d%+.1i%-hd`[k% 7.8hd% hdw3%-5.8i%-.1s0%+9i% 6hd2*%-.5hu", 5741, -21552, -15306.937501112445, 30619, 10298, -10316, -403888, -18664, -3596.4495045327694, -846192, -12014, -29783, 17963, 92614, -154489, -4132, -25417, 13078, -358509, "t^f4-$ae6tyr;a`", 426661, 4060, -25242),
sprintf(boba113, "%+.0hib%+4.3hd% .8f% .9hdvqg%+.2hd%-.3hd%+4d% .10hie%+f%-.6i%-4hu2/%-hd!2;%-7hu(% 7d%+.1i%-hd`[k% 7.8hd% hdw3%-5.8i%-.1s0%+9i% 6hd2*%-.5hu", 5741, -21552, -15306.937501112445, 30619, 10298, -10316, -403888, -18664, -3596.4495045327694, -846192, -12014, -29783, 17963, 92614, -154489, -4132, -25417, 13078, -358509, "t^f4-$ae6tyr;a`", 426661, 4060, -25242));
ck_assert_str_eq(boba113_s21, boba113);
}
END_TEST

START_TEST(bebasik__114) {
char boba114_s21[10000];
char boba114[10000];
ck_assert_int_eq(s21_sprintf(boba114_s21, "%+1ff`f9% hi/%+5.7d% 3.7hdqt% i&-/%-7.7hdl% .10hi%-3hi/d% 6.6iq%-.6hul% 3d#%-.10hd0% 9hd% de/%-.0hi%+10hd% .7i", -9651.084958386498, -12210, 886115, 30420, 278615, -22642, 13461, 19855, -39414, 9394, 381808, -4100, -5740, -174361, -6128, 26828, -564166),
sprintf(boba114, "%+1ff`f9% hi/%+5.7d% 3.7hdqt% i&-/%-7.7hdl% .10hi%-3hi/d% 6.6iq%-.6hul% 3d#%-.10hd0% 9hd% de/%-.0hi%+10hd% .7i", -9651.084958386498, -12210, 886115, 30420, 278615, -22642, 13461, 19855, -39414, 9394, 381808, -4100, -5740, -174361, -6128, 26828, -564166));
ck_assert_str_eq(boba114_s21, boba114);
}
END_TEST

START_TEST(bebasik__115) {
char boba115_s21[10000];
char boba115[10000];
ck_assert_int_eq(s21_sprintf(boba115_s21, "% 6.1hi%-.6hd%-f#% 2.2hd%-4.4ic7[% 6.4fn%-4hi% 5hi", 10603, -14755, 24848.304511902465, 12596, 860749, 5296.465717349738, 1718, -29982),
sprintf(boba115, "% 6.1hi%-.6hd%-f#% 2.2hd%-4.4ic7[% 6.4fn%-4hi% 5hi", 10603, -14755, 24848.304511902465, 12596, 860749, 5296.465717349738, 1718, -29982));
ck_assert_str_eq(boba115_s21, boba115);
}
END_TEST

START_TEST(bebasik__116) {
char boba116_s21[10000];
char boba116[10000];
ck_assert_int_eq(s21_sprintf(boba116_s21, "%-.5f% 5hdqh% 10i%+1.4hi%-hu%+.8hi%-.6hd45%-4.0f8s%+4hd%+3f%+f%-.7d%+i,%-9.2fx%+9i%+7fc% .2i$%+10.9hiq%-1.4dtp", -14359.59320412247, 15818, 694243, -11436, -23745, -15504, 10333, -2210.3914161185235, -22999, 6158.83165480872, 7037.667986969673, -870262, 697284, -11669.640743223523, 462429, -438.4106966867137, 827279, -22389, 14967),
sprintf(boba116, "%-.5f% 5hdqh% 10i%+1.4hi%-hu%+.8hi%-.6hd45%-4.0f8s%+4hd%+3f%+f%-.7d%+i,%-9.2fx%+9i%+7fc% .2i$%+10.9hiq%-1.4dtp", -14359.59320412247, 15818, 694243, -11436, -23745, -15504, 10333, -2210.3914161185235, -22999, 6158.83165480872, 7037.667986969673, -870262, 697284, -11669.640743223523, 462429, -438.4106966867137, 827279, -22389, 14967));
ck_assert_str_eq(boba116_s21, boba116);
}
END_TEST

START_TEST(bebasik__117) {
char boba117_s21[10000];
char boba117[10000];
ck_assert_int_eq(s21_sprintf(boba117_s21, "% 1hi%-9.7hu*% 2hixa%+i)%+2.7ds", 14619, -28073, 10079, 123005, 335517),
sprintf(boba117, "% 1hi%-9.7hu*% 2hixa%+i)%+2.7ds", 14619, -28073, 10079, 123005, 335517));
ck_assert_str_eq(boba117_s21, boba117);
}
END_TEST

START_TEST(bebasik__118) {
char boba118_s21[10000];
char boba118[10000];
ck_assert_int_eq(s21_sprintf(boba118_s21, "% 6.3his%-7.1hi$%-u%-3hd%+.1hi/9%-5hi%+i@[%-7.4s", 21136, 28225, -787339, -22666, 18664, 25180, -100236, "x/2v#fevk`sd)$p06`"),
sprintf(boba118, "% 6.3his%-7.1hi$%-u%-3hd%+.1hi/9%-5hi%+i@[%-7.4s", 21136, 28225, -787339, -22666, 18664, 25180, -100236, "x/2v#fevk`sd)$p06`"));
ck_assert_str_eq(boba118_s21, boba118);
}
END_TEST

START_TEST(bebasik__119) {
char boba119_s21[10000];
char boba119[10000];
ck_assert_int_eq(s21_sprintf(boba119_s21, "% 1.8ia%-.8hi%+1.3d% .0i% deh%+4hd%-c%-.4hi4d%+hi[% ipa.%+hi%+hi%-c% 6.0i%-.6iy@o%-4.5hd% .0hd=% 6hdw%-hue@%+4fh", -400230, -2606, -860786, 862305, -111584, 21751, '&', -18117, -26788, -6637, -4684, -11021, '#', -994672, -979048, 130, 13529, 31358, -14921, 3485.4172682151866),
sprintf(boba119, "% 1.8ia%-.8hi%+1.3d% .0i% deh%+4hd%-c%-.4hi4d%+hi[% ipa.%+hi%+hi%-c% 6.0i%-.6iy@o%-4.5hd% .0hd=% 6hdw%-hue@%+4fh", -400230, -2606, -860786, 862305, -111584, 21751, '&', -18117, -26788, -6637, -4684, -11021, '#', -994672, -979048, 130, 13529, 31358, -14921, 3485.4172682151866));
ck_assert_str_eq(boba119_s21, boba119);
}
END_TEST

START_TEST(bebasik__120) {
char boba120_s21[10000];
char boba120[10000];
ck_assert_int_eq(s21_sprintf(boba120_s21, "%+8hd", 4669),
sprintf(boba120, "%+8hd", 4669));
ck_assert_str_eq(boba120_s21, boba120);
}
END_TEST

START_TEST(bebasik__121) {
char boba121_s21[10000];
char boba121[10000];
ck_assert_int_eq(s21_sprintf(boba121_s21, "% 7hi=2=/%-.7hu7&v`^5%+.0d%+8hd%+hi% .0d% .0i", 27357, 27938, 293445, 26302, -31802, 764764, -956111),
sprintf(boba121, "% 7hi=2=/%-.7hu7&v`^5%+.0d%+8hd%+hi% .0d% .0i", 27357, 27938, 293445, 26302, -31802, 764764, -956111));
ck_assert_str_eq(boba121_s21, boba121);
}
END_TEST

START_TEST(bebasik__122) {
char boba122_s21[10000];
char boba122[10000];
ck_assert_int_eq(s21_sprintf(boba122_s21, "%+.0hd^1*qmd%+10.6hd7%-.0iim%+6hi6%-10f%+2hdd%-5d%+1d-% .3hdvavt%+10hi% .7d%-5hik=npujm%-d.%-10.3u%-.4huw% 1hd%+2.2hd%-.1hi`p%-s%+.6d% 5d%-8ij&%+fa% .4f", 26920, 19767, 427849, 29069, 15533.193021795192, -3833, -18780, 498767, 46, 8685, 281278, -3068, -856145, 842040, -31957, -21243, 10928, -302, "g.kay7g^iw=4b18@9-[dd", 189201, -969080, -91086, -24349.68808049874, 12256.929535175728),
sprintf(boba122, "%+.0hd^1*qmd%+10.6hd7%-.0iim%+6hi6%-10f%+2hdd%-5d%+1d-% .3hdvavt%+10hi% .7d%-5hik=npujm%-d.%-10.3u%-.4huw% 1hd%+2.2hd%-.1hi`p%-s%+.6d% 5d%-8ij&%+fa% .4f", 26920, 19767, 427849, 29069, 15533.193021795192, -3833, -18780, 498767, 46, 8685, 281278, -3068, -856145, 842040, -31957, -21243, 10928, -302, "g.kay7g^iw=4b18@9-[dd", 189201, -969080, -91086, -24349.68808049874, 12256.929535175728));
ck_assert_str_eq(boba122_s21, boba122);
}
END_TEST

START_TEST(bebasik__123) {
char boba123_s21[10000];
char boba123[10000];
ck_assert_int_eq(s21_sprintf(boba123_s21, "%-2.4hu2$%-3c%-10s3[r% 7.9hi4%+2.5hd%+hd%-hik", -720, 'v', "^0yo7#0*8q96h)*0o9jl", -22619, -23526, 28880, 10195),
sprintf(boba123, "%-2.4hu2$%-3c%-10s3[r% 7.9hi4%+2.5hd%+hd%-hik", -720, 'v', "^0yo7#0*8q96h)*0o9jl", -22619, -23526, 28880, 10195));
ck_assert_str_eq(boba123_s21, boba123);
}
END_TEST

START_TEST(bebasik__124) {
char boba124_s21[10000];
char boba124[10000];
ck_assert_int_eq(s21_sprintf(boba124_s21, "%+de%+10.10i%+.6d4%+9.6hd0%-9u&,p%+hd%-10f/% 4.8i% 1f=%-.0d%-6hu%-2hu% fp% 5.0d% 6.1d%-hiz6%-6.10i%-1.1u%+10.10hd.2%+2.6d% 10hd.ju% 7.2hi;s8q0", -423869, 322154, -759142, -17973, -319116, -25321, 2398.7412474388075, -154008, -19091.914114241616, 133330, 28348, -10050, -2742.5281841961864, -734946, -461736, 15490, -573115, 632419, 2570, -986117, 10274, 3258),
sprintf(boba124, "%+de%+10.10i%+.6d4%+9.6hd0%-9u&,p%+hd%-10f/% 4.8i% 1f=%-.0d%-6hu%-2hu% fp% 5.0d% 6.1d%-hiz6%-6.10i%-1.1u%+10.10hd.2%+2.6d% 10hd.ju% 7.2hi;s8q0", -423869, 322154, -759142, -17973, -319116, -25321, 2398.7412474388075, -154008, -19091.914114241616, 133330, 28348, -10050, -2742.5281841961864, -734946, -461736, 15490, -573115, 632419, 2570, -986117, 10274, 3258));
ck_assert_str_eq(boba124_s21, boba124);
}
END_TEST

START_TEST(bebasik__125) {
char boba125_s21[10000];
char boba125[10000];
ck_assert_int_eq(s21_sprintf(boba125_s21, "%-4.8d%+7hd%-9.4uy", -40683, 7034, -975677),
sprintf(boba125, "%-4.8d%+7hd%-9.4uy", -40683, 7034, -975677));
ck_assert_str_eq(boba125_s21, boba125);
}
END_TEST

START_TEST(bebasik__126) {
char boba126_s21[10000];
char boba126[10000];
ck_assert_int_eq(s21_sprintf(boba126_s21, "% 6i%+.0hd%+.9d% .1hi%-6hi^%-2.6su%+10.2hd%+6hi)%+4d% .6hd%-4.4hd% .3hdn% .0hd%+hdp*%-.1f4% 10fc%+.4d%+5i7am", -555565, 11216, 876222, -1757, -22097, "))0;^r3-^", -18654, -31561, 641371, 15919, 6239, 31949, -23198, 1076, 1907.6690758502525, -3292.853369760725, -40986, 476730),
sprintf(boba126, "% 6i%+.0hd%+.9d% .1hi%-6hi^%-2.6su%+10.2hd%+6hi)%+4d% .6hd%-4.4hd% .3hdn% .0hd%+hdp*%-.1f4% 10fc%+.4d%+5i7am", -555565, 11216, 876222, -1757, -22097, "))0;^r3-^", -18654, -31561, 641371, 15919, 6239, 31949, -23198, 1076, 1907.6690758502525, -3292.853369760725, -40986, 476730));
ck_assert_str_eq(boba126_s21, boba126);
}
END_TEST

START_TEST(bebasik__127) {
char boba127_s21[10000];
char boba127[10000];
ck_assert_int_eq(s21_sprintf(boba127_s21, "% 8.4hd%-hd% i%+.0hip%+6hi`%+1.1d1%-huy%-4.1u%+10.0hi%+9.7f% 10hdc", 29020, 17878, 116331, -10514, -1402, 566586, 17298, 180138, -5018, 21604.0030744508, 22435),
sprintf(boba127, "% 8.4hd%-hd% i%+.0hip%+6hi`%+1.1d1%-huy%-4.1u%+10.0hi%+9.7f% 10hdc", 29020, 17878, 116331, -10514, -1402, 566586, 17298, 180138, -5018, 21604.0030744508, 22435));
ck_assert_str_eq(boba127_s21, boba127);
}
END_TEST

START_TEST(bebasik__128) {
char boba128_s21[10000];
char boba128[10000];
ck_assert_int_eq(s21_sprintf(boba128_s21, "% i%-3.6f(% 1.5i% .1fx1%+3.4f%-.0hur% 2.0hiz1/% 4hd%-3.7hi^%+3dg%+1.4hd-b% 7.5f%+f% 1.2dz%+6i%+.0hiz*", 732530, -5910.878522977763, 153371, 22620.355458356033, -7712.492060006194, 21948, 31029, -17961, -29943, 230021, 11466, 26878.939682489105, 11435.173322001752, -625323, 241465, -27754),
sprintf(boba128, "% i%-3.6f(% 1.5i% .1fx1%+3.4f%-.0hur% 2.0hiz1/% 4hd%-3.7hi^%+3dg%+1.4hd-b% 7.5f%+f% 1.2dz%+6i%+.0hiz*", 732530, -5910.878522977763, 153371, 22620.355458356033, -7712.492060006194, 21948, 31029, -17961, -29943, 230021, 11466, 26878.939682489105, 11435.173322001752, -625323, 241465, -27754));
ck_assert_str_eq(boba128_s21, boba128);
}
END_TEST

START_TEST(bebasik__129) {
char boba129_s21[10000];
char boba129[10000];
ck_assert_int_eq(s21_sprintf(boba129_s21, "% .2hdw*(q% .5f% 1d$% .4hdwitr%+1hd%-9f", 29886, 3730.426342316792, 850685, -10843, -24251, 259.9547923474403),
sprintf(boba129, "% .2hdw*(q% .5f% 1d$% .4hdwitr%+1hd%-9f", 29886, 3730.426342316792, 850685, -10843, -24251, 259.9547923474403));
ck_assert_str_eq(boba129_s21, boba129);
}
END_TEST

START_TEST(bebasik__130) {
char boba130_s21[10000];
char boba130[10000];
ck_assert_int_eq(s21_sprintf(boba130_s21, "% 5.6hd% hi%-s.% 3i%+8d% .4hi", -20489, -2573, "/=0=2(-=;dv`", -310626, 835770, -12721),
sprintf(boba130, "% 5.6hd% hi%-s.% 3i%+8d% .4hi", -20489, -2573, "/=0=2(-=;dv`", -310626, 835770, -12721));
ck_assert_str_eq(boba130_s21, boba130);
}
END_TEST

START_TEST(bebasik__131) {
char boba131_s21[10000];
char boba131[10000];
ck_assert_int_eq(s21_sprintf(boba131_s21, "%-hd% .3hd[`%-5hd%-hu0% .10i%-.4hu)%+i% d% .5f`% i4% 6.7hd8ep%+4.10d%-.7hi%-2.5hdx% 1.0hi%-.7d%-1hd% 10hi%+.8hd%-f%+10i%-1.2u3&a/%-10s%-6hu`", -16184, 23107, 31199, -29238, 241990, 15528, 444970, 328597, 2543.4802370162056, 317529, -25152, -983007, 13173, -12976, -20582, -927128, 23911, 17018, 19886, -20537.57308316649, -168165, -415392, "j.gcx8==5lzos", -16690),
sprintf(boba131, "%-hd% .3hd[`%-5hd%-hu0% .10i%-.4hu)%+i% d% .5f`% i4% 6.7hd8ep%+4.10d%-.7hi%-2.5hdx% 1.0hi%-.7d%-1hd% 10hi%+.8hd%-f%+10i%-1.2u3&a/%-10s%-6hu`", -16184, 23107, 31199, -29238, 241990, 15528, 444970, 328597, 2543.4802370162056, 317529, -25152, -983007, 13173, -12976, -20582, -927128, 23911, 17018, 19886, -20537.57308316649, -168165, -415392, "j.gcx8==5lzos", -16690));
ck_assert_str_eq(boba131_s21, boba131);
}
END_TEST

START_TEST(bebasik__132) {
char boba132_s21[10000];
char boba132[10000];
ck_assert_int_eq(s21_sprintf(boba132_s21, "%+8.6f,d%+9.10hiv%+7hi%-.0u%-8.5i% .9fw% hdq4% 8.8isj`%+d%+.8f%+d%-.7d^%+.7dw%-s% d% .8hi% hdn%+.9d@", 36.778256633478335, 12162, -8460, -539173, -913400, -13846.478709461984, 14497, -361757, 623365, 7481.5237811722745, -450986, -954483, 216296, "$#t$llf9gvp;4wi#6tm3i75*i", -300883, -11694, 9674, 407665),
sprintf(boba132, "%+8.6f,d%+9.10hiv%+7hi%-.0u%-8.5i% .9fw% hdq4% 8.8isj`%+d%+.8f%+d%-.7d^%+.7dw%-s% d% .8hi% hdn%+.9d@", 36.778256633478335, 12162, -8460, -539173, -913400, -13846.478709461984, 14497, -361757, 623365, 7481.5237811722745, -450986, -954483, 216296, "$#t$llf9gvp;4wi#6tm3i75*i", -300883, -11694, 9674, 407665));
ck_assert_str_eq(boba132_s21, boba132);
}
END_TEST

START_TEST(bebasik__133) {
char boba133_s21[10000];
char boba133[10000];
ck_assert_int_eq(s21_sprintf(boba133_s21, "% 9hi% 1d% .6ii%-4hd=^% 3.1hiqo%-.9d8r%+6hd%+.8hij%+hi% f%+4.6f%-hiinums/u%+.9hi%+1.4i%-5.2s", 2744, 656458, -533292, 11630, -7499, -161620, -29515, 19156, -27720, 16914.685116687422, -20519.146125488052, 5063, -13778, 84021, "/954olew;i2v)y)"),
sprintf(boba133, "% 9hi% 1d% .6ii%-4hd=^% 3.1hiqo%-.9d8r%+6hd%+.8hij%+hi% f%+4.6f%-hiinums/u%+.9hi%+1.4i%-5.2s", 2744, 656458, -533292, 11630, -7499, -161620, -29515, 19156, -27720, 16914.685116687422, -20519.146125488052, 5063, -13778, 84021, "/954olew;i2v)y)"));
ck_assert_str_eq(boba133_s21, boba133);
}
END_TEST

START_TEST(bebasik__134) {
char boba134_s21[10000];
char boba134[10000];
ck_assert_int_eq(s21_sprintf(boba134_s21, "% 2hd% 4hd%-s8", -15019, 3211, "`bc4f6fy-l/nh)(/t=z3pk"),
sprintf(boba134, "% 2hd% 4hd%-s8", -15019, 3211, "`bc4f6fy-l/nh)(/t=z3pk"));
ck_assert_str_eq(boba134_s21, boba134);
}
END_TEST

START_TEST(bebasik__135) {
char boba135_s21[10000];
char boba135[10000];
ck_assert_int_eq(s21_sprintf(boba135_s21, "% .1f%+7d$% hdb%-.8i8sk% hiy% .5d,%+hi6", 3134.3527747346493, 663115, -29631, 749405, 9546, -245920, 15659),
sprintf(boba135, "% .1f%+7d$% hdb%-.8i8sk% hiy% .5d,%+hi6", 3134.3527747346493, 663115, -29631, 749405, 9546, -245920, 15659));
ck_assert_str_eq(boba135_s21, boba135);
}
END_TEST

START_TEST(bebasik__136) {
char boba136_s21[10000];
char boba136[10000];
ck_assert_int_eq(s21_sprintf(boba136_s21, "%+9hd% 8hd% .9hdd%+9.5du%-2.4hu%-2.7sn% 1.2hd%+9hd/%-4u% 7f@@-p98%-10f[%+3.1hi%+.0d% hi%-8.7s=[*%+6hiv%+hd", -8110, 31042, 1669, -787079, 24398, "", -31934, -28262, 598224, 4025.27252394391, -528.3964926581943, 24391, -308040, -14461, "n!xyz`@jn5,!5*^1w", -25613, 20040),
sprintf(boba136, "%+9hd% 8hd% .9hdd%+9.5du%-2.4hu%-2.7sn% 1.2hd%+9hd/%-4u% 7f@@-p98%-10f[%+3.1hi%+.0d% hi%-8.7s=[*%+6hiv%+hd", -8110, 31042, 1669, -787079, 24398, "", -31934, -28262, 598224, 4025.27252394391, -528.3964926581943, 24391, -308040, -14461, "n!xyz`@jn5,!5*^1w", -25613, 20040));
ck_assert_str_eq(boba136_s21, boba136);
}
END_TEST

START_TEST(bebasik__137) {
char boba137_s21[10000];
char boba137[10000];
ck_assert_int_eq(s21_sprintf(boba137_s21, "%+.6hdx%+fy% 1i% 6.6d%+f*% 1.7dt% 6.3d[h%-10i%-.3hd%-.8i%+d%-4hd% 1.7hdt(u%+2hi% .2d%+4.6hiq%+.0f-)b% i%-4hime%+dk", -19844, -889.1327550018111, -719505, 126456, 1713.0167515645178, -363436, -192615, 273433, -17833, -419815, 604025, 23870, 6394, -18227, -203920, -9669, 2342.8065207871105, -911825, -25767, 634901),
sprintf(boba137, "%+.6hdx%+fy% 1i% 6.6d%+f*% 1.7dt% 6.3d[h%-10i%-.3hd%-.8i%+d%-4hd% 1.7hdt(u%+2hi% .2d%+4.6hiq%+.0f-)b% i%-4hime%+dk", -19844, -889.1327550018111, -719505, 126456, 1713.0167515645178, -363436, -192615, 273433, -17833, -419815, 604025, 23870, 6394, -18227, -203920, -9669, 2342.8065207871105, -911825, -25767, 634901));
ck_assert_str_eq(boba137_s21, boba137);
}
END_TEST

START_TEST(bebasik__138) {
char boba138_s21[10000];
char boba138[10000];
ck_assert_int_eq(s21_sprintf(boba138_s21, "% .1hd% 10d%-c%+8dg%+hi74z%-.7hdr%-.5d%-6.7hdn%+8f%+.7hi5% 9hik%-5csv1%+hi.%+4.4f1%-8.8hu%+6.6hd%-2.4hu*1% 9.5hdp-", -23048, 558510, '@', -700904, 28905, -16815, 806703, -16640, 11183.045114672288, -14156, 15605, '=', -7959, 587.0804312398514, -25524, -16856, -2224, 31212),
sprintf(boba138, "% .1hd% 10d%-c%+8dg%+hi74z%-.7hdr%-.5d%-6.7hdn%+8f%+.7hi5% 9hik%-5csv1%+hi.%+4.4f1%-8.8hu%+6.6hd%-2.4hu*1% 9.5hdp-", -23048, 558510, '@', -700904, 28905, -16815, 806703, -16640, 11183.045114672288, -14156, 15605, '=', -7959, 587.0804312398514, -25524, -16856, -2224, 31212));
ck_assert_str_eq(boba138_s21, boba138);
}
END_TEST

START_TEST(bebasik__139) {
char boba139_s21[10000];
char boba139[10000];
ck_assert_int_eq(s21_sprintf(boba139_s21, "% .0hd%-c% 7.6hd#%-7.6hii% 4hdqq% hi^sa", 18102, '7', -25298, 6622, 12740, 9397),
sprintf(boba139, "% .0hd%-c% 7.6hd#%-7.6hii% 4hdqq% hi^sa", 18102, '7', -25298, 6622, 12740, 9397));
ck_assert_str_eq(boba139_s21, boba139);
}
END_TEST

START_TEST(bebasik__140) {
char boba140_s21[10000];
char boba140[10000];
ck_assert_int_eq(s21_sprintf(boba140_s21, "%-7.5i7%+1d% d$%-4dck%-.2hd% 3hd%+.1hi%+7fz%+hi5;g% 4.0iubk3t%-.8hi%-3imxg", -516448, 783334, -647582, 417163, 27989, -8515, -10704, 2890.8714501176814, -6244, -749879, -19383, -823703),
sprintf(boba140, "%-7.5i7%+1d% d$%-4dck%-.2hd% 3hd%+.1hi%+7fz%+hi5;g% 4.0iubk3t%-.8hi%-3imxg", -516448, 783334, -647582, 417163, 27989, -8515, -10704, 2890.8714501176814, -6244, -749879, -19383, -823703));
ck_assert_str_eq(boba140_s21, boba140);
}
END_TEST

START_TEST(bebasik__141) {
char boba141_s21[10000];
char boba141[10000];
ck_assert_int_eq(s21_sprintf(boba141_s21, "%+i.vfuj%+5hiz%+hi;-[%+2.4hii%-5.5hi%-8s[%+.4hit%+f%+3f3t%+i%-.4uf% .7i(%+1f)t/#% hi% 10.4f% 9i", 462087, 11040, 18383, 10873, 22131, "0*lofdj;sfswwt7;![x^^n22c8b", 18985, 2427.8305267870837, -10741.953772389019, 821712, 83319, -818324, -3844.581515647627, -4575, -3959.601346047871, -176865),
sprintf(boba141, "%+i.vfuj%+5hiz%+hi;-[%+2.4hii%-5.5hi%-8s[%+.4hit%+f%+3f3t%+i%-.4uf% .7i(%+1f)t/#% hi% 10.4f% 9i", 462087, 11040, 18383, 10873, 22131, "0*lofdj;sfswwt7;![x^^n22c8b", 18985, 2427.8305267870837, -10741.953772389019, 821712, 83319, -818324, -3844.581515647627, -4575, -3959.601346047871, -176865));
ck_assert_str_eq(boba141_s21, boba141);
}
END_TEST

START_TEST(bebasik__142) {
char boba142_s21[10000];
char boba142[10000];
ck_assert_int_eq(s21_sprintf(boba142_s21, "%-4hd0t%-sdj%-7.2d$y9%-d%-2.8hdu#%+f%-hij#8x%-.4hi`;%-2.2hd%+5.8d-@$% f", -31184, "/hzmrv", -532329, 179788, 7748, -11851.182469573163, 23395, 30493, 7218, -575946, -10715.510098011464),
sprintf(boba142, "%-4hd0t%-sdj%-7.2d$y9%-d%-2.8hdu#%+f%-hij#8x%-.4hi`;%-2.2hd%+5.8d-@$% f", -31184, "/hzmrv", -532329, 179788, 7748, -11851.182469573163, 23395, 30493, 7218, -575946, -10715.510098011464));
ck_assert_str_eq(boba142_s21, boba142);
}
END_TEST

START_TEST(bebasik__143) {
char boba143_s21[10000];
char boba143[10000];
ck_assert_int_eq(s21_sprintf(boba143_s21, "%-hi% 10i%+.5i% 2.9f@% i%-hi-%-1.2hd%-9.2hu`2%+.10d=@%+4.3hi/%-.3dx*% 10f-", 24154, -523408, 870169, 4334.747366106868, 194473, -7246, 20924, -27821, -259725, -14458, 621998, 23055.50169096061),
sprintf(boba143, "%-hi% 10i%+.5i% 2.9f@% i%-hi-%-1.2hd%-9.2hu`2%+.10d=@%+4.3hi/%-.3dx*% 10f-", 24154, -523408, 870169, 4334.747366106868, 194473, -7246, 20924, -27821, -259725, -14458, 621998, 23055.50169096061));
ck_assert_str_eq(boba143_s21, boba143);
}
END_TEST

START_TEST(bebasik__144) {
char boba144_s21[10000];
char boba144[10000];
ck_assert_int_eq(s21_sprintf(boba144_s21, "%+8hd%+.7hi%-.2hu;2%-10.0hdt[[(3% .0hi$%+6hdgn%-10hi49du%+.0f%-hit%-.9fz88% 9hi@5% 4hi%+f%-2.2hu% .8hit% .2f%+i7%+10hi%-10.5hif", 17673, -6731, 5689, -28237, 11038, 7801, 2564, 12623.873415526916, 22232, -4930.617223491236, 392, 21617, 5203.769413796839, -23955, -29918, -559.665595994212, -418919, -16410, -14078),
sprintf(boba144, "%+8hd%+.7hi%-.2hu;2%-10.0hdt[[(3% .0hi$%+6hdgn%-10hi49du%+.0f%-hit%-.9fz88% 9hi@5% 4hi%+f%-2.2hu% .8hit% .2f%+i7%+10hi%-10.5hif", 17673, -6731, 5689, -28237, 11038, 7801, 2564, 12623.873415526916, 22232, -4930.617223491236, 392, 21617, 5203.769413796839, -23955, -29918, -559.665595994212, -418919, -16410, -14078));
ck_assert_str_eq(boba144_s21, boba144);
}
END_TEST

START_TEST(bebasik__145) {
char boba145_s21[10000];
char boba145[10000];
ck_assert_int_eq(s21_sprintf(boba145_s21, "%+.6i&%+d%-.7d%-2i%-8hd[j/%-2hd%-5.1i% .4hi%-.9hu*% .8hdj%-.4ul18%+del62% 10.9d", 530208, -839845, -446947, 194439, -1167, 2327, 918209, 21080, 29062, -1469, -513805, -791252, -795300),
sprintf(boba145, "%+.6i&%+d%-.7d%-2i%-8hd[j/%-2hd%-5.1i% .4hi%-.9hu*% .8hdj%-.4ul18%+del62% 10.9d", 530208, -839845, -446947, 194439, -1167, 2327, 918209, 21080, 29062, -1469, -513805, -791252, -795300));
ck_assert_str_eq(boba145_s21, boba145);
}
END_TEST

START_TEST(bebasik__146) {
char boba146_s21[10000];
char boba146[10000];
ck_assert_int_eq(s21_sprintf(boba146_s21, "% f#v%+7.5df%+i/% fd% i%+.2hi%+2hi%+hi4% 6hd%+f1%-2.4hdb81%-6.8hd% f%+10.3d% 1.5hd%-3.2hu%-.4hd&r% 3.3hd78", -9776.589318219689, 422746, -875569, 6590.774333579549, -402318, 27181, 9934, -5597, -18727, 20328.450094783566, -17945, 17248, -2296.406870192875, -523346, 28733, -27217, -20299, 19428),
sprintf(boba146, "% f#v%+7.5df%+i/% fd% i%+.2hi%+2hi%+hi4% 6hd%+f1%-2.4hdb81%-6.8hd% f%+10.3d% 1.5hd%-3.2hu%-.4hd&r% 3.3hd78", -9776.589318219689, 422746, -875569, 6590.774333579549, -402318, 27181, 9934, -5597, -18727, 20328.450094783566, -17945, 17248, -2296.406870192875, -523346, 28733, -27217, -20299, 19428));
ck_assert_str_eq(boba146_s21, boba146);
}
END_TEST

START_TEST(bebasik__147) {
char boba147_s21[10000];
char boba147[10000];
ck_assert_int_eq(s21_sprintf(boba147_s21, "% 7i%+7i%-.6d% hd6%+6.5hi%-hdo[% d=-", -182299, -786466, 357245, 30969, 17736, -5046, -238198),
sprintf(boba147, "% 7i%+7i%-.6d% hd6%+6.5hi%-hdo[% d=-", -182299, -786466, 357245, 30969, 17736, -5046, -238198));
ck_assert_str_eq(boba147_s21, boba147);
}
END_TEST

START_TEST(bebasik__148) {
char boba148_s21[10000];
char boba148[10000];
ck_assert_int_eq(s21_sprintf(boba148_s21, "%+d9", 612440),
sprintf(boba148, "%+d9", 612440));
ck_assert_str_eq(boba148_s21, boba148);
}
END_TEST

START_TEST(bebasik__149) {
char boba149_s21[10000];
char boba149[10000];
ck_assert_int_eq(s21_sprintf(boba149_s21, "%+3hi", 18477),
sprintf(boba149, "%+3hi", 18477));
ck_assert_str_eq(boba149_s21, boba149);
}
END_TEST

START_TEST(bebasik__150) {
char boba150_s21[10000];
char boba150[10000];
ck_assert_int_eq(s21_sprintf(boba150_s21, "%-.6hi6%-10.10izk%+5.4ii% .4f% ff5%-4.8u%-.2hu0a4% 4.5hi%-4hdod1x%-4.6s%-1.2d%-.7i%-.2ds!%+7.8hd%-7s;%-.8dl1!%+.8f% 5.0hd8%+7.7i", -15281, -411637, -347789, -1512.0727405621221, 23722.632851958737, -475570, -16215, -16617, -7646, "", 537678, 519859, -445357, -9270, "da=40e4cgixkw`)cxqw&.", 916733, 7866.365481540827, -12511, 187719),
sprintf(boba150, "%-.6hi6%-10.10izk%+5.4ii% .4f% ff5%-4.8u%-.2hu0a4% 4.5hi%-4hdod1x%-4.6s%-1.2d%-.7i%-.2ds!%+7.8hd%-7s;%-.8dl1!%+.8f% 5.0hd8%+7.7i", -15281, -411637, -347789, -1512.0727405621221, 23722.632851958737, -475570, -16215, -16617, -7646, "", 537678, 519859, -445357, -9270, "da=40e4cgixkw`)cxqw&.", 916733, 7866.365481540827, -12511, 187719));
ck_assert_str_eq(boba150_s21, boba150);
}
END_TEST

START_TEST(bebasik__151) {
char boba151_s21[10000];
char boba151[10000];
ck_assert_int_eq(s21_sprintf(boba151_s21, "%-.10hi% hi/%-7.8hib3%+.10d%-upj", 14805, -16303, -5737, -894666, 408506),
sprintf(boba151, "%-.10hi% hi/%-7.8hib3%+.10d%-upj", 14805, -16303, -5737, -894666, 408506));
ck_assert_str_eq(boba151_s21, boba151);
}
END_TEST

START_TEST(bebasik__152) {
char boba152_s21[10000];
char boba152[10000];
ck_assert_int_eq(s21_sprintf(boba152_s21, "%-hil%+2hd% 4f%+.9i%-9.3dz% .8hdu[x%-d2a)q%+6.4hd,%+hd#%-.2i7&% 3.10fl% 8.1i%-10fq%-.9i9%-.2i", -380, 8265, -1726.536984825349, -509502, -916936, 12928, -225305, 11571, -14166, 378727, 1172.89277959415, 336753, -10712.427356428208, -822508, -470403),
sprintf(boba152, "%-hil%+2hd% 4f%+.9i%-9.3dz% .8hdu[x%-d2a)q%+6.4hd,%+hd#%-.2i7&% 3.10fl% 8.1i%-10fq%-.9i9%-.2i", -380, 8265, -1726.536984825349, -509502, -916936, 12928, -225305, 11571, -14166, 378727, 1172.89277959415, 336753, -10712.427356428208, -822508, -470403));
ck_assert_str_eq(boba152_s21, boba152);
}
END_TEST

START_TEST(bebasik__153) {
char boba153_s21[10000];
char boba153[10000];
ck_assert_int_eq(s21_sprintf(boba153_s21, "%+10hd#%+2.8f% hi%-7hd-=%+8.0fn732", 13208, -20906.009601221816, -27368, -11795, 8530.19494374982),
sprintf(boba153, "%+10hd#%+2.8f% hi%-7hd-=%+8.0fn732", 13208, -20906.009601221816, -27368, -11795, 8530.19494374982));
ck_assert_str_eq(boba153_s21, boba153);
}
END_TEST

START_TEST(bebasik__154) {
char boba154_s21[10000];
char boba154[10000];
ck_assert_int_eq(s21_sprintf(boba154_s21, "% 8f% hdl&u%-.6hu9% 3.2hd^s0%-7.10s,%+.4i6% hdo% 1hd*% hivjj%+d2", -275.5303620943131, -13196, 29833, 26091, "cq@y$9`a)&i@zv=m7!v*-/1lv*u9", -435654, 22700, -22549, -18405, -627400),
sprintf(boba154, "% 8f% hdl&u%-.6hu9% 3.2hd^s0%-7.10s,%+.4i6% hdo% 1hd*% hivjj%+d2", -275.5303620943131, -13196, 29833, 26091, "cq@y$9`a)&i@zv=m7!v*-/1lv*u9", -435654, 22700, -22549, -18405, -627400));
ck_assert_str_eq(boba154_s21, boba154);
}
END_TEST

START_TEST(bebasik__155) {
char boba155_s21[10000];
char boba155[10000];
ck_assert_int_eq(s21_sprintf(boba155_s21, "%+7hiv%-8hi@m%+hip%-u% 9i)!%+3.10hi%-.5hu% hi%+.8f", -2076, -23112, 18925, -759852, -132521, 8726, 8039, 21010, -10055.7720067947),
sprintf(boba155, "%+7hiv%-8hi@m%+hip%-u% 9i)!%+3.10hi%-.5hu% hi%+.8f", -2076, -23112, 18925, -759852, -132521, 8726, 8039, 21010, -10055.7720067947));
ck_assert_str_eq(boba155_s21, boba155);
}
END_TEST

START_TEST(bebasik__156) {
char boba156_s21[10000];
char boba156[10000];
ck_assert_int_eq(s21_sprintf(boba156_s21, "%-.2hu[b%+8.2i%-10.6hip%+9.8f%+6.5i)%-5.1hi^% .8iw% dm%-.8hi%-3.7hd%-8hi[&z% 7i% ik=%+i% .8i2%+hi%+8.10hdlz% .10f4d% 4.9hd% 9.2hd%+fw19%-.6hi% 8.10hd=%+8hdd*=t", 29977, 606354, -28875, 16031.662596467988, 629052, 12236, -881541, 741139, 31720, -31644, -13708, 106247, -244755, -718395, 751820, 1149, 31782, -17323.356859013413, -27358, 18786, -10919.766589498702, 11232, 10990, 18293),
sprintf(boba156, "%-.2hu[b%+8.2i%-10.6hip%+9.8f%+6.5i)%-5.1hi^% .8iw% dm%-.8hi%-3.7hd%-8hi[&z% 7i% ik=%+i% .8i2%+hi%+8.10hdlz% .10f4d% 4.9hd% 9.2hd%+fw19%-.6hi% 8.10hd=%+8hdd*=t", 29977, 606354, -28875, 16031.662596467988, 629052, 12236, -881541, 741139, 31720, -31644, -13708, 106247, -244755, -718395, 751820, 1149, 31782, -17323.356859013413, -27358, 18786, -10919.766589498702, 11232, 10990, 18293));
ck_assert_str_eq(boba156_s21, boba156);
}
END_TEST

START_TEST(bebasik__157) {
char boba157_s21[10000];
char boba157[10000];
ck_assert_int_eq(s21_sprintf(boba157_s21, "% 1dl%-9i3.%-.3hi[%+10.7i%+5.8hd8% .1hi%-.0hd", -972667, 93575, 1671, 662486, -6541, -27914, 14920),
sprintf(boba157, "% 1dl%-9i3.%-.3hi[%+10.7i%+5.8hd8% .1hi%-.0hd", -972667, 93575, 1671, 662486, -6541, -27914, 14920));
ck_assert_str_eq(boba157_s21, boba157);
}
END_TEST

START_TEST(bebasik__158) {
char boba158_s21[10000];
char boba158[10000];
ck_assert_int_eq(s21_sprintf(boba158_s21, "%+5.7hd% 3.4d%+5hd/% 6.2f-% hd% 6.1d,", 26063, -355605, 6608, -25236.125047803234, 12472, 136851),
sprintf(boba158, "%+5.7hd% 3.4d%+5hd/% 6.2f-% hd% 6.1d,", 26063, -355605, 6608, -25236.125047803234, 12472, 136851));
ck_assert_str_eq(boba158_s21, boba158);
}
END_TEST

START_TEST(bebasik__159) {
char boba159_s21[10000];
char boba159[10000];
ck_assert_int_eq(s21_sprintf(boba159_s21, "%-8.7um%+f%+10hd.% 3hih%-da%-.10if%-9fn% is.%-1.1d% 3.6i%-.2i%+10.10d%+2hdxi^x%-4.6hi%+7d", -978024, -3107.834032127269, 30987, 6386, 848958, 925182, -1031.6883636337627, -2370, 498858, 346314, 795387, -303306, 30489, -6607, 412119),
sprintf(boba159, "%-8.7um%+f%+10hd.% 3hih%-da%-.10if%-9fn% is.%-1.1d% 3.6i%-.2i%+10.10d%+2hdxi^x%-4.6hi%+7d", -978024, -3107.834032127269, 30987, 6386, 848958, 925182, -1031.6883636337627, -2370, 498858, 346314, 795387, -303306, 30489, -6607, 412119));
ck_assert_str_eq(boba159_s21, boba159);
}
END_TEST

START_TEST(bebasik__160) {
char boba160_s21[10000];
char boba160[10000];
ck_assert_int_eq(s21_sprintf(boba160_s21, "%+8.6f%+.10dll$%-.2dw% .9hir% 10hi*% .2i$%+2d&x[w% .7hig% 2.3hd7%+7hiw%-4d*%-8i% 1hd%-8.8hu%-.0hi% 4.8dy%+7i% d&% 2i% 5hiy%-.10hi!%-7d-% .3hd=%-.10s", 17947.280815211117, -737998, -96226, -7960, 14292, -769526, 468076, 18122, 18907, -15844, -570502, -431554, 14206, 12964, -17103, -539709, 441582, 517971, -787262, -5566, 21868, -768335, 25295, "vy.&kh"),
sprintf(boba160, "%+8.6f%+.10dll$%-.2dw% .9hir% 10hi*% .2i$%+2d&x[w% .7hig% 2.3hd7%+7hiw%-4d*%-8i% 1hd%-8.8hu%-.0hi% 4.8dy%+7i% d&% 2i% 5hiy%-.10hi!%-7d-% .3hd=%-.10s", 17947.280815211117, -737998, -96226, -7960, 14292, -769526, 468076, 18122, 18907, -15844, -570502, -431554, 14206, 12964, -17103, -539709, 441582, 517971, -787262, -5566, 21868, -768335, 25295, "vy.&kh"));
ck_assert_str_eq(boba160_s21, boba160);
}
END_TEST

START_TEST(bebasik__161) {
char boba161_s21[10000];
char boba161[10000];
ck_assert_int_eq(s21_sprintf(boba161_s21, "%+d", 155277),
sprintf(boba161, "%+d", 155277));
ck_assert_str_eq(boba161_s21, boba161);
}
END_TEST

START_TEST(bebasik__162) {
char boba162_s21[10000];
char boba162[10000];
ck_assert_int_eq(s21_sprintf(boba162_s21, "% .0hi%+4f%-.10hd%-u,x%-.8hu;&x% .3hi%-3hurst%+3.2fe%-.8hu8bs%-4ck%+.5i%-u% iqde[2%+hig/yjh%-hd% hi%+.6hd;%-hip%-d`% f^8$=[%+10.8hif(0%-.6hi%-9hd% d", 16493, -1387.7091467405535, 7416, -480411, 26242, 3767, -31101, 15806.317308451196, 15651, '8', -695394, 446061, 92898, 22447, 4607, -21330, 28065, 9542, -45653, 3824.3945246669978, 20344, 31471, -20166, -526649),
sprintf(boba162, "% .0hi%+4f%-.10hd%-u,x%-.8hu;&x% .3hi%-3hurst%+3.2fe%-.8hu8bs%-4ck%+.5i%-u% iqde[2%+hig/yjh%-hd% hi%+.6hd;%-hip%-d`% f^8$=[%+10.8hif(0%-.6hi%-9hd% d", 16493, -1387.7091467405535, 7416, -480411, 26242, 3767, -31101, 15806.317308451196, 15651, '8', -695394, 446061, 92898, 22447, 4607, -21330, 28065, 9542, -45653, 3824.3945246669978, 20344, 31471, -20166, -526649));
ck_assert_str_eq(boba162_s21, boba162);
}
END_TEST

START_TEST(bebasik__163) {
char boba163_s21[10000];
char boba163[10000];
ck_assert_int_eq(s21_sprintf(boba163_s21, "%+hd#g2% 1.2i% ifw% hd2% 2.2dxg", 19593, -948094, -33914, 12605, 989567),
sprintf(boba163, "%+hd#g2% 1.2i% ifw% hd2% 2.2dxg", 19593, -948094, -33914, 12605, 989567));
ck_assert_str_eq(boba163_s21, boba163);
}
END_TEST

START_TEST(bebasik__164) {
char boba164_s21[10000];
char boba164[10000];
ck_assert_int_eq(s21_sprintf(boba164_s21, "%-1hd%-7.8hi% hd&$%+.7hi7%-.10hd!%-.10hiblm3%+10.0f%-7hi%-10hi8/[di%-10u%+5.2hil@%-9.6f1%+1.1hir3%+i%+5.6f(;%-2.3hd%-7hi=[% hd%+7.7hiu;%-hi@% .8hd% 7.1hd3%-f0/&", 8304, -18452, 8841, 6332, 23481, -6032, -14267.018528237597, -30887, 31369, -315117, 18741, -14625.234705002862, -11664, 696446, -956.9922009308575, 27862, -11672, -14821, 16953, 9477, 24475, 11916, 25271.233182835243),
sprintf(boba164, "%-1hd%-7.8hi% hd&$%+.7hi7%-.10hd!%-.10hiblm3%+10.0f%-7hi%-10hi8/[di%-10u%+5.2hil@%-9.6f1%+1.1hir3%+i%+5.6f(;%-2.3hd%-7hi=[% hd%+7.7hiu;%-hi@% .8hd% 7.1hd3%-f0/&", 8304, -18452, 8841, 6332, 23481, -6032, -14267.018528237597, -30887, 31369, -315117, 18741, -14625.234705002862, -11664, 696446, -956.9922009308575, 27862, -11672, -14821, 16953, 9477, 24475, 11916, 25271.233182835243));
ck_assert_str_eq(boba164_s21, boba164);
}
END_TEST

START_TEST(bebasik__165) {
char boba165_s21[10000];
char boba165[10000];
ck_assert_int_eq(s21_sprintf(boba165_s21, "% ig%+2hi%-hd)ya% 6fx% d%-f% 1hdu@4ox%-.5hi6zno%-7c% 1.3dj%-hu%-9hig", -627817, -24940, 14457, -6778.488251565003, -990640, 4870.628731954389, 23659, 2561, '/', -306474, 16584, -19738),
sprintf(boba165, "% ig%+2hi%-hd)ya% 6fx% d%-f% 1hdu@4ox%-.5hi6zno%-7c% 1.3dj%-hu%-9hig", -627817, -24940, 14457, -6778.488251565003, -990640, 4870.628731954389, 23659, 2561, '/', -306474, 16584, -19738));
ck_assert_str_eq(boba165_s21, boba165);
}
END_TEST

START_TEST(bebasik__166) {
char boba166_s21[10000];
char boba166[10000];
ck_assert_int_eq(s21_sprintf(boba166_s21, "%+3hi%-1.6hu8sc!;7% 7.4i[%+1.3d% 5hi22/a5%+.0hd%-u", -20851, -14735, -266137, -573102, -17119, 9181, 135491),
sprintf(boba166, "%+3hi%-1.6hu8sc!;7% 7.4i[%+1.3d% 5hi22/a5%+.0hd%-u", -20851, -14735, -266137, -573102, -17119, 9181, 135491));
ck_assert_str_eq(boba166_s21, boba166);
}
END_TEST

START_TEST(bebasik__167) {
char boba167_s21[10000];
char boba167[10000];
ck_assert_int_eq(s21_sprintf(boba167_s21, "%+4.0hi*% 3.9hif%-f8% i6x9!% 10.3hi%+.8dd% .8hi%+i%-.9f7@%+.2hd%+hi`n1t4%-4s@4g% 4.7f.% 8.7fc%+.4hi% .6hi% .1fu#% 10i% dl(o% .7hdf%+i7m%+f6,% .9hih^% .8i", -6484, 5494, -11960.3398156116, 491916, -15252, -295892, 23292, 463874, -3069.592914973971, 14773, 11384, "o`x)79vqvx2s0;q$/8;bgg6k*[", -4581.9304250711075, 12096.418770624092, 10595, 8746, -3366.2332731351657, -456386, 573951, -18089, -755940, 470.90256506815865, -9742, 83688),
sprintf(boba167, "%+4.0hi*% 3.9hif%-f8% i6x9!% 10.3hi%+.8dd% .8hi%+i%-.9f7@%+.2hd%+hi`n1t4%-4s@4g% 4.7f.% 8.7fc%+.4hi% .6hi% .1fu#% 10i% dl(o% .7hdf%+i7m%+f6,% .9hih^% .8i", -6484, 5494, -11960.3398156116, 491916, -15252, -295892, 23292, 463874, -3069.592914973971, 14773, 11384, "o`x)79vqvx2s0;q$/8;bgg6k*[", -4581.9304250711075, 12096.418770624092, 10595, 8746, -3366.2332731351657, -456386, 573951, -18089, -755940, 470.90256506815865, -9742, 83688));
ck_assert_str_eq(boba167_s21, boba167);
}
END_TEST

START_TEST(bebasik__168) {
char boba168_s21[10000];
char boba168[10000];
ck_assert_int_eq(s21_sprintf(boba168_s21, "%+10.3d%+8fb% .10hi%+hd77k%+7.8hd7%+4.10i%+d% .1hdx^%+hd%+4i%+8f%-hd% d%+hi^% hi`% 10.8i7@o%-.7f% 6.5i% .3f% .0f% .7hic%-hd%+hd%-.3hid", -76047, 4922.490623537418, 26021, 8997, -1611, 696014, -71293, 21806, -19404, 694453, 17570.113042117588, -15959, -652669, -2976, -27089, 724346, -15073.171226632752, 299817, 18029.313926749015, -7050.985352275766, -29024, 1647, 8189, 11630),
sprintf(boba168, "%+10.3d%+8fb% .10hi%+hd77k%+7.8hd7%+4.10i%+d% .1hdx^%+hd%+4i%+8f%-hd% d%+hi^% hi`% 10.8i7@o%-.7f% 6.5i% .3f% .0f% .7hic%-hd%+hd%-.3hid", -76047, 4922.490623537418, 26021, 8997, -1611, 696014, -71293, 21806, -19404, 694453, 17570.113042117588, -15959, -652669, -2976, -27089, 724346, -15073.171226632752, 299817, 18029.313926749015, -7050.985352275766, -29024, 1647, 8189, 11630));
ck_assert_str_eq(boba168_s21, boba168);
}
END_TEST

START_TEST(bebasik__169) {
char boba169_s21[10000];
char boba169[10000];
ck_assert_int_eq(s21_sprintf(boba169_s21, "%+10d% 5hdn1% 10hi0i3%+i#% 3d%-.0ii%-hd", 418024, 19523, -24620, 411019, -658780, 526932, -11580),
sprintf(boba169, "%+10d% 5hdn1% 10hi0i3%+i#% 3d%-.0ii%-hd", 418024, 19523, -24620, 411019, -658780, 526932, -11580));
ck_assert_str_eq(boba169_s21, boba169);
}
END_TEST

START_TEST(bebasik__170) {
char boba170_s21[10000];
char boba170[10000];
ck_assert_int_eq(s21_sprintf(boba170_s21, "% hd(s% hi% 7.2f8.rdb%-2.1hi%+5dv%+2fx%+2.9hdb% 5.8ia% .8i&)% .1hdv%-.4f2% ij*% 6i% hd%+9f% .5f%+.6d17% 5.9fv81ak% .8i% .5f;", 28863, -12463, 7143.1863391928755, 19581, 919024, 7890.820005748612, -6188, -652977, -931554, 11216, 14001.74686106915, 82356, 395753, -1551, -224.2668006401273, -2566.6413573200493, 80543, 113.82836592856043, -358247, -24379.24319767447),
sprintf(boba170, "% hd(s% hi% 7.2f8.rdb%-2.1hi%+5dv%+2fx%+2.9hdb% 5.8ia% .8i&)% .1hdv%-.4f2% ij*% 6i% hd%+9f% .5f%+.6d17% 5.9fv81ak% .8i% .5f;", 28863, -12463, 7143.1863391928755, 19581, 919024, 7890.820005748612, -6188, -652977, -931554, 11216, 14001.74686106915, 82356, 395753, -1551, -224.2668006401273, -2566.6413573200493, 80543, 113.82836592856043, -358247, -24379.24319767447));
ck_assert_str_eq(boba170_s21, boba170);
}
END_TEST

START_TEST(bebasik__171) {
char boba171_s21[10000];
char boba171[10000];
ck_assert_int_eq(s21_sprintf(boba171_s21, "%+9i% dz%+10hd2", 682157, -311382, 5374),
sprintf(boba171, "%+9i% dz%+10hd2", 682157, -311382, 5374));
ck_assert_str_eq(boba171_s21, boba171);
}
END_TEST

START_TEST(bebasik__172) {
char boba172_s21[10000];
char boba172[10000];
ck_assert_int_eq(s21_sprintf(boba172_s21, "%-10i%+3.0hi3d%+hi%-.4f%+.9hdd%+hi%-s%+.7hd%-1hi%+4.5hir%-s% d%+7hd%+.3f;[e%+2hiz% 6fp% .5i@%-hic%-.10hi%-u^% .2hd4%-hd", -960200, 29111, 12367, -19266.736144799608, 686, -16417, "(-6m,x1h7v,915;t#-py4r7kx", -12847, 27808, 28376, "3ec0jh6gro*=2=qg", -617776, 29832, 456.1627014161291, -8367, 254.02187608441574, 284562, -5984, 10984, 498968, 20528, -29079),
sprintf(boba172, "%-10i%+3.0hi3d%+hi%-.4f%+.9hdd%+hi%-s%+.7hd%-1hi%+4.5hir%-s% d%+7hd%+.3f;[e%+2hiz% 6fp% .5i@%-hic%-.10hi%-u^% .2hd4%-hd", -960200, 29111, 12367, -19266.736144799608, 686, -16417, "(-6m,x1h7v,915;t#-py4r7kx", -12847, 27808, 28376, "3ec0jh6gro*=2=qg", -617776, 29832, 456.1627014161291, -8367, 254.02187608441574, 284562, -5984, 10984, 498968, 20528, -29079));
ck_assert_str_eq(boba172_s21, boba172);
}
END_TEST

START_TEST(bebasik__173) {
char boba173_s21[10000];
char boba173[10000];
ck_assert_int_eq(s21_sprintf(boba173_s21, "%-huv%+.5hi% .9hi0%+i=.z*%+5f% .4f%-10hdx;%+6.4hi%+d%+7d%+3.3i%+fei%+hi%-.6u=% f%+hi@za", 25860, -10619, -8810, -350880, 10136.77722074573, -24975.025911020413, -10419, -11401, -525711, 241655, -725008, 3725.428257343791, 29258, 254256, -664.8375683383719, -14339),
sprintf(boba173, "%-huv%+.5hi% .9hi0%+i=.z*%+5f% .4f%-10hdx;%+6.4hi%+d%+7d%+3.3i%+fei%+hi%-.6u=% f%+hi@za", 25860, -10619, -8810, -350880, 10136.77722074573, -24975.025911020413, -10419, -11401, -525711, 241655, -725008, 3725.428257343791, 29258, 254256, -664.8375683383719, -14339));
ck_assert_str_eq(boba173_s21, boba173);
}
END_TEST

START_TEST(bebasik__174) {
char boba174_s21[10000];
char boba174[10000];
ck_assert_int_eq(s21_sprintf(boba174_s21, "%-5.1hd%-3huj;%-hu3k%+hds0&% hd)1% 4hd% .1d`% 2i%+8.8hda%+9.6do% 7.10d$$%-3s!%+hd% hi%-1hd%-1i", 8186, -17117, -30319, -15236, 9688, 30725, -544433, 535888, 20982, -977193, -638153, "z;v$ti6k,,@re@&r/v1(l`[2;", 24729, -9389, 8462, -348828),
sprintf(boba174, "%-5.1hd%-3huj;%-hu3k%+hds0&% hd)1% 4hd% .1d`% 2i%+8.8hda%+9.6do% 7.10d$$%-3s!%+hd% hi%-1hd%-1i", 8186, -17117, -30319, -15236, 9688, 30725, -544433, 535888, 20982, -977193, -638153, "z;v$ti6k,,@re@&r/v1(l`[2;", 24729, -9389, 8462, -348828));
ck_assert_str_eq(boba174_s21, boba174);
}
END_TEST

START_TEST(bebasik__175) {
char boba175_s21[10000];
char boba175[10000];
ck_assert_int_eq(s21_sprintf(boba175_s21, "%+hipts%-10.1hd$% .4d)b#", 5537, 2615, 716966),
sprintf(boba175, "%+hipts%-10.1hd$% .4d)b#", 5537, 2615, 716966));
ck_assert_str_eq(boba175_s21, boba175);
}
END_TEST

START_TEST(bebasik__176) {
char boba176_s21[10000];
char boba176[10000];
ck_assert_int_eq(s21_sprintf(boba176_s21, "%+.1hi%-.8d% 3dq`%-dy% 10hdqmg%-3.5u%+.9hi!% 5.6dtk[%+hdb=%+5.1hi1% .7hi%+3f%+9.8i% 6hi(i%+hi%+7.7f%-hi%-2hio9ly%-5.10us%+4f% hd%+10hdh", -23835, 923550, 951562, 724431, -15749, -553500, 26633, 10246, 26982, -9807, -9581, -16170.467853401147, -721288, -11814, 29376, 17802.499033751144, 29446, 22225, -507251, 656.4579153924922, -1348, -11526),
sprintf(boba176, "%+.1hi%-.8d% 3dq`%-dy% 10hdqmg%-3.5u%+.9hi!% 5.6dtk[%+hdb=%+5.1hi1% .7hi%+3f%+9.8i% 6hi(i%+hi%+7.7f%-hi%-2hio9ly%-5.10us%+4f% hd%+10hdh", -23835, 923550, 951562, 724431, -15749, -553500, 26633, 10246, 26982, -9807, -9581, -16170.467853401147, -721288, -11814, 29376, 17802.499033751144, 29446, 22225, -507251, 656.4579153924922, -1348, -11526));
ck_assert_str_eq(boba176_s21, boba176);
}
END_TEST

START_TEST(bebasik__177) {
char boba177_s21[10000];
char boba177[10000];
ck_assert_int_eq(s21_sprintf(boba177_s21, "%+10.10hi%-fz^4%+.4hi1e%-2d%+8f2yz!% d&=)%-9i2j)*% 8.9hduk%-.3hi% .0d% 7.0hd%-.6i%-.5huf% .6hd", 15851, -14361.254768346165, 17962, -433233, -6123.458567736178, 228067, 449339, -20942, 6404, -824560, -29453, 796209, -30137, 10868),
sprintf(boba177, "%+10.10hi%-fz^4%+.4hi1e%-2d%+8f2yz!% d&=)%-9i2j)*% 8.9hduk%-.3hi% .0d% 7.0hd%-.6i%-.5huf% .6hd", 15851, -14361.254768346165, 17962, -433233, -6123.458567736178, 228067, 449339, -20942, 6404, -824560, -29453, 796209, -30137, 10868));
ck_assert_str_eq(boba177_s21, boba177);
}
END_TEST

START_TEST(bebasik__178) {
char boba178_s21[10000];
char boba178[10000];
ck_assert_int_eq(s21_sprintf(boba178_s21, "% .3hd^hrn%-.1hix% 7.9hi% .3d%-2u15v", 15071, -30447, -29071, -170438, -130071),
sprintf(boba178, "% .3hd^hrn%-.1hix% 7.9hi% .3d%-2u15v", 15071, -30447, -29071, -170438, -130071));
ck_assert_str_eq(boba178_s21, boba178);
}
END_TEST

START_TEST(bebasik__179) {
char boba179_s21[10000];
char boba179[10000];
ck_assert_int_eq(s21_sprintf(boba179_s21, "%+2.0f%+.3hig%+dsup%+.1dqn*$i%+6.6i%-hi8dx%-6s%+5.10d%+.10hi% .1i% hd5u.v%-.5hd%+.1dx", -4924.053396647995, 16140, -32556, -956813, -718088, -27696, "wxp;u[k0g`)r#&^o&(,[4v-h&qw)", 919674, -19444, -186768, 14732, 28884, -630202),
sprintf(boba179, "%+2.0f%+.3hig%+dsup%+.1dqn*$i%+6.6i%-hi8dx%-6s%+5.10d%+.10hi% .1i% hd5u.v%-.5hd%+.1dx", -4924.053396647995, 16140, -32556, -956813, -718088, -27696, "wxp;u[k0g`)r#&^o&(,[4v-h&qw)", 919674, -19444, -186768, 14732, 28884, -630202));
ck_assert_str_eq(boba179_s21, boba179);
}
END_TEST

START_TEST(bebasik__180) {
char boba180_s21[10000];
char boba180[10000];
ck_assert_int_eq(s21_sprintf(boba180_s21, "%-.8d%+4.7d% .2djb%+.3hi8%+4i;%+4hi$2*%+2.4hd%-hd% 10f%-.1hi% 8.10in% 3.1hi%-.9hds%+7ihw% i", -366686, 322858, 837174, 10395, 508678, -16074, 22438, 22573, -5791.040554328813, 23937, -538530, 25591, -3910, 816130, -650183),
sprintf(boba180, "%-.8d%+4.7d% .2djb%+.3hi8%+4i;%+4hi$2*%+2.4hd%-hd% 10f%-.1hi% 8.10in% 3.1hi%-.9hds%+7ihw% i", -366686, 322858, 837174, 10395, 508678, -16074, 22438, 22573, -5791.040554328813, 23937, -538530, 25591, -3910, 816130, -650183));
ck_assert_str_eq(boba180_s21, boba180);
}
END_TEST

START_TEST(bebasik__181) {
char boba181_s21[10000];
char boba181[10000];
ck_assert_int_eq(s21_sprintf(boba181_s21, "%-hu%+.1hd%+hi%-huge%-3hdz%-.9hi.t8%-4s%+10.3hd.", -5983, -5019, 10103, 11014, -14079, 9926, "3ufu@x@9j2", 29787),
sprintf(boba181, "%-hu%+.1hd%+hi%-huge%-3hdz%-.9hi.t8%-4s%+10.3hd.", -5983, -5019, 10103, 11014, -14079, 9926, "3ufu@x@9j2", 29787));
ck_assert_str_eq(boba181_s21, boba181);
}
END_TEST

START_TEST(bebasik__182) {
char boba182_s21[10000];
char boba182[10000];
ck_assert_int_eq(s21_sprintf(boba182_s21, "% 6fh8w% 2f% i%+4f[%+6.5hif#4%-6hd%-.3i% i%+hi%+hd%-f7%+2.1i% hd% .8dh% 4f% .2hd% 3.10hd3%-hi&c%+.2i%-4.5d9#", -4086.346994107799, -504.53405080842174, 244911, 3880.0439300666135, -30299, -8474, 549226, 105980, -23759, 16552, -726.69997141636, 568714, -4276, 688448, -1460.653657295551, 14301, -14354, -13686, -335454, 575240),
sprintf(boba182, "% 6fh8w% 2f% i%+4f[%+6.5hif#4%-6hd%-.3i% i%+hi%+hd%-f7%+2.1i% hd% .8dh% 4f% .2hd% 3.10hd3%-hi&c%+.2i%-4.5d9#", -4086.346994107799, -504.53405080842174, 244911, 3880.0439300666135, -30299, -8474, 549226, 105980, -23759, 16552, -726.69997141636, 568714, -4276, 688448, -1460.653657295551, 14301, -14354, -13686, -335454, 575240));
ck_assert_str_eq(boba182_s21, boba182);
}
END_TEST

START_TEST(bebasik__183) {
char boba183_s21[10000];
char boba183[10000];
ck_assert_int_eq(s21_sprintf(boba183_s21, "% hd%-f% 1fsr% .7fc%-8i@#%-.5hdz(% hd%+.7hd", 25475, -8083.53565239014, -9213.210223771612, 567.344539413301, 7430, -5317, 23995, -24928),
sprintf(boba183, "% hd%-f% 1fsr% .7fc%-8i@#%-.5hdz(% hd%+.7hd", 25475, -8083.53565239014, -9213.210223771612, 567.344539413301, 7430, -5317, 23995, -24928));
ck_assert_str_eq(boba183_s21, boba183);
}
END_TEST

START_TEST(bebasik__184) {
char boba184_s21[10000];
char boba184[10000];
ck_assert_int_eq(s21_sprintf(boba184_s21, "%-.0d%+5hd%+7.0i%+.7hi%+9.7hd%+3hi%+3d%-7.9d", 831623, 27012, -645202, 632, -20896, 750, -60556, -194582),
sprintf(boba184, "%-.0d%+5hd%+7.0i%+.7hi%+9.7hd%+3hi%+3d%-7.9d", 831623, 27012, -645202, 632, -20896, 750, -60556, -194582));
ck_assert_str_eq(boba184_s21, boba184);
}
END_TEST

START_TEST(bebasik__185) {
char boba185_s21[10000];
char boba185[10000];
ck_assert_int_eq(s21_sprintf(boba185_s21, "% hi@o%-hd% 6.2hie%+8.6hi%-7.5i%-2.6hu5% 4.9hi%-.6f% 8.8f%+hd% 10.2d", -1586, 4783, 30748, 17170, 979131, -15069, 30946, -1257.7351981808, -2964.749867243332, 2479, 901222),
sprintf(boba185, "% hi@o%-hd% 6.2hie%+8.6hi%-7.5i%-2.6hu5% 4.9hi%-.6f% 8.8f%+hd% 10.2d", -1586, 4783, 30748, 17170, 979131, -15069, 30946, -1257.7351981808, -2964.749867243332, 2479, 901222));
ck_assert_str_eq(boba185_s21, boba185);
}
END_TEST

START_TEST(bebasik__186) {
char boba186_s21[10000];
char boba186[10000];
ck_assert_int_eq(s21_sprintf(boba186_s21, "%+3.6i/r%-2sg.%+.8hd(daj4%+9d#% i%-.9hu5^0p%+.4hdcm% 10.2f&%-.4hij%+3.10i%+8ft%+.6hd% .7f% 2.1i48d6%-.6f% 3iy%+.7d0lt", 262516, "z0*o/$-5,1", -25894, -262056, -565966, 30115, 30055, -4106.235949026153, -7819, -99661, 5976.4692505812245, -30504, -9807.188045441399, -802169, 1263.8049438971714, 673263, 620130),
sprintf(boba186, "%+3.6i/r%-2sg.%+.8hd(daj4%+9d#% i%-.9hu5^0p%+.4hdcm% 10.2f&%-.4hij%+3.10i%+8ft%+.6hd% .7f% 2.1i48d6%-.6f% 3iy%+.7d0lt", 262516, "z0*o/$-5,1", -25894, -262056, -565966, 30115, 30055, -4106.235949026153, -7819, -99661, 5976.4692505812245, -30504, -9807.188045441399, -802169, 1263.8049438971714, 673263, 620130));
ck_assert_str_eq(boba186_s21, boba186);
}
END_TEST

START_TEST(bebasik__187) {
char boba187_s21[10000];
char boba187[10000];
ck_assert_int_eq(s21_sprintf(boba187_s21, "%-.3i% 5f%-.7hi% 6hi;-w% .9d% 8i% 5hi%+10f% 6hi0%-.7u5% 3hd%+.10f% 6hiz%-9.1s", -192954, -14078.397373999876, -15857, 6483, -782793, -543331, -6116, -18721.58493437676, 14768, -397045, 2401, -7036.109483212474, -9085, "a)!;m(-"),
sprintf(boba187, "%-.3i% 5f%-.7hi% 6hi;-w% .9d% 8i% 5hi%+10f% 6hi0%-.7u5% 3hd%+.10f% 6hiz%-9.1s", -192954, -14078.397373999876, -15857, 6483, -782793, -543331, -6116, -18721.58493437676, 14768, -397045, 2401, -7036.109483212474, -9085, "a)!;m(-"));
ck_assert_str_eq(boba187_s21, boba187);
}
END_TEST

START_TEST(bebasik__188) {
char boba188_s21[10000];
char boba188[10000];
ck_assert_int_eq(s21_sprintf(boba188_s21, "%+9i*n[![% .0hdu!3% 8hi/to%+10.9fz6w% 1hi%-3.8hi% .0hi(%+.6hi%+.9hd%-.3s%-c%+hdh%-.0hd9xj% i@ep`=t%-9.2hi[", -842556, 27309, 28624, -1551.8503293795811, 27332, -9635, -29350, -18017, 29961, "xg91kx", 'j', 20789, 11762, 512353, -12022),
sprintf(boba188, "%+9i*n[![% .0hdu!3% 8hi/to%+10.9fz6w% 1hi%-3.8hi% .0hi(%+.6hi%+.9hd%-.3s%-c%+hdh%-.0hd9xj% i@ep`=t%-9.2hi[", -842556, 27309, 28624, -1551.8503293795811, 27332, -9635, -29350, -18017, 29961, "xg91kx", 'j', 20789, 11762, 512353, -12022));
ck_assert_str_eq(boba188_s21, boba188);
}
END_TEST

START_TEST(bebasik__189) {
char boba189_s21[10000];
char boba189[10000];
ck_assert_int_eq(s21_sprintf(boba189_s21, "%+hd% .2fx% hd,% hi%+.3f", 6960, 7480.491339887206, -6757, -9226, -3338.064539972469),
sprintf(boba189, "%+hd% .2fx% hd,% hi%+.3f", 6960, 7480.491339887206, -6757, -9226, -3338.064539972469));
ck_assert_str_eq(boba189_s21, boba189);
}
END_TEST

START_TEST(bebasik__190) {
char boba190_s21[10000];
char boba190[10000];
ck_assert_int_eq(s21_sprintf(boba190_s21, "%-.1hd%-.10i% 6hi%+hd%+hi4,%-6f%-.1s%+8.3d%-hd% i82a", 22213, 640139, -22591, 18944, 10198, -5967.003754461802, "!g`ks8)^1170p/7k)3dh92(6.5.", 688629, 10622, -693930),
sprintf(boba190, "%-.1hd%-.10i% 6hi%+hd%+hi4,%-6f%-.1s%+8.3d%-hd% i82a", 22213, 640139, -22591, 18944, 10198, -5967.003754461802, "!g`ks8)^1170p/7k)3dh92(6.5.", 688629, 10622, -693930));
ck_assert_str_eq(boba190_s21, boba190);
}
END_TEST

START_TEST(bebasik__191) {
char boba191_s21[10000];
char boba191[10000];
ck_assert_int_eq(s21_sprintf(boba191_s21, "%+8d%-6.10io%+2hi!b%-.3d%+hit#%+6.5hi% .10dq2`%+f.i% ft% db%+d1c!%-.7hi%-6.9hd5e%-.7hd%-9.0hdk%-.10hi3%+hd-s%+.4hi8j", -557257, -867392, 27188, 898656, -6572, 26717, 639554, -9027.155258113085, 16383.71292576951, -46048, 439908, -6922, 16537, -15338, 26787, -10452, 30661, -28141),
sprintf(boba191, "%+8d%-6.10io%+2hi!b%-.3d%+hit#%+6.5hi% .10dq2`%+f.i% ft% db%+d1c!%-.7hi%-6.9hd5e%-.7hd%-9.0hdk%-.10hi3%+hd-s%+.4hi8j", -557257, -867392, 27188, 898656, -6572, 26717, 639554, -9027.155258113085, 16383.71292576951, -46048, 439908, -6922, 16537, -15338, 26787, -10452, 30661, -28141));
ck_assert_str_eq(boba191_s21, boba191);
}
END_TEST

START_TEST(bebasik__192) {
char boba192_s21[10000];
char boba192[10000];
ck_assert_int_eq(s21_sprintf(boba192_s21, "%-uy%+10i0o`2qrpl38% 6f$c%+.5d%-8.2hu% .8hi%+7.7hi%-.5s% 1.6i%+hi%+.9ia;%+4.6hd% i%-9.3s;%+.7hi;.p% dra% 6hi% hd%-4.0hur", 764438, 936169, 8781.844063929431, 157071, 5178, 26442, -13899, "6/[08l1fh", 842440, -26081, -549143, 22826, -858891, "g*,o6a@91dc#@", 14535, -334023, -29869, 30279, -25750),
sprintf(boba192, "%-uy%+10i0o`2qrpl38% 6f$c%+.5d%-8.2hu% .8hi%+7.7hi%-.5s% 1.6i%+hi%+.9ia;%+4.6hd% i%-9.3s;%+.7hi;.p% dra% 6hi% hd%-4.0hur", 764438, 936169, 8781.844063929431, 157071, 5178, 26442, -13899, "6/[08l1fh", 842440, -26081, -549143, 22826, -858891, "g*,o6a@91dc#@", 14535, -334023, -29869, 30279, -25750));
ck_assert_str_eq(boba192_s21, boba192);
}
END_TEST

START_TEST(bebasik__193) {
char boba193_s21[10000];
char boba193[10000];
ck_assert_int_eq(s21_sprintf(boba193_s21, "% 10.10f%-6hdm%+5hid%-4.3hu% hi%+i%-3hu%+.2hd.3%-.10hd,%-.6hda%-ss%-hi%-.7s*%-u% .6i% .0f% if% .0i", 8614.027037299886, 19361, -19287, 15288, -516, 902949, -11080, 15967, 4752, 19794, "wp!y;nl*ffc-u&dtn!,.ym", 31483, "gyhm*,eic6yg", -953093, 822934, 4193.382594016187, -963480, 272298),
sprintf(boba193, "% 10.10f%-6hdm%+5hid%-4.3hu% hi%+i%-3hu%+.2hd.3%-.10hd,%-.6hda%-ss%-hi%-.7s*%-u% .6i% .0f% if% .0i", 8614.027037299886, 19361, -19287, 15288, -516, 902949, -11080, 15967, 4752, 19794, "wp!y;nl*ffc-u&dtn!,.ym", 31483, "gyhm*,eic6yg", -953093, 822934, 4193.382594016187, -963480, 272298));
ck_assert_str_eq(boba193_s21, boba193);
}
END_TEST

START_TEST(bebasik__194) {
char boba194_s21[10000];
char boba194[10000];
ck_assert_int_eq(s21_sprintf(boba194_s21, "%-3hid%-5hu2@% hi% .10f%+7.4his%-7.8hu%-10.7hi% .3d%-hd", -21296, 10127, -13654, 495.61378493348207, 21226, 17054, 22703, -122263, -13525),
sprintf(boba194, "%-3hid%-5hu2@% hi% .10f%+7.4his%-7.8hu%-10.7hi% .3d%-hd", -21296, 10127, -13654, 495.61378493348207, 21226, 17054, 22703, -122263, -13525));
ck_assert_str_eq(boba194_s21, boba194);
}
END_TEST

START_TEST(bebasik__195) {
char boba195_s21[10000];
char boba195[10000];
ck_assert_int_eq(s21_sprintf(boba195_s21, "%+9.10hd%+dwyp%-.3ifx% i%-.5hu%+2f%-3hi", 23018, -896912, -765454, 225148, -24832, 4644.739236118951, 13244),
sprintf(boba195, "%+9.10hd%+dwyp%-.3ifx% i%-.5hu%+2f%-3hi", 23018, -896912, -765454, 225148, -24832, 4644.739236118951, 13244));
ck_assert_str_eq(boba195_s21, boba195);
}
END_TEST

START_TEST(bebasik__196) {
char boba196_s21[10000];
char boba196[10000];
ck_assert_int_eq(s21_sprintf(boba196_s21, "%-.8hiv/62%-10hd% 9d%-hu7% .1hi% 8.2d%-hi%-10s%-8f% .1hd% .8hia", 30908, 15769, 788507, -8607, -29399, 248311, 19422, "tn=2ozuwt54ek", 22971.285559105545, 22992, -10038),
sprintf(boba196, "%-.8hiv/62%-10hd% 9d%-hu7% .1hi% 8.2d%-hi%-10s%-8f% .1hd% .8hia", 30908, 15769, 788507, -8607, -29399, 248311, 19422, "tn=2ozuwt54ek", 22971.285559105545, 22992, -10038));
ck_assert_str_eq(boba196_s21, boba196);
}
END_TEST

START_TEST(bebasik__197) {
char boba197_s21[10000];
char boba197[10000];
ck_assert_int_eq(s21_sprintf(boba197_s21, "%+.2ij%-9hu1z)%+i3%+hde%-8.7u%-.0f,[%-.1hi4% .6hi%-hi% .5d% 3f% hd% .10d% .0hd% 8.8d%-hi% .4d%-fn6%-10.10hd-s0%+3.1hi% 5i% .4hd&%+8hd0", 203016, -3579, -259027, 22907, 765681, 14169.626980063576, -13859, -28005, -21558, -921809, 3917.946604511926, 320, -431456, 6924, -296436, -433, 634238, -5160.061459651965, 27254, -24595, -504450, 21073, 9973),
sprintf(boba197, "%+.2ij%-9hu1z)%+i3%+hde%-8.7u%-.0f,[%-.1hi4% .6hi%-hi% .5d% 3f% hd% .10d% .0hd% 8.8d%-hi% .4d%-fn6%-10.10hd-s0%+3.1hi% 5i% .4hd&%+8hd0", 203016, -3579, -259027, 22907, 765681, 14169.626980063576, -13859, -28005, -21558, -921809, 3917.946604511926, 320, -431456, 6924, -296436, -433, 634238, -5160.061459651965, 27254, -24595, -504450, 21073, 9973));
ck_assert_str_eq(boba197_s21, boba197);
}
END_TEST

START_TEST(bebasik__198) {
char boba198_s21[10000];
char boba198[10000];
ck_assert_int_eq(s21_sprintf(boba198_s21, "%+9.5hi%-2hd)%-3.3i%-f;% 3.4fi%+d% .10i%-6.9i% f% 2.8f%+.6d", -26202, 7911, -186998, 968.6272949655322, -3045.830384058977, 957592, 899719, 224798, -22488.173794637536, 2225.989295854352, -567759),
sprintf(boba198, "%+9.5hi%-2hd)%-3.3i%-f;% 3.4fi%+d% .10i%-6.9i% f% 2.8f%+.6d", -26202, 7911, -186998, 968.6272949655322, -3045.830384058977, 957592, 899719, 224798, -22488.173794637536, 2225.989295854352, -567759));
ck_assert_str_eq(boba198_s21, boba198);
}
END_TEST

START_TEST(bebasik__199) {
char boba199_s21[10000];
char boba199[10000];
ck_assert_int_eq(s21_sprintf(boba199_s21, "%+2f@)`% .5hi%-9hukx%-.9sb(%+1.5hd%+hivwn-wf%-u%+.9i5%-hu@% 1.8hd[u% hdmk.y% .8d%-hiv.%+.2hd", 8850.59853147911, 24525, -19800, ".g3amh^^xc(--7blp58w@", -17235, -8526, -930486, -533645, -18022, 23089, -9432, 133533, -21230, -21916),
sprintf(boba199, "%+2f@)`% .5hi%-9hukx%-.9sb(%+1.5hd%+hivwn-wf%-u%+.9i5%-hu@% 1.8hd[u% hdmk.y% .8d%-hiv.%+.2hd", 8850.59853147911, 24525, -19800, ".g3amh^^xc(--7blp58w@", -17235, -8526, -930486, -533645, -18022, 23089, -9432, 133533, -21230, -21916));
ck_assert_str_eq(boba199_s21, boba199);
}
END_TEST

START_TEST(bebasik__200) {
char boba200_s21[10000];
char boba200[10000];
ck_assert_int_eq(s21_sprintf(boba200_s21, "%+.8f% hi%+7i%+10hie%-i9%-1.3i%+.5i%-8dq% hd%+hi%-10c%-6i%-3.10hu% 1i% .1hd%+7.7d1-%+.5hiz%+hi%+hi%+hi%-9fxx3y% 8du%-6.3hdf%+.5hd", 567.6124199696375, -31427, 272804, 22525, 81405, -165092, 897372, 964228, 28378, 11946, 'd', -375995, 26099, 800966, -9574, -205261, -7057, 6368, -21497, -13207, -170.5392489025164, -151128, -31804, 13858),
sprintf(boba200, "%+.8f% hi%+7i%+10hie%-i9%-1.3i%+.5i%-8dq% hd%+hi%-10c%-6i%-3.10hu% 1i% .1hd%+7.7d1-%+.5hiz%+hi%+hi%+hi%-9fxx3y% 8du%-6.3hdf%+.5hd", 567.6124199696375, -31427, 272804, 22525, 81405, -165092, 897372, 964228, 28378, 11946, 'd', -375995, 26099, 800966, -9574, -205261, -7057, 6368, -21497, -13207, -170.5392489025164, -151128, -31804, 13858));
ck_assert_str_eq(boba200_s21, boba200);
}
END_TEST

START_TEST(bebasik__201) {
char boba201_s21[10000];
char boba201[10000];
ck_assert_int_eq(s21_sprintf(boba201_s21, "% .3f%+i%-.3i% hdsb% 8.2hi%+2.6hi%-5i%+7.8hd&2", 17639.127356477904, -554970, -656129, -26662, -28550, 28497, 4843, 13467),
sprintf(boba201, "% .3f%+i%-.3i% hdsb% 8.2hi%+2.6hi%-5i%+7.8hd&2", 17639.127356477904, -554970, -656129, -26662, -28550, 28497, 4843, 13467));
ck_assert_str_eq(boba201_s21, boba201);
}
END_TEST

START_TEST(bebasik__202) {
char boba202_s21[10000];
char boba202[10000];
ck_assert_int_eq(s21_sprintf(boba202_s21, "%+hd%+4i%+10.4hi(;%-10.4hu`%+8.0i%-.10ia% 10hdy%-4c-%+10hd@% 9d%+.7hd% 10hi5s8% 7hiwt%-3.2hdy", -17221, 537214, -10986, 3922, 731050, -268381, 6686, '8', -15092, -682799, -30758, 8766, 14893, 20647),
sprintf(boba202, "%+hd%+4i%+10.4hi(;%-10.4hu`%+8.0i%-.10ia% 10hdy%-4c-%+10hd@% 9d%+.7hd% 10hi5s8% 7hiwt%-3.2hdy", -17221, 537214, -10986, 3922, 731050, -268381, 6686, '8', -15092, -682799, -30758, 8766, 14893, 20647));
ck_assert_str_eq(boba202_s21, boba202);
}
END_TEST

START_TEST(bebasik__203) {
char boba203_s21[10000];
char boba203[10000];
ck_assert_int_eq(s21_sprintf(boba203_s21, "%-.3hu%+.1i% 5.8i.4%+2.2i72%+9hi%-7c", -22443, -317908, 688045, -903610, -7282, 'q'),
sprintf(boba203, "%-.3hu%+.1i% 5.8i.4%+2.2i72%+9hi%-7c", -22443, -317908, 688045, -903610, -7282, 'q'));
ck_assert_str_eq(boba203_s21, boba203);
}
END_TEST

START_TEST(bebasik__204) {
char boba204_s21[10000];
char boba204[10000];
ck_assert_int_eq(s21_sprintf(boba204_s21, "%+hd#hc%-4d^%+.9f;%+2hix% 7hin%-u%+9.9hd4%-5.2fge%-.7i%+10hi&,-q#%-7hu%-5d%-.3s%+5.1db% hd%-.0d%-2uls% 1.6i`% .10i[%+1ff", 15927, -545858, 7818.896719255435, -13075, -24329, -563296, -6039, 5144.710393246897, -639483, -21001, 21893, 71104, "aor($4*7bn1@-=al1oa;ime(2wvj[", -264309, 29408, 169353, -660215, 611552, -686605, -1749.186800791905),
sprintf(boba204, "%+hd#hc%-4d^%+.9f;%+2hix% 7hin%-u%+9.9hd4%-5.2fge%-.7i%+10hi&,-q#%-7hu%-5d%-.3s%+5.1db% hd%-.0d%-2uls% 1.6i`% .10i[%+1ff", 15927, -545858, 7818.896719255435, -13075, -24329, -563296, -6039, 5144.710393246897, -639483, -21001, 21893, 71104, "aor($4*7bn1@-=al1oa;ime(2wvj[", -264309, 29408, 169353, -660215, 611552, -686605, -1749.186800791905));
ck_assert_str_eq(boba204_s21, boba204);
}
END_TEST

START_TEST(bebasik__205) {
char boba205_s21[10000];
char boba205[10000];
ck_assert_int_eq(s21_sprintf(boba205_s21, "%-.8dk% hd`%+i$0%+9d^% 7.6hdf`d2%-4.8hd% 10.4ff%-.1hu% hdpi", -886702, 24034, 339874, 355318, 30738, 19019, 28588.961178719193, 13797, -18367),
sprintf(boba205, "%-.8dk% hd`%+i$0%+9d^% 7.6hdf`d2%-4.8hd% 10.4ff%-.1hu% hdpi", -886702, 24034, 339874, 355318, 30738, 19019, 28588.961178719193, 13797, -18367));
ck_assert_str_eq(boba205_s21, boba205);
}
END_TEST

START_TEST(bebasik__206) {
char boba206_s21[10000];
char boba206[10000];
ck_assert_int_eq(s21_sprintf(boba206_s21, "%-.7hubg%+10.2hincuhu% .8f% 1hd", -4382, -7226, -2863.213144079123, -4774),
sprintf(boba206, "%-.7hubg%+10.2hincuhu% .8f% 1hd", -4382, -7226, -2863.213144079123, -4774));
ck_assert_str_eq(boba206_s21, boba206);
}
END_TEST

START_TEST(bebasik__207) {
char boba207_s21[10000];
char boba207[10000];
ck_assert_int_eq(s21_sprintf(boba207_s21, "%+8.1hdq-% 3.4ft%+.8f% 4.7hd`%+4hd% 6.5f%+.7i%-10.3f%-fn;k% hd%-4.2hd%-9.5f% 1f% 1.6i%+hip,%+9fgb%+.5d%-c% 9.9hi%-7hi2sf.gzeg% hi%-hddm7[% 9i%-1.8is", 22922, -1838.7706711668973, -7583.473754069132, 17894, 13460, -3838.832264189508, -649822, -1115.010167335904, -474.71514182667795, 31356, 354, -3165.9783757193914, 15282.846478998084, -954223, -8705, 1394.533884969215, -789615, 'h', 25629, -3027, -1083, -27942, -225719, 961489),
sprintf(boba207, "%+8.1hdq-% 3.4ft%+.8f% 4.7hd`%+4hd% 6.5f%+.7i%-10.3f%-fn;k% hd%-4.2hd%-9.5f% 1f% 1.6i%+hip,%+9fgb%+.5d%-c% 9.9hi%-7hi2sf.gzeg% hi%-hddm7[% 9i%-1.8is", 22922, -1838.7706711668973, -7583.473754069132, 17894, 13460, -3838.832264189508, -649822, -1115.010167335904, -474.71514182667795, 31356, 354, -3165.9783757193914, 15282.846478998084, -954223, -8705, 1394.533884969215, -789615, 'h', 25629, -3027, -1083, -27942, -225719, 961489));
ck_assert_str_eq(boba207_s21, boba207);
}
END_TEST

START_TEST(bebasik__208) {
char boba208_s21[10000];
char boba208[10000];
ck_assert_int_eq(s21_sprintf(boba208_s21, "%+3i", -407812),
sprintf(boba208, "%+3i", -407812));
ck_assert_str_eq(boba208_s21, boba208);
}
END_TEST

START_TEST(bebasik__209) {
char boba209_s21[10000];
char boba209[10000];
ck_assert_int_eq(s21_sprintf(boba209_s21, "%+.1f% .4hd% 4hd!p&*1aj&s5", 26498.69405340137, -8497, 25368),
sprintf(boba209, "%+.1f% .4hd% 4hd!p&*1aj&s5", 26498.69405340137, -8497, 25368));
ck_assert_str_eq(boba209_s21, boba209);
}
END_TEST

START_TEST(bebasik__210) {
char boba210_s21[10000];
char boba210[10000];
ck_assert_int_eq(s21_sprintf(boba210_s21, "%-.1um%+.4i%+.0i%+.1hd%+.8d% 7.1f&nyg@e3%+.4d%-.4s%+6hi3i%+hd%+.5hd-%+.1d&3%+f-%+9d3", 894927, -618513, 560094, 3721, -164760, -7711.328889423815, -596282, "uch=k&.k)ty8r8#", 27619, 25786, 30964, 77697, 27989.719921347223, 447116),
sprintf(boba210, "%-.1um%+.4i%+.0i%+.1hd%+.8d% 7.1f&nyg@e3%+.4d%-.4s%+6hi3i%+hd%+.5hd-%+.1d&3%+f-%+9d3", 894927, -618513, 560094, 3721, -164760, -7711.328889423815, -596282, "uch=k&.k)ty8r8#", 27619, 25786, 30964, 77697, 27989.719921347223, 447116));
ck_assert_str_eq(boba210_s21, boba210);
}
END_TEST

START_TEST(bebasik__211) {
char boba211_s21[10000];
char boba211[10000];
ck_assert_int_eq(s21_sprintf(boba211_s21, "%+6f%-hu`x2/%-3hu", 2026.7600057358782, 13379, -19753),
sprintf(boba211, "%+6f%-hu`x2/%-3hu", 2026.7600057358782, 13379, -19753));
ck_assert_str_eq(boba211_s21, boba211);
}
END_TEST

START_TEST(bebasik__212) {
char boba212_s21[10000];
char boba212[10000];
ck_assert_int_eq(s21_sprintf(boba212_s21, "%+.6hd", 22909),
sprintf(boba212, "%+.6hd", 22909));
ck_assert_str_eq(boba212_s21, boba212);
}
END_TEST

START_TEST(bebasik__213) {
char boba213_s21[10000];
char boba213[10000];
ck_assert_int_eq(s21_sprintf(boba213_s21, "% 7d!*% fm^,m%-3.10hi%+6f% 8.9d%+.2hi;j%-.4hu)%-.10i@7%-fkn% hd% 6fam5", -127466, 5544.346319851468, -19223, -2907.7885309747453, 17094, 1230, 9563, -308431, 166.50957550724064, -1783, 13813.475423910515),
sprintf(boba213, "% 7d!*% fm^,m%-3.10hi%+6f% 8.9d%+.2hi;j%-.4hu)%-.10i@7%-fkn% hd% 6fam5", -127466, 5544.346319851468, -19223, -2907.7885309747453, 17094, 1230, 9563, -308431, 166.50957550724064, -1783, 13813.475423910515));
ck_assert_str_eq(boba213_s21, boba213);
}
END_TEST

START_TEST(bebasik__214) {
char boba214_s21[10000];
char boba214[10000];
ck_assert_int_eq(s21_sprintf(boba214_s21, "%+.3d%-hu%-.6dj1%+8i%+6.3d1%-1.6f8%+.5d% 9hi%-.10s%-4.6hdwo%+.9f%-2.5hi%+hdr", -479701, 25039, -351515, -715886, 359792, -3.3726410691608164, -5591, 12498, "i(h^gyc/d&(((!3v9zh", -13785, -6904.318725081273, -29287, -22892),
sprintf(boba214, "%+.3d%-hu%-.6dj1%+8i%+6.3d1%-1.6f8%+.5d% 9hi%-.10s%-4.6hdwo%+.9f%-2.5hi%+hdr", -479701, 25039, -351515, -715886, 359792, -3.3726410691608164, -5591, 12498, "i(h^gyc/d&(((!3v9zh", -13785, -6904.318725081273, -29287, -22892));
ck_assert_str_eq(boba214_s21, boba214);
}
END_TEST

START_TEST(bebasik__215) {
char boba215_s21[10000];
char boba215[10000];
ck_assert_int_eq(s21_sprintf(boba215_s21, "%+8hi% 5.0i%-6.3hu(%+iw0%+2hi%-1.3s%+5hi%-9.0hifx%-1dlf%+.3f%-.4huq%+5hi%-4hij%+3hi3%+7.4d2ah(% 8hi%-2hu%+8hix% 7.8i!;(", 30859, -283394, -1547, -191019, 1445, "1q60q4#sfz0y#y2h-v[tz", -11804, 29401, -462287, -6026.139634690023, 3816, 8414, 160, -6442, -543413, -555, 12340, 30794, -367140),
sprintf(boba215, "%+8hi% 5.0i%-6.3hu(%+iw0%+2hi%-1.3s%+5hi%-9.0hifx%-1dlf%+.3f%-.4huq%+5hi%-4hij%+3hi3%+7.4d2ah(% 8hi%-2hu%+8hix% 7.8i!;(", 30859, -283394, -1547, -191019, 1445, "1q60q4#sfz0y#y2h-v[tz", -11804, 29401, -462287, -6026.139634690023, 3816, 8414, 160, -6442, -543413, -555, 12340, 30794, -367140));
ck_assert_str_eq(boba215_s21, boba215);
}
END_TEST

START_TEST(bebasik__216) {
char boba216_s21[10000];
char boba216[10000];
ck_assert_int_eq(s21_sprintf(boba216_s21, "%+hd% 10.5dl% .9i-% hdo%-1.10i%+.10f%-9hd%-6.9hi%+d% 2d%-i%+d%+dt%+hi,% 4.8f", 30401, 175085, -515063, -16467, -214714, -2411.2855348335006, -17826, -710, 307076, 607549, 160468, 841107, 367650, 25381, -4838.886038963627),
sprintf(boba216, "%+hd% 10.5dl% .9i-% hdo%-1.10i%+.10f%-9hd%-6.9hi%+d% 2d%-i%+d%+dt%+hi,% 4.8f", 30401, 175085, -515063, -16467, -214714, -2411.2855348335006, -17826, -710, 307076, 607549, 160468, 841107, 367650, 25381, -4838.886038963627));
ck_assert_str_eq(boba216_s21, boba216);
}
END_TEST

START_TEST(bebasik__217) {
char boba217_s21[10000];
char boba217[10000];
ck_assert_int_eq(s21_sprintf(boba217_s21, "%+.1hd.l%-hd%+hi.f% 7.10f%+.5f% d%-9i3% 2.3hi%-hd%+9.1hi%-3s%-hu=l%-3.10hd%+d%+5.0hdi%+.0hi`", 6075, -17421, 5648, -4493.34106883847, 5187.285726701251, -973429, -264567, 25783, 18970, -21258, "", -8511, 10244, -476287, 2140, -21424),
sprintf(boba217, "%+.1hd.l%-hd%+hi.f% 7.10f%+.5f% d%-9i3% 2.3hi%-hd%+9.1hi%-3s%-hu=l%-3.10hd%+d%+5.0hdi%+.0hi`", 6075, -17421, 5648, -4493.34106883847, 5187.285726701251, -973429, -264567, 25783, 18970, -21258, "", -8511, 10244, -476287, 2140, -21424));
ck_assert_str_eq(boba217_s21, boba217);
}
END_TEST

START_TEST(bebasik__218) {
char boba218_s21[10000];
char boba218[10000];
ck_assert_int_eq(s21_sprintf(boba218_s21, "%-1dnb% 6.2hd^% .10hd%-uhc3% .3d%+9.9d#%+7hd% 3.3f#fd%+.10isa% .6i%+.4hi,;% 6.1f6%-.1hu*% 1.0hi%+4.5hi% 3.1hi6$% 5i", 877010, 14248, -30135, -814647, 448100, -521456, 29423, 6781.428167817455, -91849, -424780, 4509, -1950.4942619238052, -22301, 10396, -1065, 4758, 241794),
sprintf(boba218, "%-1dnb% 6.2hd^% .10hd%-uhc3% .3d%+9.9d#%+7hd% 3.3f#fd%+.10isa% .6i%+.4hi,;% 6.1f6%-.1hu*% 1.0hi%+4.5hi% 3.1hi6$% 5i", 877010, 14248, -30135, -814647, 448100, -521456, 29423, 6781.428167817455, -91849, -424780, 4509, -1950.4942619238052, -22301, 10396, -1065, 4758, 241794));
ck_assert_str_eq(boba218_s21, boba218);
}
END_TEST

START_TEST(bebasik__219) {
char boba219_s21[10000];
char boba219[10000];
ck_assert_int_eq(s21_sprintf(boba219_s21, "%-5cm&%+.4hdo", '=', 3810),
sprintf(boba219, "%-5cm&%+.4hdo", '=', 3810));
ck_assert_str_eq(boba219_s21, boba219);
}
END_TEST

START_TEST(bebasik__220) {
char boba220_s21[10000];
char boba220[10000];
ck_assert_int_eq(s21_sprintf(boba220_s21, "%+5hd%-7.6d(/% 6.0fb% .6i%+f/i%+.0hd%-6u9% i%-.5hi%+.5hdp%+6ibqm%+3.10iq%+fc4j%+2.7i%-1.8hda", -11114, -787507, 300.94348753633363, -254049, -5422.75921899646, 15201, -396852, 660051, -24804, -18709, 305554, 675601, -24818.55246879792, -628289, 25472),
sprintf(boba220, "%+5hd%-7.6d(/% 6.0fb% .6i%+f/i%+.0hd%-6u9% i%-.5hi%+.5hdp%+6ibqm%+3.10iq%+fc4j%+2.7i%-1.8hda", -11114, -787507, 300.94348753633363, -254049, -5422.75921899646, 15201, -396852, 660051, -24804, -18709, 305554, 675601, -24818.55246879792, -628289, 25472));
ck_assert_str_eq(boba220_s21, boba220);
}
END_TEST

START_TEST(bebasik__221) {
char boba221_s21[10000];
char boba221[10000];
ck_assert_int_eq(s21_sprintf(boba221_s21, "%+.2hi)!", 10175),
sprintf(boba221, "%+.2hi)!", 10175));
ck_assert_str_eq(boba221_s21, boba221);
}
END_TEST

START_TEST(bebasik__222) {
char boba222_s21[10000];
char boba222[10000];
ck_assert_int_eq(s21_sprintf(boba222_s21, "%+.8fg% 2in%-f% 4hd%-.5s/z%-.9di=%+6hd(rt#u%+.5hi(%-1i8%-c%-s%+4.10d% 7.0d% 4hd%+2hi31ld(q[%-i%+3.1hi% 6f;d%+hi", 962.1647085379772, 459103, -25608.342390376638, 30079, "/", -80773, 11809, -14632, 407367, '*', "*", 805827, -602012, 20471, 29007, -842803, -30040, -13914.421439103671, -18813),
sprintf(boba222, "%+.8fg% 2in%-f% 4hd%-.5s/z%-.9di=%+6hd(rt#u%+.5hi(%-1i8%-c%-s%+4.10d% 7.0d% 4hd%+2hi31ld(q[%-i%+3.1hi% 6f;d%+hi", 962.1647085379772, 459103, -25608.342390376638, 30079, "/", -80773, 11809, -14632, 407367, '*', "*", 805827, -602012, 20471, 29007, -842803, -30040, -13914.421439103671, -18813));
ck_assert_str_eq(boba222_s21, boba222);
}
END_TEST

START_TEST(bebasik__223) {
char boba223_s21[10000];
char boba223[10000];
ck_assert_int_eq(s21_sprintf(boba223_s21, "% f1#%-hi%+.3hdrut2`%-10.4u%-hu`i%-hi%-4s%-.9hd%+hdg&% .8is%+2hdu% 7hd% df1,n", -2248.9930234057274, -3548, -24062, 825284, 8569, -27466, "#k$5", -12416, -23935, -913023, -22407, 1207, 842714),
sprintf(boba223, "% f1#%-hi%+.3hdrut2`%-10.4u%-hu`i%-hi%-4s%-.9hd%+hdg&% .8is%+2hdu% 7hd% df1,n", -2248.9930234057274, -3548, -24062, 825284, 8569, -27466, "#k$5", -12416, -23935, -913023, -22407, 1207, 842714));
ck_assert_str_eq(boba223_s21, boba223);
}
END_TEST

START_TEST(bebasik__224) {
char boba224_s21[10000];
char boba224[10000];
ck_assert_int_eq(s21_sprintf(boba224_s21, "% 8hd%-9f%+i%+.6his% 9hi%+8.6hd% .1hd%-.7i%+1.0hdy%-7s%-.0hd%-7.10iqmu%-5.2i% 9.1hi,% .1i6d%+hdup% 3f3[%+6hd", 11264, 16194.299327948545, -92650, 29714, 8582, -28844, 4997, 803626, 6709, "bw&`", -730, -540894, -267468, 25316, 922019, -18737, 16487.325045850943, -24455),
sprintf(boba224, "% 8hd%-9f%+i%+.6his% 9hi%+8.6hd% .1hd%-.7i%+1.0hdy%-7s%-.0hd%-7.10iqmu%-5.2i% 9.1hi,% .1i6d%+hdup% 3f3[%+6hd", 11264, 16194.299327948545, -92650, 29714, 8582, -28844, 4997, 803626, 6709, "bw&`", -730, -540894, -267468, 25316, 922019, -18737, 16487.325045850943, -24455));
ck_assert_str_eq(boba224_s21, boba224);
}
END_TEST

START_TEST(bebasik__225) {
char boba225_s21[10000];
char boba225[10000];
ck_assert_int_eq(s21_sprintf(boba225_s21, "%-2c% 7.8hd0%+.7iy0%-7hi% 6i% d)% .2hd5l%+10d.xq89% 6.4fvz,hu$d% 1hd%-5.0u% .5do%+4.7i%-5c=%-i% 7ik% 4f% 7.3f% 5f", 'n', -9966, 488523, -3168, 132470, -941584, 23596, -782458, 20825.091134327275, -25317, 134311, 439572, -232797, 'b', 905108, -239789, 18486.757305713905, -1856.268753574169, 14202.92640362045),
sprintf(boba225, "%-2c% 7.8hd0%+.7iy0%-7hi% 6i% d)% .2hd5l%+10d.xq89% 6.4fvz,hu$d% 1hd%-5.0u% .5do%+4.7i%-5c=%-i% 7ik% 4f% 7.3f% 5f", 'n', -9966, 488523, -3168, 132470, -941584, 23596, -782458, 20825.091134327275, -25317, 134311, 439572, -232797, 'b', 905108, -239789, 18486.757305713905, -1856.268753574169, 14202.92640362045));
ck_assert_str_eq(boba225_s21, boba225);
}
END_TEST

START_TEST(bebasik__226) {
char boba226_s21[10000];
char boba226[10000];
ck_assert_int_eq(s21_sprintf(boba226_s21, "%-s45% 1i%+.1hd", ")g5$5e66h/.ljq*l=07", 706233, -16094),
sprintf(boba226, "%-s45% 1i%+.1hd", ")g5$5e66h/.ljq*l=07", 706233, -16094));
ck_assert_str_eq(boba226_s21, boba226);
}
END_TEST

START_TEST(bebasik__227) {
char boba227_s21[10000];
char boba227[10000];
ck_assert_int_eq(s21_sprintf(boba227_s21, "%+.7hdw", 6219),
sprintf(boba227, "%+.7hdw", 6219));
ck_assert_str_eq(boba227_s21, boba227);
}
END_TEST

START_TEST(bebasik__228) {
char boba228_s21[10000];
char boba228[10000];
ck_assert_int_eq(s21_sprintf(boba228_s21, "%+8.3hd%-hu,%+10hd#%+f%-.9i%+7hd%-.4hu% .9d%+5d(ds%+5hd%+9.2hiy% 3fkr%-.5hd%-d@z% f% hiz% d.% .1fnfq*", 22136, -11819, 18020, 16067.153777524602, 292487, 24235, 10621, -478382, -769432, -31741, 3081, 2547.458495376764, 3802, 462598, 14666.668154362438, -11394, 821487, 4016.387420341812),
sprintf(boba228, "%+8.3hd%-hu,%+10hd#%+f%-.9i%+7hd%-.4hu% .9d%+5d(ds%+5hd%+9.2hiy% 3fkr%-.5hd%-d@z% f% hiz% d.% .1fnfq*", 22136, -11819, 18020, 16067.153777524602, 292487, 24235, 10621, -478382, -769432, -31741, 3081, 2547.458495376764, 3802, 462598, 14666.668154362438, -11394, 821487, 4016.387420341812));
ck_assert_str_eq(boba228_s21, boba228);
}
END_TEST

START_TEST(bebasik__229) {
char boba229_s21[10000];
char boba229[10000];
ck_assert_int_eq(s21_sprintf(boba229_s21, "% hd%+.9hi% dm%+.3frts4%+.6i", -29016, 3621, -915044, -21006.28128801225, -846814),
sprintf(boba229, "% hd%+.9hi% dm%+.3frts4%+.6i", -29016, 3621, -915044, -21006.28128801225, -846814));
ck_assert_str_eq(boba229_s21, boba229);
}
END_TEST

START_TEST(bebasik__230) {
char boba230_s21[10000];
char boba230[10000];
ck_assert_int_eq(s21_sprintf(boba230_s21, "%+8hd-%+.5da%+.10hd%-.3u%+5.7hd*% 4hd%+3hdb-t[z%-.3i%-7d% 5hi%-.3hux%-9dw8%-sy", -23682, 601126, -22593, 498606, 12565, -14841, 28408, -331880, 749527, 7184, 25716, 791454, "wnjm^.d.-&@=14ib@q"),
sprintf(boba230, "%+8hd-%+.5da%+.10hd%-.3u%+5.7hd*% 4hd%+3hdb-t[z%-.3i%-7d% 5hi%-.3hux%-9dw8%-sy", -23682, 601126, -22593, 498606, 12565, -14841, 28408, -331880, 749527, 7184, 25716, 791454, "wnjm^.d.-&@=14ib@q"));
ck_assert_str_eq(boba230_s21, boba230);
}
END_TEST

START_TEST(bebasik__231) {
char boba231_s21[10000];
char boba231[10000];
ck_assert_int_eq(s21_sprintf(boba231_s21, "%-hi%+.4duw,% 10.0ddl[% hde!%+.4hdk% 1d)[%-4.3hd(%-.10hu9`-&o2u", -31491, 138265, 502346, -7051, 9747, 802860, -12122, 16678),
sprintf(boba231, "%-hi%+.4duw,% 10.0ddl[% hde!%+.4hdk% 1d)[%-4.3hd(%-.10hu9`-&o2u", -31491, 138265, 502346, -7051, 9747, 802860, -12122, 16678));
ck_assert_str_eq(boba231_s21, boba231);
}
END_TEST

START_TEST(bebasik__232) {
char boba232_s21[10000];
char boba232[10000];
ck_assert_int_eq(s21_sprintf(boba232_s21, "%+.9i!%+8.7hd%+hiu%+4f%+.9hi)%-.10hiroi)% hd%+hig/r4f;$% .2hix@%-5hi=% 3hi971h*#[s*%+hd^%-10.2f28% .6hi", -651823, 18007, 23743, -707.3105843647868, -17559, 13617, 24867, 29616, -11621, -22299, -6264, 2390, 5478.466992116542, -15626),
sprintf(boba232, "%+.9i!%+8.7hd%+hiu%+4f%+.9hi)%-.10hiroi)% hd%+hig/r4f;$% .2hix@%-5hi=% 3hi971h*#[s*%+hd^%-10.2f28% .6hi", -651823, 18007, 23743, -707.3105843647868, -17559, 13617, 24867, 29616, -11621, -22299, -6264, 2390, 5478.466992116542, -15626));
ck_assert_str_eq(boba232_s21, boba232);
}
END_TEST

START_TEST(bebasik__233) {
char boba233_s21[10000];
char boba233[10000];
ck_assert_int_eq(s21_sprintf(boba233_s21, "% .0f%-.0hd2% 7.8d=,g% 8d% hi%+2hi5(%-hi&%+.1hi%-hd%-3hi4p% f%-hi=f% .9i%+fq% .3f% 4hi%-hd%+.4i%-5f%-6f", -216.20946126053366, -14357, 917808, -238252, 27068, 26621, 30110, -27611, 12806, 25938, -3795.5772752783537, 8870, -240227, 2158.1825443809144, 19108.005495886962, -14205, -6652, 33899, 3544.90810644175, 1820.9673745326618),
sprintf(boba233, "% .0f%-.0hd2% 7.8d=,g% 8d% hi%+2hi5(%-hi&%+.1hi%-hd%-3hi4p% f%-hi=f% .9i%+fq% .3f% 4hi%-hd%+.4i%-5f%-6f", -216.20946126053366, -14357, 917808, -238252, 27068, 26621, 30110, -27611, 12806, 25938, -3795.5772752783537, 8870, -240227, 2158.1825443809144, 19108.005495886962, -14205, -6652, 33899, 3544.90810644175, 1820.9673745326618));
ck_assert_str_eq(boba233_s21, boba233);
}
END_TEST

START_TEST(bebasik__234) {
char boba234_s21[10000];
char boba234[10000];
ck_assert_int_eq(s21_sprintf(boba234_s21, "%-.6uf9(vq7% 3.10hd86,ye%+1.7hi%+.1hi%+hd%+9.10hd%+3.0hd%-3.10f% d% 2i^% 8.9hi% i0%-1.8hu%-1.6fs%+10.10i%-.4hd% 3.3d%+hi=v% 10.5hdy%-ij&,9y%+hi", 373548, 12517, -25349, -17557, -18596, 8629, -24294, -8651.73852083838, -945399, -722724, -25269, 817294, -13155, 3893.165406126753, -281339, -17678, -587858, -17652, -27880, 689493, 10711),
sprintf(boba234, "%-.6uf9(vq7% 3.10hd86,ye%+1.7hi%+.1hi%+hd%+9.10hd%+3.0hd%-3.10f% d% 2i^% 8.9hi% i0%-1.8hu%-1.6fs%+10.10i%-.4hd% 3.3d%+hi=v% 10.5hdy%-ij&,9y%+hi", 373548, 12517, -25349, -17557, -18596, 8629, -24294, -8651.73852083838, -945399, -722724, -25269, 817294, -13155, 3893.165406126753, -281339, -17678, -587858, -17652, -27880, 689493, 10711));
ck_assert_str_eq(boba234_s21, boba234);
}
END_TEST

START_TEST(bebasik__235) {
char boba235_s21[10000];
char boba235[10000];
ck_assert_int_eq(s21_sprintf(boba235_s21, "% 1f% .5hivjs%-1hd% hd%-2.0d)%+4.4dvi%+2hd%-5.2szr%-.0fi%+10.3hd% 1hd%+1.10hi% .8f%+f,/$%-7hu%+.10hi%+i/,%-.6s,%+7.4d^%+2.2hio;% 4.10hdhdj%+f%+7hi&", -20259.06414018841, -1477, 16504, -17187, -539135, 947921, 23953, "qx9s$w@5^#vl*6znq=/$k!^6", -2939.6214403640074, -9392, 8347, -12241, -3284.287879996205, -14642.275105389614, -30213, 2357, 891814, "pqv&q[ehk", -525747, -17171, -3463, -16371.511357479494, 22031),
sprintf(boba235, "% 1f% .5hivjs%-1hd% hd%-2.0d)%+4.4dvi%+2hd%-5.2szr%-.0fi%+10.3hd% 1hd%+1.10hi% .8f%+f,/$%-7hu%+.10hi%+i/,%-.6s,%+7.4d^%+2.2hio;% 4.10hdhdj%+f%+7hi&", -20259.06414018841, -1477, 16504, -17187, -539135, 947921, 23953, "qx9s$w@5^#vl*6znq=/$k!^6", -2939.6214403640074, -9392, 8347, -12241, -3284.287879996205, -14642.275105389614, -30213, 2357, 891814, "pqv&q[ehk", -525747, -17171, -3463, -16371.511357479494, 22031));
ck_assert_str_eq(boba235_s21, boba235);
}
END_TEST

START_TEST(bebasik__236) {
char boba236_s21[10000];
char boba236[10000];
ck_assert_int_eq(s21_sprintf(boba236_s21, "%+7f%-5hi%-8.0hd@fx%-6d%-1u% 2.9f% .4hit%+7.0i", 4686.617737553517, -30578, -7854, -573977, 169850, 14312.420195900824, -26385, 415219),
sprintf(boba236, "%+7f%-5hi%-8.0hd@fx%-6d%-1u% 2.9f% .4hit%+7.0i", 4686.617737553517, -30578, -7854, -573977, 169850, 14312.420195900824, -26385, 415219));
ck_assert_str_eq(boba236_s21, boba236);
}
END_TEST

START_TEST(bebasik__237) {
char boba237_s21[10000];
char boba237[10000];
ck_assert_int_eq(s21_sprintf(boba237_s21, "%+.2hi0%+hd*%-.5faf% 1i%-.8sr*`%+1im% hd0/% .8hi%+2dt%+.3d", -5409, -20282, 23801.9473672237, -708033, "i=4sdo(/5n2(urtg!fg-#", -923477, -8276, 31689, 204713, 345032),
sprintf(boba237, "%+.2hi0%+hd*%-.5faf% 1i%-.8sr*`%+1im% hd0/% .8hi%+2dt%+.3d", -5409, -20282, 23801.9473672237, -708033, "i=4sdo(/5n2(urtg!fg-#", -923477, -8276, 31689, 204713, 345032));
ck_assert_str_eq(boba237_s21, boba237);
}
END_TEST

START_TEST(bebasik__238) {
char boba238_s21[10000];
char boba238[10000];
ck_assert_int_eq(s21_sprintf(boba238_s21, "%-hi%+d% f%+f8%-1hu46j% 9f% 6.10dmmc% 3.8hi% il[%-5.7s%+6f", -16946, -488609, -438.54176811412975, 9585.41558834725, 15972, -1825.5256819964043, 874954, 22092, 335000, "t!r,yess3v5aam![!(3uy", -7041.755676774152),
sprintf(boba238, "%-hi%+d% f%+f8%-1hu46j% 9f% 6.10dmmc% 3.8hi% il[%-5.7s%+6f", -16946, -488609, -438.54176811412975, 9585.41558834725, 15972, -1825.5256819964043, 874954, 22092, 335000, "t!r,yess3v5aam![!(3uy", -7041.755676774152));
ck_assert_str_eq(boba238_s21, boba238);
}
END_TEST

START_TEST(bebasik__239) {
char boba239_s21[10000];
char boba239[10000];
ck_assert_int_eq(s21_sprintf(boba239_s21, "% .8i3%+9.6hiy%+.7d`%+1i0%-7.3hu%-hd% .8hdycd%+.4hdqpb%+10d8c2s%-9u% 3.10hi%-4hi%-.2iz!%-1hi%+.3hi%-hi% i% 8d;*", 538824, 23585, 760966, 438459, -25778, 3576, 15754, -23621, -25460, -661918, -30085, -24183, 735150, 28815, 13225, 11539, 846842, 469593),
sprintf(boba239, "% .8i3%+9.6hiy%+.7d`%+1i0%-7.3hu%-hd% .8hdycd%+.4hdqpb%+10d8c2s%-9u% 3.10hi%-4hi%-.2iz!%-1hi%+.3hi%-hi% i% 8d;*", 538824, 23585, 760966, 438459, -25778, 3576, 15754, -23621, -25460, -661918, -30085, -24183, 735150, 28815, 13225, 11539, 846842, 469593));
ck_assert_str_eq(boba239_s21, boba239);
}
END_TEST

START_TEST(bebasik__240) {
char boba240_s21[10000];
char boba240[10000];
ck_assert_int_eq(s21_sprintf(boba240_s21, "%-4.6d", 451634),
sprintf(boba240, "%-4.6d", 451634));
ck_assert_str_eq(boba240_s21, boba240);
}
END_TEST

START_TEST(bebasik__241) {
char boba241_s21[10000];
char boba241[10000];
ck_assert_int_eq(s21_sprintf(boba241_s21, "%-huw5%-2u0%+9d% d%+hd% .4fiq[46j(%+8f8% 9hi1l%-hisn[%-u%-6hi% 3.0d%-.5hi84s% 8.4dr% 5i%+f% .7hd% 9hi% 3.4hiiq0/%+hd,%+6.1hi% d%+i", -19440, -486347, -34771, 653806, 23414, -299.8206551845592, 4839.897670078694, -22650, -31788, -868574, 1940, 5805, -16709, -756221, 385531, -16123.609091359427, 3125, 14175, -13644, -10850, -12915, -546975, -812703),
sprintf(boba241, "%-huw5%-2u0%+9d% d%+hd% .4fiq[46j(%+8f8% 9hi1l%-hisn[%-u%-6hi% 3.0d%-.5hi84s% 8.4dr% 5i%+f% .7hd% 9hi% 3.4hiiq0/%+hd,%+6.1hi% d%+i", -19440, -486347, -34771, 653806, 23414, -299.8206551845592, 4839.897670078694, -22650, -31788, -868574, 1940, 5805, -16709, -756221, 385531, -16123.609091359427, 3125, 14175, -13644, -10850, -12915, -546975, -812703));
ck_assert_str_eq(boba241_s21, boba241);
}
END_TEST

START_TEST(bebasik__242) {
char boba242_s21[10000];
char boba242[10000];
ck_assert_int_eq(s21_sprintf(boba242_s21, "%+.7f%-u;% f7%-9.5ub% 8f%+8hd*2%+.1io%-.6hdi$% 4hd%-hu%+1hd% i6%+i0%-hi%+i%-2isv% 2.10i%+hic%+hd% i", -25687.07543819771, -570378, 8709.462559476999, -644301, -653.0081617849346, 7198, 391254, -21556, -15425, -12053, 2564, -288569, 636621, -11536, 806231, 843810, 2622, -3169, -20222, -256927),
sprintf(boba242, "%+.7f%-u;% f7%-9.5ub% 8f%+8hd*2%+.1io%-.6hdi$% 4hd%-hu%+1hd% i6%+i0%-hi%+i%-2isv% 2.10i%+hic%+hd% i", -25687.07543819771, -570378, 8709.462559476999, -644301, -653.0081617849346, 7198, 391254, -21556, -15425, -12053, 2564, -288569, 636621, -11536, 806231, 843810, 2622, -3169, -20222, -256927));
ck_assert_str_eq(boba242_s21, boba242);
}
END_TEST

START_TEST(bebasik__243) {
char boba243_s21[10000];
char boba243[10000];
ck_assert_int_eq(s21_sprintf(boba243_s21, "%+iz9%-8s;53% hidin%+.8hdx%-.7hu/gj%-1.0hi&-m)% 8hi5**1%+hio-e%-.2u,hyn1%-3dzx%+9fx-(% 1f%+.1f`% dcleu$%+.7hd`% .5i)@%+d% 8hi%-4hief%-hi% 4.3f", -847253, "!0otj1gi[.quqm,,^.d#)dsa", 7352, 2684, 2801, -19916, 23801, -4970, -6548, -676040, 11048.227680756607, -2891.2382096015194, -4976.995450091676, 935251, -22390, 145996, 991074, 24055, -17402, -24769, 13754.75451867193),
sprintf(boba243, "%+iz9%-8s;53% hidin%+.8hdx%-.7hu/gj%-1.0hi&-m)% 8hi5**1%+hio-e%-.2u,hyn1%-3dzx%+9fx-(% 1f%+.1f`% dcleu$%+.7hd`% .5i)@%+d% 8hi%-4hief%-hi% 4.3f", -847253, "!0otj1gi[.quqm,,^.d#)dsa", 7352, 2684, 2801, -19916, 23801, -4970, -6548, -676040, 11048.227680756607, -2891.2382096015194, -4976.995450091676, 935251, -22390, 145996, 991074, 24055, -17402, -24769, 13754.75451867193));
ck_assert_str_eq(boba243_s21, boba243);
}
END_TEST

START_TEST(bebasik__244) {
char boba244_s21[10000];
char boba244[10000];
ck_assert_int_eq(s21_sprintf(boba244_s21, "%-8f45%-hu)5o*%+2d%-.5hd%+i% 9d%+i.%+hi89)4b&ji% i%-7.5ujnz% .0hd0g% 9f%-3d=@%-f8%+.4hd`%+hd@% 3hdd", 1078.4352919797932, 10228, -946700, -10105, -561579, -894332, 641002, -10557, 28540, -705516, 2281, -14500.936316698046, 470778, -7246.157442170045, -13869, 16762, 25395),
sprintf(boba244, "%-8f45%-hu)5o*%+2d%-.5hd%+i% 9d%+i.%+hi89)4b&ji% i%-7.5ujnz% .0hd0g% 9f%-3d=@%-f8%+.4hd`%+hd@% 3hdd", 1078.4352919797932, 10228, -946700, -10105, -561579, -894332, 641002, -10557, 28540, -705516, 2281, -14500.936316698046, 470778, -7246.157442170045, -13869, 16762, 25395));
ck_assert_str_eq(boba244_s21, boba244);
}
END_TEST

START_TEST(bebasik__245) {
char boba245_s21[10000];
char boba245[10000];
ck_assert_int_eq(s21_sprintf(boba245_s21, "% i8%+1.7d% i%+3.0dm%-hi%+5.7f% hiiv% .3f56% 7.1hde)n% 3i&(v% .0hi3e% f0%+.0hdj% i%-.7d5d%-5sz(6`e[irz&%+de%-hi", -484026, -875991, 548364, -843309, -19776, 10165.373630316082, -11499, 8997.983898267656, 18475, -375678, -27704, 8068.73860769854, 18095, -167538, 378995, "9!`njo14)kw02j((`o*", 535203, 31454),
sprintf(boba245, "% i8%+1.7d% i%+3.0dm%-hi%+5.7f% hiiv% .3f56% 7.1hde)n% 3i&(v% .0hi3e% f0%+.0hdj% i%-.7d5d%-5sz(6`e[irz&%+de%-hi", -484026, -875991, 548364, -843309, -19776, 10165.373630316082, -11499, 8997.983898267656, 18475, -375678, -27704, 8068.73860769854, 18095, -167538, 378995, "9!`njo14)kw02j((`o*", 535203, 31454));
ck_assert_str_eq(boba245_s21, boba245);
}
END_TEST

START_TEST(bebasik__246) {
char boba246_s21[10000];
char boba246[10000];
ck_assert_int_eq(s21_sprintf(boba246_s21, "% 5d%-10.9f!% 4hd% 2hi%+2hd%+10.9d%+6.3hd%+2.7hi% .10i% hd%+2hi$$% .0hd% 8dm%+9.8d% f25#.%-hi%-7c%-3.1i% .1hd", 562913, -16658.427460506133, 2911, 11218, -16170, 239979, 13238, -30288, -313918, 17139, -20798, 22206, -857761, 23379, -2797.829403643503, -14131, 'k', -801393, -2547),
sprintf(boba246, "% 5d%-10.9f!% 4hd% 2hi%+2hd%+10.9d%+6.3hd%+2.7hi% .10i% hd%+2hi$$% .0hd% 8dm%+9.8d% f25#.%-hi%-7c%-3.1i% .1hd", 562913, -16658.427460506133, 2911, 11218, -16170, 239979, 13238, -30288, -313918, 17139, -20798, 22206, -857761, 23379, -2797.829403643503, -14131, 'k', -801393, -2547));
ck_assert_str_eq(boba246_s21, boba246);
}
END_TEST

START_TEST(bebasik__247) {
char boba247_s21[10000];
char boba247[10000];
ck_assert_int_eq(s21_sprintf(boba247_s21, "% 10.8d%-.7hu%-d%-7f1", 704597, 25523, -692049, 4043.816094449076),
sprintf(boba247, "% 10.8d%-.7hu%-d%-7f1", 704597, 25523, -692049, 4043.816094449076));
ck_assert_str_eq(boba247_s21, boba247);
}
END_TEST

START_TEST(bebasik__248) {
char boba248_s21[10000];
char boba248[10000];
ck_assert_int_eq(s21_sprintf(boba248_s21, "%-3hd&h4-% 5f%-.1hi%-.8hu% d31n%-1.0u", -27279, 12105.761303675807, 505, 29367, 706888, -557481),
sprintf(boba248, "%-3hd&h4-% 5f%-.1hi%-.8hu% d31n%-1.0u", -27279, 12105.761303675807, 505, 29367, 706888, -557481));
ck_assert_str_eq(boba248_s21, boba248);
}
END_TEST

START_TEST(bebasik__249) {
char boba249_s21[10000];
char boba249[10000];
ck_assert_int_eq(s21_sprintf(boba249_s21, "% d%+.5hdh$%-1.8d,!;%+10.10f%-3.3s%+9.2d;[6%-2hue% 2.8f% .6hd%-.7hu", -237833, -19503, -246269, 24965.24745753288, "*7st/w9fn;^", 686648, -7412, -1316.3136401205154, -20555, -17461),
sprintf(boba249, "% d%+.5hdh$%-1.8d,!;%+10.10f%-3.3s%+9.2d;[6%-2hue% 2.8f% .6hd%-.7hu", -237833, -19503, -246269, 24965.24745753288, "*7st/w9fn;^", 686648, -7412, -1316.3136401205154, -20555, -17461));
ck_assert_str_eq(boba249_s21, boba249);
}
END_TEST

START_TEST(bebasik__250) {
char boba250_s21[10000];
char boba250[10000];
ck_assert_int_eq(s21_sprintf(boba250_s21, "%+i%-.2us=79x%+6d%-.3hu%-.0id%-1ul3`y%-.10hu!w%+4.5hdh% 9.5d% f% 3.5hd% .0hdox", -283548, -273804, -444767, 15588, -49420, -70397, 16047, -13113, 959293, 1844.5170940747546, -13782, -11764),
sprintf(boba250, "%+i%-.2us=79x%+6d%-.3hu%-.0id%-1ul3`y%-.10hu!w%+4.5hdh% 9.5d% f% 3.5hd% .0hdox", -283548, -273804, -444767, 15588, -49420, -70397, 16047, -13113, 959293, 1844.5170940747546, -13782, -11764));
ck_assert_str_eq(boba250_s21, boba250);
}
END_TEST

START_TEST(bebasik__251) {
char boba251_s21[10000];
char boba251[10000];
ck_assert_int_eq(s21_sprintf(boba251_s21, "% .7hi% .0hd%-10.6hu% 1.6d1%-2iux%-.8hik%-4.7hi% 8.2hi% 6.0d%+9f!% d%+.8i%+f=% 4.2f%+3hd5*[zq", 3457, -14885, 5272, 510710, 420386, -18286, -12717, -17961, -838766, 73.73708902330833, 187986, -79306, -6002.253920552424, 1513.7485687675828, 11239),
sprintf(boba251, "% .7hi% .0hd%-10.6hu% 1.6d1%-2iux%-.8hik%-4.7hi% 8.2hi% 6.0d%+9f!% d%+.8i%+f=% 4.2f%+3hd5*[zq", 3457, -14885, 5272, 510710, 420386, -18286, -12717, -17961, -838766, 73.73708902330833, 187986, -79306, -6002.253920552424, 1513.7485687675828, 11239));
ck_assert_str_eq(boba251_s21, boba251);
}
END_TEST

START_TEST(bebasik__252) {
char boba252_s21[10000];
char boba252[10000];
ck_assert_int_eq(s21_sprintf(boba252_s21, "%+2hd9% hi% 10.1hiq%-hir% f%-dj%+5.1hd% .4ib9% .6i`%-.5s% .6hi%-10f,6s", -19426, 23580, -14581, 8310, -4226.501291872255, 687656, 28863, -279552, 274363, "87*;*fth1*k(zb*$x8v6k)ue,kek", -6588, 3635.277324583853),
sprintf(boba252, "%+2hd9% hi% 10.1hiq%-hir% f%-dj%+5.1hd% .4ib9% .6i`%-.5s% .6hi%-10f,6s", -19426, 23580, -14581, 8310, -4226.501291872255, 687656, 28863, -279552, 274363, "87*;*fth1*k(zb*$x8v6k)ue,kek", -6588, 3635.277324583853));
ck_assert_str_eq(boba252_s21, boba252);
}
END_TEST

START_TEST(bebasik__253) {
char boba253_s21[10000];
char boba253[10000];
ck_assert_int_eq(s21_sprintf(boba253_s21, "%+.2him0%+2f% .5dv% d% 1fn% .10hd%+.8i%+d,%-9.6hd%+1.4d% 2.1hdl6%+.10hiph)5@lq% hi% 9fk%+3f2pyl%-3.7hu7-pg% .6f%+.1i;", -21591, -17846.80843219481, -711007, -302743, -20754.638643155424, 20687, 67445, 483502, -30630, 353456, 2440, 23967, 67, -16158.04201557737, 983.3998101066218, 27040, -7926.941074131391, 251312),
sprintf(boba253, "%+.2him0%+2f% .5dv% d% 1fn% .10hd%+.8i%+d,%-9.6hd%+1.4d% 2.1hdl6%+.10hiph)5@lq% hi% 9fk%+3f2pyl%-3.7hu7-pg% .6f%+.1i;", -21591, -17846.80843219481, -711007, -302743, -20754.638643155424, 20687, 67445, 483502, -30630, 353456, 2440, 23967, 67, -16158.04201557737, 983.3998101066218, 27040, -7926.941074131391, 251312));
ck_assert_str_eq(boba253_s21, boba253);
}
END_TEST

START_TEST(bebasik__254) {
char boba254_s21[10000];
char boba254[10000];
ck_assert_int_eq(s21_sprintf(boba254_s21, "% 2f%+.10hi%+2.1hd%+.5i%-7.10hd%+hdw% 8d%+4.6i%-f%-4.3f%+2i%-9d%-f%+4.5f8)&%-6.1hui!opil", 520.6339494751238, 26131, -30450, -839338, -1915, -26392, 925966, 96178, 15514.233847267675, -4243.881595921975, -67646, -552429, 18089.242542375527, 4194.368446657312, 18333),
sprintf(boba254, "% 2f%+.10hi%+2.1hd%+.5i%-7.10hd%+hdw% 8d%+4.6i%-f%-4.3f%+2i%-9d%-f%+4.5f8)&%-6.1hui!opil", 520.6339494751238, 26131, -30450, -839338, -1915, -26392, 925966, 96178, 15514.233847267675, -4243.881595921975, -67646, -552429, 18089.242542375527, 4194.368446657312, 18333));
ck_assert_str_eq(boba254_s21, boba254);
}
END_TEST

START_TEST(bebasik__255) {
char boba255_s21[10000];
char boba255[10000];
ck_assert_int_eq(s21_sprintf(boba255_s21, "%-6.6hu[%+d%-6.0u% hd% hdt=% .0i/%+.2i%+hik;dz%+f)$% 7f$6e%-.3hi%-6u% 5dw%-9.5hd3(!%+6f%+i`$=(%+.3fl.5xl$12%-7.6hu#%-u%+7hi%+3i%-fi%-f", -271, -905924, 2439, -3581, 31010, -778031, 431813, -25193, 15716.842841623316, -29875.776084637386, 25742, -287208, -987098, -9721, 173.60204851866794, -605005, 7273.219969049019, 29001, 690810, 29519, 999878, 8930.575813287123, 1570.3207348190092),
sprintf(boba255, "%-6.6hu[%+d%-6.0u% hd% hdt=% .0i/%+.2i%+hik;dz%+f)$% 7f$6e%-.3hi%-6u% 5dw%-9.5hd3(!%+6f%+i`$=(%+.3fl.5xl$12%-7.6hu#%-u%+7hi%+3i%-fi%-f", -271, -905924, 2439, -3581, 31010, -778031, 431813, -25193, 15716.842841623316, -29875.776084637386, 25742, -287208, -987098, -9721, 173.60204851866794, -605005, 7273.219969049019, 29001, 690810, 29519, 999878, 8930.575813287123, 1570.3207348190092));
ck_assert_str_eq(boba255_s21, boba255);
}
END_TEST

START_TEST(bebasik__256) {
char boba256_s21[10000];
char boba256[10000];
ck_assert_int_eq(s21_sprintf(boba256_s21, "%-4.3d% 10.2hi,$3%-4.0s8c%+f/% 3.10d[%-s%-i% d%+4i% hd%-u% 3hd*%+d% 9.9f", -112029, -324, "81", -17429.97871354459, 881369, ",rrb!0z;^z!bu8&mvjm*a", 379025, 540573, 639217, 31597, -341984, -25875, -883137, 11049.690383075746),
sprintf(boba256, "%-4.3d% 10.2hi,$3%-4.0s8c%+f/% 3.10d[%-s%-i% d%+4i% hd%-u% 3hd*%+d% 9.9f", -112029, -324, "81", -17429.97871354459, 881369, ",rrb!0z;^z!bu8&mvjm*a", 379025, 540573, 639217, 31597, -341984, -25875, -883137, 11049.690383075746));
ck_assert_str_eq(boba256_s21, boba256);
}
END_TEST

START_TEST(bebasik__257) {
char boba257_s21[10000];
char boba257[10000];
ck_assert_int_eq(s21_sprintf(boba257_s21, "% 2f% .2hd@2%+d3% 6d-", -184.81343683514746, -26135, 784606, -756621),
sprintf(boba257, "% 2f% .2hd@2%+d3% 6d-", -184.81343683514746, -26135, 784606, -756621));
ck_assert_str_eq(boba257_s21, boba257);
}
END_TEST

START_TEST(bebasik__258) {
char boba258_s21[10000];
char boba258[10000];
ck_assert_int_eq(s21_sprintf(boba258_s21, "% dp%+fb6%+2.7d% 1hif%-huqn%-.3f%-.10s% .6f%-hu(0%-hd%-.10d7%-4hih^`%-3hd#)iu%+.5hi^*%+10.8hi%-9hd% 2hit/% 10i%+i%-1hdiq%-1.1hd)v% hi/%+9d#% hd", -520353, 511.1325013046352, 384514, -22820, -19403, 10064.12870845711, "k1nccvso*l=30d=6", 1916.6162025584827, 17470, -29796, -553011, 2875, 11659, -17972, 7059, 21272, -11517, 53260, -627657, 13237, -19396, -24150, 694824, 19814),
sprintf(boba258, "% dp%+fb6%+2.7d% 1hif%-huqn%-.3f%-.10s% .6f%-hu(0%-hd%-.10d7%-4hih^`%-3hd#)iu%+.5hi^*%+10.8hi%-9hd% 2hit/% 10i%+i%-1hdiq%-1.1hd)v% hi/%+9d#% hd", -520353, 511.1325013046352, 384514, -22820, -19403, 10064.12870845711, "k1nccvso*l=30d=6", 1916.6162025584827, 17470, -29796, -553011, 2875, 11659, -17972, 7059, 21272, -11517, 53260, -627657, 13237, -19396, -24150, 694824, 19814));
ck_assert_str_eq(boba258_s21, boba258);
}
END_TEST

START_TEST(bebasik__259) {
char boba259_s21[10000];
char boba259[10000];
ck_assert_int_eq(s21_sprintf(boba259_s21, "% d%+.5hi%-4.7hi%-.6u%+10i% him", 230562, 30611, 18977, -625392, 198733, 27106),
sprintf(boba259, "% d%+.5hi%-4.7hi%-.6u%+10i% him", 230562, 30611, 18977, -625392, 198733, 27106));
ck_assert_str_eq(boba259_s21, boba259);
}
END_TEST

START_TEST(bebasik__260) {
char boba260_s21[10000];
char boba260[10000];
ck_assert_int_eq(s21_sprintf(boba260_s21, "%-8c%-hu% hdt% 6.8hi%+3.5dt%+5hiki4%+icuq%+10.4hi1%-dq)%+.10hiliy/%+8.8hi%+.3i%+9.5d;%-10fb4/m%-8dad%-.4fpp%+.0d6%+ds% 4.7f8% d% hdt% d.eh*% .0hiy% 4hd", '/', -23575, 26401, 3486, 649349, -22012, -612407, -3032, -729820, -19781, 3553, -125507, -833520, -1346.641712733749, -857724, 7440.491431476306, 689788, -566559, 5034.606936839132, -854931, -12613, -474064, 10996, -11878),
sprintf(boba260, "%-8c%-hu% hdt% 6.8hi%+3.5dt%+5hiki4%+icuq%+10.4hi1%-dq)%+.10hiliy/%+8.8hi%+.3i%+9.5d;%-10fb4/m%-8dad%-.4fpp%+.0d6%+ds% 4.7f8% d% hdt% d.eh*% .0hiy% 4hd", '/', -23575, 26401, 3486, 649349, -22012, -612407, -3032, -729820, -19781, 3553, -125507, -833520, -1346.641712733749, -857724, 7440.491431476306, 689788, -566559, 5034.606936839132, -854931, -12613, -474064, 10996, -11878));
ck_assert_str_eq(boba260_s21, boba260);
}
END_TEST

START_TEST(bebasik__261) {
char boba261_s21[10000];
char boba261[10000];
ck_assert_int_eq(s21_sprintf(boba261_s21, "%-.0i5xpi% 5hd@4b3lw%+6.7hd3c6% .5hi55%+.3hd%-.8hd-9,-% 7hi%-d@=% .1hi`%-7.8u5%+7.10hi^%+4hd&7", 876184, 407, -27954, 13834, 28134, -10931, 19905, 554717, -5429, -704685, 18038, -20264),
sprintf(boba261, "%-.0i5xpi% 5hd@4b3lw%+6.7hd3c6% .5hi55%+.3hd%-.8hd-9,-% 7hi%-d@=% .1hi`%-7.8u5%+7.10hi^%+4hd&7", 876184, 407, -27954, 13834, 28134, -10931, 19905, 554717, -5429, -704685, 18038, -20264));
ck_assert_str_eq(boba261_s21, boba261);
}
END_TEST

START_TEST(bebasik__262) {
char boba262_s21[10000];
char boba262[10000];
ck_assert_int_eq(s21_sprintf(boba262_s21, "%+.3hd% 5hi;t/%+f%+1.4hi%+hizs%+6hiv%+4.10f%+.8i%+.2f@#gfp%+f% 5hi!0%+10.8hdw,-% 1hi@*j% hi% 10ih%+1.1hd42%+9d%-2s% .2hd", 706, 18319, 1590.2318595263644, 20984, -31038, 29593, -2546.301201913199, 442764, 465.9601952245819, 18267.871804354567, 26982, 21750, -5760, -3324, -644493, 11612, -676596, "`q@f.#87#b9z123cv(mxn`ue", 14546),
sprintf(boba262, "%+.3hd% 5hi;t/%+f%+1.4hi%+hizs%+6hiv%+4.10f%+.8i%+.2f@#gfp%+f% 5hi!0%+10.8hdw,-% 1hi@*j% hi% 10ih%+1.1hd42%+9d%-2s% .2hd", 706, 18319, 1590.2318595263644, 20984, -31038, 29593, -2546.301201913199, 442764, 465.9601952245819, 18267.871804354567, 26982, 21750, -5760, -3324, -644493, 11612, -676596, "`q@f.#87#b9z123cv(mxn`ue", 14546));
ck_assert_str_eq(boba262_s21, boba262);
}
END_TEST

START_TEST(bebasik__263) {
char boba263_s21[10000];
char boba263[10000];
ck_assert_int_eq(s21_sprintf(boba263_s21, "%+.6hde7% .8hi% .1fb$-%-7hu%-f6%-9hd08%-.3dxt%+2hd[% 9i", -384, -31226, 1650.847574921859, 16143, 19304.60317230418, -18171, 506661, -25898, -468096),
sprintf(boba263, "%+.6hde7% .8hi% .1fb$-%-7hu%-f6%-9hd08%-.3dxt%+2hd[% 9i", -384, -31226, 1650.847574921859, 16143, 19304.60317230418, -18171, 506661, -25898, -468096));
ck_assert_str_eq(boba263_s21, boba263);
}
END_TEST

START_TEST(bebasik__264) {
char boba264_s21[10000];
char boba264[10000];
ck_assert_int_eq(s21_sprintf(boba264_s21, "% i74h% hd/f8@0", -315786, -30985),
sprintf(boba264, "% i74h% hd/f8@0", -315786, -30985));
ck_assert_str_eq(boba264_s21, boba264);
}
END_TEST

START_TEST(bebasik__265) {
char boba265_s21[10000];
char boba265[10000];
ck_assert_int_eq(s21_sprintf(boba265_s21, "%-.1u%+2d=%+1hit%+hd;#c9s%+f%+.6fj$m% .3hi[% hi.[*t`594%-4.9dh% 4f8w%+2f%+9.9ft80%-6.1ij%-4c% 8.8hd0t% 8.7hd3%+hdm%-hd%-1.9hu).", -879898, -811900, -18846, -24731, -6388.409601233342, 125.86402968771577, 24833, -30577, 6606, 6742.730924109176, 2984.128424805718, -24185.8252785677, 59806, 'p', -5731, 3784, 581, 13442, 20297),
sprintf(boba265, "%-.1u%+2d=%+1hit%+hd;#c9s%+f%+.6fj$m% .3hi[% hi.[*t`594%-4.9dh% 4f8w%+2f%+9.9ft80%-6.1ij%-4c% 8.8hd0t% 8.7hd3%+hdm%-hd%-1.9hu).", -879898, -811900, -18846, -24731, -6388.409601233342, 125.86402968771577, 24833, -30577, 6606, 6742.730924109176, 2984.128424805718, -24185.8252785677, 59806, 'p', -5731, 3784, 581, 13442, 20297));
ck_assert_str_eq(boba265_s21, boba265);
}
END_TEST

START_TEST(bebasik__266) {
char boba266_s21[10000];
char boba266[10000];
ck_assert_int_eq(s21_sprintf(boba266_s21, "%+hd%+9diw.%+9.4hi05% 10.4hd%-hu%+hi", 25660, 834407, 17960, 20388, 17120, 16272),
sprintf(boba266, "%+hd%+9diw.%+9.4hi05% 10.4hd%-hu%+hi", 25660, 834407, 17960, 20388, 17120, 16272));
ck_assert_str_eq(boba266_s21, boba266);
}
END_TEST

START_TEST(bebasik__267) {
char boba267_s21[10000];
char boba267[10000];
ck_assert_int_eq(s21_sprintf(boba267_s21, "%+9.0hd% 2.0i$h%-7.9hi%-.6hi*2`/t%-.8hus%-2ci%-5s*w", 26301, -64576, 21852, 13331, 3939, '6', "m[$k46n72r@vl16c"),
sprintf(boba267, "%+9.0hd% 2.0i$h%-7.9hi%-.6hi*2`/t%-.8hus%-2ci%-5s*w", 26301, -64576, 21852, 13331, 3939, '6', "m[$k46n72r@vl16c"));
ck_assert_str_eq(boba267_s21, boba267);
}
END_TEST

START_TEST(bebasik__268) {
char boba268_s21[10000];
char boba268[10000];
ck_assert_int_eq(s21_sprintf(boba268_s21, "%-10i% 1f%+.7i7r1%+.6hdc%-7.0hi1),u%-.7f%-d.w1%+10hi", -450372, -5137.531170187369, -680762, -18727, -5503, 5102.350905534826, 319646, 19610),
sprintf(boba268, "%-10i% 1f%+.7i7r1%+.6hdc%-7.0hi1),u%-.7f%-d.w1%+10hi", -450372, -5137.531170187369, -680762, -18727, -5503, 5102.350905534826, 319646, 19610));
ck_assert_str_eq(boba268_s21, boba268);
}
END_TEST

START_TEST(bebasik__269) {
char boba269_s21[10000];
char boba269[10000];
ck_assert_int_eq(s21_sprintf(boba269_s21, "%+hd%-.3hi0%-4.7d%-2hu%-.9i%-9.0hu104% 1.3hd%+.4hdhb2% 2hd%+7.0d).7tq.%-hd05%+5d%+8.8hdt*w=% .8dq%+hd", -21943, 30511, -866424, 20271, -808761, -5295, -1892, 13524, 1611, -176173, 22821, 175836, 6219, 681397, 5391),
sprintf(boba269, "%+hd%-.3hi0%-4.7d%-2hu%-.9i%-9.0hu104% 1.3hd%+.4hdhb2% 2hd%+7.0d).7tq.%-hd05%+5d%+8.8hdt*w=% .8dq%+hd", -21943, 30511, -866424, 20271, -808761, -5295, -1892, 13524, 1611, -176173, 22821, 175836, 6219, 681397, 5391));
ck_assert_str_eq(boba269_s21, boba269);
}
END_TEST

START_TEST(bebasik__270) {
char boba270_s21[10000];
char boba270[10000];
ck_assert_int_eq(s21_sprintf(boba270_s21, "%+10hd8%-6.1hd/9h3%-.9hd%+8.2f,%-3.2hd3%-9.8u8o7%-9.8hiw%+2i% .4d%-hd% hd%+hd.%+hii%-4.0dwp%+10f(", 30257, 20045, 887, 4571.100739954101, 558, 674006, 2401, -638550, -416947, -26181, 5133, -14835, -22726, 467264, 4348.262459263308),
sprintf(boba270, "%+10hd8%-6.1hd/9h3%-.9hd%+8.2f,%-3.2hd3%-9.8u8o7%-9.8hiw%+2i% .4d%-hd% hd%+hd.%+hii%-4.0dwp%+10f(", 30257, 20045, 887, 4571.100739954101, 558, 674006, 2401, -638550, -416947, -26181, 5133, -14835, -22726, 467264, 4348.262459263308));
ck_assert_str_eq(boba270_s21, boba270);
}
END_TEST

START_TEST(bebasik__271) {
char boba271_s21[10000];
char boba271[10000];
ck_assert_int_eq(s21_sprintf(boba271_s21, "% hi% de% 9.1hd$7[0%-5hiab6u%+9.0f%-3hd%-.10hu%-fe^%+6f%+.6hi3% 9.4hi$% 7.2i% .7hdu%+.0i9%+8.6i&t%-7f%+.4hiy.% .8hi% .2hd%+5f5,%-9d% .4hiwj% d% 4hdq", 7833, 777302, 27416, 17225, 5193.072784958754, 14343, 9113, 855.6330023306253, 859.6497240325282, -29506, -15304, -962927, -6873, -876553, -444171, -181.9530584246731, 25226, 6747, -12785, -7038.1242187457065, 592092, 30605, -328756, 9773),
sprintf(boba271, "% hi% de% 9.1hd$7[0%-5hiab6u%+9.0f%-3hd%-.10hu%-fe^%+6f%+.6hi3% 9.4hi$% 7.2i% .7hdu%+.0i9%+8.6i&t%-7f%+.4hiy.% .8hi% .2hd%+5f5,%-9d% .4hiwj% d% 4hdq", 7833, 777302, 27416, 17225, 5193.072784958754, 14343, 9113, 855.6330023306253, 859.6497240325282, -29506, -15304, -962927, -6873, -876553, -444171, -181.9530584246731, 25226, 6747, -12785, -7038.1242187457065, 592092, 30605, -328756, 9773));
ck_assert_str_eq(boba271_s21, boba271);
}
END_TEST

START_TEST(bebasik__272) {
char boba272_s21[10000];
char boba272[10000];
ck_assert_int_eq(s21_sprintf(boba272_s21, "%-10.2i% dd%-u%-.1hi%-2c&%-1.1huw%+.8di(5[=%-10hds%-.5hdy% 2hd%+8hd%+6.4f16", 506392, 328348, -99556, -23607, 'k', -13595, 254421, -9972, -4618, -2049, 1608, 10767.867635403905),
sprintf(boba272, "%-10.2i% dd%-u%-.1hi%-2c&%-1.1huw%+.8di(5[=%-10hds%-.5hdy% 2hd%+8hd%+6.4f16", 506392, 328348, -99556, -23607, 'k', -13595, 254421, -9972, -4618, -2049, 1608, 10767.867635403905));
ck_assert_str_eq(boba272_s21, boba272);
}
END_TEST

START_TEST(bebasik__273) {
char boba273_s21[10000];
char boba273[10000];
ck_assert_int_eq(s21_sprintf(boba273_s21, "%+8.10i=% .0i% 6.7ifrhwq% .9i=0q%+8.3fn% hde% .2his5% 10hd4g%+hi% .5hd.%-2hu% .9f%+d% .6hi(%-.4hu%-6f% 4fna%+.3i", -727274, 285128, -413994, 365005, -23440.830507632945, -1361, 5138, -27836, 11929, 13988, 10594, 10680.127469841496, 555935, -21863, 5144, -12199.00930100327, -9780.912997422545, 201232),
sprintf(boba273, "%+8.10i=% .0i% 6.7ifrhwq% .9i=0q%+8.3fn% hde% .2his5% 10hd4g%+hi% .5hd.%-2hu% .9f%+d% .6hi(%-.4hu%-6f% 4fna%+.3i", -727274, 285128, -413994, 365005, -23440.830507632945, -1361, 5138, -27836, 11929, 13988, 10594, 10680.127469841496, 555935, -21863, 5144, -12199.00930100327, -9780.912997422545, 201232));
ck_assert_str_eq(boba273_s21, boba273);
}
END_TEST

START_TEST(bebasik__274) {
char boba274_s21[10000];
char boba274[10000];
ck_assert_int_eq(s21_sprintf(boba274_s21, "%-.7u% .5hi%-3.4hi%+.1f-%+d4i6%-9hd%-hi/&%-.8dp%-hd%+.2hd1f% .8i%+d65% hd%-8.4sh##%-2.1hi% .4hd%+9.1iv%-6.9d% hi=ate%-hih%-2i", -108003, 28411, -528, -16253.506217527227, -662086, -15481, 3328, 595465, -31702, -14615, -401683, 538294, -16810, "1(b20to6aidt*4[mhp8", 10259, -10295, 202437, -15947, -30697, -7988, 272870),
sprintf(boba274, "%-.7u% .5hi%-3.4hi%+.1f-%+d4i6%-9hd%-hi/&%-.8dp%-hd%+.2hd1f% .8i%+d65% hd%-8.4sh##%-2.1hi% .4hd%+9.1iv%-6.9d% hi=ate%-hih%-2i", -108003, 28411, -528, -16253.506217527227, -662086, -15481, 3328, 595465, -31702, -14615, -401683, 538294, -16810, "1(b20to6aidt*4[mhp8", 10259, -10295, 202437, -15947, -30697, -7988, 272870));
ck_assert_str_eq(boba274_s21, boba274);
}
END_TEST

START_TEST(bebasik__275) {
char boba275_s21[10000];
char boba275[10000];
ck_assert_int_eq(s21_sprintf(boba275_s21, "%+.5hdw%-10d$%+hiv45c%-2his(hzx/% .6i%-.9f[!r%+d`%-6.5i%-huh50`%-6.1hd%+10hi%-8.10ft%-4.0s%-2hdqna%-.5hi% 8.6f", -28285, -43590, -31010, -21924, 452045, -7329.300820657605, -758164, -703159, 14813, 15792, 24941, 9666.11074634478, "rjnahxl,y25ox", 9798, 28339, -10736.216230692035),
sprintf(boba275, "%+.5hdw%-10d$%+hiv45c%-2his(hzx/% .6i%-.9f[!r%+d`%-6.5i%-huh50`%-6.1hd%+10hi%-8.10ft%-4.0s%-2hdqna%-.5hi% 8.6f", -28285, -43590, -31010, -21924, 452045, -7329.300820657605, -758164, -703159, 14813, 15792, 24941, 9666.11074634478, "rjnahxl,y25ox", 9798, 28339, -10736.216230692035));
ck_assert_str_eq(boba275_s21, boba275);
}
END_TEST

START_TEST(bebasik__276) {
char boba276_s21[10000];
char boba276[10000];
ck_assert_int_eq(s21_sprintf(boba276_s21, "%-4i%+hiaf%-hd2(=6g%+.6it", -745813, -28616, 31731, 461872),
sprintf(boba276, "%-4i%+hiaf%-hd2(=6g%+.6it", -745813, -28616, 31731, 461872));
ck_assert_str_eq(boba276_s21, boba276);
}
END_TEST

START_TEST(bebasik__277) {
char boba277_s21[10000];
char boba277[10000];
ck_assert_int_eq(s21_sprintf(boba277_s21, "%-c%+.0d", '&', 704774),
sprintf(boba277, "%-c%+.0d", '&', 704774));
ck_assert_str_eq(boba277_s21, boba277);
}
END_TEST

START_TEST(bebasik__278) {
char boba278_s21[10000];
char boba278[10000];
ck_assert_int_eq(s21_sprintf(boba278_s21, "%-cd%-5.3io6.0%-7.8d%+8.4hdz%-himh$% hi.% 9f% 5.1i%-.6d-tga% f% 1.6hi% hd%+6.7f#%-.6hu% hif1sjp1`8%+10hifd% 7hd% 4.10d66% .6fe.ly%+hd", 'z', 816857, -74063, 15195, 20007, 31470, 663.3726377418851, 322877, 624782, -13927.863618193987, -14358, 14723, 6789.129054851559, -8437, 1956, 3577, 31302, -828035, 8617.60731151927, 30319),
sprintf(boba278, "%-cd%-5.3io6.0%-7.8d%+8.4hdz%-himh$% hi.% 9f% 5.1i%-.6d-tga% f% 1.6hi% hd%+6.7f#%-.6hu% hif1sjp1`8%+10hifd% 7hd% 4.10d66% .6fe.ly%+hd", 'z', 816857, -74063, 15195, 20007, 31470, 663.3726377418851, 322877, 624782, -13927.863618193987, -14358, 14723, 6789.129054851559, -8437, 1956, 3577, 31302, -828035, 8617.60731151927, 30319));
ck_assert_str_eq(boba278_s21, boba278);
}
END_TEST

START_TEST(bebasik__279) {
char boba279_s21[10000];
char boba279[10000];
ck_assert_int_eq(s21_sprintf(boba279_s21, "%-2.9i^%+4.3f%+d%+2i%+1hd%-5f%-8.6hu.%-hd4% hi%-7.1d%-fy%-c% .9hi/% 3.3fo%+hdn%-2hu%+hi%-dl%-1.1huz/2i/;%-.4u% 2hdp% 8i%+1.0f%+1hiv", -816892, -10329.083376611381, -984851, 329046, -8666, -3611.163682838364, 13964, -7212, -29894, -154825, -21663.564229302483, '.', -14784, 7836.4699078232525, -263, 16572, -22245, 581782, -19139, -534728, -9281, -799153, -6756.543652116223, -13150),
sprintf(boba279, "%-2.9i^%+4.3f%+d%+2i%+1hd%-5f%-8.6hu.%-hd4% hi%-7.1d%-fy%-c% .9hi/% 3.3fo%+hdn%-2hu%+hi%-dl%-1.1huz/2i/;%-.4u% 2hdp% 8i%+1.0f%+1hiv", -816892, -10329.083376611381, -984851, 329046, -8666, -3611.163682838364, 13964, -7212, -29894, -154825, -21663.564229302483, '.', -14784, 7836.4699078232525, -263, 16572, -22245, 581782, -19139, -534728, -9281, -799153, -6756.543652116223, -13150));
ck_assert_str_eq(boba279_s21, boba279);
}
END_TEST

START_TEST(bebasik__280) {
char boba280_s21[10000];
char boba280[10000];
ck_assert_int_eq(s21_sprintf(boba280_s21, "%+.9hd%+f,%-2.10u%-8hd% i%-8fz-n%+4hd%-4hd%+.10d% .7i0%+.4d%-7.2i%+.2db%-c% hd^tp", -18787, -4529.454210910731, -423630, 27986, -340882, 1767.5693595497808, -6250, -28829, -555332, 914736, 426052, 786833, -377767, '2', -26173),
sprintf(boba280, "%+.9hd%+f,%-2.10u%-8hd% i%-8fz-n%+4hd%-4hd%+.10d% .7i0%+.4d%-7.2i%+.2db%-c% hd^tp", -18787, -4529.454210910731, -423630, 27986, -340882, 1767.5693595497808, -6250, -28829, -555332, 914736, 426052, 786833, -377767, '2', -26173));
ck_assert_str_eq(boba280_s21, boba280);
}
END_TEST

START_TEST(bebasik__281) {
char boba281_s21[10000];
char boba281[10000];
ck_assert_int_eq(s21_sprintf(boba281_s21, "% 4.5iu%+.8hi% 7.4higg%+.1hd%+.2hi%+10hi!aor%+i%-3hu% 9d% 9f%+hd%-7.8hi%+10.4hi5%+hi,%-hd% 3.7is%-4hu% hi", -506717, 22810, -14598, 25564, 29126, 17600, 208246, 9723, 378888, 13507.970098837763, 15582, 3372, 22033, -12512, 28558, 337929, -30551, -17659),
sprintf(boba281, "% 4.5iu%+.8hi% 7.4higg%+.1hd%+.2hi%+10hi!aor%+i%-3hu% 9d% 9f%+hd%-7.8hi%+10.4hi5%+hi,%-hd% 3.7is%-4hu% hi", -506717, 22810, -14598, 25564, 29126, 17600, 208246, 9723, 378888, 13507.970098837763, 15582, 3372, 22033, -12512, 28558, 337929, -30551, -17659));
ck_assert_str_eq(boba281_s21, boba281);
}
END_TEST

START_TEST(bebasik__282) {
char boba282_s21[10000];
char boba282[10000];
ck_assert_int_eq(s21_sprintf(boba282_s21, "%+5i% 5hdv6;", -687040, -25021),
sprintf(boba282, "%+5i% 5hdv6;", -687040, -25021));
ck_assert_str_eq(boba282_s21, boba282);
}
END_TEST

START_TEST(bebasik__283) {
char boba283_s21[10000];
char boba283[10000];
ck_assert_int_eq(s21_sprintf(boba283_s21, "%-.9hd6/%+hi% 4f`% hd%-s;$% 10d2% 10d(%-d,b%-.1hii%+10.3hii[%-1.3hd", 20166, 23243, 9776.41014737564, -464, "x07qnng!r6`hzsw-$&qfm", -52271, -285633, -93866, 28971, -14824, 22710),
sprintf(boba283, "%-.9hd6/%+hi% 4f`% hd%-s;$% 10d2% 10d(%-d,b%-.1hii%+10.3hii[%-1.3hd", 20166, 23243, 9776.41014737564, -464, "x07qnng!r6`hzsw-$&qfm", -52271, -285633, -93866, 28971, -14824, 22710));
ck_assert_str_eq(boba283_s21, boba283);
}
END_TEST

START_TEST(bebasik__284) {
char boba284_s21[10000];
char boba284[10000];
ck_assert_int_eq(s21_sprintf(boba284_s21, "% i%+8hdl%+i75-1jy%-u% 4i!*l%-7.6hig)y5[%-.1hi%+.1flsl,%-2.8huf!%-.4i%-4hi%-2.0ieu$cf%+.3hdkx", 74687, 510, 784871, 932884, -226145, -2786, 24326, -19656.893833723767, -16456, -458853, -13105, 980941, 24861),
sprintf(boba284, "% i%+8hdl%+i75-1jy%-u% 4i!*l%-7.6hig)y5[%-.1hi%+.1flsl,%-2.8huf!%-.4i%-4hi%-2.0ieu$cf%+.3hdkx", 74687, 510, 784871, 932884, -226145, -2786, 24326, -19656.893833723767, -16456, -458853, -13105, 980941, 24861));
ck_assert_str_eq(boba284_s21, boba284);
}
END_TEST

START_TEST(bebasik__285) {
char boba285_s21[10000];
char boba285[10000];
ck_assert_int_eq(s21_sprintf(boba285_s21, "%-9.9s% hd% .8i%+1fb[% 2.1i7% 8hi0%-.9hi%+.2hih8,f%+.3hdy(%-9.10sb0)/% 8hd", "jdafc;9(@`sn*=l,edg;*;;*hxz7l", -23896, -902212, -15589.094086809182, 846276, -24795, 4310, 19022, -31294, ")*(1cgtf=[lv/fc*7h", 29785),
sprintf(boba285, "%-9.9s% hd% .8i%+1fb[% 2.1i7% 8hi0%-.9hi%+.2hih8,f%+.3hdy(%-9.10sb0)/% 8hd", "jdafc;9(@`sn*=l,edg;*;;*hxz7l", -23896, -902212, -15589.094086809182, 846276, -24795, 4310, 19022, -31294, ")*(1cgtf=[lv/fc*7h", 29785));
ck_assert_str_eq(boba285_s21, boba285);
}
END_TEST

START_TEST(bebasik__286) {
char boba286_s21[10000];
char boba286[10000];
ck_assert_int_eq(s21_sprintf(boba286_s21, "%-10fm%+8.1hi% .2hi%+fbh% 6hi3-%-8.3f%-hi9x", 9210.71723471178, 13460, 13123, 1920.0615670370337, -4511, -11623.144308129407, 28667),
sprintf(boba286, "%-10fm%+8.1hi% .2hi%+fbh% 6hi3-%-8.3f%-hi9x", 9210.71723471178, 13460, 13123, 1920.0615670370337, -4511, -11623.144308129407, 28667));
ck_assert_str_eq(boba286_s21, boba286);
}
END_TEST

START_TEST(bebasik__287) {
char boba287_s21[10000];
char boba287[10000];
ck_assert_int_eq(s21_sprintf(boba287_s21, "%+4hi%-9d3*d%+.6hd%-huo%+5.8hdl3% 3.10hd`% 6hi5%-7hi%-1.9hu%-8.10sct%-1hu%-1u%-9.7hu9% 7.5hd%-.9hu%-6hi%+.4hd%-10s@/h8%+9d", 11090, -191011, -19452, 7503, 11103, 10194, -18441, -341, -24645, "v&yderb;t&i.2t4r3c[fte48i!", 26953, 223091, 11953, -21670, 6405, 20529, -22273, "3", 158187),
sprintf(boba287, "%+4hi%-9d3*d%+.6hd%-huo%+5.8hdl3% 3.10hd`% 6hi5%-7hi%-1.9hu%-8.10sct%-1hu%-1u%-9.7hu9% 7.5hd%-.9hu%-6hi%+.4hd%-10s@/h8%+9d", 11090, -191011, -19452, 7503, 11103, 10194, -18441, -341, -24645, "v&yderb;t&i.2t4r3c[fte48i!", 26953, 223091, 11953, -21670, 6405, 20529, -22273, "3", 158187));
ck_assert_str_eq(boba287_s21, boba287);
}
END_TEST

START_TEST(bebasik__288) {
char boba288_s21[10000];
char boba288[10000];
ck_assert_int_eq(s21_sprintf(boba288_s21, "% .4i% 7.4hd-%+his(,%+f`j% dg% 9.10dq%+.8i%+hdxipl%-.7hd2% hi`0%+ds*% .6hi%+f% .1d%+7.6hdj% .8fh%-c%+6hd@", 545421, -11430, 3902, -1872.4103269609814, -520121, -711512, 690065, -8015, -23083, 25861, -169832, -17652, -12902.435738388225, 238622, -17738, -10664.290773337718, 'v', 1499),
sprintf(boba288, "% .4i% 7.4hd-%+his(,%+f`j% dg% 9.10dq%+.8i%+hdxipl%-.7hd2% hi`0%+ds*% .6hi%+f% .1d%+7.6hdj% .8fh%-c%+6hd@", 545421, -11430, 3902, -1872.4103269609814, -520121, -711512, 690065, -8015, -23083, 25861, -169832, -17652, -12902.435738388225, 238622, -17738, -10664.290773337718, 'v', 1499));
ck_assert_str_eq(boba288_s21, boba288);
}
END_TEST

START_TEST(bebasik__289) {
char boba289_s21[10000];
char boba289[10000];
ck_assert_int_eq(s21_sprintf(boba289_s21, "%-5.3hi!% hd%+f% 7.5hd% d% 6hiq(%-10.7hu%+.10fllom@97%-hiyz*f%+.7f%-5.10hi*7%+7.9hi%-hd% 8dh3% 1hi=%-.10hu%-.6d6c%+d%+hdj%-svn%-1hd%-10.0d&", -1357, 25534, -6757.47322538019, -1391, -103120, 10213, -30175, 3057.4263527538014, -7418, 270.3197283567904, 11037, 14738, -20120, 86531, -18294, -25526, -612077, -711704, -30671, ";", -15448, 688374),
sprintf(boba289, "%-5.3hi!% hd%+f% 7.5hd% d% 6hiq(%-10.7hu%+.10fllom@97%-hiyz*f%+.7f%-5.10hi*7%+7.9hi%-hd% 8dh3% 1hi=%-.10hu%-.6d6c%+d%+hdj%-svn%-1hd%-10.0d&", -1357, 25534, -6757.47322538019, -1391, -103120, 10213, -30175, 3057.4263527538014, -7418, 270.3197283567904, 11037, 14738, -20120, 86531, -18294, -25526, -612077, -711704, -30671, ";", -15448, 688374));
ck_assert_str_eq(boba289_s21, boba289);
}
END_TEST

START_TEST(bebasik__290) {
char boba290_s21[10000];
char boba290[10000];
ck_assert_int_eq(s21_sprintf(boba290_s21, "% 2.6hd-930b,d@%-5i%-d(%+7da%-.9sbc)*%-7.5ucf%-9.2huc%+5.7hda%+hdv%-hd^% 4d% 5.10hdx&&%+10.9hd%+.3hdh%-8.8dj% fd%-5.2hud%-6hu%+9.8hiq% 2.0dnsr", 10971, -183450, -305668, 96899, "h1d)bpw3d#,p$96m8a#j^^fs", 349289, -6616, -8954, 6715, -11813, 70079, 7817, -16064, 24935, 860361, 1648.1994673463882, 28585, 21355, -26073, 44000),
sprintf(boba290, "% 2.6hd-930b,d@%-5i%-d(%+7da%-.9sbc)*%-7.5ucf%-9.2huc%+5.7hda%+hdv%-hd^% 4d% 5.10hdx&&%+10.9hd%+.3hdh%-8.8dj% fd%-5.2hud%-6hu%+9.8hiq% 2.0dnsr", 10971, -183450, -305668, 96899, "h1d)bpw3d#,p$96m8a#j^^fs", 349289, -6616, -8954, 6715, -11813, 70079, 7817, -16064, 24935, 860361, 1648.1994673463882, 28585, 21355, -26073, 44000));
ck_assert_str_eq(boba290_s21, boba290);
}
END_TEST

START_TEST(bebasik__291) {
char boba291_s21[10000];
char boba291[10000];
ck_assert_int_eq(s21_sprintf(boba291_s21, "%+d9=%-3.4i%-hu*6%+10hd%+hdds%+2i,2kh%+hd% 2fs%+1.7i%+hi", -867038, -317068, -19085, -27576, -15463, -649854, -18588, -2297.859658736387, -63569, 3737),
sprintf(boba291, "%+d9=%-3.4i%-hu*6%+10hd%+hdds%+2i,2kh%+hd% 2fs%+1.7i%+hi", -867038, -317068, -19085, -27576, -15463, -649854, -18588, -2297.859658736387, -63569, 3737));
ck_assert_str_eq(boba291_s21, boba291);
}
END_TEST

START_TEST(bebasik__292) {
char boba292_s21[10000];
char boba292[10000];
ck_assert_int_eq(s21_sprintf(boba292_s21, "%-8fe", 5796.561736103445),
sprintf(boba292, "%-8fe", 5796.561736103445));
ck_assert_str_eq(boba292_s21, boba292);
}
END_TEST

START_TEST(bebasik__293) {
char boba293_s21[10000];
char boba293[10000];
ck_assert_int_eq(s21_sprintf(boba293_s21, "%+6i9.%+2.9hiy%-2iux[% f%+i@%+hi%+3.7f5%+f=%-cm&%-ie%-.8d% hi%+1.5f`#%-.6hu*#r%-d%+.6i%+7f#% 5.7hi%-cm%+2.2hd%-.2d%-3hi", -77674, 14907, -794106, 100.50159532771256, 742987, -25196, 444.6113094658054, -2651.3288923078117, '&', -213793, -412168, 11617, 24956.332334395807, 16098, 293801, 888635, 1201.7966063469912, 29015, 'o', 18986, -947218, 8858),
sprintf(boba293, "%+6i9.%+2.9hiy%-2iux[% f%+i@%+hi%+3.7f5%+f=%-cm&%-ie%-.8d% hi%+1.5f`#%-.6hu*#r%-d%+.6i%+7f#% 5.7hi%-cm%+2.2hd%-.2d%-3hi", -77674, 14907, -794106, 100.50159532771256, 742987, -25196, 444.6113094658054, -2651.3288923078117, '&', -213793, -412168, 11617, 24956.332334395807, 16098, 293801, 888635, 1201.7966063469912, 29015, 'o', 18986, -947218, 8858));
ck_assert_str_eq(boba293_s21, boba293);
}
END_TEST

START_TEST(bebasik__294) {
char boba294_s21[10000];
char boba294[10000];
ck_assert_int_eq(s21_sprintf(boba294_s21, "% 10f%+9.4f% 10.1hi%+hi%-10.9s%-6.5i=c%-2s%-3.10s5i7j% 9.7f/vukf% hi%-8.2f%-5.10huxw(%+1hd%+4hi!% dj", -21126.793577602282, 8545.862123878067, 25128, -5245, "2g*ah)h6[4b4s1zv", -803332, "i8..5g1r&e0&2-ms.iy&hu", "kbzyatr=!tin..dy-74rd7", 24114.823306200426, 30936, 7605.071415704124, -8459, 6154, 3502, 606233),
sprintf(boba294, "% 10f%+9.4f% 10.1hi%+hi%-10.9s%-6.5i=c%-2s%-3.10s5i7j% 9.7f/vukf% hi%-8.2f%-5.10huxw(%+1hd%+4hi!% dj", -21126.793577602282, 8545.862123878067, 25128, -5245, "2g*ah)h6[4b4s1zv", -803332, "i8..5g1r&e0&2-ms.iy&hu", "kbzyatr=!tin..dy-74rd7", 24114.823306200426, 30936, 7605.071415704124, -8459, 6154, 3502, 606233));
ck_assert_str_eq(boba294_s21, boba294);
}
END_TEST

START_TEST(bebasik__295) {
char boba295_s21[10000];
char boba295[10000];
ck_assert_int_eq(s21_sprintf(boba295_s21, "%-.0fh%+d%+1.2d%+6.9d%+.4i&%+d% 9.9hd7%+.6d$c(", -2173.0943917276554, 931486, -752587, -492150, -731653, 620164, 26049, -422847),
sprintf(boba295, "%-.0fh%+d%+1.2d%+6.9d%+.4i&%+d% 9.9hd7%+.6d$c(", -2173.0943917276554, 931486, -752587, -492150, -731653, 620164, 26049, -422847));
ck_assert_str_eq(boba295_s21, boba295);
}
END_TEST

START_TEST(bebasik__296) {
char boba296_s21[10000];
char boba296[10000];
ck_assert_int_eq(s21_sprintf(boba296_s21, "%+8hdmb% 8i@% .0i%-5.10ur.%+5.6hd,o% .7d%+5.6hi%+8hd)%-4.2hu5.%+hd[%-hd,(u%+4hd%-5d.% hi% d%-hi%+.4dd,% 1hi% .8hizt%-9.6ixkufj% d", -20270, -496690, -55923, 190025, -3582, 648632, -12212, 30755, 16277, -17866, 21700, 7857, -343980, 17055, 345120, 26035, 775833, -19801, 18710, -911387, -847597),
sprintf(boba296, "%+8hdmb% 8i@% .0i%-5.10ur.%+5.6hd,o% .7d%+5.6hi%+8hd)%-4.2hu5.%+hd[%-hd,(u%+4hd%-5d.% hi% d%-hi%+.4dd,% 1hi% .8hizt%-9.6ixkufj% d", -20270, -496690, -55923, 190025, -3582, 648632, -12212, 30755, 16277, -17866, 21700, 7857, -343980, 17055, 345120, 26035, 775833, -19801, 18710, -911387, -847597));
ck_assert_str_eq(boba296_s21, boba296);
}
END_TEST

START_TEST(bebasik__297) {
char boba297_s21[10000];
char boba297[10000];
ck_assert_int_eq(s21_sprintf(boba297_s21, "% .10i$%-6.9s%+f=% 10f%-.8i% f70% 1.1hdv8%-4.9i%-hd% 5f*.%+5.3d%+7.1f%+.8dp% 8.2fz%-7.6hu6`#%-.9iq%-8c", -540742, ";4n*6#fis4`;p4;t*", -787.8207478468744, 6011.595301678287, 912159, 20155.406770596757, 31124, -570364, -26399, 6653.166508228398, -981235, 9108.126743673436, 557886, 649.7010459532355, 16330, 963684, '2'),
sprintf(boba297, "% .10i$%-6.9s%+f=% 10f%-.8i% f70% 1.1hdv8%-4.9i%-hd% 5f*.%+5.3d%+7.1f%+.8dp% 8.2fz%-7.6hu6`#%-.9iq%-8c", -540742, ";4n*6#fis4`;p4;t*", -787.8207478468744, 6011.595301678287, 912159, 20155.406770596757, 31124, -570364, -26399, 6653.166508228398, -981235, 9108.126743673436, 557886, 649.7010459532355, 16330, 963684, '2'));
ck_assert_str_eq(boba297_s21, boba297);
}
END_TEST

START_TEST(bebasik__298) {
char boba298_s21[10000];
char boba298[10000];
ck_assert_int_eq(s21_sprintf(boba298_s21, "%-2hicz%-4.2s%-3f8e.% 6.4f%+.8hd%+7hi9m% 6.5d;%+fbvu", -11099, "7@nozjs[npvi/5n.emym48(4", 4751.4014909558955, -1692.0666505191011, 15479, -4312, -208073, 19144.99406334489),
sprintf(boba298, "%-2hicz%-4.2s%-3f8e.% 6.4f%+.8hd%+7hi9m% 6.5d;%+fbvu", -11099, "7@nozjs[npvi/5n.emym48(4", 4751.4014909558955, -1692.0666505191011, 15479, -4312, -208073, 19144.99406334489));
ck_assert_str_eq(boba298_s21, boba298);
}
END_TEST

START_TEST(bebasik__299) {
char boba299_s21[10000];
char boba299[10000];
ck_assert_int_eq(s21_sprintf(boba299_s21, "%-u%-7hd% 1hd0vh%+i@,ltw^% 4.5hi% 9hi%-5.2s$% .6d% 1d% 7.10i/% .4hd6% .0f5h% 9.1d8[b%+5fzcv% 1.4hd%-.6hu%+d@%+6.0hikx%+i=%+hdy%-10.5hiv% .8hd", 298365, -11977, 11439, 721689, 3738, -10546, "yp28#=*c9!wplkax!&8[z3s", 739445, -862598, -280569, 16275, 7067.360136827913, 819026, -17169.220614754984, 27662, 17721, 321439, 30583, 617784, 13286, -29970, 8178),
sprintf(boba299, "%-u%-7hd% 1hd0vh%+i@,ltw^% 4.5hi% 9hi%-5.2s$% .6d% 1d% 7.10i/% .4hd6% .0f5h% 9.1d8[b%+5fzcv% 1.4hd%-.6hu%+d@%+6.0hikx%+i=%+hdy%-10.5hiv% .8hd", 298365, -11977, 11439, 721689, 3738, -10546, "yp28#=*c9!wplkax!&8[z3s", 739445, -862598, -280569, 16275, 7067.360136827913, 819026, -17169.220614754984, 27662, 17721, 321439, 30583, 617784, 13286, -29970, 8178));
ck_assert_str_eq(boba299_s21, boba299);
}
END_TEST

START_TEST(bebasik__300) {
char boba300_s21[10000];
char boba300[10000];
ck_assert_int_eq(s21_sprintf(boba300_s21, "%-3.7imgx`%-s%+9.6ff%-5s%-.5hu%+9f^%+2hd%+10.1hd7%+7hix%-.6hi%-4f%-c#b%+6.3d%-.1hi%-uf%+10i%-10hu5v%-c% .6hi%-4.0s%+1d% hd7vmx%-hd@%+.10hi", -463884, "pjj[q/&f&3", -7277.687011816047, "lo#", 10034, -290.93801871302054, -14525, 22172, -8716, 1472, 7739.310178590371, 'a', -324919, -3453, -825177, -168694, 19772, '0', 16736, "3wbs3.1kw20", 355131, 5131, 16360, -26575),
sprintf(boba300, "%-3.7imgx`%-s%+9.6ff%-5s%-.5hu%+9f^%+2hd%+10.1hd7%+7hix%-.6hi%-4f%-c#b%+6.3d%-.1hi%-uf%+10i%-10hu5v%-c% .6hi%-4.0s%+1d% hd7vmx%-hd@%+.10hi", -463884, "pjj[q/&f&3", -7277.687011816047, "lo#", 10034, -290.93801871302054, -14525, 22172, -8716, 1472, 7739.310178590371, 'a', -324919, -3453, -825177, -168694, 19772, '0', 16736, "3wbs3.1kw20", 355131, 5131, 16360, -26575));
ck_assert_str_eq(boba300_s21, boba300);
}
END_TEST

START_TEST(bebasik__301) {
char boba301_s21[10000];
char boba301[10000];
ck_assert_int_eq(s21_sprintf(boba301_s21, "% .10hd%-3.8d0% 4hd% i% 4i", 11435, 357433, -23095, -470549, 522911),
sprintf(boba301, "% .10hd%-3.8d0% 4hd% i% 4i", 11435, 357433, -23095, -470549, 522911));
ck_assert_str_eq(boba301_s21, boba301);
}
END_TEST

START_TEST(bebasik__302) {
char boba302_s21[10000];
char boba302[10000];
ck_assert_int_eq(s21_sprintf(boba302_s21, "%+d% 8.1hiy%+2ip)% 10dp=%+.2i%+3.0ft%+5f%-1hu&%-4.7huw%+3.4hi2%+9hi", -53963, -21515, -857986, 291300, -645015, 9789.38612598254, -602.3295298621445, 1249, -7782, -13669, -26150),
sprintf(boba302, "%+d% 8.1hiy%+2ip)% 10dp=%+.2i%+3.0ft%+5f%-1hu&%-4.7huw%+3.4hi2%+9hi", -53963, -21515, -857986, 291300, -645015, 9789.38612598254, -602.3295298621445, 1249, -7782, -13669, -26150));
ck_assert_str_eq(boba302_s21, boba302);
}
END_TEST

START_TEST(bebasik__303) {
char boba303_s21[10000];
char boba303[10000];
ck_assert_int_eq(s21_sprintf(boba303_s21, "%+4.8hd7=%-9.1hdr0u%-2.5u%+.1hd%-9hu%-8.10dcaqv2%+hig%-ds-% 5hd`", 7111, -20306, -647581, 15997, -22393, 429906, 10754, -849493, 28388),
sprintf(boba303, "%+4.8hd7=%-9.1hdr0u%-2.5u%+.1hd%-9hu%-8.10dcaqv2%+hig%-ds-% 5hd`", 7111, -20306, -647581, 15997, -22393, 429906, 10754, -849493, 28388));
ck_assert_str_eq(boba303_s21, boba303);
}
END_TEST

START_TEST(bebasik__304) {
char boba304_s21[10000];
char boba304[10000];
ck_assert_int_eq(s21_sprintf(boba304_s21, "%-.7s7=.", "bn7mm*e"),
sprintf(boba304, "%-.7s7=.", "bn7mm*e"));
ck_assert_str_eq(boba304_s21, boba304);
}
END_TEST

START_TEST(bebasik__305) {
char boba305_s21[10000];
char boba305[10000];
ck_assert_int_eq(s21_sprintf(boba305_s21, "%+hd% 6.7d15%+.3d%-9.1ie)%+9hi%+.3hi79% i)", -3255, 960394, 610784, -542575, 27742, -29828, -201060),
sprintf(boba305, "%+hd% 6.7d15%+.3d%-9.1ie)%+9hi%+.3hi79% i)", -3255, 960394, 610784, -542575, 27742, -29828, -201060));
ck_assert_str_eq(boba305_s21, boba305);
}
END_TEST

START_TEST(bebasik__306) {
char boba306_s21[10000];
char boba306[10000];
ck_assert_int_eq(s21_sprintf(boba306_s21, "% hi,$%+hdhys8,%+i%-.7hu=%+4hd6%-.6hd%+hi%-2.6hi&% i% 3.3hdw%-4.7fvz%-hu%+1.2f2,% hd%+9hd% 4d", -20697, 10662, -443292, -14189, 5066, -5359, -20605, -21875, -160395, 20033, 29165.728037460944, 27009, -9035.07860099513, 30899, -26740, 595245),
sprintf(boba306, "% hi,$%+hdhys8,%+i%-.7hu=%+4hd6%-.6hd%+hi%-2.6hi&% i% 3.3hdw%-4.7fvz%-hu%+1.2f2,% hd%+9hd% 4d", -20697, 10662, -443292, -14189, 5066, -5359, -20605, -21875, -160395, 20033, 29165.728037460944, 27009, -9035.07860099513, 30899, -26740, 595245));
ck_assert_str_eq(boba306_s21, boba306);
}
END_TEST

START_TEST(bebasik__307) {
char boba307_s21[10000];
char boba307[10000];
ck_assert_int_eq(s21_sprintf(boba307_s21, "%+5i%+8.0i%-2hik1c% .8dxa% 7.0hi%-1.10hu%-6d%+2.7hi;@2%-.3hi`m6%-dt%-hi% 7hi%+.4hd%+f% 10im;%+f%+.1i#$@9%-6.5u", 600529, 77337, -22634, -229545, 23206, 6092, 623426, 24835, -26035, -528524, -25814, 10201, -19880, 8831.029336706311, -547713, 7227.400287210842, -191719, 87576),
sprintf(boba307, "%+5i%+8.0i%-2hik1c% .8dxa% 7.0hi%-1.10hu%-6d%+2.7hi;@2%-.3hi`m6%-dt%-hi% 7hi%+.4hd%+f% 10im;%+f%+.1i#$@9%-6.5u", 600529, 77337, -22634, -229545, 23206, 6092, 623426, 24835, -26035, -528524, -25814, 10201, -19880, 8831.029336706311, -547713, 7227.400287210842, -191719, 87576));
ck_assert_str_eq(boba307_s21, boba307);
}
END_TEST

START_TEST(bebasik__308) {
char boba308_s21[10000];
char boba308[10000];
ck_assert_int_eq(s21_sprintf(boba308_s21, "%+.0hi%-f% 7i4y%+3ic%+1i%+10.4d2g`@a% 10hd% 10.8hi[%-.3hu% hdh%-6c%+hi", 5406, 5525.431329823143, 249333, -195359, 357064, 230277, -26452, -17337, -5032, -1184, '&', -26072),
sprintf(boba308, "%+.0hi%-f% 7i4y%+3ic%+1i%+10.4d2g`@a% 10hd% 10.8hi[%-.3hu% hdh%-6c%+hi", 5406, 5525.431329823143, 249333, -195359, 357064, 230277, -26452, -17337, -5032, -1184, '&', -26072));
ck_assert_str_eq(boba308_s21, boba308);
}
END_TEST

START_TEST(bebasik__309) {
char boba309_s21[10000];
char boba309[10000];
ck_assert_int_eq(s21_sprintf(boba309_s21, "% 3.0f%-.1s%+8.2hio% .1hd% 8.3i#9%+3hi`8p%-10u% .10hi1a4% hd% i3%-s%-2hi%-1.0f% 6.9f% hii/y%-.1ft!%+hi%-5s% .4hd%+hi%+d", -2550.451737253523, "ti^&*=kk3h1g!01)k6", -20120, 18103, 134393, -16990, -981683, -1036, 22620, -174296, "s;,)2&#*bhkt@ua@;7", -7826, -5228.934708188199, -799.1937949383176, 20837, -19084.077862637307, 18148, "8h9$hl=keu23h268rr", 20131, -6140, -756998),
sprintf(boba309, "% 3.0f%-.1s%+8.2hio% .1hd% 8.3i#9%+3hi`8p%-10u% .10hi1a4% hd% i3%-s%-2hi%-1.0f% 6.9f% hii/y%-.1ft!%+hi%-5s% .4hd%+hi%+d", -2550.451737253523, "ti^&*=kk3h1g!01)k6", -20120, 18103, 134393, -16990, -981683, -1036, 22620, -174296, "s;,)2&#*bhkt@ua@;7", -7826, -5228.934708188199, -799.1937949383176, 20837, -19084.077862637307, 18148, "8h9$hl=keu23h268rr", 20131, -6140, -756998));
ck_assert_str_eq(boba309_s21, boba309);
}
END_TEST

START_TEST(bebasik__310) {
char boba310_s21[10000];
char boba310[10000];
ck_assert_int_eq(s21_sprintf(boba310_s21, "%+2.5hd%+.5hdi% .0dn/.ne% .6i% 9i%-9c", -9460, 24854, 484687, -330638, -579577, 'h'),
sprintf(boba310, "%+2.5hd%+.5hdi% .0dn/.ne% .6i% 9i%-9c", -9460, 24854, 484687, -330638, -579577, 'h'));
ck_assert_str_eq(boba310_s21, boba310);
}
END_TEST

START_TEST(bebasik__311) {
char boba311_s21[10000];
char boba311[10000];
ck_assert_int_eq(s21_sprintf(boba311_s21, "% 10hi%-5c%-4u%+2hdq&%-9i^h% .3hdn%-.4hi%+9.3i% .1hile%+10hip% f%-8.6f0!%-.9hu%+8.1d9%+3d6%+i3% .8hie=*%-.7hi% 3.9hi%-.7s%-.1hd-% .1hdl%+hi%-.1hi", 6057, 'h', 591060, -20545, -708236, 22160, -19223, 238275, -10107, -14454, -2992.8953117169, 10810.762094554646, 17884, -858317, 44214, 848312, 10848, -6966, 1261, "09yfow)ot8d", -16608, -10262, -20210, 31035),
sprintf(boba311, "% 10hi%-5c%-4u%+2hdq&%-9i^h% .3hdn%-.4hi%+9.3i% .1hile%+10hip% f%-8.6f0!%-.9hu%+8.1d9%+3d6%+i3% .8hie=*%-.7hi% 3.9hi%-.7s%-.1hd-% .1hdl%+hi%-.1hi", 6057, 'h', 591060, -20545, -708236, 22160, -19223, 238275, -10107, -14454, -2992.8953117169, 10810.762094554646, 17884, -858317, 44214, 848312, 10848, -6966, 1261, "09yfow)ot8d", -16608, -10262, -20210, 31035));
ck_assert_str_eq(boba311_s21, boba311);
}
END_TEST

START_TEST(bebasik__312) {
char boba312_s21[10000];
char boba312[10000];
ck_assert_int_eq(s21_sprintf(boba312_s21, "% d-`j% 3hi/%-u%-c%-u!,t%-8.4d%+2d6q% .2hdu7;%+.10d% hd03%-3.1d%+6iq% 5hi%+.10hdn% f% hdw", 107947, 551, -732471, 'o', -444532, 618533, -925566, 20353, -143745, 19189, 927146, -367064, 16482, 23990, -13451.854808745164, 23443),
sprintf(boba312, "% d-`j% 3hi/%-u%-c%-u!,t%-8.4d%+2d6q% .2hdu7;%+.10d% hd03%-3.1d%+6iq% 5hi%+.10hdn% f% hdw", 107947, 551, -732471, 'o', -444532, 618533, -925566, 20353, -143745, 19189, 927146, -367064, 16482, 23990, -13451.854808745164, 23443));
ck_assert_str_eq(boba312_s21, boba312);
}
END_TEST

START_TEST(bebasik__313) {
char boba313_s21[10000];
char boba313[10000];
ck_assert_int_eq(s21_sprintf(boba313_s21, "%-5.5hd/", 24445),
sprintf(boba313, "%-5.5hd/", 24445));
ck_assert_str_eq(boba313_s21, boba313);
}
END_TEST

START_TEST(bebasik__314) {
char boba314_s21[10000];
char boba314[10000];
ck_assert_int_eq(s21_sprintf(boba314_s21, "%-.4hd5%-9hi%-5f%+.10hd% 8hdy% i% f% 5hi5", 16316, 19918, -8114.206002183837, -28422, -27346, 140371, -10768.372456059451, 13102),
sprintf(boba314, "%-.4hd5%-9hi%-5f%+.10hd% 8hdy% i% f% 5hi5", 16316, 19918, -8114.206002183837, -28422, -27346, 140371, -10768.372456059451, 13102));
ck_assert_str_eq(boba314_s21, boba314);
}
END_TEST

START_TEST(bebasik__315) {
char boba315_s21[10000];
char boba315[10000];
ck_assert_int_eq(s21_sprintf(boba315_s21, "%-.5hi%+7.0i!o%-9uz%+4d)w)f$(if%-9c6%+f%-iv4%-8.4hi%+.6d% f%+8d%-3.1hi%+10hd%+3hd@%+1.1hd%-7huuc*%+8.7hd% .4i%+10hd% 3.4hd", -30385, -71921, 678315, -100697, '8', -12138.76871860892, 749010, -15102, 889168, 29496.508153344195, 704877, 10577, 29723, 16328, -7154, -1241, 9803, 703215, -22944, 891),
sprintf(boba315, "%-.5hi%+7.0i!o%-9uz%+4d)w)f$(if%-9c6%+f%-iv4%-8.4hi%+.6d% f%+8d%-3.1hi%+10hd%+3hd@%+1.1hd%-7huuc*%+8.7hd% .4i%+10hd% 3.4hd", -30385, -71921, 678315, -100697, '8', -12138.76871860892, 749010, -15102, 889168, 29496.508153344195, 704877, 10577, 29723, 16328, -7154, -1241, 9803, 703215, -22944, 891));
ck_assert_str_eq(boba315_s21, boba315);
}
END_TEST

START_TEST(bebasik__316) {
char boba316_s21[10000];
char boba316[10000];
ck_assert_int_eq(s21_sprintf(boba316_s21, "%+hd% 4hi$%-hu%-.1f^%-10hd", -15833, 17482, -29765, -11365.045822248867, -5417),
sprintf(boba316, "%+hd% 4hi$%-hu%-.1f^%-10hd", -15833, 17482, -29765, -11365.045822248867, -5417));
ck_assert_str_eq(boba316_s21, boba316);
}
END_TEST

START_TEST(bebasik__317) {
char boba317_s21[10000];
char boba317[10000];
ck_assert_int_eq(s21_sprintf(boba317_s21, "%-.4f", 3349.441347934494),
sprintf(boba317, "%-.4f", 3349.441347934494));
ck_assert_str_eq(boba317_s21, boba317);
}
END_TEST

START_TEST(bebasik__318) {
char boba318_s21[10000];
char boba318[10000];
ck_assert_int_eq(s21_sprintf(boba318_s21, "%-f)x%+10.7dr", -204.34231205725007, -366119),
sprintf(boba318, "%-f)x%+10.7dr", -204.34231205725007, -366119));
ck_assert_str_eq(boba318_s21, boba318);
}
END_TEST

START_TEST(bebasik__319) {
char boba319_s21[10000];
char boba319[10000];
ck_assert_int_eq(s21_sprintf(boba319_s21, "%-.7u% 10d%+2.0hi%+4i()", -742111, -775293, -21259, -989124),
sprintf(boba319, "%-.7u% 10d%+2.0hi%+4i()", -742111, -775293, -21259, -989124));
ck_assert_str_eq(boba319_s21, boba319);
}
END_TEST

START_TEST(bebasik__320) {
char boba320_s21[10000];
char boba320[10000];
ck_assert_int_eq(s21_sprintf(boba320_s21, "%+.9d% 2.0d% .3f1m.mc%-hi%+.10d% iy-b&8su%-2d%+f^% 1.1hd%-.1hi%+.1d% 9.1i.%+3.1hdg%+.7hdya1%+.0d`j% hd@% 5d", 648071, 744942, -17092.668159746616, 20620, 536889, -525474, -32151, 148.26286723001635, -5652, 1922, -928405, 237328, 19973, 18939, 801487, -3761, -823527),
sprintf(boba320, "%+.9d% 2.0d% .3f1m.mc%-hi%+.10d% iy-b&8su%-2d%+f^% 1.1hd%-.1hi%+.1d% 9.1i.%+3.1hdg%+.7hdya1%+.0d`j% hd@% 5d", 648071, 744942, -17092.668159746616, 20620, 536889, -525474, -32151, 148.26286723001635, -5652, 1922, -928405, 237328, 19973, 18939, 801487, -3761, -823527));
ck_assert_str_eq(boba320_s21, boba320);
}
END_TEST

START_TEST(bebasik__321) {
char boba321_s21[10000];
char boba321[10000];
ck_assert_int_eq(s21_sprintf(boba321_s21, "%-8d0", 424946),
sprintf(boba321, "%-8d0", 424946));
ck_assert_str_eq(boba321_s21, boba321);
}
END_TEST

START_TEST(bebasik__322) {
char boba322_s21[10000];
char boba322[10000];
ck_assert_int_eq(s21_sprintf(boba322_s21, "%+3.0hi,%+hd,(&%-6.7f%+.5hdp%-8.3hi.9%-u% .0hi%-1.9hd", -24493, -14596, -3446.2557732903038, 12636, -14204, 168619, 26186, -21270),
sprintf(boba322, "%+3.0hi,%+hd,(&%-6.7f%+.5hdp%-8.3hi.9%-u% .0hi%-1.9hd", -24493, -14596, -3446.2557732903038, 12636, -14204, 168619, 26186, -21270));
ck_assert_str_eq(boba322_s21, boba322);
}
END_TEST

START_TEST(bebasik__323) {
char boba323_s21[10000];
char boba323[10000];
ck_assert_int_eq(s21_sprintf(boba323_s21, "%-5d%+4.9f/*l$f;d%+.5fai%-5s$@%-1.3s;", -857648, -11316.454790272945, 4471.029687029513, "f;=18/9/7jdhs[[.-2esuw;g", "w5*.3[c#"),
sprintf(boba323, "%-5d%+4.9f/*l$f;d%+.5fai%-5s$@%-1.3s;", -857648, -11316.454790272945, 4471.029687029513, "f;=18/9/7jdhs[[.-2esuw;g", "w5*.3[c#"));
ck_assert_str_eq(boba323_s21, boba323);
}
END_TEST

START_TEST(bebasik__324) {
char boba324_s21[10000];
char boba324[10000];
ck_assert_int_eq(s21_sprintf(boba324_s21, "% iz@tr-", -557932),
sprintf(boba324, "% iz@tr-", -557932));
ck_assert_str_eq(boba324_s21, boba324);
}
END_TEST

START_TEST(bebasik__325) {
char boba325_s21[10000];
char boba325[10000];
ck_assert_int_eq(s21_sprintf(boba325_s21, "%+.2fp%-d%-7.6hu=% 10d%+6.8hd%-10.6hd%-.0hd%+.9hi$/%+10d8i*% i4%+5.2hd% hd% dm#% 7hia% hi%+7i% 6hi% 6.4hi%-9hu%-5.8ur%-.1iw1%-9s53$%-5spe)*% hd", -18820.97136653547, 94367, 6199, -691191, 4794, 28641, 12554, -23751, -763440, -959144, 30784, 27332, -513155, -28528, 19046, -483697, -16699, -26332, 10148, -384132, 727924, "e.dbi@b;j,0sd", ";rknnz;sg$`/q4#`e!lvd(,[8)1", -22474),
sprintf(boba325, "%+.2fp%-d%-7.6hu=% 10d%+6.8hd%-10.6hd%-.0hd%+.9hi$/%+10d8i*% i4%+5.2hd% hd% dm#% 7hia% hi%+7i% 6hi% 6.4hi%-9hu%-5.8ur%-.1iw1%-9s53$%-5spe)*% hd", -18820.97136653547, 94367, 6199, -691191, 4794, 28641, 12554, -23751, -763440, -959144, 30784, 27332, -513155, -28528, 19046, -483697, -16699, -26332, 10148, -384132, 727924, "e.dbi@b;j,0sd", ";rknnz;sg$`/q4#`e!lvd(,[8)1", -22474));
ck_assert_str_eq(boba325_s21, boba325);
}
END_TEST

START_TEST(bebasik__326) {
char boba326_s21[10000];
char boba326[10000];
ck_assert_int_eq(s21_sprintf(boba326_s21, "%+.0hd6%-.2hd%-6.2hu[9%+9.3f% 3hd%-.5hilp6%+10hiw%+3hd6u% 7.3il%-7.10hu7% hi% .0hi%+6hi%+hde#%-6.9d%-9.2u8h7la% hd%+4hi;g%+4hd=%+6f% dh8% hdtb", -174, -25799, -10253, -270.8807292440474, 29409, 6084, 6518, -14894, -234873, -8504, 5744, 22371, -30208, -8806, -763482, 447886, 11539, 8036, -17976, 24824.369324487016, -368358, 24321),
sprintf(boba326, "%+.0hd6%-.2hd%-6.2hu[9%+9.3f% 3hd%-.5hilp6%+10hiw%+3hd6u% 7.3il%-7.10hu7% hi% .0hi%+6hi%+hde#%-6.9d%-9.2u8h7la% hd%+4hi;g%+4hd=%+6f% dh8% hdtb", -174, -25799, -10253, -270.8807292440474, 29409, 6084, 6518, -14894, -234873, -8504, 5744, 22371, -30208, -8806, -763482, 447886, 11539, 8036, -17976, 24824.369324487016, -368358, 24321));
ck_assert_str_eq(boba326_s21, boba326);
}
END_TEST

START_TEST(bebasik__327) {
char boba327_s21[10000];
char boba327[10000];
ck_assert_int_eq(s21_sprintf(boba327_s21, "% .10hi%+4f%+9d,% .2f=-", -14413, 9548.716904866365, 974319, -13768.827505997093),
sprintf(boba327, "% .10hi%+4f%+9d,% .2f=-", -14413, 9548.716904866365, 974319, -13768.827505997093));
ck_assert_str_eq(boba327_s21, boba327);
}
END_TEST

START_TEST(bebasik__328) {
char boba328_s21[10000];
char boba328[10000];
ck_assert_int_eq(s21_sprintf(boba328_s21, "% d08%+hia.% 3.0im2fk% .3ds%+.0hix%+7hd% 9i%+1hd%+i%-.3sc4% hd% d02%-8u% hd%+5.10hi%-hd", 778255, 5191, 549807, 198041, -10288, 14593, 157708, 18070, -556998, "u6,ui!ib", 8308, 17551, -391008, -3493, -3640, 14979),
sprintf(boba328, "% d08%+hia.% 3.0im2fk% .3ds%+.0hix%+7hd% 9i%+1hd%+i%-.3sc4% hd% d02%-8u% hd%+5.10hi%-hd", 778255, 5191, 549807, 198041, -10288, 14593, 157708, 18070, -556998, "u6,ui!ib", 8308, 17551, -391008, -3493, -3640, 14979));
ck_assert_str_eq(boba328_s21, boba328);
}
END_TEST

START_TEST(bebasik__329) {
char boba329_s21[10000];
char boba329[10000];
ck_assert_int_eq(s21_sprintf(boba329_s21, "%+d%-6hi%+hi%+iws% 9fs%+2.3d%+.0hi", -715059, -27723, -6361, 266935, -24183.51144482488, 105229, -25766),
sprintf(boba329, "%+d%-6hi%+hi%+iws% 9fs%+2.3d%+.0hi", -715059, -27723, -6361, 266935, -24183.51144482488, 105229, -25766));
ck_assert_str_eq(boba329_s21, boba329);
}
END_TEST

START_TEST(bebasik__330) {
char boba330_s21[10000];
char boba330[10000];
ck_assert_int_eq(s21_sprintf(boba330_s21, "%+5.0hd(% 9hd%+3hi%-7hu%+4.0f% hd% hi% hdr*%-hdws% 6hd%-2s%+6.8hi% 2.0hd2d%+9.4hi% .6hd", 11359, -23195, -21210, -20404, 6271.291375925545, -21968, 24322, -13871, 16063, 26658, "885;0.gp.^", 18372, 12586, 6557, -3014),
sprintf(boba330, "%+5.0hd(% 9hd%+3hi%-7hu%+4.0f% hd% hi% hdr*%-hdws% 6hd%-2s%+6.8hi% 2.0hd2d%+9.4hi% .6hd", 11359, -23195, -21210, -20404, 6271.291375925545, -21968, 24322, -13871, 16063, 26658, "885;0.gp.^", 18372, 12586, 6557, -3014));
ck_assert_str_eq(boba330_s21, boba330);
}
END_TEST

START_TEST(bebasik__331) {
char boba331_s21[10000];
char boba331[10000];
ck_assert_int_eq(s21_sprintf(boba331_s21, "%+.10f$%-7.4il%-hi-%-6co% 4hd//5% 8.7hi(h!%-.9hd)sz%+8d%-4f%-6.8hi%+9hdyqt% 9.1i*%+3d%+hi% hi% 7.7hi1%+6f6%+.8d% .4hdyi%+8.0hd% .7i%+1hiqk% 5i/-&*", 1366.5079592849102, -929778, 2853, '#', 16135, 7878, -1324, -306333, 18631.27258567306, 1013, -8179, 416012, -576222, -30037, -987, 22927, -127.6246268286797, 709589, -25125, -8710, -194545, -3992, 428867),
sprintf(boba331, "%+.10f$%-7.4il%-hi-%-6co% 4hd//5% 8.7hi(h!%-.9hd)sz%+8d%-4f%-6.8hi%+9hdyqt% 9.1i*%+3d%+hi% hi% 7.7hi1%+6f6%+.8d% .4hdyi%+8.0hd% .7i%+1hiqk% 5i/-&*", 1366.5079592849102, -929778, 2853, '#', 16135, 7878, -1324, -306333, 18631.27258567306, 1013, -8179, 416012, -576222, -30037, -987, 22927, -127.6246268286797, 709589, -25125, -8710, -194545, -3992, 428867));
ck_assert_str_eq(boba331_s21, boba331);
}
END_TEST

START_TEST(bebasik__332) {
char boba332_s21[10000];
char boba332[10000];
ck_assert_int_eq(s21_sprintf(boba332_s21, "%-.8i7jl2o%+i%-4.7u%-.6sz^c%+6.10fq% f59e%-c%-.8hd%-s%-3.0hd$% hd5%+hd%+hi5.%-hu%-hi/&%+.2hd% imvk", 705338, 873672, 90046, ")/9#5)b0&[-l54ighbxwd(&", 3409.913486017273, 1118.24519747694, '2', -27622, "r6tm(o(b*/c83baq,xr*e=9q7dhj(", 23344, -21320, -3925, -9466, -21572, -15213, 28002, -414024),
sprintf(boba332, "%-.8i7jl2o%+i%-4.7u%-.6sz^c%+6.10fq% f59e%-c%-.8hd%-s%-3.0hd$% hd5%+hd%+hi5.%-hu%-hi/&%+.2hd% imvk", 705338, 873672, 90046, ")/9#5)b0&[-l54ighbxwd(&", 3409.913486017273, 1118.24519747694, '2', -27622, "r6tm(o(b*/c83baq,xr*e=9q7dhj(", 23344, -21320, -3925, -9466, -21572, -15213, 28002, -414024));
ck_assert_str_eq(boba332_s21, boba332);
}
END_TEST

START_TEST(bebasik__333) {
char boba333_s21[10000];
char boba333[10000];
ck_assert_int_eq(s21_sprintf(boba333_s21, "%-10.4hu%-.10hi% 10d%-5c)w% .3dn(% .5hd%-.0hi%-dd% .3f[%+f%+hd3% .7ilmbq1z%-.10u%-.10s[)% 3fb%-f%+i5n%+.7ia% hd)m% 7.1d%+9.8i%-.2s.0%-s%+.8d", -17596, -29957, -877351, ';', 580558, 11132, -6317, 517692, -9421.864351092569, -1361.863570303999, 26269, -387389, 497871, "&zvb,w;$7fd99d$60$wl^mvw4`y[=", 30179.910023261702, -17210.838323223354, -958064, 858213, -13100, -202560, 183420, "p^.bj(*zggg2m^z4s^16&w-v/.", "sa39l0ty$2e2*9984", -88142),
sprintf(boba333, "%-10.4hu%-.10hi% 10d%-5c)w% .3dn(% .5hd%-.0hi%-dd% .3f[%+f%+hd3% .7ilmbq1z%-.10u%-.10s[)% 3fb%-f%+i5n%+.7ia% hd)m% 7.1d%+9.8i%-.2s.0%-s%+.8d", -17596, -29957, -877351, ';', 580558, 11132, -6317, 517692, -9421.864351092569, -1361.863570303999, 26269, -387389, 497871, "&zvb,w;$7fd99d$60$wl^mvw4`y[=", 30179.910023261702, -17210.838323223354, -958064, 858213, -13100, -202560, 183420, "p^.bj(*zggg2m^z4s^16&w-v/.", "sa39l0ty$2e2*9984", -88142));
ck_assert_str_eq(boba333_s21, boba333);
}
END_TEST

START_TEST(bebasik__334) {
char boba334_s21[10000];
char boba334[10000];
ck_assert_int_eq(s21_sprintf(boba334_s21, "%-.1ff% hi,4`%-9st%+hday9%-hiws@", 13412.063929549016, -26843, "hay(80^ce04rm", 31582, 27577),
sprintf(boba334, "%-.1ff% hi,4`%-9st%+hday9%-hiws@", 13412.063929549016, -26843, "hay(80^ce04rm", 31582, 27577));
ck_assert_str_eq(boba334_s21, boba334);
}
END_TEST

START_TEST(bebasik__335) {
char boba335_s21[10000];
char boba335[10000];
ck_assert_int_eq(s21_sprintf(boba335_s21, "% hdz%-hd% .10fnx%+hir%+5.2hi6% 3.9d^7h)e;&tr18h%-6uiw%+.4hivta% 8hd%+2hd% .6hi% 6ir%-.8hi%-6hd-p=eecbj", 19478, -4469, 3540.788690933885, 7661, 18062, -49134, -500771, 27806, -3049, -22741, 8811, -86625, -9127, 17452),
sprintf(boba335, "% hdz%-hd% .10fnx%+hir%+5.2hi6% 3.9d^7h)e;&tr18h%-6uiw%+.4hivta% 8hd%+2hd% .6hi% 6ir%-.8hi%-6hd-p=eecbj", 19478, -4469, 3540.788690933885, 7661, 18062, -49134, -500771, 27806, -3049, -22741, 8811, -86625, -9127, 17452));
ck_assert_str_eq(boba335_s21, boba335);
}
END_TEST

START_TEST(bebasik__336) {
char boba336_s21[10000];
char boba336[10000];
ck_assert_int_eq(s21_sprintf(boba336_s21, "%-2hd%-8.9sc4%+3hi% hd%+.8f*% .1dq%+hdxbi%-hd% hi%-hu% .0hi%+.9hix% .6f[%-10hu,*% 8hd0pj% .3imu% i.[h%+1hd(%+dy% 5d", 12883, "jl6c[,f28#a0r0", -28111, -17310, -4061.5235085235986, -655215, 26534, -11190, -30346, 23757, -21176, 4609, 807.3285078734039, -30535, -20523, -216238, 581119, 12038, 388580, -669469),
sprintf(boba336, "%-2hd%-8.9sc4%+3hi% hd%+.8f*% .1dq%+hdxbi%-hd% hi%-hu% .0hi%+.9hix% .6f[%-10hu,*% 8hd0pj% .3imu% i.[h%+1hd(%+dy% 5d", 12883, "jl6c[,f28#a0r0", -28111, -17310, -4061.5235085235986, -655215, 26534, -11190, -30346, 23757, -21176, 4609, 807.3285078734039, -30535, -20523, -216238, 581119, 12038, 388580, -669469));
ck_assert_str_eq(boba336_s21, boba336);
}
END_TEST

START_TEST(bebasik__337) {
char boba337_s21[10000];
char boba337[10000];
ck_assert_int_eq(s21_sprintf(boba337_s21, "% 1.7hir1x%+.1f2m%-.3u%-.9i%-8.3f%-d%+1hi%-6f%-3.7d% hd%-4hd*%+9fc%+4hd%+i%+5.7hdm/% .2hix% f%-4.4hu%+4.5i0", 10664, 8564.357301699283, -846072, 993198, 5758.779430482733, 837459, -24385, -16259.786336565254, 903668, -9870, 10151, -21194.20104849749, 24990, -466790, 22522, -16873, -899.5608447939933, -10715, 817055),
sprintf(boba337, "% 1.7hir1x%+.1f2m%-.3u%-.9i%-8.3f%-d%+1hi%-6f%-3.7d% hd%-4hd*%+9fc%+4hd%+i%+5.7hdm/% .2hix% f%-4.4hu%+4.5i0", 10664, 8564.357301699283, -846072, 993198, 5758.779430482733, 837459, -24385, -16259.786336565254, 903668, -9870, 10151, -21194.20104849749, 24990, -466790, 22522, -16873, -899.5608447939933, -10715, 817055));
ck_assert_str_eq(boba337_s21, boba337);
}
END_TEST

START_TEST(bebasik__338) {
char boba338_s21[10000];
char boba338[10000];
ck_assert_int_eq(s21_sprintf(boba338_s21, "% 7.2hi^^%+.1hi% 2.10i%+9hi% 8.8hd3% .8d%+f%-hu%-9dhv%+6.5fy% .0hdc% .8hd%+2hd%-hu)yj% fhte&%+d/)8x&^($% .8hde% i%+8.1d3%+5.7hd%-6c", 18548, -20858, -395020, 29734, -915, 275406, -21487.524583114307, 9956, -919535, 10395.699279699329, 28769, 13185, 27424, 19877, -630.058857837683, 9851, 1438, -570855, -452037, -13616, 'o'),
sprintf(boba338, "% 7.2hi^^%+.1hi% 2.10i%+9hi% 8.8hd3% .8d%+f%-hu%-9dhv%+6.5fy% .0hdc% .8hd%+2hd%-hu)yj% fhte&%+d/)8x&^($% .8hde% i%+8.1d3%+5.7hd%-6c", 18548, -20858, -395020, 29734, -915, 275406, -21487.524583114307, 9956, -919535, 10395.699279699329, 28769, 13185, 27424, 19877, -630.058857837683, 9851, 1438, -570855, -452037, -13616, 'o'));
ck_assert_str_eq(boba338_s21, boba338);
}
END_TEST

START_TEST(bebasik__339) {
char boba339_s21[10000];
char boba339[10000];
ck_assert_int_eq(s21_sprintf(boba339_s21, "% 3hi%-.5hiqw", 4690, 11946),
sprintf(boba339, "% 3hi%-.5hiqw", 4690, 11946));
ck_assert_str_eq(boba339_s21, boba339);
}
END_TEST

START_TEST(bebasik__340) {
char boba340_s21[10000];
char boba340[10000];
ck_assert_int_eq(s21_sprintf(boba340_s21, "%+8i%-5.10s%-6i%+8.3hd% 6hd^%+3f%-6hu%-.3f6% 4.6f% f%-.6hd&% f%-.2hdm% hi%-uj% hibmc2w%-7hu% 4d[%-5szu%+3hi% .6hi%-.0fjcq5br", 334031, "9`absnlx/fmzk^m.rn=m", -270873, 13140, -1883, 16817.55800893424, 29077, -5085.601519140712, 6810.627664408335, 30063.66706298769, 28926, -169.68003500727204, -21992, 28547, 346601, 14972, -16237, -812719, "vf^k0k8gk!-z", -6536, -15472, 5092.327661001407),
sprintf(boba340, "%+8i%-5.10s%-6i%+8.3hd% 6hd^%+3f%-6hu%-.3f6% 4.6f% f%-.6hd&% f%-.2hdm% hi%-uj% hibmc2w%-7hu% 4d[%-5szu%+3hi% .6hi%-.0fjcq5br", 334031, "9`absnlx/fmzk^m.rn=m", -270873, 13140, -1883, 16817.55800893424, 29077, -5085.601519140712, 6810.627664408335, 30063.66706298769, 28926, -169.68003500727204, -21992, 28547, 346601, 14972, -16237, -812719, "vf^k0k8gk!-z", -6536, -15472, 5092.327661001407));
ck_assert_str_eq(boba340_s21, boba340);
}
END_TEST

START_TEST(bebasik__341) {
char boba341_s21[10000];
char boba341[10000];
ck_assert_int_eq(s21_sprintf(boba341_s21, "% 2hd%+5d%+8hi% hd%+.5hd`^s%+deg#l% 3i%-c% 7.0hi", 14794, 911587, -14113, -16421, -13951, -335888, -51020, '/', 20995),
sprintf(boba341, "% 2hd%+5d%+8hi% hd%+.5hd`^s%+deg#l% 3i%-c% 7.0hi", 14794, 911587, -14113, -16421, -13951, -335888, -51020, '/', 20995));
ck_assert_str_eq(boba341_s21, boba341);
}
END_TEST

START_TEST(bebasik__342) {
char boba342_s21[10000];
char boba342[10000];
ck_assert_int_eq(s21_sprintf(boba342_s21, "%+.0hdn% hi$,tj4%+hi", 31006, -8991, -5686),
sprintf(boba342, "%+.0hdn% hi$,tj4%+hi", 31006, -8991, -5686));
ck_assert_str_eq(boba342_s21, boba342);
}
END_TEST

START_TEST(bebasik__343) {
char boba343_s21[10000];
char boba343[10000];
ck_assert_int_eq(s21_sprintf(boba343_s21, "% 2.0f% .9ixz0% .8hdaz%-6.2hu%-.3hd9v(m%+1.3i%+.5hi%-1.2f%+.4hi!q%-9.4io%+4hdt% 3f=%+4.3f% 5.5hi1% 6hd[*5-^yxw%-7.2hi-%+hdd;%-.8d% 9hi%-hd% hi4% 7.2hi2% 2hd", 5253.409595418272, -702744, 30435, -22845, 19693, 253814, 17035, 9889.755379550621, -18098, 390668, -7057, -135.22337448228546, 7580.612030898823, 14892, 18320, 12424, -3000, -321024, 29573, -10373, -10481, 20996, 14739),
sprintf(boba343, "% 2.0f% .9ixz0% .8hdaz%-6.2hu%-.3hd9v(m%+1.3i%+.5hi%-1.2f%+.4hi!q%-9.4io%+4hdt% 3f=%+4.3f% 5.5hi1% 6hd[*5-^yxw%-7.2hi-%+hdd;%-.8d% 9hi%-hd% hi4% 7.2hi2% 2hd", 5253.409595418272, -702744, 30435, -22845, 19693, 253814, 17035, 9889.755379550621, -18098, 390668, -7057, -135.22337448228546, 7580.612030898823, 14892, 18320, 12424, -3000, -321024, 29573, -10373, -10481, 20996, 14739));
ck_assert_str_eq(boba343_s21, boba343);
}
END_TEST

START_TEST(bebasik__344) {
char boba344_s21[10000];
char boba344[10000];
ck_assert_int_eq(s21_sprintf(boba344_s21, "%-10hd%-5.7hi%-.1d% .1fvk8%+9.1hi%-hu&0f%-8.7s% d88%+d%-c=)w=[%+hd@58%+i1[%+3.6hd%+6.1hi%-c", -4161, 10710, -911579, -14301.682307835925, -18563, -6068, ",*2$@k.acemk(w4$$g0iu,u8", 732742, 607407, 'i', 13916, 214632, -12629, -29538, 'b'),
sprintf(boba344, "%-10hd%-5.7hi%-.1d% .1fvk8%+9.1hi%-hu&0f%-8.7s% d88%+d%-c=)w=[%+hd@58%+i1[%+3.6hd%+6.1hi%-c", -4161, 10710, -911579, -14301.682307835925, -18563, -6068, ",*2$@k.acemk(w4$$g0iu,u8", 732742, 607407, 'i', 13916, 214632, -12629, -29538, 'b'));
ck_assert_str_eq(boba344_s21, boba344);
}
END_TEST

START_TEST(bebasik__345) {
char boba345_s21[10000];
char boba345[10000];
ck_assert_int_eq(s21_sprintf(boba345_s21, "%-2u%-10.10d6%+hd%-.1d%-6.6hd% 4.1hii!%+.6f%-hi%-.4f%-5fd%+6.1f.x%+10hi%-7d6zy% d2r% .6f", -437065, -18522, 5279, 434048, 31961, -1185, 2337.239209770307, -4309, 1805.8258003418475, 157.96558905641047, 5264.393694678208, 8942, -680876, -688886, -126.52393770308448),
sprintf(boba345, "%-2u%-10.10d6%+hd%-.1d%-6.6hd% 4.1hii!%+.6f%-hi%-.4f%-5fd%+6.1f.x%+10hi%-7d6zy% d2r% .6f", -437065, -18522, 5279, 434048, 31961, -1185, 2337.239209770307, -4309, 1805.8258003418475, 157.96558905641047, 5264.393694678208, 8942, -680876, -688886, -126.52393770308448));
ck_assert_str_eq(boba345_s21, boba345);
}
END_TEST

START_TEST(bebasik__346) {
char boba346_s21[10000];
char boba346[10000];
ck_assert_int_eq(s21_sprintf(boba346_s21, "% 9.9f%-2ff.$%+10.1db(%-9.5hd%-5f-% hi% 5f%+ft!%-7hdd7z/p%+hd5% 9d", 344.05560806325616, 8686.519805323906, -901539, -28564, 7636.439807746282, -26326, 932.1981186798711, -8278.465604977388, -2344, 3100, -700130),
sprintf(boba346, "% 9.9f%-2ff.$%+10.1db(%-9.5hd%-5f-% hi% 5f%+ft!%-7hdd7z/p%+hd5% 9d", 344.05560806325616, 8686.519805323906, -901539, -28564, 7636.439807746282, -26326, 932.1981186798711, -8278.465604977388, -2344, 3100, -700130));
ck_assert_str_eq(boba346_s21, boba346);
}
END_TEST

START_TEST(bebasik__347) {
char boba347_s21[10000];
char boba347[10000];
ck_assert_int_eq(s21_sprintf(boba347_s21, "% .8ibl;@%+6.6hd% ft% fc%+d#% 6hd%-.3f%-8i", 763642, -16121, 16246.568246097573, 854.9158508283298, 426511, -14047, -17511.80105448907, 533364),
sprintf(boba347, "% .8ibl;@%+6.6hd% ft% fc%+d#% 6hd%-.3f%-8i", 763642, -16121, 16246.568246097573, 854.9158508283298, 426511, -14047, -17511.80105448907, 533364));
ck_assert_str_eq(boba347_s21, boba347);
}
END_TEST

START_TEST(bebasik__348) {
char boba348_s21[10000];
char boba348[10000];
ck_assert_int_eq(s21_sprintf(boba348_s21, "%-.1hivq%-u% 2.2hdy1%-hu%+10hd% hd%-6.10hd% 2f%+hi% .6i(y7%+8.10fsn%-.0hi87%-8c% 2.4f% hdw6ir%+4f%-6.9hi% 8.9f% 3f% hi", -20726, -26817, -31961, 17472, 30319, -14786, -5830, -18300.932232338077, 25858, -8428, 652.5235641816975, 6400, 'z', 535.0748978189356, -19499, -3071.9922228241676, -1005, 14643.685736682795, 1056.259265556521, -12284),
sprintf(boba348, "%-.1hivq%-u% 2.2hdy1%-hu%+10hd% hd%-6.10hd% 2f%+hi% .6i(y7%+8.10fsn%-.0hi87%-8c% 2.4f% hdw6ir%+4f%-6.9hi% 8.9f% 3f% hi", -20726, -26817, -31961, 17472, 30319, -14786, -5830, -18300.932232338077, 25858, -8428, 652.5235641816975, 6400, 'z', 535.0748978189356, -19499, -3071.9922228241676, -1005, 14643.685736682795, 1056.259265556521, -12284));
ck_assert_str_eq(boba348_s21, boba348);
}
END_TEST

START_TEST(bebasik__349) {
char boba349_s21[10000];
char boba349[10000];
ck_assert_int_eq(s21_sprintf(boba349_s21, "% 4hi%+7hi%+3hi% 6.2d#% hi%-9.4f% .2f%+.6d=%-5.1hiw2", 27300, 27720, 477, -511270, -11396, -15245.496291889145, -392.72001739881256, -691353, 6747),
sprintf(boba349, "% 4hi%+7hi%+3hi% 6.2d#% hi%-9.4f% .2f%+.6d=%-5.1hiw2", 27300, 27720, 477, -511270, -11396, -15245.496291889145, -392.72001739881256, -691353, 6747));
ck_assert_str_eq(boba349_s21, boba349);
}
END_TEST

START_TEST(bebasik__350) {
char boba350_s21[10000];
char boba350[10000];
ck_assert_int_eq(s21_sprintf(boba350_s21, "% 3hi%+ic", -11199, -774315),
sprintf(boba350, "% 3hi%+ic", -11199, -774315));
ck_assert_str_eq(boba350_s21, boba350);
}
END_TEST

START_TEST(bebasik__351) {
char boba351_s21[10000];
char boba351[10000];
ck_assert_int_eq(s21_sprintf(boba351_s21, "%-hu5%+i% 9hd% 6dc%-4f", 4296, -447536, 5256, -626407, 6695.87311224295),
sprintf(boba351, "%-hu5%+i% 9hd% 6dc%-4f", 4296, -447536, 5256, -626407, 6695.87311224295));
ck_assert_str_eq(boba351_s21, boba351);
}
END_TEST

START_TEST(bebasik__352) {
char boba352_s21[10000];
char boba352[10000];
ck_assert_int_eq(s21_sprintf(boba352_s21, "% 9hi3h%-4.4dp%-f8%-hu%-10d%-1.6fy9% 10hi%-5f%-10hdz", -23378, 312965, 3671.299181421074, 23065, 437021, 13305.731830340892, -25761, 17037.181751785625, 25269),
sprintf(boba352, "% 9hi3h%-4.4dp%-f8%-hu%-10d%-1.6fy9% 10hi%-5f%-10hdz", -23378, 312965, 3671.299181421074, 23065, 437021, 13305.731830340892, -25761, 17037.181751785625, 25269));
ck_assert_str_eq(boba352_s21, boba352);
}
END_TEST

START_TEST(bebasik__353) {
char boba353_s21[10000];
char boba353[10000];
ck_assert_int_eq(s21_sprintf(boba353_s21, "% .9i%-.10f%-9.0d% 9hd`uf1% 8.10hiu%+3f4/% hd$%-5huisw% .2hd%+7hi%+1i2yt%+7d;4x%-1i%-4.0u3jvbfq#%-6.10d8xt% 2hi%-3hd% 9.10hd-%+1.2f%-10.9hi", -884953, 11373.967247386287, 337809, 22391, 8570, -29930.58444321322, -23482, 19038, -5561, -1181, -69738, -320542, 417908, 779461, 537543, -28615, 4129, 5150, -26884.627428145766, -1670),
sprintf(boba353, "% .9i%-.10f%-9.0d% 9hd`uf1% 8.10hiu%+3f4/% hd$%-5huisw% .2hd%+7hi%+1i2yt%+7d;4x%-1i%-4.0u3jvbfq#%-6.10d8xt% 2hi%-3hd% 9.10hd-%+1.2f%-10.9hi", -884953, 11373.967247386287, 337809, 22391, 8570, -29930.58444321322, -23482, 19038, -5561, -1181, -69738, -320542, 417908, 779461, 537543, -28615, 4129, 5150, -26884.627428145766, -1670));
ck_assert_str_eq(boba353_s21, boba353);
}
END_TEST

START_TEST(bebasik__354) {
char boba354_s21[10000];
char boba354[10000];
ck_assert_int_eq(s21_sprintf(boba354_s21, "%-f%-4d63p%+8i9!0%+1.1d=%-5hu%-1d4[3fc%-hit%+.5i.=% 3hi%+d-#%-.9s%+7hd*%-5.8hu%-.3s%+6hi%-.3hi%+.10hip3l%-9i%-2hi9%+.4iu8%-4.8hddamvk(", -5006.628506850445, -170391, 340975, -843457, 28068, 442762, -13488, 474465, -14565, -244619, "5kbcok*kh3l", 27365, -4761, "4b4", -14171, 4801, 29346, -606146, 11123, -615309, -7025),
sprintf(boba354, "%-f%-4d63p%+8i9!0%+1.1d=%-5hu%-1d4[3fc%-hit%+.5i.=% 3hi%+d-#%-.9s%+7hd*%-5.8hu%-.3s%+6hi%-.3hi%+.10hip3l%-9i%-2hi9%+.4iu8%-4.8hddamvk(", -5006.628506850445, -170391, 340975, -843457, 28068, 442762, -13488, 474465, -14565, -244619, "5kbcok*kh3l", 27365, -4761, "4b4", -14171, 4801, 29346, -606146, 11123, -615309, -7025));
ck_assert_str_eq(boba354_s21, boba354);
}
END_TEST

START_TEST(bebasik__355) {
char boba355_s21[10000];
char boba355[10000];
ck_assert_int_eq(s21_sprintf(boba355_s21, "%-7.1sjp", "f2orn11[/"),
sprintf(boba355, "%-7.1sjp", "f2orn11[/"));
ck_assert_str_eq(boba355_s21, boba355);
}
END_TEST

START_TEST(bebasik__356) {
char boba356_s21[10000];
char boba356[10000];
ck_assert_int_eq(s21_sprintf(boba356_s21, "% .6hd% 4.5hdo%-.8s2%+2iz% 1.0f%+1f(% dtpq1f0.%+f%-2huw% 4f%-1i%+.1hdi", 77, 30907, "t=7o.8o=", -584088, -287.8553523316332, -3125.256229510366, 358165, 4280.6054336617135, -25768, -1999.9453966316848, -41377, -23761),
sprintf(boba356, "% .6hd% 4.5hdo%-.8s2%+2iz% 1.0f%+1f(% dtpq1f0.%+f%-2huw% 4f%-1i%+.1hdi", 77, 30907, "t=7o.8o=", -584088, -287.8553523316332, -3125.256229510366, 358165, 4280.6054336617135, -25768, -1999.9453966316848, -41377, -23761));
ck_assert_str_eq(boba356_s21, boba356);
}
END_TEST

START_TEST(bebasik__357) {
char boba357_s21[10000];
char boba357[10000];
ck_assert_int_eq(s21_sprintf(boba357_s21, "%-3.7ds%-u%+5hd% .4hi(i% .0hd%-.10foep2!r%+5hi%+8hd%+3.8hdi#%-4f% .3i% 6.7d% 3hi", -844941, -559591, -2683, -17602, 7486, -8989.058836287113, -27319, -9666, -29393, 10398.392684854078, 973404, -209972, -8591),
sprintf(boba357, "%-3.7ds%-u%+5hd% .4hi(i% .0hd%-.10foep2!r%+5hi%+8hd%+3.8hdi#%-4f% .3i% 6.7d% 3hi", -844941, -559591, -2683, -17602, 7486, -8989.058836287113, -27319, -9666, -29393, 10398.392684854078, 973404, -209972, -8591));
ck_assert_str_eq(boba357_s21, boba357);
}
END_TEST

START_TEST(bebasik__358) {
char boba358_s21[10000];
char boba358[10000];
ck_assert_int_eq(s21_sprintf(boba358_s21, "% fb%+.8hi%+.4hd%+hi%-i%+dx%+.5hd/=%+.4hi% 3f*%-hu%-f", -263.06581679465694, -4906, 17867, -7286, -247495, 963472, -1596, 16190, 14531.503271374644, -23197, 31601.509034175768),
sprintf(boba358, "% fb%+.8hi%+.4hd%+hi%-i%+dx%+.5hd/=%+.4hi% 3f*%-hu%-f", -263.06581679465694, -4906, 17867, -7286, -247495, 963472, -1596, 16190, 14531.503271374644, -23197, 31601.509034175768));
ck_assert_str_eq(boba358_s21, boba358);
}
END_TEST

START_TEST(bebasik__359) {
char boba359_s21[10000];
char boba359[10000];
ck_assert_int_eq(s21_sprintf(boba359_s21, "%+3.2fb%+9d% 3hd)% 4dx%-5.1d0rc(%+1hi% 1hd%-6.2do%+2fxt%+inv%+6d%-u% 8.10hd% .10hi)% 8f", 9911.07889138352, 397657, 30636, 305452, -582770, -21308, 12132, -710447, -8586.212027599626, 583623, -396106, 298389, -30910, -15375, 15344.328928959867),
sprintf(boba359, "%+3.2fb%+9d% 3hd)% 4dx%-5.1d0rc(%+1hi% 1hd%-6.2do%+2fxt%+inv%+6d%-u% 8.10hd% .10hi)% 8f", 9911.07889138352, 397657, 30636, 305452, -582770, -21308, 12132, -710447, -8586.212027599626, 583623, -396106, 298389, -30910, -15375, 15344.328928959867));
ck_assert_str_eq(boba359_s21, boba359);
}
END_TEST

START_TEST(bebasik__360) {
char boba360_s21[10000];
char boba360[10000];
ck_assert_int_eq(s21_sprintf(boba360_s21, "%+.4d%+3hd%+hi%+.7i7j.6% .7d%+in*%+7.3hd;%-.8i%+3.1if%-s/f%+5.4f8u%+.0d=dma7v%-8fcrm% 10ixg% hi%+f% .2hi6w5% 8.2hi%+10.7i$% hi9%+.6dv% hij.cz%+.6i6m44%+3.5i", -282061, 2960, -29001, 825946, 779594, -70100, 31830, 825887, -592156, "m75[[t5uw/hn!#=04@,m", 2615.7794986744834, 613764, -15916.12022500026, 65454, 19356, 1439.624164241725, 5613, -23092, 962421, 30478, 858725, -26434, 337574, 767538),
sprintf(boba360, "%+.4d%+3hd%+hi%+.7i7j.6% .7d%+in*%+7.3hd;%-.8i%+3.1if%-s/f%+5.4f8u%+.0d=dma7v%-8fcrm% 10ixg% hi%+f% .2hi6w5% 8.2hi%+10.7i$% hi9%+.6dv% hij.cz%+.6i6m44%+3.5i", -282061, 2960, -29001, 825946, 779594, -70100, 31830, 825887, -592156, "m75[[t5uw/hn!#=04@,m", 2615.7794986744834, 613764, -15916.12022500026, 65454, 19356, 1439.624164241725, 5613, -23092, 962421, 30478, 858725, -26434, 337574, 767538));
ck_assert_str_eq(boba360_s21, boba360);
}
END_TEST

START_TEST(bebasik__361) {
char boba361_s21[10000];
char boba361[10000];
ck_assert_int_eq(s21_sprintf(boba361_s21, "%+8hd%-8hi% 7.2f%+8d&=#8.h%-iz%-.1i*% hd*8% .3hi%-.0hd% hi% .9d", 24921, -20930, 4293.944636416582, -642892, -719691, 23702, 7914, 31130, -14591, 7013, 846538),
sprintf(boba361, "%+8hd%-8hi% 7.2f%+8d&=#8.h%-iz%-.1i*% hd*8% .3hi%-.0hd% hi% .9d", 24921, -20930, 4293.944636416582, -642892, -719691, 23702, 7914, 31130, -14591, 7013, 846538));
ck_assert_str_eq(boba361_s21, boba361);
}
END_TEST

START_TEST(bebasik__362) {
char boba362_s21[10000];
char boba362[10000];
ck_assert_int_eq(s21_sprintf(boba362_s21, "%+10d%+hd%+4d[", -476559, -14380, -423541),
sprintf(boba362, "%+10d%+hd%+4d[", -476559, -14380, -423541));
ck_assert_str_eq(boba362_s21, boba362);
}
END_TEST

START_TEST(bebasik__363) {
char boba363_s21[10000];
char boba363[10000];
ck_assert_int_eq(s21_sprintf(boba363_s21, "% f)% d/8a%+9.1ir$r=%+f#(l6))2`;%+.0d9g=% fv% .2ik% 10hi% .2i% .4i%-4.10hu%-.3hu%+.5f%+7hi&% 10.9hi[%+.5hd%+hd(%+hi", 21878.792129426394, -228209, -60049, -21711.191734818596, 576507, 1741.2812498110338, 992394, -1872, -27820, -174637, 14241, -11819, -7932.230437677099, 6068, 13709, 18333, 13892, 15531),
sprintf(boba363, "% f)% d/8a%+9.1ir$r=%+f#(l6))2`;%+.0d9g=% fv% .2ik% 10hi% .2i% .4i%-4.10hu%-.3hu%+.5f%+7hi&% 10.9hi[%+.5hd%+hd(%+hi", 21878.792129426394, -228209, -60049, -21711.191734818596, 576507, 1741.2812498110338, 992394, -1872, -27820, -174637, 14241, -11819, -7932.230437677099, 6068, 13709, 18333, 13892, 15531));
ck_assert_str_eq(boba363_s21, boba363);
}
END_TEST

START_TEST(bebasik__364) {
char boba364_s21[10000];
char boba364[10000];
ck_assert_int_eq(s21_sprintf(boba364_s21, "%-9s$0", "v5txg[o4un/k-tk#(!a;u3vv!"),
sprintf(boba364, "%-9s$0", "v5txg[o4un/k-tk#(!a;u3vv!"));
ck_assert_str_eq(boba364_s21, boba364);
}
END_TEST

START_TEST(bebasik__365) {
char boba365_s21[10000];
char boba365[10000];
ck_assert_int_eq(s21_sprintf(boba365_s21, "%-fou%-hu-2p%+9i%+8ftdt%-huq%-3huo6q%-5.8du% .3de%-1c% hd%-cib% 10d%+2.9f%-c% 2f%+hi%+4.0hd#%+4hd$%+d", -1980.696957610598, 29038, 36429, 1641.554445662884, 2676, -23197, -655758, -850555, '*', -7033, '3', 10794, 12961.33499868298, 'b', 149.7726858555535, -25896, -13255, 3845, -931948),
sprintf(boba365, "%-fou%-hu-2p%+9i%+8ftdt%-huq%-3huo6q%-5.8du% .3de%-1c% hd%-cib% 10d%+2.9f%-c% 2f%+hi%+4.0hd#%+4hd$%+d", -1980.696957610598, 29038, 36429, 1641.554445662884, 2676, -23197, -655758, -850555, '*', -7033, '3', 10794, 12961.33499868298, 'b', 149.7726858555535, -25896, -13255, 3845, -931948));
ck_assert_str_eq(boba365_s21, boba365);
}
END_TEST

START_TEST(bebasik__366) {
char boba366_s21[10000];
char boba366[10000];
ck_assert_int_eq(s21_sprintf(boba366_s21, "% hi%+7.3d-p%+.3hd%+.5hi4is%+.4hi%-hi%-d7*uj% 4.8i%-f%+.8dx%-2hu% f", -31325, 112370, 28730, -12246, -5150, -6146, 908294, -475392, 4150.107737190843, -616335, -714, 7886.762752735267),
sprintf(boba366, "% hi%+7.3d-p%+.3hd%+.5hi4is%+.4hi%-hi%-d7*uj% 4.8i%-f%+.8dx%-2hu% f", -31325, 112370, 28730, -12246, -5150, -6146, 908294, -475392, 4150.107737190843, -616335, -714, 7886.762752735267));
ck_assert_str_eq(boba366_s21, boba366);
}
END_TEST

START_TEST(bebasik__367) {
char boba367_s21[10000];
char boba367[10000];
ck_assert_int_eq(s21_sprintf(boba367_s21, "%-7.4iert%+7.4f%+10hd%+hi!t%-.0ic#!%+9.6hd% 2d5brfe% hi@.(h%+.4hij% hd", -347495, -43.11169626966588, -10640, 27453, -180180, -27353, -730031, -4168, -13933, 29763),
sprintf(boba367, "%-7.4iert%+7.4f%+10hd%+hi!t%-.0ic#!%+9.6hd% 2d5brfe% hi@.(h%+.4hij% hd", -347495, -43.11169626966588, -10640, 27453, -180180, -27353, -730031, -4168, -13933, 29763));
ck_assert_str_eq(boba367_s21, boba367);
}
END_TEST

START_TEST(bebasik__368) {
char boba368_s21[10000];
char boba368[10000];
ck_assert_int_eq(s21_sprintf(boba368_s21, "%-1.3i5% .3d%-hi", -291921, -55527, 10386),
sprintf(boba368, "%-1.3i5% .3d%-hi", -291921, -55527, 10386));
ck_assert_str_eq(boba368_s21, boba368);
}
END_TEST

START_TEST(bebasik__369) {
char boba369_s21[10000];
char boba369[10000];
ck_assert_int_eq(s21_sprintf(boba369_s21, "%-2hi#%-10s%-.4s&3% d%-hi%+d)% 4hia%+.4hi%-hi&%+i%-1.6s%+2f3%+.10hi%-1.3hi%+.2hd%+9.5hil^$% hd%-1.0hd% 4fk%-hi%-3.9hu^)%+4.5hi%+hi", 18875, "&^xxptbyh9rzi$j2&sn98", "c@n", -762365, 21562, 321374, -2725, 30433, 12226, 851417, "cdnstm1mm8sxuq5(/fh!vvezp0am!", 1861.1582893062757, -28606, 9056, 4055, 29634, -15665, -21961, 11850.020713565986, 5136, 28485, 3598, -10469),
sprintf(boba369, "%-2hi#%-10s%-.4s&3% d%-hi%+d)% 4hia%+.4hi%-hi&%+i%-1.6s%+2f3%+.10hi%-1.3hi%+.2hd%+9.5hil^$% hd%-1.0hd% 4fk%-hi%-3.9hu^)%+4.5hi%+hi", 18875, "&^xxptbyh9rzi$j2&sn98", "c@n", -762365, 21562, 321374, -2725, 30433, 12226, 851417, "cdnstm1mm8sxuq5(/fh!vvezp0am!", 1861.1582893062757, -28606, 9056, 4055, 29634, -15665, -21961, 11850.020713565986, 5136, 28485, 3598, -10469));
ck_assert_str_eq(boba369_s21, boba369);
}
END_TEST

START_TEST(bebasik__370) {
char boba370_s21[10000];
char boba370[10000];
ck_assert_int_eq(s21_sprintf(boba370_s21, "%-.2hd%+.7i% 9iw)sr% i=)%+.6d% .2d&h0% .9hdzv% 4hdf*%-.2hd%+2hicu%+d% 5hd%-hus%-1.1hd% .2hikm!%-3.5huz% 4.4i%-f", -29545, 201119, -54504, 966729, -519958, -258104, -9162, 16633, -13554, 17391, 483764, -28067, 25121, -19286, -24076, 3088, -681851, -2472.0557283505877),
sprintf(boba370, "%-.2hd%+.7i% 9iw)sr% i=)%+.6d% .2d&h0% .9hdzv% 4hdf*%-.2hd%+2hicu%+d% 5hd%-hus%-1.1hd% .2hikm!%-3.5huz% 4.4i%-f", -29545, 201119, -54504, 966729, -519958, -258104, -9162, 16633, -13554, 17391, 483764, -28067, 25121, -19286, -24076, 3088, -681851, -2472.0557283505877));
ck_assert_str_eq(boba370_s21, boba370);
}
END_TEST

START_TEST(bebasik__371) {
char boba371_s21[10000];
char boba371[10000];
ck_assert_int_eq(s21_sprintf(boba371_s21, "%-hi%-10d%-1.10hd%-8hun%-ik%-8f%+.5hd2$j7%-3.0s/%+.10i%-c*y%+10.5f=", -18451, -387465, 11003, 4726, 896522, 2864.338557284298, -13341, "^m*", -727654, 'v', 19894.618071940742),
sprintf(boba371, "%-hi%-10d%-1.10hd%-8hun%-ik%-8f%+.5hd2$j7%-3.0s/%+.10i%-c*y%+10.5f=", -18451, -387465, 11003, 4726, 896522, 2864.338557284298, -13341, "^m*", -727654, 'v', 19894.618071940742));
ck_assert_str_eq(boba371_s21, boba371);
}
END_TEST

START_TEST(bebasik__372) {
char boba372_s21[10000];
char boba372[10000];
ck_assert_int_eq(s21_sprintf(boba372_s21, "%-hd", -17261),
sprintf(boba372, "%-hd", -17261));
ck_assert_str_eq(boba372_s21, boba372);
}
END_TEST

START_TEST(bebasik__373) {
char boba373_s21[10000];
char boba373[10000];
ck_assert_int_eq(s21_sprintf(boba373_s21, "%-.7hix%-10.1hic%+.1ia%-2s%-1.7hd#b%-8.5d% f63%+.3f%+hiy)%+fdv^tr%-5.1hi%+.0hi% 6.4ic%-.0f#% hinc;%+4hd%+.8d% 1hi`% hd,o[$", 12372, 3291, 497146, "q37nfh9.josej`9ux#,h;^;d", 28574, 782564, -9493.162063552416, 2676.3558333039346, -28172, -4371.913205142642, 15080, 31289, -36098, -11569.2707096574, -8383, -4679, -893563, -11779, 11490),
sprintf(boba373, "%-.7hix%-10.1hic%+.1ia%-2s%-1.7hd#b%-8.5d% f63%+.3f%+hiy)%+fdv^tr%-5.1hi%+.0hi% 6.4ic%-.0f#% hinc;%+4hd%+.8d% 1hi`% hd,o[$", 12372, 3291, 497146, "q37nfh9.josej`9ux#,h;^;d", 28574, 782564, -9493.162063552416, 2676.3558333039346, -28172, -4371.913205142642, 15080, 31289, -36098, -11569.2707096574, -8383, -4679, -893563, -11779, 11490));
ck_assert_str_eq(boba373_s21, boba373);
}
END_TEST

START_TEST(bebasik__374) {
char boba374_s21[10000];
char boba374[10000];
ck_assert_int_eq(s21_sprintf(boba374_s21, "%-hu% .6hd)% 10.6him%+.6i%-.10hus% 7hik%-.5hd%-6hu&% 7.7hii.y9% 4d)s0qqm% hi8% hivy36^% d%+i[0;g%+8hd%-9.1hd%-.6hi92% 5hi%-hi1.%-.3s(%+.8hd%-4hilb-%-8hu", 24150, 25593, 9877, 718512, 22729, -6397, 21898, -20513, 26761, 543507, 2192, 30291, -792280, -60954, 22280, -29023, -13285, -26059, 22322, "o@[^^0s/u7", 19211, 11707, 22830),
sprintf(boba374, "%-hu% .6hd)% 10.6him%+.6i%-.10hus% 7hik%-.5hd%-6hu&% 7.7hii.y9% 4d)s0qqm% hi8% hivy36^% d%+i[0;g%+8hd%-9.1hd%-.6hi92% 5hi%-hi1.%-.3s(%+.8hd%-4hilb-%-8hu", 24150, 25593, 9877, 718512, 22729, -6397, 21898, -20513, 26761, 543507, 2192, 30291, -792280, -60954, 22280, -29023, -13285, -26059, 22322, "o@[^^0s/u7", 19211, 11707, 22830));
ck_assert_str_eq(boba374_s21, boba374);
}
END_TEST

START_TEST(bebasik__375) {
char boba375_s21[10000];
char boba375[10000];
ck_assert_int_eq(s21_sprintf(boba375_s21, "% d% .5i%-5.10f%-dc%+4.5hi=% .6hif% 3d%+.10i%-hd%+.1dk%-2.2hd)%-9.0ir% i% .2hd% 2iw", 665180, 641665, 4341.991962147953, -386562, 4804, -26592, 47768, 41847, -11276, 673806, 5082, -519647, 140399, -15976, 447672),
sprintf(boba375, "% d% .5i%-5.10f%-dc%+4.5hi=% .6hif% 3d%+.10i%-hd%+.1dk%-2.2hd)%-9.0ir% i% .2hd% 2iw", 665180, 641665, 4341.991962147953, -386562, 4804, -26592, 47768, 41847, -11276, 673806, 5082, -519647, 140399, -15976, 447672));
ck_assert_str_eq(boba375_s21, boba375);
}
END_TEST

START_TEST(bebasik__376) {
char boba376_s21[10000];
char boba376[10000];
ck_assert_int_eq(s21_sprintf(boba376_s21, "%-6hig% d,%-4.7hd%-hu% d%-10.2hd;)!ybd% fgo%+i`%+6hd%-7i%-2hd,%-9.5u% 6.8hi% hibp%+8.2fx$z% 2hd%+4d% 5fu", 13337, -854172, 26796, 30811, -54770, -14566, -2008.5466100976898, 660027, -10228, -968755, -7246, -238553, -3899, -10951, -721.9261627344345, 14331, 197730, 7681.980402641225),
sprintf(boba376, "%-6hig% d,%-4.7hd%-hu% d%-10.2hd;)!ybd% fgo%+i`%+6hd%-7i%-2hd,%-9.5u% 6.8hi% hibp%+8.2fx$z% 2hd%+4d% 5fu", 13337, -854172, 26796, 30811, -54770, -14566, -2008.5466100976898, 660027, -10228, -968755, -7246, -238553, -3899, -10951, -721.9261627344345, 14331, 197730, 7681.980402641225));
ck_assert_str_eq(boba376_s21, boba376);
}
END_TEST

START_TEST(bebasik__377) {
char boba377_s21[10000];
char boba377[10000];
ck_assert_int_eq(s21_sprintf(boba377_s21, "% 8hi%-hd% hd%+.3hi%-.5fox", 4173, -649, -1952, -2372, 15650.0224344125),
sprintf(boba377, "% 8hi%-hd% hd%+.3hi%-.5fox", 4173, -649, -1952, -2372, 15650.0224344125));
ck_assert_str_eq(boba377_s21, boba377);
}
END_TEST

START_TEST(bebasik__378) {
char boba378_s21[10000];
char boba378[10000];
ck_assert_int_eq(s21_sprintf(boba378_s21, "% hi$% 6.7hd0% .1hi% 10.3hd%+.2f23a% 9.2i% .1i%-hd@% .10f%+10.9hi0% .3hit%+.4hi%+3f%-8i% .9hitjj%+10.7hi%+3i% .0hi@%+10.5i%+8hif% hi% .7d%-.8u%+5.2i.u", -12474, -25502, -14586, 16497, -25358.48130452086, 420617, 55613, -22023, 2615.17852159293, 893, -9855, -11469, 12570.846945591891, -343941, 31639, -27968, -754976, 13580, -780748, 21096, 23861, 811302, 656607, 141014),
sprintf(boba378, "% hi$% 6.7hd0% .1hi% 10.3hd%+.2f23a% 9.2i% .1i%-hd@% .10f%+10.9hi0% .3hit%+.4hi%+3f%-8i% .9hitjj%+10.7hi%+3i% .0hi@%+10.5i%+8hif% hi% .7d%-.8u%+5.2i.u", -12474, -25502, -14586, 16497, -25358.48130452086, 420617, 55613, -22023, 2615.17852159293, 893, -9855, -11469, 12570.846945591891, -343941, 31639, -27968, -754976, 13580, -780748, 21096, 23861, 811302, 656607, 141014));
ck_assert_str_eq(boba378_s21, boba378);
}
END_TEST

START_TEST(bebasik__379) {
char boba379_s21[10000];
char boba379[10000];
ck_assert_int_eq(s21_sprintf(boba379_s21, "%+9.9i(k0zz% 8hd% i%-hij% 10.8i%+2f%+f% 10.7d*%+hd^h^d%-6hd%-4hi% hib% .0hd%+2.8hd^%-.10i%-8.7s.u%-.8f,%+9f%-9.10hiy% .10dg%-10.3hi6n", 731891, 14302, 812400, -9106, -925285, 7560.799747711339, 911.6348425022895, 439340, -23219, 27186, 9343, 20506, 1229, 10738, -922965, "xh1(9w`hwjes=q=rt@@u4s)j.bc", -6138.886741750562, 27348.670847459045, 5292, 764925, -28576),
sprintf(boba379, "%+9.9i(k0zz% 8hd% i%-hij% 10.8i%+2f%+f% 10.7d*%+hd^h^d%-6hd%-4hi% hib% .0hd%+2.8hd^%-.10i%-8.7s.u%-.8f,%+9f%-9.10hiy% .10dg%-10.3hi6n", 731891, 14302, 812400, -9106, -925285, 7560.799747711339, 911.6348425022895, 439340, -23219, 27186, 9343, 20506, 1229, 10738, -922965, "xh1(9w`hwjes=q=rt@@u4s)j.bc", -6138.886741750562, 27348.670847459045, 5292, 764925, -28576));
ck_assert_str_eq(boba379_s21, boba379);
}
END_TEST

START_TEST(bebasik__380) {
char boba380_s21[10000];
char boba380[10000];
ck_assert_int_eq(s21_sprintf(boba380_s21, "%-.9f%-s", -7728.428434744762, "019k^!g*d4c-`j&g1,hh&v1-`"),
sprintf(boba380, "%-.9f%-s", -7728.428434744762, "019k^!g*d4c-`j&g1,hh&v1-`"));
ck_assert_str_eq(boba380_s21, boba380);
}
END_TEST

START_TEST(bebasik__381) {
char boba381_s21[10000];
char boba381[10000];
ck_assert_int_eq(s21_sprintf(boba381_s21, "%-1f%-8.4hi9%-.10s9a% 3dn% .10hd%+.3hi%-10.0d% .7f-% 10d%+f3t&$%+.0hd% 9hd5u%+.6hi%+3hi", -8589.847733934199, 28155, "!mvg^f", 457955, 18571, -21016, 407060, -15309.95511361877, 830672, 15352.922074800206, 30704, 26113, 6594, -31580),
sprintf(boba381, "%-1f%-8.4hi9%-.10s9a% 3dn% .10hd%+.3hi%-10.0d% .7f-% 10d%+f3t&$%+.0hd% 9hd5u%+.6hi%+3hi", -8589.847733934199, 28155, "!mvg^f", 457955, 18571, -21016, 407060, -15309.95511361877, 830672, 15352.922074800206, 30704, 26113, 6594, -31580));
ck_assert_str_eq(boba381_s21, boba381);
}
END_TEST

START_TEST(bebasik__382) {
char boba382_s21[10000];
char boba382[10000];
ck_assert_int_eq(s21_sprintf(boba382_s21, "%-.1f`h/v% 1hdj%+2d`2% 5hd%-9.9hu% fu% hd/10%-.5hu%+5hdk#% .10hi%+3.2hd% .4ic%-.5su% .1hi%-i;%+1hd%-9ckn% 8.5hi", 7271.645952509608, -9650, -364919, -3164, 29882, 14129.190090398837, 13, 29928, -30447, 5660, 1990, 378327, "w", -8723, 938971, 5702, 'j', 12568),
sprintf(boba382, "%-.1f`h/v% 1hdj%+2d`2% 5hd%-9.9hu% fu% hd/10%-.5hu%+5hdk#% .10hi%+3.2hd% .4ic%-.5su% .1hi%-i;%+1hd%-9ckn% 8.5hi", 7271.645952509608, -9650, -364919, -3164, 29882, 14129.190090398837, 13, 29928, -30447, 5660, 1990, 378327, "w", -8723, 938971, 5702, 'j', 12568));
ck_assert_str_eq(boba382_s21, boba382);
}
END_TEST

START_TEST(bebasik__383) {
char boba383_s21[10000];
char boba383[10000];
ck_assert_int_eq(s21_sprintf(boba383_s21, "% 9.5d%-9.10hu6%-1.4ssf%+7fpf%-1.7i%-1.10hu%+10.3hdcp%+5f%-hd", -313032, 15562, "mga5z@d&`", -4818.98716266637, 995399, 1615, 14489, 3771.9468020560134, -5113),
sprintf(boba383, "% 9.5d%-9.10hu6%-1.4ssf%+7fpf%-1.7i%-1.10hu%+10.3hdcp%+5f%-hd", -313032, 15562, "mga5z@d&`", -4818.98716266637, 995399, 1615, 14489, 3771.9468020560134, -5113));
ck_assert_str_eq(boba383_s21, boba383);
}
END_TEST

START_TEST(bebasik__384) {
char boba384_s21[10000];
char boba384[10000];
ck_assert_int_eq(s21_sprintf(boba384_s21, "%-hu% 1i%-3.3u%-.4hu%+5dv% 9.10hdy2%+10i%-3sg7[x% .5hi!z%+7.8f%-5.4hd", 17354, 433367, 987894, 21885, -152481, 1722, 567008, "@6./vt.u/p56*0j30iyocyvoe2ua6", -28479, 8798.774262044653, 31623),
sprintf(boba384, "%-hu% 1i%-3.3u%-.4hu%+5dv% 9.10hdy2%+10i%-3sg7[x% .5hi!z%+7.8f%-5.4hd", 17354, 433367, 987894, 21885, -152481, 1722, 567008, "@6./vt.u/p56*0j30iyocyvoe2ua6", -28479, 8798.774262044653, 31623));
ck_assert_str_eq(boba384_s21, boba384);
}
END_TEST

START_TEST(bebasik__385) {
char boba385_s21[10000];
char boba385[10000];
ck_assert_int_eq(s21_sprintf(boba385_s21, "%+8hd7pw%-hi))fq%+.1hd1%+8.1f%-hd% 2.0hd% hd%-7hug%-3.1d-%-hd", 13767, 6558, 24105, 10091.55424818098, -8866, 2570, -6949, -10332, -920552, -3357),
sprintf(boba385, "%+8hd7pw%-hi))fq%+.1hd1%+8.1f%-hd% 2.0hd% hd%-7hug%-3.1d-%-hd", 13767, 6558, 24105, 10091.55424818098, -8866, 2570, -6949, -10332, -920552, -3357));
ck_assert_str_eq(boba385_s21, boba385);
}
END_TEST

START_TEST(bebasik__386) {
char boba386_s21[10000];
char boba386[10000];
ck_assert_int_eq(s21_sprintf(boba386_s21, "%-7i% 1hi% 6.7iul% .6hd", -743487, 31330, -835637, 31564),
sprintf(boba386, "%-7i% 1hi% 6.7iul% .6hd", -743487, 31330, -835637, 31564));
ck_assert_str_eq(boba386_s21, boba386);
}
END_TEST

START_TEST(bebasik__387) {
char boba387_s21[10000];
char boba387[10000];
ck_assert_int_eq(s21_sprintf(boba387_s21, "%-i% 4.0hi", 285169, -19040),
sprintf(boba387, "%-i% 4.0hi", 285169, -19040));
ck_assert_str_eq(boba387_s21, boba387);
}
END_TEST

START_TEST(bebasik__388) {
char boba388_s21[10000];
char boba388[10000];
ck_assert_int_eq(s21_sprintf(boba388_s21, "%+8.8hi,n%-hd% 3i[%-.6hu%-d% 7.5fj5z%-.0d)%+8dho=% 5hdwv%+d%+.6iba*6b%+5hi/% 8.0hd%-4c%-4.6da% .8d%+.2hdli%-4u8% 1hd^% 9.10fv%-.0hu%-.5dy%-9.9hus%+4i", 10652, -30258, -37688, 23208, -426014, -14083.497235103103, -635144, -956052, -30792, -308820, -993862, 12535, 566, 'r', 407599, 223532, 12108, -186074, 10521, -1138.6585306850798, 26617, -814857, 24181, 395847),
sprintf(boba388, "%+8.8hi,n%-hd% 3i[%-.6hu%-d% 7.5fj5z%-.0d)%+8dho=% 5hdwv%+d%+.6iba*6b%+5hi/% 8.0hd%-4c%-4.6da% .8d%+.2hdli%-4u8% 1hd^% 9.10fv%-.0hu%-.5dy%-9.9hus%+4i", 10652, -30258, -37688, 23208, -426014, -14083.497235103103, -635144, -956052, -30792, -308820, -993862, 12535, 566, 'r', 407599, 223532, 12108, -186074, 10521, -1138.6585306850798, 26617, -814857, 24181, 395847));
ck_assert_str_eq(boba388_s21, boba388);
}
END_TEST

START_TEST(bebasik__389) {
char boba389_s21[10000];
char boba389[10000];
ck_assert_int_eq(s21_sprintf(boba389_s21, "%-5.5d)% 7.8hi6g%+1.0i%-5.3it%-1.8hu% .9hiv,% 1.4i%+4hd%+5.9hi#w2%-2utng", 927935, -807, 482087, 119323, 30769, -22267, 800992, 7672, 4570, -512914),
sprintf(boba389, "%-5.5d)% 7.8hi6g%+1.0i%-5.3it%-1.8hu% .9hiv,% 1.4i%+4hd%+5.9hi#w2%-2utng", 927935, -807, 482087, 119323, 30769, -22267, 800992, 7672, 4570, -512914));
ck_assert_str_eq(boba389_s21, boba389);
}
END_TEST

START_TEST(bebasik__390) {
char boba390_s21[10000];
char boba390[10000];
ck_assert_int_eq(s21_sprintf(boba390_s21, "%+2.10f%-.2i%+.2i% fg% 7hi% d%-4.5dh0% 9.10i;;f%+9hi%+.5hi)a%-hd%-.8s#% .4ik[y[&%-.9f;q", 49.5260649164263, 38046, 548498, -332.9459182796036, -15949, -610717, 206042, 193365, -27426, -19275, -6075, "*[ij!h1-)g,ngl)", 245373, 16961.268521893893),
sprintf(boba390, "%+2.10f%-.2i%+.2i% fg% 7hi% d%-4.5dh0% 9.10i;;f%+9hi%+.5hi)a%-hd%-.8s#% .4ik[y[&%-.9f;q", 49.5260649164263, 38046, 548498, -332.9459182796036, -15949, -610717, 206042, 193365, -27426, -19275, -6075, "*[ij!h1-)g,ngl)", 245373, 16961.268521893893));
ck_assert_str_eq(boba390_s21, boba390);
}
END_TEST

START_TEST(bebasik__391) {
char boba391_s21[10000];
char boba391[10000];
ck_assert_int_eq(s21_sprintf(boba391_s21, "%-9hu2in[% hd%+6hi[=%-.6hu%-.4hi", -12683, -18098, 27205, -24575, 17516),
sprintf(boba391, "%-9hu2in[% hd%+6hi[=%-.6hu%-.4hi", -12683, -18098, 27205, -24575, 17516));
ck_assert_str_eq(boba391_s21, boba391);
}
END_TEST

START_TEST(bebasik__392) {
char boba392_s21[10000];
char boba392[10000];
ck_assert_int_eq(s21_sprintf(boba392_s21, "%+2hi4%+hi;%+.9i%-hu%-7.3hu7i% d%+hd`% 1d%+f%+iir%-.10sxmr6%-.7hd% 10hi% 9.7hd28% .0i%+i% 4.4f-nj", 17993, 3134, -513266, -13236, 26057, 817505, -3988, 602356, 2182.156416860346, 958139, "3-knx`", -12277, -5378, -6486, 168496, -680728, -2686.2208651735828),
sprintf(boba392, "%+2hi4%+hi;%+.9i%-hu%-7.3hu7i% d%+hd`% 1d%+f%+iir%-.10sxmr6%-.7hd% 10hi% 9.7hd28% .0i%+i% 4.4f-nj", 17993, 3134, -513266, -13236, 26057, 817505, -3988, 602356, 2182.156416860346, 958139, "3-knx`", -12277, -5378, -6486, 168496, -680728, -2686.2208651735828));
ck_assert_str_eq(boba392_s21, boba392);
}
END_TEST

START_TEST(bebasik__393) {
char boba393_s21[10000];
char boba393[10000];
ck_assert_int_eq(s21_sprintf(boba393_s21, "%-10d0&h%-.5hi", -850219, -17271),
sprintf(boba393, "%-10d0&h%-.5hi", -850219, -17271));
ck_assert_str_eq(boba393_s21, boba393);
}
END_TEST

START_TEST(bebasik__394) {
char boba394_s21[10000];
char boba394[10000];
ck_assert_int_eq(s21_sprintf(boba394_s21, "% 5hi=e%+4i% i% .6hd% .2f%+.1f^4% 1im% .2fq%+fb%+3.3d%+6du%-7hu%-u%-4.8hd%-8d$&/*% dhg%+hd%-3.8hu%+8.2i% 6.5f", -7962, -948137, 222389, 12727, 7817.645192124978, 11358.677255040744, 226500, -14996.034352674349, 656.2414424256569, -459142, 625390, 8814, -61173, -647, -642264, 167215, -26680, -10658, 409632, -14953.337707110048),
sprintf(boba394, "% 5hi=e%+4i% i% .6hd% .2f%+.1f^4% 1im% .2fq%+fb%+3.3d%+6du%-7hu%-u%-4.8hd%-8d$&/*% dhg%+hd%-3.8hu%+8.2i% 6.5f", -7962, -948137, 222389, 12727, 7817.645192124978, 11358.677255040744, 226500, -14996.034352674349, 656.2414424256569, -459142, 625390, 8814, -61173, -647, -642264, 167215, -26680, -10658, 409632, -14953.337707110048));
ck_assert_str_eq(boba394_s21, boba394);
}
END_TEST

START_TEST(bebasik__395) {
char boba395_s21[10000];
char boba395[10000];
ck_assert_int_eq(s21_sprintf(boba395_s21, "% i% 4hd%+.9i%-.2f%-hit%-.4hu%-5f1e% .1hib2% .0hi%+.5d% f% 8.9hd!0%-9i%-i% .2d%+.8hij%+fba9%+2.9hi% f!%+6hd%+.10d*", 895993, 22778, -107904, 15151.972326925395, 11051, -1682, -50.70399764571166, -23200, -7649, 929435, -2888.5125549220375, -7399, -237967, 398325, -752841, -28231, -16368.67152380748, -4980, 12419.953741767582, -31111, 609191),
sprintf(boba395, "% i% 4hd%+.9i%-.2f%-hit%-.4hu%-5f1e% .1hib2% .0hi%+.5d% f% 8.9hd!0%-9i%-i% .2d%+.8hij%+fba9%+2.9hi% f!%+6hd%+.10d*", 895993, 22778, -107904, 15151.972326925395, 11051, -1682, -50.70399764571166, -23200, -7649, 929435, -2888.5125549220375, -7399, -237967, 398325, -752841, -28231, -16368.67152380748, -4980, 12419.953741767582, -31111, 609191));
ck_assert_str_eq(boba395_s21, boba395);
}
END_TEST

START_TEST(bebasik__396) {
char boba396_s21[10000];
char boba396[10000];
ck_assert_int_eq(s21_sprintf(boba396_s21, "%-6hi^lxy%-9f%+8i% 8.1hi^2c%+hi", -24510, -2139.722290664879, 144739, 15737, -2205),
sprintf(boba396, "%-6hi^lxy%-9f%+8i% 8.1hi^2c%+hi", -24510, -2139.722290664879, 144739, 15737, -2205));
ck_assert_str_eq(boba396_s21, boba396);
}
END_TEST

START_TEST(bebasik__397) {
char boba397_s21[10000];
char boba397[10000];
ck_assert_int_eq(s21_sprintf(boba397_s21, "% .2ir%-.4hd% 2.9hd6!%+fb5%-10.4hu0**%-hu% f%+d&d0ae8% .6hi2% .2hd/%-6.6u6j%+hi%+i6%+hd% 7hi%-hd% .1hi% 3hd% 10hd!", 435811, -23963, 7800, 294.2848303895191, -21469, 26600, -11504.8485714661, 900741, -3191, 15421, 215460, -17150, -749243, -755, -28192, 6975, 29245, -17193, -20857),
sprintf(boba397, "% .2ir%-.4hd% 2.9hd6!%+fb5%-10.4hu0**%-hu% f%+d&d0ae8% .6hi2% .2hd/%-6.6u6j%+hi%+i6%+hd% 7hi%-hd% .1hi% 3hd% 10hd!", 435811, -23963, 7800, 294.2848303895191, -21469, 26600, -11504.8485714661, 900741, -3191, 15421, 215460, -17150, -749243, -755, -28192, 6975, 29245, -17193, -20857));
ck_assert_str_eq(boba397_s21, boba397);
}
END_TEST

START_TEST(bebasik__398) {
char boba398_s21[10000];
char boba398[10000];
ck_assert_int_eq(s21_sprintf(boba398_s21, "% 7.9i% 3.4ix%+hd% 8hir%-10.0fs9m%-9.10f%+hi%+f% .9d% hd", 185684, -964128, -28097, 18041, 17368.510005267734, -1935.3023455889902, 2936, 8510.115452709328, 708577, 4322),
sprintf(boba398, "% 7.9i% 3.4ix%+hd% 8hir%-10.0fs9m%-9.10f%+hi%+f% .9d% hd", 185684, -964128, -28097, 18041, 17368.510005267734, -1935.3023455889902, 2936, 8510.115452709328, 708577, 4322));
ck_assert_str_eq(boba398_s21, boba398);
}
END_TEST

START_TEST(bebasik__399) {
char boba399_s21[10000];
char boba399[10000];
ck_assert_int_eq(s21_sprintf(boba399_s21, "% hdh/8% dhqw%-4hi%-.4hi%-8.5hu%+10.0d% hd", 2114, -677934, -11074, -21284, 8181, 196388, 7087),
sprintf(boba399, "% hdh/8% dhqw%-4hi%-.4hi%-8.5hu%+10.0d% hd", 2114, -677934, -11074, -21284, 8181, 196388, 7087));
ck_assert_str_eq(boba399_s21, boba399);
}
END_TEST

START_TEST(bebasik__400) {
char boba400_s21[10000];
char boba400[10000];
ck_assert_int_eq(s21_sprintf(boba400_s21, "%-hd`i%-.10s%+hi", 29683, "t9ax", -10960),
sprintf(boba400, "%-hd`i%-.10s%+hi", 29683, "t9ax", -10960));
ck_assert_str_eq(boba400_s21, boba400);
}
END_TEST

START_TEST(bebasik__401) {
char boba401_s21[10000];
char boba401[10000];
ck_assert_int_eq(s21_sprintf(boba401_s21, "% .4f%-.7hi4%-9s%-fx3%-10.3hdm%+.6ff5%-3hi%+3i,5%+.0f)%+3.10i% 8hd%-1i%+.3fo% .9hi/r% 5.7hih% 7.8ig2=s%-hu1g% 10.1hd4", 11256.888156668103, -9582, "qadin#c", -12604.137341067415, 28764, -4117.177171109005, 14753, -106431, -10319.474751897531, 205491, 12321, 505916, -11157.090988990118, 30167, -140, 767864, 26257, -26416),
sprintf(boba401, "% .4f%-.7hi4%-9s%-fx3%-10.3hdm%+.6ff5%-3hi%+3i,5%+.0f)%+3.10i% 8hd%-1i%+.3fo% .9hi/r% 5.7hih% 7.8ig2=s%-hu1g% 10.1hd4", 11256.888156668103, -9582, "qadin#c", -12604.137341067415, 28764, -4117.177171109005, 14753, -106431, -10319.474751897531, 205491, 12321, 505916, -11157.090988990118, 30167, -140, 767864, 26257, -26416));
ck_assert_str_eq(boba401_s21, boba401);
}
END_TEST

START_TEST(bebasik__402) {
char boba402_s21[10000];
char boba402[10000];
ck_assert_int_eq(s21_sprintf(boba402_s21, "%-.4u,)z$j`%+hd% 7.1f% .4hi%-.9hu%+hdhndwu%+i%+2.1hdw% .0hi%+hd%+10.2i%-9d%+.6hi% .3hd%+.0f%+d&%-.7hi8(%+.7i`-y%+9hd[h;", 522116, 1450, -27945.841128488584, -12802, 17341, -16944, -793483, 26122, -5946, -26867, -715562, 989912, 21591, -7028, -4985.33582333499, -404486, 12326, -519902, 5677),
sprintf(boba402, "%-.4u,)z$j`%+hd% 7.1f% .4hi%-.9hu%+hdhndwu%+i%+2.1hdw% .0hi%+hd%+10.2i%-9d%+.6hi% .3hd%+.0f%+d&%-.7hi8(%+.7i`-y%+9hd[h;", 522116, 1450, -27945.841128488584, -12802, 17341, -16944, -793483, 26122, -5946, -26867, -715562, 989912, 21591, -7028, -4985.33582333499, -404486, 12326, -519902, 5677));
ck_assert_str_eq(boba402_s21, boba402);
}
END_TEST

START_TEST(bebasik__403) {
char boba403_s21[10000];
char boba403[10000];
ck_assert_int_eq(s21_sprintf(boba403_s21, "% .0ic*%+8i&!%+2.0f6e%+7.2hi%+hi% hi%-.6usm@%+.5f2g", -994920, 940425, 5181.816946642055, -28932, 20795, -2710, 12018, -28404.825021439803),
sprintf(boba403, "% .0ic*%+8i&!%+2.0f6e%+7.2hi%+hi% hi%-.6usm@%+.5f2g", -994920, 940425, 5181.816946642055, -28932, 20795, -2710, 12018, -28404.825021439803));
ck_assert_str_eq(boba403_s21, boba403);
}
END_TEST

START_TEST(bebasik__404) {
char boba404_s21[10000];
char boba404[10000];
ck_assert_int_eq(s21_sprintf(boba404_s21, "% hin%+.2hd%-hu6s% 5.4dgw%+8i% .4hd%+.8fs;%+.1i%+hd%-3i;% hd%+7.6hin;%-5u,% 9.0d%+6.9f.w%-7.8f$*", -14814, 10563, -1493, -474624, 358001, 10467, -6357.323504837908, 368853, -31407, 561753, 15101, 18318, -397647, -270732, -21066.743909603687, 6791.478193781147),
sprintf(boba404, "% hin%+.2hd%-hu6s% 5.4dgw%+8i% .4hd%+.8fs;%+.1i%+hd%-3i;% hd%+7.6hin;%-5u,% 9.0d%+6.9f.w%-7.8f$*", -14814, 10563, -1493, -474624, 358001, 10467, -6357.323504837908, 368853, -31407, 561753, 15101, 18318, -397647, -270732, -21066.743909603687, 6791.478193781147));
ck_assert_str_eq(boba404_s21, boba404);
}
END_TEST

START_TEST(bebasik__405) {
char boba405_s21[10000];
char boba405[10000];
ck_assert_int_eq(s21_sprintf(boba405_s21, "%-4.0hu%+1.3f%+i%-hu%-hd#% .1f%-.1s$bvz*a% 3.1f%+10d&% 1hd!!^!% dzuuv$%+4hi$%-f%+.7hisja%+3.1hi0%-9.7u%-f%+8d", 828, -13779.617136032784, 571772, 23427, -28485, -29077.86340987275, "", -10.106692698714555, -114966, -9671, -285830, 19246, 3508.1783992841156, 2277, 27598, -19348, 1132.1514702259055, -968764),
sprintf(boba405, "%-4.0hu%+1.3f%+i%-hu%-hd#% .1f%-.1s$bvz*a% 3.1f%+10d&% 1hd!!^!% dzuuv$%+4hi$%-f%+.7hisja%+3.1hi0%-9.7u%-f%+8d", 828, -13779.617136032784, 571772, 23427, -28485, -29077.86340987275, "", -10.106692698714555, -114966, -9671, -285830, 19246, 3508.1783992841156, 2277, 27598, -19348, 1132.1514702259055, -968764));
ck_assert_str_eq(boba405_s21, boba405);
}
END_TEST

START_TEST(bebasik__406) {
char boba406_s21[10000];
char boba406[10000];
ck_assert_int_eq(s21_sprintf(boba406_s21, "%+hdn%+.1hi%+hd5;/!9%-hd*[ks%+5.1in%-7u,m%+4hd[% .0hdb%-4i%+7.10hi%+9.0da%-5.10u% 4.0hi%+.3hi% 6.7fy%+.4hi0% 5hi*%+9f%-.0s$%+hi%-1hd5% 6.1dlv", 18206, 30081, -368, 8189, 302772, 316281, 4409, -1521, -675356, 324, 689589, 17885, -26441, -5270, -2115.5432380440056, 22827, -2973, 4326.794749015423, "&k$$[p.!w*u$wkc245d.o-", 20141, -10426, -581845),
sprintf(boba406, "%+hdn%+.1hi%+hd5;/!9%-hd*[ks%+5.1in%-7u,m%+4hd[% .0hdb%-4i%+7.10hi%+9.0da%-5.10u% 4.0hi%+.3hi% 6.7fy%+.4hi0% 5hi*%+9f%-.0s$%+hi%-1hd5% 6.1dlv", 18206, 30081, -368, 8189, 302772, 316281, 4409, -1521, -675356, 324, 689589, 17885, -26441, -5270, -2115.5432380440056, 22827, -2973, 4326.794749015423, "&k$$[p.!w*u$wkc245d.o-", 20141, -10426, -581845));
ck_assert_str_eq(boba406_s21, boba406);
}
END_TEST

START_TEST(bebasik__407) {
char boba407_s21[10000];
char boba407[10000];
ck_assert_int_eq(s21_sprintf(boba407_s21, "%-hd% .5f%+6.9i7%+9hd(%-10.4d%+9fldk8", 15540, 5450.907955043001, 695056, 5500, -724456, -8804.252811151242),
sprintf(boba407, "%-hd% .5f%+6.9i7%+9hd(%-10.4d%+9fldk8", 15540, 5450.907955043001, 695056, 5500, -724456, -8804.252811151242));
ck_assert_str_eq(boba407_s21, boba407);
}
END_TEST

START_TEST(bebasik__408) {
char boba408_s21[10000];
char boba408[10000];
ck_assert_int_eq(s21_sprintf(boba408_s21, "% 4f%+d", 10272.383031774085, -97879),
sprintf(boba408, "% 4f%+d", 10272.383031774085, -97879));
ck_assert_str_eq(boba408_s21, boba408);
}
END_TEST

START_TEST(bebasik__409) {
char boba409_s21[10000];
char boba409[10000];
ck_assert_int_eq(s21_sprintf(boba409_s21, "%+8d", -116650),
sprintf(boba409, "%+8d", -116650));
ck_assert_str_eq(boba409_s21, boba409);
}
END_TEST

START_TEST(bebasik__410) {
char boba410_s21[10000];
char boba410[10000];
ck_assert_int_eq(s21_sprintf(boba410_s21, "% 6hd1o%-sw4(%+.8f%-.0d`g%-4.5hij^g%+7.6iz![%+.10df% .0i)", -31264, "y[srd-.8h9alw", 1351.2959735016354, 188826, 303, 742084, -22515, 417987),
sprintf(boba410, "% 6hd1o%-sw4(%+.8f%-.0d`g%-4.5hij^g%+7.6iz![%+.10df% .0i)", -31264, "y[srd-.8h9alw", 1351.2959735016354, 188826, 303, 742084, -22515, 417987));
ck_assert_str_eq(boba410_s21, boba410);
}
END_TEST

START_TEST(bebasik__411) {
char boba411_s21[10000];
char boba411[10000];
ck_assert_int_eq(s21_sprintf(boba411_s21, "% 9.3i`^q% .8hi/s#%-3.5hurl% 2hd% 3.0f%+f.% 8i^&%+.4df0% .0fd%-3.5us% 4.3i*m%+3.2f4egcl..% 10hi*% i% 5hi%-9.1hi%-hd-%-7hi% 9.2hdf0% 4il/h%+5ff% 10f%+.1f%+ddh", 994339, 3990, 725, -14651, -9070.391037294366, 15037.769326472351, 116013, 306328, 7109.214637867465, 14592, 225633, -11474.659421197492, -24522, 733856, 27164, 31615, -25333, -11004, -25739, -940478, 10808.29306854746, -9055.416172925015, -5531.030036203506, 137261),
sprintf(boba411, "% 9.3i`^q% .8hi/s#%-3.5hurl% 2hd% 3.0f%+f.% 8i^&%+.4df0% .0fd%-3.5us% 4.3i*m%+3.2f4egcl..% 10hi*% i% 5hi%-9.1hi%-hd-%-7hi% 9.2hdf0% 4il/h%+5ff% 10f%+.1f%+ddh", 994339, 3990, 725, -14651, -9070.391037294366, 15037.769326472351, 116013, 306328, 7109.214637867465, 14592, 225633, -11474.659421197492, -24522, 733856, 27164, 31615, -25333, -11004, -25739, -940478, 10808.29306854746, -9055.416172925015, -5531.030036203506, 137261));
ck_assert_str_eq(boba411_s21, boba411);
}
END_TEST

START_TEST(bebasik__412) {
char boba412_s21[10000];
char boba412[10000];
ck_assert_int_eq(s21_sprintf(boba412_s21, "% 8.10hd%+9hi%-hu%-5hi%-10f%+hd$% .6f%+5da[m", -18437, 21162, 29882, 12693, 15062.911796954782, -20866, 5921.206183595547, -936017),
sprintf(boba412, "% 8.10hd%+9hi%-hu%-5hi%-10f%+hd$% .6f%+5da[m", -18437, 21162, 29882, 12693, 15062.911796954782, -20866, 5921.206183595547, -936017));
ck_assert_str_eq(boba412_s21, boba412);
}
END_TEST

START_TEST(bebasik__413) {
char boba413_s21[10000];
char boba413[10000];
ck_assert_int_eq(s21_sprintf(boba413_s21, "%-9hd%-.9hi%+4.10hi%-hix% .7iv%+him%-8.1hdh@%+1f% 10.8dn%+.3hi", 24681, -23557, 19216, -19654, -356596, -317, -24477, -20021.671520832857, -337172, -11434),
sprintf(boba413, "%-9hd%-.9hi%+4.10hi%-hix% .7iv%+him%-8.1hdh@%+1f% 10.8dn%+.3hi", 24681, -23557, 19216, -19654, -356596, -317, -24477, -20021.671520832857, -337172, -11434));
ck_assert_str_eq(boba413_s21, boba413);
}
END_TEST

START_TEST(bebasik__414) {
char boba414_s21[10000];
char boba414[10000];
ck_assert_int_eq(s21_sprintf(boba414_s21, "% .4hi%-2.5s% 4.7i%+i%+.10f% 10.2dy% .10hi%+7.2hd%-7.2s%-.0hd79@%+8.8hi%-i%+f%+hd&/&`%+9hiq", -7844, "", 52752, -64080, -1452.4252044468685, -103934, -31215, 9125, "@c6$hpeb36x54b58#;", 11189, 11248, -404633, -15688.279158401292, -14127, 24341),
sprintf(boba414, "% .4hi%-2.5s% 4.7i%+i%+.10f% 10.2dy% .10hi%+7.2hd%-7.2s%-.0hd79@%+8.8hi%-i%+f%+hd&/&`%+9hiq", -7844, "", 52752, -64080, -1452.4252044468685, -103934, -31215, 9125, "@c6$hpeb36x54b58#;", 11189, 11248, -404633, -15688.279158401292, -14127, 24341));
ck_assert_str_eq(boba414_s21, boba414);
}
END_TEST

START_TEST(bebasik__415) {
char boba415_s21[10000];
char boba415[10000];
ck_assert_int_eq(s21_sprintf(boba415_s21, "% 8.5hd%+.9d% .8hija%-10.2hu/h$`% hia%-.6u%+.9hd%-ifsb.%-3.2sh[%-hd%-.6ds%-10.10hu% 2hij(j%-3ff@f% .5i", 10947, 290417, 3165, -20004, 143, -206264, -9248, -315008, ")3", -27449, 64957, 26571, 29354, 2625.2878134137814, -497875),
sprintf(boba415, "% 8.5hd%+.9d% .8hija%-10.2hu/h$`% hia%-.6u%+.9hd%-ifsb.%-3.2sh[%-hd%-.6ds%-10.10hu% 2hij(j%-3ff@f% .5i", 10947, 290417, 3165, -20004, 143, -206264, -9248, -315008, ")3", -27449, 64957, 26571, 29354, 2625.2878134137814, -497875));
ck_assert_str_eq(boba415_s21, boba415);
}
END_TEST

START_TEST(bebasik__416) {
char boba416_s21[10000];
char boba416[10000];
ck_assert_int_eq(s21_sprintf(boba416_s21, "%-1.9hd%+9.10hd% 1f%-hu.% 5di", 14900, -1414, -18398.325652037915, -6500, 549701),
sprintf(boba416, "%-1.9hd%+9.10hd% 1f%-hu.% 5di", 14900, -1414, -18398.325652037915, -6500, 549701));
ck_assert_str_eq(boba416_s21, boba416);
}
END_TEST

START_TEST(bebasik__417) {
char boba417_s21[10000];
char boba417[10000];
ck_assert_int_eq(s21_sprintf(boba417_s21, "%+9.10hib% 8hi% 9.10hd^", 3088, 9084, -24487),
sprintf(boba417, "%+9.10hib% 8hi% 9.10hd^", 3088, 9084, -24487));
ck_assert_str_eq(boba417_s21, boba417);
}
END_TEST

START_TEST(bebasik__418) {
char boba418_s21[10000];
char boba418[10000];
ck_assert_int_eq(s21_sprintf(boba418_s21, "%-.8ix^oz", 60695),
sprintf(boba418, "%-.8ix^oz", 60695));
ck_assert_str_eq(boba418_s21, boba418);
}
END_TEST

START_TEST(bebasik__419) {
char boba419_s21[10000];
char boba419[10000];
ck_assert_int_eq(s21_sprintf(boba419_s21, "%-st(%-.3dli436", "=7cojn-8ry)#;7aty=2[3,4o/*b", -462097),
sprintf(boba419, "%-st(%-.3dli436", "=7cojn-8ry)#;7aty=2[3,4o/*b", -462097));
ck_assert_str_eq(boba419_s21, boba419);
}
END_TEST

START_TEST(bebasik__420) {
char boba420_s21[10000];
char boba420[10000];
ck_assert_int_eq(s21_sprintf(boba420_s21, "% 8.9hd% .6i%+3i(6*waepx% 10.7iwgp% 8hd% .0ds%-hi% 8f)% f!bb(% 6.5hdguj% 4.1hd,% d%+fw%+.9hd% 8.2f@1% hd%+.2hd@b%-6f#%-hiz", -5100, 110971, 864640, -730029, -18876, 271411, 24237, -3714.098757640578, -628.3838779097637, -31341, -31279, -710689, 5811.23096522194, -29382, -14698.44716159765, 23971, 27381, -10510.106553825179, 12072),
sprintf(boba420, "% 8.9hd% .6i%+3i(6*waepx% 10.7iwgp% 8hd% .0ds%-hi% 8f)% f!bb(% 6.5hdguj% 4.1hd,% d%+fw%+.9hd% 8.2f@1% hd%+.2hd@b%-6f#%-hiz", -5100, 110971, 864640, -730029, -18876, 271411, 24237, -3714.098757640578, -628.3838779097637, -31341, -31279, -710689, 5811.23096522194, -29382, -14698.44716159765, 23971, 27381, -10510.106553825179, 12072));
ck_assert_str_eq(boba420_s21, boba420);
}
END_TEST

START_TEST(bebasik__421) {
char boba421_s21[10000];
char boba421[10000];
ck_assert_int_eq(s21_sprintf(boba421_s21, "%-.4s% .10f% hi% 1d%+d3%+3.6hdb%+10.7i%+1.0f% 7.2hi)% .1hd% .10hi", "w6dw@$je,9gs/v-&@w", 3318.598248012153, 26596, -51417, 136539, 11821, 619419, 17901.687469601362, -6773, 4610, 17648),
sprintf(boba421, "%-.4s% .10f% hi% 1d%+d3%+3.6hdb%+10.7i%+1.0f% 7.2hi)% .1hd% .10hi", "w6dw@$je,9gs/v-&@w", 3318.598248012153, 26596, -51417, 136539, 11821, 619419, 17901.687469601362, -6773, 4610, 17648));
ck_assert_str_eq(boba421_s21, boba421);
}
END_TEST

START_TEST(bebasik__422) {
char boba422_s21[10000];
char boba422[10000];
ck_assert_int_eq(s21_sprintf(boba422_s21, "%-hu", 24506),
sprintf(boba422, "%-hu", 24506));
ck_assert_str_eq(boba422_s21, boba422);
}
END_TEST

START_TEST(bebasik__423) {
char boba423_s21[10000];
char boba423[10000];
ck_assert_int_eq(s21_sprintf(boba423_s21, "% 7.6hd%-4hi%-.0hi1%-.10hi% ds%-u8p", -19117, -17178, 26876, 13240, 528004, -492102),
sprintf(boba423, "% 7.6hd%-4hi%-.0hi1%-.10hi% ds%-u8p", -19117, -17178, 26876, 13240, 528004, -492102));
ck_assert_str_eq(boba423_s21, boba423);
}
END_TEST

START_TEST(bebasik__424) {
char boba424_s21[10000];
char boba424[10000];
ck_assert_int_eq(s21_sprintf(boba424_s21, "% .7ia% i%+4f%-.9d45%+f%-3hupa%+10.4d%+7his%-u%+.1hi%-.2hd/=3% hdf", 13960, 94880, 1052.5665967613904, 444012, -6586.956871669409, 23795, 316363, -13657, 959, 3237, -22771, 16210),
sprintf(boba424, "% .7ia% i%+4f%-.9d45%+f%-3hupa%+10.4d%+7his%-u%+.1hi%-.2hd/=3% hdf", 13960, 94880, 1052.5665967613904, 444012, -6586.956871669409, 23795, 316363, -13657, 959, 3237, -22771, 16210));
ck_assert_str_eq(boba424_s21, boba424);
}
END_TEST

START_TEST(bebasik__425) {
char boba425_s21[10000];
char boba425[10000];
ck_assert_int_eq(s21_sprintf(boba425_s21, "% f%+i%-.6d", 15273.56474157008, -840137, -403824),
sprintf(boba425, "% f%+i%-.6d", 15273.56474157008, -840137, -403824));
ck_assert_str_eq(boba425_s21, boba425);
}
END_TEST

START_TEST(bebasik__426) {
char boba426_s21[10000];
char boba426[10000];
ck_assert_int_eq(s21_sprintf(boba426_s21, "%+2.4f7f%+1hdc% 3.10i%+9.6d7o%-d% 7hd[8gb%+.5hi2=%+.7hdda%-.0d&$b%-.1hu%-hu%+4hix", -165.85568114239106, -3909, -497782, -768476, 305834, 14689, -8525, 12458, -83624, 19981, -25464, 21960),
sprintf(boba426, "%+2.4f7f%+1hdc% 3.10i%+9.6d7o%-d% 7hd[8gb%+.5hi2=%+.7hdda%-.0d&$b%-.1hu%-hu%+4hix", -165.85568114239106, -3909, -497782, -768476, 305834, 14689, -8525, 12458, -83624, 19981, -25464, 21960));
ck_assert_str_eq(boba426_s21, boba426);
}
END_TEST

START_TEST(bebasik__427) {
char boba427_s21[10000];
char boba427[10000];
ck_assert_int_eq(s21_sprintf(boba427_s21, "%+2hi% 2hi% 9.1hioh%+.0d%+6d%+hd,p%+.8fy%+d% hd%+6fra%+5fz.%-.5hi%-7iw%+1.6hd%-c%+10.7fiw%+7hd%+7hdf%+2d% 2.8f%+f5ua% d^j% 7i", -24223, 31472, 25894, 828443, 367622, -8965, 11249.060729573566, -775384, -15227, -8518.21453830455, 18302.499241067177, 23412, -155613, 4671, '[', 427.36215688524527, 4524, -1491, -173065, -3418.6470787990615, -8246.414028813228, -169589, 82998),
sprintf(boba427, "%+2hi% 2hi% 9.1hioh%+.0d%+6d%+hd,p%+.8fy%+d% hd%+6fra%+5fz.%-.5hi%-7iw%+1.6hd%-c%+10.7fiw%+7hd%+7hdf%+2d% 2.8f%+f5ua% d^j% 7i", -24223, 31472, 25894, 828443, 367622, -8965, 11249.060729573566, -775384, -15227, -8518.21453830455, 18302.499241067177, 23412, -155613, 4671, '[', 427.36215688524527, 4524, -1491, -173065, -3418.6470787990615, -8246.414028813228, -169589, 82998));
ck_assert_str_eq(boba427_s21, boba427);
}
END_TEST

START_TEST(bebasik__428) {
char boba428_s21[10000];
char boba428[10000];
ck_assert_int_eq(s21_sprintf(boba428_s21, "%-.7hda9#g%+10.1f=@%+1.7hd=4-x% .2hii%-.6s% 6.7i4%-.3i%-.4d% d% .10hi%-i% 6.8hd% .6hi%+hi%-.5f% .9hd", -10368, 12129.442422983037, -31827, 23652, "3ak748#$", 335856, -623366, -891988, -744906, 2862, 262551, 18841, -30116, -22471, -152.88082548486065, 17987),
sprintf(boba428, "%-.7hda9#g%+10.1f=@%+1.7hd=4-x% .2hii%-.6s% 6.7i4%-.3i%-.4d% d% .10hi%-i% 6.8hd% .6hi%+hi%-.5f% .9hd", -10368, 12129.442422983037, -31827, 23652, "3ak748#$", 335856, -623366, -891988, -744906, 2862, 262551, 18841, -30116, -22471, -152.88082548486065, 17987));
ck_assert_str_eq(boba428_s21, boba428);
}
END_TEST

START_TEST(bebasik__429) {
char boba429_s21[10000];
char boba429[10000];
ck_assert_int_eq(s21_sprintf(boba429_s21, "%-.3hi", -26429),
sprintf(boba429, "%-.3hi", -26429));
ck_assert_str_eq(boba429_s21, boba429);
}
END_TEST

START_TEST(bebasik__430) {
char boba430_s21[10000];
char boba430[10000];
ck_assert_int_eq(s21_sprintf(boba430_s21, "%+hi%+4irm%-10.1u%-.1hd77% .5hi% .3hd% hd%+6hd%+1.1hit%-d% hd4%+10.7him%-d[(;d%-4.2hi3h%-.6sq% 9.7i%-4.6hu%-1.2i!b% 7.0hi%+f% 9.0iy;5=%-hd%-9.10hu", 31313, 160847, -386580, -10911, -16236, -1272, 8886, 18620, 13704, 162296, 2128, -24990, -932778, -4075, "@r-d^=,!3xm6[zkg`", 579888, -28018, 729598, -26681, -3384.7540611996687, 683053, 982, 23585),
sprintf(boba430, "%+hi%+4irm%-10.1u%-.1hd77% .5hi% .3hd% hd%+6hd%+1.1hit%-d% hd4%+10.7him%-d[(;d%-4.2hi3h%-.6sq% 9.7i%-4.6hu%-1.2i!b% 7.0hi%+f% 9.0iy;5=%-hd%-9.10hu", 31313, 160847, -386580, -10911, -16236, -1272, 8886, 18620, 13704, 162296, 2128, -24990, -932778, -4075, "@r-d^=,!3xm6[zkg`", 579888, -28018, 729598, -26681, -3384.7540611996687, 683053, 982, 23585));
ck_assert_str_eq(boba430_s21, boba430);
}
END_TEST

START_TEST(bebasik__431) {
char boba431_s21[10000];
char boba431[10000];
ck_assert_int_eq(s21_sprintf(boba431_s21, "%-hd!% 4hiz%+d[% 2hi", -19517, 14761, -307908, 3570),
sprintf(boba431, "%-hd!% 4hiz%+d[% 2hi", -19517, 14761, -307908, 3570));
ck_assert_str_eq(boba431_s21, boba431);
}
END_TEST

START_TEST(bebasik__432) {
char boba432_s21[10000];
char boba432[10000];
ck_assert_int_eq(s21_sprintf(boba432_s21, "%-hd%-d,b%-5i*`p% hi%-hd%-.10s(g%-.7hu% fvj[w% hd!%+hi!v=;w%+hd%+inhy%+8hi% .5hd", 15304, 764394, -557428, 16868, -5783, "v7^4h@q=eo;!onhh6zw==/=v", -17761, -7793.130619597621, 7737, -8125, -1403, -279055, 30893, 13581),
sprintf(boba432, "%-hd%-d,b%-5i*`p% hi%-hd%-.10s(g%-.7hu% fvj[w% hd!%+hi!v=;w%+hd%+inhy%+8hi% .5hd", 15304, 764394, -557428, 16868, -5783, "v7^4h@q=eo;!onhh6zw==/=v", -17761, -7793.130619597621, 7737, -8125, -1403, -279055, 30893, 13581));
ck_assert_str_eq(boba432_s21, boba432);
}
END_TEST

START_TEST(bebasik__433) {
char boba433_s21[10000];
char boba433[10000];
ck_assert_int_eq(s21_sprintf(boba433_s21, "%+6f%-4.3hdo%-.1i", 27013.72732960517, 5306, -50486),
sprintf(boba433, "%+6f%-4.3hdo%-.1i", 27013.72732960517, 5306, -50486));
ck_assert_str_eq(boba433_s21, boba433);
}
END_TEST

START_TEST(bebasik__434) {
char boba434_s21[10000];
char boba434[10000];
ck_assert_int_eq(s21_sprintf(boba434_s21, "% 7.5hd%-u[6z%+.1d;%+7.1hd.-ldx% .1d% .6hd^%-3.10sp%+d!%-hi% .5hi;% .3hi7`p", -16076, -238689, 1210, -21332, -423365, 4101, "^`6zg.4l", 958927, -27672, -31334, 12036),
sprintf(boba434, "% 7.5hd%-u[6z%+.1d;%+7.1hd.-ldx% .1d% .6hd^%-3.10sp%+d!%-hi% .5hi;% .3hi7`p", -16076, -238689, 1210, -21332, -423365, 4101, "^`6zg.4l", 958927, -27672, -31334, 12036));
ck_assert_str_eq(boba434_s21, boba434);
}
END_TEST

START_TEST(bebasik__435) {
char boba435_s21[10000];
char boba435[10000];
ck_assert_int_eq(s21_sprintf(boba435_s21, "%-2.0i#,%+hd% hd%+2.9ic% 2.2hi%-d%-4.1hdh=%+2.1d)% .7hi% i%+.8f$% .8i% 1d@b% 2.7hi%+1.4f%-d% f%+.5hds", 595484, 1803, -3674, -779493, 26548, 612934, -3172, 956172, 23347, 213768, 18749.190267437658, 168215, 290752, -11742, 8171.018915105857, 820324, 17048.11739991309, -3833),
sprintf(boba435, "%-2.0i#,%+hd% hd%+2.9ic% 2.2hi%-d%-4.1hdh=%+2.1d)% .7hi% i%+.8f$% .8i% 1d@b% 2.7hi%+1.4f%-d% f%+.5hds", 595484, 1803, -3674, -779493, 26548, 612934, -3172, 956172, 23347, 213768, 18749.190267437658, 168215, 290752, -11742, 8171.018915105857, 820324, 17048.11739991309, -3833));
ck_assert_str_eq(boba435_s21, boba435);
}
END_TEST

START_TEST(bebasik__436) {
char boba436_s21[10000];
char boba436[10000];
ck_assert_int_eq(s21_sprintf(boba436_s21, "%-8.10hd% 8.7d%+8.2hd%-fe%-.6hd", 18108, 868399, 28728, 7899.134527177731, 2301),
sprintf(boba436, "%-8.10hd% 8.7d%+8.2hd%-fe%-.6hd", 18108, 868399, 28728, 7899.134527177731, 2301));
ck_assert_str_eq(boba436_s21, boba436);
}
END_TEST

START_TEST(bebasik__437) {
char boba437_s21[10000];
char boba437[10000];
ck_assert_int_eq(s21_sprintf(boba437_s21, "%+d6%+2hd%+hd%-.7hd(% .6hi% hd%+i$%+hi/%+5.3hd%-.4uvr%+3.10hdox%-7.2hd", -729987, 12403, -18786, 22778, -113, -21096, -682926, 17135, -14802, 891605, 946, -30333),
sprintf(boba437, "%+d6%+2hd%+hd%-.7hd(% .6hi% hd%+i$%+hi/%+5.3hd%-.4uvr%+3.10hdox%-7.2hd", -729987, 12403, -18786, 22778, -113, -21096, -682926, 17135, -14802, 891605, 946, -30333));
ck_assert_str_eq(boba437_s21, boba437);
}
END_TEST

START_TEST(bebasik__438) {
char boba438_s21[10000];
char boba438[10000];
ck_assert_int_eq(s21_sprintf(boba438_s21, "%-.2hi&9%+2.3hd%-.7hi%-6.1i%+1di%+hi% d%-.3hi%-hd% .0hi9% hij42h%-8i$lvs`^.%-9.9hd!%-3.3hds%+4.5hd1w%-7his% 9.6ic%-1f%-7da% 3.5i% hd%-fd%+7hd%+1.10hd", -4354, -6823, 30733, -259507, -147884, 1296, 68313, -2257, -7234, -15868, 18301, 690686, 28970, 10562, 13161, 28355, -704387, -3519.5740813217058, 55911, -881085, 2232, 1242.7634067897789, 10413, -6567),
sprintf(boba438, "%-.2hi&9%+2.3hd%-.7hi%-6.1i%+1di%+hi% d%-.3hi%-hd% .0hi9% hij42h%-8i$lvs`^.%-9.9hd!%-3.3hds%+4.5hd1w%-7his% 9.6ic%-1f%-7da% 3.5i% hd%-fd%+7hd%+1.10hd", -4354, -6823, 30733, -259507, -147884, 1296, 68313, -2257, -7234, -15868, 18301, 690686, 28970, 10562, 13161, 28355, -704387, -3519.5740813217058, 55911, -881085, 2232, 1242.7634067897789, 10413, -6567));
ck_assert_str_eq(boba438_s21, boba438);
}
END_TEST

START_TEST(bebasik__439) {
char boba439_s21[10000];
char boba439[10000];
ck_assert_int_eq(s21_sprintf(boba439_s21, "%-.4hufz*% 10.7hib%+hd3#", -25251, -8159, 28621),
sprintf(boba439, "%-.4hufz*% 10.7hib%+hd3#", -25251, -8159, 28621));
ck_assert_str_eq(boba439_s21, boba439);
}
END_TEST

START_TEST(bebasik__440) {
char boba440_s21[10000];
char boba440[10000];
ck_assert_int_eq(s21_sprintf(boba440_s21, "%+2f!% f% 10.5f%-hd8&% 9i%+.1f.% .6hdagv%+.6f%+.3hiy-p%-hi% 3d%+.1dg1%-hi-% .0hd", -14182.78531901424, 12266.920946094664, 3065.7601605660475, 11181, -997583, 9124.123115735849, 24678, 1047.9717503206052, -9222, 2127, -572777, -694728, 12379, 12316),
sprintf(boba440, "%+2f!% f% 10.5f%-hd8&% 9i%+.1f.% .6hdagv%+.6f%+.3hiy-p%-hi% 3d%+.1dg1%-hi-% .0hd", -14182.78531901424, 12266.920946094664, 3065.7601605660475, 11181, -997583, 9124.123115735849, 24678, 1047.9717503206052, -9222, 2127, -572777, -694728, 12379, 12316));
ck_assert_str_eq(boba440_s21, boba440);
}
END_TEST

START_TEST(bebasik__441) {
char boba441_s21[10000];
char boba441[10000];
ck_assert_int_eq(s21_sprintf(boba441_s21, "%-10.4hd.1i%-cf%-.2hd%+3d%-u%-.0hu**% .6hibs% .7hin.h%+4i!&0% hi$%-.5hi;d% 10hiwr!%+1.0f", -27152, '7', 27501, -968897, 398732, -109, 2678, -6617, -916588, 6711, 22872, 16160, 6898.4641791085605),
sprintf(boba441, "%-10.4hd.1i%-cf%-.2hd%+3d%-u%-.0hu**% .6hibs% .7hin.h%+4i!&0% hi$%-.5hi;d% 10hiwr!%+1.0f", -27152, '7', 27501, -968897, 398732, -109, 2678, -6617, -916588, 6711, 22872, 16160, 6898.4641791085605));
ck_assert_str_eq(boba441_s21, boba441);
}
END_TEST

START_TEST(bebasik__442) {
char boba442_s21[10000];
char boba442[10000];
ck_assert_int_eq(s21_sprintf(boba442_s21, "% 2hi%+9hdk1%+.3hi%+7.7hi%-8.1hu%-9hi%-.10s%+.2d% 6f%-hd% .5f%+d=y% 5.8hd% .3d=6c% 7hd", -23291, 4752, 2820, -16372, -12631, -23448, "uu[9.y3", -113893, 3674.9712277789904, -19291, -4640.378718057544, -18983, -5867, -302648, 25124),
sprintf(boba442, "% 2hi%+9hdk1%+.3hi%+7.7hi%-8.1hu%-9hi%-.10s%+.2d% 6f%-hd% .5f%+d=y% 5.8hd% .3d=6c% 7hd", -23291, 4752, 2820, -16372, -12631, -23448, "uu[9.y3", -113893, 3674.9712277789904, -19291, -4640.378718057544, -18983, -5867, -302648, 25124));
ck_assert_str_eq(boba442_s21, boba442);
}
END_TEST

START_TEST(bebasik__443) {
char boba443_s21[10000];
char boba443[10000];
ck_assert_int_eq(s21_sprintf(boba443_s21, "% .2ins%-4hu% 3f%+f% .6hdyu%-.3i%+1.9hd% hi0", 859010, -2638, 13862.29369507773, -901.6695348806825, -852, 818176, 13561, 15271),
sprintf(boba443, "% .2ins%-4hu% 3f%+f% .6hdyu%-.3i%+1.9hd% hi0", 859010, -2638, 13862.29369507773, -901.6695348806825, -852, 818176, 13561, 15271));
ck_assert_str_eq(boba443_s21, boba443);
}
END_TEST

START_TEST(bebasik__444) {
char boba444_s21[10000];
char boba444[10000];
ck_assert_int_eq(s21_sprintf(boba444_s21, "%+7.2hd%+9.9hi%+.0hd4% 1.10fs%+i% ddf%-5.6u-%-hd@8%-9ucw", -5451, -24011, -11910, 2222.175589755516, -539484, 154651, -201627, -692, 624218),
sprintf(boba444, "%+7.2hd%+9.9hi%+.0hd4% 1.10fs%+i% ddf%-5.6u-%-hd@8%-9ucw", -5451, -24011, -11910, 2222.175589755516, -539484, 154651, -201627, -692, 624218));
ck_assert_str_eq(boba444_s21, boba444);
}
END_TEST

START_TEST(bebasik__445) {
char boba445_s21[10000];
char boba445[10000];
ck_assert_int_eq(s21_sprintf(boba445_s21, "% hia%-.9hu50rj,7% 8hif5%+9.0hikm%-2.6hd4k% 4i1)#e%+hi", -14001, 8352, 25752, -9797, -14663, 95408, -29893),
sprintf(boba445, "% hia%-.9hu50rj,7% 8hif5%+9.0hikm%-2.6hd4k% 4i1)#e%+hi", -14001, 8352, 25752, -9797, -14663, 95408, -29893));
ck_assert_str_eq(boba445_s21, boba445);
}
END_TEST

START_TEST(bebasik__446) {
char boba446_s21[10000];
char boba446[10000];
ck_assert_int_eq(s21_sprintf(boba446_s21, "%+1hdo8jn#%+10hd0% .5hd% .2hi1%-hd=% f% .7f% .3i% 5f% 9.1hdit%+.10fp=^% .3d1!%+9hibx.;% 4.5hdv% .6d% 9.7hik-(9%-5.7hd%-5d4", 641, -4884, 2598, 6142, -20197, -1878.5902903805195, 2307.7774145498042, 91466, -139.86500536476314, 10489, 14495.666759674004, -803649, 20812, 30365, 471632, -10548, 24441, 989974),
sprintf(boba446, "%+1hdo8jn#%+10hd0% .5hd% .2hi1%-hd=% f% .7f% .3i% 5f% 9.1hdit%+.10fp=^% .3d1!%+9hibx.;% 4.5hdv% .6d% 9.7hik-(9%-5.7hd%-5d4", 641, -4884, 2598, 6142, -20197, -1878.5902903805195, 2307.7774145498042, 91466, -139.86500536476314, 10489, 14495.666759674004, -803649, 20812, 30365, 471632, -10548, 24441, 989974));
ck_assert_str_eq(boba446_s21, boba446);
}
END_TEST

START_TEST(bebasik__447) {
char boba447_s21[10000];
char boba447[10000];
ck_assert_int_eq(s21_sprintf(boba447_s21, "%-.4s%+hd%+3hd% hio% .3hidsf% .2hi).%-.2s%+8.10d%-.8f-4i% 4.6d%-4i9x%+db", "$-ezk8[2qcjv&.`#bs4kf(a2", -11202, -13263, 22645, 28413, -30327, "-9i7h07637x&0jrs&)", -89785, 5697.9543079374425, -627547, 188715, 495123),
sprintf(boba447, "%-.4s%+hd%+3hd% hio% .3hidsf% .2hi).%-.2s%+8.10d%-.8f-4i% 4.6d%-4i9x%+db", "$-ezk8[2qcjv&.`#bs4kf(a2", -11202, -13263, 22645, 28413, -30327, "-9i7h07637x&0jrs&)", -89785, 5697.9543079374425, -627547, 188715, 495123));
ck_assert_str_eq(boba447_s21, boba447);
}
END_TEST

START_TEST(bebasik__448) {
char boba448_s21[10000];
char boba448[10000];
ck_assert_int_eq(s21_sprintf(boba448_s21, "%+7.5hi0vz%-8.0hd/% 7.3dh%-1.10huy,g[%-.8huf%+3hi% .6f#!9z%+i2!4d", 404, 29468, 817690, -29413, -18998, 15086, 155.43580224518763, 558128),
sprintf(boba448, "%+7.5hi0vz%-8.0hd/% 7.3dh%-1.10huy,g[%-.8huf%+3hi% .6f#!9z%+i2!4d", 404, 29468, 817690, -29413, -18998, 15086, 155.43580224518763, 558128));
ck_assert_str_eq(boba448_s21, boba448);
}
END_TEST

START_TEST(bebasik__449) {
char boba449_s21[10000];
char boba449[10000];
ck_assert_int_eq(s21_sprintf(boba449_s21, "% hd%-7hi^q7%+4.4hd%-.0hd%+10hi%+3hi%-.10u%-.1s%-9ik%+hi%+d!m/%-iq%-.4hiy%+.0hd3%-1.5f/.%-u%-4hd(%+i% 2.1hi4x`", -6672, -29122, 18555, -25171, -7960, 2806, 834494, "z0ec#*&ru*1ydb,.=y@", -580332, 23998, -258026, -954563, -13075, 29923, 574.1246303054377, -626892, 9622, -535146, -10580),
sprintf(boba449, "% hd%-7hi^q7%+4.4hd%-.0hd%+10hi%+3hi%-.10u%-.1s%-9ik%+hi%+d!m/%-iq%-.4hiy%+.0hd3%-1.5f/.%-u%-4hd(%+i% 2.1hi4x`", -6672, -29122, 18555, -25171, -7960, 2806, 834494, "z0ec#*&ru*1ydb,.=y@", -580332, 23998, -258026, -954563, -13075, 29923, 574.1246303054377, -626892, 9622, -535146, -10580));
ck_assert_str_eq(boba449_s21, boba449);
}
END_TEST

START_TEST(bebasik__450) {
char boba450_s21[10000];
char boba450[10000];
ck_assert_int_eq(s21_sprintf(boba450_s21, "% hid%+9.7hdx% 3.10hd%-3.7i% 4hdeq%-.7u(% 1.7hdjw.i9(%-coek#em% 4i#0ox9(%-5.7fy% 2.4fp%+hd% f`)8%-.9hd", -13457, 11179, 5460, -980460, -13186, -940132, -676, '4', -368627, 16497.749863365214, 9572.103446304582, 11167, 5288.795598953305, -1448),
sprintf(boba450, "% hid%+9.7hdx% 3.10hd%-3.7i% 4hdeq%-.7u(% 1.7hdjw.i9(%-coek#em% 4i#0ox9(%-5.7fy% 2.4fp%+hd% f`)8%-.9hd", -13457, 11179, 5460, -980460, -13186, -940132, -676, '4', -368627, 16497.749863365214, 9572.103446304582, 11167, 5288.795598953305, -1448));
ck_assert_str_eq(boba450_s21, boba450);
}
END_TEST

START_TEST(bebasik__451) {
char boba451_s21[10000];
char boba451[10000];
ck_assert_int_eq(s21_sprintf(boba451_s21, "%+.10i% .5d% hd7y[5%+7f", 357544, 602739, 31526, -13758.407446702953),
sprintf(boba451, "%+.10i% .5d% hd7y[5%+7f", 357544, 602739, 31526, -13758.407446702953));
ck_assert_str_eq(boba451_s21, boba451);
}
END_TEST

START_TEST(bebasik__452) {
char boba452_s21[10000];
char boba452[10000];
ck_assert_int_eq(s21_sprintf(boba452_s21, "%-2.4hu% 10hdl%+hil%-hu%+.1hi.%+1.2hi^us%+10.7f8o2%-2.10u", 19132, 24909, -29753, -22907, -9752, -29661, -7734.3443680163755, -504373),
sprintf(boba452, "%-2.4hu% 10hdl%+hil%-hu%+.1hi.%+1.2hi^us%+10.7f8o2%-2.10u", 19132, 24909, -29753, -22907, -9752, -29661, -7734.3443680163755, -504373));
ck_assert_str_eq(boba452_s21, boba452);
}
END_TEST

START_TEST(bebasik__453) {
char boba453_s21[10000];
char boba453[10000];
ck_assert_int_eq(s21_sprintf(boba453_s21, "% 3i%+hizr%+9d% .1f4%+hiu%+8hi!wa% .2d%-hdc4", 235778, -12414, -301784, -4640.183630289289, -3569, -11662, 660799, -19034),
sprintf(boba453, "% 3i%+hizr%+9d% .1f4%+hiu%+8hi!wa% .2d%-hdc4", 235778, -12414, -301784, -4640.183630289289, -3569, -11662, 660799, -19034));
ck_assert_str_eq(boba453_s21, boba453);
}
END_TEST

START_TEST(bebasik__454) {
char boba454_s21[10000];
char boba454[10000];
ck_assert_int_eq(s21_sprintf(boba454_s21, "% .2f%-10hu&%+9hig% 3.10i%-1u% hii% i%+7d%-i% .0i7j=%-8hd$`% 9.5hd%+1hi[=*% .5d", -12409.142624996828, -5964, 27358, -721630, -824889, 26631, -680594, 875237, -93639, 539365, -1771, 22484, 1703, 775745),
sprintf(boba454, "% .2f%-10hu&%+9hig% 3.10i%-1u% hii% i%+7d%-i% .0i7j=%-8hd$`% 9.5hd%+1hi[=*% .5d", -12409.142624996828, -5964, 27358, -721630, -824889, 26631, -680594, 875237, -93639, 539365, -1771, 22484, 1703, 775745));
ck_assert_str_eq(boba454_s21, boba454);
}
END_TEST

START_TEST(bebasik__455) {
char boba455_s21[10000];
char boba455[10000];
ck_assert_int_eq(s21_sprintf(boba455_s21, "% 4.4hi%-9cz%+hi%+3.9d%+9.3hd%+hd%-10hu%+.6fzu%+6.8hi3%+.7ik%-hu% .4f", 14423, 'u', -12470, -994740, 948, 22399, 15073, 12.290793340908728, -9746, -56919, -26098, 14215.679098600698),
sprintf(boba455, "% 4.4hi%-9cz%+hi%+3.9d%+9.3hd%+hd%-10hu%+.6fzu%+6.8hi3%+.7ik%-hu% .4f", 14423, 'u', -12470, -994740, 948, 22399, 15073, 12.290793340908728, -9746, -56919, -26098, 14215.679098600698));
ck_assert_str_eq(boba455_s21, boba455);
}
END_TEST

START_TEST(bebasik__456) {
char boba456_s21[10000];
char boba456[10000];
ck_assert_int_eq(s21_sprintf(boba456_s21, "%+.10f/)#eet%+.4i%+.6hi34iv% .8hdq%+6hi%-7.10d%+d/%+.8hi^b% hi%+.6f% 6hd0% 7.9hi% 8i%-hu.", -16981.66645216089, -145005, 24602, 15911, 21571, 782714, 447008, -20845, 31940, 6222.728397998607, 18219, -25056, -750803, 12420),
sprintf(boba456, "%+.10f/)#eet%+.4i%+.6hi34iv% .8hdq%+6hi%-7.10d%+d/%+.8hi^b% hi%+.6f% 6hd0% 7.9hi% 8i%-hu.", -16981.66645216089, -145005, 24602, 15911, 21571, 782714, 447008, -20845, 31940, 6222.728397998607, 18219, -25056, -750803, 12420));
ck_assert_str_eq(boba456_s21, boba456);
}
END_TEST

START_TEST(bebasik__457) {
char boba457_s21[10000];
char boba457[10000];
ck_assert_int_eq(s21_sprintf(boba457_s21, "%+6.0hi% 6hd%+10.5hdpc%+7.6d%-1.8hdf% .2hi% .2hi,%-9hdg8%-.9hd%-.3d=^c%+8.6hi%+.4d%-8c% .0f%-6.4d% .5hi.@%-7hiw@7x%+3.5d%-3hd$w", 7111, 11538, -25461, -281352, -16295, 6501, -548, 27895, -23360, 864650, 17708, 861027, 'x', -765.2875226134706, 930484, 23505, 21540, 225005, 19396),
sprintf(boba457, "%+6.0hi% 6hd%+10.5hdpc%+7.6d%-1.8hdf% .2hi% .2hi,%-9hdg8%-.9hd%-.3d=^c%+8.6hi%+.4d%-8c% .0f%-6.4d% .5hi.@%-7hiw@7x%+3.5d%-3hd$w", 7111, 11538, -25461, -281352, -16295, 6501, -548, 27895, -23360, 864650, 17708, 861027, 'x', -765.2875226134706, 930484, 23505, 21540, 225005, 19396));
ck_assert_str_eq(boba457_s21, boba457);
}
END_TEST

START_TEST(bebasik__458) {
char boba458_s21[10000];
char boba458[10000];
ck_assert_int_eq(s21_sprintf(boba458_s21, "% 8.10hd#o8b% i9% fl[5u#k-% .3hi%+.1hd%+7.6i% hd% .2f%+6.0hd5%+.4him-05d%-10hu5%+6hd%+10hi6%+9.10ij", -30581, 349966, 8054.941008080142, -515, 23756, 847311, -23318, -16069.685916482786, 19472, 24582, -20346, -12019, 22397, 291239),
sprintf(boba458, "% 8.10hd#o8b% i9% fl[5u#k-% .3hi%+.1hd%+7.6i% hd% .2f%+6.0hd5%+.4him-05d%-10hu5%+6hd%+10hi6%+9.10ij", -30581, 349966, 8054.941008080142, -515, 23756, 847311, -23318, -16069.685916482786, 19472, 24582, -20346, -12019, 22397, 291239));
ck_assert_str_eq(boba458_s21, boba458);
}
END_TEST

START_TEST(bebasik__459) {
char boba459_s21[10000];
char boba459[10000];
ck_assert_int_eq(s21_sprintf(boba459_s21, "%+hdxx%+5fw#", -8579, -3316.2715461049984),
sprintf(boba459, "%+hdxx%+5fw#", -8579, -3316.2715461049984));
ck_assert_str_eq(boba459_s21, boba459);
}
END_TEST

START_TEST(bebasik__460) {
char boba460_s21[10000];
char boba460[10000];
ck_assert_int_eq(s21_sprintf(boba460_s21, "% 8d%+.4f%-2.2i% f%-hi;%-.7hu(`k=/6%+9.2fm%-2hu", -810087, -4331.003389289445, -259005, 3919.644021725045, -8748, -15331, -845.7162134415528, -26002),
sprintf(boba460, "% 8d%+.4f%-2.2i% f%-hi;%-.7hu(`k=/6%+9.2fm%-2hu", -810087, -4331.003389289445, -259005, 3919.644021725045, -8748, -15331, -845.7162134415528, -26002));
ck_assert_str_eq(boba460_s21, boba460);
}
END_TEST

START_TEST(bebasik__461) {
char boba461_s21[10000];
char boba461[10000];
ck_assert_int_eq(s21_sprintf(boba461_s21, "% 5.10d% 9i3%+hic%+hd% .8hi%-2.6hd@% 10.0hd%-10f,^oj% 8f=&%-4.9hii%-4u6%+.10hd%-hu", 491208, 249416, -14634, -5545, 4591, -15031, -14435, 25664.65146435717, -8858.600399991386, 9605, -150489, -6016, 181),
sprintf(boba461, "% 5.10d% 9i3%+hic%+hd% .8hi%-2.6hd@% 10.0hd%-10f,^oj% 8f=&%-4.9hii%-4u6%+.10hd%-hu", 491208, 249416, -14634, -5545, 4591, -15031, -14435, 25664.65146435717, -8858.600399991386, 9605, -150489, -6016, 181));
ck_assert_str_eq(boba461_s21, boba461);
}
END_TEST

START_TEST(bebasik__462) {
char boba462_s21[10000];
char boba462[10000];
ck_assert_int_eq(s21_sprintf(boba462_s21, "%-6.5ux", 116374),
sprintf(boba462, "%-6.5ux", 116374));
ck_assert_str_eq(boba462_s21, boba462);
}
END_TEST

START_TEST(bebasik__463) {
char boba463_s21[10000];
char boba463[10000];
ck_assert_int_eq(s21_sprintf(boba463_s21, "%+4.4hi% d%-7hi% hien3% 2hdj% .4d;v`g%+hd% .4i%-huyvk%-hi%-.5u*%+4hi% 5d.yhg/% .4dw% 6f%+.10d%-8.10hu%+.0him% hi%-fm[% 5hd2o%+2.5hi%-i% .7hi!ze9", -11253, 60860, 23211, 19386, 11797, 542002, 2162, -109761, 502, 14165, 226629, -8959, -780312, -488096, 11380.581857598074, 935946, 22809, -17064, -26346, 1572.0653563094959, -29168, -1618, 846366, -6625),
sprintf(boba463, "%+4.4hi% d%-7hi% hien3% 2hdj% .4d;v`g%+hd% .4i%-huyvk%-hi%-.5u*%+4hi% 5d.yhg/% .4dw% 6f%+.10d%-8.10hu%+.0him% hi%-fm[% 5hd2o%+2.5hi%-i% .7hi!ze9", -11253, 60860, 23211, 19386, 11797, 542002, 2162, -109761, 502, 14165, 226629, -8959, -780312, -488096, 11380.581857598074, 935946, 22809, -17064, -26346, 1572.0653563094959, -29168, -1618, 846366, -6625));
ck_assert_str_eq(boba463_s21, boba463);
}
END_TEST

START_TEST(bebasik__464) {
char boba464_s21[10000];
char boba464[10000];
ck_assert_int_eq(s21_sprintf(boba464_s21, "%-.1hi%-8hd% 10f%-5f7%-10.5huf^&% .3f%+hd%+6.8d%-.1hu% 10hi2%-6.3f%-7cp% .9f%-9i% 6.10i%-.6uf% d%+6.4d", -1122, 11681, 2137.316337776445, -5245.882640455208, 9490, 6673.835600960618, -26433, -728814, 17173, -14765, 648.762972359794, 'v', 16586.04754397716, -296247, -263743, -910681, -434486, -290055),
sprintf(boba464, "%-.1hi%-8hd% 10f%-5f7%-10.5huf^&% .3f%+hd%+6.8d%-.1hu% 10hi2%-6.3f%-7cp% .9f%-9i% 6.10i%-.6uf% d%+6.4d", -1122, 11681, 2137.316337776445, -5245.882640455208, 9490, 6673.835600960618, -26433, -728814, 17173, -14765, 648.762972359794, 'v', 16586.04754397716, -296247, -263743, -910681, -434486, -290055));
ck_assert_str_eq(boba464_s21, boba464);
}
END_TEST

START_TEST(bebasik__465) {
char boba465_s21[10000];
char boba465[10000];
ck_assert_int_eq(s21_sprintf(boba465_s21, "% hd!% 8f%+hi3;mr", 12968, 3016.2827501113993, -13315),
sprintf(boba465, "% hd!% 8f%+hi3;mr", 12968, 3016.2827501113993, -13315));
ck_assert_str_eq(boba465_s21, boba465);
}
END_TEST

START_TEST(bebasik__466) {
char boba466_s21[10000];
char boba466[10000];
ck_assert_int_eq(s21_sprintf(boba466_s21, "% .3hd% hi%-.1d%-10.4hd%+8.7i%+.9hi=v%+.3d;%-.10dx7z% dzz%+d% 1hd;5i%-2s", -10621, 30448, 157096, -29179, 778518, 23963, 211921, 602358, 53983, 541061, -31368, "24o(d4ytwsen4fqeql(,["),
sprintf(boba466, "% .3hd% hi%-.1d%-10.4hd%+8.7i%+.9hi=v%+.3d;%-.10dx7z% dzz%+d% 1hd;5i%-2s", -10621, 30448, 157096, -29179, 778518, 23963, 211921, 602358, 53983, 541061, -31368, "24o(d4ytwsen4fqeql(,["));
ck_assert_str_eq(boba466_s21, boba466);
}
END_TEST

START_TEST(bebasik__467) {
char boba467_s21[10000];
char boba467[10000];
ck_assert_int_eq(s21_sprintf(boba467_s21, "%+hd%-4.2hi% 7hd", 10507, 11651, 7423),
sprintf(boba467, "%+hd%-4.2hi% 7hd", 10507, 11651, 7423));
ck_assert_str_eq(boba467_s21, boba467);
}
END_TEST

START_TEST(bebasik__468) {
char boba468_s21[10000];
char boba468[10000];
ck_assert_int_eq(s21_sprintf(boba468_s21, "%-dh% d%-c@% 8.8f%-4.7hu%-1.9i%+7.8hif(%-1c7mj!a@r=f% 6f%-5c%-4hica%-.7hi% hi", -795004, -522885, 'a', 3287.6328018998115, -13048, 505320, 21284, '9', -9071.403164022599, '6', -16961, -27424, -27945),
sprintf(boba468, "%-dh% d%-c@% 8.8f%-4.7hu%-1.9i%+7.8hif(%-1c7mj!a@r=f% 6f%-5c%-4hica%-.7hi% hi", -795004, -522885, 'a', 3287.6328018998115, -13048, 505320, 21284, '9', -9071.403164022599, '6', -16961, -27424, -27945));
ck_assert_str_eq(boba468_s21, boba468);
}
END_TEST

START_TEST(bebasik__469) {
char boba469_s21[10000];
char boba469[10000];
ck_assert_int_eq(s21_sprintf(boba469_s21, "% .6hi%+hi%-4.1u%-8s%+f%+7hi%+hdo%-2f%+10d% 5.8hi% 4.1hiu5%+hdw%+hd% hdty;7[su%-9.9f!$yz%+.3d%-5.9hip6x%-.9fji% 3.5d% .6him9", 13694, 1526, -274142, "rrjc-&,v4g0w$^x-lehcvi", -2658.711609099352, -17840, 3338, 6288.816799639289, 515849, -18939, -4173, 9335, 31939, -27988, -155.2878285175573, -370446, 20439, 6589.713186141138, 119007, -21154),
sprintf(boba469, "% .6hi%+hi%-4.1u%-8s%+f%+7hi%+hdo%-2f%+10d% 5.8hi% 4.1hiu5%+hdw%+hd% hdty;7[su%-9.9f!$yz%+.3d%-5.9hip6x%-.9fji% 3.5d% .6him9", 13694, 1526, -274142, "rrjc-&,v4g0w$^x-lehcvi", -2658.711609099352, -17840, 3338, 6288.816799639289, 515849, -18939, -4173, 9335, 31939, -27988, -155.2878285175573, -370446, 20439, 6589.713186141138, 119007, -21154));
ck_assert_str_eq(boba469_s21, boba469);
}
END_TEST

START_TEST(bebasik__470) {
char boba470_s21[10000];
char boba470[10000];
ck_assert_int_eq(s21_sprintf(boba470_s21, "%-c%+6.5hiy#%+hi", 's', 24988, 18072),
sprintf(boba470, "%-c%+6.5hiy#%+hi", 's', 24988, 18072));
ck_assert_str_eq(boba470_s21, boba470);
}
END_TEST

START_TEST(bebasik__471) {
char boba471_s21[10000];
char boba471[10000];
ck_assert_int_eq(s21_sprintf(boba471_s21, "% 9.6f6%+.4d-% hd6r%-.1husx% .2i%+10.2hi% 6.1hd% hi[/%+.3i% .1hdj%+1hd%-1.8f%+f(% .5hd,,.%+9hi/%+.10hd%+.5i%-10hu% 7.4d%-1hid[rk)% 10f-", -11719.963996203891, 234646, 17809, -2150, -758034, -25032, 9249, -2451, 806305, -19, -3977, -6666.518139403887, 2752.380241516641, -8483, 11240, 5180, -150945, 6935, -903752, -13466, 8400.082445412017),
sprintf(boba471, "% 9.6f6%+.4d-% hd6r%-.1husx% .2i%+10.2hi% 6.1hd% hi[/%+.3i% .1hdj%+1hd%-1.8f%+f(% .5hd,,.%+9hi/%+.10hd%+.5i%-10hu% 7.4d%-1hid[rk)% 10f-", -11719.963996203891, 234646, 17809, -2150, -758034, -25032, 9249, -2451, 806305, -19, -3977, -6666.518139403887, 2752.380241516641, -8483, 11240, 5180, -150945, 6935, -903752, -13466, 8400.082445412017));
ck_assert_str_eq(boba471_s21, boba471);
}
END_TEST

START_TEST(bebasik__472) {
char boba472_s21[10000];
char boba472[10000];
ck_assert_int_eq(s21_sprintf(boba472_s21, "%+5hi.q%-i#w-yg9% 9.6hdo", -4242, -334977, -11294),
sprintf(boba472, "%+5hi.q%-i#w-yg9% 9.6hdo", -4242, -334977, -11294));
ck_assert_str_eq(boba472_s21, boba472);
}
END_TEST

START_TEST(bebasik__473) {
char boba473_s21[10000];
char boba473[10000];
ck_assert_int_eq(s21_sprintf(boba473_s21, "%+7hd[f%+2.1hd%-.0s=le%+f#% 4.8hd&`i% 3hd%-8.4hd% f5%+8.3hd% .5hid%+9.2hd3ps% .4hi3i8%-1hu)", 31724, -14302, "0k=0ms.&w-9*4m@hg6;wq`!3f4", 3404.60815511405, -26769, 16344, 21433, 1748.6773534850863, 7097, -13686, 4556, 22398, 2792),
sprintf(boba473, "%+7hd[f%+2.1hd%-.0s=le%+f#% 4.8hd&`i% 3hd%-8.4hd% f5%+8.3hd% .5hid%+9.2hd3ps% .4hi3i8%-1hu)", 31724, -14302, "0k=0ms.&w-9*4m@hg6;wq`!3f4", 3404.60815511405, -26769, 16344, 21433, 1748.6773534850863, 7097, -13686, 4556, 22398, 2792));
ck_assert_str_eq(boba473_s21, boba473);
}
END_TEST

START_TEST(bebasik__474) {
char boba474_s21[10000];
char boba474[10000];
ck_assert_int_eq(s21_sprintf(boba474_s21, "%-8.3hu%-.9hu,%+10hdu%-3.10hi% 6hi(", -12972, -27560, -25284, 9170, 14013),
sprintf(boba474, "%-8.3hu%-.9hu,%+10hdu%-3.10hi% 6hi(", -12972, -27560, -25284, 9170, 14013));
ck_assert_str_eq(boba474_s21, boba474);
}
END_TEST

START_TEST(bebasik__475) {
char boba475_s21[10000];
char boba475[10000];
ck_assert_int_eq(s21_sprintf(boba475_s21, "% 5hdh%-.9i;!q%+.4i%-f%+5.8him%-2c% 3hd%-5c%+1.6i%-10.8d% 8hd%+6.7hdy^%-hu8% 3.3d%-3i%+.9f", -9410, 908415, 805015, 49.33038254076648, 5898, 's', -25835, '0', 21502, 968447, -2642, -30618, -3831, 80828, -689610, 19418.089795418906),
sprintf(boba475, "% 5hdh%-.9i;!q%+.4i%-f%+5.8him%-2c% 3hd%-5c%+1.6i%-10.8d% 8hd%+6.7hdy^%-hu8% 3.3d%-3i%+.9f", -9410, 908415, 805015, 49.33038254076648, 5898, 's', -25835, '0', 21502, 968447, -2642, -30618, -3831, 80828, -689610, 19418.089795418906));
ck_assert_str_eq(boba475_s21, boba475);
}
END_TEST

START_TEST(bebasik__476) {
char boba476_s21[10000];
char boba476[10000];
ck_assert_int_eq(s21_sprintf(boba476_s21, "% 5.4dt%-1hi!3%-6.9huz%-.7f%+4hd@%+4hin%-.10u%+f%+8.2f%+8i%+dy%+2d%-c% hifd4% .5hd% .1f%+.1ir%-.8hu3% 2f% 2hd%-.7s90`%+1.2il", -233565, -26971, -12383, 1989.0842537867045, 17534, -262, -56485, -299.9272136161563, -20434.450247633577, 64341, 723426, -449948, ',', -17081, -30710, 11539.811083572511, -419842, 28158, 6605.833672385183, 29889, "t", 97703),
sprintf(boba476, "% 5.4dt%-1hi!3%-6.9huz%-.7f%+4hd@%+4hin%-.10u%+f%+8.2f%+8i%+dy%+2d%-c% hifd4% .5hd% .1f%+.1ir%-.8hu3% 2f% 2hd%-.7s90`%+1.2il", -233565, -26971, -12383, 1989.0842537867045, 17534, -262, -56485, -299.9272136161563, -20434.450247633577, 64341, 723426, -449948, ',', -17081, -30710, 11539.811083572511, -419842, 28158, 6605.833672385183, 29889, "t", 97703));
ck_assert_str_eq(boba476_s21, boba476);
}
END_TEST

START_TEST(bebasik__477) {
char boba477_s21[10000];
char boba477[10000];
ck_assert_int_eq(s21_sprintf(boba477_s21, "%-u9%-.3db%-5hi%+5i%+8f*%+7f%+3fb%+d&r%+dsmb%+f%-10.10hi% 2hityz% 10i% hin% 6.1hi% 6dhthn% 5.5i)te% .7hi%-.6s4% 9.10i%-9hu%-3u%-.10hd9r", 597343, 190871, -20967, 577473, -16662.631846297994, 3378.2435125171037, 17710.88026955456, 243371, 279296, 8825.773684369342, -20319, -10551, 651268, 25854, 18422, 179288, -558517, -10090, "w#g;,2pgsk5@1k!d1!;(=w@!y0z", 966538, -838, -481989, 25837),
sprintf(boba477, "%-u9%-.3db%-5hi%+5i%+8f*%+7f%+3fb%+d&r%+dsmb%+f%-10.10hi% 2hityz% 10i% hin% 6.1hi% 6dhthn% 5.5i)te% .7hi%-.6s4% 9.10i%-9hu%-3u%-.10hd9r", 597343, 190871, -20967, 577473, -16662.631846297994, 3378.2435125171037, 17710.88026955456, 243371, 279296, 8825.773684369342, -20319, -10551, 651268, 25854, 18422, 179288, -558517, -10090, "w#g;,2pgsk5@1k!d1!;(=w@!y0z", 966538, -838, -481989, 25837));
ck_assert_str_eq(boba477_s21, boba477);
}
END_TEST

START_TEST(bebasik__478) {
char boba478_s21[10000];
char boba478[10000];
ck_assert_int_eq(s21_sprintf(boba478_s21, "%-8.2hutc&)/g,% .0fi0q0%-6.9hu%+4.9f$^%-hu.%-i%-7hd95%+d&% hdqo% .4d8$.*%-.10huuu%-hu%+10f% 1i7wv", 19185, -4807.476397914441, 5121, 2851.881388303772, 25156, 719743, 25580, 249555, -30863, 583645, -20814, 4425, -561.5532138134533, -167988),
sprintf(boba478, "%-8.2hutc&)/g,% .0fi0q0%-6.9hu%+4.9f$^%-hu.%-i%-7hd95%+d&% hdqo% .4d8$.*%-.10huuu%-hu%+10f% 1i7wv", 19185, -4807.476397914441, 5121, 2851.881388303772, 25156, 719743, 25580, 249555, -30863, 583645, -20814, 4425, -561.5532138134533, -167988));
ck_assert_str_eq(boba478_s21, boba478);
}
END_TEST

START_TEST(bebasik__479) {
char boba479_s21[10000];
char boba479[10000];
ck_assert_int_eq(s21_sprintf(boba479_s21, "% 5.9f^%-3.0hi,&a% 3.9f% 10.9hdt(% 1.7hd`==c6i%+2.3hi%+9hi-x% hdz% 1fg4%+hdf%+2.10di% .4hi@%-hij% 9.7hd%-8.7hi%+hif", 7029.313586198521, 20718, -7781.865059918657, 11022, 15758, -20802, -933, 1091, 2745.8283379569157, 20529, -494697, -20603, -13794, -7238, -9562, -18448),
sprintf(boba479, "% 5.9f^%-3.0hi,&a% 3.9f% 10.9hdt(% 1.7hd`==c6i%+2.3hi%+9hi-x% hdz% 1fg4%+hdf%+2.10di% .4hi@%-hij% 9.7hd%-8.7hi%+hif", 7029.313586198521, 20718, -7781.865059918657, 11022, 15758, -20802, -933, 1091, 2745.8283379569157, 20529, -494697, -20603, -13794, -7238, -9562, -18448));
ck_assert_str_eq(boba479_s21, boba479);
}
END_TEST

START_TEST(bebasik__480) {
char boba480_s21[10000];
char boba480[10000];
ck_assert_int_eq(s21_sprintf(boba480_s21, "% .1fw%-1d7%-f@%+9.5hifw%-.10fq% 6hd%-it%-.1sx%+f&80%-7hi%+1.3i%-hi% 4.5i%-hur%-de% d%+3i", -151.59036991948355, -184749, 9570.203053663337, -23281, -1874.2007179671282, -626, -221950, "[p2by8.w..r$j80,bi[4", 9.64440916141022, -17793, -578169, 7687, -846074, 1262, 53290, -233138, -323365),
sprintf(boba480, "% .1fw%-1d7%-f@%+9.5hifw%-.10fq% 6hd%-it%-.1sx%+f&80%-7hi%+1.3i%-hi% 4.5i%-hur%-de% d%+3i", -151.59036991948355, -184749, 9570.203053663337, -23281, -1874.2007179671282, -626, -221950, "[p2by8.w..r$j80,bi[4", 9.64440916141022, -17793, -578169, 7687, -846074, 1262, 53290, -233138, -323365));
ck_assert_str_eq(boba480_s21, boba480);
}
END_TEST

START_TEST(bebasik__481) {
char boba481_s21[10000];
char boba481[10000];
ck_assert_int_eq(s21_sprintf(boba481_s21, "% 7d%-f%-8hu%+hi%+.2f%-hu%-.5f^%-.8hu.93% f% 8.0hi% .6iy2d% da%-1se% 4.5d% 9.3i7% 9.3hi", 417750, 20.52900829487969, -23611, 5661, -16616.628163753543, 26095, -2401.408485426928, 26287, -16220.760836405947, 10254, 146336, 639047, "$yifuu$29jp(^0,&$xo", 482123, -480950, 1690),
sprintf(boba481, "% 7d%-f%-8hu%+hi%+.2f%-hu%-.5f^%-.8hu.93% f% 8.0hi% .6iy2d% da%-1se% 4.5d% 9.3i7% 9.3hi", 417750, 20.52900829487969, -23611, 5661, -16616.628163753543, 26095, -2401.408485426928, 26287, -16220.760836405947, 10254, 146336, 639047, "$yifuu$29jp(^0,&$xo", 482123, -480950, 1690));
ck_assert_str_eq(boba481_s21, boba481);
}
END_TEST

START_TEST(bebasik__482) {
char boba482_s21[10000];
char boba482[10000];
ck_assert_int_eq(s21_sprintf(boba482_s21, "%+hi", -15846),
sprintf(boba482, "%+hi", -15846));
ck_assert_str_eq(boba482_s21, boba482);
}
END_TEST

START_TEST(bebasik__483) {
char boba483_s21[10000];
char boba483[10000];
ck_assert_int_eq(s21_sprintf(boba483_s21, "%-9.5u;k%-.4i% 4.9d%+hi%+hi%+4.9il%+6hi%+2.5hd%-7d7-%-dlzx5%+hi%-.2f%+hii%+.3hi% f% 3.5i% hd%+5.8hi%+10hi,h%-u./wm1ax% .6hd(2%+.9hi7%+3f.*%-4ug", 806742, 330923, 89844, -9454, -11333, -705612, -2320, -26670, -597640, -780274, -3661, -8684.93595225634, 12119, 15993, -109.46785028672119, -936239, -7019, 2308, -2982, -74669, -967, 1663, -3081.6853038159998, 227241),
sprintf(boba483, "%-9.5u;k%-.4i% 4.9d%+hi%+hi%+4.9il%+6hi%+2.5hd%-7d7-%-dlzx5%+hi%-.2f%+hii%+.3hi% f% 3.5i% hd%+5.8hi%+10hi,h%-u./wm1ax% .6hd(2%+.9hi7%+3f.*%-4ug", 806742, 330923, 89844, -9454, -11333, -705612, -2320, -26670, -597640, -780274, -3661, -8684.93595225634, 12119, 15993, -109.46785028672119, -936239, -7019, 2308, -2982, -74669, -967, 1663, -3081.6853038159998, 227241));
ck_assert_str_eq(boba483_s21, boba483);
}
END_TEST

START_TEST(bebasik__484) {
char boba484_s21[10000];
char boba484[10000];
ck_assert_int_eq(s21_sprintf(boba484_s21, "%+.9i%-5hd%-5s%+hd%+2hi% hdub,%+.5i)%+hi% .7i", 545925, 9208, "tc@x/a*h4", 15055, -25581, -30026, 155813, 18391, -711007),
sprintf(boba484, "%+.9i%-5hd%-5s%+hd%+2hi% hdub,%+.5i)%+hi% .7i", 545925, 9208, "tc@x/a*h4", 15055, -25581, -30026, 155813, 18391, -711007));
ck_assert_str_eq(boba484_s21, boba484);
}
END_TEST

START_TEST(bebasik__485) {
char boba485_s21[10000];
char boba485[10000];
ck_assert_int_eq(s21_sprintf(boba485_s21, "%-3.3d% .7hd@% 7.1hi% .6hdk(&% 9him^%-.7uv!% .0hi%-2.3s%-1f6(1@zax% d(#%+.1hi%-hu% dzf%+i%-hd%-.4huh%-hu.[% 6i", 252070, -23032, 1798, 14941, -1010, 47666, 4937, "h`$[).yq", -15581.630132767175, 27314, 12911, 408, -182358, 797592, -12071, 12, 10719, -36496),
sprintf(boba485, "%-3.3d% .7hd@% 7.1hi% .6hdk(&% 9him^%-.7uv!% .0hi%-2.3s%-1f6(1@zax% d(#%+.1hi%-hu% dzf%+i%-hd%-.4huh%-hu.[% 6i", 252070, -23032, 1798, 14941, -1010, 47666, 4937, "h`$[).yq", -15581.630132767175, 27314, 12911, 408, -182358, 797592, -12071, 12, 10719, -36496));
ck_assert_str_eq(boba485_s21, boba485);
}
END_TEST

START_TEST(bebasik__486) {
char boba486_s21[10000];
char boba486[10000];
ck_assert_int_eq(s21_sprintf(boba486_s21, "% i", -412475),
sprintf(boba486, "% i", -412475));
ck_assert_str_eq(boba486_s21, boba486);
}
END_TEST

START_TEST(bebasik__487) {
char boba487_s21[10000];
char boba487[10000];
ck_assert_int_eq(s21_sprintf(boba487_s21, "%-2f@%-.8hue8.z^% .2d%+.1hd% 7.1d)%-4hu#%-hd%-.4hu%-4.1u%+.6f%-4.3hub`-9r", -3066.7949467568096, -13496, 681702, -28097, 651791, -21905, 7683, -2817, -616769, -2851.5330403654234, -29736),
sprintf(boba487, "%-2f@%-.8hue8.z^% .2d%+.1hd% 7.1d)%-4hu#%-hd%-.4hu%-4.1u%+.6f%-4.3hub`-9r", -3066.7949467568096, -13496, 681702, -28097, 651791, -21905, 7683, -2817, -616769, -2851.5330403654234, -29736));
ck_assert_str_eq(boba487_s21, boba487);
}
END_TEST

START_TEST(bebasik__488) {
char boba488_s21[10000];
char boba488[10000];
ck_assert_int_eq(s21_sprintf(boba488_s21, "%-.1f)%+9i7%-5.10hd@", -4860.369663379521, -827810, 16337),
sprintf(boba488, "%-.1f)%+9i7%-5.10hd@", -4860.369663379521, -827810, 16337));
ck_assert_str_eq(boba488_s21, boba488);
}
END_TEST

START_TEST(bebasik__489) {
char boba489_s21[10000];
char boba489[10000];
ck_assert_int_eq(s21_sprintf(boba489_s21, "%-4.3hie&;%+2fik$%-.1u%-.10hu=", -145, 826.8844102992252, -715264, -13007),
sprintf(boba489, "%-4.3hie&;%+2fik$%-.1u%-.10hu=", -145, 826.8844102992252, -715264, -13007));
ck_assert_str_eq(boba489_s21, boba489);
}
END_TEST

START_TEST(bebasik__490) {
char boba490_s21[10000];
char boba490[10000];
ck_assert_int_eq(s21_sprintf(boba490_s21, "%+9hd%-hd!%-s%-6d808", 6500, 1003, "g(8b/*^v#y(t/x-", -51179),
sprintf(boba490, "%+9hd%-hd!%-s%-6d808", 6500, 1003, "g(8b/*^v#y(t/x-", -51179));
ck_assert_str_eq(boba490_s21, boba490);
}
END_TEST

START_TEST(bebasik__491) {
char boba491_s21[10000];
char boba491[10000];
ck_assert_int_eq(s21_sprintf(boba491_s21, "% hi%-6.10hd,%-1.7s%-hu,u%-4.1sm%+7.3hidz3% hi%-hid%+8hi%-.2sio%+4hilh%+4idw%-3hi3%-.0u0xh[%+9hd*% .4hd%+3.9hi%-8.4igq% 5.4d%+.7hi%+hd% 9d%-8.6hixa-% 3.1hd", -27668, -3824, ".2)[l854rj7@q$0&d;/a(#-r", -11140, "2u`)@!jy7m50;[c8d8[6-5", 17895, 26677, 25546, 19744, "t", -9310, 688868, 18687, -877629, -30678, 23226, 8432, 979130, 530277, -28523, -19847, -126219, -5891, -2637),
sprintf(boba491, "% hi%-6.10hd,%-1.7s%-hu,u%-4.1sm%+7.3hidz3% hi%-hid%+8hi%-.2sio%+4hilh%+4idw%-3hi3%-.0u0xh[%+9hd*% .4hd%+3.9hi%-8.4igq% 5.4d%+.7hi%+hd% 9d%-8.6hixa-% 3.1hd", -27668, -3824, ".2)[l854rj7@q$0&d;/a(#-r", -11140, "2u`)@!jy7m50;[c8d8[6-5", 17895, 26677, 25546, 19744, "t", -9310, 688868, 18687, -877629, -30678, 23226, 8432, 979130, 530277, -28523, -19847, -126219, -5891, -2637));
ck_assert_str_eq(boba491_s21, boba491);
}
END_TEST

START_TEST(bebasik__492) {
char boba492_s21[10000];
char boba492[10000];
ck_assert_int_eq(s21_sprintf(boba492_s21, "%+i% .10d$ssb%+hd%-10.0s% 7.4hdl%+hi% 10hd.#% hio%-9hu7%-.4hu%+10.2d% hd", -921961, 43012, -4477, "y$nwircq(no.y0e;*44rq&k2r=w", 8523, -13571, -5934, 3287, 12151, -25671, 383824, -27324),
sprintf(boba492, "%+i% .10d$ssb%+hd%-10.0s% 7.4hdl%+hi% 10hd.#% hio%-9hu7%-.4hu%+10.2d% hd", -921961, 43012, -4477, "y$nwircq(no.y0e;*44rq&k2r=w", 8523, -13571, -5934, 3287, 12151, -25671, 383824, -27324));
ck_assert_str_eq(boba492_s21, boba492);
}
END_TEST

START_TEST(bebasik__493) {
char boba493_s21[10000];
char boba493[10000];
ck_assert_int_eq(s21_sprintf(boba493_s21, "%-9.3f% 4i02)*% .9fn% hi*)% .1hd%-.10i%+4hd,`%+hi[% 6.0f% i%+6dy%+5.4hi% 8.5i% .5it%-.8f%-6u% 1.9d-%+.4f4#o%+7.4i[&4% hi9%+hi%+.10hi%-1.4s", 14537.512812162604, -730753, 8750.566733666523, 29582, -1651, 357468, -5334, 8937, -9070.843278032524, -298397, -988787, 25848, 791266, 558571, 401.8203805366497, -905270, 456837, 9165.369313541829, -811632, -26235, 29188, -25717, "2`fpinxa7#6(jeo^&2cr@g;nm5"),
sprintf(boba493, "%-9.3f% 4i02)*% .9fn% hi*)% .1hd%-.10i%+4hd,`%+hi[% 6.0f% i%+6dy%+5.4hi% 8.5i% .5it%-.8f%-6u% 1.9d-%+.4f4#o%+7.4i[&4% hi9%+hi%+.10hi%-1.4s", 14537.512812162604, -730753, 8750.566733666523, 29582, -1651, 357468, -5334, 8937, -9070.843278032524, -298397, -988787, 25848, 791266, 558571, 401.8203805366497, -905270, 456837, 9165.369313541829, -811632, -26235, 29188, -25717, "2`fpinxa7#6(jeo^&2cr@g;nm5"));
ck_assert_str_eq(boba493_s21, boba493);
}
END_TEST

START_TEST(bebasik__494) {
char boba494_s21[10000];
char boba494[10000];
ck_assert_int_eq(s21_sprintf(boba494_s21, "%-3f%+9.3f", -14428.151880592004, -2759.005814321286),
sprintf(boba494, "%-3f%+9.3f", -14428.151880592004, -2759.005814321286));
ck_assert_str_eq(boba494_s21, boba494);
}
END_TEST

START_TEST(bebasik__495) {
char boba495_s21[10000];
char boba495[10000];
ck_assert_int_eq(s21_sprintf(boba495_s21, "%+f%-4hd%-9hd%+10.1hd%-10.3hi", -12884.650589792107, -30321, -16142, -14456, 25351),
sprintf(boba495, "%+f%-4hd%-9hd%+10.1hd%-10.3hi", -12884.650589792107, -30321, -16142, -14456, 25351));
ck_assert_str_eq(boba495_s21, boba495);
}
END_TEST

START_TEST(bebasik__496) {
char boba496_s21[10000];
char boba496[10000];
ck_assert_int_eq(s21_sprintf(boba496_s21, "% 3.8hi% 10.5f%-.5uv% .5hdx% .8fk%+d%+ff8% 6.10hd%-hd`f^%+i7% .8hdy%-2.6f%-.0d1@x%+hi8%-.4d6% d% 1d%+hih", -6610, 3612.8587341744883, 778265, 12177, -10025.64689728834, -48355, 12516.29534578816, 1471, -9567, 601152, -18755, -6539.962526393759, -221692, -23782, -971883, 636231, -973991, 12467),
sprintf(boba496, "% 3.8hi% 10.5f%-.5uv% .5hdx% .8fk%+d%+ff8% 6.10hd%-hd`f^%+i7% .8hdy%-2.6f%-.0d1@x%+hi8%-.4d6% d% 1d%+hih", -6610, 3612.8587341744883, 778265, 12177, -10025.64689728834, -48355, 12516.29534578816, 1471, -9567, 601152, -18755, -6539.962526393759, -221692, -23782, -971883, 636231, -973991, 12467));
ck_assert_str_eq(boba496_s21, boba496);
}
END_TEST

START_TEST(bebasik__497) {
char boba497_s21[10000];
char boba497[10000];
ck_assert_int_eq(s21_sprintf(boba497_s21, "%-5.1u-", 958582),
sprintf(boba497, "%-5.1u-", 958582));
ck_assert_str_eq(boba497_s21, boba497);
}
END_TEST

START_TEST(bebasik__498) {
char boba498_s21[10000];
char boba498[10000];
ck_assert_int_eq(s21_sprintf(boba498_s21, "% f&%-5ff% hd%+d% hd%-.8s%-.5d%-4.5s% .9hi%-.7hi2qw`u/%-8.9fj% 3i% hdh%+hd", -9539.03897534164, 7095.123073592671, 19593, 809789, -10241, "awq@f29kd^3r4ly*04/wul**jb@c", 790609, "#ignt8dlzk9mksu", -26102, 31966, 16459.161913702643, 624017, -30075, 5614),
sprintf(boba498, "% f&%-5ff% hd%+d% hd%-.8s%-.5d%-4.5s% .9hi%-.7hi2qw`u/%-8.9fj% 3i% hdh%+hd", -9539.03897534164, 7095.123073592671, 19593, 809789, -10241, "awq@f29kd^3r4ly*04/wul**jb@c", 790609, "#ignt8dlzk9mksu", -26102, 31966, 16459.161913702643, 624017, -30075, 5614));
ck_assert_str_eq(boba498_s21, boba498);
}
END_TEST

START_TEST(bebasik__499) {
char boba499_s21[10000];
char boba499[10000];
ck_assert_int_eq(s21_sprintf(boba499_s21, "% d4% 5hih% 5.2hi9q%-.7hi5%-hid%+i2% 9f% 7.3i$% 4.6hi,hlm0% .4hiu%-2.10hig%-hi%-hu%+1hi%+hi%-d%+6.2d", -217817, -24387, 3215, -16790, 18339, -335164, -571.8066897327794, 902946, 6486, -5395, 31010, -30220, -25892, -3715, -24681, -999214, -524137),
sprintf(boba499, "% d4% 5hih% 5.2hi9q%-.7hi5%-hid%+i2% 9f% 7.3i$% 4.6hi,hlm0% .4hiu%-2.10hig%-hi%-hu%+1hi%+hi%-d%+6.2d", -217817, -24387, 3215, -16790, 18339, -335164, -571.8066897327794, 902946, 6486, -5395, 31010, -30220, -25892, -3715, -24681, -999214, -524137));
ck_assert_str_eq(boba499_s21, boba499);
}
END_TEST

START_TEST(bebasik__500) {
char boba500_s21[10000];
char boba500[10000];
ck_assert_int_eq(s21_sprintf(boba500_s21, "%+10f%-.4hu%+.9hd%+7hi% 6i!%-u%+.0f8%+.2hd%+8.5d% fb2%+10hd%-f%-hu% 7.4i3&v8% 1.8d% 5.9hd3%-10.9i%+6.2hia%+3.7d% 5.4d", -12531.52759574055, -15134, -24807, -10274, -621191, -362369, 1247.6976373080147, 4599, 540759, -5184.978376504037, -14397, 18741.510238369574, 7350, -87630, -498066, -3454, 693166, 16913, 832679, 676734),
sprintf(boba500, "%+10f%-.4hu%+.9hd%+7hi% 6i!%-u%+.0f8%+.2hd%+8.5d% fb2%+10hd%-f%-hu% 7.4i3&v8% 1.8d% 5.9hd3%-10.9i%+6.2hia%+3.7d% 5.4d", -12531.52759574055, -15134, -24807, -10274, -621191, -362369, 1247.6976373080147, 4599, 540759, -5184.978376504037, -14397, 18741.510238369574, 7350, -87630, -498066, -3454, 693166, 16913, 832679, 676734));
ck_assert_str_eq(boba500_s21, boba500);
}
END_TEST

START_TEST(bebasik__501) {
char boba501_s21[10000];
char boba501[10000];
ck_assert_int_eq(s21_sprintf(boba501_s21, "%-1u% 1hi%-7.9fs#%+f% 1.7hd% 9.3i% 2.0hd%-6.10i#%-huhq", -663677, -3878, -8055.9375031718, -6025.004167798533, -13881, 227894, 21560, 325326, 25448),
sprintf(boba501, "%-1u% 1hi%-7.9fs#%+f% 1.7hd% 9.3i% 2.0hd%-6.10i#%-huhq", -663677, -3878, -8055.9375031718, -6025.004167798533, -13881, 227894, 21560, 325326, 25448));
ck_assert_str_eq(boba501_s21, boba501);
}
END_TEST

START_TEST(bebasik__502) {
char boba502_s21[10000];
char boba502[10000];
ck_assert_int_eq(s21_sprintf(boba502_s21, "%+.6i)%-5drh%+9f;", -261316, 276508, 3363.856005465202),
sprintf(boba502, "%+.6i)%-5drh%+9f;", -261316, 276508, 3363.856005465202));
ck_assert_str_eq(boba502_s21, boba502);
}
END_TEST

START_TEST(bebasik__503) {
char boba503_s21[10000];
char boba503[10000];
ck_assert_int_eq(s21_sprintf(boba503_s21, "% hdx%+7.1f", -27842, 209.3709565640223),
sprintf(boba503, "% hdx%+7.1f", -27842, 209.3709565640223));
ck_assert_str_eq(boba503_s21, boba503);
}
END_TEST

START_TEST(bebasik__504) {
char boba504_s21[10000];
char boba504[10000];
ck_assert_int_eq(s21_sprintf(boba504_s21, "%+.0d%-1.5s%+.5hd%+3.4hi%+8hd% 1hi#6%+5hi%-hul#ty% fc&@j&% f2x,x% 2.1d% 6dj%+6.4ik,%-hi%+1.8hi/i%-1f.h%-3c;%+5.1hda% .7hdiv.,%+2f% hd%-u% 6.4i%+1hi", -635071, "w7=^k65vavvsrg.t3`6wj!t!", 18803, 6697, -30530, -20782, -1519, 3880, -6222.420529504513, -3264.4198007356235, -146317, 379469, 576057, -12814, 5405, 3632.4264656683117, 'v', 13411, -30039, -3508.9935057558623, 3963, 844050, 638394, -3762),
sprintf(boba504, "%+.0d%-1.5s%+.5hd%+3.4hi%+8hd% 1hi#6%+5hi%-hul#ty% fc&@j&% f2x,x% 2.1d% 6dj%+6.4ik,%-hi%+1.8hi/i%-1f.h%-3c;%+5.1hda% .7hdiv.,%+2f% hd%-u% 6.4i%+1hi", -635071, "w7=^k65vavvsrg.t3`6wj!t!", 18803, 6697, -30530, -20782, -1519, 3880, -6222.420529504513, -3264.4198007356235, -146317, 379469, 576057, -12814, 5405, 3632.4264656683117, 'v', 13411, -30039, -3508.9935057558623, 3963, 844050, 638394, -3762));
ck_assert_str_eq(boba504_s21, boba504);
}
END_TEST

START_TEST(bebasik__505) {
char boba505_s21[10000];
char boba505[10000];
ck_assert_int_eq(s21_sprintf(boba505_s21, "%+1i%-.7d&%+.9hia%-hdrl%-s-ooz&% .2d#% 1.3i% 9.6i%+6.9dy%+3.7hdq", 772800, 910287, 29573, 7489, ",l$1hwo1rttbf(0e", 459941, -833714, 35661, 170390, 30139),
sprintf(boba505, "%+1i%-.7d&%+.9hia%-hdrl%-s-ooz&% .2d#% 1.3i% 9.6i%+6.9dy%+3.7hdq", 772800, 910287, 29573, 7489, ",l$1hwo1rttbf(0e", 459941, -833714, 35661, 170390, 30139));
ck_assert_str_eq(boba505_s21, boba505);
}
END_TEST

START_TEST(bebasik__506) {
char boba506_s21[10000];
char boba506[10000];
ck_assert_int_eq(s21_sprintf(boba506_s21, "%+7.6hi% 4.0f%+f% d% .10hd%+10d.%+f%+.8hi% 6hd%+.0hi%+dc%-.2hi#%+.3hd./%-.7hu7(5o%+.2d%-.6hd% .3hd%-3.9f% 2im*% 6hd", -1843, 1083.4514884932616, 21766.65201833819, 88259, 17396, 607790, 739.4473167466147, 31694, 24771, 1867, -60642, -31483, -19725, 28564, 755128, 6456, 23518, -19272.166397852754, 989056, 8232),
sprintf(boba506, "%+7.6hi% 4.0f%+f% d% .10hd%+10d.%+f%+.8hi% 6hd%+.0hi%+dc%-.2hi#%+.3hd./%-.7hu7(5o%+.2d%-.6hd% .3hd%-3.9f% 2im*% 6hd", -1843, 1083.4514884932616, 21766.65201833819, 88259, 17396, 607790, 739.4473167466147, 31694, 24771, 1867, -60642, -31483, -19725, 28564, 755128, 6456, 23518, -19272.166397852754, 989056, 8232));
ck_assert_str_eq(boba506_s21, boba506);
}
END_TEST

START_TEST(bebasik__507) {
char boba507_s21[10000];
char boba507[10000];
ck_assert_int_eq(s21_sprintf(boba507_s21, "%+.3hd1%-7.9s%-huq%-3hi8f%-i", -6241, "9vhe).$&vg1e6vrqby[2l", -30870, -4113, -465859),
sprintf(boba507, "%+.3hd1%-7.9s%-huq%-3hi8f%-i", -6241, "9vhe).$&vg1e6vrqby[2l", -30870, -4113, -465859));
ck_assert_str_eq(boba507_s21, boba507);
}
END_TEST

START_TEST(bebasik__508) {
char boba508_s21[10000];
char boba508[10000];
ck_assert_int_eq(s21_sprintf(boba508_s21, "%+.4i%+.5himl-% hd%-2.2ffy% .5hdv%-hd9% 8.2i% d%-2hd% 5.2i(%+9hi%+1f`h%+.9d% fs% hd%+hdn%-hi%+2hi3h%-sa`%-.8hd", -125464, -29189, -7733, -1981.116261439058, 28491, -10084, 113660, 695351, -16587, -332105, 601, -5014.235637239376, 708314, 4725.51876514579, -30112, -27711, 5591, -25654, "a8dq6e!vbiv*5h8v$!.^/m1(#", 13033),
sprintf(boba508, "%+.4i%+.5himl-% hd%-2.2ffy% .5hdv%-hd9% 8.2i% d%-2hd% 5.2i(%+9hi%+1f`h%+.9d% fs% hd%+hdn%-hi%+2hi3h%-sa`%-.8hd", -125464, -29189, -7733, -1981.116261439058, 28491, -10084, 113660, 695351, -16587, -332105, 601, -5014.235637239376, 708314, 4725.51876514579, -30112, -27711, 5591, -25654, "a8dq6e!vbiv*5h8v$!.^/m1(#", 13033));
ck_assert_str_eq(boba508_s21, boba508);
}
END_TEST

START_TEST(bebasik__509) {
char boba509_s21[10000];
char boba509[10000];
ck_assert_int_eq(s21_sprintf(boba509_s21, "%-u%-.4hik", -692092, -5627),
sprintf(boba509, "%-u%-.4hik", -692092, -5627));
ck_assert_str_eq(boba509_s21, boba509);
}
END_TEST

START_TEST(bebasik__510) {
char boba510_s21[10000];
char boba510[10000];
ck_assert_int_eq(s21_sprintf(boba510_s21, "%-4u%+.4hd% 9.8d%-9f% 2.2f%-.6hiu*% 5d% 5.6hd%-7hi.%+.5fks%-2.1hu2.%-8hu% 1.3fq% 10i", -471762, -3826, 337660, -4339.9768406920375, 569.5619277293298, -2175, 455844, 15774, -386, 4149.551133740539, 19034, 11334, -556.2986181964353, 690080),
sprintf(boba510, "%-4u%+.4hd% 9.8d%-9f% 2.2f%-.6hiu*% 5d% 5.6hd%-7hi.%+.5fks%-2.1hu2.%-8hu% 1.3fq% 10i", -471762, -3826, 337660, -4339.9768406920375, 569.5619277293298, -2175, 455844, 15774, -386, 4149.551133740539, 19034, 11334, -556.2986181964353, 690080));
ck_assert_str_eq(boba510_s21, boba510);
}
END_TEST

START_TEST(bebasik__511) {
char boba511_s21[10000];
char boba511[10000];
ck_assert_int_eq(s21_sprintf(boba511_s21, "%-c%+i[%+9d%-6.6hdz5.8%-us% .6i% 2d% 1.4hi%-9hi% 1d%+8d5% .5hig%+7i%-.3hi", 'j', -635901, -393396, 26002, 941167, -605180, 319256, 4080, -3889, -446339, 867841, -17814, -123102, -4102),
sprintf(boba511, "%-c%+i[%+9d%-6.6hdz5.8%-us% .6i% 2d% 1.4hi%-9hi% 1d%+8d5% .5hig%+7i%-.3hi", 'j', -635901, -393396, 26002, 941167, -605180, 319256, 4080, -3889, -446339, 867841, -17814, -123102, -4102));
ck_assert_str_eq(boba511_s21, boba511);
}
END_TEST

START_TEST(bebasik__512) {
char boba512_s21[10000];
char boba512[10000];
ck_assert_int_eq(s21_sprintf(boba512_s21, "% 8i(% 1.5hi", -715206, -14442),
sprintf(boba512, "% 8i(% 1.5hi", -715206, -14442));
ck_assert_str_eq(boba512_s21, boba512);
}
END_TEST

START_TEST(bebasik__513) {
char boba513_s21[10000];
char boba513[10000];
ck_assert_int_eq(s21_sprintf(boba513_s21, "%-.10d% dv%+5.8i%-u%+10f%-8.5hu% 5.10hd%-d#%+10hi*#%+9.5hd%+hi% 6hih% 5.6hilz", 236117, -258376, 303289, 620696, -2664.597405633541, -26332, -8633, -634135, 6343, 8374, -29502, -30986, 3734),
sprintf(boba513, "%-.10d% dv%+5.8i%-u%+10f%-8.5hu% 5.10hd%-d#%+10hi*#%+9.5hd%+hi% 6hih% 5.6hilz", 236117, -258376, 303289, 620696, -2664.597405633541, -26332, -8633, -634135, 6343, 8374, -29502, -30986, 3734));
ck_assert_str_eq(boba513_s21, boba513);
}
END_TEST

START_TEST(bebasik__514) {
char boba514_s21[10000];
char boba514[10000];
ck_assert_int_eq(s21_sprintf(boba514_s21, "% hd% .2dx1r%-4.0u%-5u/%-.7hi% 3hdh1d", -9553, 467996, -975433, -851709, -11673, -13934),
sprintf(boba514, "% hd% .2dx1r%-4.0u%-5u/%-.7hi% 3hdh1d", -9553, 467996, -975433, -851709, -11673, -13934));
ck_assert_str_eq(boba514_s21, boba514);
}
END_TEST

START_TEST(bebasik__515) {
char boba515_s21[10000];
char boba515[10000];
ck_assert_int_eq(s21_sprintf(boba515_s21, "%-.8hixtn% 2.3hi;%+4hd% d% hd%+f^% hd%-d% hdt1%+.6d;%+1d%+4hd%+fv4t6;%+d%-7.4i%-3.0huq1%-8.6hi% 9i$7%+4.5f% hi", 19510, -20961, -2479, -593734, 16265, -7510.453705557588, 6192, 565267, 25064, -693052, -464708, -3668, 23601.84533008663, 285754, -966167, 29374, 7473, -488035, 1700.9450484090423, 2834),
sprintf(boba515, "%-.8hixtn% 2.3hi;%+4hd% d% hd%+f^% hd%-d% hdt1%+.6d;%+1d%+4hd%+fv4t6;%+d%-7.4i%-3.0huq1%-8.6hi% 9i$7%+4.5f% hi", 19510, -20961, -2479, -593734, 16265, -7510.453705557588, 6192, 565267, 25064, -693052, -464708, -3668, 23601.84533008663, 285754, -966167, 29374, 7473, -488035, 1700.9450484090423, 2834));
ck_assert_str_eq(boba515_s21, boba515);
}
END_TEST

START_TEST(bebasik__516) {
char boba516_s21[10000];
char boba516[10000];
ck_assert_int_eq(s21_sprintf(boba516_s21, "%+ih% .3f%+2hd% 8.9dy$% 3.6hi% .1hd.% .6hdf%+1d5%-3hi% 4d% i@%+hd%-.5hi$%-6.4hd%+1f%-.4i%+5.4hi@", -860454, 4023.150834501948, -28374, -330340, -14980, -23968, -17404, 491287, 15660, -427667, -805783, 18083, -29606, -6996, -8552.11364438452, 147027, 13531),
sprintf(boba516, "%+ih% .3f%+2hd% 8.9dy$% 3.6hi% .1hd.% .6hdf%+1d5%-3hi% 4d% i@%+hd%-.5hi$%-6.4hd%+1f%-.4i%+5.4hi@", -860454, 4023.150834501948, -28374, -330340, -14980, -23968, -17404, 491287, 15660, -427667, -805783, 18083, -29606, -6996, -8552.11364438452, 147027, 13531));
ck_assert_str_eq(boba516_s21, boba516);
}
END_TEST

START_TEST(bebasik__517) {
char boba517_s21[10000];
char boba517[10000];
ck_assert_int_eq(s21_sprintf(boba517_s21, "%-.10hik%-hdu%-1ccs%+hiu%-3f% .2f%+.0d% 5.9hd%-7hub% 2fl", -25990, 11349, '7', 10515, 3654.9757377531937, -14675.753366819092, 883098, 30634, 30209, 8406.318970974055),
sprintf(boba517, "%-.10hik%-hdu%-1ccs%+hiu%-3f% .2f%+.0d% 5.9hd%-7hub% 2fl", -25990, 11349, '7', 10515, 3654.9757377531937, -14675.753366819092, 883098, 30634, 30209, 8406.318970974055));
ck_assert_str_eq(boba517_s21, boba517);
}
END_TEST

START_TEST(bebasik__518) {
char boba518_s21[10000];
char boba518[10000];
ck_assert_int_eq(s21_sprintf(boba518_s21, "% hd% 5.3hi% .4hdc8%+.4f91x@% .9il% fys%+6fx%+9hi(%-d% 5f%+3.7hi6bq%+2f.!% .8hd", 30205, 1374, 29630, 6994.131578914184, 552509, -2078.7402040112934, -2018.355757314967, 7690, -724221, -154.87635298053672, -22852, 450.9617172607989, -8105),
sprintf(boba518, "% hd% 5.3hi% .4hdc8%+.4f91x@% .9il% fys%+6fx%+9hi(%-d% 5f%+3.7hi6bq%+2f.!% .8hd", 30205, 1374, 29630, 6994.131578914184, 552509, -2078.7402040112934, -2018.355757314967, 7690, -724221, -154.87635298053672, -22852, 450.9617172607989, -8105));
ck_assert_str_eq(boba518_s21, boba518);
}
END_TEST

START_TEST(bebasik__519) {
char boba519_s21[10000];
char boba519[10000];
ck_assert_int_eq(s21_sprintf(boba519_s21, "%-.1u,t5%-5u%+10hi[%-.7fr% 2.5hivv%-s%-1hi%-.0hi3%-10.2hi", -224965, -865842, -15879, -21672.194609056172, -7777, "p,0e;bkx^3u.jx3/e8", 16641, 23648, 21386),
sprintf(boba519, "%-.1u,t5%-5u%+10hi[%-.7fr% 2.5hivv%-s%-1hi%-.0hi3%-10.2hi", -224965, -865842, -15879, -21672.194609056172, -7777, "p,0e;bkx^3u.jx3/e8", 16641, 23648, 21386));
ck_assert_str_eq(boba519_s21, boba519);
}
END_TEST

START_TEST(bebasik__520) {
char boba520_s21[10000];
char boba520[10000];
ck_assert_int_eq(s21_sprintf(boba520_s21, "%+.4hi9y", 1581),
sprintf(boba520, "%+.4hi9y", 1581));
ck_assert_str_eq(boba520_s21, boba520);
}
END_TEST

START_TEST(bebasik__521) {
char boba521_s21[10000];
char boba521[10000];
ck_assert_int_eq(s21_sprintf(boba521_s21, "%+7f$%+hd/&% 3.1iie;%-6hip(%+hi=%+.4i% 10hia`% .8hd%+d%-1.3hd%-5.8u.s% .9hi7%-.4fu% 8fw", 9227.604891473062, 13244, -365824, -24667, -10753, -94765, -15370, 13560, -836165, -1669, 74152, -25244, -14777.345293506389, -24852.30437788336),
sprintf(boba521, "%+7f$%+hd/&% 3.1iie;%-6hip(%+hi=%+.4i% 10hia`% .8hd%+d%-1.3hd%-5.8u.s% .9hi7%-.4fu% 8fw", 9227.604891473062, 13244, -365824, -24667, -10753, -94765, -15370, 13560, -836165, -1669, 74152, -25244, -14777.345293506389, -24852.30437788336));
ck_assert_str_eq(boba521_s21, boba521);
}
END_TEST

START_TEST(bebasik__522) {
char boba522_s21[10000];
char boba522[10000];
ck_assert_int_eq(s21_sprintf(boba522_s21, "%+6.3f% .1hi0osy)%-9.1hd%-10.1hu.u%-.1hi%+9hd;% 8i53j/*%-6.9i&;%-.6i%+1i=8", 1391.5591521072574, -2994, 18370, -13945, 25522, 13176, -104229, -213151, -220938, -851458),
sprintf(boba522, "%+6.3f% .1hi0osy)%-9.1hd%-10.1hu.u%-.1hi%+9hd;% 8i53j/*%-6.9i&;%-.6i%+1i=8", 1391.5591521072574, -2994, 18370, -13945, 25522, 13176, -104229, -213151, -220938, -851458));
ck_assert_str_eq(boba522_s21, boba522);
}
END_TEST

START_TEST(bebasik__523) {
char boba523_s21[10000];
char boba523[10000];
ck_assert_int_eq(s21_sprintf(boba523_s21, "% 1.6hd%+10fg%+6hd%+6f9&%+6.0hd% .0f%+1.7hdem% 1.4hd8", -18604, 5260.474134049154, -11654, 1402.3150592449547, 19826, -15194.09547027839, 10190, 15210),
sprintf(boba523, "% 1.6hd%+10fg%+6hd%+6f9&%+6.0hd% .0f%+1.7hdem% 1.4hd8", -18604, 5260.474134049154, -11654, 1402.3150592449547, 19826, -15194.09547027839, 10190, 15210));
ck_assert_str_eq(boba523_s21, boba523);
}
END_TEST

START_TEST(bebasik__524) {
char boba524_s21[10000];
char boba524[10000];
ck_assert_int_eq(s21_sprintf(boba524_s21, "% 9hd% 1.5i3%-s% 1hdf%+hdd% d%-7.7dh%+hi%+1hd%+3.7hd%-.4hd%-8i%-.4d%+1.5hi%+5i%-4.4hd% 4.3hi*% 2f%-5hd% .6i", 2041, -620491, "y5[/vrz;p3@d$h,1)@", 1831, 5237, 751619, -424794, -14422, 6576, -26029, -19154, 604169, 609217, 7775, 951304, 1757, -31336, -15973.092075297705, 8711, -261880),
sprintf(boba524, "% 9hd% 1.5i3%-s% 1hdf%+hdd% d%-7.7dh%+hi%+1hd%+3.7hd%-.4hd%-8i%-.4d%+1.5hi%+5i%-4.4hd% 4.3hi*% 2f%-5hd% .6i", 2041, -620491, "y5[/vrz;p3@d$h,1)@", 1831, 5237, 751619, -424794, -14422, 6576, -26029, -19154, 604169, 609217, 7775, 951304, 1757, -31336, -15973.092075297705, 8711, -261880));
ck_assert_str_eq(boba524_s21, boba524);
}
END_TEST

START_TEST(bebasik__525) {
char boba525_s21[10000];
char boba525[10000];
ck_assert_int_eq(s21_sprintf(boba525_s21, "%-7.4s!)% 4.6hi)", "(.nlx8ok-0`xfh1y*r^)(9^", 3913),
sprintf(boba525, "%-7.4s!)% 4.6hi)", "(.nlx8ok-0`xfh1y*r^)(9^", 3913));
ck_assert_str_eq(boba525_s21, boba525);
}
END_TEST

START_TEST(bebasik__526) {
char boba526_s21[10000];
char boba526[10000];
ck_assert_int_eq(s21_sprintf(boba526_s21, "%+8.4fb[%+4d9% 3.3is%-7.1hdj%-hu", 13094.769699898086, 841044, -625746, -19639, -30893),
sprintf(boba526, "%+8.4fb[%+4d9% 3.3is%-7.1hdj%-hu", 13094.769699898086, 841044, -625746, -19639, -30893));
ck_assert_str_eq(boba526_s21, boba526);
}
END_TEST

START_TEST(bebasik__527) {
char boba527_s21[10000];
char boba527[10000];
ck_assert_int_eq(s21_sprintf(boba527_s21, "%+d`6%-.2f%-2.0hd9s%+8.9hi% .8hd%-5.4ub% 4hd,^%-8hib% .3fd@%+4.1i%+.5hik%-2d%-.9hu6#0/% 3f/%-u% .0d%-1.5i4%+dt", -486898, -5232.494687916856, 16940, -11272, -1268, 69184, -25441, -16327, -1365.934984527714, 636736, -15340, 803515, 19908, -3292.7363841928272, -745563, -89609, -454746, -968719),
sprintf(boba527, "%+d`6%-.2f%-2.0hd9s%+8.9hi% .8hd%-5.4ub% 4hd,^%-8hib% .3fd@%+4.1i%+.5hik%-2d%-.9hu6#0/% 3f/%-u% .0d%-1.5i4%+dt", -486898, -5232.494687916856, 16940, -11272, -1268, 69184, -25441, -16327, -1365.934984527714, 636736, -15340, 803515, 19908, -3292.7363841928272, -745563, -89609, -454746, -968719));
ck_assert_str_eq(boba527_s21, boba527);
}
END_TEST

START_TEST(bebasik__528) {
char boba528_s21[10000];
char boba528[10000];
ck_assert_int_eq(s21_sprintf(boba528_s21, "% 8f1%-hd=% 10hd4*0%-.10hi% 7d% .10f%-2.7d%+.7i)(.p% hi%+hi", 12825.709852058646, 20551, -11221, 20968, -679432, 14870.508791625125, -612565, 249641, -781, 1385),
sprintf(boba528, "% 8f1%-hd=% 10hd4*0%-.10hi% 7d% .10f%-2.7d%+.7i)(.p% hi%+hi", 12825.709852058646, 20551, -11221, 20968, -679432, 14870.508791625125, -612565, 249641, -781, 1385));
ck_assert_str_eq(boba528_s21, boba528);
}
END_TEST

START_TEST(bebasik__529) {
char boba529_s21[10000];
char boba529[10000];
ck_assert_int_eq(s21_sprintf(boba529_s21, "%+.9f%-1hiil#;q% .4hi,%-3hi%-5c%-1.3u% hi%-4sn(g%+5.0hd;fzcm%-4.3u;%+.0f8v", -665.9661272067423, 17175, 2625, 22831, '`', 765836, -24275, "6`", 18763, 454324, -17704.748592450833),
sprintf(boba529, "%+.9f%-1hiil#;q% .4hi,%-3hi%-5c%-1.3u% hi%-4sn(g%+5.0hd;fzcm%-4.3u;%+.0f8v", -665.9661272067423, 17175, 2625, 22831, '`', 765836, -24275, "6`", 18763, 454324, -17704.748592450833));
ck_assert_str_eq(boba529_s21, boba529);
}
END_TEST

START_TEST(bebasik__530) {
char boba530_s21[10000];
char boba530[10000];
ck_assert_int_eq(s21_sprintf(boba530_s21, "%+.2hd(%+6.9hihe%+f@lh% 9.6fb%+.2f/% .4fr,[%-10.5him%+.5f/% .7i)@gg% .4f%+4d%+3.6hd% 1.3hifd1$6fe% 6hd!#%-7cz;xx% 8hd%-4.10s% 10hd7^=% hi", 11928, 2247, 2700.464344760354, -1825.6725828242152, -2869.9076266174925, -1269.360121623511, -24189, -15600.465888267494, 968242, -10583.679754237713, 966135, -13319, -21610, 12193, '=', -15194, "bd2n6q!7xtqc!jy7vw", -1164, -31171),
sprintf(boba530, "%+.2hd(%+6.9hihe%+f@lh% 9.6fb%+.2f/% .4fr,[%-10.5him%+.5f/% .7i)@gg% .4f%+4d%+3.6hd% 1.3hifd1$6fe% 6hd!#%-7cz;xx% 8hd%-4.10s% 10hd7^=% hi", 11928, 2247, 2700.464344760354, -1825.6725828242152, -2869.9076266174925, -1269.360121623511, -24189, -15600.465888267494, 968242, -10583.679754237713, 966135, -13319, -21610, 12193, '=', -15194, "bd2n6q!7xtqc!jy7vw", -1164, -31171));
ck_assert_str_eq(boba530_s21, boba530);
}
END_TEST

START_TEST(bebasik__531) {
char boba531_s21[10000];
char boba531[10000];
ck_assert_int_eq(s21_sprintf(boba531_s21, "% 7.10fx", -1628.3898990587172),
sprintf(boba531, "% 7.10fx", -1628.3898990587172));
ck_assert_str_eq(boba531_s21, boba531);
}
END_TEST

START_TEST(bebasik__532) {
char boba532_s21[10000];
char boba532[10000];
ck_assert_int_eq(s21_sprintf(boba532_s21, "%-.2hd%-fe-%+.8d%-.6i%-9f^%+10hi3&d9cfts4s% .8hix%-f% 6.2hde=-r6%+7hd%+.0f%-his% 10dq% 3hdb%+4.6hd5;% .8f% d% 10.7hdg%-hu%+1d@% hi8", 21073, 5821.129295094522, -634538, -338453, 1571.3568915090236, 31668, -12835, 2215.4429043640785, -4886, -2150, 1224.3541434550807, -21882, 28513, -27562, -4397, -1688.0102656053875, -259798, 18186, 14752, -185253, -22980),
sprintf(boba532, "%-.2hd%-fe-%+.8d%-.6i%-9f^%+10hi3&d9cfts4s% .8hix%-f% 6.2hde=-r6%+7hd%+.0f%-his% 10dq% 3hdb%+4.6hd5;% .8f% d% 10.7hdg%-hu%+1d@% hi8", 21073, 5821.129295094522, -634538, -338453, 1571.3568915090236, 31668, -12835, 2215.4429043640785, -4886, -2150, 1224.3541434550807, -21882, 28513, -27562, -4397, -1688.0102656053875, -259798, 18186, 14752, -185253, -22980));
ck_assert_str_eq(boba532_s21, boba532);
}
END_TEST

START_TEST(bebasik__533) {
char boba533_s21[10000];
char boba533[10000];
ck_assert_int_eq(s21_sprintf(boba533_s21, "%+9.4ik%+f%-hd#% 7hi0k% .6dt!mm%-10c^q%+.5hi=e%-4hic% 10.6hd9)ef%+10.3hi1%-huuo%-8.10hd% 6hi%-10.7u%-2.9hu%+5.9hd%+1.9dvm%-s", -813906, -5740.2801009638015, 5308, 22438, 335620, 'o', -27027, 11276, 14543, 1344, -19402, -16651, -15483, 511131, -2595, 7677, -601718, "n)*;-q*bycqf5ka"),
sprintf(boba533, "%+9.4ik%+f%-hd#% 7hi0k% .6dt!mm%-10c^q%+.5hi=e%-4hic% 10.6hd9)ef%+10.3hi1%-huuo%-8.10hd% 6hi%-10.7u%-2.9hu%+5.9hd%+1.9dvm%-s", -813906, -5740.2801009638015, 5308, 22438, 335620, 'o', -27027, 11276, 14543, 1344, -19402, -16651, -15483, 511131, -2595, 7677, -601718, "n)*;-q*bycqf5ka"));
ck_assert_str_eq(boba533_s21, boba533);
}
END_TEST

START_TEST(bebasik__534) {
char boba534_s21[10000];
char boba534[10000];
ck_assert_int_eq(s21_sprintf(boba534_s21, "%-u% .7hdt3#", 931623, 11353),
sprintf(boba534, "%-u% .7hdt3#", 931623, 11353));
ck_assert_str_eq(boba534_s21, boba534);
}
END_TEST

START_TEST(bebasik__535) {
char boba535_s21[10000];
char boba535[10000];
ck_assert_int_eq(s21_sprintf(boba535_s21, "%+d% .1hd=t%+1f%+9.6d% ds%+him6%+.6hikfh%+iu", -707550, 17564, -12133.569901067107, -241113, 966350, -4264, 20576, 719974),
sprintf(boba535, "%+d% .1hd=t%+1f%+9.6d% ds%+him6%+.6hikfh%+iu", -707550, 17564, -12133.569901067107, -241113, 966350, -4264, 20576, 719974));
ck_assert_str_eq(boba535_s21, boba535);
}
END_TEST

START_TEST(bebasik__536) {
char boba536_s21[10000];
char boba536[10000];
ck_assert_int_eq(s21_sprintf(boba536_s21, "%+8hi%-.9hu9% 10di%-10.2s%-5.1fm2^%+6hisns%+7.6hi%-f2^% i", -15785, -16690, -913125, "&vtrml&[u=k$", -27049.958590307528, -26169, 6767, 12026.162630371215, -491294),
sprintf(boba536, "%+8hi%-.9hu9% 10di%-10.2s%-5.1fm2^%+6hisns%+7.6hi%-f2^% i", -15785, -16690, -913125, "&vtrml&[u=k$", -27049.958590307528, -26169, 6767, 12026.162630371215, -491294));
ck_assert_str_eq(boba536_s21, boba536);
}
END_TEST

START_TEST(bebasik__537) {
char boba537_s21[10000];
char boba537[10000];
ck_assert_int_eq(s21_sprintf(boba537_s21, "%+.6hd6w=% 8.7dp% hi% 2.3i%+2.2d(=d8%-u% 5hd%+hi=rh,#%+6hi%-df%-6.8fkavs", -15528, -794068, 13978, -219935, 111986, -924851, -14935, -25669, 26343, -239783, -18041.94039365051),
sprintf(boba537, "%+.6hd6w=% 8.7dp% hi% 2.3i%+2.2d(=d8%-u% 5hd%+hi=rh,#%+6hi%-df%-6.8fkavs", -15528, -794068, 13978, -219935, 111986, -924851, -14935, -25669, 26343, -239783, -18041.94039365051));
ck_assert_str_eq(boba537_s21, boba537);
}
END_TEST

START_TEST(bebasik__538) {
char boba538_s21[10000];
char boba538[10000];
ck_assert_int_eq(s21_sprintf(boba538_s21, "% 5.6i%-2.6hd% 3.8hd%+.9hd%-.5hif% 5dm%+2d%-6.0hu%-.0d%+3.9hi%-.9i% .8i%+.1d5%+3.9i% .5hi,9aj% .3f1o% 3.4hdb(%-.10f%+10.3hdm241%+.6fh%-9ij% 4.3hd", -70398, -24115, -8300, -20914, 3538, 394540, -899361, 25073, -80307, 8301, 466294, 495139, -806331, -801958, -7349, -3205.0050523194172, 8366, 12581.266969779876, -30151, 4053.3653361330566, 931025, 24640),
sprintf(boba538, "% 5.6i%-2.6hd% 3.8hd%+.9hd%-.5hif% 5dm%+2d%-6.0hu%-.0d%+3.9hi%-.9i% .8i%+.1d5%+3.9i% .5hi,9aj% .3f1o% 3.4hdb(%-.10f%+10.3hdm241%+.6fh%-9ij% 4.3hd", -70398, -24115, -8300, -20914, 3538, 394540, -899361, 25073, -80307, 8301, 466294, 495139, -806331, -801958, -7349, -3205.0050523194172, 8366, 12581.266969779876, -30151, 4053.3653361330566, 931025, 24640));
ck_assert_str_eq(boba538_s21, boba538);
}
END_TEST

START_TEST(bebasik__539) {
char boba539_s21[10000];
char boba539[10000];
ck_assert_int_eq(s21_sprintf(boba539_s21, "%-7.5d%+8.2i% f@% 6.9f%-c%+hd%-9hi% 9hd% 7.2hi#r;e%+f% .0i%-8.3hu% 4fy", -695655, 918544, -16979.1529196204, 14954.052214299785, '-', -9198, -16417, 17195, 19118, 6056.1810662327025, 596666, -278, 491.63539854688577),
sprintf(boba539, "%-7.5d%+8.2i% f@% 6.9f%-c%+hd%-9hi% 9hd% 7.2hi#r;e%+f% .0i%-8.3hu% 4fy", -695655, 918544, -16979.1529196204, 14954.052214299785, '-', -9198, -16417, 17195, 19118, 6056.1810662327025, 596666, -278, 491.63539854688577));
ck_assert_str_eq(boba539_s21, boba539);
}
END_TEST

START_TEST(bebasik__540) {
char boba540_s21[10000];
char boba540[10000];
ck_assert_int_eq(s21_sprintf(boba540_s21, "%-7c)% .7i%-10c", 'n', 435828, '3'),
sprintf(boba540, "%-7c)% .7i%-10c", 'n', 435828, '3'));
ck_assert_str_eq(boba540_s21, boba540);
}
END_TEST

START_TEST(bebasik__541) {
char boba541_s21[10000];
char boba541[10000];
ck_assert_int_eq(s21_sprintf(boba541_s21, "% 9.10hi8%+d% f%+f% 8hd%+.8f%-u%-3d7%-6.4di5[", -27492, 97270, -7832.152733088724, -2194.5652167205585, 23505, 1624.4708570957123, -479086, -970974, -674592),
sprintf(boba541, "% 9.10hi8%+d% f%+f% 8hd%+.8f%-u%-3d7%-6.4di5[", -27492, 97270, -7832.152733088724, -2194.5652167205585, 23505, 1624.4708570957123, -479086, -970974, -674592));
ck_assert_str_eq(boba541_s21, boba541);
}
END_TEST

START_TEST(bebasik__542) {
char boba542_s21[10000];
char boba542[10000];
ck_assert_int_eq(s21_sprintf(boba542_s21, "% fjir=3% 9.2f%-8.1hd3% 1hiz% 8.1hionv%+6.2hijz%-4.2hd% 10.10d% 5.8it%+3hd%-7.4hi%-2f^%-u%+3f3g`[%-1.0d%-.8d2", 18817.225999075974, -6719.433791150733, -14269, -6487, 24593, 30837, 12814, -659011, 236169, -20528, 16798, 12021.931892832561, 52302, -5178.361470890644, 823226, -91110),
sprintf(boba542, "% fjir=3% 9.2f%-8.1hd3% 1hiz% 8.1hionv%+6.2hijz%-4.2hd% 10.10d% 5.8it%+3hd%-7.4hi%-2f^%-u%+3f3g`[%-1.0d%-.8d2", 18817.225999075974, -6719.433791150733, -14269, -6487, 24593, 30837, 12814, -659011, 236169, -20528, 16798, 12021.931892832561, 52302, -5178.361470890644, 823226, -91110));
ck_assert_str_eq(boba542_s21, boba542);
}
END_TEST

START_TEST(bebasik__543) {
char boba543_s21[10000];
char boba543[10000];
ck_assert_int_eq(s21_sprintf(boba543_s21, "%-2.10hu@%+10if-tft% hd", 18183, 948004, -21205),
sprintf(boba543, "%-2.10hu@%+10if-tft% hd", 18183, 948004, -21205));
ck_assert_str_eq(boba543_s21, boba543);
}
END_TEST

START_TEST(bebasik__544) {
char boba544_s21[10000];
char boba544[10000];
ck_assert_int_eq(s21_sprintf(boba544_s21, "% 8.6f%+.2d%+4.5dz4%+6hi[b%+4f%-hi9*% .9fgiq%+.4dp%+10.5dge%-.1d%+9.4hd%-9f%+f% 7d7z% .6hd% .8hd%-hi%-huc%-4.9f%-8.4hd%-3.0dv%+7.5hio&u6%+fx", 2.992950836925597, 809371, 75175, 22072, 14598.875371790651, -12381, 14277.966974225392, -910128, 965793, -661413, -10809, -5342.155227482679, -5167.554158032625, 619868, -29591, -31106, 20098, -9461, -5116.396754037617, 10784, 557300, -27497, -17375.776632821126),
sprintf(boba544, "% 8.6f%+.2d%+4.5dz4%+6hi[b%+4f%-hi9*% .9fgiq%+.4dp%+10.5dge%-.1d%+9.4hd%-9f%+f% 7d7z% .6hd% .8hd%-hi%-huc%-4.9f%-8.4hd%-3.0dv%+7.5hio&u6%+fx", 2.992950836925597, 809371, 75175, 22072, 14598.875371790651, -12381, 14277.966974225392, -910128, 965793, -661413, -10809, -5342.155227482679, -5167.554158032625, 619868, -29591, -31106, 20098, -9461, -5116.396754037617, 10784, 557300, -27497, -17375.776632821126));
ck_assert_str_eq(boba544_s21, boba544);
}
END_TEST

START_TEST(bebasik__545) {
char boba545_s21[10000];
char boba545[10000];
ck_assert_int_eq(s21_sprintf(boba545_s21, "%+.10hdi%-s% hi% 9hdcsi%-3huy%-5.6ic;pp%+9hi%+hd(f%+hi,`% 10.0hi%-9di8%+6i% .3ih% hd%+.7fb[$%-f", -14536, "tsujxtk/7$=&m!pc", -17823, 23316, -30513, 918200, 17970, 6383, 3461, 28421, 296053, -570234, 859382, 28074, -802.7857748982433, 2217.365693246824),
sprintf(boba545, "%+.10hdi%-s% hi% 9hdcsi%-3huy%-5.6ic;pp%+9hi%+hd(f%+hi,`% 10.0hi%-9di8%+6i% .3ih% hd%+.7fb[$%-f", -14536, "tsujxtk/7$=&m!pc", -17823, 23316, -30513, 918200, 17970, 6383, 3461, 28421, 296053, -570234, 859382, 28074, -802.7857748982433, 2217.365693246824));
ck_assert_str_eq(boba545_s21, boba545);
}
END_TEST

START_TEST(bebasik__546) {
char boba546_s21[10000];
char boba546[10000];
ck_assert_int_eq(s21_sprintf(boba546_s21, "% .10hic(%-.4hu%-3uf.p8j% .0hdb$%-8.9i% 8hibd% 8i%+6.0hi%+7.0hil%+hd%+5f%-5.1s6%+.1hi==j0%-.5hd%+3.8hi%-5hum!&.%+hi%+10hiz8&%+hd% 9hd,%+4hi%+5.8hd.op", 12195, -30299, -570390, -8364, 737789, -15325, -321591, -240, 27173, -19445, 167.55834555811012, "81!dgp@cgt3m2g-0$^-4s.o1;l", 5535, 9970, 9270, -13392, -17938, -25804, -19497, 12151, -2297, -28935),
sprintf(boba546, "% .10hic(%-.4hu%-3uf.p8j% .0hdb$%-8.9i% 8hibd% 8i%+6.0hi%+7.0hil%+hd%+5f%-5.1s6%+.1hi==j0%-.5hd%+3.8hi%-5hum!&.%+hi%+10hiz8&%+hd% 9hd,%+4hi%+5.8hd.op", 12195, -30299, -570390, -8364, 737789, -15325, -321591, -240, 27173, -19445, 167.55834555811012, "81!dgp@cgt3m2g-0$^-4s.o1;l", 5535, 9970, 9270, -13392, -17938, -25804, -19497, 12151, -2297, -28935));
ck_assert_str_eq(boba546_s21, boba546);
}
END_TEST

START_TEST(bebasik__547) {
char boba547_s21[10000];
char boba547[10000];
ck_assert_int_eq(s21_sprintf(boba547_s21, "% d%+10hd% 10f@[a%+.5hd)7(%-2.2d%+hdi-@*n%+9.10f%-.2hd%-d@%-.6f% .6f4%-10f;%+.10hi", -150085, 10642, -10390.523123735367, 4291, -266508, -9897, 8987.91977707205, -22029, -164460, 23958.63075236312, -17638.747817339194, -3878.0775162337222, -17428),
sprintf(boba547, "% d%+10hd% 10f@[a%+.5hd)7(%-2.2d%+hdi-@*n%+9.10f%-.2hd%-d@%-.6f% .6f4%-10f;%+.10hi", -150085, 10642, -10390.523123735367, 4291, -266508, -9897, 8987.91977707205, -22029, -164460, 23958.63075236312, -17638.747817339194, -3878.0775162337222, -17428));
ck_assert_str_eq(boba547_s21, boba547);
}
END_TEST

START_TEST(bebasik__548) {
char boba548_s21[10000];
char boba548[10000];
ck_assert_int_eq(s21_sprintf(boba548_s21, "%+.8dj5%-hu%-6hdq%-6.5u)8[`x%+hi%+2iy%-4.1s% .1d%+2d%+hi$% .4d% hi1&`% .6ds%+10d%-7.7fc% f8%+4hi9%-.1hu2g%-8hd@%+.6f-p84%+4.1d5tu% .3f", 644010, -1201, -21939, -142757, 4491, -108368, "!rx6u0/)g/lr[l,/=jnfqx&pcdti", 753687, 461090, -13240, -588300, 30868, 17807, 771509, 5992.684949655713, 5507.119913178182, 3274, 13817, -24299, -1553.5221499839745, -812305, -18901.059918039442),
sprintf(boba548, "%+.8dj5%-hu%-6hdq%-6.5u)8[`x%+hi%+2iy%-4.1s% .1d%+2d%+hi$% .4d% hi1&`% .6ds%+10d%-7.7fc% f8%+4hi9%-.1hu2g%-8hd@%+.6f-p84%+4.1d5tu% .3f", 644010, -1201, -21939, -142757, 4491, -108368, "!rx6u0/)g/lr[l,/=jnfqx&pcdti", 753687, 461090, -13240, -588300, 30868, 17807, 771509, 5992.684949655713, 5507.119913178182, 3274, 13817, -24299, -1553.5221499839745, -812305, -18901.059918039442));
ck_assert_str_eq(boba548_s21, boba548);
}
END_TEST

START_TEST(bebasik__549) {
char boba549_s21[10000];
char boba549[10000];
ck_assert_int_eq(s21_sprintf(boba549_s21, "%+6.6hi!", -4636),
sprintf(boba549, "%+6.6hi!", -4636));
ck_assert_str_eq(boba549_s21, boba549);
}
END_TEST

START_TEST(bebasik__550) {
char boba550_s21[10000];
char boba550[10000];
ck_assert_int_eq(s21_sprintf(boba550_s21, "%+.9hd% hd%-.0fq%+.4hi", 23193, -14654, 2555.3927952768713, 13324),
sprintf(boba550, "%+.9hd% hd%-.0fq%+.4hi", 23193, -14654, 2555.3927952768713, 13324));
ck_assert_str_eq(boba550_s21, boba550);
}
END_TEST

START_TEST(bebasik__551) {
char boba551_s21[10000];
char boba551[10000];
ck_assert_int_eq(s21_sprintf(boba551_s21, "%+4.5hi", -825),
sprintf(boba551, "%+4.5hi", -825));
ck_assert_str_eq(boba551_s21, boba551);
}
END_TEST

START_TEST(bebasik__552) {
char boba552_s21[10000];
char boba552[10000];
ck_assert_int_eq(s21_sprintf(boba552_s21, "%-f%-10.9f6%+8hi% 4f% .9hi%+.8dtdg% hi%+i%-.10hdh``g^% .6f% .6d;%-1c.,oh%+2.5f&w%+9hd%+hi0x%-6.6hd=4f%-.2hdu", -1480.8404834988683, -3621.3891249632898, -28435, 14480.554287859755, -12388, 453595, 9683, 633243, 30427, 3017.227933469179, 588454, 's', -111.10601273241265, -2804, 3743, 25554, -29095),
sprintf(boba552, "%-f%-10.9f6%+8hi% 4f% .9hi%+.8dtdg% hi%+i%-.10hdh``g^% .6f% .6d;%-1c.,oh%+2.5f&w%+9hd%+hi0x%-6.6hd=4f%-.2hdu", -1480.8404834988683, -3621.3891249632898, -28435, 14480.554287859755, -12388, 453595, 9683, 633243, 30427, 3017.227933469179, 588454, 's', -111.10601273241265, -2804, 3743, 25554, -29095));
ck_assert_str_eq(boba552_s21, boba552);
}
END_TEST

START_TEST(bebasik__553) {
char boba553_s21[10000];
char boba553[10000];
ck_assert_int_eq(s21_sprintf(boba553_s21, "%-3hu%+d%+6.1hd%-c,%+3hdo%-.0f,%+5d^", -21792, 980617, -3690, '-', 3827, 16912.75135365086, -962102),
sprintf(boba553, "%-3hu%+d%+6.1hd%-c,%+3hdo%-.0f,%+5d^", -21792, 980617, -3690, '-', 3827, 16912.75135365086, -962102));
ck_assert_str_eq(boba553_s21, boba553);
}
END_TEST

START_TEST(bebasik__554) {
char boba554_s21[10000];
char boba554[10000];
ck_assert_int_eq(s21_sprintf(boba554_s21, "% hd% .5d[00%+.7d%-d%-3.7d9%+.4hdem%-.5hu17n%-.0d", 14583, -753554, -983711, -673394, 601010, 25351, 8180, -720079),
sprintf(boba554, "% hd% .5d[00%+.7d%-d%-3.7d9%+.4hdem%-.5hu17n%-.0d", 14583, -753554, -983711, -673394, 601010, 25351, 8180, -720079));
ck_assert_str_eq(boba554_s21, boba554);
}
END_TEST

START_TEST(bebasik__555) {
char boba555_s21[10000];
char boba555[10000];
ck_assert_int_eq(s21_sprintf(boba555_s21, "%+6.3i%-3d%+im0=%+.7hd%+.4i% 3hd% hd%-.9hu%+1.7d% .6id% .7hi/d%+hi2$b% .0hi% 6i[,/rdiqg^2% 2.4hdv% 10d$", -864179, -408262, -307801, -26592, -494678, 8706, -4063, -7771, 58707, -974049, 15077, 19090, -4048, -872362, 943, -717306),
sprintf(boba555, "%+6.3i%-3d%+im0=%+.7hd%+.4i% 3hd% hd%-.9hu%+1.7d% .6id% .7hi/d%+hi2$b% .0hi% 6i[,/rdiqg^2% 2.4hdv% 10d$", -864179, -408262, -307801, -26592, -494678, 8706, -4063, -7771, 58707, -974049, 15077, 19090, -4048, -872362, 943, -717306));
ck_assert_str_eq(boba555_s21, boba555);
}
END_TEST

START_TEST(bebasik__556) {
char boba556_s21[10000];
char boba556[10000];
ck_assert_int_eq(s21_sprintf(boba556_s21, "%-4c% .7f%+.2d%-1.1hi6%-10.6d%-1.2hdy^% 1.7hip%-fyro,;g% 8f%+.5f%-10utcc%-hi%+.1d%-.10hd%+1.4ibhok3%-.1hu%+2.0i%-.9hu6r%-6hu", 'c', 3730.180963855054, 288701, -1458, -391572, -2640, 19732, -3773.2914555110297, -502.29372124398776, -112.62348715023013, 92309, 29613, -412464, -17906, -806655, 2372, -706303, -19011, 31685),
sprintf(boba556, "%-4c% .7f%+.2d%-1.1hi6%-10.6d%-1.2hdy^% 1.7hip%-fyro,;g% 8f%+.5f%-10utcc%-hi%+.1d%-.10hd%+1.4ibhok3%-.1hu%+2.0i%-.9hu6r%-6hu", 'c', 3730.180963855054, 288701, -1458, -391572, -2640, 19732, -3773.2914555110297, -502.29372124398776, -112.62348715023013, 92309, 29613, -412464, -17906, -806655, 2372, -706303, -19011, 31685));
ck_assert_str_eq(boba556_s21, boba556);
}
END_TEST

START_TEST(bebasik__557) {
char boba557_s21[10000];
char boba557[10000];
ck_assert_int_eq(s21_sprintf(boba557_s21, "% 7.0d% d%+.10ic9% .7hi%-.0hu%+.5di*%+4.1f%+hip%-c%-3.4hu#p[h@vm", -740175, -907647, 989103, 6858, 9254, 727257, 1564.6642295367742, 18550, 'o', -23742),
sprintf(boba557, "% 7.0d% d%+.10ic9% .7hi%-.0hu%+.5di*%+4.1f%+hip%-c%-3.4hu#p[h@vm", -740175, -907647, 989103, 6858, 9254, 727257, 1564.6642295367742, 18550, 'o', -23742));
ck_assert_str_eq(boba557_s21, boba557);
}
END_TEST

START_TEST(bebasik__558) {
char boba558_s21[10000];
char boba558[10000];
ck_assert_int_eq(s21_sprintf(boba558_s21, "% 9.5i% i%-.6hu0%-7.8u%-1s% hiz% d%-.8hu%+.1i%-.9hu% .1f%-6.4hu%-.8d%+8.2hi%+10io#%+3.2d%+i%-.9hu%+i,% 9hd^fm%+3.4f*r%-4hi%-.7hi", -911340, 517263, -15416, 679651, "5(ohds#(", 5977, 609041, 435, -767981, 23925, -10368.772714999708, 27532, 502413, 12177, 348999, -230517, -172654, 29305, -701391, 18215, 20134.441068703112, 20252, -23102),
sprintf(boba558, "% 9.5i% i%-.6hu0%-7.8u%-1s% hiz% d%-.8hu%+.1i%-.9hu% .1f%-6.4hu%-.8d%+8.2hi%+10io#%+3.2d%+i%-.9hu%+i,% 9hd^fm%+3.4f*r%-4hi%-.7hi", -911340, 517263, -15416, 679651, "5(ohds#(", 5977, 609041, 435, -767981, 23925, -10368.772714999708, 27532, 502413, 12177, 348999, -230517, -172654, 29305, -701391, 18215, 20134.441068703112, 20252, -23102));
ck_assert_str_eq(boba558_s21, boba558);
}
END_TEST

START_TEST(bebasik__559) {
char boba559_s21[10000];
char boba559[10000];
ck_assert_int_eq(s21_sprintf(boba559_s21, "%-.5fg@% 8hdz%+.2i%-5.5s% 6f%-huvb6/a%-u^%-.6smhxo#%-10hd)r0&", 183.1212981220369, 14680, -735758, "8oeia!f", 3441.105754450209, 6799, 678783, "8t7lw#67vydn`i@=/j)", -9591),
sprintf(boba559, "%-.5fg@% 8hdz%+.2i%-5.5s% 6f%-huvb6/a%-u^%-.6smhxo#%-10hd)r0&", 183.1212981220369, 14680, -735758, "8oeia!f", 3441.105754450209, 6799, 678783, "8t7lw#67vydn`i@=/j)", -9591));
ck_assert_str_eq(boba559_s21, boba559);
}
END_TEST

START_TEST(bebasik__560) {
char boba560_s21[10000];
char boba560[10000];
ck_assert_int_eq(s21_sprintf(boba560_s21, "%+.10f4=% 1.4hi%-.4hi% 4iy", -13494.640314348017, 29261, -18354, 650010),
sprintf(boba560, "%+.10f4=% 1.4hi%-.4hi% 4iy", -13494.640314348017, 29261, -18354, 650010));
ck_assert_str_eq(boba560_s21, boba560);
}
END_TEST

START_TEST(bebasik__561) {
char boba561_s21[10000];
char boba561[10000];
ck_assert_int_eq(s21_sprintf(boba561_s21, "% .2hdk%-10d% .9hd,% hi% hi%-.1hu%+9hi% f%+10.3d%+d% i^[3", -1409, -546551, -16662, 22796, -23316, -23276, -30673, 1238.863003568335, -952979, -684089, -330888),
sprintf(boba561, "% .2hdk%-10d% .9hd,% hi% hi%-.1hu%+9hi% f%+10.3d%+d% i^[3", -1409, -546551, -16662, 22796, -23316, -23276, -30673, 1238.863003568335, -952979, -684089, -330888));
ck_assert_str_eq(boba561_s21, boba561);
}
END_TEST

START_TEST(bebasik__562) {
char boba562_s21[10000];
char boba562[10000];
ck_assert_int_eq(s21_sprintf(boba562_s21, "% hi@% d1)#/% 5hijp% .9hi% .3hdnnql6% .3hi%-.5fo.v% .2f%-5c.1*2%+2.1hi% .1duumo%-c#% hd5n% .8f%+1hi%-1.9hd%+6hi0%-.1hu;^% 10hi%-4hid% hdf%+di", -1290, 52360, 5986, -22282, -11410, 8047, 21062.54329889198, -9403.285678502523, '5', 12664, 8679, 'b', 3205, 90.43992201110328, 6403, -7297, -23366, -6267, -1088, 30988, -23700, 901504),
sprintf(boba562, "% hi@% d1)#/% 5hijp% .9hi% .3hdnnql6% .3hi%-.5fo.v% .2f%-5c.1*2%+2.1hi% .1duumo%-c#% hd5n% .8f%+1hi%-1.9hd%+6hi0%-.1hu;^% 10hi%-4hid% hdf%+di", -1290, 52360, 5986, -22282, -11410, 8047, 21062.54329889198, -9403.285678502523, '5', 12664, 8679, 'b', 3205, 90.43992201110328, 6403, -7297, -23366, -6267, -1088, 30988, -23700, 901504));
ck_assert_str_eq(boba562_s21, boba562);
}
END_TEST

START_TEST(bebasik__563) {
char boba563_s21[10000];
char boba563[10000];
ck_assert_int_eq(s21_sprintf(boba563_s21, "%+1.6hi% .6fc% 3.3hd% 8.2i9% hi;% .8hd%+4hivfh% 9hd%-1.0hd% .8hdz% 9hi%+4.0hi%+hd%-5hup%-5u9% hd%+1hi% 7.0hi8e0%-3.8hd% 5hi=", 11974, 2250.451975589993, -18747, 940808, -24227, 1296, 4070, -1534, -8828, 22668, -8302, -4845, 9287, 17036, -7962, -871, -9731, 24415, 4635, -26784),
sprintf(boba563, "%+1.6hi% .6fc% 3.3hd% 8.2i9% hi;% .8hd%+4hivfh% 9hd%-1.0hd% .8hdz% 9hi%+4.0hi%+hd%-5hup%-5u9% hd%+1hi% 7.0hi8e0%-3.8hd% 5hi=", 11974, 2250.451975589993, -18747, 940808, -24227, 1296, 4070, -1534, -8828, 22668, -8302, -4845, 9287, 17036, -7962, -871, -9731, 24415, 4635, -26784));
ck_assert_str_eq(boba563_s21, boba563);
}
END_TEST

START_TEST(bebasik__564) {
char boba564_s21[10000];
char boba564[10000];
ck_assert_int_eq(s21_sprintf(boba564_s21, "% 9hi% d% .6d%+7.3f@%-2u.", 9345, 859610, -728586, 1146.99126698821, 28181),
sprintf(boba564, "% 9hi% d% .6d%+7.3f@%-2u.", 9345, 859610, -728586, 1146.99126698821, 28181));
ck_assert_str_eq(boba564_s21, boba564);
}
END_TEST

START_TEST(bebasik__565) {
char boba565_s21[10000];
char boba565[10000];
ck_assert_int_eq(s21_sprintf(boba565_s21, "% .6hd%+.3d%+.5i%-.1hu%+3.9hd=dq7,%+4.8i% .5f% .0hi!% .10i^% .9di", 22617, 371043, -657008, 15245, 28798, -616028, -16620.052874270823, 3602, -309351, -896840),
sprintf(boba565, "% .6hd%+.3d%+.5i%-.1hu%+3.9hd=dq7,%+4.8i% .5f% .0hi!% .10i^% .9di", 22617, 371043, -657008, 15245, 28798, -616028, -16620.052874270823, 3602, -309351, -896840));
ck_assert_str_eq(boba565_s21, boba565);
}
END_TEST

START_TEST(bebasik__566) {
char boba566_s21[10000];
char boba566[10000];
ck_assert_int_eq(s21_sprintf(boba566_s21, "%-9fsp%-3imdb%-c%-.3s-%+.2hi`5% .9d%-5hi% f2r% .3hi% 1hd%+iaq7v%-9.2hduw%-.6d%-.1f%-hd=dak*[%-1hd%+1.3d%-f% 2.8hi9%+3dwz4y% f;% hd", -382.675525690538, 964985, 'l', "d5,0rj4qr[b1v0l&.ce)y[hi", 19212, 158495, -14069, 728.6973895382191, -16785, 19399, -432296, -8342, 171213, -5918.582270654672, -9979, 18473, -954121, -22558.73418077524, -30085, -596083, 11207.77833691549, -8304),
sprintf(boba566, "%-9fsp%-3imdb%-c%-.3s-%+.2hi`5% .9d%-5hi% f2r% .3hi% 1hd%+iaq7v%-9.2hduw%-.6d%-.1f%-hd=dak*[%-1hd%+1.3d%-f% 2.8hi9%+3dwz4y% f;% hd", -382.675525690538, 964985, 'l', "d5,0rj4qr[b1v0l&.ce)y[hi", 19212, 158495, -14069, 728.6973895382191, -16785, 19399, -432296, -8342, 171213, -5918.582270654672, -9979, 18473, -954121, -22558.73418077524, -30085, -596083, 11207.77833691549, -8304));
ck_assert_str_eq(boba566_s21, boba566);
}
END_TEST

START_TEST(bebasik__567) {
char boba567_s21[10000];
char boba567[10000];
ck_assert_int_eq(s21_sprintf(boba567_s21, "% 3d% 8.2hi% .6i%+hdir**%+7.7ibs%+10.3i% 10.1dv% 2d%-4.3sfr%+.8hd%+6.9da% 2f% 3.9hd% 2.2hi% .5fe.% 1hd", 900362, 30201, 990495, -22223, -385662, 452368, 989811, 648275, "", 24016, -91868, -1321.3374029975298, -8228, -3777, -1877.8717135792995, 19959),
sprintf(boba567, "% 3d% 8.2hi% .6i%+hdir**%+7.7ibs%+10.3i% 10.1dv% 2d%-4.3sfr%+.8hd%+6.9da% 2f% 3.9hd% 2.2hi% .5fe.% 1hd", 900362, 30201, 990495, -22223, -385662, 452368, 989811, 648275, "", 24016, -91868, -1321.3374029975298, -8228, -3777, -1877.8717135792995, 19959));
ck_assert_str_eq(boba567_s21, boba567);
}
END_TEST

START_TEST(bebasik__568) {
char boba568_s21[10000];
char boba568[10000];
ck_assert_int_eq(s21_sprintf(boba568_s21, "%+hi2% .4f9%+.2i%-i%-.7u% hdc% 2.4hd% f%+2hd%+6i)f4%+1hi% 3hi7.%+6.2d%-1sg#%+6.1hi(j% 6d% .6hd%+.3i%-5hu`m)9%-hd%-7f", 31231, 24244.19545240036, 13701, 675262, -805641, -27458, -29810, 12342.432860049932, 22041, -947567, -27617, 19310, -624569, "z[a2s", 8588, 727083, -13740, 166515, 15196, -14688, -10999.94074829209),
sprintf(boba568, "%+hi2% .4f9%+.2i%-i%-.7u% hdc% 2.4hd% f%+2hd%+6i)f4%+1hi% 3hi7.%+6.2d%-1sg#%+6.1hi(j% 6d% .6hd%+.3i%-5hu`m)9%-hd%-7f", 31231, 24244.19545240036, 13701, 675262, -805641, -27458, -29810, 12342.432860049932, 22041, -947567, -27617, 19310, -624569, "z[a2s", 8588, 727083, -13740, 166515, 15196, -14688, -10999.94074829209));
ck_assert_str_eq(boba568_s21, boba568);
}
END_TEST

START_TEST(bebasik__569) {
char boba569_s21[10000];
char boba569[10000];
ck_assert_int_eq(s21_sprintf(boba569_s21, "%+.10him%+hd%+.0i%+5.3i%+hi%-5hih%+.8hd% .5d% 8.6d7h% .9hd9^%-hdf%-i%+1hi^", -25823, -22535, 899582, 639397, -23749, -8248, 5293, 754438, -71936, -24580, -8240, 561558, 709),
sprintf(boba569, "%+.10him%+hd%+.0i%+5.3i%+hi%-5hih%+.8hd% .5d% 8.6d7h% .9hd9^%-hdf%-i%+1hi^", -25823, -22535, 899582, 639397, -23749, -8248, 5293, 754438, -71936, -24580, -8240, 561558, 709));
ck_assert_str_eq(boba569_s21, boba569);
}
END_TEST

START_TEST(bebasik__570) {
char boba570_s21[10000];
char boba570[10000];
ck_assert_int_eq(s21_sprintf(boba570_s21, "%+2d% 10hi", -473118, 26542),
sprintf(boba570, "%+2d% 10hi", -473118, 26542));
ck_assert_str_eq(boba570_s21, boba570);
}
END_TEST

START_TEST(bebasik__571) {
char boba571_s21[10000];
char boba571[10000];
ck_assert_int_eq(s21_sprintf(boba571_s21, "%-.10hi%+7hd3%-7.0d%-hd4%-2.5hu%-1.6f&;o9(7f%+7d% d!%+.6d% hi5/%-8.10hi%-hu% f%-.2higl%-8.4hdb4%+.1f%-9.9u=%+10.9ib04yb", 8417, -15592, -962230, -10980, 5163, 22546.237589317825, 311884, -756441, 175834, 31727, 26543, 27314, -12313.099046405932, 28309, 18366, -1467.6666054630305, 523751, -157426),
sprintf(boba571, "%-.10hi%+7hd3%-7.0d%-hd4%-2.5hu%-1.6f&;o9(7f%+7d% d!%+.6d% hi5/%-8.10hi%-hu% f%-.2higl%-8.4hdb4%+.1f%-9.9u=%+10.9ib04yb", 8417, -15592, -962230, -10980, 5163, 22546.237589317825, 311884, -756441, 175834, 31727, 26543, 27314, -12313.099046405932, 28309, 18366, -1467.6666054630305, 523751, -157426));
ck_assert_str_eq(boba571_s21, boba571);
}
END_TEST

START_TEST(bebasik__572) {
char boba572_s21[10000];
char boba572[10000];
ck_assert_int_eq(s21_sprintf(boba572_s21, "%+i%-7hi%-1.10hdv%-8hiuj%-hu% .1hi% 9hi% 6f%+hdx%-hi%-3.4hi,v% hdy.%+hi9c%-3.1hudr%+fp% 3.1ir@g)y%-9.1f0", 859389, 18316, -28474, -23852, 3861, 1874, -24748, 5530.268386962653, -21848, -14866, 392, 30450, 10397, 17249, -15543.574765903539, 52026, 3244.589258411528),
sprintf(boba572, "%+i%-7hi%-1.10hdv%-8hiuj%-hu% .1hi% 9hi% 6f%+hdx%-hi%-3.4hi,v% hdy.%+hi9c%-3.1hudr%+fp% 3.1ir@g)y%-9.1f0", 859389, 18316, -28474, -23852, 3861, 1874, -24748, 5530.268386962653, -21848, -14866, 392, 30450, 10397, 17249, -15543.574765903539, 52026, 3244.589258411528));
ck_assert_str_eq(boba572_s21, boba572);
}
END_TEST

START_TEST(bebasik__573) {
char boba573_s21[10000];
char boba573[10000];
ck_assert_int_eq(s21_sprintf(boba573_s21, "%+7.2f%-2i^% .2f%-hi%+.8hi% .3hd%-8u%-8.4hd8", 287.6062431364171, -435645, -2868.087496595311, -13175, 5235, -24596, -2337, 15191),
sprintf(boba573, "%+7.2f%-2i^% .2f%-hi%+.8hi% .3hd%-8u%-8.4hd8", 287.6062431364171, -435645, -2868.087496595311, -13175, 5235, -24596, -2337, 15191));
ck_assert_str_eq(boba573_s21, boba573);
}
END_TEST

START_TEST(bebasik__574) {
char boba574_s21[10000];
char boba574[10000];
ck_assert_int_eq(s21_sprintf(boba574_s21, "%+i%-i8%-2s(%+4d%-9s,=f`=&l$%+4.0d$% 2.3hdb%+3hd5%-.6hd%-7i%-.4u@%+6.5if%-.2fh", -43312, 466296, "dxny5(48rcbt", -700914, "6@83douovh8hrr;ab@", -591925, -280, -2275, -30737, -787875, -198917, -500254, 16935.23461529866),
sprintf(boba574, "%+i%-i8%-2s(%+4d%-9s,=f`=&l$%+4.0d$% 2.3hdb%+3hd5%-.6hd%-7i%-.4u@%+6.5if%-.2fh", -43312, 466296, "dxny5(48rcbt", -700914, "6@83douovh8hrr;ab@", -591925, -280, -2275, -30737, -787875, -198917, -500254, 16935.23461529866));
ck_assert_str_eq(boba574_s21, boba574);
}
END_TEST

START_TEST(bebasik__575) {
char boba575_s21[10000];
char boba575[10000];
ck_assert_int_eq(s21_sprintf(boba575_s21, "%+2hd=% hdvk9", -21906, 17640),
sprintf(boba575, "%+2hd=% hdvk9", -21906, 17640));
ck_assert_str_eq(boba575_s21, boba575);
}
END_TEST

START_TEST(bebasik__576) {
char boba576_s21[10000];
char boba576[10000];
ck_assert_int_eq(s21_sprintf(boba576_s21, "%-5.6u#%-10.4u%-sro% hi%-2f%+1.6fzq%-10hir", -648758, -314790, "9w[x=@xtrwr0sn081iz;^!3pwt0", -7809, -14531.2225201358, -5746.845119356034, -31240),
sprintf(boba576, "%-5.6u#%-10.4u%-sro% hi%-2f%+1.6fzq%-10hir", -648758, -314790, "9w[x=@xtrwr0sn081iz;^!3pwt0", -7809, -14531.2225201358, -5746.845119356034, -31240));
ck_assert_str_eq(boba576_s21, boba576);
}
END_TEST

START_TEST(bebasik__577) {
char boba577_s21[10000];
char boba577[10000];
ck_assert_int_eq(s21_sprintf(boba577_s21, "%-2hd6c% 3hi*% f%+7.2hi%-hu9% hd% .0hd2hi% 1.10d%+4.9hi$% 4.8d,%-7.0hio%+hi%-.8hi", 9451, -10393, 18892.896724489372, -3762, -11592, -27867, 20121, 773617, 19824, -377096, 14688, -24934, -18438),
sprintf(boba577, "%-2hd6c% 3hi*% f%+7.2hi%-hu9% hd% .0hd2hi% 1.10d%+4.9hi$% 4.8d,%-7.0hio%+hi%-.8hi", 9451, -10393, 18892.896724489372, -3762, -11592, -27867, 20121, 773617, 19824, -377096, 14688, -24934, -18438));
ck_assert_str_eq(boba577_s21, boba577);
}
END_TEST

START_TEST(bebasik__578) {
char boba578_s21[10000];
char boba578[10000];
ck_assert_int_eq(s21_sprintf(boba578_s21, "% 9.1f%-.8i=% 7hix% 5.5hi%+.7d%+4.8f-%-10hdu%+.5hd% .7d!,%-.2hda.% 5.5ivt,)e", -24597.195012374515, -548017, 22534, 10997, 383069, 12448.163308580057, -18575, -23675, -490195, 2338, 15414),
sprintf(boba578, "% 9.1f%-.8i=% 7hix% 5.5hi%+.7d%+4.8f-%-10hdu%+.5hd% .7d!,%-.2hda.% 5.5ivt,)e", -24597.195012374515, -548017, 22534, 10997, 383069, 12448.163308580057, -18575, -23675, -490195, 2338, 15414));
ck_assert_str_eq(boba578_s21, boba578);
}
END_TEST

START_TEST(bebasik__579) {
char boba579_s21[10000];
char boba579[10000];
ck_assert_int_eq(s21_sprintf(boba579_s21, "%-.9hiq7", 11454),
sprintf(boba579, "%-.9hiq7", 11454));
ck_assert_str_eq(boba579_s21, boba579);
}
END_TEST

START_TEST(bebasik__580) {
char boba580_s21[10000];
char boba580[10000];
ck_assert_int_eq(s21_sprintf(boba580_s21, "%+8dr%-c%-8.6s%-.7d", -761892, 'z', "s*h6x10v=l/8mi45r3/", 604054),
sprintf(boba580, "%+8dr%-c%-8.6s%-.7d", -761892, 'z', "s*h6x10v=l/8mi45r3/", 604054));
ck_assert_str_eq(boba580_s21, boba580);
}
END_TEST

START_TEST(bebasik__581) {
char boba581_s21[10000];
char boba581[10000];
ck_assert_int_eq(s21_sprintf(boba581_s21, "%+4.8d% ixc%-2hu% .7fs%+9.6ikt2% 1.1hd@% .0hi%-1.6hu^", 82857, -258923, -26811, 4850.42436441312, -401385, 27045, -25984, -19943),
sprintf(boba581, "%+4.8d% ixc%-2hu% .7fs%+9.6ikt2% 1.1hd@% .0hi%-1.6hu^", 82857, -258923, -26811, 4850.42436441312, -401385, 27045, -25984, -19943));
ck_assert_str_eq(boba581_s21, boba581);
}
END_TEST

START_TEST(bebasik__582) {
char boba582_s21[10000];
char boba582[10000];
ck_assert_int_eq(s21_sprintf(boba582_s21, "%+8.3hd%-2hu^%+.0i=7i36%+.8hi%+hi%+.6fe(l% hi%-.10hu;%-6hd%-2.5it%-8i22%+.4hi% hd@%+8.2hd,% 3.10iv% .10hi% f;.7", 11819, -17806, 868951, 23413, -1770, -16566.29670288369, 24675, -22263, 9008, -844237, -387064, 27667, 20023, -15447, -797333, -8543, 659.3734323338842),
sprintf(boba582, "%+8.3hd%-2hu^%+.0i=7i36%+.8hi%+hi%+.6fe(l% hi%-.10hu;%-6hd%-2.5it%-8i22%+.4hi% hd@%+8.2hd,% 3.10iv% .10hi% f;.7", 11819, -17806, 868951, 23413, -1770, -16566.29670288369, 24675, -22263, 9008, -844237, -387064, 27667, 20023, -15447, -797333, -8543, 659.3734323338842));
ck_assert_str_eq(boba582_s21, boba582);
}
END_TEST

START_TEST(bebasik__583) {
char boba583_s21[10000];
char boba583[10000];
ck_assert_int_eq(s21_sprintf(boba583_s21, "% d%+6.8hi%-10.1hi*%+10.1hd%+.0dx%-10d%+.2ii%+i5x3%+10.3i,", 59262, -26510, -26828, 7425, 149994, -417426, -724744, 102240, 816669),
sprintf(boba583, "% d%+6.8hi%-10.1hi*%+10.1hd%+.0dx%-10d%+.2ii%+i5x3%+10.3i,", 59262, -26510, -26828, 7425, 149994, -417426, -724744, 102240, 816669));
ck_assert_str_eq(boba583_s21, boba583);
}
END_TEST

START_TEST(bebasik__584) {
char boba584_s21[10000];
char boba584[10000];
ck_assert_int_eq(s21_sprintf(boba584_s21, "%-fxn% .9f%+hd7%+7hi!%+9hdk*% i%-.2s%-6.9hdg%-8uj% 3f/v% i;%+.1f% hijwi3% .0d!g7%+d*%+4.5hi.8[% i%-.2hi%-.9dq% .10hip%+9i`% 1.4hi%+8.6hd%-5.3iw", 1172.777739554264, -20844.912553323313, -23406, 17070, 16126, 559116, "u`lg9)blw=2-", -12408, 171004, 4471.414069824481, -428500, 19062.96229359558, 18114, -220685, 405179, 18830, 653259, 14951, -491817, -10862, 157877, 18124, -23785, 594964),
sprintf(boba584, "%-fxn% .9f%+hd7%+7hi!%+9hdk*% i%-.2s%-6.9hdg%-8uj% 3f/v% i;%+.1f% hijwi3% .0d!g7%+d*%+4.5hi.8[% i%-.2hi%-.9dq% .10hip%+9i`% 1.4hi%+8.6hd%-5.3iw", 1172.777739554264, -20844.912553323313, -23406, 17070, 16126, 559116, "u`lg9)blw=2-", -12408, 171004, 4471.414069824481, -428500, 19062.96229359558, 18114, -220685, 405179, 18830, 653259, 14951, -491817, -10862, 157877, 18124, -23785, 594964));
ck_assert_str_eq(boba584_s21, boba584);
}
END_TEST

START_TEST(bebasik__585) {
char boba585_s21[10000];
char boba585[10000];
ck_assert_int_eq(s21_sprintf(boba585_s21, "% .1hi7%-3.8su%-hi2s%+3.6hd.%+hi%+.0i%+10iz%-6.9u", 10375, "f$9xi0$;sa0p8a", 14520, 25313, 30195, -631673, 111983, -477520),
sprintf(boba585, "% .1hi7%-3.8su%-hi2s%+3.6hd.%+hi%+.0i%+10iz%-6.9u", 10375, "f$9xi0$;sa0p8a", 14520, 25313, 30195, -631673, 111983, -477520));
ck_assert_str_eq(boba585_s21, boba585);
}
END_TEST

START_TEST(bebasik__586) {
char boba586_s21[10000];
char boba586[10000];
ck_assert_int_eq(s21_sprintf(boba586_s21, "% .6d%-.2huoea%+.2hi%+9.0f$% 5.4hi7f6;y!)%+.3dnr% hd% d/", -42955, -13497, -10853, 7803.492641517268, 15605, -821249, 4994, -923584),
sprintf(boba586, "% .6d%-.2huoea%+.2hi%+9.0f$% 5.4hi7f6;y!)%+.3dnr% hd% d/", -42955, -13497, -10853, 7803.492641517268, 15605, -821249, 4994, -923584));
ck_assert_str_eq(boba586_s21, boba586);
}
END_TEST

START_TEST(bebasik__587) {
char boba587_s21[10000];
char boba587[10000];
ck_assert_int_eq(s21_sprintf(boba587_s21, "%-10.1f%+3hin2.*x%-1.0hd% 1hi%-i.$m% 8hd%-10.1i%-.1hu% 7.6hd%-.10hi%+9hi% .9f% .7dh%-4.2hi%+9.0ix%-d^c", 4890.422249713069, -1673, 798, -18420, -605801, 18118, -138436, 4762, -15472, -30765, -20708, -23384.79384245729, -804054, 7356, 168031, 36254),
sprintf(boba587, "%-10.1f%+3hin2.*x%-1.0hd% 1hi%-i.$m% 8hd%-10.1i%-.1hu% 7.6hd%-.10hi%+9hi% .9f% .7dh%-4.2hi%+9.0ix%-d^c", 4890.422249713069, -1673, 798, -18420, -605801, 18118, -138436, 4762, -15472, -30765, -20708, -23384.79384245729, -804054, 7356, 168031, 36254));
ck_assert_str_eq(boba587_s21, boba587);
}
END_TEST

START_TEST(bebasik__588) {
char boba588_s21[10000];
char boba588[10000];
ck_assert_int_eq(s21_sprintf(boba588_s21, "% hi#`ym%-9.8hu^c!i7", -10660, -14113),
sprintf(boba588, "% hi#`ym%-9.8hu^c!i7", -10660, -14113));
ck_assert_str_eq(boba588_s21, boba588);
}
END_TEST

START_TEST(bebasik__589) {
char boba589_s21[10000];
char boba589[10000];
ck_assert_int_eq(s21_sprintf(boba589_s21, "%+5hd% 4.2hi%-5is%-1.9hi% 9.10hi0%-7.2hi%+i7%-hu", -24889, 10704, 650622, 9977, 9553, 22689, -53315, 1027),
sprintf(boba589, "%+5hd% 4.2hi%-5is%-1.9hi% 9.10hi0%-7.2hi%+i7%-hu", -24889, 10704, 650622, 9977, 9553, 22689, -53315, 1027));
ck_assert_str_eq(boba589_s21, boba589);
}
END_TEST

START_TEST(bebasik__590) {
char boba590_s21[10000];
char boba590[10000];
ck_assert_int_eq(s21_sprintf(boba590_s21, "% hi*%+.5hd%+.1hi", 30778, -22866, 6903),
sprintf(boba590, "% hi*%+.5hd%+.1hi", 30778, -22866, 6903));
ck_assert_str_eq(boba590_s21, boba590);
}
END_TEST

START_TEST(bebasik__591) {
char boba591_s21[10000];
char boba591[10000];
ck_assert_int_eq(s21_sprintf(boba591_s21, "%+3hd%+2.1i-.pn% d8%+hd8%-7c3l$-^t^)x%+f,1%+i$", 11424, 508230, 316783, 10724, 's', -1790.4723444062886, -685032),
sprintf(boba591, "%+3hd%+2.1i-.pn% d8%+hd8%-7c3l$-^t^)x%+f,1%+i$", 11424, 508230, 316783, 10724, 's', -1790.4723444062886, -685032));
ck_assert_str_eq(boba591_s21, boba591);
}
END_TEST

START_TEST(bebasik__592) {
char boba592_s21[10000];
char boba592[10000];
ck_assert_int_eq(s21_sprintf(boba592_s21, "%+.9i/%-hu=x%-8.4i%-6.1f!% 3fr% 9.3hi%+d%+.7hi%-.5ix%-hdm0-%-5i7[%-.8ie56%-5.9u%+.2hi", 276644, -19517, 81457, 5930.542076026432, -16413.515645995856, 10769, 521885, 15668, 386710, 5287, 108172, -422074, -582437, -8904),
sprintf(boba592, "%+.9i/%-hu=x%-8.4i%-6.1f!% 3fr% 9.3hi%+d%+.7hi%-.5ix%-hdm0-%-5i7[%-.8ie56%-5.9u%+.2hi", 276644, -19517, 81457, 5930.542076026432, -16413.515645995856, 10769, 521885, 15668, 386710, 5287, 108172, -422074, -582437, -8904));
ck_assert_str_eq(boba592_s21, boba592);
}
END_TEST

START_TEST(bebasik__593) {
char boba593_s21[10000];
char boba593[10000];
ck_assert_int_eq(s21_sprintf(boba593_s21, "% 5.0f%+7.9d%-.2hd%+1.10d%-hi% 2.7f*v%+d%-6.2hib%+.7i%+f", -2573.8965730110344, 229569, -24, -547563, 30817, 3685.964287783003, -967546, -24192, -584403, -11022.06511772466),
sprintf(boba593, "% 5.0f%+7.9d%-.2hd%+1.10d%-hi% 2.7f*v%+d%-6.2hib%+.7i%+f", -2573.8965730110344, 229569, -24, -547563, 30817, 3685.964287783003, -967546, -24192, -584403, -11022.06511772466));
ck_assert_str_eq(boba593_s21, boba593);
}
END_TEST

START_TEST(bebasik__594) {
char boba594_s21[10000];
char boba594[10000];
ck_assert_int_eq(s21_sprintf(boba594_s21, "%-7.6f%+8.6hi", -54.86418809904146, 11915),
sprintf(boba594, "%-7.6f%+8.6hi", -54.86418809904146, 11915));
ck_assert_str_eq(boba594_s21, boba594);
}
END_TEST

START_TEST(bebasik__595) {
char boba595_s21[10000];
char boba595[10000];
ck_assert_int_eq(s21_sprintf(boba595_s21, "% 7hd1o6% 7.10f.%-.9hic%-.6uan% fmn% .4hd[o;%-2.10hu%-.5hu% 8.0hd%+.8hi6a", 30913, -2986.9551945722255, -20555, 869054, 9012.742211175699, -21605, -19838, -10320, 16716, 19572),
sprintf(boba595, "% 7hd1o6% 7.10f.%-.9hic%-.6uan% fmn% .4hd[o;%-2.10hu%-.5hu% 8.0hd%+.8hi6a", 30913, -2986.9551945722255, -20555, 869054, 9012.742211175699, -21605, -19838, -10320, 16716, 19572));
ck_assert_str_eq(boba595_s21, boba595);
}
END_TEST

START_TEST(bebasik__596) {
char boba596_s21[10000];
char boba596[10000];
ck_assert_int_eq(s21_sprintf(boba596_s21, "%-hu", -27461),
sprintf(boba596, "%-hu", -27461));
ck_assert_str_eq(boba596_s21, boba596);
}
END_TEST

START_TEST(bebasik__597) {
char boba597_s21[10000];
char boba597[10000];
ck_assert_int_eq(s21_sprintf(boba597_s21, "%-sh%-7.8hi%+1.7fz", "5a!.3", 12155, 672.7315634294022),
sprintf(boba597, "%-sh%-7.8hi%+1.7fz", "5a!.3", 12155, 672.7315634294022));
ck_assert_str_eq(boba597_s21, boba597);
}
END_TEST

START_TEST(bebasik__598) {
char boba598_s21[10000];
char boba598[10000];
ck_assert_int_eq(s21_sprintf(boba598_s21, "%-8.4u%+.9f96s%+4dd% 1hd2% d%-.4i%+3.5hdx%-1.3hd2%-1hu%+3.0i%+8.6hdz(bn%-.9fv% 3.8hi@% i5;uj", 8060, 2701.3029577910884, 15361, -25321, 235947, 208384, -20081, 19377, 3273, -637497, -11796, 10810.843800111565, -6402, -15490),
sprintf(boba598, "%-8.4u%+.9f96s%+4dd% 1hd2% d%-.4i%+3.5hdx%-1.3hd2%-1hu%+3.0i%+8.6hdz(bn%-.9fv% 3.8hi@% i5;uj", 8060, 2701.3029577910884, 15361, -25321, 235947, 208384, -20081, 19377, 3273, -637497, -11796, 10810.843800111565, -6402, -15490));
ck_assert_str_eq(boba598_s21, boba598);
}
END_TEST

START_TEST(bebasik__599) {
char boba599_s21[10000];
char boba599[10000];
ck_assert_int_eq(s21_sprintf(boba599_s21, "% do%+.9hin%+8.9f% hi% .0d%-5.3hi%-.2ug%+f4k%+7f% .3hi", -872196, 8192, 168.63436606309605, -2894, -41921, 11297, 837825, 912.6039768922387, -2973.7213705342656, -18120),
sprintf(boba599, "% do%+.9hin%+8.9f% hi% .0d%-5.3hi%-.2ug%+f4k%+7f% .3hi", -872196, 8192, 168.63436606309605, -2894, -41921, 11297, 837825, 912.6039768922387, -2973.7213705342656, -18120));
ck_assert_str_eq(boba599_s21, boba599);
}
END_TEST

START_TEST(bebasik__600) {
char boba600_s21[10000];
char boba600[10000];
ck_assert_int_eq(s21_sprintf(boba600_s21, "%+6.10hd%-hd% 1d%+7hifj%-hi@zi%+2.8f/pm%-.2u%-.8hd%-4hd%+hd%+.7d%+.0hddd% .1hd%+2d%+hd&g%-hd%+i-% i8% .4hi`$% 6hd% .7hd)`%-5.7hi%-hi%+8hd[*", -19060, 6396, 126343, -4940, 16831, -9547.342884299165, -457148, 6692, -18942, 25175, 499246, -20056, 1098, 262722, 26533, -21805, -551392, -630008, 23141, -26372, -30820, 10704, 30968, -16389),
sprintf(boba600, "%+6.10hd%-hd% 1d%+7hifj%-hi@zi%+2.8f/pm%-.2u%-.8hd%-4hd%+hd%+.7d%+.0hddd% .1hd%+2d%+hd&g%-hd%+i-% i8% .4hi`$% 6hd% .7hd)`%-5.7hi%-hi%+8hd[*", -19060, 6396, 126343, -4940, 16831, -9547.342884299165, -457148, 6692, -18942, 25175, 499246, -20056, 1098, 262722, 26533, -21805, -551392, -630008, 23141, -26372, -30820, 10704, 30968, -16389));
ck_assert_str_eq(boba600_s21, boba600);
}
END_TEST

START_TEST(bebasik__601) {
char boba601_s21[10000];
char boba601[10000];
ck_assert_int_eq(s21_sprintf(boba601_s21, "% d%-.4d% 6.5hi)% 9.6hd% .4hd%+3.3his`%-f", 117643, 858596, 14306, -27939, -18526, 27729, 529.0502203064224),
sprintf(boba601, "% d%-.4d% 6.5hi)% 9.6hd% .4hd%+3.3his`%-f", 117643, 858596, 14306, -27939, -18526, 27729, 529.0502203064224));
ck_assert_str_eq(boba601_s21, boba601);
}
END_TEST

START_TEST(bebasik__602) {
char boba602_s21[10000];
char boba602[10000];
ck_assert_int_eq(s21_sprintf(boba602_s21, "%+1.9hi%+i%+hi/%+.7f[%-2hd[%+9hi`%+fq%-c=% hi,d%+f% 10.5him&% di^%-fw", 17492, -547877, -394, -1855.06767915903, 16373, 28047, -4108.898335403521, 'f', 24008, -2178.9247277717354, -5398, -686145, -15180.860486457717),
sprintf(boba602, "%+1.9hi%+i%+hi/%+.7f[%-2hd[%+9hi`%+fq%-c=% hi,d%+f% 10.5him&% di^%-fw", 17492, -547877, -394, -1855.06767915903, 16373, 28047, -4108.898335403521, 'f', 24008, -2178.9247277717354, -5398, -686145, -15180.860486457717));
ck_assert_str_eq(boba602_s21, boba602);
}
END_TEST

START_TEST(bebasik__603) {
char boba603_s21[10000];
char boba603[10000];
ck_assert_int_eq(s21_sprintf(boba603_s21, "% 3.6dzw%-sj%+9.10f% hd(`%+f%+hi%-.0f&).% hd%-1hu)%+.5hdbpx0% 3.5i%+6.4hd,g%+1.6hi%+.0fr%+9hi% 3.7f%+6hi%-7d%-.0hu% 6hi[n", 620700, "sx[", 5698.786358456263, -10581, -6938.5448869375305, -31500, 14246.462300727697, -30956, -28931, -8757, 607065, -17202, -2984, 4262.1606436484535, -22945, 17679.32126378524, -12080, -682541, 27678, 3691),
sprintf(boba603, "% 3.6dzw%-sj%+9.10f% hd(`%+f%+hi%-.0f&).% hd%-1hu)%+.5hdbpx0% 3.5i%+6.4hd,g%+1.6hi%+.0fr%+9hi% 3.7f%+6hi%-7d%-.0hu% 6hi[n", 620700, "sx[", 5698.786358456263, -10581, -6938.5448869375305, -31500, 14246.462300727697, -30956, -28931, -8757, 607065, -17202, -2984, 4262.1606436484535, -22945, 17679.32126378524, -12080, -682541, 27678, 3691));
ck_assert_str_eq(boba603_s21, boba603);
}
END_TEST

START_TEST(bebasik__604) {
char boba604_s21[10000];
char boba604[10000];
ck_assert_int_eq(s21_sprintf(boba604_s21, "%-.4sj9%-7u%+.3hd", ";,#wp)`f!5=[i#z,", 329417, 11692),
sprintf(boba604, "%-.4sj9%-7u%+.3hd", ";,#wp)`f!5=[i#z,", 329417, 11692));
ck_assert_str_eq(boba604_s21, boba604);
}
END_TEST

START_TEST(bebasik__605) {
char boba605_s21[10000];
char boba605[10000];
ck_assert_int_eq(s21_sprintf(boba605_s21, "%+.3d% .2dh%-3hi% hi%-.4hd%-.8hi%-10.1hd1% 5.7f% 2hi,%-2hd*%-6.1hu1%+3.1d%+9hd!k% .5hd", -675286, 600561, -6153, 25214, 18793, 20397, -8939, -3883.7880558467177, 26503, 8081, -27138, -123416, 1147, 12498),
sprintf(boba605, "%+.3d% .2dh%-3hi% hi%-.4hd%-.8hi%-10.1hd1% 5.7f% 2hi,%-2hd*%-6.1hu1%+3.1d%+9hd!k% .5hd", -675286, 600561, -6153, 25214, 18793, 20397, -8939, -3883.7880558467177, 26503, 8081, -27138, -123416, 1147, 12498));
ck_assert_str_eq(boba605_s21, boba605);
}
END_TEST

START_TEST(bebasik__606) {
char boba606_s21[10000];
char boba606[10000];
ck_assert_int_eq(s21_sprintf(boba606_s21, "%+.4i% 7.3hi$%-6cx%+10hi%+7.7d2%-.1hu%-.6hdn(% 4f$% hd%+.10hi%+9.4fp$ycueg%+8d%+6.2d^", -416183, 16780, '.', 887, 96080, 6906, -21643, 2116.6293813507214, -2887, -12742, 3182.8737633655096, 327146, 614773),
sprintf(boba606, "%+.4i% 7.3hi$%-6cx%+10hi%+7.7d2%-.1hu%-.6hdn(% 4f$% hd%+.10hi%+9.4fp$ycueg%+8d%+6.2d^", -416183, 16780, '.', 887, 96080, 6906, -21643, 2116.6293813507214, -2887, -12742, 3182.8737633655096, 327146, 614773));
ck_assert_str_eq(boba606_s21, boba606);
}
END_TEST

START_TEST(bebasik__607) {
char boba607_s21[10000];
char boba607[10000];
ck_assert_int_eq(s21_sprintf(boba607_s21, "% 9i[%+.10iu-%+9fin2% .1i/", -110451, -815987, 1214.8135729897892, -732824),
sprintf(boba607, "% 9i[%+.10iu-%+9fin2% .1i/", -110451, -815987, 1214.8135729897892, -732824));
ck_assert_str_eq(boba607_s21, boba607);
}
END_TEST

START_TEST(bebasik__608) {
char boba608_s21[10000];
char boba608[10000];
ck_assert_int_eq(s21_sprintf(boba608_s21, "%+2.2hi-% 9hd%-hu%-.2u% 7hi% 4i%-.3s%-5i#% .2hdud%-10hd[j@%+.1f% d%+hi9*(%-5.3dh);%-s(st%+f(4% 3hir% 3.1hdoy#", -9729, 12306, 1560, 843103, -9223, -161211, "8q$`enp", -493197, 14457, -15165, 9178.443910372236, 407520, 4186, -622211, "k;@ea#.b5u3pka56eipmbeph=tw1b", 4566.915159112394, 30061, 28306),
sprintf(boba608, "%+2.2hi-% 9hd%-hu%-.2u% 7hi% 4i%-.3s%-5i#% .2hdud%-10hd[j@%+.1f% d%+hi9*(%-5.3dh);%-s(st%+f(4% 3hir% 3.1hdoy#", -9729, 12306, 1560, 843103, -9223, -161211, "8q$`enp", -493197, 14457, -15165, 9178.443910372236, 407520, 4186, -622211, "k;@ea#.b5u3pka56eipmbeph=tw1b", 4566.915159112394, 30061, 28306));
ck_assert_str_eq(boba608_s21, boba608);
}
END_TEST

START_TEST(bebasik__609) {
char boba609_s21[10000];
char boba609[10000];
ck_assert_int_eq(s21_sprintf(boba609_s21, "%-.0hu% .4iy^%+.2hd%-5i%-1hi%+f%-us%+.10f98a%+.3f% .0hd0%-5.1hi%+d-% 3.5hd9l%+.8ihpt%+i%+.8hi% 9.5f% 3hitdyb", -9694, -391247, 5573, -177057, 12175, -62.192494137795904, 74771, -9785.081177170294, 8484.420500339822, -14241, 19518, -957727, 27947, -559174, -799843, 5845, 4905.034436608423, 13387),
sprintf(boba609, "%-.0hu% .4iy^%+.2hd%-5i%-1hi%+f%-us%+.10f98a%+.3f% .0hd0%-5.1hi%+d-% 3.5hd9l%+.8ihpt%+i%+.8hi% 9.5f% 3hitdyb", -9694, -391247, 5573, -177057, 12175, -62.192494137795904, 74771, -9785.081177170294, 8484.420500339822, -14241, 19518, -957727, 27947, -559174, -799843, 5845, 4905.034436608423, 13387));
ck_assert_str_eq(boba609_s21, boba609);
}
END_TEST

START_TEST(bebasik__610) {
char boba610_s21[10000];
char boba610[10000];
ck_assert_int_eq(s21_sprintf(boba610_s21, "% 5f3i% 8.4di%-.7f(%+hd% .9i5% 5.8hd% 9.6d% 10d57%+hd%-hih% 8hd%+i%-4hi% f% 2.0iu$%+4.5hd% .6hd", -9298.749238090519, 623220, -15062.117326456693, 12018, -55939, 26109, -182804, -310124, 25654, -27518, 8023, -769801, 13482, 13097.879318504263, 787526, 2865, 17224),
sprintf(boba610, "% 5f3i% 8.4di%-.7f(%+hd% .9i5% 5.8hd% 9.6d% 10d57%+hd%-hih% 8hd%+i%-4hi% f% 2.0iu$%+4.5hd% .6hd", -9298.749238090519, 623220, -15062.117326456693, 12018, -55939, 26109, -182804, -310124, 25654, -27518, 8023, -769801, 13482, 13097.879318504263, 787526, 2865, 17224));
ck_assert_str_eq(boba610_s21, boba610);
}
END_TEST

START_TEST(bebasik__611) {
char boba611_s21[10000];
char boba611[10000];
ck_assert_int_eq(s21_sprintf(boba611_s21, "%-2hi.% 8.9d%-c;d%+7.3f%-5hu% .6hi%-.5i8&%+10hi%+d% 1hd% 4.5hix@%-1.8hd%+.0f%+hdl%-10d,% d%-10.5icgij%-8.2hdr3%+.5hib%+i#)", 9035, 393710, '@', 3698.8799539422293, 29726, -4807, -954490, -9992, -14375, 4387, 30778, 26862, -263.08047459921966, 8518, 987233, -848847, -55037, 19892, 28899, -587221),
sprintf(boba611, "%-2hi.% 8.9d%-c;d%+7.3f%-5hu% .6hi%-.5i8&%+10hi%+d% 1hd% 4.5hix@%-1.8hd%+.0f%+hdl%-10d,% d%-10.5icgij%-8.2hdr3%+.5hib%+i#)", 9035, 393710, '@', 3698.8799539422293, 29726, -4807, -954490, -9992, -14375, 4387, 30778, 26862, -263.08047459921966, 8518, 987233, -848847, -55037, 19892, 28899, -587221));
ck_assert_str_eq(boba611_s21, boba611);
}
END_TEST

START_TEST(bebasik__612) {
char boba612_s21[10000];
char boba612[10000];
ck_assert_int_eq(s21_sprintf(boba612_s21, "% .9hd.%+2f7%-5s4a% hi[% 6f%-.0hd% 6.9fr/%-hu%-2.3hd% 4.4hi%+7f% hiw%-4.7hu;% 6.4i%+.2id% da%+dc%-4.3f% 1i%+i5-", 30951, 4126.403531343353, "!q*bg1p0g29p)aduj(xgyug", -15934, -23265.936697825673, -19075, 783.1576070391641, 24323, -20525, -27497, -4854.280020682727, -4608, -24451, 807488, -156728, -944080, 665772, -7212.132645738366, -41230, -314832),
sprintf(boba612, "% .9hd.%+2f7%-5s4a% hi[% 6f%-.0hd% 6.9fr/%-hu%-2.3hd% 4.4hi%+7f% hiw%-4.7hu;% 6.4i%+.2id% da%+dc%-4.3f% 1i%+i5-", 30951, 4126.403531343353, "!q*bg1p0g29p)aduj(xgyug", -15934, -23265.936697825673, -19075, 783.1576070391641, 24323, -20525, -27497, -4854.280020682727, -4608, -24451, 807488, -156728, -944080, 665772, -7212.132645738366, -41230, -314832));
ck_assert_str_eq(boba612_s21, boba612);
}
END_TEST

START_TEST(bebasik__613) {
char boba613_s21[10000];
char boba613[10000];
ck_assert_int_eq(s21_sprintf(boba613_s21, "%-2.1f% 9hd%+hi% 8.8hi8rmp%+d#%-.9hi%-4.0hu5hx!i%+.2hi%+.9f*b8`&xt%-.5hih%+10.2djs%+hd-9%-hi%-5.6f%-6hu% hi", -13646.608915339357, 5007, 8835, -5069, 96351, -23918, -9808, -22039, -505.71994861315045, -13284, 700689, 6329, -9378, 2080.733034057654, 2914, 12765),
sprintf(boba613, "%-2.1f% 9hd%+hi% 8.8hi8rmp%+d#%-.9hi%-4.0hu5hx!i%+.2hi%+.9f*b8`&xt%-.5hih%+10.2djs%+hd-9%-hi%-5.6f%-6hu% hi", -13646.608915339357, 5007, 8835, -5069, 96351, -23918, -9808, -22039, -505.71994861315045, -13284, 700689, 6329, -9378, 2080.733034057654, 2914, 12765));
ck_assert_str_eq(boba613_s21, boba613);
}
END_TEST

START_TEST(bebasik__614) {
char boba614_s21[10000];
char boba614[10000];
ck_assert_int_eq(s21_sprintf(boba614_s21, "%-.5s%-2fp%-hi$0% 9hd%-1u*%-10.8u", "xik//4u=wn[b7&t5/`*;tg14", -3205.428444847314, -5453, 13060, -719180, 678342),
sprintf(boba614, "%-.5s%-2fp%-hi$0% 9hd%-1u*%-10.8u", "xik//4u=wn[b7&t5/`*;tg14", -3205.428444847314, -5453, 13060, -719180, 678342));
ck_assert_str_eq(boba614_s21, boba614);
}
END_TEST

START_TEST(bebasik__615) {
char boba615_s21[10000];
char boba615[10000];
ck_assert_int_eq(s21_sprintf(boba615_s21, "%+3.0hd%+10.9hd% .3fyh", -15234, -4214, 22626.877690996433),
sprintf(boba615, "%+3.0hd%+10.9hd% .3fyh", -15234, -4214, 22626.877690996433));
ck_assert_str_eq(boba615_s21, boba615);
}
END_TEST

START_TEST(bebasik__616) {
char boba616_s21[10000];
char boba616[10000];
ck_assert_int_eq(s21_sprintf(boba616_s21, "%+hd`h% 8i%+9.7hd;", 6706, -882286, -3595),
sprintf(boba616, "%+hd`h% 8i%+9.7hd;", 6706, -882286, -3595));
ck_assert_str_eq(boba616_s21, boba616);
}
END_TEST

START_TEST(bebasik__617) {
char boba617_s21[10000];
char boba617[10000];
ck_assert_int_eq(s21_sprintf(boba617_s21, "%-4.8iw)%+.8hd% .10hdv%+6il%+9hi% .5hd% 4hi% 1his[%+7i% 9i4$% 1.4hd,%-9i^", 505388, 23906, 16961, 647344, 9707, -29636, 26964, -7507, 89904, -253455, -5329, 436868),
sprintf(boba617, "%-4.8iw)%+.8hd% .10hdv%+6il%+9hi% .5hd% 4hi% 1his[%+7i% 9i4$% 1.4hd,%-9i^", 505388, 23906, 16961, 647344, 9707, -29636, 26964, -7507, 89904, -253455, -5329, 436868));
ck_assert_str_eq(boba617_s21, boba617);
}
END_TEST

START_TEST(bebasik__618) {
char boba618_s21[10000];
char boba618[10000];
ck_assert_int_eq(s21_sprintf(boba618_s21, "%+.3hdxthb%+hd% .0hi%+.5f(&uz%+i%+.7hd-n", 2014, -6157, 9511, 3752.1723434454716, 971601, 5735),
sprintf(boba618, "%+.3hdxthb%+hd% .0hi%+.5f(&uz%+i%+.7hd-n", 2014, -6157, 9511, 3752.1723434454716, 971601, 5735));
ck_assert_str_eq(boba618_s21, boba618);
}
END_TEST

START_TEST(bebasik__619) {
char boba619_s21[10000];
char boba619[10000];
ck_assert_int_eq(s21_sprintf(boba619_s21, "%-i%+10.5f%-.0hdi%-5.8hi% dd90% dg%+8.1hik% 3hd0%+hd%-3u%+2.1hd", -11860, 10802.424659310422, 8631, 2949, 943900, 635515, -6450, -12834, -20678, 313260, 25995),
sprintf(boba619, "%-i%+10.5f%-.0hdi%-5.8hi% dd90% dg%+8.1hik% 3hd0%+hd%-3u%+2.1hd", -11860, 10802.424659310422, 8631, 2949, 943900, 635515, -6450, -12834, -20678, 313260, 25995));
ck_assert_str_eq(boba619_s21, boba619);
}
END_TEST

START_TEST(bebasik__620) {
char boba620_s21[10000];
char boba620[10000];
ck_assert_int_eq(s21_sprintf(boba620_s21, "%+.7hin%-6hu%+10.0i0^fq%+i%+hi&% 6.10hd%-f=%-4f%-4.2sk5%+2i$%-5.4hdn-% .2hdv% .0hi%+.8hdr!% i", 26006, 6823, -951403, 983034, -11701, 2572, 15392.570318726752, -11215.237033902342, "yz5zcs@op@p5vf,l3#lcc@7f$uk", -548310, -13337, -16757, 27775, 9096, -875606),
sprintf(boba620, "%+.7hin%-6hu%+10.0i0^fq%+i%+hi&% 6.10hd%-f=%-4f%-4.2sk5%+2i$%-5.4hdn-% .2hdv% .0hi%+.8hdr!% i", 26006, 6823, -951403, 983034, -11701, 2572, 15392.570318726752, -11215.237033902342, "yz5zcs@op@p5vf,l3#lcc@7f$uk", -548310, -13337, -16757, 27775, 9096, -875606));
ck_assert_str_eq(boba620_s21, boba620);
}
END_TEST

START_TEST(bebasik__621) {
char boba621_s21[10000];
char boba621[10000];
ck_assert_int_eq(s21_sprintf(boba621_s21, "% i%-.8hd5*%+i;n%-8.6u4% 5.8d% hiu%+iy%-hd% 5.0hd%+4.3hd", -875636, 26761, -300286, 488337, 961593, 17843, -316528, 31501, 31052, 26832),
sprintf(boba621, "% i%-.8hd5*%+i;n%-8.6u4% 5.8d% hiu%+iy%-hd% 5.0hd%+4.3hd", -875636, 26761, -300286, 488337, 961593, 17843, -316528, 31501, 31052, 26832));
ck_assert_str_eq(boba621_s21, boba621);
}
END_TEST

START_TEST(bebasik__622) {
char boba622_s21[10000];
char boba622[10000];
ck_assert_int_eq(s21_sprintf(boba622_s21, "% .8d% .8d#242c7e8%+6.6hd%+io%+.0hix1%+3f%-3.9dt% 10.5hi4d%+4d%-s^)x)%+7hd% 1d%+2hd% 8.7f%+hib%+i% hiq%+do0%-6.10fi%-7hi8%+7.9d%-him7", -552419, -152644, -23203, -437412, 11583, 6990.147542261892, -10997, 5659, -353838, "r3l1.fch[1$^iovqtb6lq(n", -3576, 984721, 20001, -13109.325130041625, -9538, -648308, 1993, -989496, 7061.2284767884585, 13558, -905629, -6111),
sprintf(boba622, "% .8d% .8d#242c7e8%+6.6hd%+io%+.0hix1%+3f%-3.9dt% 10.5hi4d%+4d%-s^)x)%+7hd% 1d%+2hd% 8.7f%+hib%+i% hiq%+do0%-6.10fi%-7hi8%+7.9d%-him7", -552419, -152644, -23203, -437412, 11583, 6990.147542261892, -10997, 5659, -353838, "r3l1.fch[1$^iovqtb6lq(n", -3576, 984721, 20001, -13109.325130041625, -9538, -648308, 1993, -989496, 7061.2284767884585, 13558, -905629, -6111));
ck_assert_str_eq(boba622_s21, boba622);
}
END_TEST

START_TEST(bebasik__623) {
char boba623_s21[10000];
char boba623[10000];
ck_assert_int_eq(s21_sprintf(boba623_s21, "%-9hijj%+.8f%+1.6d% 3his%+9i% .4i%-8.10u(%+3.0hd% 9hi%+ib.3p%-.9hix", 756, -6224.930874969831, -291437, -8891, 54967, 71264, 567142, -26059, 10652, -95712, 28120),
sprintf(boba623, "%-9hijj%+.8f%+1.6d% 3his%+9i% .4i%-8.10u(%+3.0hd% 9hi%+ib.3p%-.9hix", 756, -6224.930874969831, -291437, -8891, 54967, 71264, 567142, -26059, 10652, -95712, 28120));
ck_assert_str_eq(boba623_s21, boba623);
}
END_TEST

START_TEST(bebasik__624) {
char boba624_s21[10000];
char boba624[10000];
ck_assert_int_eq(s21_sprintf(boba624_s21, "%-.2hd)%-3.1hd7% .8d!% 7.1hd% 9i%+3.6hd%+f4% .8de%+8hi% 10.9hd% 5if%-6.3hi%+9hd%+.0hi1l1%+hi725%+.1hd%+6.0hi6%+i%-1.8sh% .5hd%+.6hd%-.2shb%+hd%+f", -12931, 5958, -521655, -19130, 870035, -23824, 577.1374885821288, -21865, -26162, 10272, -697972, -17826, -12672, 21208, 23928, -29265, 22255, -167227, "1nl$i=)xo@`r-#8", -13103, -26891, "h/bhb(#=rc04lf=", -22618, -2470.4307340932546),
sprintf(boba624, "%-.2hd)%-3.1hd7% .8d!% 7.1hd% 9i%+3.6hd%+f4% .8de%+8hi% 10.9hd% 5if%-6.3hi%+9hd%+.0hi1l1%+hi725%+.1hd%+6.0hi6%+i%-1.8sh% .5hd%+.6hd%-.2shb%+hd%+f", -12931, 5958, -521655, -19130, 870035, -23824, 577.1374885821288, -21865, -26162, 10272, -697972, -17826, -12672, 21208, 23928, -29265, 22255, -167227, "1nl$i=)xo@`r-#8", -13103, -26891, "h/bhb(#=rc04lf=", -22618, -2470.4307340932546));
ck_assert_str_eq(boba624_s21, boba624);
}
END_TEST

START_TEST(bebasik__625) {
char boba625_s21[10000];
char boba625[10000];
ck_assert_int_eq(s21_sprintf(boba625_s21, "% 10.5f% hdtk%+.4dd!%-6.6hih/!%-9d% 1iu*%+5.2hd%-.5s%-6hiz% 7.5is;0%+6.3ii0l1%+7d%-10.6s[%+2.0i/i%+hd% .5ig-%+1hdps@#%+iq%-9sxo%+fzt3[y0*%-hu% 2.8hd", 6352.530760163695, 2762, -734004, 21813, -594777, 654039, 16380, "8.m53z0)xwd^e#=9", 25942, -182088, -156533, 109486, "1p-va*[a(,q9r(u#(`", 881127, 13197, 846835, 21124, 83727, "48[;pu*1;[;2j`5d/(", 7575.203207452797, -23730, -16366),
sprintf(boba625, "% 10.5f% hdtk%+.4dd!%-6.6hih/!%-9d% 1iu*%+5.2hd%-.5s%-6hiz% 7.5is;0%+6.3ii0l1%+7d%-10.6s[%+2.0i/i%+hd% .5ig-%+1hdps@#%+iq%-9sxo%+fzt3[y0*%-hu% 2.8hd", 6352.530760163695, 2762, -734004, 21813, -594777, 654039, 16380, "8.m53z0)xwd^e#=9", 25942, -182088, -156533, 109486, "1p-va*[a(,q9r(u#(`", 881127, 13197, 846835, 21124, 83727, "48[;pu*1;[;2j`5d/(", 7575.203207452797, -23730, -16366));
ck_assert_str_eq(boba625_s21, boba625);
}
END_TEST

START_TEST(bebasik__626) {
char boba626_s21[10000];
char boba626[10000];
ck_assert_int_eq(s21_sprintf(boba626_s21, "%-.8hd% .0hi%-d%+9.0f%+7.5hi*% 5hd%+.6i%+3f8%-1.9hd%-10.5hiwo`8%+2.3dh%-.6d%-ue!c%-2hi% hi8%-.10hu%+.7hd7", 18817, -1611, -628070, -5018.406165694007, -16588, -30299, -694908, -5066.121024443767, 2156, 450, 530009, 841219, -474933, 24747, -28355, 18048, -8793),
sprintf(boba626, "%-.8hd% .0hi%-d%+9.0f%+7.5hi*% 5hd%+.6i%+3f8%-1.9hd%-10.5hiwo`8%+2.3dh%-.6d%-ue!c%-2hi% hi8%-.10hu%+.7hd7", 18817, -1611, -628070, -5018.406165694007, -16588, -30299, -694908, -5066.121024443767, 2156, 450, 530009, 841219, -474933, 24747, -28355, 18048, -8793));
ck_assert_str_eq(boba626_s21, boba626);
}
END_TEST

START_TEST(bebasik__627) {
char boba627_s21[10000];
char boba627[10000];
ck_assert_int_eq(s21_sprintf(boba627_s21, "%-hi% .9i%-.5hdq.%-hi% 4.9hik%-8hufi", -24554, -199719, -29645, 22069, -5241, -26119),
sprintf(boba627, "%-hi% .9i%-.5hdq.%-hi% 4.9hik%-8hufi", -24554, -199719, -29645, 22069, -5241, -26119));
ck_assert_str_eq(boba627_s21, boba627);
}
END_TEST

START_TEST(bebasik__628) {
char boba628_s21[10000];
char boba628[10000];
ck_assert_int_eq(s21_sprintf(boba628_s21, "%-10hd% .2hd% 1i.%+5.0hd%-6.7d% .3hi%+9.5hd% 9i%+.4hd%+.7hdk%-hu%+2i% 6.3i42f$%-7.9s% 2.9d*a% .6hiko", 6701, 27767, 860082, 2646, -628596, -10870, 27692, 312715, -25796, 25044, 16635, 927236, 767136, "5f/t@*qc/s`$gn", -708726, -21432),
sprintf(boba628, "%-10hd% .2hd% 1i.%+5.0hd%-6.7d% .3hi%+9.5hd% 9i%+.4hd%+.7hdk%-hu%+2i% 6.3i42f$%-7.9s% 2.9d*a% .6hiko", 6701, 27767, 860082, 2646, -628596, -10870, 27692, 312715, -25796, 25044, 16635, 927236, 767136, "5f/t@*qc/s`$gn", -708726, -21432));
ck_assert_str_eq(boba628_s21, boba628);
}
END_TEST

START_TEST(bebasik__629) {
char boba629_s21[10000];
char boba629[10000];
ck_assert_int_eq(s21_sprintf(boba629_s21, "%+.8i#%-.3hd%-.0d%+2.2d@1%-.3hi% 2d@ukt% d%-.3f%+6hdb^i%-hi%-1.6i% i%+8.9iram,%-6c%-.0sq%-i%+8hi!% hd#%+8.10hd&%-hd!,$%+.1i%-.8hu", -18054, -12177, -261210, 527078, -12185, 614718, 745344, 5957.920308566305, -11961, -5608, -341292, 270241, 301226, 'j', "83gpod3", -114699, -8652, 24182, -13011, 29513, -369800, -15474),
sprintf(boba629, "%+.8i#%-.3hd%-.0d%+2.2d@1%-.3hi% 2d@ukt% d%-.3f%+6hdb^i%-hi%-1.6i% i%+8.9iram,%-6c%-.0sq%-i%+8hi!% hd#%+8.10hd&%-hd!,$%+.1i%-.8hu", -18054, -12177, -261210, 527078, -12185, 614718, 745344, 5957.920308566305, -11961, -5608, -341292, 270241, 301226, 'j', "83gpod3", -114699, -8652, 24182, -13011, 29513, -369800, -15474));
ck_assert_str_eq(boba629_s21, boba629);
}
END_TEST

START_TEST(bebasik__630) {
char boba630_s21[10000];
char boba630[10000];
ck_assert_int_eq(s21_sprintf(boba630_s21, "% f-2%+5.2hdk%-9.0hi%-hdb,;% 10f%-8su%-2hdx%-i(c%+hi%+ij%+.2hd%+.1f% f%+6d1% .8dlc%+hi% 9.7hi% .10hi9x[#4z% 10.8hip2e[%+9.9ip7bsyh%-d%-i%-.3f", 20988.25940984843, 18816, 12871, 16473, -9425.183890394828, "*b.7w/)dj1!;zif/*&n/", -28739, 789033, 15798, 770573, 6116, -1095.2876335432, -1018.0104693781404, 170206, 421549, 9035, -15260, 26159, -10923, -172962, 250101, -100603, 6659.68701295139),
sprintf(boba630, "% f-2%+5.2hdk%-9.0hi%-hdb,;% 10f%-8su%-2hdx%-i(c%+hi%+ij%+.2hd%+.1f% f%+6d1% .8dlc%+hi% 9.7hi% .10hi9x[#4z% 10.8hip2e[%+9.9ip7bsyh%-d%-i%-.3f", 20988.25940984843, 18816, 12871, 16473, -9425.183890394828, "*b.7w/)dj1!;zif/*&n/", -28739, 789033, 15798, 770573, 6116, -1095.2876335432, -1018.0104693781404, 170206, 421549, 9035, -15260, 26159, -10923, -172962, 250101, -100603, 6659.68701295139));
ck_assert_str_eq(boba630_s21, boba630);
}
END_TEST

START_TEST(bebasik__631) {
char boba631_s21[10000];
char boba631[10000];
ck_assert_int_eq(s21_sprintf(boba631_s21, "%-.10hi9% f%-.2hi%+5.10f%-7hun5%+.1hi% 5.8hir%+1.8hd%-2.5i%-3.0d% hd%-hu$*% 4hi%+2d%-.3srw% 5i%-hi=#u%+3.2hdf)%-.1hud", 24822, 1388.6934105344576, -31967, 25194.35994285982, 24801, -10716, 6971, -3731, -353840, -615272, 11276, -24625, -19600, -605293, "7[`[&bavb)n`", 226871, -31810, 30945, 6450),
sprintf(boba631, "%-.10hi9% f%-.2hi%+5.10f%-7hun5%+.1hi% 5.8hir%+1.8hd%-2.5i%-3.0d% hd%-hu$*% 4hi%+2d%-.3srw% 5i%-hi=#u%+3.2hdf)%-.1hud", 24822, 1388.6934105344576, -31967, 25194.35994285982, 24801, -10716, 6971, -3731, -353840, -615272, 11276, -24625, -19600, -605293, "7[`[&bavb)n`", 226871, -31810, 30945, 6450));
ck_assert_str_eq(boba631_s21, boba631);
}
END_TEST

START_TEST(bebasik__632) {
char boba632_s21[10000];
char boba632[10000];
ck_assert_int_eq(s21_sprintf(boba632_s21, "%-hu% 4.0fmnwy#a%+hd% 9.0hd6%-1hi%-1hd^%-.2hu% .1hi!c% 2hi%+5hi%-9.5uv% .9d@%+6hd%+hi%-.4s%-.0u%+2.6i%-6hu%+hi% 8.7hi%+9.3hd%-2.1hi% .3hi%-hd=j", 13069, 5847.32354414253, 25680, -23123, -19345, 311, -7340, 26307, -8651, 1871, -146267, -577011, -5106, -2545, "r$x6p40lcdo6d#-m/fl", -656649, -682558, 12786, 28931, -16321, 28721, -14661, -1312, -20599),
sprintf(boba632, "%-hu% 4.0fmnwy#a%+hd% 9.0hd6%-1hi%-1hd^%-.2hu% .1hi!c% 2hi%+5hi%-9.5uv% .9d@%+6hd%+hi%-.4s%-.0u%+2.6i%-6hu%+hi% 8.7hi%+9.3hd%-2.1hi% .3hi%-hd=j", 13069, 5847.32354414253, 25680, -23123, -19345, 311, -7340, 26307, -8651, 1871, -146267, -577011, -5106, -2545, "r$x6p40lcdo6d#-m/fl", -656649, -682558, 12786, 28931, -16321, 28721, -14661, -1312, -20599));
ck_assert_str_eq(boba632_s21, boba632);
}
END_TEST

START_TEST(bebasik__633) {
char boba633_s21[10000];
char boba633[10000];
ck_assert_int_eq(s21_sprintf(boba633_s21, "%-.9u% .0ir[3%-.6hdr7zv!% 4.9hi%+d%+.3hi", 760079, 387644, -15584, 24582, -398278, -12872),
sprintf(boba633, "%-.9u% .0ir[3%-.6hdr7zv!% 4.9hi%+d%+.3hi", 760079, 387644, -15584, 24582, -398278, -12872));
ck_assert_str_eq(boba633_s21, boba633);
}
END_TEST

START_TEST(bebasik__634) {
char boba634_s21[10000];
char boba634[10000];
ck_assert_int_eq(s21_sprintf(boba634_s21, "% 7i% 5in", 174448, 878896),
sprintf(boba634, "% 7i% 5in", 174448, 878896));
ck_assert_str_eq(boba634_s21, boba634);
}
END_TEST

START_TEST(bebasik__635) {
char boba635_s21[10000];
char boba635[10000];
ck_assert_int_eq(s21_sprintf(boba635_s21, "% dm% .1f%-.9i%-4.0f%-hi`% 2.5f%-4hd%-.5hu% doi%-.10sf5% hdi%+8.4hi% ir9%-3cx% 9.3f6% .7hi%-4hi%-hd%+hd%-3.6d", -86087, -4076.103609443706, -158094, 983.8748674189176, -15579, 7958.3494514444565, -7436, -99, 489771, "--", -27900, 27935, -724549, '/', -5582.184684519568, 6580, -17352, -8658, 17248, -812937),
sprintf(boba635, "% dm% .1f%-.9i%-4.0f%-hi`% 2.5f%-4hd%-.5hu% doi%-.10sf5% hdi%+8.4hi% ir9%-3cx% 9.3f6% .7hi%-4hi%-hd%+hd%-3.6d", -86087, -4076.103609443706, -158094, 983.8748674189176, -15579, 7958.3494514444565, -7436, -99, 489771, "--", -27900, 27935, -724549, '/', -5582.184684519568, 6580, -17352, -8658, 17248, -812937));
ck_assert_str_eq(boba635_s21, boba635);
}
END_TEST

START_TEST(bebasik__636) {
char boba636_s21[10000];
char boba636[10000];
ck_assert_int_eq(s21_sprintf(boba636_s21, "%-hd%-hi%-hi%+hdq% .4hi% 1.5fi%+8hi%-ub% .1d%+.3ft[%+.7hd%+6.10hi% 7i4e%+10.8d*%-.3hu^% 2hib% 3f%+7i% 10.7d,ajhydm", -13961, 17234, -30787, 23829, -24590, 10878.026012373542, 23503, 714679, -539821, 515.6285479066864, -9330, -22453, 222607, 100307, -28701, 31563, 15468.45755960953, -963855, -195352),
sprintf(boba636, "%-hd%-hi%-hi%+hdq% .4hi% 1.5fi%+8hi%-ub% .1d%+.3ft[%+.7hd%+6.10hi% 7i4e%+10.8d*%-.3hu^% 2hib% 3f%+7i% 10.7d,ajhydm", -13961, 17234, -30787, 23829, -24590, 10878.026012373542, 23503, 714679, -539821, 515.6285479066864, -9330, -22453, 222607, 100307, -28701, 31563, 15468.45755960953, -963855, -195352));
ck_assert_str_eq(boba636_s21, boba636);
}
END_TEST

START_TEST(bebasik__637) {
char boba637_s21[10000];
char boba637[10000];
ck_assert_int_eq(s21_sprintf(boba637_s21, "% .7hd4t!%+f% 10hd#o%+hi)%+.5i%+.1hi%+1.4i#%-hu%-2.8hi#%-1hu% 4hi% 3.10i@", 5160, -5221.350976909426, 5193, 8075, 385987, -22514, 992223, 26356, -28799, -2375, -28056, 93655),
sprintf(boba637, "% .7hd4t!%+f% 10hd#o%+hi)%+.5i%+.1hi%+1.4i#%-hu%-2.8hi#%-1hu% 4hi% 3.10i@", 5160, -5221.350976909426, 5193, 8075, 385987, -22514, 992223, 26356, -28799, -2375, -28056, 93655));
ck_assert_str_eq(boba637_s21, boba637);
}
END_TEST

START_TEST(bebasik__638) {
char boba638_s21[10000];
char boba638[10000];
ck_assert_int_eq(s21_sprintf(boba638_s21, "% 1.2f% 4.4dg%+hi%+7d", 14145.37736451738, 321635, 11357, -167363),
sprintf(boba638, "% 1.2f% 4.4dg%+hi%+7d", 14145.37736451738, 321635, 11357, -167363));
ck_assert_str_eq(boba638_s21, boba638);
}
END_TEST

START_TEST(bebasik__639) {
char boba639_s21[10000];
char boba639[10000];
ck_assert_int_eq(s21_sprintf(boba639_s21, "% 9hi-1%+.8ddp%-3.7s%+f5% .5hdd% d2% 8.0hi4% 3i%+hi1g-(%+5hd6z%-2.10do%+f%+5f% i% .5hi2% 9.5hd% iq%-d%-.9hisuq%-.3d% .4hi%-hu!%-hin% hi", -31536, -529569, "no#5wbz-molh)qlyxp^$", 27802.409569478692, 3763, -815392, 6683, -532440, -6177, 31740, -857777, -1680.0752775727449, 21177.63374930526, 68199, 9259, -6228, -169738, 701856, 19196, -942763, 25858, 9006, 15656, -4222),
sprintf(boba639, "% 9hi-1%+.8ddp%-3.7s%+f5% .5hdd% d2% 8.0hi4% 3i%+hi1g-(%+5hd6z%-2.10do%+f%+5f% i% .5hi2% 9.5hd% iq%-d%-.9hisuq%-.3d% .4hi%-hu!%-hin% hi", -31536, -529569, "no#5wbz-molh)qlyxp^$", 27802.409569478692, 3763, -815392, 6683, -532440, -6177, 31740, -857777, -1680.0752775727449, 21177.63374930526, 68199, 9259, -6228, -169738, 701856, 19196, -942763, 25858, 9006, 15656, -4222));
ck_assert_str_eq(boba639_s21, boba639);
}
END_TEST

START_TEST(bebasik__640) {
char boba640_s21[10000];
char boba640[10000];
ck_assert_int_eq(s21_sprintf(boba640_s21, "%+4d%-cjb7% 6.0hi*% 7hd%+2.7hdh%-.10hiq% 4.3hi% 3hizm=k% hi% 8d%-.3fz% .2f).% 9i=% 2.7hi% 4.6i=cg%-8i(gy% 8.7f%-.5s*", -288958, 'j', -28989, 30277, -11556, -10306, 9863, -11028, -5246, -671194, -2422.8653871341685, 9584.257374262137, 812829, -18380, 558015, -3714, 570.9328198089185, "fol69zvc3-`wu,14)@c$"),
sprintf(boba640, "%+4d%-cjb7% 6.0hi*% 7hd%+2.7hdh%-.10hiq% 4.3hi% 3hizm=k% hi% 8d%-.3fz% .2f).% 9i=% 2.7hi% 4.6i=cg%-8i(gy% 8.7f%-.5s*", -288958, 'j', -28989, 30277, -11556, -10306, 9863, -11028, -5246, -671194, -2422.8653871341685, 9584.257374262137, 812829, -18380, 558015, -3714, 570.9328198089185, "fol69zvc3-`wu,14)@c$"));
ck_assert_str_eq(boba640_s21, boba640);
}
END_TEST

START_TEST(bebasik__641) {
char boba641_s21[10000];
char boba641[10000];
ck_assert_int_eq(s21_sprintf(boba641_s21, "% 8d%-ff3y% hd%+fp% 1.10i&%+.6hd[% .6hi%+.5f%+10f%-6huf%+.6dkb;%-10.0i!%-hd% 10.5hi&,7j% hd6cf[% .7ik", 760413, 7965.844670602281, 13640, -6247.824963651875, 634965, 20869, 14477, -2656.458253440737, -10889.554696609332, 15677, -235136, 299917, 11055, -6422, -9481, -561806),
sprintf(boba641, "% 8d%-ff3y% hd%+fp% 1.10i&%+.6hd[% .6hi%+.5f%+10f%-6huf%+.6dkb;%-10.0i!%-hd% 10.5hi&,7j% hd6cf[% .7ik", 760413, 7965.844670602281, 13640, -6247.824963651875, 634965, 20869, 14477, -2656.458253440737, -10889.554696609332, 15677, -235136, 299917, 11055, -6422, -9481, -561806));
ck_assert_str_eq(boba641_s21, boba641);
}
END_TEST

START_TEST(bebasik__642) {
char boba642_s21[10000];
char boba642[10000];
ck_assert_int_eq(s21_sprintf(boba642_s21, "%-6.7d%+10.2f% .6hi7j% d%-2.1iy%+9.1f%-hi% 8hd%+2f[9c*%+.1hd%+7dp%-7.9u", -499994, -5863.2176591873695, 1684, 899260, -902967, 6071.764514501244, -1220, -11537, -4863.4931172504075, 14874, 876119, -478156),
sprintf(boba642, "%-6.7d%+10.2f% .6hi7j% d%-2.1iy%+9.1f%-hi% 8hd%+2f[9c*%+.1hd%+7dp%-7.9u", -499994, -5863.2176591873695, 1684, 899260, -902967, 6071.764514501244, -1220, -11537, -4863.4931172504075, 14874, 876119, -478156));
ck_assert_str_eq(boba642_s21, boba642);
}
END_TEST

START_TEST(bebasik__643) {
char boba643_s21[10000];
char boba643[10000];
ck_assert_int_eq(s21_sprintf(boba643_s21, "%-4hd% hdh% .5hi%+.0di% 4dbs%+.8i%+9.7f% .8hi%-.6uf#%+.4f%+hd$=% 5hic%+3.7i%-2i*% 1.5ftg%+1.3hd", -1897, -1099, -10617, -104576, 147450, -272371, 7328.115910823959, -22276, 197648, -14383.637787499263, 6099, -2542, -607240, -979913, 289.60437247827196, -16940),
sprintf(boba643, "%-4hd% hdh% .5hi%+.0di% 4dbs%+.8i%+9.7f% .8hi%-.6uf#%+.4f%+hd$=% 5hic%+3.7i%-2i*% 1.5ftg%+1.3hd", -1897, -1099, -10617, -104576, 147450, -272371, 7328.115910823959, -22276, 197648, -14383.637787499263, 6099, -2542, -607240, -979913, 289.60437247827196, -16940));
ck_assert_str_eq(boba643_s21, boba643);
}
END_TEST

START_TEST(bebasik__644) {
char boba644_s21[10000];
char boba644[10000];
ck_assert_int_eq(s21_sprintf(boba644_s21, "% i%-8u%+1dh%+.1f% 7.8igip% .10f%+10hi%+.10hd%+d%-hu(b", -296682, 588519, 200247, -10959.071301434113, -692927, -5418.7470137995715, 5119, -9911, -741685, 27608),
sprintf(boba644, "% i%-8u%+1dh%+.1f% 7.8igip% .10f%+10hi%+.10hd%+d%-hu(b", -296682, 588519, 200247, -10959.071301434113, -692927, -5418.7470137995715, 5119, -9911, -741685, 27608));
ck_assert_str_eq(boba644_s21, boba644);
}
END_TEST

START_TEST(bebasik__645) {
char boba645_s21[10000];
char boba645[10000];
ck_assert_int_eq(s21_sprintf(boba645_s21, "% i.`% 10hi7z2x%-5u% 7.4hi%+3.4hdf.s;% .1fwk%+3hd%-cwe2%-3f%+d^,e[;iftz%-.6hd%+1f%+2d%+.0hdd% .0hi%-1hd%-f@vzfz7yl/&%+3.4iukj4%-.5s% .0hd", -51462, -27652, -629724, -7705, -7051, -733.4119475164212, 26737, 'u', -37.87532844175999, 450059, 22818, 81.72812582934107, 262724, 23742, 30235, 12552, 13835.417276031185, -550661, "1hij5nc5l&i4rfwqa1#29@01w", 28237),
sprintf(boba645, "% i.`% 10hi7z2x%-5u% 7.4hi%+3.4hdf.s;% .1fwk%+3hd%-cwe2%-3f%+d^,e[;iftz%-.6hd%+1f%+2d%+.0hdd% .0hi%-1hd%-f@vzfz7yl/&%+3.4iukj4%-.5s% .0hd", -51462, -27652, -629724, -7705, -7051, -733.4119475164212, 26737, 'u', -37.87532844175999, 450059, 22818, 81.72812582934107, 262724, 23742, 30235, 12552, 13835.417276031185, -550661, "1hij5nc5l&i4rfwqa1#29@01w", 28237));
ck_assert_str_eq(boba645_s21, boba645);
}
END_TEST

START_TEST(bebasik__646) {
char boba646_s21[10000];
char boba646[10000];
ck_assert_int_eq(s21_sprintf(boba646_s21, "%+f% 1.0fn(a% 2.7hdipf`t%+9.5d% f%+6.7hi%+hi% 9.9hd%-3.2s`*,%+f% i*%+.10hi);vg%-4.0hu%+.3i%-3.10f%-.8fomz%-10.10hd([p%+.3hik% 4.9hdf% 8hd%-10hd", 9220.487618877112, 5676.186786569834, 4279, -933211, -17845.850922751535, 6293, -24509, 13700, "og-x^3[ey-ta`6nkqtc", -7947.233392828643, 554866, 16857, -15335, -565653, 3159.237080714307, -25246.84795464638, 5435, 20398, -2918, 26046, 3455),
sprintf(boba646, "%+f% 1.0fn(a% 2.7hdipf`t%+9.5d% f%+6.7hi%+hi% 9.9hd%-3.2s`*,%+f% i*%+.10hi);vg%-4.0hu%+.3i%-3.10f%-.8fomz%-10.10hd([p%+.3hik% 4.9hdf% 8hd%-10hd", 9220.487618877112, 5676.186786569834, 4279, -933211, -17845.850922751535, 6293, -24509, 13700, "og-x^3[ey-ta`6nkqtc", -7947.233392828643, 554866, 16857, -15335, -565653, 3159.237080714307, -25246.84795464638, 5435, 20398, -2918, 26046, 3455));
ck_assert_str_eq(boba646_s21, boba646);
}
END_TEST

START_TEST(bebasik__647) {
char boba647_s21[10000];
char boba647[10000];
ck_assert_int_eq(s21_sprintf(boba647_s21, "% 4hdd%+2.8hd%+hi/9%-9.5s% .0f% 7.1i2a6%-hd%-6.7d%+d%-10.8hd6%+7.5f%+f%+5hi% d% .0hd%-i^q% .8hdm%-s[(3f(%-2hi0%+4.3d%+9d&%-6sb%+.0hi% hih", 5938, 2211, -6909, "^&6nx@2", -6114.640044010371, -435800, -30241, 367292, 87900, -13935, 16220.809890436567, -8115.042931556686, -28401, -325758, -14315, 881377, -20291, "6k-r3*8.f7rzv5b", -24938, -618927, 814954, "(c*a;t[=h", -5890, 52),
sprintf(boba647, "% 4hdd%+2.8hd%+hi/9%-9.5s% .0f% 7.1i2a6%-hd%-6.7d%+d%-10.8hd6%+7.5f%+f%+5hi% d% .0hd%-i^q% .8hdm%-s[(3f(%-2hi0%+4.3d%+9d&%-6sb%+.0hi% hih", 5938, 2211, -6909, "^&6nx@2", -6114.640044010371, -435800, -30241, 367292, 87900, -13935, 16220.809890436567, -8115.042931556686, -28401, -325758, -14315, 881377, -20291, "6k-r3*8.f7rzv5b", -24938, -618927, 814954, "(c*a;t[=h", -5890, 52));
ck_assert_str_eq(boba647_s21, boba647);
}
END_TEST

START_TEST(bebasik__648) {
char boba648_s21[10000];
char boba648[10000];
ck_assert_int_eq(s21_sprintf(boba648_s21, "%+2.8i)p%+4.0f3)n)@%+5hd.*%+du.%+.3i%+7.1f(%-ft% .2hd/%-9ixhw", -156457, 223.81294274702526, 8076, 267583, -707921, -15325.791949383573, -6974.288171165249, 8183, -930027),
sprintf(boba648, "%+2.8i)p%+4.0f3)n)@%+5hd.*%+du.%+.3i%+7.1f(%-ft% .2hd/%-9ixhw", -156457, 223.81294274702526, 8076, 267583, -707921, -15325.791949383573, -6974.288171165249, 8183, -930027));
ck_assert_str_eq(boba648_s21, boba648);
}
END_TEST

START_TEST(bebasik__649) {
char boba649_s21[10000];
char boba649[10000];
ck_assert_int_eq(s21_sprintf(boba649_s21, "% 3i%-u%-6c5dwu%-hd=wo2%-10.6hi% 2hd%-7.0hu%-fa`", 181634, 358686, ',', -31234, 22999, -20582, -14732, -3034.769796223371),
sprintf(boba649, "% 3i%-u%-6c5dwu%-hd=wo2%-10.6hi% 2hd%-7.0hu%-fa`", 181634, 358686, ',', -31234, 22999, -20582, -14732, -3034.769796223371));
ck_assert_str_eq(boba649_s21, boba649);
}
END_TEST

START_TEST(bebasik__650) {
char boba650_s21[10000];
char boba650[10000];
ck_assert_int_eq(s21_sprintf(boba650_s21, "%+dqwlr5%+9.1hd%-8.0hu3%-.8hd%+.1d% 4dl", -532172, -22294, -4021, -6262, -658146, -839965),
sprintf(boba650, "%+dqwlr5%+9.1hd%-8.0hu3%-.8hd%+.1d% 4dl", -532172, -22294, -4021, -6262, -658146, -839965));
ck_assert_str_eq(boba650_s21, boba650);
}
END_TEST

START_TEST(bebasik__651) {
char boba651_s21[10000];
char boba651[10000];
ck_assert_int_eq(s21_sprintf(boba651_s21, "%-.7u)%-.4hi6% 2.7hd%+5.9hi4%-.3hd$fv%+i;k% icf% .4hi%-f%-6hdb)%+1hi%+1hd5*u% 8hi% 8.9hd!a0i!%+i% .8hi%+9.10hd% 4db^% hdj8% i-3,%-hd%-.6s% hir#x", -690661, -14602, -29487, 14844, -1093, 524842, 106849, -29812, 18469.770227971494, 3026, -10550, 1609, -21712, -352, -253607, -4910, 28279, -653464, -286, 548736, -1297, "&k", -9799),
sprintf(boba651, "%-.7u)%-.4hi6% 2.7hd%+5.9hi4%-.3hd$fv%+i;k% icf% .4hi%-f%-6hdb)%+1hi%+1hd5*u% 8hi% 8.9hd!a0i!%+i% .8hi%+9.10hd% 4db^% hdj8% i-3,%-hd%-.6s% hir#x", -690661, -14602, -29487, 14844, -1093, 524842, 106849, -29812, 18469.770227971494, 3026, -10550, 1609, -21712, -352, -253607, -4910, 28279, -653464, -286, 548736, -1297, "&k", -9799));
ck_assert_str_eq(boba651_s21, boba651);
}
END_TEST

START_TEST(bebasik__652) {
char boba652_s21[10000];
char boba652[10000];
ck_assert_int_eq(s21_sprintf(boba652_s21, "%-hu% .6f% .6hdf@% 6.8dd%-hi1tc%-8.0f%-5.0hi% hi", -25160, 10526.252367043022, -2678, 785438, -28723, 5839.342019434122, -29072, 6146),
sprintf(boba652, "%-hu% .6f% .6hdf@% 6.8dd%-hi1tc%-8.0f%-5.0hi% hi", -25160, 10526.252367043022, -2678, 785438, -28723, 5839.342019434122, -29072, 6146));
ck_assert_str_eq(boba652_s21, boba652);
}
END_TEST

START_TEST(bebasik__653) {
char boba653_s21[10000];
char boba653[10000];
ck_assert_int_eq(s21_sprintf(boba653_s21, "%+10.5hiv%-6.10hi% 3.9hi(,u^%-.9i1%-7s-% 2d#o&vu%-9.8d%+.4i%-7hupt%+5.7hdd.%-2.7hud`% 4hiledb% 2hd% .6hi% f% 1.6f%-.6hu% 6hd%-7.10hii&;,%+3hd`n%+.5frz% 6i)%-1.1f% 8.3i#fo", -20008, 30286, 2125, -134798, "3&h[&kh`/x4lx.2i$yfr[15r&[($j", 391257, 134101, -919373, 17315, -22779, 19409, 28140, -17315, 6361, -30226.684530897764, -5857.408334175617, -3328, 14437, 26607, 17082, 274.2646323142787, -210021, -25264.227092670542, 110521),
sprintf(boba653, "%+10.5hiv%-6.10hi% 3.9hi(,u^%-.9i1%-7s-% 2d#o&vu%-9.8d%+.4i%-7hupt%+5.7hdd.%-2.7hud`% 4hiledb% 2hd% .6hi% f% 1.6f%-.6hu% 6hd%-7.10hii&;,%+3hd`n%+.5frz% 6i)%-1.1f% 8.3i#fo", -20008, 30286, 2125, -134798, "3&h[&kh`/x4lx.2i$yfr[15r&[($j", 391257, 134101, -919373, 17315, -22779, 19409, 28140, -17315, 6361, -30226.684530897764, -5857.408334175617, -3328, 14437, 26607, 17082, 274.2646323142787, -210021, -25264.227092670542, 110521));
ck_assert_str_eq(boba653_s21, boba653);
}
END_TEST

START_TEST(bebasik__654) {
char boba654_s21[10000];
char boba654[10000];
ck_assert_int_eq(s21_sprintf(boba654_s21, "% 10.10io% hii*n/%-sx%+2d,=%-4hd%-1.1hi7", -128472, -16378, "^j##([@uq=qy5qs", -893527, 26023, -2374),
sprintf(boba654, "% 10.10io% hii*n/%-sx%+2d,=%-4hd%-1.1hi7", -128472, -16378, "^j##([@uq=qy5qs", -893527, 26023, -2374));
ck_assert_str_eq(boba654_s21, boba654);
}
END_TEST

START_TEST(bebasik__655) {
char boba655_s21[10000];
char boba655[10000];
ck_assert_int_eq(s21_sprintf(boba655_s21, "%-hd#y%+.8hi%+fpx%+d%+.5i%-u%+il%-10.5d%-9.4d%+i%-9.2d%+10hdpk%+.1hi%+7.8f2o%-3hi% d.%-10.3hu% 3.8hd%+hd,ei% hi%+4f%+hi", -25284, 16712, -4722.537508370085, -116993, -665601, -15166, -500793, -430989, 75884, 546612, 233698, 21205, 13199, -752.741198978875, 1681, 722151, 3454, 16702, 1604, 31451, 9783.992808229212, -3234),
sprintf(boba655, "%-hd#y%+.8hi%+fpx%+d%+.5i%-u%+il%-10.5d%-9.4d%+i%-9.2d%+10hdpk%+.1hi%+7.8f2o%-3hi% d.%-10.3hu% 3.8hd%+hd,ei% hi%+4f%+hi", -25284, 16712, -4722.537508370085, -116993, -665601, -15166, -500793, -430989, 75884, 546612, 233698, 21205, 13199, -752.741198978875, 1681, 722151, 3454, 16702, 1604, 31451, 9783.992808229212, -3234));
ck_assert_str_eq(boba655_s21, boba655);
}
END_TEST

START_TEST(bebasik__656) {
char boba656_s21[10000];
char boba656[10000];
ck_assert_int_eq(s21_sprintf(boba656_s21, "%+.0hd,0% f%+2.1i!)9% .7fa% 3.3i% 5.0hd%+hi% f% 5.4d=or-shtkj[-o0% 4hd9%+9.10f%-ia%+3.6hd#%+hd%+hde%-.0u!v%-3.4hu% .10hi[shq%+8.1f%-4s7!n`", 7993, 1887.846870789656, -68501, -4655.667925074112, -837975, 887, 26612, 14349.61080559717, -426317, -25092, 1225.2155357249214, -60216, 5060, -3827, -1196, -561511, -7937, 9743, 8963.809962119334, "#-@3,l^lj()0bch$z3b!c#)e^bj"),
sprintf(boba656, "%+.0hd,0% f%+2.1i!)9% .7fa% 3.3i% 5.0hd%+hi% f% 5.4d=or-shtkj[-o0% 4hd9%+9.10f%-ia%+3.6hd#%+hd%+hde%-.0u!v%-3.4hu% .10hi[shq%+8.1f%-4s7!n`", 7993, 1887.846870789656, -68501, -4655.667925074112, -837975, 887, 26612, 14349.61080559717, -426317, -25092, 1225.2155357249214, -60216, 5060, -3827, -1196, -561511, -7937, 9743, 8963.809962119334, "#-@3,l^lj()0bch$z3b!c#)e^bj"));
ck_assert_str_eq(boba656_s21, boba656);
}
END_TEST

START_TEST(bebasik__657) {
char boba657_s21[10000];
char boba657[10000];
ck_assert_int_eq(s21_sprintf(boba657_s21, "% 2.8d%-3u% 7d%-i/%+.7fpd%+5ibc%-1djvkt%+i[%-.0d%+.4hi% 5.5f% 10.3hiiy%+.5i%-igc% 4hi%+9.3hi`%-2.2s", 275246, 482884, -448013, -695081, 5468.397964954133, 56944, 870861, -268059, 738906, -4553, -6038.714345521749, 23726, -840859, 51932, 2412, -593, "u;#9pi9#,&bexoh6[(dw2,r@2c#"),
sprintf(boba657, "% 2.8d%-3u% 7d%-i/%+.7fpd%+5ibc%-1djvkt%+i[%-.0d%+.4hi% 5.5f% 10.3hiiy%+.5i%-igc% 4hi%+9.3hi`%-2.2s", 275246, 482884, -448013, -695081, 5468.397964954133, 56944, 870861, -268059, 738906, -4553, -6038.714345521749, 23726, -840859, 51932, 2412, -593, "u;#9pi9#,&bexoh6[(dw2,r@2c#"));
ck_assert_str_eq(boba657_s21, boba657);
}
END_TEST

START_TEST(bebasik__658) {
char boba658_s21[10000];
char boba658[10000];
ck_assert_int_eq(s21_sprintf(boba658_s21, "%-.9sm%+i/*% 2hi%-.8d%+iowq%-2hd.h% d%-8.0hii%+6.0hd#% hd% hd%+hi", "qy5cz/)nmoyh-sz6rdkpm/.gcqgj", 126184, -19264, 841491, -722526, -22349, -462316, 28713, 7266, 18426, -8180, -13212),
sprintf(boba658, "%-.9sm%+i/*% 2hi%-.8d%+iowq%-2hd.h% d%-8.0hii%+6.0hd#% hd% hd%+hi", "qy5cz/)nmoyh-sz6rdkpm/.gcqgj", 126184, -19264, 841491, -722526, -22349, -462316, 28713, 7266, 18426, -8180, -13212));
ck_assert_str_eq(boba658_s21, boba658);
}
END_TEST

START_TEST(bebasik__659) {
char boba659_s21[10000];
char boba659[10000];
ck_assert_int_eq(s21_sprintf(boba659_s21, "%+.5d%-.10hu[0%-f%-.4hd%+5.6f%-2hil%+1hi% dfg&%-1.7d% 8.1hi%+5d% hd$@g=96% 2.4i% .7f% 8.0hd8bf9%+9ftw0%+9f%+.4hi%+.0hd5% 4hie%+6d%+10.2hd6", -800021, -22902, 16416.53437400157, 30606, -4594.919396318905, 10600, 8641, 887126, -169484, 13283, 468899, 27123, 480180, 1916.034447650508, 14795, 14229.72653732708, 8297.184390456341, -5863, -12929, -2520, 428555, 582),
sprintf(boba659, "%+.5d%-.10hu[0%-f%-.4hd%+5.6f%-2hil%+1hi% dfg&%-1.7d% 8.1hi%+5d% hd$@g=96% 2.4i% .7f% 8.0hd8bf9%+9ftw0%+9f%+.4hi%+.0hd5% 4hie%+6d%+10.2hd6", -800021, -22902, 16416.53437400157, 30606, -4594.919396318905, 10600, 8641, 887126, -169484, 13283, 468899, 27123, 480180, 1916.034447650508, 14795, 14229.72653732708, 8297.184390456341, -5863, -12929, -2520, 428555, 582));
ck_assert_str_eq(boba659_s21, boba659);
}
END_TEST

START_TEST(bebasik__660) {
char boba660_s21[10000];
char boba660[10000];
ck_assert_int_eq(s21_sprintf(boba660_s21, "% fd(qvuf% 4i%+hi2%+6hi%+i%+.4i% 9hd[%-8f%+9i%+8.4d", -2321.1014125815036, -181414, 7920, 27481, -346213, -424197, -6746, -9183.783628780066, -584892, 541649),
sprintf(boba660, "% fd(qvuf% 4i%+hi2%+6hi%+i%+.4i% 9hd[%-8f%+9i%+8.4d", -2321.1014125815036, -181414, 7920, 27481, -346213, -424197, -6746, -9183.783628780066, -584892, 541649));
ck_assert_str_eq(boba660_s21, boba660);
}
END_TEST

START_TEST(bebasik__661) {
char boba661_s21[10000];
char boba661[10000];
ck_assert_int_eq(s21_sprintf(boba661_s21, "%-.10hits%+1.10hid%-.9u%-9hiy%+6.9d%+d%-.7f%-8.5hua%+3.10i%+3.3hi%-.5sq)gno% .0hd^;%-.3d%-hu%-8.4d% hd% 10ilrb*% hib", 6572, -13295, 260799, -2367, -680822, -65141, 238.93683378056755, 25260, 48621, -5629, "t.^b1nnn0[(", 11384, 519910, -22463, -182531, 27905, -554377, 17213),
sprintf(boba661, "%-.10hits%+1.10hid%-.9u%-9hiy%+6.9d%+d%-.7f%-8.5hua%+3.10i%+3.3hi%-.5sq)gno% .0hd^;%-.3d%-hu%-8.4d% hd% 10ilrb*% hib", 6572, -13295, 260799, -2367, -680822, -65141, 238.93683378056755, 25260, 48621, -5629, "t.^b1nnn0[(", 11384, 519910, -22463, -182531, 27905, -554377, 17213));
ck_assert_str_eq(boba661_s21, boba661);
}
END_TEST

START_TEST(bebasik__662) {
char boba662_s21[10000];
char boba662[10000];
ck_assert_int_eq(s21_sprintf(boba662_s21, "%-1.9d% 7.1hd", 705450, -19280),
sprintf(boba662, "%-1.9d% 7.1hd", 705450, -19280));
ck_assert_str_eq(boba662_s21, boba662);
}
END_TEST

START_TEST(bebasik__663) {
char boba663_s21[10000];
char boba663[10000];
ck_assert_int_eq(s21_sprintf(boba663_s21, "%-.6huq(&g%+2i%-7u0%+9i$sb7[%+6.7d% 7hi", -15115, -185580, -96227, -153727, 65499, 1548),
sprintf(boba663, "%-.6huq(&g%+2i%-7u0%+9i$sb7[%+6.7d% 7hi", -15115, -185580, -96227, -153727, 65499, 1548));
ck_assert_str_eq(boba663_s21, boba663);
}
END_TEST

START_TEST(bebasik__664) {
char boba664_s21[10000];
char boba664[10000];
ck_assert_int_eq(s21_sprintf(boba664_s21, "% hi!i,%+2i*%-1.6i%-hi% d%+4ifo% 4hi%+10.4hi", 1519, 62863, -151019, 10286, -821601, 147163, 7247, -24785),
sprintf(boba664, "% hi!i,%+2i*%-1.6i%-hi% d%+4ifo% 4hi%+10.4hi", 1519, 62863, -151019, 10286, -821601, 147163, 7247, -24785));
ck_assert_str_eq(boba664_s21, boba664);
}
END_TEST

START_TEST(bebasik__665) {
char boba665_s21[10000];
char boba665[10000];
ck_assert_int_eq(s21_sprintf(boba665_s21, "% hi2%-hu%-9.1hd% f%+.0hdo% 5.3hi% 7d^)% hi./%-7.8s5e(&%-9ctz%+9f%-4c0%-7cv%+hi/% 1.4f%-c&%+4hi%-d% 9i-3%-1.10hi% .1i%+.4hd0%-8hi%-8f", 21700, 13121, -23078, 15380.874197962106, -21637, -16426, -832473, 3803, "j(", 'w', -3066.1491749663983, '.', '^', 13311, 350.1419786590769, 'v', 7139, 514047, -866735, 21605, 927229, -31787, -5988, 3237.0826002733584),
sprintf(boba665, "% hi2%-hu%-9.1hd% f%+.0hdo% 5.3hi% 7d^)% hi./%-7.8s5e(&%-9ctz%+9f%-4c0%-7cv%+hi/% 1.4f%-c&%+4hi%-d% 9i-3%-1.10hi% .1i%+.4hd0%-8hi%-8f", 21700, 13121, -23078, 15380.874197962106, -21637, -16426, -832473, 3803, "j(", 'w', -3066.1491749663983, '.', '^', 13311, 350.1419786590769, 'v', 7139, 514047, -866735, 21605, 927229, -31787, -5988, 3237.0826002733584));
ck_assert_str_eq(boba665_s21, boba665);
}
END_TEST

START_TEST(bebasik__666) {
char boba666_s21[10000];
char boba666[10000];
ck_assert_int_eq(s21_sprintf(boba666_s21, "% .3i[!lq%+9hd^3%-.4sqaqt^23%-3d%+hd", -152950, -14832, "c/c2,,#l#=31slvvr$r!s4mglk=", 241785, -17025),
sprintf(boba666, "% .3i[!lq%+9hd^3%-.4sqaqt^23%-3d%+hd", -152950, -14832, "c/c2,,#l#=31slvvr$r!s4mglk=", 241785, -17025));
ck_assert_str_eq(boba666_s21, boba666);
}
END_TEST

START_TEST(bebasik__667) {
char boba667_s21[10000];
char boba667[10000];
ck_assert_int_eq(s21_sprintf(boba667_s21, "%+hd8%+1.6d", 23713, -980766),
sprintf(boba667, "%+hd8%+1.6d", 23713, -980766));
ck_assert_str_eq(boba667_s21, boba667);
}
END_TEST

START_TEST(bebasik__668) {
char boba668_s21[10000];
char boba668[10000];
ck_assert_int_eq(s21_sprintf(boba668_s21, "%-4.7f%+4.0hi% 6f%-.6s% .1f%+iw4uv!%+.3hdf%+2.2f%+5.0i% 9hd", -1335.774796696395, 20950, -9201.519841161886, "t", 1168.9451592989906, -794658, -12606, -5057.864497966222, -782781, -20954),
sprintf(boba668, "%-4.7f%+4.0hi% 6f%-.6s% .1f%+iw4uv!%+.3hdf%+2.2f%+5.0i% 9hd", -1335.774796696395, 20950, -9201.519841161886, "t", 1168.9451592989906, -794658, -12606, -5057.864497966222, -782781, -20954));
ck_assert_str_eq(boba668_s21, boba668);
}
END_TEST

START_TEST(bebasik__669) {
char boba669_s21[10000];
char boba669[10000];
ck_assert_int_eq(s21_sprintf(boba669_s21, "% 2d87%-1.10f/&%-5hi%-7c&.%+i%-sn==%+6hd%+4de3%-hin**u%-7.2s% hio8q% 4.1hdqcth6%-.1hd", -273495, 83.50800858213614, -27880, '=', -222556, "!=ctt.bhz953ox", -24008, -543299, -22960, ";^c/wm4a", 10408, 18727, -20772),
sprintf(boba669, "% 2d87%-1.10f/&%-5hi%-7c&.%+i%-sn==%+6hd%+4de3%-hin**u%-7.2s% hio8q% 4.1hdqcth6%-.1hd", -273495, 83.50800858213614, -27880, '=', -222556, "!=ctt.bhz953ox", -24008, -543299, -22960, ";^c/wm4a", 10408, 18727, -20772));
ck_assert_str_eq(boba669_s21, boba669);
}
END_TEST

START_TEST(bebasik__670) {
char boba670_s21[10000];
char boba670[10000];
ck_assert_int_eq(s21_sprintf(boba670_s21, "% hi% i6q% 3.3d%+d23,% hd% il% .8dh%-.1hi%+hd%-.1i%+3hd%-4.0d", 27519, -536409, 158551, -69394, -26584, -181836, -71899, -31558, 23854, 763208, 4453, -316851),
sprintf(boba670, "% hi% i6q% 3.3d%+d23,% hd% il% .8dh%-.1hi%+hd%-.1i%+3hd%-4.0d", 27519, -536409, 158551, -69394, -26584, -181836, -71899, -31558, 23854, 763208, 4453, -316851));
ck_assert_str_eq(boba670_s21, boba670);
}
END_TEST

START_TEST(bebasik__671) {
char boba671_s21[10000];
char boba671[10000];
ck_assert_int_eq(s21_sprintf(boba671_s21, "%+.9hd(% 2fv%+6.10hi!(i%+4i*% 7.9d9%+8.6f3%+10.9hd% hd%+5.3f9% 7hdl%+i6r7% 7hi,52%-.2hd0% hi%+hilr%-5.6hi0% hi)l% 7hd% 4.0fcg%-.1hu2", 1595, 18285.41901865448, -16825, 266472, 880099, -483.7733046042094, 5535, 21072, 17903.59941616273, -7676, 693980, 31323, 26886, -8580, 16720, -19389, -3573, -23299, 2193.2592467195436, -3785),
sprintf(boba671, "%+.9hd(% 2fv%+6.10hi!(i%+4i*% 7.9d9%+8.6f3%+10.9hd% hd%+5.3f9% 7hdl%+i6r7% 7hi,52%-.2hd0% hi%+hilr%-5.6hi0% hi)l% 7hd% 4.0fcg%-.1hu2", 1595, 18285.41901865448, -16825, 266472, 880099, -483.7733046042094, 5535, 21072, 17903.59941616273, -7676, 693980, 31323, 26886, -8580, 16720, -19389, -3573, -23299, 2193.2592467195436, -3785));
ck_assert_str_eq(boba671_s21, boba671);
}
END_TEST

START_TEST(bebasik__672) {
char boba672_s21[10000];
char boba672[10000];
ck_assert_int_eq(s21_sprintf(boba672_s21, "% 2.10hi-% 3.1d,l% .9hi--x[.3%-.1hi3", 25200, -107848, -29465, 7235),
sprintf(boba672, "% 2.10hi-% 3.1d,l% .9hi--x[.3%-.1hi3", 25200, -107848, -29465, 7235));
ck_assert_str_eq(boba672_s21, boba672);
}
END_TEST

START_TEST(bebasik__673) {
char boba673_s21[10000];
char boba673[10000];
ck_assert_int_eq(s21_sprintf(boba673_s21, "%-4.6hu%-6hu0%-.6hitn%+.7d% i", -4670, -18506, 2138, -562518, 527469),
sprintf(boba673, "%-4.6hu%-6hu0%-.6hitn%+.7d% i", -4670, -18506, 2138, -562518, 527469));
ck_assert_str_eq(boba673_s21, boba673);
}
END_TEST

START_TEST(bebasik__674) {
char boba674_s21[10000];
char boba674[10000];
ck_assert_int_eq(s21_sprintf(boba674_s21, "%+7.0it", 821211),
sprintf(boba674, "%+7.0it", 821211));
ck_assert_str_eq(boba674_s21, boba674);
}
END_TEST

START_TEST(bebasik__675) {
char boba675_s21[10000];
char boba675[10000];
ck_assert_int_eq(s21_sprintf(boba675_s21, "%-8.3hu% hi%-8.7d%-.7u%-2f/% .6hd", 8467, -22383, -799468, 596239, -2058.624056977827, -8062),
sprintf(boba675, "%-8.3hu% hi%-8.7d%-.7u%-2f/% .6hd", 8467, -22383, -799468, 596239, -2058.624056977827, -8062));
ck_assert_str_eq(boba675_s21, boba675);
}
END_TEST

START_TEST(bebasik__676) {
char boba676_s21[10000];
char boba676[10000];
ck_assert_int_eq(s21_sprintf(boba676_s21, "%+3.8dclu% 3hi% .8hit6097% hd1i@;#% .6i%+7.9hdb%-.1hdr@wx%+.1d% hd% dq8=%+5.1d%+i% 5hd% i% 4.4hi% .10ii%+1d7-%+3hi", 756387, -12842, 14816, -30590, 331778, 4142, 25700, 903436, 2281, -605033, 217169, 821664, -19384, -20017, 25127, -96893, -524752, 15520),
sprintf(boba676, "%+3.8dclu% 3hi% .8hit6097% hd1i@;#% .6i%+7.9hdb%-.1hdr@wx%+.1d% hd% dq8=%+5.1d%+i% 5hd% i% 4.4hi% .10ii%+1d7-%+3hi", 756387, -12842, 14816, -30590, 331778, 4142, 25700, 903436, 2281, -605033, 217169, 821664, -19384, -20017, 25127, -96893, -524752, 15520));
ck_assert_str_eq(boba676_s21, boba676);
}
END_TEST

START_TEST(bebasik__677) {
char boba677_s21[10000];
char boba677[10000];
ck_assert_int_eq(s21_sprintf(boba677_s21, "%+.9hd% .6hi%-3.5hd%-c% 3dlj%-10.4hul% .2hi%+d.%+.2hi%+.2i%+.0hd% 3.0d`l% 4.3d8-g% 10.7hd!% .0hd0wq%-.2hi;x(%-hdb@(%+.8f0%-.9hi%-8d10v", -23524, 22555, 9272, 'z', -737665, -30284, -7943, 257517, 20629, -85303, -8565, -349001, -277158, -5582, -30701, 30060, 31500, 31103.725843392007, 23173, -255430),
sprintf(boba677, "%+.9hd% .6hi%-3.5hd%-c% 3dlj%-10.4hul% .2hi%+d.%+.2hi%+.2i%+.0hd% 3.0d`l% 4.3d8-g% 10.7hd!% .0hd0wq%-.2hi;x(%-hdb@(%+.8f0%-.9hi%-8d10v", -23524, 22555, 9272, 'z', -737665, -30284, -7943, 257517, 20629, -85303, -8565, -349001, -277158, -5582, -30701, 30060, 31500, 31103.725843392007, 23173, -255430));
ck_assert_str_eq(boba677_s21, boba677);
}
END_TEST

START_TEST(bebasik__678) {
char boba678_s21[10000];
char boba678[10000];
ck_assert_int_eq(s21_sprintf(boba678_s21, "%+.8ih%-2dlu%+7.7d%-d%+f9h% 7.9hdy% i% hd% i7% .5d%+9d%-.7u[%+.8hd/% 1.0dt%+hi%-hi%+9.9hi%+.1i", -176288, 829808, -823636, 347187, 23674.43915152642, 21697, 294588, -10083, -483720, -986034, 82651, -275218, 19281, 489981, 12293, -14768, 10072, 284295),
sprintf(boba678, "%+.8ih%-2dlu%+7.7d%-d%+f9h% 7.9hdy% i% hd% i7% .5d%+9d%-.7u[%+.8hd/% 1.0dt%+hi%-hi%+9.9hi%+.1i", -176288, 829808, -823636, 347187, 23674.43915152642, 21697, 294588, -10083, -483720, -986034, 82651, -275218, 19281, 489981, 12293, -14768, 10072, 284295));
ck_assert_str_eq(boba678_s21, boba678);
}
END_TEST

START_TEST(bebasik__679) {
char boba679_s21[10000];
char boba679[10000];
ck_assert_int_eq(s21_sprintf(boba679_s21, "% 5f", 19260.25276998015),
sprintf(boba679, "% 5f", 19260.25276998015));
ck_assert_str_eq(boba679_s21, boba679);
}
END_TEST

START_TEST(bebasik__680) {
char boba680_s21[10000];
char boba680[10000];
ck_assert_int_eq(s21_sprintf(boba680_s21, "% .10hig70)*%-.8id@q% hdy% 6.10de%-4hic2f% .9hdd5l% 5.3hd%-2.2sa%-3.4hu", 20168, -815966, -5266, -316774, 8683, 11257, 7830, "j5mz", -26711),
sprintf(boba680, "% .10hig70)*%-.8id@q% hdy% 6.10de%-4hic2f% .9hdd5l% 5.3hd%-2.2sa%-3.4hu", 20168, -815966, -5266, -316774, 8683, 11257, 7830, "j5mz", -26711));
ck_assert_str_eq(boba680_s21, boba680);
}
END_TEST

START_TEST(bebasik__681) {
char boba681_s21[10000];
char boba681[10000];
ck_assert_int_eq(s21_sprintf(boba681_s21, "%-4.2hu%+hi%+8d8% 3i", -20177, 5940, 971560, 5760),
sprintf(boba681, "%-4.2hu%+hi%+8d8% 3i", -20177, 5940, 971560, 5760));
ck_assert_str_eq(boba681_s21, boba681);
}
END_TEST

START_TEST(bebasik__682) {
char boba682_s21[10000];
char boba682[10000];
ck_assert_int_eq(s21_sprintf(boba682_s21, "%-.7hd=%+ic$.8e%+.4i(%-7.3st%+.1iik8% 4hi% .6hiu(% .7hi%-.3hi% 1.5i% 3il9", -28343, -398109, -966609, "tuiy3f#=e^jzrobf9j2j2.8n", -144849, 3389, 23753, 5510, -8435, 722315, 733222),
sprintf(boba682, "%-.7hd=%+ic$.8e%+.4i(%-7.3st%+.1iik8% 4hi% .6hiu(% .7hi%-.3hi% 1.5i% 3il9", -28343, -398109, -966609, "tuiy3f#=e^jzrobf9j2j2.8n", -144849, 3389, 23753, 5510, -8435, 722315, 733222));
ck_assert_str_eq(boba682_s21, boba682);
}
END_TEST

START_TEST(bebasik__683) {
char boba683_s21[10000];
char boba683[10000];
ck_assert_int_eq(s21_sprintf(boba683_s21, "% .4im% .10f% hi% hix% ib%+.2d%-.9d%+3.7d%+1.10d%+4f%-8.9hd", -507502, -21414.972866731467, 24393, -10691, -699128, 364841, 495740, -489497, 634448, -1133.9976282448872, -29851),
sprintf(boba683, "% .4im% .10f% hi% hix% ib%+.2d%-.9d%+3.7d%+1.10d%+4f%-8.9hd", -507502, -21414.972866731467, 24393, -10691, -699128, 364841, 495740, -489497, 634448, -1133.9976282448872, -29851));
ck_assert_str_eq(boba683_s21, boba683);
}
END_TEST

START_TEST(bebasik__684) {
char boba684_s21[10000];
char boba684[10000];
ck_assert_int_eq(s21_sprintf(boba684_s21, "% 2hdi", 28135),
sprintf(boba684, "% 2hdi", 28135));
ck_assert_str_eq(boba684_s21, boba684);
}
END_TEST

START_TEST(bebasik__685) {
char boba685_s21[10000];
char boba685[10000];
ck_assert_int_eq(s21_sprintf(boba685_s21, "% .1i% hi#jrvu%+9.7dy%-.0hi%+7.6hd1%-.5hd%-f%-hi^%+7hd8%+5.7hdl1% 4hd(%+.1f@f% hd%-10.1huz%-.10s%+hdx*5@% 10iq%-1.6dxzp% .1hi%+f% f%+8hdr%-10fw% i", 746593, -23819, -158582, -20394, 2258, -18949, -417.4779014653062, -12268, 27877, -15841, -1203, 4385.15113922187, -8249, 16157, "=dbp2e/1mh*()^s7,6w/6b", -13584, -834380, 847693, -31981, -5898.043786882329, -103.7650748636789, 12279, -6324.300610644007, 27286),
sprintf(boba685, "% .1i% hi#jrvu%+9.7dy%-.0hi%+7.6hd1%-.5hd%-f%-hi^%+7hd8%+5.7hdl1% 4hd(%+.1f@f% hd%-10.1huz%-.10s%+hdx*5@% 10iq%-1.6dxzp% .1hi%+f% f%+8hdr%-10fw% i", 746593, -23819, -158582, -20394, 2258, -18949, -417.4779014653062, -12268, 27877, -15841, -1203, 4385.15113922187, -8249, 16157, "=dbp2e/1mh*()^s7,6w/6b", -13584, -834380, 847693, -31981, -5898.043786882329, -103.7650748636789, 12279, -6324.300610644007, 27286));
ck_assert_str_eq(boba685_s21, boba685);
}
END_TEST

START_TEST(bebasik__686) {
char boba686_s21[10000];
char boba686[10000];
ck_assert_int_eq(s21_sprintf(boba686_s21, "%+7hi1$[% 7i%+4hi% d% 9.10hd% .8daj%-1.1hi%-f", -30365, -325152, -22529, -551987, 822, -391105, -27373, 1542.1912651128182),
sprintf(boba686, "%+7hi1$[% 7i%+4hi% d% 9.10hd% .8daj%-1.1hi%-f", -30365, -325152, -22529, -551987, 822, -391105, -27373, 1542.1912651128182));
ck_assert_str_eq(boba686_s21, boba686);
}
END_TEST

START_TEST(bebasik__687) {
char boba687_s21[10000];
char boba687[10000];
ck_assert_int_eq(s21_sprintf(boba687_s21, "% hi)r%+.7hi;% .0d0ki% 2ft%-hu%+8hiq$@%+8hd/8%+hi%-.3hd% 10d)/#p9% 2.0hi% 5i&%+.9hi", 10952, 28829, -602773, 2720.98358748259, -14906, -13301, -19653, 14796, -1701, -403105, -17689, -15394, -18289),
sprintf(boba687, "% hi)r%+.7hi;% .0d0ki% 2ft%-hu%+8hiq$@%+8hd/8%+hi%-.3hd% 10d)/#p9% 2.0hi% 5i&%+.9hi", 10952, 28829, -602773, 2720.98358748259, -14906, -13301, -19653, 14796, -1701, -403105, -17689, -15394, -18289));
ck_assert_str_eq(boba687_s21, boba687);
}
END_TEST

START_TEST(bebasik__688) {
char boba688_s21[10000];
char boba688[10000];
ck_assert_int_eq(s21_sprintf(boba688_s21, "%+10d% 9.1hi% .9dgh6%+3.8hdf% 10i% .9hiy% 8hd7% 9.1f%-4hd$%+f*`% 6.9d8%-5si% hd%-.10dbn#", 842696, 9960, 914466, -27956, -81682, -28774, -12780, 15467.9347832142, 5317, -1505.4036525043055, 70891, "[$nom*#7$(,@r2f", -551, 719808),
sprintf(boba688, "%+10d% 9.1hi% .9dgh6%+3.8hdf% 10i% .9hiy% 8hd7% 9.1f%-4hd$%+f*`% 6.9d8%-5si% hd%-.10dbn#", 842696, 9960, 914466, -27956, -81682, -28774, -12780, 15467.9347832142, 5317, -1505.4036525043055, 70891, "[$nom*#7$(,@r2f", -551, 719808));
ck_assert_str_eq(boba688_s21, boba688);
}
END_TEST

START_TEST(bebasik__689) {
char boba689_s21[10000];
char boba689[10000];
ck_assert_int_eq(s21_sprintf(boba689_s21, "%+hdc%-.4hdcob%+6hi%-8.7hu%-.7hdt", -15020, 16671, 14974, -22384, 11126),
sprintf(boba689, "%+hdc%-.4hdcob%+6hi%-8.7hu%-.7hdt", -15020, 16671, 14974, -22384, 11126));
ck_assert_str_eq(boba689_s21, boba689);
}
END_TEST

START_TEST(bebasik__690) {
char boba690_s21[10000];
char boba690[10000];
ck_assert_int_eq(s21_sprintf(boba690_s21, "% .4hisxt(% 3hd%-6u0%-.1s*3-,%+8.1hd% 8.7hd%+.2ifp", -28573, -4872, -737056, "l1m;3t7xg3-n!yy(@n27x4cg=t7q", -3928, 1151, 150092),
sprintf(boba690, "% .4hisxt(% 3hd%-6u0%-.1s*3-,%+8.1hd% 8.7hd%+.2ifp", -28573, -4872, -737056, "l1m;3t7xg3-n!yy(@n27x4cg=t7q", -3928, 1151, 150092));
ck_assert_str_eq(boba690_s21, boba690);
}
END_TEST

START_TEST(bebasik__691) {
char boba691_s21[10000];
char boba691[10000];
ck_assert_int_eq(s21_sprintf(boba691_s21, "%-.3hd;z)%-.3u", 16118, -764518),
sprintf(boba691, "%-.3hd;z)%-.3u", 16118, -764518));
ck_assert_str_eq(boba691_s21, boba691);
}
END_TEST

START_TEST(bebasik__692) {
char boba692_s21[10000];
char boba692[10000];
ck_assert_int_eq(s21_sprintf(boba692_s21, "%+hd% .3hi%-4hu%-.4hu% i%+2.8f%+.7i% 2hi;e%+5hip6%+d#et89%-i%-.0hi%+10.1hi&in% 8i% 8hi%-10.8dg%+8.1i&% .3hi% 2d", -14840, 31941, 31255, -5726, 936244, -1961.3289034259128, 443542, 14924, -18350, -256949, -420106, -12881, -18145, -767758, -20912, -740327, 202019, -4831, 889562),
sprintf(boba692, "%+hd% .3hi%-4hu%-.4hu% i%+2.8f%+.7i% 2hi;e%+5hip6%+d#et89%-i%-.0hi%+10.1hi&in% 8i% 8hi%-10.8dg%+8.1i&% .3hi% 2d", -14840, 31941, 31255, -5726, 936244, -1961.3289034259128, 443542, 14924, -18350, -256949, -420106, -12881, -18145, -767758, -20912, -740327, 202019, -4831, 889562));
ck_assert_str_eq(boba692_s21, boba692);
}
END_TEST

START_TEST(bebasik__693) {
char boba693_s21[10000];
char boba693[10000];
ck_assert_int_eq(s21_sprintf(boba693_s21, "% .2fiw%+8hi", -2812.741497274895, -29547),
sprintf(boba693, "% .2fiw%+8hi", -2812.741497274895, -29547));
ck_assert_str_eq(boba693_s21, boba693);
}
END_TEST

START_TEST(bebasik__694) {
char boba694_s21[10000];
char boba694[10000];
ck_assert_int_eq(s21_sprintf(boba694_s21, "%+.7dpl% 8hd% .1hi(%+.9hi*%-8.2hi9%-4f%+3.6hi%+.3hd", 673954, 15302, 3839, -24159, -15556, -11568.099873806601, -560, 16590),
sprintf(boba694, "%+.7dpl% 8hd% .1hi(%+.9hi*%-8.2hi9%-4f%+3.6hi%+.3hd", 673954, 15302, 3839, -24159, -15556, -11568.099873806601, -560, 16590));
ck_assert_str_eq(boba694_s21, boba694);
}
END_TEST

START_TEST(bebasik__695) {
char boba695_s21[10000];
char boba695[10000];
ck_assert_int_eq(s21_sprintf(boba695_s21, "%-idc)% 7hix%+5hd%-9d", -225303, 6414, 14304, 4050),
sprintf(boba695, "%-idc)% 7hix%+5hd%-9d", -225303, 6414, 14304, 4050));
ck_assert_str_eq(boba695_s21, boba695);
}
END_TEST

START_TEST(bebasik__696) {
char boba696_s21[10000];
char boba696[10000];
ck_assert_int_eq(s21_sprintf(boba696_s21, "%-4hi%-10f%-dk5&% .2f% fm[$[%-9s", 20013, -12588.31238129206, 139434, -10415.098788022526, -213.70896969806765, "t;b0*c-*ui;@"),
sprintf(boba696, "%-4hi%-10f%-dk5&% .2f% fm[$[%-9s", 20013, -12588.31238129206, 139434, -10415.098788022526, -213.70896969806765, "t;b0*c-*ui;@"));
ck_assert_str_eq(boba696_s21, boba696);
}
END_TEST

START_TEST(bebasik__697) {
char boba697_s21[10000];
char boba697[10000];
ck_assert_int_eq(s21_sprintf(boba697_s21, "%-3hiz% .10i3%-.9hi4% 4.3fbtz", -2486, -903909, -18381, -5148.400029743307),
sprintf(boba697, "%-3hiz% .10i3%-.9hi4% 4.3fbtz", -2486, -903909, -18381, -5148.400029743307));
ck_assert_str_eq(boba697_s21, boba697);
}
END_TEST

START_TEST(bebasik__698) {
char boba698_s21[10000];
char boba698[10000];
ck_assert_int_eq(s21_sprintf(boba698_s21, "%-hdg%-6c% 10iu%-2.2u%-hi%+hd*4w`/*-% 5i% 6f!`.% dr% 8i%+4hi61%-.0hu% 8.4hi1a% 2f% 6.8hd;% hi%-.7huz% hi%-f%+.9hd%+hd% .4f% .5i", -1310, 'z', 26645, 425087, 1998, -9849, -384855, -3482.74410357666, 104026, 959589, -23999, -12272, -31889, -8461.970227774833, 22228, 23459, -2571, 5928, 662.1021365714298, -6727, -2323, -1237.9659742774145, -998860),
sprintf(boba698, "%-hdg%-6c% 10iu%-2.2u%-hi%+hd*4w`/*-% 5i% 6f!`.% dr% 8i%+4hi61%-.0hu% 8.4hi1a% 2f% 6.8hd;% hi%-.7huz% hi%-f%+.9hd%+hd% .4f% .5i", -1310, 'z', 26645, 425087, 1998, -9849, -384855, -3482.74410357666, 104026, 959589, -23999, -12272, -31889, -8461.970227774833, 22228, 23459, -2571, 5928, 662.1021365714298, -6727, -2323, -1237.9659742774145, -998860));
ck_assert_str_eq(boba698_s21, boba698);
}
END_TEST

START_TEST(bebasik__699) {
char boba699_s21[10000];
char boba699[10000];
ck_assert_int_eq(s21_sprintf(boba699_s21, "% hiul%+.9hi*cf,%-hih%-.4f%-cn`%+5hi%-f%+.10hd% 5.5i.`% 3.2f%-hi% i% 7.2f%-.0fd^%-.3d%-2hif;5)js%+3hi% hd", -21677, 8282, 17906, 4962.0491974211, 'z', 10768, -15307.29745938735, -7078, -890356, -13400.438369400568, 30719, 599442, 4839.199104864018, -1200.6448621136162, 302028, -8186, 20566, -19439),
sprintf(boba699, "% hiul%+.9hi*cf,%-hih%-.4f%-cn`%+5hi%-f%+.10hd% 5.5i.`% 3.2f%-hi% i% 7.2f%-.0fd^%-.3d%-2hif;5)js%+3hi% hd", -21677, 8282, 17906, 4962.0491974211, 'z', 10768, -15307.29745938735, -7078, -890356, -13400.438369400568, 30719, 599442, 4839.199104864018, -1200.6448621136162, 302028, -8186, 20566, -19439));
ck_assert_str_eq(boba699_s21, boba699);
}
END_TEST

START_TEST(bebasik__700) {
char boba700_s21[10000];
char boba700[10000];
ck_assert_int_eq(s21_sprintf(boba700_s21, "% 7i% 9.5hi#j%+.7f1%+.4i!c% hiod=bt$%+2hd%-.10hd4% 9.5hd4% 10d%-hu*%+5.0hi%+.7f%-5ur", 206450, -31911, 3292.4122676045304, -264996, -14275, -26252, 6448, -12118, 421860, -884, 10744, -6935.868123725035, -362120),
sprintf(boba700, "% 7i% 9.5hi#j%+.7f1%+.4i!c% hiod=bt$%+2hd%-.10hd4% 9.5hd4% 10d%-hu*%+5.0hi%+.7f%-5ur", 206450, -31911, 3292.4122676045304, -264996, -14275, -26252, 6448, -12118, 421860, -884, 10744, -6935.868123725035, -362120));
ck_assert_str_eq(boba700_s21, boba700);
}
END_TEST

START_TEST(bebasik__701) {
char boba701_s21[10000];
char boba701[10000];
ck_assert_int_eq(s21_sprintf(boba701_s21, "%+1.2d% fcso%-10i%-5.5hu-e%-s%-u4% 1fj%+.7d% .9hd$%+f7% 4.9i*%-hdvw1@% 8.10hi%-.10hu%+6i3%-5hu", -483810, -19809.901340163702, 244965, -3407, "1)2p", -954914, 11525.390727056509, -283337, 4947, 2004.836200261049, 582573, -767, -27686, -16201, 687982, 4080),
sprintf(boba701, "%+1.2d% fcso%-10i%-5.5hu-e%-s%-u4% 1fj%+.7d% .9hd$%+f7% 4.9i*%-hdvw1@% 8.10hi%-.10hu%+6i3%-5hu", -483810, -19809.901340163702, 244965, -3407, "1)2p", -954914, 11525.390727056509, -283337, 4947, 2004.836200261049, 582573, -767, -27686, -16201, 687982, 4080));
ck_assert_str_eq(boba701_s21, boba701);
}
END_TEST

START_TEST(bebasik__702) {
char boba702_s21[10000];
char boba702[10000];
ck_assert_int_eq(s21_sprintf(boba702_s21, "%-5.4hdm% .9i(03$!;% .2db%+9.1hd[%+5hd% 9hizn%-hd%-5.4hu1,% 5.8hi% 7.5hi% 8.0duq&k!%+i% 3.10hi%-.5hu-#7fq", 20786, -144569, -929896, -21198, 4770, -27654, -2269, -24674, 13658, -25977, 344895, -758606, -6722, -1410),
sprintf(boba702, "%-5.4hdm% .9i(03$!;% .2db%+9.1hd[%+5hd% 9hizn%-hd%-5.4hu1,% 5.8hi% 7.5hi% 8.0duq&k!%+i% 3.10hi%-.5hu-#7fq", 20786, -144569, -929896, -21198, 4770, -27654, -2269, -24674, 13658, -25977, 344895, -758606, -6722, -1410));
ck_assert_str_eq(boba702_s21, boba702);
}
END_TEST

START_TEST(bebasik__703) {
char boba703_s21[10000];
char boba703[10000];
ck_assert_int_eq(s21_sprintf(boba703_s21, "%-d% d% 1hdm% 2f% hi% ih%-hd3k6% 7hd%+hd% 5.2i3yt% hd% .5i%+.6i%+1hi!o%+f%+.9hd(!% 4f/% 6.1d% 4hd)it%-6.8hdhr", -486588, 860859, -12822, -10895.224965237261, -4800, 517175, 3852, -26184, 5825, -676143, -18087, -258866, 557739, 4909, -12.682533330636051, -26609, -22562.064905571013, 685377, 17587, -30878),
sprintf(boba703, "%-d% d% 1hdm% 2f% hi% ih%-hd3k6% 7hd%+hd% 5.2i3yt% hd% .5i%+.6i%+1hi!o%+f%+.9hd(!% 4f/% 6.1d% 4hd)it%-6.8hdhr", -486588, 860859, -12822, -10895.224965237261, -4800, 517175, 3852, -26184, 5825, -676143, -18087, -258866, 557739, 4909, -12.682533330636051, -26609, -22562.064905571013, 685377, 17587, -30878));
ck_assert_str_eq(boba703_s21, boba703);
}
END_TEST

START_TEST(bebasik__704) {
char boba704_s21[10000];
char boba704[10000];
ck_assert_int_eq(s21_sprintf(boba704_s21, "%-.4sat(% dvh@d%-.8hd%-.5sc%+hi%+.6hdy%-3hi%-3.0fo% .8hd%+7io%+dt%-hi&q%-1.9hi% 8hd!0t8;h", "$u7#`d5tyvu@4tlke2yv7p#", -274368, 2, "6v&.2=vt", 31086, -17041, -19447, 22276.055861524466, 14362, -698989, 336096, 14071, 6599, 18575),
sprintf(boba704, "%-.4sat(% dvh@d%-.8hd%-.5sc%+hi%+.6hdy%-3hi%-3.0fo% .8hd%+7io%+dt%-hi&q%-1.9hi% 8hd!0t8;h", "$u7#`d5tyvu@4tlke2yv7p#", -274368, 2, "6v&.2=vt", 31086, -17041, -19447, 22276.055861524466, 14362, -698989, 336096, 14071, 6599, 18575));
ck_assert_str_eq(boba704_s21, boba704);
}
END_TEST

START_TEST(bebasik__705) {
char boba705_s21[10000];
char boba705[10000];
ck_assert_int_eq(s21_sprintf(boba705_s21, "% .4f% 3.9hd%-hu0% hd% 6fm", -10865.195547689398, 9508, -27046, -8096, -21418.131064294284),
sprintf(boba705, "% .4f% 3.9hd%-hu0% hd% 6fm", -10865.195547689398, 9508, -27046, -8096, -21418.131064294284));
ck_assert_str_eq(boba705_s21, boba705);
}
END_TEST

START_TEST(bebasik__706) {
char boba706_s21[10000];
char boba706[10000];
ck_assert_int_eq(s21_sprintf(boba706_s21, "%+4.2hd% hip%+.7hd%+hi% .4hd%+d% 4f%-2.8hip%+.3f%-.5hi%+.0dy%-9hu%-5.2hd%+.10i98l% 3hi%+1.1d%-i$o%-9hd% 3.4hd/t4v%+1.2i%+.6f% 9.2i%-.1fw2#za", -4948, 30397, -2842, 15645, 17163, -844631, 4183.052870198939, -2255, -2052.61060488746, 27808, 437271, 18503, 10938, 945142, -24925, -895268, -847981, -14853, -8954, -140752, -11114.975800493648, 934684, -8742.76695272547),
sprintf(boba706, "%+4.2hd% hip%+.7hd%+hi% .4hd%+d% 4f%-2.8hip%+.3f%-.5hi%+.0dy%-9hu%-5.2hd%+.10i98l% 3hi%+1.1d%-i$o%-9hd% 3.4hd/t4v%+1.2i%+.6f% 9.2i%-.1fw2#za", -4948, 30397, -2842, 15645, 17163, -844631, 4183.052870198939, -2255, -2052.61060488746, 27808, 437271, 18503, 10938, 945142, -24925, -895268, -847981, -14853, -8954, -140752, -11114.975800493648, 934684, -8742.76695272547));
ck_assert_str_eq(boba706_s21, boba706);
}
END_TEST

START_TEST(bebasik__707) {
char boba707_s21[10000];
char boba707[10000];
ck_assert_int_eq(s21_sprintf(boba707_s21, "%+.8hi5%+9ir%+3fi9cslo$h% .1hi%-hdmn/% 7.8hi$% 4hd%-9.4hu% .5d%+2.2i&3k% hiq", 25716, 931911, 3138.8350867028453, 1221, -19348, -22504, 13456, -9228, 779891, 74403, -14483),
sprintf(boba707, "%+.8hi5%+9ir%+3fi9cslo$h% .1hi%-hdmn/% 7.8hi$% 4hd%-9.4hu% .5d%+2.2i&3k% hiq", 25716, 931911, 3138.8350867028453, 1221, -19348, -22504, 13456, -9228, 779891, 74403, -14483));
ck_assert_str_eq(boba707_s21, boba707);
}
END_TEST

START_TEST(bebasik__708) {
char boba708_s21[10000];
char boba708[10000];
ck_assert_int_eq(s21_sprintf(boba708_s21, "% .5hd% 9.7d%+2hi)eo$b% .10i% 8hd!v0% .0hd,% f% hd% 5.4ik%+.2d%+9.0hdnh%-7.7iz% 6hdm% 1.7fw%-4.2u% 5hdd%+5.9f%-4.4s%-f% .7hig9%-7.5d%+10d)ju@%-s$", 22165, 968498, 15542, 718217, -17080, -24577, -5320.08885190392, -27042, 42347, 311876, 27711, 484231, 12099, 834.5032047536251, -653392, 27750, -16012.45976310814, "yzzzw^u0kiy#z", -2265.69458882205, 10356, -977027, 785398, "8==)&1/2nmg/l/wnug"),
sprintf(boba708, "% .5hd% 9.7d%+2hi)eo$b% .10i% 8hd!v0% .0hd,% f% hd% 5.4ik%+.2d%+9.0hdnh%-7.7iz% 6hdm% 1.7fw%-4.2u% 5hdd%+5.9f%-4.4s%-f% .7hig9%-7.5d%+10d)ju@%-s$", 22165, 968498, 15542, 718217, -17080, -24577, -5320.08885190392, -27042, 42347, 311876, 27711, 484231, 12099, 834.5032047536251, -653392, 27750, -16012.45976310814, "yzzzw^u0kiy#z", -2265.69458882205, 10356, -977027, 785398, "8==)&1/2nmg/l/wnug"));
ck_assert_str_eq(boba708_s21, boba708);
}
END_TEST

START_TEST(bebasik__709) {
char boba709_s21[10000];
char boba709[10000];
ck_assert_int_eq(s21_sprintf(boba709_s21, "% 10d%-5.5hi% 6.0hd6=^% f(% 4.4hdh%+10.5i", 93117, 3965, -23441, 19992.730222036847, 2084, -600102),
sprintf(boba709, "% 10d%-5.5hi% 6.0hd6=^% f(% 4.4hdh%+10.5i", 93117, 3965, -23441, 19992.730222036847, 2084, -600102));
ck_assert_str_eq(boba709_s21, boba709);
}
END_TEST

START_TEST(bebasik__710) {
char boba710_s21[10000];
char boba710[10000];
ck_assert_int_eq(s21_sprintf(boba710_s21, "%-8d% .8hd%-hi-%-1hi%-4hi!%+1hd%-s%-2hu% 3hi%-4.10huc3% 7i%-6hi%-.4hd%+.9hd%+7.8hd(%-hin% 1f% 4.9i", -978273, 16536, -29540, 8186, 27456, 18448, "x0[$`fn`@2aw42abpo`2vj16f(", -16955, -4918, -17840, 587516, 20494, -20717, 21704, 14095, -17026, 6259.888048775328, -417451),
sprintf(boba710, "%-8d% .8hd%-hi-%-1hi%-4hi!%+1hd%-s%-2hu% 3hi%-4.10huc3% 7i%-6hi%-.4hd%+.9hd%+7.8hd(%-hin% 1f% 4.9i", -978273, 16536, -29540, 8186, 27456, 18448, "x0[$`fn`@2aw42abpo`2vj16f(", -16955, -4918, -17840, 587516, 20494, -20717, 21704, 14095, -17026, 6259.888048775328, -417451));
ck_assert_str_eq(boba710_s21, boba710);
}
END_TEST

START_TEST(bebasik__711) {
char boba711_s21[10000];
char boba711[10000];
ck_assert_int_eq(s21_sprintf(boba711_s21, "%-4.5hu-c% 5d%-.6s2/%-5.7s%+.0d3y%+hd", -16278, 563606, "be", "yz/@/c[*v5,", -129410, -2781),
sprintf(boba711, "%-4.5hu-c% 5d%-.6s2/%-5.7s%+.0d3y%+hd", -16278, 563606, "be", "yz/@/c[*v5,", -129410, -2781));
ck_assert_str_eq(boba711_s21, boba711);
}
END_TEST

START_TEST(bebasik__712) {
char boba712_s21[10000];
char boba712[10000];
ck_assert_int_eq(s21_sprintf(boba712_s21, "%+.10hi%-5.5f5)%+4hi%+4.9hi%+8.6d%-2u%-.4s=,%+.3hi%-3dp-% .8i%+1.5hic% 1.5fw%+8d%+7hdw%-.7f% 3dz%-9.4hd;%-.8s", 12060, 25175.60744897709, 4003, 19898, -467671, 212731, "wlqd2p9^jp2x1a7a@dt^v", -3442, -826740, -139091, 11559, 14012.384620662704, 951769, 14426, -27985.8094708453, 930679, -23508, "w,x01wl0sw@j#(9"),
sprintf(boba712, "%+.10hi%-5.5f5)%+4hi%+4.9hi%+8.6d%-2u%-.4s=,%+.3hi%-3dp-% .8i%+1.5hic% 1.5fw%+8d%+7hdw%-.7f% 3dz%-9.4hd;%-.8s", 12060, 25175.60744897709, 4003, 19898, -467671, 212731, "wlqd2p9^jp2x1a7a@dt^v", -3442, -826740, -139091, 11559, 14012.384620662704, 951769, 14426, -27985.8094708453, 930679, -23508, "w,x01wl0sw@j#(9"));
ck_assert_str_eq(boba712_s21, boba712);
}
END_TEST

START_TEST(bebasik__713) {
char boba713_s21[10000];
char boba713[10000];
ck_assert_int_eq(s21_sprintf(boba713_s21, "%-2huh% .3hi5m%-10.6d%-hd% .2hi", -9065, 17554, 622820, -26427, -1893),
sprintf(boba713, "%-2huh% .3hi5m%-10.6d%-hd% .2hi", -9065, 17554, 622820, -26427, -1893));
ck_assert_str_eq(boba713_s21, boba713);
}
END_TEST

START_TEST(bebasik__714) {
char boba714_s21[10000];
char boba714[10000];
ck_assert_int_eq(s21_sprintf(boba714_s21, "% .10hd%+.4d% 8d% 6hi`%-9.3hi%+1d%-10hu%+6hd% 5d%-.2s%+9.9hd%+9i%+it`", 21342, -621, 807574, -16933, -18425, -287504, -19567, -16496, 73874, "g4nj4$4w0&", 923, 404106, -150),
sprintf(boba714, "% .10hd%+.4d% 8d% 6hi`%-9.3hi%+1d%-10hu%+6hd% 5d%-.2s%+9.9hd%+9i%+it`", 21342, -621, 807574, -16933, -18425, -287504, -19567, -16496, 73874, "g4nj4$4w0&", 923, 404106, -150));
ck_assert_str_eq(boba714_s21, boba714);
}
END_TEST

START_TEST(bebasik__715) {
char boba715_s21[10000];
char boba715[10000];
ck_assert_int_eq(s21_sprintf(boba715_s21, "% 7.10f6% d)m%+2ikvlus%+2hd% .0hi^)`-1ph%+2.6hi%+i% 3ih% hd2.h%+10.2i%+10.6hdr%-hi/% .8hi;@;[% .0hd%+2.8dw% .7f;c[% 3.9hiv%+.10d%+.0f%+.0hds1%+f5$j=c", 1974.5258431557104, 122683, -376058, -3834, -20848, 17988, 276377, 592242, -8690, -5722, -2042, 4226, -14409, -29559, -298553, 355.10496200764294, 27096, 302185, -14657.290574302177, 21522, 2832.1951738537286),
sprintf(boba715, "% 7.10f6% d)m%+2ikvlus%+2hd% .0hi^)`-1ph%+2.6hi%+i% 3ih% hd2.h%+10.2i%+10.6hdr%-hi/% .8hi;@;[% .0hd%+2.8dw% .7f;c[% 3.9hiv%+.10d%+.0f%+.0hds1%+f5$j=c", 1974.5258431557104, 122683, -376058, -3834, -20848, 17988, 276377, 592242, -8690, -5722, -2042, 4226, -14409, -29559, -298553, 355.10496200764294, 27096, 302185, -14657.290574302177, 21522, 2832.1951738537286));
ck_assert_str_eq(boba715_s21, boba715);
}
END_TEST

START_TEST(bebasik__716) {
char boba716_s21[10000];
char boba716[10000];
ck_assert_int_eq(s21_sprintf(boba716_s21, "%-10hi%-2.5hi% 6hih2%-3.5s% 4hd*% du%+hd%+1hds", 7123, 14879, 13079, "50ou$eng4", -16160, -702574, -6258, -25578),
sprintf(boba716, "%-10hi%-2.5hi% 6hih2%-3.5s% 4hd*% du%+hd%+1hds", 7123, 14879, 13079, "50ou$eng4", -16160, -702574, -6258, -25578));
ck_assert_str_eq(boba716_s21, boba716);
}
END_TEST

START_TEST(bebasik__717) {
char boba717_s21[10000];
char boba717[10000];
ck_assert_int_eq(s21_sprintf(boba717_s21, "%+.0hd%+7d%+9i@h*4%+9hi% hi%+7hi(*ike%-7hi% .6i*% 10i%-4.9hd5if8%+.7i%-.6hu%-.0hi65%-.4hu%+6i$i*%-5u%-10d%+i-6.1x% 2.4ic)g% 7hd-2e4w&%-10d-%+.1hi!`[2", 21699, 430000, -506275, 21732, -30091, -19624, 5115, -224657, 425194, -25048, 421773, 3573, -30197, 4800, 428193, -74156, -445045, -39593, 218625, 21511, -348723, 7852),
sprintf(boba717, "%+.0hd%+7d%+9i@h*4%+9hi% hi%+7hi(*ike%-7hi% .6i*% 10i%-4.9hd5if8%+.7i%-.6hu%-.0hi65%-.4hu%+6i$i*%-5u%-10d%+i-6.1x% 2.4ic)g% 7hd-2e4w&%-10d-%+.1hi!`[2", 21699, 430000, -506275, 21732, -30091, -19624, 5115, -224657, 425194, -25048, 421773, 3573, -30197, 4800, 428193, -74156, -445045, -39593, 218625, 21511, -348723, 7852));
ck_assert_str_eq(boba717_s21, boba717);
}
END_TEST

START_TEST(bebasik__718) {
char boba718_s21[10000];
char boba718[10000];
ck_assert_int_eq(s21_sprintf(boba718_s21, "%-i%-3.4hi(qy% d% 4.8d% 6i.% .10f", -312976, 7740, 608994, 240095, -53260, -16750.816329897505),
sprintf(boba718, "%-i%-3.4hi(qy% d% 4.8d% 6i.% .10f", -312976, 7740, 608994, 240095, -53260, -16750.816329897505));
ck_assert_str_eq(boba718_s21, boba718);
}
END_TEST

START_TEST(bebasik__719) {
char boba719_s21[10000];
char boba719[10000];
ck_assert_int_eq(s21_sprintf(boba719_s21, "%+.6him%-.6hu4m% 5hi,p7%+8.3f#%-10dr@% 3.6f)jj%+1.9i", -19221, 24060, -18065, 19232.59581234776, -506122, -2193.0666055443385, 804212),
sprintf(boba719, "%+.6him%-.6hu4m% 5hi,p7%+8.3f#%-10dr@% 3.6f)jj%+1.9i", -19221, 24060, -18065, 19232.59581234776, -506122, -2193.0666055443385, 804212));
ck_assert_str_eq(boba719_s21, boba719);
}
END_TEST

START_TEST(bebasik__720) {
char boba720_s21[10000];
char boba720[10000];
ck_assert_int_eq(s21_sprintf(boba720_s21, "%+.5hd%-c% hd% .4d%+f^k%+3.8f%+7d", 19655, 'k', 1361, -804597, 1232.5184789786902, -16743.223048501874, 277377),
sprintf(boba720, "%+.5hd%-c% hd% .4d%+f^k%+3.8f%+7d", 19655, 'k', 1361, -804597, 1232.5184789786902, -16743.223048501874, 277377));
ck_assert_str_eq(boba720_s21, boba720);
}
END_TEST

START_TEST(bebasik__721) {
char boba721_s21[10000];
char boba721[10000];
ck_assert_int_eq(s21_sprintf(boba721_s21, "% .8hd%+.8hi%-5hi%+7.5hi;% if2p%+.4hi%-3hd4`%-6hi,`m% .8fn15%+6i=%+10i[%+iu%-hd%-6hd%-8.3i!% .3fc%-d%+2hd% hdb0%+.0hd%+5i0mqju%-.4hdym%-.9f", 22365, -23497, -6288, -28067, 254951, 24829, -5551, 24300, 17613.479021719115, 150933, -923711, -672922, -4384, 17078, -379836, -620.4361537099614, -560206, 31821, -14221, -15402, 547887, 25539, -3939.3770983790932),
sprintf(boba721, "% .8hd%+.8hi%-5hi%+7.5hi;% if2p%+.4hi%-3hd4`%-6hi,`m% .8fn15%+6i=%+10i[%+iu%-hd%-6hd%-8.3i!% .3fc%-d%+2hd% hdb0%+.0hd%+5i0mqju%-.4hdym%-.9f", 22365, -23497, -6288, -28067, 254951, 24829, -5551, 24300, 17613.479021719115, 150933, -923711, -672922, -4384, 17078, -379836, -620.4361537099614, -560206, 31821, -14221, -15402, 547887, 25539, -3939.3770983790932));
ck_assert_str_eq(boba721_s21, boba721);
}
END_TEST

START_TEST(bebasik__722) {
char boba722_s21[10000];
char boba722[10000];
ck_assert_int_eq(s21_sprintf(boba722_s21, "% 1hi`t%-hu%+5hir%+10.6i0%+6.2hil% ia% 5.8hi%-.0f%+.8hd", 26822, -1379, 7669, -195224, 13975, -735774, 2525, -4317.516791632687, 17568),
sprintf(boba722, "% 1hi`t%-hu%+5hir%+10.6i0%+6.2hil% ia% 5.8hi%-.0f%+.8hd", 26822, -1379, 7669, -195224, 13975, -735774, 2525, -4317.516791632687, 17568));
ck_assert_str_eq(boba722_s21, boba722);
}
END_TEST

START_TEST(bebasik__723) {
char boba723_s21[10000];
char boba723[10000];
ck_assert_int_eq(s21_sprintf(boba723_s21, "%+6.3hd%-hip%+6hd% 8i%-hi%-5him%-4.4i% 10.2hi%-.4huu%-6.2dj% 7f%+5.6dr%-.9u% 9i% .0hi%+4.9hd^v(%+9fd$", -2409, -7310, 30970, 205225, -9341, 12286, -277249, -6948, -717, -435306, 4112.813027643149, -723491, -792185, 441692, -484, 22379, -1260.506094466608),
sprintf(boba723, "%+6.3hd%-hip%+6hd% 8i%-hi%-5him%-4.4i% 10.2hi%-.4huu%-6.2dj% 7f%+5.6dr%-.9u% 9i% .0hi%+4.9hd^v(%+9fd$", -2409, -7310, 30970, 205225, -9341, 12286, -277249, -6948, -717, -435306, 4112.813027643149, -723491, -792185, 441692, -484, 22379, -1260.506094466608));
ck_assert_str_eq(boba723_s21, boba723);
}
END_TEST

START_TEST(bebasik__724) {
char boba724_s21[10000];
char boba724[10000];
ck_assert_int_eq(s21_sprintf(boba724_s21, "%+2.8hi4% fz%+8.3f0%-.6fd% .3dbc6", 19317, 6386.915532121853, 20862.551208664147, 14683.362338845986, 359311),
sprintf(boba724, "%+2.8hi4% fz%+8.3f0%-.6fd% .3dbc6", 19317, 6386.915532121853, 20862.551208664147, 14683.362338845986, 359311));
ck_assert_str_eq(boba724_s21, boba724);
}
END_TEST

START_TEST(bebasik__725) {
char boba725_s21[10000];
char boba725[10000];
ck_assert_int_eq(s21_sprintf(boba725_s21, "%+.7fas[a^;w%-1f=9a% .4d@%-5i% 1.0f%-hi@@6% hi% hd%+is% f%-d%-1.10hi5jb% hi(6;w%-hud%-u", 21502.73539058398, -11062.234509491156, 740822, -878816, -11231.804153333625, -4786, -30425, -28422, 834669, 2405.2347160508434, 92593, 18317, -24800, 24155, -912155),
sprintf(boba725, "%+.7fas[a^;w%-1f=9a% .4d@%-5i% 1.0f%-hi@@6% hi% hd%+is% f%-d%-1.10hi5jb% hi(6;w%-hud%-u", 21502.73539058398, -11062.234509491156, 740822, -878816, -11231.804153333625, -4786, -30425, -28422, 834669, 2405.2347160508434, 92593, 18317, -24800, 24155, -912155));
ck_assert_str_eq(boba725_s21, boba725);
}
END_TEST

START_TEST(bebasik__726) {
char boba726_s21[10000];
char boba726[10000];
ck_assert_int_eq(s21_sprintf(boba726_s21, "%-.1hd=%+.8i%-4.9hi-%+10.6i@%+7.10dr@%-.4u% hd7zf%+4hd% .8hd%-3.4du.)q% .8d;0%+hi%-7.6hdoc0%-.0ic%+f%-hdu%-7u% i^% d$% 8i%+2hi% hi7%+8.7it(", 28744, -550258, -31162, -922574, -267752, 824646, -2597, 15545, 12915, -277028, 754810, 8120, 4737, 743970, 7703.573806857225, 12559, -955135, -765752, 791505, 749709, -20039, -24539, -183334),
sprintf(boba726, "%-.1hd=%+.8i%-4.9hi-%+10.6i@%+7.10dr@%-.4u% hd7zf%+4hd% .8hd%-3.4du.)q% .8d;0%+hi%-7.6hdoc0%-.0ic%+f%-hdu%-7u% i^% d$% 8i%+2hi% hi7%+8.7it(", 28744, -550258, -31162, -922574, -267752, 824646, -2597, 15545, 12915, -277028, 754810, 8120, 4737, 743970, 7703.573806857225, 12559, -955135, -765752, 791505, 749709, -20039, -24539, -183334));
ck_assert_str_eq(boba726_s21, boba726);
}
END_TEST

START_TEST(bebasik__727) {
char boba727_s21[10000];
char boba727[10000];
ck_assert_int_eq(s21_sprintf(boba727_s21, "%+4hi%-u% i%-.7s%+4.9d% 1fh%-.2u51%+1hd% hdnn`[% 7.6i;p)%-7.0hi%-.7u%-.8iwh%-.3u7%-.4spa%-3.1hi0$x% .6f% 5.3i7% .7hi%+7.0d% hd%+.9hi", 25835, -859001, -208337, "bga;y48`;;3k0jm$(4,4", 562184, 22549.167059734013, 291480, 12792, 22644, 399524, -23452, 64098, -830372, 500533, "*", -18426, 23092.219204970123, -599987, -27432, -611779, 13081, 4036),
sprintf(boba727, "%+4hi%-u% i%-.7s%+4.9d% 1fh%-.2u51%+1hd% hdnn`[% 7.6i;p)%-7.0hi%-.7u%-.8iwh%-.3u7%-.4spa%-3.1hi0$x% .6f% 5.3i7% .7hi%+7.0d% hd%+.9hi", 25835, -859001, -208337, "bga;y48`;;3k0jm$(4,4", 562184, 22549.167059734013, 291480, 12792, 22644, 399524, -23452, 64098, -830372, 500533, "*", -18426, 23092.219204970123, -599987, -27432, -611779, 13081, 4036));
ck_assert_str_eq(boba727_s21, boba727);
}
END_TEST

START_TEST(bebasik__728) {
char boba728_s21[10000];
char boba728[10000];
ck_assert_int_eq(s21_sprintf(boba728_s21, "% 2.10f%+3hd% 3hi&%+2hd%+4.10i%-5.6hi;% 5.4iyh% hd%+.2hd%+.3d3% hd$1% 1.2hd%-u% hdm/$%+i% 7.10d% hi%+10hio!wcx^%-1hig%+i2% 7d", -10884.155027556122, 5948, 5355, 17529, 741221, 16930, 964242, 29187, -31509, 76488, 25453, -6602, -762337, 14855, 994200, -454219, -4946, -15245, 28958, 580675, 458949),
sprintf(boba728, "% 2.10f%+3hd% 3hi&%+2hd%+4.10i%-5.6hi;% 5.4iyh% hd%+.2hd%+.3d3% hd$1% 1.2hd%-u% hdm/$%+i% 7.10d% hi%+10hio!wcx^%-1hig%+i2% 7d", -10884.155027556122, 5948, 5355, 17529, 741221, 16930, 964242, 29187, -31509, 76488, 25453, -6602, -762337, 14855, 994200, -454219, -4946, -15245, 28958, 580675, 458949));
ck_assert_str_eq(boba728_s21, boba728);
}
END_TEST

START_TEST(bebasik__729) {
char boba729_s21[10000];
char boba729[10000];
ck_assert_int_eq(s21_sprintf(boba729_s21, "%+.4hd%+6.5fb%-c5o% 8.7f8px", -27249, 17989.66504091601, 'n', 14.777385987569584),
sprintf(boba729, "%+.4hd%+6.5fb%-c5o% 8.7f8px", -27249, 17989.66504091601, 'n', 14.777385987569584));
ck_assert_str_eq(boba729_s21, boba729);
}
END_TEST

START_TEST(bebasik__730) {
char boba730_s21[10000];
char boba730[10000];
ck_assert_int_eq(s21_sprintf(boba730_s21, "%-1.2ibzo", 212544),
sprintf(boba730, "%-1.2ibzo", 212544));
ck_assert_str_eq(boba730_s21, boba730);
}
END_TEST

START_TEST(bebasik__731) {
char boba731_s21[10000];
char boba731[10000];
ck_assert_int_eq(s21_sprintf(boba731_s21, "%-.0hi%+hi;%-fbl%+.8i% 4hiy", 10162, 5937, -1285.699520765413, -336448, 6384),
sprintf(boba731, "%-.0hi%+hi;%-fbl%+.8i% 4hiy", 10162, 5937, -1285.699520765413, -336448, 6384));
ck_assert_str_eq(boba731_s21, boba731);
}
END_TEST

START_TEST(bebasik__732) {
char boba732_s21[10000];
char boba732[10000];
ck_assert_int_eq(s21_sprintf(boba732_s21, "% .5f%-.3f% .4f%+.4hi% 1f6pl%-.9hu^%+1.9f8z% 3hi0% 4.2i%+hd%-d%-8hi", 3151.4818697382025, 13396.498293469842, -18777.1190452552, 27402, -551.5896915488426, 23487, 2535.287641881095, -21600, 965113, -10775, 165012, -7394),
sprintf(boba732, "% .5f%-.3f% .4f%+.4hi% 1f6pl%-.9hu^%+1.9f8z% 3hi0% 4.2i%+hd%-d%-8hi", 3151.4818697382025, 13396.498293469842, -18777.1190452552, 27402, -551.5896915488426, 23487, 2535.287641881095, -21600, 965113, -10775, 165012, -7394));
ck_assert_str_eq(boba732_s21, boba732);
}
END_TEST

START_TEST(bebasik__733) {
char boba733_s21[10000];
char boba733[10000];
ck_assert_int_eq(s21_sprintf(boba733_s21, "%-.0hd4% .0hi% 8.5f", 30202, -13334, 1147.5655194614233),
sprintf(boba733, "%-.0hd4% .0hi% 8.5f", 30202, -13334, 1147.5655194614233));
ck_assert_str_eq(boba733_s21, boba733);
}
END_TEST

START_TEST(bebasik__734) {
char boba734_s21[10000];
char boba734[10000];
ck_assert_int_eq(s21_sprintf(boba734_s21, "% f% 6f5%-7.7i%+.10ikuo%+d.2%+i%-4i%-1.1f", 10843.189801301596, -88.44983411995743, 753355, -919003, 561832, -667653, 346676, 1709.8692358081591),
sprintf(boba734, "% f% 6f5%-7.7i%+.10ikuo%+d.2%+i%-4i%-1.1f", 10843.189801301596, -88.44983411995743, 753355, -919003, 561832, -667653, 346676, 1709.8692358081591));
ck_assert_str_eq(boba734_s21, boba734);
}
END_TEST

START_TEST(bebasik__735) {
char boba735_s21[10000];
char boba735[10000];
ck_assert_int_eq(s21_sprintf(boba735_s21, "% hdl29%+hd% 3d% .9i%-10.3hd", -1553, -25638, 775512, 442362, -12064),
sprintf(boba735, "% hdl29%+hd% 3d% .9i%-10.3hd", -1553, -25638, 775512, 442362, -12064));
ck_assert_str_eq(boba735_s21, boba735);
}
END_TEST

START_TEST(bebasik__736) {
char boba736_s21[10000];
char boba736[10000];
ck_assert_int_eq(s21_sprintf(boba736_s21, "%+9.3ia%+.1dl% .9hd%+8.10hd*g/`% f%+hdp%-hdw;%+.9f%+.5f$% .3hit% .1hd%-d% 2d% 10.9hi% .9hd%+10.10fhf% .10hi^$j%-.1i3sr", -262312, 594479, -8819, -2634, 392.74506809039684, -25881, 5484, 14567.790785736017, 8052.329731550906, -23053, -21142, -543013, 85594, 23020, 16016, 1400.1276084653016, -1161, 873778),
sprintf(boba736, "%+9.3ia%+.1dl% .9hd%+8.10hd*g/`% f%+hdp%-hdw;%+.9f%+.5f$% .3hit% .1hd%-d% 2d% 10.9hi% .9hd%+10.10fhf% .10hi^$j%-.1i3sr", -262312, 594479, -8819, -2634, 392.74506809039684, -25881, 5484, 14567.790785736017, 8052.329731550906, -23053, -21142, -543013, 85594, 23020, 16016, 1400.1276084653016, -1161, 873778));
ck_assert_str_eq(boba736_s21, boba736);
}
END_TEST

START_TEST(bebasik__737) {
char boba737_s21[10000];
char boba737[10000];
ck_assert_int_eq(s21_sprintf(boba737_s21, "%+7.2hi% 7.6hicc%-1hd$%+.1i% hd%-.2d%-hd%-4u% .7hi3", -8125, 24815, -17550, -577006, 27933, -356931, -13105, 393724, 31941),
sprintf(boba737, "%+7.2hi% 7.6hicc%-1hd$%+.1i% hd%-.2d%-hd%-4u% .7hi3", -8125, 24815, -17550, -577006, 27933, -356931, -13105, 393724, 31941));
ck_assert_str_eq(boba737_s21, boba737);
}
END_TEST

START_TEST(bebasik__738) {
char boba738_s21[10000];
char boba738[10000];
ck_assert_int_eq(s21_sprintf(boba738_s21, "% 3.0f%-.7s%+8i% .9hi% hdc%-9.3huw% 7hi%-7s%+3.4hi%-7.4d-% 7.3d%-6.10s7!n% 3hd", -7197.914701670554, ".qt1", 188029, 11787, -26713, 12143, -29493, "f(l#s(5mg2x64ci3!.`i(.r,m.", 13013, 655341, 728081, "./.", -8660),
sprintf(boba738, "% 3.0f%-.7s%+8i% .9hi% hdc%-9.3huw% 7hi%-7s%+3.4hi%-7.4d-% 7.3d%-6.10s7!n% 3hd", -7197.914701670554, ".qt1", 188029, 11787, -26713, 12143, -29493, "f(l#s(5mg2x64ci3!.`i(.r,m.", 13013, 655341, 728081, "./.", -8660));
ck_assert_str_eq(boba738_s21, boba738);
}
END_TEST

START_TEST(bebasik__739) {
char boba739_s21[10000];
char boba739[10000];
ck_assert_int_eq(s21_sprintf(boba739_s21, "%-8hu-% 8.9i% i% .7f(j%-.10d%+1d%+d% 1hd% hi% .9hd%-hu-%+ij0`h[^%-.4i5`yr% .4hdm%-5id% d0% hip% 8d!1j0% .2hi%-10s", -23922, 947722, -101325, 402.7285942954722, 964885, -492892, 798394, 12060, 30268, -4740, -10434, -899649, 473855, 20968, 712292, 449658, 17848, -611582, 27357, "/ufh`.vy0#z#sk=jqx$"),
sprintf(boba739, "%-8hu-% 8.9i% i% .7f(j%-.10d%+1d%+d% 1hd% hi% .9hd%-hu-%+ij0`h[^%-.4i5`yr% .4hdm%-5id% d0% hip% 8d!1j0% .2hi%-10s", -23922, 947722, -101325, 402.7285942954722, 964885, -492892, 798394, 12060, 30268, -4740, -10434, -899649, 473855, 20968, 712292, 449658, 17848, -611582, 27357, "/ufh`.vy0#z#sk=jqx$"));
ck_assert_str_eq(boba739_s21, boba739);
}
END_TEST

START_TEST(bebasik__740) {
char boba740_s21[10000];
char boba740[10000];
ck_assert_int_eq(s21_sprintf(boba740_s21, "%+.1d-%+2hd% .0d%+7d%+hi% hi0%+5hi%-10.6i%+5hi%-hi% 3hd^% 4hiz%+9.6dx[%-fsj%+dnu%+hi%+hd% 10hi`", -828370, -18770, -73455, -584118, -16257, 4773, -25049, -830012, -3372, -20886, 11847, -23258, 530309, -13522.691093960564, 384751, 19563, 14350, 30036),
sprintf(boba740, "%+.1d-%+2hd% .0d%+7d%+hi% hi0%+5hi%-10.6i%+5hi%-hi% 3hd^% 4hiz%+9.6dx[%-fsj%+dnu%+hi%+hd% 10hi`", -828370, -18770, -73455, -584118, -16257, 4773, -25049, -830012, -3372, -20886, 11847, -23258, 530309, -13522.691093960564, 384751, 19563, 14350, 30036));
ck_assert_str_eq(boba740_s21, boba740);
}
END_TEST

START_TEST(bebasik__741) {
char boba741_s21[10000];
char boba741[10000];
ck_assert_int_eq(s21_sprintf(boba741_s21, "% hi(", 21700),
sprintf(boba741, "% hi(", 21700));
ck_assert_str_eq(boba741_s21, boba741);
}
END_TEST

START_TEST(bebasik__742) {
char boba742_s21[10000];
char boba742[10000];
ck_assert_int_eq(s21_sprintf(boba742_s21, "% hd99p% 3hi4/3%+9hdy%+6dh% 9.2hd", 11282, 23604, 4979, -28623, 15811),
sprintf(boba742, "% hd99p% 3hi4/3%+9hdy%+6dh% 9.2hd", 11282, 23604, 4979, -28623, 15811));
ck_assert_str_eq(boba742_s21, boba742);
}
END_TEST

START_TEST(bebasik__743) {
char boba743_s21[10000];
char boba743[10000];
ck_assert_int_eq(s21_sprintf(boba743_s21, "%-.10dk`o%-u%-7d%-su.%-3.3d%+.1hi#", -878103, -512054, -188437, "#(padmnt", -947006, -19081),
sprintf(boba743, "%-.10dk`o%-u%-7d%-su.%-3.3d%+.1hi#", -878103, -512054, -188437, "#(padmnt", -947006, -19081));
ck_assert_str_eq(boba743_s21, boba743);
}
END_TEST

START_TEST(bebasik__744) {
char boba744_s21[10000];
char boba744[10000];
ck_assert_int_eq(s21_sprintf(boba744_s21, "%+d% 1hi% 8f%-.9s% .3hi", -194234, 6621, -193.2124849189514, "y-1(1c,", -6989),
sprintf(boba744, "%+d% 1hi% 8f%-.9s% .3hi", -194234, 6621, -193.2124849189514, "y-1(1c,", -6989));
ck_assert_str_eq(boba744_s21, boba744);
}
END_TEST

START_TEST(bebasik__745) {
char boba745_s21[10000];
char boba745[10000];
ck_assert_int_eq(s21_sprintf(boba745_s21, "% 5ds% .3f%+3.2hi%-9.0f9,%+9hiza% 10hi% .3io% 4dm% hibhzgit8j9%-2hu%-hu%+.10d%+3.8d9,%+.6icmi8.-%-2.5hdh%-9.2uk%+1hd%+1d%-4i-pfjck%+4.7hiku%-.0s.(n%+f%+5d% 4hd", 617940, -6564.40274182298, -12294, -9957.526314324292, 19593, -14312, 844634, 994302, -15820, -28910, 7985, -720336, -91112, 429233, -8298, 119811, 5798, -203322, 431347, -2474, "a", 3796.6219192360263, -627938, 12435),
sprintf(boba745, "% 5ds% .3f%+3.2hi%-9.0f9,%+9hiza% 10hi% .3io% 4dm% hibhzgit8j9%-2hu%-hu%+.10d%+3.8d9,%+.6icmi8.-%-2.5hdh%-9.2uk%+1hd%+1d%-4i-pfjck%+4.7hiku%-.0s.(n%+f%+5d% 4hd", 617940, -6564.40274182298, -12294, -9957.526314324292, 19593, -14312, 844634, 994302, -15820, -28910, 7985, -720336, -91112, 429233, -8298, 119811, 5798, -203322, 431347, -2474, "a", 3796.6219192360263, -627938, 12435));
ck_assert_str_eq(boba745_s21, boba745);
}
END_TEST

START_TEST(bebasik__746) {
char boba746_s21[10000];
char boba746[10000];
ck_assert_int_eq(s21_sprintf(boba746_s21, "%+4d", 776717),
sprintf(boba746, "%+4d", 776717));
ck_assert_str_eq(boba746_s21, boba746);
}
END_TEST

START_TEST(bebasik__747) {
char boba747_s21[10000];
char boba747[10000];
ck_assert_int_eq(s21_sprintf(boba747_s21, "%-.5hi5t^%+fpn%-c%-4c% hde% 9i%+4.3hi4%-6.6hi0%-f,)%+7.6dv%+i)% hd% .0hi%-.0f%-.5i%-6s3c% 2hd$%-hi", -3013, 27832.141624929765, 'v', '6', 18627, 232054, 18603, -13949, 2675.487963199817, -53534, -260076, -1158, 6212, -3281.624452965143, 52414, "e&d81e^w;#1n[,6wd4$gr8ai)ko", -26762, -1668),
sprintf(boba747, "%-.5hi5t^%+fpn%-c%-4c% hde% 9i%+4.3hi4%-6.6hi0%-f,)%+7.6dv%+i)% hd% .0hi%-.0f%-.5i%-6s3c% 2hd$%-hi", -3013, 27832.141624929765, 'v', '6', 18627, 232054, 18603, -13949, 2675.487963199817, -53534, -260076, -1158, 6212, -3281.624452965143, 52414, "e&d81e^w;#1n[,6wd4$gr8ai)ko", -26762, -1668));
ck_assert_str_eq(boba747_s21, boba747);
}
END_TEST

START_TEST(bebasik__748) {
char boba748_s21[10000];
char boba748[10000];
ck_assert_int_eq(s21_sprintf(boba748_s21, "% .6i2%+.3hi%-f%-ig%-7.4hi%-.4hd%-5f% 9hi.%+f% hd% 7.1hin%+9hd%+8i)w4/o%+.7hie%-1f,% i", -624629, 29242, -5138.647274763878, -779539, 17628, -20897, 6281.302995417541, 31398, 14087.495220468783, 20627, 13555, -5985, -688612, 30930, -39.22576605464092, 635010),
sprintf(boba748, "% .6i2%+.3hi%-f%-ig%-7.4hi%-.4hd%-5f% 9hi.%+f% hd% 7.1hin%+9hd%+8i)w4/o%+.7hie%-1f,% i", -624629, 29242, -5138.647274763878, -779539, 17628, -20897, 6281.302995417541, 31398, 14087.495220468783, 20627, 13555, -5985, -688612, 30930, -39.22576605464092, 635010));
ck_assert_str_eq(boba748_s21, boba748);
}
END_TEST

START_TEST(bebasik__749) {
char boba749_s21[10000];
char boba749[10000];
ck_assert_int_eq(s21_sprintf(boba749_s21, "%+1.10hi6%+1.2hi`% f2% 4hi/@%+hii%+1.7hdyrg%-hdl%-3hi/y%+5.2f&%-u2%-2.5f% .2f%+.6f%+.0hi%-9.8dx%-6.5i%+1hd% 3dh/%+.0f%-c#", -27857, 18436, -1503.2718648145703, 9220, 15278, -29814, -1778, -16998, -996.7142049551591, -813540, -11027.182451896799, 3988.671656702677, 6731.230475095422, 6676, -707389, 152316, -15586, -226877, 17422.577407506058, 'y'),
sprintf(boba749, "%+1.10hi6%+1.2hi`% f2% 4hi/@%+hii%+1.7hdyrg%-hdl%-3hi/y%+5.2f&%-u2%-2.5f% .2f%+.6f%+.0hi%-9.8dx%-6.5i%+1hd% 3dh/%+.0f%-c#", -27857, 18436, -1503.2718648145703, 9220, 15278, -29814, -1778, -16998, -996.7142049551591, -813540, -11027.182451896799, 3988.671656702677, 6731.230475095422, 6676, -707389, 152316, -15586, -226877, 17422.577407506058, 'y'));
ck_assert_str_eq(boba749_s21, boba749);
}
END_TEST

START_TEST(bebasik__750) {
char boba750_s21[10000];
char boba750[10000];
ck_assert_int_eq(s21_sprintf(boba750_s21, "%-f% .2hif)g%+.2f&=^%+9d*%+ic%+8.6hd% 10hivewf%-5d@%+5.0f8z%+.7hie;9% 6i% d", -12700.612482028035, -11129, -4046.161295600055, 582704, 380227, 17725, -14511, -304981, 5276.818576892047, 11127, 694386, -519653),
sprintf(boba750, "%-f% .2hif)g%+.2f&=^%+9d*%+ic%+8.6hd% 10hivewf%-5d@%+5.0f8z%+.7hie;9% 6i% d", -12700.612482028035, -11129, -4046.161295600055, 582704, 380227, 17725, -14511, -304981, 5276.818576892047, 11127, 694386, -519653));
ck_assert_str_eq(boba750_s21, boba750);
}
END_TEST

START_TEST(bebasik__751) {
char boba751_s21[10000];
char boba751[10000];
ck_assert_int_eq(s21_sprintf(boba751_s21, "%-ur%+10hi`!4^8% 6.3dwx$%-d% .5i% 6hi% .7f,5%-.3i%-3.6hd@% 10hd9%+1hd&*% d%-hde%+.8hd8", -477376, -7446, 732241, -264293, 247985, 24013, -6846.776775188313, 192471, -10636, 17608, -4540, -795810, -26729, -18404),
sprintf(boba751, "%-ur%+10hi`!4^8% 6.3dwx$%-d% .5i% 6hi% .7f,5%-.3i%-3.6hd@% 10hd9%+1hd&*% d%-hde%+.8hd8", -477376, -7446, 732241, -264293, 247985, 24013, -6846.776775188313, 192471, -10636, 17608, -4540, -795810, -26729, -18404));
ck_assert_str_eq(boba751_s21, boba751);
}
END_TEST

START_TEST(bebasik__752) {
char boba752_s21[10000];
char boba752[10000];
ck_assert_int_eq(s21_sprintf(boba752_s21, "%-hu4.g)%+.7hi(%-.10hibn% 9.10hipj-% 2hd% .4i%+.8hd%-3.0hu$%+f5tg%-1.6f% 2hd%-hd% .6d-%-3hu% .5f`y%-5hi%-1.7hi% hd=r%+3.2him0%+7f", 29285, -29439, 30368, 20716, -26855, -272929, -23153, 418, 2229.536646985568, -3758.8924361500235, 14000, 17162, 304586, -24419, -12515.824163974612, -15714, -4666, 8720, -653, 1761.1209141710108),
sprintf(boba752, "%-hu4.g)%+.7hi(%-.10hibn% 9.10hipj-% 2hd% .4i%+.8hd%-3.0hu$%+f5tg%-1.6f% 2hd%-hd% .6d-%-3hu% .5f`y%-5hi%-1.7hi% hd=r%+3.2him0%+7f", 29285, -29439, 30368, 20716, -26855, -272929, -23153, 418, 2229.536646985568, -3758.8924361500235, 14000, 17162, 304586, -24419, -12515.824163974612, -15714, -4666, 8720, -653, 1761.1209141710108));
ck_assert_str_eq(boba752_s21, boba752);
}
END_TEST

START_TEST(bebasik__753) {
char boba753_s21[10000];
char boba753[10000];
ck_assert_int_eq(s21_sprintf(boba753_s21, "%+hd%-.7hdcx%+1.4f821p%-7fu=n%-9d%+3d%-2hi%-5d% .3f@g%-9.9dw% 4f%+4.5hd%-5hij%-hd", -27348, -27994, -18055.52545667207, -2863.9601500301965, -75817, 498756, -28718, -392391, 12246.277660558648, 444676, -3962.9118653377236, -23449, 1340, 19009),
sprintf(boba753, "%+hd%-.7hdcx%+1.4f821p%-7fu=n%-9d%+3d%-2hi%-5d% .3f@g%-9.9dw% 4f%+4.5hd%-5hij%-hd", -27348, -27994, -18055.52545667207, -2863.9601500301965, -75817, 498756, -28718, -392391, 12246.277660558648, 444676, -3962.9118653377236, -23449, 1340, 19009));
ck_assert_str_eq(boba753_s21, boba753);
}
END_TEST

START_TEST(bebasik__754) {
char boba754_s21[10000];
char boba754[10000];
ck_assert_int_eq(s21_sprintf(boba754_s21, "%-hiba%-.8f1(%-hd%+.10dm%-d#%-1.5hdc", -24513, -2380.5226433841785, 29221, 560088, 343402, 13842),
sprintf(boba754, "%-hiba%-.8f1(%-hd%+.10dm%-d#%-1.5hdc", -24513, -2380.5226433841785, 29221, 560088, 343402, 13842));
ck_assert_str_eq(boba754_s21, boba754);
}
END_TEST

START_TEST(bebasik__755) {
char boba755_s21[10000];
char boba755[10000];
ck_assert_int_eq(s21_sprintf(boba755_s21, "% i,%+3.3hd%+5fk%+.6f% 9.8hi%-8.5hd%+i%-2d5%-.3hd% f,#%-10.1hdhqa% .7d%-.2s%-8hi2% fv%-i%+.9hi% .6hdv%+1d$k/", -342803, 14402, 806.6820697936897, -3536.917408715306, 13838, 12501, -521986, -184724, 2681, -2011.1796269189326, -15860, -459180, ".*^/*j", -21391, -1286.5273534554117, 508522, -15767, -5349, -436138),
sprintf(boba755, "% i,%+3.3hd%+5fk%+.6f% 9.8hi%-8.5hd%+i%-2d5%-.3hd% f,#%-10.1hdhqa% .7d%-.2s%-8hi2% fv%-i%+.9hi% .6hdv%+1d$k/", -342803, 14402, 806.6820697936897, -3536.917408715306, 13838, 12501, -521986, -184724, 2681, -2011.1796269189326, -15860, -459180, ".*^/*j", -21391, -1286.5273534554117, 508522, -15767, -5349, -436138));
ck_assert_str_eq(boba755_s21, boba755);
}
END_TEST

START_TEST(bebasik__756) {
char boba756_s21[10000];
char boba756[10000];
ck_assert_int_eq(s21_sprintf(boba756_s21, "%-8i8.gi%+i% 9.9hi%-hu% 6.1hdy!", 934911, -860923, -10644, -24642, -8966),
sprintf(boba756, "%-8i8.gi%+i% 9.9hi%-hu% 6.1hdy!", 934911, -860923, -10644, -24642, -8966));
ck_assert_str_eq(boba756_s21, boba756);
}
END_TEST

START_TEST(bebasik__757) {
char boba757_s21[10000];
char boba757[10000];
ck_assert_int_eq(s21_sprintf(boba757_s21, "%+4.9i^%-.7f;9%-i% .0hi%-2.8f%-7.10di%-d=%+.3hd%+.8hd%+3hi%+.7him6%-8.2hi%+d#%-6uko% .8hi% .3hd% .10hi2[%-4cdk%-3hd%+.1f% 7f%-f/%+.8i", -762221, 11630.287884507125, -498201, 20364, -18223.51953497653, 858574, 154090, -4447, 18397, -21235, -25514, -30619, 918853, 739661, -11608, -16442, -30842, '1', -14736, 18237.243500032233, 7066.472677878134, -21555.85135706294, -912490),
sprintf(boba757, "%+4.9i^%-.7f;9%-i% .0hi%-2.8f%-7.10di%-d=%+.3hd%+.8hd%+3hi%+.7him6%-8.2hi%+d#%-6uko% .8hi% .3hd% .10hi2[%-4cdk%-3hd%+.1f% 7f%-f/%+.8i", -762221, 11630.287884507125, -498201, 20364, -18223.51953497653, 858574, 154090, -4447, 18397, -21235, -25514, -30619, 918853, 739661, -11608, -16442, -30842, '1', -14736, 18237.243500032233, 7066.472677878134, -21555.85135706294, -912490));
ck_assert_str_eq(boba757_s21, boba757);
}
END_TEST

START_TEST(bebasik__758) {
char boba758_s21[10000];
char boba758[10000];
ck_assert_int_eq(s21_sprintf(boba758_s21, "%-9hd% 2f;9x%-hd;#%+7hi% hd=.%+7.0d6*%+dl@8%-1f%+2.5f%-9.6hd4%+6hd% f%-hd%-9hd%+.2d", 14456, -21097.467639281334, 21484, -31850, 17835, 241458, 730120, 18853.72284295108, 9456.204245452716, 22509, 13275, -5275.102349380183, 27768, 3547, -512902),
sprintf(boba758, "%-9hd% 2f;9x%-hd;#%+7hi% hd=.%+7.0d6*%+dl@8%-1f%+2.5f%-9.6hd4%+6hd% f%-hd%-9hd%+.2d", 14456, -21097.467639281334, 21484, -31850, 17835, 241458, 730120, 18853.72284295108, 9456.204245452716, 22509, 13275, -5275.102349380183, 27768, 3547, -512902));
ck_assert_str_eq(boba758_s21, boba758);
}
END_TEST

START_TEST(bebasik__759) {
char boba759_s21[10000];
char boba759[10000];
ck_assert_int_eq(s21_sprintf(boba759_s21, "%+7.8f^%-3.1hd$%-.7s[% 3.0hd%-7hdr/% 6hi% du", -25374.80540352729, 2093, "8*t.1e.&v", 2220, 2223, -25728, 632888),
sprintf(boba759, "%+7.8f^%-3.1hd$%-.7s[% 3.0hd%-7hdr/% 6hi% du", -25374.80540352729, 2093, "8*t.1e.&v", 2220, 2223, -25728, 632888));
ck_assert_str_eq(boba759_s21, boba759);
}
END_TEST

START_TEST(bebasik__760) {
char boba760_s21[10000];
char boba760[10000];
ck_assert_int_eq(s21_sprintf(boba760_s21, "%+3dep%-8.8hd[%-7hu%-4.0sh%-u*%+d% 7hd%-3i% 6.7i`uf% .10hi4m%-3.3u/f5% .0hi", -439286, 4092, 14406, "(g^m!xq.#k8hcaw88gj", -9501, -418270, 8095, -744622, 728556, -6082, 43936, -2712),
sprintf(boba760, "%+3dep%-8.8hd[%-7hu%-4.0sh%-u*%+d% 7hd%-3i% 6.7i`uf% .10hi4m%-3.3u/f5% .0hi", -439286, 4092, 14406, "(g^m!xq.#k8hcaw88gj", -9501, -418270, 8095, -744622, 728556, -6082, 43936, -2712));
ck_assert_str_eq(boba760_s21, boba760);
}
END_TEST

START_TEST(bebasik__761) {
char boba761_s21[10000];
char boba761[10000];
ck_assert_int_eq(s21_sprintf(boba761_s21, "% 1hdmp% 2hda% 2.5hipo%-c`3%-9.3hiahy", -1758, 24504, 3315, ')', 11372),
sprintf(boba761, "% 1hdmp% 2hda% 2.5hipo%-c`3%-9.3hiahy", -1758, 24504, 3315, ')', 11372));
ck_assert_str_eq(boba761_s21, boba761);
}
END_TEST

START_TEST(bebasik__762) {
char boba762_s21[10000];
char boba762[10000];
ck_assert_int_eq(s21_sprintf(boba762_s21, "%+7hdb%-9.2f% 6hd%-1.3u1%+9i%+1.0hd% 7.2hd%+4i% 6hi%+.1hd%-.5hi&h", -11082, -9940.697978247808, 8887, -995818, 56807, -26246, -17582, 514353, 7731, 12691, 4505),
sprintf(boba762, "%+7hdb%-9.2f% 6hd%-1.3u1%+9i%+1.0hd% 7.2hd%+4i% 6hi%+.1hd%-.5hi&h", -11082, -9940.697978247808, 8887, -995818, 56807, -26246, -17582, 514353, 7731, 12691, 4505));
ck_assert_str_eq(boba762_s21, boba762);
}
END_TEST

START_TEST(bebasik__763) {
char boba763_s21[10000];
char boba763[10000];
ck_assert_int_eq(s21_sprintf(boba763_s21, "%-s%-5hit)%-.8hd% 3.6id$eeaw%-1.8hiw.8x@%-8.10sj% i=%-7.7dl% hi;=e%+9.7i%-1hi-", "p#9a4-a5@r;", -30269, 24010, 83238, 310, "v9$8=x2;63", -487835, -634317, 31510, -124425, -10599),
sprintf(boba763, "%-s%-5hit)%-.8hd% 3.6id$eeaw%-1.8hiw.8x@%-8.10sj% i=%-7.7dl% hi;=e%+9.7i%-1hi-", "p#9a4-a5@r;", -30269, 24010, 83238, 310, "v9$8=x2;63", -487835, -634317, 31510, -124425, -10599));
ck_assert_str_eq(boba763_s21, boba763);
}
END_TEST

START_TEST(bebasik__764) {
char boba764_s21[10000];
char boba764[10000];
ck_assert_int_eq(s21_sprintf(boba764_s21, "% hi%-4.4hi;% .7d% 10.7i% 4.7d%-10f%+.0hd% 8hi%-.2hi%+5.6hdg4)% d&%+.10hiv8%+5.5d", -18229, 18136, 479503, -973460, -186427, -28336.539029934833, 14611, -31767, -15281, 2714, 945200, -24200, 90404),
sprintf(boba764, "% hi%-4.4hi;% .7d% 10.7i% 4.7d%-10f%+.0hd% 8hi%-.2hi%+5.6hdg4)% d&%+.10hiv8%+5.5d", -18229, 18136, 479503, -973460, -186427, -28336.539029934833, 14611, -31767, -15281, 2714, 945200, -24200, 90404));
ck_assert_str_eq(boba764_s21, boba764);
}
END_TEST

START_TEST(bebasik__765) {
char boba765_s21[10000];
char boba765[10000];
ck_assert_int_eq(s21_sprintf(boba765_s21, "% .5hde8v%-3hdyo%-.10f/0% .6hi% hi%+.8ic%-2hd%-u% .2hio% 2hi%+.5hiju@%+8hdy.% 8.8hi2gw*g%-4.6u%+8ip%-2.8u%+6fus% .4f%-1hil%+9.4hi%+.3hi7", 2332, 23251, -3858.7301842672687, 15319, 8352, 500882, -31520, -978265, 25720, -798, 13410, 30232, 24324, -264466, 230139, -509530, 6570.60520836467, -8283.364533256252, 24168, 7026, -1203),
sprintf(boba765, "% .5hde8v%-3hdyo%-.10f/0% .6hi% hi%+.8ic%-2hd%-u% .2hio% 2hi%+.5hiju@%+8hdy.% 8.8hi2gw*g%-4.6u%+8ip%-2.8u%+6fus% .4f%-1hil%+9.4hi%+.3hi7", 2332, 23251, -3858.7301842672687, 15319, 8352, 500882, -31520, -978265, 25720, -798, 13410, 30232, 24324, -264466, 230139, -509530, 6570.60520836467, -8283.364533256252, 24168, 7026, -1203));
ck_assert_str_eq(boba765_s21, boba765);
}
END_TEST

START_TEST(bebasik__766) {
char boba766_s21[10000];
char boba766[10000];
ck_assert_int_eq(s21_sprintf(boba766_s21, "%+hi51% 2.0hd% 10.0hi)% 5i#z%-hi0.% .2hd% i%-i3%+7.3hi16%-3.9s,5[s%-hu% .8dclk%+.3hi%-.8f%+.10i@7%+8.6d8%+hdz%-4hd)c[% hix% .4i", -9512, -21630, -10651, -111780, -21318, 23502, -963852, -199641, 21348, "`!,`/l772kj7^zs,c^;)po7$)6", 20835, -510943, -22650, -4137.2248395113875, 585854, 682407, -21035, -6670, -1169, -58031),
sprintf(boba766, "%+hi51% 2.0hd% 10.0hi)% 5i#z%-hi0.% .2hd% i%-i3%+7.3hi16%-3.9s,5[s%-hu% .8dclk%+.3hi%-.8f%+.10i@7%+8.6d8%+hdz%-4hd)c[% hix% .4i", -9512, -21630, -10651, -111780, -21318, 23502, -963852, -199641, 21348, "`!,`/l772kj7^zs,c^;)po7$)6", 20835, -510943, -22650, -4137.2248395113875, 585854, 682407, -21035, -6670, -1169, -58031));
ck_assert_str_eq(boba766_s21, boba766);
}
END_TEST

START_TEST(bebasik__767) {
char boba767_s21[10000];
char boba767[10000];
ck_assert_int_eq(s21_sprintf(boba767_s21, "%-4.3hi% 3.8io%-hu% 6.10hi%+3.5fx% 2dl)", 1097, 528446, 27391, -1393, 4197.313558102222, 131551),
sprintf(boba767, "%-4.3hi% 3.8io%-hu% 6.10hi%+3.5fx% 2dl)", 1097, 528446, 27391, -1393, 4197.313558102222, 131551));
ck_assert_str_eq(boba767_s21, boba767);
}
END_TEST

START_TEST(bebasik__768) {
char boba768_s21[10000];
char boba768[10000];
ck_assert_int_eq(s21_sprintf(boba768_s21, "%+hi%-9hd%-f,)%-5u(l%-9.5iez,%+.5hd%+6.7f!%+him(% 10i", 58, 10848, -3165.6851854096735, -93949, 326900, 27108, -12367.853492904618, -23697, -327521),
sprintf(boba768, "%+hi%-9hd%-f,)%-5u(l%-9.5iez,%+.5hd%+6.7f!%+him(% 10i", 58, 10848, -3165.6851854096735, -93949, 326900, 27108, -12367.853492904618, -23697, -327521));
ck_assert_str_eq(boba768_s21, boba768);
}
END_TEST

START_TEST(bebasik__769) {
char boba769_s21[10000];
char boba769[10000];
ck_assert_int_eq(s21_sprintf(boba769_s21, "% 2f", 8202.82069484793),
sprintf(boba769, "% 2f", 8202.82069484793));
ck_assert_str_eq(boba769_s21, boba769);
}
END_TEST

START_TEST(bebasik__770) {
char boba770_s21[10000];
char boba770[10000];
ck_assert_int_eq(s21_sprintf(boba770_s21, "%-2.5hu% .4hi%-d% hdx% .1hi%-6i%-10u*%+.8hd% 9.7hi%+3.9f%-f%+6d%+.3hi%+.2hi%+9i.3% 8f%-10hu(% hd", -20646, 13470, -714202, 28826, -10820, -136950, -618027, -8106, 25668, 5026.130898699629, 10365.203248327061, -957488, 30681, -31837, -396747, 17796.47814968046, 1949, -13124),
sprintf(boba770, "%-2.5hu% .4hi%-d% hdx% .1hi%-6i%-10u*%+.8hd% 9.7hi%+3.9f%-f%+6d%+.3hi%+.2hi%+9i.3% 8f%-10hu(% hd", -20646, 13470, -714202, 28826, -10820, -136950, -618027, -8106, 25668, 5026.130898699629, 10365.203248327061, -957488, 30681, -31837, -396747, 17796.47814968046, 1949, -13124));
ck_assert_str_eq(boba770_s21, boba770);
}
END_TEST

START_TEST(bebasik__771) {
char boba771_s21[10000];
char boba771[10000];
ck_assert_int_eq(s21_sprintf(boba771_s21, "%+6.4hi%-hd%+d% f2% 6fc%-9hdmk5%+10hi%+d%+hii%-3.1f%+10hdm%-db%-.5f%-10.7i% 7.1hi%-6.5hif% .1d@%-4d% hi% hijj%+hd", 8941, -9331, 882414, 4213.638729508616, 20086.19244708098, 19655, 9366, 918998, 8410, 12424.172953501076, -18958, -34687, -10555.190255581389, 80929, -17408, 19883, 263958, 497666, -4229, -30218, -6045),
sprintf(boba771, "%+6.4hi%-hd%+d% f2% 6fc%-9hdmk5%+10hi%+d%+hii%-3.1f%+10hdm%-db%-.5f%-10.7i% 7.1hi%-6.5hif% .1d@%-4d% hi% hijj%+hd", 8941, -9331, 882414, 4213.638729508616, 20086.19244708098, 19655, 9366, 918998, 8410, 12424.172953501076, -18958, -34687, -10555.190255581389, 80929, -17408, 19883, 263958, 497666, -4229, -30218, -6045));
ck_assert_str_eq(boba771_s21, boba771);
}
END_TEST

START_TEST(bebasik__772) {
char boba772_s21[10000];
char boba772[10000];
ck_assert_int_eq(s21_sprintf(boba772_s21, "%+10hibr/%+hi1e%-4.3hd*l%+8.6hd%+is%+f% 4.6f9)95%-hud`a% 4hi%-i(%-7su%+7.7fjp%+9.8d%-.7u% 10.1f-%+4f% .8hdi% .10hi%-.9hd", 8409, -18604, 13612, -22109, 818838, 12647.3875265596, 17868.328300315927, -31679, 18320, -737470, "/^s$0aib341h&ens&l#c", 16472.268670635054, -445901, 991317, -5448.475528559726, 1813.679452475354, 28406, 17224, 13483),
sprintf(boba772, "%+10hibr/%+hi1e%-4.3hd*l%+8.6hd%+is%+f% 4.6f9)95%-hud`a% 4hi%-i(%-7su%+7.7fjp%+9.8d%-.7u% 10.1f-%+4f% .8hdi% .10hi%-.9hd", 8409, -18604, 13612, -22109, 818838, 12647.3875265596, 17868.328300315927, -31679, 18320, -737470, "/^s$0aib341h&ens&l#c", 16472.268670635054, -445901, 991317, -5448.475528559726, 1813.679452475354, 28406, 17224, 13483));
ck_assert_str_eq(boba772_s21, boba772);
}
END_TEST

START_TEST(bebasik__773) {
char boba773_s21[10000];
char boba773[10000];
ck_assert_int_eq(s21_sprintf(boba773_s21, "% .3f)s%+.7hipy%+8i%-4hu% 4f% i!q4v%-hic%+hd`w%-7f%-hd%+10.7hd!%+6.3f% .6f%-8.0hu% 8f%-f9-)o%+.4hi9%-1d^%+10hi", -4975.136714947444, 26047, 761707, 5837, -10793.049661037869, 337687, 12421, -20064, 13990.407877420228, -13981, 29794, -341.7210351566265, -5829.021525026122, 14285, 2758.0254357750214, 9262.712843411082, 19484, 118598, 10918),
sprintf(boba773, "% .3f)s%+.7hipy%+8i%-4hu% 4f% i!q4v%-hic%+hd`w%-7f%-hd%+10.7hd!%+6.3f% .6f%-8.0hu% 8f%-f9-)o%+.4hi9%-1d^%+10hi", -4975.136714947444, 26047, 761707, 5837, -10793.049661037869, 337687, 12421, -20064, 13990.407877420228, -13981, 29794, -341.7210351566265, -5829.021525026122, 14285, 2758.0254357750214, 9262.712843411082, 19484, 118598, 10918));
ck_assert_str_eq(boba773_s21, boba773);
}
END_TEST

START_TEST(bebasik__774) {
char boba774_s21[10000];
char boba774[10000];
ck_assert_int_eq(s21_sprintf(boba774_s21, "%-10.1f% hi--%-.10u% 1.3f% 3dw%-4.3i%+4hd!%+.3fp0(s%-.0hu%+f%+d% .4iz% ibb%-1.0s% 1.2hi%+hi#j%-sug%+.9hir% 2.1hi% hd=`gq%-5.10i% .7i%-9.9hi", -16011.686445433497, 2993, -453052, -9647.638315410253, 289950, 737747, -20175, -13797.323838096814, -31042, -18071.542829019538, 454133, 445939, -157616, "", -29125, -6914, ",;kyk&bx)hv(k^#-ww8xf;-u!nk`/", -28300, 31767, 19077, 11453, 190488, 31483),
sprintf(boba774, "%-10.1f% hi--%-.10u% 1.3f% 3dw%-4.3i%+4hd!%+.3fp0(s%-.0hu%+f%+d% .4iz% ibb%-1.0s% 1.2hi%+hi#j%-sug%+.9hir% 2.1hi% hd=`gq%-5.10i% .7i%-9.9hi", -16011.686445433497, 2993, -453052, -9647.638315410253, 289950, 737747, -20175, -13797.323838096814, -31042, -18071.542829019538, 454133, 445939, -157616, "", -29125, -6914, ",;kyk&bx)hv(k^#-ww8xf;-u!nk`/", -28300, 31767, 19077, 11453, 190488, 31483));
ck_assert_str_eq(boba774_s21, boba774);
}
END_TEST

START_TEST(bebasik__775) {
char boba775_s21[10000];
char boba775[10000];
ck_assert_int_eq(s21_sprintf(boba775_s21, "%+2.7hd%-hi% 3hi&%+d9!r% hio%-1.8s%+hd%-2hi.3j% 4.10d=%+i%+7hd%+hie%-5hu4% 2dz%+4hie%-1.3hd%+1hd%-hi3q4% 3dk%+.0f34% 10hio% hi.&p%-2hi", 2223, -15888, -9799, 176845, -4208, "`5tq&$s`d#,)8^*", -12757, 5311, -963702, 371464, 29109, 20402, 25011, -516707, 5881, -26017, 21494, 6029, -216005, -11529.397515827568, 4067, -17935, 22428),
sprintf(boba775, "%+2.7hd%-hi% 3hi&%+d9!r% hio%-1.8s%+hd%-2hi.3j% 4.10d=%+i%+7hd%+hie%-5hu4% 2dz%+4hie%-1.3hd%+1hd%-hi3q4% 3dk%+.0f34% 10hio% hi.&p%-2hi", 2223, -15888, -9799, 176845, -4208, "`5tq&$s`d#,)8^*", -12757, 5311, -963702, 371464, 29109, 20402, 25011, -516707, 5881, -26017, 21494, 6029, -216005, -11529.397515827568, 4067, -17935, 22428));
ck_assert_str_eq(boba775_s21, boba775);
}
END_TEST

START_TEST(bebasik__776) {
char boba776_s21[10000];
char boba776[10000];
ck_assert_int_eq(s21_sprintf(boba776_s21, "%-u9% 3.2i% .8hdb$% 2hd% 10i%+f% hi5(% 9.10hd% .0hd%-hul3%-.7hu7%+3.9d%+8i.% i1%+.9i%+6d% 4hic%-.3i%-.8hd%+4hdw", -763046, 202628, -6755, 2528, 532804, -22814.246860711217, 14094, 9297, 1239, 5924, 6706, 686995, -994050, 114262, -845449, 140591, 3023, 166350, 22079, -11402),
sprintf(boba776, "%-u9% 3.2i% .8hdb$% 2hd% 10i%+f% hi5(% 9.10hd% .0hd%-hul3%-.7hu7%+3.9d%+8i.% i1%+.9i%+6d% 4hic%-.3i%-.8hd%+4hdw", -763046, 202628, -6755, 2528, 532804, -22814.246860711217, 14094, 9297, 1239, 5924, 6706, 686995, -994050, 114262, -845449, 140591, 3023, 166350, 22079, -11402));
ck_assert_str_eq(boba776_s21, boba776);
}
END_TEST

START_TEST(bebasik__777) {
char boba777_s21[10000];
char boba777[10000];
ck_assert_int_eq(s21_sprintf(boba777_s21, "%-6.8hdv", -9898),
sprintf(boba777, "%-6.8hdv", -9898));
ck_assert_str_eq(boba777_s21, boba777);
}
END_TEST

START_TEST(bebasik__778) {
char boba778_s21[10000];
char boba778[10000];
ck_assert_int_eq(s21_sprintf(boba778_s21, "%-.8hi%+ij%-.3fdv7% 4i% 5i%-.9fe^%-8hu%+4hd% .4hd% 7.5i% .3d%-.0hd^% 10d%+7.3hd%+3f% 9i=sy-%+2hd% 2hil%+.8hd6%+3.10d% .5f", -11743, -222543, 1391.9740360662797, -593537, 244659, -1433.7537152340392, 17225, 31290, 8508, -614882, 703858, 30362, -976026, 22517, 547.7154239311125, -898951, -2337, -4005, -1875, -293050, 3343.88567752301),
sprintf(boba778, "%-.8hi%+ij%-.3fdv7% 4i% 5i%-.9fe^%-8hu%+4hd% .4hd% 7.5i% .3d%-.0hd^% 10d%+7.3hd%+3f% 9i=sy-%+2hd% 2hil%+.8hd6%+3.10d% .5f", -11743, -222543, 1391.9740360662797, -593537, 244659, -1433.7537152340392, 17225, 31290, 8508, -614882, 703858, 30362, -976026, 22517, 547.7154239311125, -898951, -2337, -4005, -1875, -293050, 3343.88567752301));
ck_assert_str_eq(boba778_s21, boba778);
}
END_TEST

START_TEST(bebasik__779) {
char boba779_s21[10000];
char boba779[10000];
ck_assert_int_eq(s21_sprintf(boba779_s21, "%-3.4hus%+6.4hd%+i% .4dp% .1i0", 26209, 18717, 102081, -859329, -446876),
sprintf(boba779, "%-3.4hus%+6.4hd%+i% .4dp% .1i0", 26209, 18717, 102081, -859329, -446876));
ck_assert_str_eq(boba779_s21, boba779);
}
END_TEST

START_TEST(bebasik__780) {
char boba780_s21[10000];
char boba780[10000];
ck_assert_int_eq(s21_sprintf(boba780_s21, "%-d%-1.2hd5%-sv%-i1% 10hia=74%+dr% .5d3d%-.9s% hiki% fh,-.[e$%+f% .1d%-huz*z%+.8i%-5hij=b%+.10hdy%-5s%+.4d% 6ii%+.6hi%-.10i% .4iwy", 685026, -26560, "3&[=6zw&kw4k", -511254, -24732, -558011, 54677, "*szd*/u,u7r!z$^^0*6egy#vs", -21516, -6323.605435973018, 9261.030136129006, 251777, 29499, 941825, 7501, -13440, "r^#rtv!*qo)i,6x5#r!", 285466, 280946, 15575, 722185, -419852),
sprintf(boba780, "%-d%-1.2hd5%-sv%-i1% 10hia=74%+dr% .5d3d%-.9s% hiki% fh,-.[e$%+f% .1d%-huz*z%+.8i%-5hij=b%+.10hdy%-5s%+.4d% 6ii%+.6hi%-.10i% .4iwy", 685026, -26560, "3&[=6zw&kw4k", -511254, -24732, -558011, 54677, "*szd*/u,u7r!z$^^0*6egy#vs", -21516, -6323.605435973018, 9261.030136129006, 251777, 29499, 941825, 7501, -13440, "r^#rtv!*qo)i,6x5#r!", 285466, 280946, 15575, 722185, -419852));
ck_assert_str_eq(boba780_s21, boba780);
}
END_TEST

START_TEST(bebasik__781) {
char boba781_s21[10000];
char boba781[10000];
ck_assert_int_eq(s21_sprintf(boba781_s21, "%+hdr%+4.9d%+4.1ii%+.9hil&u% hd%-3sn%+.8hitg% 3ia%+8.0f;0%+.9hdy%-2hu#", -17351, -779717, 156421, 25619, -31197, "5@)", -3832, 994110, 11010.107556942732, 3724, 13775),
sprintf(boba781, "%+hdr%+4.9d%+4.1ii%+.9hil&u% hd%-3sn%+.8hitg% 3ia%+8.0f;0%+.9hdy%-2hu#", -17351, -779717, 156421, 25619, -31197, "5@)", -3832, 994110, 11010.107556942732, 3724, 13775));
ck_assert_str_eq(boba781_s21, boba781);
}
END_TEST

START_TEST(bebasik__782) {
char boba782_s21[10000];
char boba782[10000];
ck_assert_int_eq(s21_sprintf(boba782_s21, "%-7.6u%+hd`t;%-7hi% hi%-hd4**%-4.2uy% .7irg%+hi%+.9i2/=m%-uw!)gx%+f%+1d%-2hu,%-9.7hd-%-8hi`% 1i", -30384, -25666, -19876, -15873, 7975, 412483, 709401, 31283, 214978, 560790, -494.09875084262274, 752609, -30239, 15965, -21943, 438345),
sprintf(boba782, "%-7.6u%+hd`t;%-7hi% hi%-hd4**%-4.2uy% .7irg%+hi%+.9i2/=m%-uw!)gx%+f%+1d%-2hu,%-9.7hd-%-8hi`% 1i", -30384, -25666, -19876, -15873, 7975, 412483, 709401, 31283, 214978, 560790, -494.09875084262274, 752609, -30239, 15965, -21943, 438345));
ck_assert_str_eq(boba782_s21, boba782);
}
END_TEST

START_TEST(bebasik__783) {
char boba783_s21[10000];
char boba783[10000];
ck_assert_int_eq(s21_sprintf(boba783_s21, "%-hu%+.6i%-10.10i$x`d%-6.5hu% 5.4d%-d%-hd%-9hd", -1319, 684504, 668242, 29308, -248070, -279946, -1622, 24854),
sprintf(boba783, "%-hu%+.6i%-10.10i$x`d%-6.5hu% 5.4d%-d%-hd%-9hd", -1319, 684504, 668242, 29308, -248070, -279946, -1622, 24854));
ck_assert_str_eq(boba783_s21, boba783);
}
END_TEST

START_TEST(bebasik__784) {
char boba784_s21[10000];
char boba784[10000];
ck_assert_int_eq(s21_sprintf(boba784_s21, "%+8.0ik%+f% 5hd6js%-5.0st%-2.6d4%+2hiodm% 10.0hi%+.0hdn%+hd", 693011, 1172.5017077717487, 15949, "[j;1=$#7v.auv7", -950822, 25786, -7769, 26809, 3650),
sprintf(boba784, "%+8.0ik%+f% 5hd6js%-5.0st%-2.6d4%+2hiodm% 10.0hi%+.0hdn%+hd", 693011, 1172.5017077717487, 15949, "[j;1=$#7v.auv7", -950822, 25786, -7769, 26809, 3650));
ck_assert_str_eq(boba784_s21, boba784);
}
END_TEST

START_TEST(bebasik__785) {
char boba785_s21[10000];
char boba785[10000];
ck_assert_int_eq(s21_sprintf(boba785_s21, "% hiu% 6hd", -12016, 24433),
sprintf(boba785, "% hiu% 6hd", -12016, 24433));
ck_assert_str_eq(boba785_s21, boba785);
}
END_TEST

START_TEST(bebasik__786) {
char boba786_s21[10000];
char boba786[10000];
ck_assert_int_eq(s21_sprintf(boba786_s21, "%-1.9hd%-2hi%+.6hdf`%-4cw1o8w% 3fz*% .10hit%+2hi$%+.9f% 7hi3% fo1%+.8d%+.7iu@%+f%+hd%+10.3i(% f", 7270, -22004, 15820, '*', 3789.7602278072554, 26020, 26491, -1556.054196096428, 11938, -4283.147371469644, 43959, 99685, -3053.30079104303, -1509, 262834, -8529.407267050885),
sprintf(boba786, "%-1.9hd%-2hi%+.6hdf`%-4cw1o8w% 3fz*% .10hit%+2hi$%+.9f% 7hi3% fo1%+.8d%+.7iu@%+f%+hd%+10.3i(% f", 7270, -22004, 15820, '*', 3789.7602278072554, 26020, 26491, -1556.054196096428, 11938, -4283.147371469644, 43959, 99685, -3053.30079104303, -1509, 262834, -8529.407267050885));
ck_assert_str_eq(boba786_s21, boba786);
}
END_TEST

START_TEST(bebasik__787) {
char boba787_s21[10000];
char boba787[10000];
ck_assert_int_eq(s21_sprintf(boba787_s21, "%+hd%+8hd% i(%+5.3f4,f%-1hu%+2.1i=1% 1.3hd%+7i%-d% hdna%-2d@%+6.1hi%+1.8hd^%-10.10hi9m% 4fd%+9hi%-.4hi%-i%+6.9hduzs% d%-1.4fm%-6hdh%-1hi)4%-9.0f", 13310, 31139, 573923, -13844.40533285849, -23000, -354312, 5813, 891678, 971798, -6989, -662631, -5380, -13785, 2804, 59.39703549473667, -30388, 4285, 485968, 15340, 201193, -7359.553979776138, -8258, 14410, -18326.178522820286),
sprintf(boba787, "%+hd%+8hd% i(%+5.3f4,f%-1hu%+2.1i=1% 1.3hd%+7i%-d% hdna%-2d@%+6.1hi%+1.8hd^%-10.10hi9m% 4fd%+9hi%-.4hi%-i%+6.9hduzs% d%-1.4fm%-6hdh%-1hi)4%-9.0f", 13310, 31139, 573923, -13844.40533285849, -23000, -354312, 5813, 891678, 971798, -6989, -662631, -5380, -13785, 2804, 59.39703549473667, -30388, 4285, 485968, 15340, 201193, -7359.553979776138, -8258, 14410, -18326.178522820286));
ck_assert_str_eq(boba787_s21, boba787);
}
END_TEST

START_TEST(bebasik__788) {
char boba788_s21[10000];
char boba788[10000];
ck_assert_int_eq(s21_sprintf(boba788_s21, "% f%-ub%-2.7s% 6.5hd% f,%-7u1!!% hi% hd% .6hi%+.1hd", -14180.4724569185, -77060, "46o", 21412, -804.548292028826, -796902, 7571, -20358, -7727, -2672),
sprintf(boba788, "% f%-ub%-2.7s% 6.5hd% f,%-7u1!!% hi% hd% .6hi%+.1hd", -14180.4724569185, -77060, "46o", 21412, -804.548292028826, -796902, 7571, -20358, -7727, -2672));
ck_assert_str_eq(boba788_s21, boba788);
}
END_TEST

START_TEST(bebasik__789) {
char boba789_s21[10000];
char boba789[10000];
ck_assert_int_eq(s21_sprintf(boba789_s21, "% .8f!% .4hd%+5.9hi%+.3hd", 29798.860985268853, 17735, -10980, 20679),
sprintf(boba789, "% .8f!% .4hd%+5.9hi%+.3hd", 29798.860985268853, 17735, -10980, 20679));
ck_assert_str_eq(boba789_s21, boba789);
}
END_TEST

START_TEST(bebasik__790) {
char boba790_s21[10000];
char boba790[10000];
ck_assert_int_eq(s21_sprintf(boba790_s21, "% .0hi%-.1hua%+.2hd4%-9.0dhm", 20498, -20542, -3147, 877729),
sprintf(boba790, "% .0hi%-.1hua%+.2hd4%-9.0dhm", 20498, -20542, -3147, 877729));
ck_assert_str_eq(boba790_s21, boba790);
}
END_TEST

START_TEST(bebasik__791) {
char boba791_s21[10000];
char boba791[10000];
ck_assert_int_eq(s21_sprintf(boba791_s21, "%+4d^6!w=%+1d%+8.1hi%+hinj% his4%-.9hur% 2.5hi%+i%+d%+5hi", -265682, 119539, 9909, 28402, 23608, -17872, -12820, -468513, -178462, -25757),
sprintf(boba791, "%+4d^6!w=%+1d%+8.1hi%+hinj% his4%-.9hur% 2.5hi%+i%+d%+5hi", -265682, 119539, 9909, 28402, 23608, -17872, -12820, -468513, -178462, -25757));
ck_assert_str_eq(boba791_s21, boba791);
}
END_TEST

START_TEST(bebasik__792) {
char boba792_s21[10000];
char boba792[10000];
ck_assert_int_eq(s21_sprintf(boba792_s21, "% .3fe% d% 6.7i%-1.8sf%+5.0hi%+9.5hd% 8.1ie&o).&% d%-scvl% .2hdt%-.1hu-^%+8f%+hi%+10d%-2.6d$%+hi(%-i&i% .7d5%-.7u5%-i%-hd", -1089.361038986605, 830887, 610423, "g", -7340, 20849, 920312, 226941, "v.bv,d[", -4221, 16381, -19778.30842889885, 14070, -848455, -495963, 8088, -124400, 407907, 489523, -13252, -21113),
sprintf(boba792, "% .3fe% d% 6.7i%-1.8sf%+5.0hi%+9.5hd% 8.1ie&o).&% d%-scvl% .2hdt%-.1hu-^%+8f%+hi%+10d%-2.6d$%+hi(%-i&i% .7d5%-.7u5%-i%-hd", -1089.361038986605, 830887, 610423, "g", -7340, 20849, 920312, 226941, "v.bv,d[", -4221, 16381, -19778.30842889885, 14070, -848455, -495963, 8088, -124400, 407907, 489523, -13252, -21113));
ck_assert_str_eq(boba792_s21, boba792);
}
END_TEST

START_TEST(bebasik__793) {
char boba793_s21[10000];
char boba793[10000];
ck_assert_int_eq(s21_sprintf(boba793_s21, "%-hdi% 10hd%+6i3n%+2i", 30331, -26727, 595454, 549780),
sprintf(boba793, "%-hdi% 10hd%+6i3n%+2i", 30331, -26727, 595454, 549780));
ck_assert_str_eq(boba793_s21, boba793);
}
END_TEST

START_TEST(bebasik__794) {
char boba794_s21[10000];
char boba794[10000];
ck_assert_int_eq(s21_sprintf(boba794_s21, "% 3.1hi7% is% 10hd% .1f;-% 7d6$*% d%+.2hi%-6.10hu%-hi&%+f[.-%+d8!%-7i%+1ic%+1.10f% 6.8hd5u%-hi6", -9500, 468409, 13765, -12214.602487136399, 751639, 671206, 1089, -5454, -16690, 17768.559835920983, 390229, 243887, 101839, -4768.9958068998985, 3736, -25035),
sprintf(boba794, "% 3.1hi7% is% 10hd% .1f;-% 7d6$*% d%+.2hi%-6.10hu%-hi&%+f[.-%+d8!%-7i%+1ic%+1.10f% 6.8hd5u%-hi6", -9500, 468409, 13765, -12214.602487136399, 751639, 671206, 1089, -5454, -16690, 17768.559835920983, 390229, 243887, 101839, -4768.9958068998985, 3736, -25035));
ck_assert_str_eq(boba794_s21, boba794);
}
END_TEST

START_TEST(bebasik__795) {
char boba795_s21[10000];
char boba795[10000];
ck_assert_int_eq(s21_sprintf(boba795_s21, "%-3.8ui,% 10hd,-%+d39", 952951, -21776, 23554),
sprintf(boba795, "%-3.8ui,% 10hd,-%+d39", 952951, -21776, 23554));
ck_assert_str_eq(boba795_s21, boba795);
}
END_TEST

START_TEST(bebasik__796) {
char boba796_s21[10000];
char boba796[10000];
ck_assert_int_eq(s21_sprintf(boba796_s21, "% .1hdo-l%-2.10i%+8.3i%-1u%+i% 10dp%-2i%+.0i%+9.4i%-u%-10.0hu%+hi%-.3i%+5i", -27449, 513850, 783956, 212339, -232205, -347016, 658705, 382370, 569520, 848364, 11093, 25405, -546543, 804085),
sprintf(boba796, "% .1hdo-l%-2.10i%+8.3i%-1u%+i% 10dp%-2i%+.0i%+9.4i%-u%-10.0hu%+hi%-.3i%+5i", -27449, 513850, 783956, 212339, -232205, -347016, 658705, 382370, 569520, 848364, 11093, 25405, -546543, 804085));
ck_assert_str_eq(boba796_s21, boba796);
}
END_TEST

START_TEST(bebasik__797) {
char boba797_s21[10000];
char boba797[10000];
ck_assert_int_eq(s21_sprintf(boba797_s21, "%+4.0hdti", 11143),
sprintf(boba797, "%+4.0hdti", 11143));
ck_assert_str_eq(boba797_s21, boba797);
}
END_TEST

START_TEST(bebasik__798) {
char boba798_s21[10000];
char boba798[10000];
ck_assert_int_eq(s21_sprintf(boba798_s21, "% 2hd% 7.10hijwd#% 8hi%-u%-2c,%+8.8d%+4hd%+.10f1%+.10hd.%+7hd&*", 27947, -29013, 29922, -345024, '.', 961590, -3908, 961.9681494364829, -6624, 3609),
sprintf(boba798, "% 2hd% 7.10hijwd#% 8hi%-u%-2c,%+8.8d%+4hd%+.10f1%+.10hd.%+7hd&*", 27947, -29013, 29922, -345024, '.', 961590, -3908, 961.9681494364829, -6624, 3609));
ck_assert_str_eq(boba798_s21, boba798);
}
END_TEST

START_TEST(bebasik__799) {
char boba799_s21[10000];
char boba799[10000];
ck_assert_int_eq(s21_sprintf(boba799_s21, "%-c% .1ic% .9hd-%-1.1f%-9.9dg`%-.10i% 8hd% 1.6hd", 'i', -94288, 20698, -11807.022896722587, -171056, 292689, 13160, -9955),
sprintf(boba799, "%-c% .1ic% .9hd-%-1.1f%-9.9dg`%-.10i% 8hd% 1.6hd", 'i', -94288, 20698, -11807.022896722587, -171056, 292689, 13160, -9955));
ck_assert_str_eq(boba799_s21, boba799);
}
END_TEST

START_TEST(bebasik__800) {
char boba800_s21[10000];
char boba800[10000];
ck_assert_int_eq(s21_sprintf(boba800_s21, "%+2.9hd%-6hd*h", 16634, 5833),
sprintf(boba800, "%+2.9hd%-6hd*h", 16634, 5833));
ck_assert_str_eq(boba800_s21, boba800);
}
END_TEST

START_TEST(bebasik__801) {
char boba801_s21[10000];
char boba801[10000];
ck_assert_int_eq(s21_sprintf(boba801_s21, "%+.9hd% hiy%+.10i%-.5hd%-2dtdg`%+4hd3% 3i% .1dir*/;,%-1d%+6.4dxt%+5hi@%-1hu%-.3f`%+8.3i%+.2fxu%+10.1f-", -17529, 18284, 80692, 808, -710868, -23590, 515315, -442208, 219133, -81513, 31348, 9146, -22237.37631202151, -196602, 201.44369398490355, -6402.766101199407),
sprintf(boba801, "%+.9hd% hiy%+.10i%-.5hd%-2dtdg`%+4hd3% 3i% .1dir*/;,%-1d%+6.4dxt%+5hi@%-1hu%-.3f`%+8.3i%+.2fxu%+10.1f-", -17529, 18284, 80692, 808, -710868, -23590, 515315, -442208, 219133, -81513, 31348, 9146, -22237.37631202151, -196602, 201.44369398490355, -6402.766101199407));
ck_assert_str_eq(boba801_s21, boba801);
}
END_TEST

START_TEST(bebasik__802) {
char boba802_s21[10000];
char boba802[10000];
ck_assert_int_eq(s21_sprintf(boba802_s21, "% .3d% 6.8hi%-.1hi% .10hdf@% hiq%-3.8hi%-hd-% 8.6i%-hi%+i% 8.6d%-hu0%+d0^1%+.10hi(s%-1.4hi%-snl% .6f%-hd!3%+ih[[%+10i", -784362, 4212, 2492, 9876, -15204, -28737, 1941, 989937, 16418, 122272, 685569, -17602, 162751, 28933, 8416, ")2(mm70m", 2939.9669518413516, -27415, -111237, -467420),
sprintf(boba802, "% .3d% 6.8hi%-.1hi% .10hdf@% hiq%-3.8hi%-hd-% 8.6i%-hi%+i% 8.6d%-hu0%+d0^1%+.10hi(s%-1.4hi%-snl% .6f%-hd!3%+ih[[%+10i", -784362, 4212, 2492, 9876, -15204, -28737, 1941, 989937, 16418, 122272, 685569, -17602, 162751, 28933, 8416, ")2(mm70m", 2939.9669518413516, -27415, -111237, -467420));
ck_assert_str_eq(boba802_s21, boba802);
}
END_TEST

START_TEST(bebasik__803) {
char boba803_s21[10000];
char boba803[10000];
ck_assert_int_eq(s21_sprintf(boba803_s21, "%-3.6s-%-hu#x%+.3d9% hi%+.9fwt$o=a%-.0dq%-huiv% 5.4dj=unz%-hi/%+5.1f^% 2if% 9hdb% .9hd% 2.9fd%+.4ft&1% 10.9hdmi% 1hi&", "/nopvu50**4@*cfi7f.=^tl=&3", -30323, -773318, 25546, 11299.358739383735, 846863, -8758, 394054, 8196, 17751.371777171677, -79141, 24672, -25678, -6200.945808948386, -4965.601492689421, 18731, -3255),
sprintf(boba803, "%-3.6s-%-hu#x%+.3d9% hi%+.9fwt$o=a%-.0dq%-huiv% 5.4dj=unz%-hi/%+5.1f^% 2if% 9hdb% .9hd% 2.9fd%+.4ft&1% 10.9hdmi% 1hi&", "/nopvu50**4@*cfi7f.=^tl=&3", -30323, -773318, 25546, 11299.358739383735, 846863, -8758, 394054, 8196, 17751.371777171677, -79141, 24672, -25678, -6200.945808948386, -4965.601492689421, 18731, -3255));
ck_assert_str_eq(boba803_s21, boba803);
}
END_TEST

START_TEST(bebasik__804) {
char boba804_s21[10000];
char boba804[10000];
ck_assert_int_eq(s21_sprintf(boba804_s21, "% 8dbzn%-huot%+8.5hd%+4.1f%+f%-7d% .3hi1%-hd% .0dzk%-9c0%+5i7n%-7hiy[z6hv0%-7.7hi2g% 4hd% .6fbm%+5.7hd% .9f", -535586, 28138, 9805, 449.4313119011449, 2610.4561268442185, -458013, 27945, -3563, 468606, 'a', 390467, -28412, 12985, 8517, -10078.403663910101, 27865, -17378.095626790848),
sprintf(boba804, "% 8dbzn%-huot%+8.5hd%+4.1f%+f%-7d% .3hi1%-hd% .0dzk%-9c0%+5i7n%-7hiy[z6hv0%-7.7hi2g% 4hd% .6fbm%+5.7hd% .9f", -535586, 28138, 9805, 449.4313119011449, 2610.4561268442185, -458013, 27945, -3563, 468606, 'a', 390467, -28412, 12985, 8517, -10078.403663910101, 27865, -17378.095626790848));
ck_assert_str_eq(boba804_s21, boba804);
}
END_TEST

START_TEST(bebasik__805) {
char boba805_s21[10000];
char boba805[10000];
ck_assert_int_eq(s21_sprintf(boba805_s21, "%+.0f0%-7u6%-fr(f%-s3%-.9hu%+6hd%-.0sw^%-10.0df%-.8in%+.0i%-7.10hiv3#=#%+7.2hi% 5.6hd", -83.48567141870132, 491795, 3230.854922993613, "c6*i9sq^b3j", -26995, 12452, "j6m2/awpr4=j/h`i)ot4", -54083, 315513, -567411, 15321, 17103, -20020),
sprintf(boba805, "%+.0f0%-7u6%-fr(f%-s3%-.9hu%+6hd%-.0sw^%-10.0df%-.8in%+.0i%-7.10hiv3#=#%+7.2hi% 5.6hd", -83.48567141870132, 491795, 3230.854922993613, "c6*i9sq^b3j", -26995, 12452, "j6m2/awpr4=j/h`i)ot4", -54083, 315513, -567411, 15321, 17103, -20020));
ck_assert_str_eq(boba805_s21, boba805);
}
END_TEST

START_TEST(bebasik__806) {
char boba806_s21[10000];
char boba806[10000];
ck_assert_int_eq(s21_sprintf(boba806_s21, "%-c[;%-8s%-3.10sg%-.8d6%+.2d% 4hd%-5hu", '5', "p*x2,a!z5![5,;q-zq74)aidil^gh", "i(8$nnh89@awelpa-9q", 20016, 737406, 21171, 23780),
sprintf(boba806, "%-c[;%-8s%-3.10sg%-.8d6%+.2d% 4hd%-5hu", '5', "p*x2,a!z5![5,;q-zq74)aidil^gh", "i(8$nnh89@awelpa-9q", 20016, 737406, 21171, 23780));
ck_assert_str_eq(boba806_s21, boba806);
}
END_TEST

START_TEST(bebasik__807) {
char boba807_s21[10000];
char boba807[10000];
ck_assert_int_eq(s21_sprintf(boba807_s21, "%-.10s^% 2.6hi[% 4.5di% 4.3hdpf%-6hi%-.9hd%+.8i% 3.5hd3x%-1.7d% dg%-hu;y%-.4s%+1.7hdf%-4.8hu8% f$j% f1z9% .2hid%-hu% hij4n^i4@h,s", "a5i^.", -18160, 437219, -22089, -20223, -28187, 542261, -31027, -19351, 758904, 18022, "7$b3g3d", -26256, 6741, 5748.0707915049825, -371.8182849329067, -30695, -20663, -22329),
sprintf(boba807, "%-.10s^% 2.6hi[% 4.5di% 4.3hdpf%-6hi%-.9hd%+.8i% 3.5hd3x%-1.7d% dg%-hu;y%-.4s%+1.7hdf%-4.8hu8% f$j% f1z9% .2hid%-hu% hij4n^i4@h,s", "a5i^.", -18160, 437219, -22089, -20223, -28187, 542261, -31027, -19351, 758904, 18022, "7$b3g3d", -26256, 6741, 5748.0707915049825, -371.8182849329067, -30695, -20663, -22329));
ck_assert_str_eq(boba807_s21, boba807);
}
END_TEST

START_TEST(bebasik__808) {
char boba808_s21[10000];
char boba808[10000];
ck_assert_int_eq(s21_sprintf(boba808_s21, "%-hivu%-3.9hu%-i% dx&%+.5iv%+.4fz!(-8% 6.1i*-% 10hdgrfs%+.9i%+9.1f", -16552, -25989, -856912, -912986, -948096, 9928.40945863422, -365938, 10900, 557221, -11301.208951457857),
sprintf(boba808, "%-hivu%-3.9hu%-i% dx&%+.5iv%+.4fz!(-8% 6.1i*-% 10hdgrfs%+.9i%+9.1f", -16552, -25989, -856912, -912986, -948096, 9928.40945863422, -365938, 10900, 557221, -11301.208951457857));
ck_assert_str_eq(boba808_s21, boba808);
}
END_TEST

START_TEST(bebasik__809) {
char boba809_s21[10000];
char boba809[10000];
ck_assert_int_eq(s21_sprintf(boba809_s21, "%+.3i% i% 1d*)=%+hi%+.6hd2%+hd%+.5is%-1.6f/%-2hd%-10u% hdov% i*,% d% .3f(m% .3d.!)wi=ga%-.5u#% 8.5hdg%-.5s0x,%+.4hihx%-hif", 366063, 536471, -761252, -30810, -5254, -22434, 107825, 40.66896155519803, -26980, 865190, -27828, -140037, 290772, -13739.380424513096, -593221, -866736, 28373, "/b!!07dr#)$vhvtina,gq#mq1@l1^", -13766, 3960),
sprintf(boba809, "%+.3i% i% 1d*)=%+hi%+.6hd2%+hd%+.5is%-1.6f/%-2hd%-10u% hdov% i*,% d% .3f(m% .3d.!)wi=ga%-.5u#% 8.5hdg%-.5s0x,%+.4hihx%-hif", 366063, 536471, -761252, -30810, -5254, -22434, 107825, 40.66896155519803, -26980, 865190, -27828, -140037, 290772, -13739.380424513096, -593221, -866736, 28373, "/b!!07dr#)$vhvtina,gq#mq1@l1^", -13766, 3960));
ck_assert_str_eq(boba809_s21, boba809);
}
END_TEST

START_TEST(bebasik__810) {
char boba810_s21[10000];
char boba810[10000];
ck_assert_int_eq(s21_sprintf(boba810_s21, "% .6hd%-hd`% 3d%+6.7d(%-4.7hi", -27466, 28509, -181145, -976883, -27173),
sprintf(boba810, "% .6hd%-hd`% 3d%+6.7d(%-4.7hi", -27466, 28509, -181145, -976883, -27173));
ck_assert_str_eq(boba810_s21, boba810);
}
END_TEST

START_TEST(bebasik__811) {
char boba811_s21[10000];
char boba811[10000];
ck_assert_int_eq(s21_sprintf(boba811_s21, "%+10.5i%-8s@% 2.1hdj% 8.4hi", 161941, "97", 10824, -2363),
sprintf(boba811, "%+10.5i%-8s@% 2.1hdj% 8.4hi", 161941, "97", 10824, -2363));
ck_assert_str_eq(boba811_s21, boba811);
}
END_TEST

START_TEST(bebasik__812) {
char boba812_s21[10000];
char boba812[10000];
ck_assert_int_eq(s21_sprintf(boba812_s21, "% 5d3%+10hd% him% hij-% hd%+.10hd(vza$p% 4.2hdp%+9i7o^", -521979, -14625, -7348, -7562, 8716, -4943, 23640, 194926),
sprintf(boba812, "% 5d3%+10hd% him% hij-% hd%+.10hd(vza$p% 4.2hdp%+9i7o^", -521979, -14625, -7348, -7562, 8716, -4943, 23640, 194926));
ck_assert_str_eq(boba812_s21, boba812);
}
END_TEST

START_TEST(bebasik__813) {
char boba813_s21[10000];
char boba813[10000];
ck_assert_int_eq(s21_sprintf(boba813_s21, "%-.4hi%-10hu% .1hi%+hd)% hi% 1.8hd2%+.7f7%-2.2i% .4hi% 10hd%+hd%-c%+9.3hi%+6f%+.2d--% 3.4hd^j%-hu3.!", -2687, 24302, 6084, -23042, 17006, 12847, -9676.46132868217, -915894, -22345, 29548, -9178, 'y', -30573, -8649.49696911181, 703353, -31152, -17335),
sprintf(boba813, "%-.4hi%-10hu% .1hi%+hd)% hi% 1.8hd2%+.7f7%-2.2i% .4hi% 10hd%+hd%-c%+9.3hi%+6f%+.2d--% 3.4hd^j%-hu3.!", -2687, 24302, 6084, -23042, 17006, 12847, -9676.46132868217, -915894, -22345, 29548, -9178, 'y', -30573, -8649.49696911181, 703353, -31152, -17335));
ck_assert_str_eq(boba813_s21, boba813);
}
END_TEST

START_TEST(bebasik__814) {
char boba814_s21[10000];
char boba814[10000];
ck_assert_int_eq(s21_sprintf(boba814_s21, "%-1f%-9.1fy(h9`c%+9d%+hd1`% 8hiu%+d%-.6hd%+hd4%-hu#&6x/r%-.1hi%-6hi%+.8i% 1hd%-.10hd%-hd% .1i%+.3dl%-.10s/% 3f4% hd% d(", -18917.55485000995, 8166.152343429051, -722919, -22749, 10330, -344669, 3844, 20839, -22200, -27696, -29970, 912815, -13575, 27266, 497, -315715, -797520, "cq", -4149.6797870784885, -9605, -991746),
sprintf(boba814, "%-1f%-9.1fy(h9`c%+9d%+hd1`% 8hiu%+d%-.6hd%+hd4%-hu#&6x/r%-.1hi%-6hi%+.8i% 1hd%-.10hd%-hd% .1i%+.3dl%-.10s/% 3f4% hd% d(", -18917.55485000995, 8166.152343429051, -722919, -22749, 10330, -344669, 3844, 20839, -22200, -27696, -29970, 912815, -13575, 27266, 497, -315715, -797520, "cq", -4149.6797870784885, -9605, -991746));
ck_assert_str_eq(boba814_s21, boba814);
}
END_TEST

START_TEST(bebasik__815) {
char boba815_s21[10000];
char boba815[10000];
ck_assert_int_eq(s21_sprintf(boba815_s21, "%+1.6hi%-.5s@4%-hdn%+.2f(% 10.7hd%+f^%-5.1hd!%-8.2hdq%-3.6u%-5hd%+9f%-7.2hi% 3.6f%-4.0hu%+.3hi#7%-1f%-hdo% d%+2.3hiey% .9dh% hi`% 10hd", 30481, "`=cj", 31455, -21443.491676013404, -10931, -2248.240607496319, 24831, -12389, -333633, -28011, -17054.58883567344, -1670, 2769.4641210373957, -18164, 1693, 23825.85507783462, -7989, -943454, 24921, 571409, 27037, -10991),
sprintf(boba815, "%+1.6hi%-.5s@4%-hdn%+.2f(% 10.7hd%+f^%-5.1hd!%-8.2hdq%-3.6u%-5hd%+9f%-7.2hi% 3.6f%-4.0hu%+.3hi#7%-1f%-hdo% d%+2.3hiey% .9dh% hi`% 10hd", 30481, "`=cj", 31455, -21443.491676013404, -10931, -2248.240607496319, 24831, -12389, -333633, -28011, -17054.58883567344, -1670, 2769.4641210373957, -18164, 1693, 23825.85507783462, -7989, -943454, 24921, 571409, 27037, -10991));
ck_assert_str_eq(boba815_s21, boba815);
}
END_TEST

START_TEST(bebasik__816) {
char boba816_s21[10000];
char boba816[10000];
ck_assert_int_eq(s21_sprintf(boba816_s21, "%-.9hi% 10.3hd% 3hi%+6d% d% .2hi%+d%-10hd&inm,%+.7hd!%-hiw% 2.9hdj!u%+1.5hi% f%-hub%+.9f0%+9hi@p%+4.5hd", 18113, -5011, -15668, -74430, 356818, 31636, -145509, -1876, -5081, 4760, 26218, -27803, -16193.960182181747, 17640, -12403.91457339324, 29878, 13357),
sprintf(boba816, "%-.9hi% 10.3hd% 3hi%+6d% d% .2hi%+d%-10hd&inm,%+.7hd!%-hiw% 2.9hdj!u%+1.5hi% f%-hub%+.9f0%+9hi@p%+4.5hd", 18113, -5011, -15668, -74430, 356818, 31636, -145509, -1876, -5081, 4760, 26218, -27803, -16193.960182181747, 17640, -12403.91457339324, 29878, 13357));
ck_assert_str_eq(boba816_s21, boba816);
}
END_TEST

START_TEST(bebasik__817) {
char boba817_s21[10000];
char boba817[10000];
ck_assert_int_eq(s21_sprintf(boba817_s21, "%+.8f%-s%-3.7hi.% 2.8hd% 2hdma% 2hd% 9.9i% hi^% 2fbk% 4hi%+9hd%-.4dt.e%-2u%-.2hiw% 4.1fg%+hi[%+5hizu/b3v% f6/% 8hd% .8hd%+2.2f%+10.9hd", 7385.915201997137, "q-", 18960, -13046, 13871, -11455, 998425, -28043, -18646.184911865974, 5245, 1378, 699923, -252004, -14528, -16530.124487778194, 29504, -17594, -1363.555269622889, -22387, 15817, -17109.354246365117, -3646),
sprintf(boba817, "%+.8f%-s%-3.7hi.% 2.8hd% 2hdma% 2hd% 9.9i% hi^% 2fbk% 4hi%+9hd%-.4dt.e%-2u%-.2hiw% 4.1fg%+hi[%+5hizu/b3v% f6/% 8hd% .8hd%+2.2f%+10.9hd", 7385.915201997137, "q-", 18960, -13046, 13871, -11455, 998425, -28043, -18646.184911865974, 5245, 1378, 699923, -252004, -14528, -16530.124487778194, 29504, -17594, -1363.555269622889, -22387, 15817, -17109.354246365117, -3646));
ck_assert_str_eq(boba817_s21, boba817);
}
END_TEST

START_TEST(bebasik__818) {
char boba818_s21[10000];
char boba818[10000];
ck_assert_int_eq(s21_sprintf(boba818_s21, "% .5hi%+hitmcv%+hi%-hi%-d% .1f%-.4u%+.3dr% .5f%+5i% 6hdu% hd%+10.2hdt.%-hiy%+3hd82y%+.5f1", -485, -16266, -13828, -7468, -282767, -16345.566390654058, -23580, -649228, 10886.633797326866, -111586, 13790, 7358, 19698, 18105, 8221, 26327.88821418774),
sprintf(boba818, "% .5hi%+hitmcv%+hi%-hi%-d% .1f%-.4u%+.3dr% .5f%+5i% 6hdu% hd%+10.2hdt.%-hiy%+3hd82y%+.5f1", -485, -16266, -13828, -7468, -282767, -16345.566390654058, -23580, -649228, 10886.633797326866, -111586, 13790, 7358, 19698, 18105, 8221, 26327.88821418774));
ck_assert_str_eq(boba818_s21, boba818);
}
END_TEST

START_TEST(bebasik__819) {
char boba819_s21[10000];
char boba819[10000];
ck_assert_int_eq(s21_sprintf(boba819_s21, "%-hi%-3hd% .6dc%+i!% 8.7hd%+1.7hd% 3.7hi% .10f%-5.9hu% f% 3i%+4.3f% .6i5% 9.10hdc% 10f% .9d% hi% 4.7i%-3.4u%-8hu", 1209, 10896, -232441, 67942, 5557, -30539, -1840, 5067.851173573976, 30272, 16928.506599550117, 876701, -6375.802380194911, -194183, 29312, 1213.4210914471762, 205007, 8800, -33284, -612731, -18458),
sprintf(boba819, "%-hi%-3hd% .6dc%+i!% 8.7hd%+1.7hd% 3.7hi% .10f%-5.9hu% f% 3i%+4.3f% .6i5% 9.10hdc% 10f% .9d% hi% 4.7i%-3.4u%-8hu", 1209, 10896, -232441, 67942, 5557, -30539, -1840, 5067.851173573976, 30272, 16928.506599550117, 876701, -6375.802380194911, -194183, 29312, 1213.4210914471762, 205007, 8800, -33284, -612731, -18458));
ck_assert_str_eq(boba819_s21, boba819);
}
END_TEST

START_TEST(bebasik__820) {
char boba820_s21[10000];
char boba820[10000];
ck_assert_int_eq(s21_sprintf(boba820_s21, "%+ig%+1f% .5fcdc", -197840, 5825.332180932578, 975.6729080012445),
sprintf(boba820, "%+ig%+1f% .5fcdc", -197840, 5825.332180932578, 975.6729080012445));
ck_assert_str_eq(boba820_s21, boba820);
}
END_TEST

START_TEST(bebasik__821) {
char boba821_s21[10000];
char boba821[10000];
ck_assert_int_eq(s21_sprintf(boba821_s21, "%-hd%-2.10i% 6hi6%-d% 9d%+6.9f%+hd%-4s%-7.7f% hi%+.10hdf)h%+8.8du%-7sr%-5.8hd9y.(ji%-.5hd`/[dd38%+9hi!9%-7.7hi", -7438, 880483, 13046, 267795, -760390, -14.41409461102152, 22285, "wyw*)", 5965.354501550555, 1645, -9813, 352714, "&h0*no!ky1-mn-vt*y2&6^wbg2)r", 15788, -30327, 14703, 21615),
sprintf(boba821, "%-hd%-2.10i% 6hi6%-d% 9d%+6.9f%+hd%-4s%-7.7f% hi%+.10hdf)h%+8.8du%-7sr%-5.8hd9y.(ji%-.5hd`/[dd38%+9hi!9%-7.7hi", -7438, 880483, 13046, 267795, -760390, -14.41409461102152, 22285, "wyw*)", 5965.354501550555, 1645, -9813, 352714, "&h0*no!ky1-mn-vt*y2&6^wbg2)r", 15788, -30327, 14703, 21615));
ck_assert_str_eq(boba821_s21, boba821);
}
END_TEST

START_TEST(bebasik__822) {
char boba822_s21[10000];
char boba822[10000];
ck_assert_int_eq(s21_sprintf(boba822_s21, "%+7i%-4hi% 6hdji%-4.3hdh,% hd% 2.5i%-hu%-8.5hi=`@%-5.0hd% 4.2hi%-6s", 236030, -20210, -21033, -10182, 20474, 764115, -8784, -29699, 10593, 29223, "qk)@^6s33me*7hz29!pxbhm4"),
sprintf(boba822, "%+7i%-4hi% 6hdji%-4.3hdh,% hd% 2.5i%-hu%-8.5hi=`@%-5.0hd% 4.2hi%-6s", 236030, -20210, -21033, -10182, 20474, 764115, -8784, -29699, 10593, 29223, "qk)@^6s33me*7hz29!pxbhm4"));
ck_assert_str_eq(boba822_s21, boba822);
}
END_TEST

START_TEST(bebasik__823) {
char boba823_s21[10000];
char boba823[10000];
ck_assert_int_eq(s21_sprintf(boba823_s21, "%+.0hi$% 4d%-1hd%-hdo%+.3f% .4f", 11965, 381533, 28467, 30877, -6018.488996100805, -6406.754967241873),
sprintf(boba823, "%+.0hi$% 4d%-1hd%-hdo%+.3f% .4f", 11965, 381533, 28467, 30877, -6018.488996100805, -6406.754967241873));
ck_assert_str_eq(boba823_s21, boba823);
}
END_TEST

START_TEST(bebasik__824) {
char boba824_s21[10000];
char boba824[10000];
ck_assert_int_eq(s21_sprintf(boba824_s21, "% 3hi.`%-2u%+2.5hdqrsb^%-s&b%-.3s1% .0hi0", 3773, -206304, 11269, "h*1@lbfo6@w=ym[72&9!pad", "!p!o^7e[&@", -20246),
sprintf(boba824, "% 3hi.`%-2u%+2.5hdqrsb^%-s&b%-.3s1% .0hi0", 3773, -206304, 11269, "h*1@lbfo6@w=ym[72&9!pad", "!p!o^7e[&@", -20246));
ck_assert_str_eq(boba824_s21, boba824);
}
END_TEST

START_TEST(bebasik__825) {
char boba825_s21[10000];
char boba825[10000];
ck_assert_int_eq(s21_sprintf(boba825_s21, "%-ff%+.8hi%+.8hd%+3.7d% .5hig[% 10hd$1s%+4hi% 1its% d,f%-.2u%+2d^", -12694.924892591296, 3224, -8777, 780910, -3200, -24031, 23043, -907237, -508898, 349184, 412657),
sprintf(boba825, "%-ff%+.8hi%+.8hd%+3.7d% .5hig[% 10hd$1s%+4hi% 1its% d,f%-.2u%+2d^", -12694.924892591296, 3224, -8777, 780910, -3200, -24031, 23043, -907237, -508898, 349184, 412657));
ck_assert_str_eq(boba825_s21, boba825);
}
END_TEST

START_TEST(bebasik__826) {
char boba826_s21[10000];
char boba826[10000];
ck_assert_int_eq(s21_sprintf(boba826_s21, "%+.5f% 10ia%+d%-.8ijk%-d% 2ij% .10hi%+.2hi%+ds%-hua%-10hu%+d%-hu$e4^%-1.8s% hd%+.3i*", 1844.3758322643857, -895911, 130360, 878444, -588692, 569632, -29968, -17157, -979099, -22365, 12705, -427721, 16553, "ff`zt*!m", -3358, 736818),
sprintf(boba826, "%+.5f% 10ia%+d%-.8ijk%-d% 2ij% .10hi%+.2hi%+ds%-hua%-10hu%+d%-hu$e4^%-1.8s% hd%+.3i*", 1844.3758322643857, -895911, 130360, 878444, -588692, 569632, -29968, -17157, -979099, -22365, 12705, -427721, 16553, "ff`zt*!m", -3358, 736818));
ck_assert_str_eq(boba826_s21, boba826);
}
END_TEST

START_TEST(bebasik__827) {
char boba827_s21[10000];
char boba827[10000];
ck_assert_int_eq(s21_sprintf(boba827_s21, "%+.10ig%-.8i1%-s;%-.9hd", -572632, 282563, "p&oo*y4qcg=.$^s26$qxy5", 12020),
sprintf(boba827, "%+.10ig%-.8i1%-s;%-.9hd", -572632, 282563, "p&oo*y4qcg=.$^s26$qxy5", 12020));
ck_assert_str_eq(boba827_s21, boba827);
}
END_TEST

START_TEST(bebasik__828) {
char boba828_s21[10000];
char boba828[10000];
ck_assert_int_eq(s21_sprintf(boba828_s21, "% 7f!^%+10hir^g`%+d%+1hd% .0fw%-8.6hu%+.1hi(%-10db1;%-.4hu% d%-.6hiq% hds7% 3hd%-huq%+.9hd31% 8f%+.9hicydj% 1.7d% 10fcc", 3448.5662745329114, -17932, 897061, 24195, -14107.843248024867, 583, -31670, 967656, 26788, -297468, -11214, 22621, -14116, 30869, -27661, -19107.837523343136, 9413, 541157, -1875.9348819524669),
sprintf(boba828, "% 7f!^%+10hir^g`%+d%+1hd% .0fw%-8.6hu%+.1hi(%-10db1;%-.4hu% d%-.6hiq% hds7% 3hd%-huq%+.9hd31% 8f%+.9hicydj% 1.7d% 10fcc", 3448.5662745329114, -17932, 897061, 24195, -14107.843248024867, 583, -31670, 967656, 26788, -297468, -11214, 22621, -14116, 30869, -27661, -19107.837523343136, 9413, 541157, -1875.9348819524669));
ck_assert_str_eq(boba828_s21, boba828);
}
END_TEST

START_TEST(bebasik__829) {
char boba829_s21[10000];
char boba829[10000];
ck_assert_int_eq(s21_sprintf(boba829_s21, "% f%+2hdj;m%+2.6d%+.10d[y%-hu% hi% f% hd%+8fx%+3.10hd%-6hi%+6hi%-3.0hi%+.4d%-.0hdt$% hil/% hil% .0du", -13846.97044884536, -23731, 89175, 495123, -2770, 17808, 996.9966394409752, 24704, -10191.84963066007, -25421, -13884, -5863, 26382, -91488, 25269, -184, -25534, -709426),
sprintf(boba829, "% f%+2hdj;m%+2.6d%+.10d[y%-hu% hi% f% hd%+8fx%+3.10hd%-6hi%+6hi%-3.0hi%+.4d%-.0hdt$% hil/% hil% .0du", -13846.97044884536, -23731, 89175, 495123, -2770, 17808, 996.9966394409752, 24704, -10191.84963066007, -25421, -13884, -5863, 26382, -91488, 25269, -184, -25534, -709426));
ck_assert_str_eq(boba829_s21, boba829);
}
END_TEST

START_TEST(bebasik__830) {
char boba830_s21[10000];
char boba830[10000];
ck_assert_int_eq(s21_sprintf(boba830_s21, "%-6hd,x%+.2d% i% 6.3ir%+10.2f3%+.2f%-4.8u% 8.0f(m%-hi%+d#a%-hik%-f-(*% 10.2f;`%+fk,.%-3hi%+.7hdp%-.3hdm*g%+i", 12659, 58947, -968708, -155139, 619.0553719687429, 1780.060037248467, 474907, -10575.487384170565, -3938, 98100, -21341, 8197.53702058216, -15083.758806449874, -20493.69008492305, 14677, -13407, 7052, 478856),
sprintf(boba830, "%-6hd,x%+.2d% i% 6.3ir%+10.2f3%+.2f%-4.8u% 8.0f(m%-hi%+d#a%-hik%-f-(*% 10.2f;`%+fk,.%-3hi%+.7hdp%-.3hdm*g%+i", 12659, 58947, -968708, -155139, 619.0553719687429, 1780.060037248467, 474907, -10575.487384170565, -3938, 98100, -21341, 8197.53702058216, -15083.758806449874, -20493.69008492305, 14677, -13407, 7052, 478856));
ck_assert_str_eq(boba830_s21, boba830);
}
END_TEST

START_TEST(bebasik__831) {
char boba831_s21[10000];
char boba831[10000];
ck_assert_int_eq(s21_sprintf(boba831_s21, "%-.10i,%+.9hd9% hi%+6hd%-1.8hi[i%-10f%+4hda% hd`97r%+2d%+f)%+.3da%+.5hdz%+6.10hd%+1hd%+1.6f%+10.2i% i4%-1hu% 2.5d8hp% .1hi% 6d", -160332, 11917, -6344, -16815, 23592, -1803.8276955107594, 13669, 24118, -505811, 8663.558849395951, 118893, 2225, -18839, -16011, 11657.250729480998, 827133, 991946, 1557, -555437, 25657, -202642),
sprintf(boba831, "%-.10i,%+.9hd9% hi%+6hd%-1.8hi[i%-10f%+4hda% hd`97r%+2d%+f)%+.3da%+.5hdz%+6.10hd%+1hd%+1.6f%+10.2i% i4%-1hu% 2.5d8hp% .1hi% 6d", -160332, 11917, -6344, -16815, 23592, -1803.8276955107594, 13669, 24118, -505811, 8663.558849395951, 118893, 2225, -18839, -16011, 11657.250729480998, 827133, 991946, 1557, -555437, 25657, -202642));
ck_assert_str_eq(boba831_s21, boba831);
}
END_TEST

START_TEST(bebasik__832) {
char boba832_s21[10000];
char boba832[10000];
ck_assert_int_eq(s21_sprintf(boba832_s21, "%+da% d&% 1.9hd% 10.7f%+5hd% f4%+8.6i4[r%-6hi=@4%-5hi%-.0hu`w%-6.2hu7%-s%-10.5hu%-8u=%-10hu%+10.2i%-6.10d/6n%-f", 258192, 798072, 22244, -4312.931701562766, 30668, -6775.507061533989, -502963, -24120, -27461, 17426, -12356, "&blli-)n", -4860, -164589, 3446, 870996, -4229, 5328.285133072665),
sprintf(boba832, "%+da% d&% 1.9hd% 10.7f%+5hd% f4%+8.6i4[r%-6hi=@4%-5hi%-.0hu`w%-6.2hu7%-s%-10.5hu%-8u=%-10hu%+10.2i%-6.10d/6n%-f", 258192, 798072, 22244, -4312.931701562766, 30668, -6775.507061533989, -502963, -24120, -27461, 17426, -12356, "&blli-)n", -4860, -164589, 3446, 870996, -4229, 5328.285133072665));
ck_assert_str_eq(boba832_s21, boba832);
}
END_TEST

START_TEST(bebasik__833) {
char boba833_s21[10000];
char boba833[10000];
ck_assert_int_eq(s21_sprintf(boba833_s21, "%+4hi/%-4.1ucf(% hi% 4hd%-iz% 1.0i%+9d9", -22518, -203058, 8534, 8441, -156868, 888729, -793554),
sprintf(boba833, "%+4hi/%-4.1ucf(% hi% 4hd%-iz% 1.0i%+9d9", -22518, -203058, 8534, 8441, -156868, 888729, -793554));
ck_assert_str_eq(boba833_s21, boba833);
}
END_TEST

START_TEST(bebasik__834) {
char boba834_s21[10000];
char boba834[10000];
ck_assert_int_eq(s21_sprintf(boba834_s21, "%+hd%+d%-hd%+i2%+3.0id,%-6.7hd%+d%+d% f)*%-5sh%+9.6hd%-5i!b%+i%-7d%+6hin%-7.3hu24% .0hi%+3hi% hi% 10.1hi", 30515, -257726, 11767, -353877, -759107, -23807, 100734, -664009, -4889.823960279087, "s4h3b7j=uh", 5993, -699050, 547169, -403903, -7091, 13343, 16543, 21980, 17371, 7074),
sprintf(boba834, "%+hd%+d%-hd%+i2%+3.0id,%-6.7hd%+d%+d% f)*%-5sh%+9.6hd%-5i!b%+i%-7d%+6hin%-7.3hu24% .0hi%+3hi% hi% 10.1hi", 30515, -257726, 11767, -353877, -759107, -23807, 100734, -664009, -4889.823960279087, "s4h3b7j=uh", 5993, -699050, 547169, -403903, -7091, 13343, 16543, 21980, 17371, 7074));
ck_assert_str_eq(boba834_s21, boba834);
}
END_TEST

START_TEST(bebasik__835) {
char boba835_s21[10000];
char boba835[10000];
ck_assert_int_eq(s21_sprintf(boba835_s21, "%+dk%+f% .6hd% hir#%-3.7s% 2hi% .9d% .7i%-.7f%+8.9hdx@% 5.7hd..", -884078, -10438.185837655443, 26016, 25942, "*,ygj8p484ajd[*);!jp", 20861, 100978, 940360, 1606.995458699889, -26147, -739),
sprintf(boba835, "%+dk%+f% .6hd% hir#%-3.7s% 2hi% .9d% .7i%-.7f%+8.9hdx@% 5.7hd..", -884078, -10438.185837655443, 26016, 25942, "*,ygj8p484ajd[*);!jp", 20861, 100978, 940360, 1606.995458699889, -26147, -739));
ck_assert_str_eq(boba835_s21, boba835);
}
END_TEST

START_TEST(bebasik__836) {
char boba836_s21[10000];
char boba836[10000];
ck_assert_int_eq(s21_sprintf(boba836_s21, "%-6hu%+hd%+9hd.%+d% 6ikwlp%-10.5hi%+.8f%-.2d%-10.3hivx%-hix4%+.8f% 6.6ipz%-.3s% i%-.0sz% .3d%+hd% 7.6i%+d%+hd%+.0i#%-2co%+i% .2d", 1094, 19774, -8697, -190506, -885215, -14272, 11798.523145055848, -916346, 16590, 26822, 2982.1450283229265, -784450, "j", -460877, "@lu0l&omk", 676631, 21993, 358316, -367015, -16620, -54930, '8', 70166, -953883),
sprintf(boba836, "%-6hu%+hd%+9hd.%+d% 6ikwlp%-10.5hi%+.8f%-.2d%-10.3hivx%-hix4%+.8f% 6.6ipz%-.3s% i%-.0sz% .3d%+hd% 7.6i%+d%+hd%+.0i#%-2co%+i% .2d", 1094, 19774, -8697, -190506, -885215, -14272, 11798.523145055848, -916346, 16590, 26822, 2982.1450283229265, -784450, "j", -460877, "@lu0l&omk", 676631, 21993, 358316, -367015, -16620, -54930, '8', 70166, -953883));
ck_assert_str_eq(boba836_s21, boba836);
}
END_TEST

START_TEST(bebasik__837) {
char boba837_s21[10000];
char boba837[10000];
ck_assert_int_eq(s21_sprintf(boba837_s21, "%+hi^4a.$%+10hiv%+2.1hd1%+.3iv% hi%+.5f%+6.8d%+7f%+10f$%-.6hd% .3i0% .6d%-d6,^%+.5f% 10.6hi%-hu1oh% 9hi5`c%+.2i/%-ci%+1.6f;%-.0hi847", -9691, -13112, 25905, -618398, -8819, -6410.77231245217, 722860, -332.9785067891809, -5026.440330438287, 18983, 370263, -689169, -304438, 2739.9971069798703, -25341, -15874, 30305, 23169, '9', -140.86007755421113, -14837),
sprintf(boba837, "%+hi^4a.$%+10hiv%+2.1hd1%+.3iv% hi%+.5f%+6.8d%+7f%+10f$%-.6hd% .3i0% .6d%-d6,^%+.5f% 10.6hi%-hu1oh% 9hi5`c%+.2i/%-ci%+1.6f;%-.0hi847", -9691, -13112, 25905, -618398, -8819, -6410.77231245217, 722860, -332.9785067891809, -5026.440330438287, 18983, 370263, -689169, -304438, 2739.9971069798703, -25341, -15874, 30305, 23169, '9', -140.86007755421113, -14837));
ck_assert_str_eq(boba837_s21, boba837);
}
END_TEST

START_TEST(bebasik__838) {
char boba838_s21[10000];
char boba838[10000];
ck_assert_int_eq(s21_sprintf(boba838_s21, "%-8.2iay% 5f% 2.6hi%+1.4hi% 4hiqk%+hd;% 10hd%-5hu&^lz.2g%+f", -234507, -1314.65412854749, 1691, -18580, 23513, -18559, -26434, 5064, -14845.354728427155),
sprintf(boba838, "%-8.2iay% 5f% 2.6hi%+1.4hi% 4hiqk%+hd;% 10hd%-5hu&^lz.2g%+f", -234507, -1314.65412854749, 1691, -18580, 23513, -18559, -26434, 5064, -14845.354728427155));
ck_assert_str_eq(boba838_s21, boba838);
}
END_TEST

START_TEST(bebasik__839) {
char boba839_s21[10000];
char boba839[10000];
ck_assert_int_eq(s21_sprintf(boba839_s21, "%+6.3i%-4.6hi%+10hi6%-9hii%+3d5=u7% 1dv%+6d%-.9hu%+.2hiq*,%+9.8i5y%-.7fwzz%+2hd&%+.4hi&`m0i9,%-us/%+8d% .4i%-d%-10hd%-4.9hd% 7.10hi%-10d%+hdk%-hi", -558851, -10171, 998, 18721, -808664, 642743, 518226, 14385, -23664, 610261, -657.6077432585648, 17607, 24186, -417823, 617810, 873003, -560694, -27590, 7545, 3432, 859201, -24417, 21129),
sprintf(boba839, "%+6.3i%-4.6hi%+10hi6%-9hii%+3d5=u7% 1dv%+6d%-.9hu%+.2hiq*,%+9.8i5y%-.7fwzz%+2hd&%+.4hi&`m0i9,%-us/%+8d% .4i%-d%-10hd%-4.9hd% 7.10hi%-10d%+hdk%-hi", -558851, -10171, 998, 18721, -808664, 642743, 518226, 14385, -23664, 610261, -657.6077432585648, 17607, 24186, -417823, 617810, 873003, -560694, -27590, 7545, 3432, 859201, -24417, 21129));
ck_assert_str_eq(boba839_s21, boba839);
}
END_TEST

START_TEST(bebasik__840) {
char boba840_s21[10000];
char boba840[10000];
ck_assert_int_eq(s21_sprintf(boba840_s21, "%+.9hi8% 6.3hdwo,%-hu%+.3f%-5hd% d% 1.10hd%+10.1hd;`%+hix%+.5i@0% 8hi&(ab%+5.2hi%+8hd=p=.%+.10hi%+.10fd%-hi% hif%-9d#% .0i;9%-7hd% .8hduv% 8d%+.1i%-7.9uyh", 18111, -6699, 30495, 799.0426873084416, 22885, -110598, -2521, 1970, -6374, -822545, -31388, 28434, 2130, 21275, -5808.644256533467, 19891, 13523, 320567, 372295, -31611, 16775, -47729, 484000, -381795),
sprintf(boba840, "%+.9hi8% 6.3hdwo,%-hu%+.3f%-5hd% d% 1.10hd%+10.1hd;`%+hix%+.5i@0% 8hi&(ab%+5.2hi%+8hd=p=.%+.10hi%+.10fd%-hi% hif%-9d#% .0i;9%-7hd% .8hduv% 8d%+.1i%-7.9uyh", 18111, -6699, 30495, 799.0426873084416, 22885, -110598, -2521, 1970, -6374, -822545, -31388, 28434, 2130, 21275, -5808.644256533467, 19891, 13523, 320567, 372295, -31611, 16775, -47729, 484000, -381795));
ck_assert_str_eq(boba840_s21, boba840);
}
END_TEST

START_TEST(bebasik__841) {
char boba841_s21[10000];
char boba841[10000];
ck_assert_int_eq(s21_sprintf(boba841_s21, "% 8.2hi% hi&%+.4hi%-6hdn% du%+8ik%-.3us!j;%-3.5hi1%-8.3hi7.%+hd[=%+4.4hi%+fr%+1.1i% i`%-8.8hi%-3.8hd)$%-2u%-.6hd%-.8uje% .4hiiyl%+3.10f6", 16965, -11730, 18679, 2273, -968556, 396873, 914924, -24056, 11960, 28172, -12208, -19469.06841852098, -459463, -994229, 26133, 28669, 531180, -5668, -178600, -27487, 20013.974937242117),
sprintf(boba841, "% 8.2hi% hi&%+.4hi%-6hdn% du%+8ik%-.3us!j;%-3.5hi1%-8.3hi7.%+hd[=%+4.4hi%+fr%+1.1i% i`%-8.8hi%-3.8hd)$%-2u%-.6hd%-.8uje% .4hiiyl%+3.10f6", 16965, -11730, 18679, 2273, -968556, 396873, 914924, -24056, 11960, 28172, -12208, -19469.06841852098, -459463, -994229, 26133, 28669, 531180, -5668, -178600, -27487, 20013.974937242117));
ck_assert_str_eq(boba841_s21, boba841);
}
END_TEST

START_TEST(bebasik__842) {
char boba842_s21[10000];
char boba842[10000];
ck_assert_int_eq(s21_sprintf(boba842_s21, "% 2f%+1i%+.5hiw&s8%-.3u0@j6% i%+4d%-10.6hu% 9.8hi4u%+.6d8hx[%-.2d%-.7hu%-hd%-10hucg%+.8f%+3.2hi% hd% .3hd%-hd", 2846.320186627786, 188089, -25538, -732129, -174018, -288716, 18500, -3708, -354012, -410240, -3127, -14621, 19005, 3013.810067625563, -20249, 887, -94, 320),
sprintf(boba842, "% 2f%+1i%+.5hiw&s8%-.3u0@j6% i%+4d%-10.6hu% 9.8hi4u%+.6d8hx[%-.2d%-.7hu%-hd%-10hucg%+.8f%+3.2hi% hd% .3hd%-hd", 2846.320186627786, 188089, -25538, -732129, -174018, -288716, 18500, -3708, -354012, -410240, -3127, -14621, 19005, 3013.810067625563, -20249, 887, -94, 320));
ck_assert_str_eq(boba842_s21, boba842);
}
END_TEST

START_TEST(bebasik__843) {
char boba843_s21[10000];
char boba843[10000];
ck_assert_int_eq(s21_sprintf(boba843_s21, "%+7.5i%-.0hd% d%+hi%+hd% i%-.2hd&5", 871937, 18052, -951939, 20625, -12423, -79275, -31831),
sprintf(boba843, "%+7.5i%-.0hd% d%+hi%+hd% i%-.2hd&5", 871937, 18052, -951939, 20625, -12423, -79275, -31831));
ck_assert_str_eq(boba843_s21, boba843);
}
END_TEST

START_TEST(bebasik__844) {
char boba844_s21[10000];
char boba844[10000];
ck_assert_int_eq(s21_sprintf(boba844_s21, "% 9.10hi%-.1i%+.10hi% 7d$%+3.7hi^%-3.9hd;6f%-.9hi% 7.2d,%+dq%+i% .4d%-ca%-hi% .4d!% .7hid% 7.2d)8% .7f% 10.6hdj% i", -8130, -924933, 1213, 222687, -27134, 14824, -30732, -79062, 503611, -699729, 234274, 'k', 20028, -644955, -14691, 961457, 8457.086561509343, -25420, -582829),
sprintf(boba844, "% 9.10hi%-.1i%+.10hi% 7d$%+3.7hi^%-3.9hd;6f%-.9hi% 7.2d,%+dq%+i% .4d%-ca%-hi% .4d!% .7hid% 7.2d)8% .7f% 10.6hdj% i", -8130, -924933, 1213, 222687, -27134, 14824, -30732, -79062, 503611, -699729, 234274, 'k', 20028, -644955, -14691, 961457, 8457.086561509343, -25420, -582829));
ck_assert_str_eq(boba844_s21, boba844);
}
END_TEST

START_TEST(bebasik__845) {
char boba845_s21[10000];
char boba845[10000];
ck_assert_int_eq(s21_sprintf(boba845_s21, "%-1hi% 9hi% 3.8i% d% .2hd% 1.3hiw", 1417, 30981, -422541, 720538, -16579, -5473),
sprintf(boba845, "%-1hi% 9hi% 3.8i% d% .2hd% 1.3hiw", 1417, 30981, -422541, 720538, -16579, -5473));
ck_assert_str_eq(boba845_s21, boba845);
}
END_TEST

START_TEST(bebasik__846) {
char boba846_s21[10000];
char boba846[10000];
ck_assert_int_eq(s21_sprintf(boba846_s21, "%-7.8s%+5.6hd%-8hi*3", "u;=q3zemnf^u#lhvj6jo47z", 31299, -7362),
sprintf(boba846, "%-7.8s%+5.6hd%-8hi*3", "u;=q3zemnf^u#lhvj6jo47z", 31299, -7362));
ck_assert_str_eq(boba846_s21, boba846);
}
END_TEST

START_TEST(bebasik__847) {
char boba847_s21[10000];
char boba847[10000];
ck_assert_int_eq(s21_sprintf(boba847_s21, "% d=@%-4.8hi7%+10.8hi@%+4fj%-8.8hd%-s% .6i%+2i% 10hdi%+9.1f%+.6hd% d%+5.3d%+hiv(55%+.1hi% .3hi0yz%+4f%+f", -728163, -20582, -1036, -21972.461193468655, 5325, "(*dm[hom", 743278, 185614, -9908, -1054.8013935738595, -26668, -881221, 960085, -29723, -27126, 21481, 7026.54150182188, -13147.65477617906),
sprintf(boba847, "% d=@%-4.8hi7%+10.8hi@%+4fj%-8.8hd%-s% .6i%+2i% 10hdi%+9.1f%+.6hd% d%+5.3d%+hiv(55%+.1hi% .3hi0yz%+4f%+f", -728163, -20582, -1036, -21972.461193468655, 5325, "(*dm[hom", 743278, 185614, -9908, -1054.8013935738595, -26668, -881221, 960085, -29723, -27126, 21481, 7026.54150182188, -13147.65477617906));
ck_assert_str_eq(boba847_s21, boba847);
}
END_TEST

START_TEST(bebasik__848) {
char boba848_s21[10000];
char boba848[10000];
ck_assert_int_eq(s21_sprintf(boba848_s21, "% 1d% hi[%+9.6hd2=% 8.5hi*@!% 2.10hd3;%+1fu%-10hi% 5.6f% d% 2hdhz3% .10hdk%+f%-10.1hu*% hd%+hd[%+6.6hd%+8hdl", 495436, -8411, 11011, 13456, -23169, 2404.2321442780385, -9040, 21050.314818288065, -967598, 12677, -24459, 11395.68860279043, -22718, 23606, -29354, 13288, -5972),
sprintf(boba848, "% 1d% hi[%+9.6hd2=% 8.5hi*@!% 2.10hd3;%+1fu%-10hi% 5.6f% d% 2hdhz3% .10hdk%+f%-10.1hu*% hd%+hd[%+6.6hd%+8hdl", 495436, -8411, 11011, 13456, -23169, 2404.2321442780385, -9040, 21050.314818288065, -967598, 12677, -24459, 11395.68860279043, -22718, 23606, -29354, 13288, -5972));
ck_assert_str_eq(boba848_s21, boba848);
}
END_TEST

START_TEST(bebasik__849) {
char boba849_s21[10000];
char boba849[10000];
ck_assert_int_eq(s21_sprintf(boba849_s21, "% 6hd% f3%+ixuw% 2.7f% .1hd%+4.6hd%-3.1i% 5hi8`%+6f4%+.9hi%-.1hu", -24031, -378.93501457793127, 190954, 591.9903965197432, -27442, -27971, 595115, 23240, 1064.082842773811, 22817, 18244),
sprintf(boba849, "% 6hd% f3%+ixuw% 2.7f% .1hd%+4.6hd%-3.1i% 5hi8`%+6f4%+.9hi%-.1hu", -24031, -378.93501457793127, 190954, 591.9903965197432, -27442, -27971, 595115, 23240, 1064.082842773811, 22817, 18244));
ck_assert_str_eq(boba849_s21, boba849);
}
END_TEST

START_TEST(bebasik__850) {
char boba850_s21[10000];
char boba850[10000];
ck_assert_int_eq(s21_sprintf(boba850_s21, "%+6hd@% 9hi0% ipl1%+4.0d^%-.6huvt%-u3%-u[9i,%+5.3hd30%-8.10f%+.6hi8% 7f`%-sn%+hii%+i.% 10.2hi6% .0hd%-5d%+6.7d% 4hi3%-.6f%+4.10hd%+.3d%-hd%+f/s^", 23374, 31462, -615901, 414440, -8933, 14887, -16599, 26239, 133.1234581464784, -25193, 12080.64047662543, "h4kr,!h44u&k7mb0n5p-lk$g6!,ao", -2080, 935641, -25414, 715, -192035, 357905, -26919, 3323.584439599133, -20365, -890425, -27829, 4971.057201467484),
sprintf(boba850, "%+6hd@% 9hi0% ipl1%+4.0d^%-.6huvt%-u3%-u[9i,%+5.3hd30%-8.10f%+.6hi8% 7f`%-sn%+hii%+i.% 10.2hi6% .0hd%-5d%+6.7d% 4hi3%-.6f%+4.10hd%+.3d%-hd%+f/s^", 23374, 31462, -615901, 414440, -8933, 14887, -16599, 26239, 133.1234581464784, -25193, 12080.64047662543, "h4kr,!h44u&k7mb0n5p-lk$g6!,ao", -2080, 935641, -25414, 715, -192035, 357905, -26919, 3323.584439599133, -20365, -890425, -27829, 4971.057201467484));
ck_assert_str_eq(boba850_s21, boba850);
}
END_TEST

START_TEST(bebasik__851) {
char boba851_s21[10000];
char boba851[10000];
ck_assert_int_eq(s21_sprintf(boba851_s21, "% f%-.3ds5w@%+4.1hd%+6.8dk)f5k@%+.3hi% hi%-i7%+1d/wh9n% 8.3fk4/%-9f;% .1f% .1f%+iq%-.9ie", 10866.297280602816, 629079, -2938, 346328, 24430, 31154, 698672, 502617, 7610.428784803965, 260.31346061518514, -26691.05240986685, 6551.026752423844, -551921, -319203),
sprintf(boba851, "% f%-.3ds5w@%+4.1hd%+6.8dk)f5k@%+.3hi% hi%-i7%+1d/wh9n% 8.3fk4/%-9f;% .1f% .1f%+iq%-.9ie", 10866.297280602816, 629079, -2938, 346328, 24430, 31154, 698672, 502617, 7610.428784803965, 260.31346061518514, -26691.05240986685, 6551.026752423844, -551921, -319203));
ck_assert_str_eq(boba851_s21, boba851);
}
END_TEST

START_TEST(bebasik__852) {
char boba852_s21[10000];
char boba852[10000];
ck_assert_int_eq(s21_sprintf(boba852_s21, "% 3.3hd%-2.3sc%-8hu%+.0ff% hd%-9.0spf%-.0hu%-s%+i%+.4i%-sp%+5.1i3%-.1d%+9i%-.8hi%+3hd,% .7i*`%-.0d%-7.3hd% 6hi% .8i%+2.1hig%+4du", 24087, ";`!3", 1762, -1067.8523750123295, -17291, ")jxo)qc6kbi", 19731, "s`48kt43*wizsc*)", 546927, 371, "", -183730, -76848, 19954, 716, -15607, -909786, -811763, 28601, 26623, 115070, 25783, -978003),
sprintf(boba852, "% 3.3hd%-2.3sc%-8hu%+.0ff% hd%-9.0spf%-.0hu%-s%+i%+.4i%-sp%+5.1i3%-.1d%+9i%-.8hi%+3hd,% .7i*`%-.0d%-7.3hd% 6hi% .8i%+2.1hig%+4du", 24087, ";`!3", 1762, -1067.8523750123295, -17291, ")jxo)qc6kbi", 19731, "s`48kt43*wizsc*)", 546927, 371, "", -183730, -76848, 19954, 716, -15607, -909786, -811763, 28601, 26623, 115070, 25783, -978003));
ck_assert_str_eq(boba852_s21, boba852);
}
END_TEST

START_TEST(bebasik__853) {
char boba853_s21[10000];
char boba853[10000];
ck_assert_int_eq(s21_sprintf(boba853_s21, "% d&#4@% d%+9ih%-6.6f%-1icj%+3d% 5hi%-ig% .3fij%+ib%-7hdl% 2f)d% 6.7hi% .1hdxw@", -997679, 786846, -660710, 28848.005390615595, -484503, -531812, -17160, -272861, -565.7395212348072, -104060, 3977, 9.327487465631512, -9859, -31573),
sprintf(boba853, "% d&#4@% d%+9ih%-6.6f%-1icj%+3d% 5hi%-ig% .3fij%+ib%-7hdl% 2f)d% 6.7hi% .1hdxw@", -997679, 786846, -660710, 28848.005390615595, -484503, -531812, -17160, -272861, -565.7395212348072, -104060, 3977, 9.327487465631512, -9859, -31573));
ck_assert_str_eq(boba853_s21, boba853);
}
END_TEST

START_TEST(bebasik__854) {
char boba854_s21[10000];
char boba854[10000];
ck_assert_int_eq(s21_sprintf(boba854_s21, "% .2i^#=r1sp% 1.9d&4v!8%+8.7f%-.8i%-i5%+f% 3f&6p%-hu`%+2.10hi),^^is%+4hi8y*`l%+d*=%-6hic[#%+.7dxpx", 24181, 956451, -860.2826407557424, -861884, -594195, 18925.582068874905, -15971.338221106596, 3343, 27989, -24162, -379556, 15076, -714737),
sprintf(boba854, "% .2i^#=r1sp% 1.9d&4v!8%+8.7f%-.8i%-i5%+f% 3f&6p%-hu`%+2.10hi),^^is%+4hi8y*`l%+d*=%-6hic[#%+.7dxpx", 24181, 956451, -860.2826407557424, -861884, -594195, 18925.582068874905, -15971.338221106596, 3343, 27989, -24162, -379556, 15076, -714737));
ck_assert_str_eq(boba854_s21, boba854);
}
END_TEST

START_TEST(bebasik__855) {
char boba855_s21[10000];
char boba855[10000];
ck_assert_int_eq(s21_sprintf(boba855_s21, "%+hieq%-3hu%-s3% hi% .10hdt3upu%-hd%+6hd% 7hd,7y%+.9hiowc", 16458, 20760, "bbyt-^i5;;yeth.nmco8fi7-57", -30373, 1889, -17940, -28838, -5356, -29038),
sprintf(boba855, "%+hieq%-3hu%-s3% hi% .10hdt3upu%-hd%+6hd% 7hd,7y%+.9hiowc", 16458, 20760, "bbyt-^i5;;yeth.nmco8fi7-57", -30373, 1889, -17940, -28838, -5356, -29038));
ck_assert_str_eq(boba855_s21, boba855);
}
END_TEST

START_TEST(bebasik__856) {
char boba856_s21[10000];
char boba856[10000];
ck_assert_int_eq(s21_sprintf(boba856_s21, "%+.7hd/%+6.2dxe% hif%-.5dy%+.3hdu% 8.9iz,4&hn=%-hib.o@", 10869, -372516, -29668, -151004, -7075, -444585, -4781),
sprintf(boba856, "%+.7hd/%+6.2dxe% hif%-.5dy%+.3hdu% 8.9iz,4&hn=%-hib.o@", 10869, -372516, -29668, -151004, -7075, -444585, -4781));
ck_assert_str_eq(boba856_s21, boba856);
}
END_TEST

START_TEST(bebasik__857) {
char boba857_s21[10000];
char boba857[10000];
ck_assert_int_eq(s21_sprintf(boba857_s21, "%-s% 9.4hik3%+10hdk%+7hi%+.3d% hd%-8.7hu,f% 9.0hd% 2.7fd;%+3.1hi%-2.5hu@%-1hu%+.0i%+4.7i% 4hd$5% .3hd", "o.jn*n^g3`xycg(.0h!9wj853dbb-", -18531, -22567, -10370, -72776, 8055, -28169, 27616, -23045.51105258119, 31824, 12289, 24016, -313331, -741358, 15812, 20724),
sprintf(boba857, "%-s% 9.4hik3%+10hdk%+7hi%+.3d% hd%-8.7hu,f% 9.0hd% 2.7fd;%+3.1hi%-2.5hu@%-1hu%+.0i%+4.7i% 4hd$5% .3hd", "o.jn*n^g3`xycg(.0h!9wj853dbb-", -18531, -22567, -10370, -72776, 8055, -28169, 27616, -23045.51105258119, 31824, 12289, 24016, -313331, -741358, 15812, 20724));
ck_assert_str_eq(boba857_s21, boba857);
}
END_TEST

START_TEST(bebasik__858) {
char boba858_s21[10000];
char boba858[10000];
ck_assert_int_eq(s21_sprintf(boba858_s21, "% fu2% .4hd%-8d", -13574.007664950685, -27051, 431256),
sprintf(boba858, "% fu2% .4hd%-8d", -13574.007664950685, -27051, 431256));
ck_assert_str_eq(boba858_s21, boba858);
}
END_TEST

START_TEST(bebasik__859) {
char boba859_s21[10000];
char boba859[10000];
ck_assert_int_eq(s21_sprintf(boba859_s21, "%-hi%+d%+hd%+.5hd[$%-.5f^% fvps%+3hiu% 4hd%+.2i^@j% hi9g5!%-9hub%+ibze#@%-.3hi%+.1hi", 29177, 240476, 15231, 5586, -8770.626570038305, -26105.4454142923, -13006, -21323, -638476, 15883, 10618, -115459, 13987, 9986),
sprintf(boba859, "%-hi%+d%+hd%+.5hd[$%-.5f^% fvps%+3hiu% 4hd%+.2i^@j% hi9g5!%-9hub%+ibze#@%-.3hi%+.1hi", 29177, 240476, 15231, 5586, -8770.626570038305, -26105.4454142923, -13006, -21323, -638476, 15883, 10618, -115459, 13987, 9986));
ck_assert_str_eq(boba859_s21, boba859);
}
END_TEST

START_TEST(bebasik__860) {
char boba860_s21[10000];
char boba860[10000];
ck_assert_int_eq(s21_sprintf(boba860_s21, "%-.1s% 2f% hd", "58,mm[l901,t.5##-58ww;j.", 7257.064967297791, -16190),
sprintf(boba860, "%-.1s% 2f% hd", "58,mm[l901,t.5##-58ww;j.", 7257.064967297791, -16190));
ck_assert_str_eq(boba860_s21, boba860);
}
END_TEST

START_TEST(bebasik__861) {
char boba861_s21[10000];
char boba861[10000];
ck_assert_int_eq(s21_sprintf(boba861_s21, "% 8hd%+.0d%+1.3i%-i%-5.7hi3v% 9d&%+hd!sl)&%-hu% 9hit6%-5.10huzp9% .3hd%-7.1hieiy%+hd;d% 6hd% 4.6d3k=p;%+.2hd^78% 2f,ys%+3io-% hds% .8hix% 2hd=3%-9hd% .7hi%+hd!", -16596, 284657, -938778, -468582, -21113, 632244, 13802, 4368, 10710, 17936, 17127, -27741, -2439, 26123, 884195, 17314, 4050.9507973950804, 57373, -1441, -11188, 15129, -2833, 28167, 30723),
sprintf(boba861, "% 8hd%+.0d%+1.3i%-i%-5.7hi3v% 9d&%+hd!sl)&%-hu% 9hit6%-5.10huzp9% .3hd%-7.1hieiy%+hd;d% 6hd% 4.6d3k=p;%+.2hd^78% 2f,ys%+3io-% hds% .8hix% 2hd=3%-9hd% .7hi%+hd!", -16596, 284657, -938778, -468582, -21113, 632244, 13802, 4368, 10710, 17936, 17127, -27741, -2439, 26123, 884195, 17314, 4050.9507973950804, 57373, -1441, -11188, 15129, -2833, 28167, 30723));
ck_assert_str_eq(boba861_s21, boba861);
}
END_TEST

START_TEST(bebasik__862) {
char boba862_s21[10000];
char boba862[10000];
ck_assert_int_eq(s21_sprintf(boba862_s21, "% d%-3hi`)i% 5d&%+.2di% hi% fvf6v%-9i1%-10d%-.1hdr4% d", 575300, -17036, -464769, 141512, -4147, -10716.284382942978, -996654, -857379, -18425, -102419),
sprintf(boba862, "% d%-3hi`)i% 5d&%+.2di% hi% fvf6v%-9i1%-10d%-.1hdr4% d", 575300, -17036, -464769, 141512, -4147, -10716.284382942978, -996654, -857379, -18425, -102419));
ck_assert_str_eq(boba862_s21, boba862);
}
END_TEST

START_TEST(bebasik__863) {
char boba863_s21[10000];
char boba863[10000];
ck_assert_int_eq(s21_sprintf(boba863_s21, "%-d=q% 6.10i%-hu% .1hi%-.10hu%+8dn2%+5.8hd,#% dc%-6.1i%+7hi% 7hi%-5.7f% .5hip% 1ii% 5.9i%+9.0d% 7.3fp%+.4d0%-u", 77231, 333626, 14913, 11088, -13470, -406710, 25992, -213512, -790145, 5162, 26575, -4840.453658998889, -2295, 644071, -384857, 783169, -16166.459479096771, 188803, 309357),
sprintf(boba863, "%-d=q% 6.10i%-hu% .1hi%-.10hu%+8dn2%+5.8hd,#% dc%-6.1i%+7hi% 7hi%-5.7f% .5hip% 1ii% 5.9i%+9.0d% 7.3fp%+.4d0%-u", 77231, 333626, 14913, 11088, -13470, -406710, 25992, -213512, -790145, 5162, 26575, -4840.453658998889, -2295, 644071, -384857, 783169, -16166.459479096771, 188803, 309357));
ck_assert_str_eq(boba863_s21, boba863);
}
END_TEST

START_TEST(bebasik__864) {
char boba864_s21[10000];
char boba864[10000];
ck_assert_int_eq(s21_sprintf(boba864_s21, "%-4hd5i%+.9i%+.3fv%-f%-8hi%+1d% 8.6hid6nd", 20334, 8155, 14213.777876842023, 7985.8286794741725, 15231, 399125, 31485),
sprintf(boba864, "%-4hd5i%+.9i%+.3fv%-f%-8hi%+1d% 8.6hid6nd", 20334, 8155, 14213.777876842023, 7985.8286794741725, 15231, 399125, 31485));
ck_assert_str_eq(boba864_s21, boba864);
}
END_TEST

START_TEST(bebasik__865) {
char boba865_s21[10000];
char boba865[10000];
ck_assert_int_eq(s21_sprintf(boba865_s21, "%+.10hd%+6.6f%+1.6hi)%-8hu% dr.m% 7f%+.9hiog;uf3%-4c% 8f)% .0f% 2d3% i% 9.9hd^% 1.8hd%+6d%+3.7hdc%-2c", 15632, 521.4917365395492, -9256, 30562, 453676, 8387.001537778104, 31410, '5', -3775.6983920002695, 3808.943183696131, 245335, 672084, -6666, -17006, -928493, -7673, 'k'),
sprintf(boba865, "%+.10hd%+6.6f%+1.6hi)%-8hu% dr.m% 7f%+.9hiog;uf3%-4c% 8f)% .0f% 2d3% i% 9.9hd^% 1.8hd%+6d%+3.7hdc%-2c", 15632, 521.4917365395492, -9256, 30562, 453676, 8387.001537778104, 31410, '5', -3775.6983920002695, 3808.943183696131, 245335, 672084, -6666, -17006, -928493, -7673, 'k'));
ck_assert_str_eq(boba865_s21, boba865);
}
END_TEST

START_TEST(bebasik__866) {
char boba866_s21[10000];
char boba866[10000];
ck_assert_int_eq(s21_sprintf(boba866_s21, "% 2hd%-u% 4.4imc% .4ii%-3.2sw% 5i%-.10ud%-8.6s% 5.3hio%-hd% .5hi6%+3.10i%-hu% 5hd", 8657, -922957, 728787, 949715, "v$0fk1@hn2/!", -249660, -516627, "^4r$f`*,[4j!^nya@pbb$&ox#w3zp", 5021, 18074, -30508, -621363, -2249, 8985),
sprintf(boba866, "% 2hd%-u% 4.4imc% .4ii%-3.2sw% 5i%-.10ud%-8.6s% 5.3hio%-hd% .5hi6%+3.10i%-hu% 5hd", 8657, -922957, 728787, 949715, "v$0fk1@hn2/!", -249660, -516627, "^4r$f`*,[4j!^nya@pbb$&ox#w3zp", 5021, 18074, -30508, -621363, -2249, 8985));
ck_assert_str_eq(boba866_s21, boba866);
}
END_TEST

START_TEST(bebasik__867) {
char boba867_s21[10000];
char boba867[10000];
ck_assert_int_eq(s21_sprintf(boba867_s21, "%+.4hif% 8.5hiv%+7d%-10.0i%-.3i8%+4d!%+2.6hi%-2hi9% 1hix%+hi%+1.8hdtz1% hdyz`!o%-.5i%-.2hi% d% 10f#", -14284, 19745, 828435, 122428, -644154, 294005, -18586, -1653, -9019, 4352, 18102, 29057, -391048, -7775, 317910, 687.5187974515135),
sprintf(boba867, "%+.4hif% 8.5hiv%+7d%-10.0i%-.3i8%+4d!%+2.6hi%-2hi9% 1hix%+hi%+1.8hdtz1% hdyz`!o%-.5i%-.2hi% d% 10f#", -14284, 19745, 828435, 122428, -644154, 294005, -18586, -1653, -9019, 4352, 18102, 29057, -391048, -7775, 317910, 687.5187974515135));
ck_assert_str_eq(boba867_s21, boba867);
}
END_TEST

START_TEST(bebasik__868) {
char boba868_s21[10000];
char boba868[10000];
ck_assert_int_eq(s21_sprintf(boba868_s21, "%+4.6hi%+.7hi%+.6f%+f%+.4hd02%+10.4hi% .7hi[%-3hu%-.7hu5%-8hi%-5.8u", 21269, 15573, -10637.201044133217, -7534.3706609207275, -807, -14983, 2440, 8763, 31039, -3042, -331526),
sprintf(boba868, "%+4.6hi%+.7hi%+.6f%+f%+.4hd02%+10.4hi% .7hi[%-3hu%-.7hu5%-8hi%-5.8u", 21269, 15573, -10637.201044133217, -7534.3706609207275, -807, -14983, 2440, 8763, 31039, -3042, -331526));
ck_assert_str_eq(boba868_s21, boba868);
}
END_TEST

START_TEST(bebasik__869) {
char boba869_s21[10000];
char boba869[10000];
ck_assert_int_eq(s21_sprintf(boba869_s21, "%+.5hi%-.10hd%-hdn% 6.8i=%-5hd%-8hd%-s%+10.8hifq% .2ik% 9.5i[%+.4hd%+3.1d%+hd%+4i.sdi%+10hd% .3d%+3.8i% 8d%+.1i%-10hd%-.2hu%+3hd%+d%-.9hd", 25265, -14568, 21394, 141822, 23574, 7279, "u4^68", -7645, 716237, -231254, -16351, 729863, 10950, 200552, 3036, -55481, -652321, 637272, 33497, 14457, 7201, -14058, 788803, -31225),
sprintf(boba869, "%+.5hi%-.10hd%-hdn% 6.8i=%-5hd%-8hd%-s%+10.8hifq% .2ik% 9.5i[%+.4hd%+3.1d%+hd%+4i.sdi%+10hd% .3d%+3.8i% 8d%+.1i%-10hd%-.2hu%+3hd%+d%-.9hd", 25265, -14568, 21394, 141822, 23574, 7279, "u4^68", -7645, 716237, -231254, -16351, 729863, 10950, 200552, 3036, -55481, -652321, 637272, 33497, 14457, 7201, -14058, 788803, -31225));
ck_assert_str_eq(boba869_s21, boba869);
}
END_TEST

START_TEST(bebasik__870) {
char boba870_s21[10000];
char boba870[10000];
ck_assert_int_eq(s21_sprintf(boba870_s21, "% .1i%-7c%+hd(% hib@%+.8dt4%+1i%+.8hd%-.4s% 7.8d-%-.0hd% 9.3d$%+f%-1hu%-.1d1% .8i5r% .7hd&%+10d@%+.0f%+10.8id%+3.5hit(% 10i% hd", -543770, '/', -29853, 14537, 211842, 925307, 25953, "6", 485005, -15137, -36488, 11060.20229986152, -20689, -788337, -941394, 9204, 134665, 558.4545843781434, -65597, -14, -189301, 26757),
sprintf(boba870, "% .1i%-7c%+hd(% hib@%+.8dt4%+1i%+.8hd%-.4s% 7.8d-%-.0hd% 9.3d$%+f%-1hu%-.1d1% .8i5r% .7hd&%+10d@%+.0f%+10.8id%+3.5hit(% 10i% hd", -543770, '/', -29853, 14537, 211842, 925307, 25953, "6", 485005, -15137, -36488, 11060.20229986152, -20689, -788337, -941394, 9204, 134665, 558.4545843781434, -65597, -14, -189301, 26757));
ck_assert_str_eq(boba870_s21, boba870);
}
END_TEST

START_TEST(bebasik__871) {
char boba871_s21[10000];
char boba871[10000];
ck_assert_int_eq(s21_sprintf(boba871_s21, "% 3.2hi6%-9cren%+3.8f%-.8hi%-.10uz%+2.5hi%+.4d% d%-.4hd", -23745, 'n', -6567.676930157023, 10572, 58091, -2211, 198977, -658953, -5642),
sprintf(boba871, "% 3.2hi6%-9cren%+3.8f%-.8hi%-.10uz%+2.5hi%+.4d% d%-.4hd", -23745, 'n', -6567.676930157023, 10572, 58091, -2211, 198977, -658953, -5642));
ck_assert_str_eq(boba871_s21, boba871);
}
END_TEST

START_TEST(bebasik__872) {
char boba872_s21[10000];
char boba872[10000];
ck_assert_int_eq(s21_sprintf(boba872_s21, "%+d%+10d%+.0hi%-.5hu%+5d51% .10hi%+4.10hda%-9.0hu%+.10hi%-1.6i%+7fd^% 5hd% 1.4d6o[", -793704, -771060, 17012, 7483, 522974, -11542, -7288, 2093, 13246, 953832, -16703.684828528687, 16874, -486532),
sprintf(boba872, "%+d%+10d%+.0hi%-.5hu%+5d51% .10hi%+4.10hda%-9.0hu%+.10hi%-1.6i%+7fd^% 5hd% 1.4d6o[", -793704, -771060, 17012, 7483, 522974, -11542, -7288, 2093, 13246, 953832, -16703.684828528687, 16874, -486532));
ck_assert_str_eq(boba872_s21, boba872);
}
END_TEST

START_TEST(bebasik__873) {
char boba873_s21[10000];
char boba873[10000];
ck_assert_int_eq(s21_sprintf(boba873_s21, "%+.3fn`% .0hd% hi#%-2.9ua[%+5.3hd#% .7hdzac%+f,!a% 4d%+hdq% hd% 2.6hi@", 6275.628940335311, 25933, 28874, -968786, 20470, -8520, -1036.582773643634, 502159, 9128, 3975, -9983),
sprintf(boba873, "%+.3fn`% .0hd% hi#%-2.9ua[%+5.3hd#% .7hdzac%+f,!a% 4d%+hdq% hd% 2.6hi@", 6275.628940335311, 25933, 28874, -968786, 20470, -8520, -1036.582773643634, 502159, 9128, 3975, -9983));
ck_assert_str_eq(boba873_s21, boba873);
}
END_TEST

START_TEST(bebasik__874) {
char boba874_s21[10000];
char boba874[10000];
ck_assert_int_eq(s21_sprintf(boba874_s21, "%+hii%+7.7in.ns%-9s%-iu%-9hi% .10i% d%-7.3huj3(t%-.4hu!$% .5i%+9hi%+d% 1.3hi6g;w$t%-.3u.wh% hik%+10hd% 4.1i-v% 8.9hin%-.4sx^dl%-6.2i% 9.0dnb9oo% 4f", -3100, 437274, "m-[7`;3ud", 780688, 17033, 427972, -138587, -24140, 17046, 179138, 30167, -952260, -15507, -36466, 24380, -10669, -529948, 14976, "0!!4l`ncnr`", -36000, 531600, -15664.536930853652),
sprintf(boba874, "%+hii%+7.7in.ns%-9s%-iu%-9hi% .10i% d%-7.3huj3(t%-.4hu!$% .5i%+9hi%+d% 1.3hi6g;w$t%-.3u.wh% hik%+10hd% 4.1i-v% 8.9hin%-.4sx^dl%-6.2i% 9.0dnb9oo% 4f", -3100, 437274, "m-[7`;3ud", 780688, 17033, 427972, -138587, -24140, 17046, 179138, 30167, -952260, -15507, -36466, 24380, -10669, -529948, 14976, "0!!4l`ncnr`", -36000, 531600, -15664.536930853652));
ck_assert_str_eq(boba874_s21, boba874);
}
END_TEST

START_TEST(bebasik__875) {
char boba875_s21[10000];
char boba875[10000];
ck_assert_int_eq(s21_sprintf(boba875_s21, "%-6huy%-c/sis#;% i%-4.2hi,bfb@", 13709, '5', -349480, 22733),
sprintf(boba875, "%-6huy%-c/sis#;% i%-4.2hi,bfb@", 13709, '5', -349480, 22733));
ck_assert_str_eq(boba875_s21, boba875);
}
END_TEST

START_TEST(bebasik__876) {
char boba876_s21[10000];
char boba876[10000];
ck_assert_int_eq(s21_sprintf(boba876_s21, "%-2.6f% 5.5hd7%-9hi", -17328.5969710486, 24422, 9387),
sprintf(boba876, "%-2.6f% 5.5hd7%-9hi", -17328.5969710486, 24422, 9387));
ck_assert_str_eq(boba876_s21, boba876);
}
END_TEST

START_TEST(bebasik__877) {
char boba877_s21[10000];
char boba877[10000];
ck_assert_int_eq(s21_sprintf(boba877_s21, "%+2d%-7.2hu@%-8.1s", 256782, -6138, "=zk`a9jc6u-7/;#;#la."),
sprintf(boba877, "%+2d%-7.2hu@%-8.1s", 256782, -6138, "=zk`a9jc6u-7/;#;#la."));
ck_assert_str_eq(boba877_s21, boba877);
}
END_TEST

START_TEST(bebasik__878) {
char boba878_s21[10000];
char boba878[10000];
ck_assert_int_eq(s21_sprintf(boba878_s21, "%+i% .7d%+9.0im%+6hd%+8hi%-7i)%-2.0u8y%-2.1f/x2^2%-8.4hd%-4.8hd%-.9u%-hd=%-9s%-7d", -266522, 58562, 431296, 29027, 21299, -408295, 655771, -8956.511560321067, -20535, -18901, -757701, -31824, "", -601174),
sprintf(boba878, "%+i% .7d%+9.0im%+6hd%+8hi%-7i)%-2.0u8y%-2.1f/x2^2%-8.4hd%-4.8hd%-.9u%-hd=%-9s%-7d", -266522, 58562, 431296, 29027, 21299, -408295, 655771, -8956.511560321067, -20535, -18901, -757701, -31824, "", -601174));
ck_assert_str_eq(boba878_s21, boba878);
}
END_TEST

START_TEST(bebasik__879) {
char boba879_s21[10000];
char boba879[10000];
ck_assert_int_eq(s21_sprintf(boba879_s21, "% i%-hu,h%-.1u%+4ib%+d", 269798, 23253, -226856, -549866, -313325),
sprintf(boba879, "% i%-hu,h%-.1u%+4ib%+d", 269798, 23253, -226856, -549866, -313325));
ck_assert_str_eq(boba879_s21, boba879);
}
END_TEST

START_TEST(bebasik__880) {
char boba880_s21[10000];
char boba880[10000];
ck_assert_int_eq(s21_sprintf(boba880_s21, "%-hi%+9.0dq)h%+1.5dp%+2d6", 26354, -512951, 434620, 67341),
sprintf(boba880, "%-hi%+9.0dq)h%+1.5dp%+2d6", 26354, -512951, 434620, 67341));
ck_assert_str_eq(boba880_s21, boba880);
}
END_TEST

START_TEST(bebasik__881) {
char boba881_s21[10000];
char boba881[10000];
ck_assert_int_eq(s21_sprintf(boba881_s21, "% .3dv%+8.8hi%-4i%+10hd%-7.2hukq2`m", 939431, -8219, 978508, 10075, 10636),
sprintf(boba881, "% .3dv%+8.8hi%-4i%+10hd%-7.2hukq2`m", 939431, -8219, 978508, 10075, 10636));
ck_assert_str_eq(boba881_s21, boba881);
}
END_TEST

START_TEST(bebasik__882) {
char boba882_s21[10000];
char boba882[10000];
ck_assert_int_eq(s21_sprintf(boba882_s21, "%-.7u% 5hi/$//am$^% 4d%+hi).3%-.5hu%-.3hu%+3d;x%-9hi% 6.3hi%+6.7hd%-c=%+2hd-fo", 586228, 27756, 305566, 20110, -1894, 11170, -677293, -14199, -10581, 23526, 'p', 26343),
sprintf(boba882, "%-.7u% 5hi/$//am$^% 4d%+hi).3%-.5hu%-.3hu%+3d;x%-9hi% 6.3hi%+6.7hd%-c=%+2hd-fo", 586228, 27756, 305566, 20110, -1894, 11170, -677293, -14199, -10581, 23526, 'p', 26343));
ck_assert_str_eq(boba882_s21, boba882);
}
END_TEST

START_TEST(bebasik__883) {
char boba883_s21[10000];
char boba883[10000];
ck_assert_int_eq(s21_sprintf(boba883_s21, "%-f%-hi%-.10d", -4908.690323195061, 10473, 442978),
sprintf(boba883, "%-f%-hi%-.10d", -4908.690323195061, 10473, 442978));
ck_assert_str_eq(boba883_s21, boba883);
}
END_TEST

START_TEST(bebasik__884) {
char boba884_s21[10000];
char boba884[10000];
ck_assert_int_eq(s21_sprintf(boba884_s21, "% 1.7fw% hi4% 5.6i% .2hi", -7259.190070842954, -2916, 333756, -10364),
sprintf(boba884, "% 1.7fw% hi4% 5.6i% .2hi", -7259.190070842954, -2916, 333756, -10364));
ck_assert_str_eq(boba884_s21, boba884);
}
END_TEST

START_TEST(bebasik__885) {
char boba885_s21[10000];
char boba885[10000];
ck_assert_int_eq(s21_sprintf(boba885_s21, "% 2.5hi/m#%+8hd*o7% 6.9hiz%+8hifk%-.3i3%+6f%-7f,94)%-.1u% df%+.5hi%-5hu%-5.3hu!% .5d*% .2hd4%+.6hi% 7fc=fv^", -28421, 8418, 3909, 27989, 420184, 4058.0038344373374, 17937.46427670271, -841161, 452448, -9306, 19994, -10401, 625072, -15279, 26590, 19068.136087001094),
sprintf(boba885, "% 2.5hi/m#%+8hd*o7% 6.9hiz%+8hifk%-.3i3%+6f%-7f,94)%-.1u% df%+.5hi%-5hu%-5.3hu!% .5d*% .2hd4%+.6hi% 7fc=fv^", -28421, 8418, 3909, 27989, 420184, 4058.0038344373374, 17937.46427670271, -841161, 452448, -9306, 19994, -10401, 625072, -15279, 26590, 19068.136087001094));
ck_assert_str_eq(boba885_s21, boba885);
}
END_TEST

START_TEST(bebasik__886) {
char boba886_s21[10000];
char boba886[10000];
ck_assert_int_eq(s21_sprintf(boba886_s21, "% .1hd%-9.8u%+.5d%-3.10d%-6.4hd%+.6fgns% 8hiqr0/z%-1.8hu#p%-.0d%+8hd% 3d% hi2%+10i", 31503, 592190, -353017, -840811, 428, -4135.02786055687, 21608, -11127, 166310, -30108, -248697, 26264, 57697),
sprintf(boba886, "% .1hd%-9.8u%+.5d%-3.10d%-6.4hd%+.6fgns% 8hiqr0/z%-1.8hu#p%-.0d%+8hd% 3d% hi2%+10i", 31503, 592190, -353017, -840811, 428, -4135.02786055687, 21608, -11127, 166310, -30108, -248697, 26264, 57697));
ck_assert_str_eq(boba886_s21, boba886);
}
END_TEST

START_TEST(bebasik__887) {
char boba887_s21[10000];
char boba887[10000];
ck_assert_int_eq(s21_sprintf(boba887_s21, "% 6hdl%+.8hi% 10hiq5%+d%+7hd% 9hd%+5.7hd% 9.7d% 3.1hi%-cq% .4f%+3d%-9.9u/5;..^", 11701, -21529, 5839, 550338, 8356, 25527, -15979, 413402, 5530, ',', -4752.382955505629, -269510, -335472),
sprintf(boba887, "% 6hdl%+.8hi% 10hiq5%+d%+7hd% 9hd%+5.7hd% 9.7d% 3.1hi%-cq% .4f%+3d%-9.9u/5;..^", 11701, -21529, 5839, 550338, 8356, 25527, -15979, 413402, 5530, ',', -4752.382955505629, -269510, -335472));
ck_assert_str_eq(boba887_s21, boba887);
}
END_TEST

START_TEST(bebasik__888) {
char boba888_s21[10000];
char boba888[10000];
ck_assert_int_eq(s21_sprintf(boba888_s21, "%+.5hdd% 3hi%-.7hd%+8.8i%-10hi%+10.4hd% .7f%-5.1hi%-3hu%-.3f%-1hiyya%+4d4z", 134, -24796, 29667, -368423, 27921, 4876, 3667.6365134830844, -8757, -20899, -5909.369751436534, 14426, 436537),
sprintf(boba888, "%+.5hdd% 3hi%-.7hd%+8.8i%-10hi%+10.4hd% .7f%-5.1hi%-3hu%-.3f%-1hiyya%+4d4z", 134, -24796, 29667, -368423, 27921, 4876, 3667.6365134830844, -8757, -20899, -5909.369751436534, 14426, 436537));
ck_assert_str_eq(boba888_s21, boba888);
}
END_TEST

START_TEST(bebasik__889) {
char boba889_s21[10000];
char boba889[10000];
ck_assert_int_eq(s21_sprintf(boba889_s21, "% 8.6hd%+2hi%+8.2hiw% 10hd%-10s@#% 6d%-7.8hu%-d", 3664, -10404, -4148, 7394, "", -60481, 27888, -137982),
sprintf(boba889, "% 8.6hd%+2hi%+8.2hiw% 10hd%-10s@#% 6d%-7.8hu%-d", 3664, -10404, -4148, 7394, "", -60481, 27888, -137982));
ck_assert_str_eq(boba889_s21, boba889);
}
END_TEST

START_TEST(bebasik__890) {
char boba890_s21[10000];
char boba890[10000];
ck_assert_int_eq(s21_sprintf(boba890_s21, "%+hi0`", -8623),
sprintf(boba890, "%+hi0`", -8623));
ck_assert_str_eq(boba890_s21, boba890);
}
END_TEST

START_TEST(bebasik__891) {
char boba891_s21[10000];
char boba891[10000];
ck_assert_int_eq(s21_sprintf(boba891_s21, "%+.3hd#%+.3hi% .6hd%+2f*p% .1f-,=;2% .9hdn%-9.5hd%+9hd%+hd%+.7i3(%+hdz% 3hi7%+i=%+8.4i% ifg", 30183, 15551, 25337, 13219.784931209015, -2477.8053117191753, -3953, -5723, 29412, 24067, 319397, -9120, -18297, -915472, 767733, -998441),
sprintf(boba891, "%+.3hd#%+.3hi% .6hd%+2f*p% .1f-,=;2% .9hdn%-9.5hd%+9hd%+hd%+.7i3(%+hdz% 3hi7%+i=%+8.4i% ifg", 30183, 15551, 25337, 13219.784931209015, -2477.8053117191753, -3953, -5723, 29412, 24067, 319397, -9120, -18297, -915472, 767733, -998441));
ck_assert_str_eq(boba891_s21, boba891);
}
END_TEST

START_TEST(bebasik__892) {
char boba892_s21[10000];
char boba892[10000];
ck_assert_int_eq(s21_sprintf(boba892_s21, "%+3hi%+6hi% 2.1hd%+hi% 1.7i%-10hd%+hd% 9hd!p3)[% 1hi%+2.7hd", 7673, -4100, -30806, 24052, -277996, -13593, 12012, -5580, -25604, -14984),
sprintf(boba892, "%+3hi%+6hi% 2.1hd%+hi% 1.7i%-10hd%+hd% 9hd!p3)[% 1hi%+2.7hd", 7673, -4100, -30806, 24052, -277996, -13593, 12012, -5580, -25604, -14984));
ck_assert_str_eq(boba892_s21, boba892);
}
END_TEST

START_TEST(bebasik__893) {
char boba893_s21[10000];
char boba893[10000];
ck_assert_int_eq(s21_sprintf(boba893_s21, "%-5fpg%-3hi2q3i%+hi% fl%+.4iy0%-.8hum%-2.1uq%-5.3f;", 7253.682324561938, -28353, 31184, -1419.3227816500378, 415571, 21955, -554166, 964.194850475138),
sprintf(boba893, "%-5fpg%-3hi2q3i%+hi% fl%+.4iy0%-.8hum%-2.1uq%-5.3f;", 7253.682324561938, -28353, 31184, -1419.3227816500378, 415571, 21955, -554166, 964.194850475138));
ck_assert_str_eq(boba893_s21, boba893);
}
END_TEST

START_TEST(bebasik__894) {
char boba894_s21[10000];
char boba894[10000];
ck_assert_int_eq(s21_sprintf(boba894_s21, "%-hu2% 6hd%+.0d`% 3.7hi5s5sbo%-2.3i%-6.0i%+6i69%+hi%-10.3d7% 10hdc% .8hiq%+d%-2.0s% .3hi% 2.5d%-.1fye% hih2`%+5iv%+.9d#% 6.0d()% d#pu% d", -7389, -27621, -980970, -20441, 733546, -548903, 427213, 1310, 70159, 28537, 20436, -446787, "v0jdl@wf3([6vi2ig;r*.6njw", 15809, 107022, -6659.6796780274435, -717, -930296, 943141, 824309, -795920, -20343),
sprintf(boba894, "%-hu2% 6hd%+.0d`% 3.7hi5s5sbo%-2.3i%-6.0i%+6i69%+hi%-10.3d7% 10hdc% .8hiq%+d%-2.0s% .3hi% 2.5d%-.1fye% hih2`%+5iv%+.9d#% 6.0d()% d#pu% d", -7389, -27621, -980970, -20441, 733546, -548903, 427213, 1310, 70159, 28537, 20436, -446787, "v0jdl@wf3([6vi2ig;r*.6njw", 15809, 107022, -6659.6796780274435, -717, -930296, 943141, 824309, -795920, -20343));
ck_assert_str_eq(boba894_s21, boba894);
}
END_TEST

START_TEST(bebasik__895) {
char boba895_s21[10000];
char boba895[10000];
ck_assert_int_eq(s21_sprintf(boba895_s21, "%+5iy9%+3.4fx%-hu", -290319, -16529.453212420645, -7554),
sprintf(boba895, "%+5iy9%+3.4fx%-hu", -290319, -16529.453212420645, -7554));
ck_assert_str_eq(boba895_s21, boba895);
}
END_TEST

START_TEST(bebasik__896) {
char boba896_s21[10000];
char boba896[10000];
ck_assert_int_eq(s21_sprintf(boba896_s21, "% .0hi% il% 3.1hi%+2da% 4d% d", -14222, 186970, -4970, 213854, -362198, -356182),
sprintf(boba896, "% .0hi% il% 3.1hi%+2da% 4d% d", -14222, 186970, -4970, 213854, -362198, -356182));
ck_assert_str_eq(boba896_s21, boba896);
}
END_TEST

START_TEST(bebasik__897) {
char boba897_s21[10000];
char boba897[10000];
ck_assert_int_eq(s21_sprintf(boba897_s21, "% .0fe[%+9.7i%+8.0hdf% 1hi% 1hi% 4.2f%-7.2d%+.6f%-4.0hd%-10.6hda% .9hd%-2hu", 16829.358524649047, 951907, 9605, 31583, 27060, 5816.863745006462, 844963, 3830.450379317958, 9096, -10345, -15949, 22979),
sprintf(boba897, "% .0fe[%+9.7i%+8.0hdf% 1hi% 1hi% 4.2f%-7.2d%+.6f%-4.0hd%-10.6hda% .9hd%-2hu", 16829.358524649047, 951907, 9605, 31583, 27060, 5816.863745006462, 844963, 3830.450379317958, 9096, -10345, -15949, 22979));
ck_assert_str_eq(boba897_s21, boba897);
}
END_TEST

START_TEST(bebasik__898) {
char boba898_s21[10000];
char boba898[10000];
ck_assert_int_eq(s21_sprintf(boba898_s21, "%+9.1hd% 7hi)%+5.3d% 10i%-6hi%+1.3hd%-10hdby%-.8s)%+.4hi8% hd%+.3fn% 2hi%+hd% .1hi", 28021, 24735, 447066, 137166, -23344, -19167, 7238, "llmx01dx2v^jesc2inu/^x", 18643, 1926, -9625.156825346028, 10887, -31824, 10765),
sprintf(boba898, "%+9.1hd% 7hi)%+5.3d% 10i%-6hi%+1.3hd%-10hdby%-.8s)%+.4hi8% hd%+.3fn% 2hi%+hd% .1hi", 28021, 24735, 447066, 137166, -23344, -19167, 7238, "llmx01dx2v^jesc2inu/^x", 18643, 1926, -9625.156825346028, 10887, -31824, 10765));
ck_assert_str_eq(boba898_s21, boba898);
}
END_TEST

START_TEST(bebasik__899) {
char boba899_s21[10000];
char boba899[10000];
ck_assert_int_eq(s21_sprintf(boba899_s21, "%+8.9hd% 4f% 9hd66&% f%+5hi4% 2.8hdl%-2.10hi%+6.2i%-8.10ubr;", 21007, -7998.949729515269, 27647, 64.02825611230166, 20399, 3985, -15083, 756963, -280101),
sprintf(boba899, "%+8.9hd% 4f% 9hd66&% f%+5hi4% 2.8hdl%-2.10hi%+6.2i%-8.10ubr;", 21007, -7998.949729515269, 27647, 64.02825611230166, 20399, 3985, -15083, 756963, -280101));
ck_assert_str_eq(boba899_s21, boba899);
}
END_TEST

START_TEST(bebasik__900) {
char boba900_s21[10000];
char boba900[10000];
ck_assert_int_eq(s21_sprintf(boba900_s21, "%+1i%+4hi% 7.1fi%+9.3i1%+hiw-%-.6hi2% 10hd% 10.1d%-c%+10.5hi@%-1hi,5%-.10hd% hiyt%+hi%-hi%-6hd%+.9ibfnbqo%+hi%+9i", -117377, -2931, -1842.502934985658, -146730, 21352, -7680, -28537, 163110, 'h', 6055, 29329, -24399, -14168, 13887, -20016, -20325, 328304, -22112, -537969),
sprintf(boba900, "%+1i%+4hi% 7.1fi%+9.3i1%+hiw-%-.6hi2% 10hd% 10.1d%-c%+10.5hi@%-1hi,5%-.10hd% hiyt%+hi%-hi%-6hd%+.9ibfnbqo%+hi%+9i", -117377, -2931, -1842.502934985658, -146730, 21352, -7680, -28537, 163110, 'h', 6055, 29329, -24399, -14168, 13887, -20016, -20325, 328304, -22112, -537969));
ck_assert_str_eq(boba900_s21, boba900);
}
END_TEST

START_TEST(bebasik__901) {
char boba901_s21[10000];
char boba901[10000];
ck_assert_int_eq(s21_sprintf(boba901_s21, "%+6.8hd^%+6i%-1.7hd`p%-.2is% 3.6f%-4.4hu%+hi% .3hi%-.8u))% hi#%-.4u%-10.1hdf-b*%-2f`$#67% fhk", -888, -289200, 7056, 764054, -21524.574189088456, 30731, 9013, -15050, 222917, -15910, -292023, 8249, 2512.6494234878537, -11773.582053536265),
sprintf(boba901, "%+6.8hd^%+6i%-1.7hd`p%-.2is% 3.6f%-4.4hu%+hi% .3hi%-.8u))% hi#%-.4u%-10.1hdf-b*%-2f`$#67% fhk", -888, -289200, 7056, 764054, -21524.574189088456, 30731, 9013, -15050, 222917, -15910, -292023, 8249, 2512.6494234878537, -11773.582053536265));
ck_assert_str_eq(boba901_s21, boba901);
}
END_TEST

START_TEST(bebasik__902) {
char boba902_s21[10000];
char boba902[10000];
ck_assert_int_eq(s21_sprintf(boba902_s21, "%-hd% id@% 3.5i!rb%+6.6i4% 1i%+4hd4% .6hi% .8hdq)", -4003, -585540, 735312, 169069, 682152, -9516, 9214, -22659),
sprintf(boba902, "%-hd% id@% 3.5i!rb%+6.6i4% 1i%+4hd4% .6hi% .8hdq)", -4003, -585540, 735312, 169069, 682152, -9516, 9214, -22659));
ck_assert_str_eq(boba902_s21, boba902);
}
END_TEST

START_TEST(bebasik__903) {
char boba903_s21[10000];
char boba903[10000];
ck_assert_int_eq(s21_sprintf(boba903_s21, "%+4f855%+.3d-%-9.2hi4)d%+8d%+10.5hd!o%-7u%-5iuu% 10hi%+1hi%-4.9fp0% 1hd%+ia%+.2i&%+.4hd", -742.3333731550665, 287212, -27203, 650001, -16292, 993948, 660775, -17356, -26208, 2218.823927893927, -30047, -553982, -564342, 23537),
sprintf(boba903, "%+4f855%+.3d-%-9.2hi4)d%+8d%+10.5hd!o%-7u%-5iuu% 10hi%+1hi%-4.9fp0% 1hd%+ia%+.2i&%+.4hd", -742.3333731550665, 287212, -27203, 650001, -16292, 993948, 660775, -17356, -26208, 2218.823927893927, -30047, -553982, -564342, 23537));
ck_assert_str_eq(boba903_s21, boba903);
}
END_TEST

START_TEST(bebasik__904) {
char boba904_s21[10000];
char boba904[10000];
ck_assert_int_eq(s21_sprintf(boba904_s21, "%-4hi%+2f% .9d.%+4hi%-1.1hufr%+9.1hiq%+f@/% .10fh[%-s`d%+.0i%-.6u!$%+.10hi%+6f%+5.2hd% 8hd%-7.8hd%+.3i% 6dk%+hi%-5.5s#%+1hi%+4f2%-.2hi", 1352, -8687.100618922932, 305179, -27296, 6892, -15763, -4207.233996620921, -15710.96351899159, "$(", 783253, 183315, 26952, -2624.8846406263324, -8861, -10139, -3481, -529235, -81102, 19278, "/0elto", 22700, -5445.118571262707, -13118),
sprintf(boba904, "%-4hi%+2f% .9d.%+4hi%-1.1hufr%+9.1hiq%+f@/% .10fh[%-s`d%+.0i%-.6u!$%+.10hi%+6f%+5.2hd% 8hd%-7.8hd%+.3i% 6dk%+hi%-5.5s#%+1hi%+4f2%-.2hi", 1352, -8687.100618922932, 305179, -27296, 6892, -15763, -4207.233996620921, -15710.96351899159, "$(", 783253, 183315, 26952, -2624.8846406263324, -8861, -10139, -3481, -529235, -81102, 19278, "/0elto", 22700, -5445.118571262707, -13118));
ck_assert_str_eq(boba904_s21, boba904);
}
END_TEST

START_TEST(bebasik__905) {
char boba905_s21[10000];
char boba905[10000];
ck_assert_int_eq(s21_sprintf(boba905_s21, "% hiq6/f%-.9iqi#0% 1.6f/q3%+.7f%-hipacm% f%+dz&**w%+5hiq=% 2.4i%+.1f%-i% 3hd% i(o% 9.1hd%-7.1un%+.0hd% hd%+5.7hd^%-2.5u% 7.7hi)@% .5hi$", 27948, 424706, -16169.446584234722, -10323.258549949669, 30097, -24601.928326735062, -514374, -13737, -639484, -11209.476669859821, 700482, -24656, -689932, 30132, 105893, -8488, -4161, 8018, -715443, -13479, -11773),
sprintf(boba905, "% hiq6/f%-.9iqi#0% 1.6f/q3%+.7f%-hipacm% f%+dz&**w%+5hiq=% 2.4i%+.1f%-i% 3hd% i(o% 9.1hd%-7.1un%+.0hd% hd%+5.7hd^%-2.5u% 7.7hi)@% .5hi$", 27948, 424706, -16169.446584234722, -10323.258549949669, 30097, -24601.928326735062, -514374, -13737, -639484, -11209.476669859821, 700482, -24656, -689932, 30132, 105893, -8488, -4161, 8018, -715443, -13479, -11773));
ck_assert_str_eq(boba905_s21, boba905);
}
END_TEST

START_TEST(bebasik__906) {
char boba906_s21[10000];
char boba906[10000];
ck_assert_int_eq(s21_sprintf(boba906_s21, "%-2d%+.8hd%+2hijv%-2hu% hilu*f%-.4hd%+1.7i%-1s%+.0i% 1hd9%+d%+.1hdg% 3hif0%-.3hdq", 297141, 23235, 2689, 17997, -26607, -17770, -812976, "5960&q7pik.f", 715086, -4056, -992840, -24774, 29551, 12646),
sprintf(boba906, "%-2d%+.8hd%+2hijv%-2hu% hilu*f%-.4hd%+1.7i%-1s%+.0i% 1hd9%+d%+.1hdg% 3hif0%-.3hdq", 297141, 23235, 2689, 17997, -26607, -17770, -812976, "5960&q7pik.f", 715086, -4056, -992840, -24774, 29551, 12646));
ck_assert_str_eq(boba906_s21, boba906);
}
END_TEST

START_TEST(bebasik__907) {
char boba907_s21[10000];
char boba907[10000];
ck_assert_int_eq(s21_sprintf(boba907_s21, "%-4hu% 9hi%-4.9hd", 12466, 1063, -28751),
sprintf(boba907, "%-4hu% 9hi%-4.9hd", 12466, 1063, -28751));
ck_assert_str_eq(boba907_s21, boba907);
}
END_TEST

START_TEST(bebasik__908) {
char boba908_s21[10000];
char boba908[10000];
ck_assert_int_eq(s21_sprintf(boba908_s21, "%+9.8i%+10hi-%-1d%+2hd55%-hu%+3.1hiw%+.3hi% .1f%+.4iv%+1.7f%-d%+.2hd%+8hi4fe", 953821, -12175, -61953, 18546, 8278, -5920, -10017, -1443.4781919146806, 128572, 4844.043377343885, -530076, -21435, -11707),
sprintf(boba908, "%+9.8i%+10hi-%-1d%+2hd55%-hu%+3.1hiw%+.3hi% .1f%+.4iv%+1.7f%-d%+.2hd%+8hi4fe", 953821, -12175, -61953, 18546, 8278, -5920, -10017, -1443.4781919146806, 128572, 4844.043377343885, -530076, -21435, -11707));
ck_assert_str_eq(boba908_s21, boba908);
}
END_TEST

START_TEST(bebasik__909) {
char boba909_s21[10000];
char boba909[10000];
ck_assert_int_eq(s21_sprintf(boba909_s21, "%-.3hu% 5.10hib", -5390, 8744),
sprintf(boba909, "%-.3hu% 5.10hib", -5390, 8744));
ck_assert_str_eq(boba909_s21, boba909);
}
END_TEST

START_TEST(bebasik__910) {
char boba910_s21[10000];
char boba910[10000];
ck_assert_int_eq(s21_sprintf(boba910_s21, "%+8.0hdc% hi%+3.5hd%+10.9d%-.10hdf%-3.4u20pj8i4%+.3dm%+7i%-u% 1.7iy%-4hd%-.4uaq%-2.9f%+6f0,% 6.0f%+1hd% ir%-hu%+i%-f% 1d%-c9%-10.7hu%+fw^", 25642, -24724, 26176, -570610, 9624, -828312, 336584, 168082, 389471, -871456, -19735, -848554, 8250.45635129274, 6811.733502865625, 9553.244206348447, 4758, 701146, 8412, 305208, 12909.590928008885, -243337, '1', -30763, -1592.1724360409844),
sprintf(boba910, "%+8.0hdc% hi%+3.5hd%+10.9d%-.10hdf%-3.4u20pj8i4%+.3dm%+7i%-u% 1.7iy%-4hd%-.4uaq%-2.9f%+6f0,% 6.0f%+1hd% ir%-hu%+i%-f% 1d%-c9%-10.7hu%+fw^", 25642, -24724, 26176, -570610, 9624, -828312, 336584, 168082, 389471, -871456, -19735, -848554, 8250.45635129274, 6811.733502865625, 9553.244206348447, 4758, 701146, 8412, 305208, 12909.590928008885, -243337, '1', -30763, -1592.1724360409844));
ck_assert_str_eq(boba910_s21, boba910);
}
END_TEST

START_TEST(bebasik__911) {
char boba911_s21[10000];
char boba911[10000];
ck_assert_int_eq(s21_sprintf(boba911_s21, "%-8him% .7hdb%+.1hd%+9hi5%-9.8hd%+7d", 1215, -28430, 20440, 28709, -8124, -404070),
sprintf(boba911, "%-8him% .7hdb%+.1hd%+9hi5%-9.8hd%+7d", 1215, -28430, 20440, 28709, -8124, -404070));
ck_assert_str_eq(boba911_s21, boba911);
}
END_TEST

START_TEST(bebasik__912) {
char boba912_s21[10000];
char boba912[10000];
ck_assert_int_eq(s21_sprintf(boba912_s21, "%-3.9s%+1.8d% .4hi% 7.0i3%-.0hd%-1u2q% .8f/g5ma.)%-.4u4m`w% 2.10hdk&%-9.2hday%-.1im%+hdj%-8.4hi", "[1", -565128, 21425, -339335, 19120, 843324, -525.6582139691969, 632167, 6586, -10486, 819392, -29261, -11868),
sprintf(boba912, "%-3.9s%+1.8d% .4hi% 7.0i3%-.0hd%-1u2q% .8f/g5ma.)%-.4u4m`w% 2.10hdk&%-9.2hday%-.1im%+hdj%-8.4hi", "[1", -565128, 21425, -339335, 19120, 843324, -525.6582139691969, 632167, 6586, -10486, 819392, -29261, -11868));
ck_assert_str_eq(boba912_s21, boba912);
}
END_TEST

START_TEST(bebasik__913) {
char boba913_s21[10000];
char boba913[10000];
ck_assert_int_eq(s21_sprintf(boba913_s21, "%+5itsp% f% 4f1@%+10.9i%-.5hi,%-3.3f;%-hu% 7ifg%-hd`$#^%-.10hd@%-9.5i%-9.10u&% 5hd% f%+.9hiw%-9.9hdnv% 6.3i.n", -484024, -12664.520304649142, 16644.05184704478, 305928, 15438, -3144.2665903314146, -30773, -197252, -26267, -9172, -366718, -736111, -4691, 1560.6587650252404, 21245, 27933, -962587),
sprintf(boba913, "%+5itsp% f% 4f1@%+10.9i%-.5hi,%-3.3f;%-hu% 7ifg%-hd`$#^%-.10hd@%-9.5i%-9.10u&% 5hd% f%+.9hiw%-9.9hdnv% 6.3i.n", -484024, -12664.520304649142, 16644.05184704478, 305928, 15438, -3144.2665903314146, -30773, -197252, -26267, -9172, -366718, -736111, -4691, 1560.6587650252404, 21245, 27933, -962587));
ck_assert_str_eq(boba913_s21, boba913);
}
END_TEST

START_TEST(bebasik__914) {
char boba914_s21[10000];
char boba914[10000];
ck_assert_int_eq(s21_sprintf(boba914_s21, "% .7dk%+7d6s8%+9.6f%+hd% .5hil%-9hd", -707140, -366734, -6219.432577040771, -340, 2761, 8290),
sprintf(boba914, "% .7dk%+7d6s8%+9.6f%+hd% .5hil%-9hd", -707140, -366734, -6219.432577040771, -340, 2761, 8290));
ck_assert_str_eq(boba914_s21, boba914);
}
END_TEST

START_TEST(bebasik__915) {
char boba915_s21[10000];
char boba915[10000];
ck_assert_int_eq(s21_sprintf(boba915_s21, "%-5.2f^% f/%-.9hi%-4.4u%-.10f% 9hdeq4% .5hd", -5628.189233245784, -2856.9416318075923, -27013, 630433, -13969.908670011213, 11255, 29101),
sprintf(boba915, "%-5.2f^% f/%-.9hi%-4.4u%-.10f% 9hdeq4% .5hd", -5628.189233245784, -2856.9416318075923, -27013, 630433, -13969.908670011213, 11255, 29101));
ck_assert_str_eq(boba915_s21, boba915);
}
END_TEST

START_TEST(bebasik__916) {
char boba916_s21[10000];
char boba916[10000];
ck_assert_int_eq(s21_sprintf(boba916_s21, "% .10i5k!3%+.10hd(v%-.6f1% .3d4j% 10hi%+5hi", -317770, 11111, 6265.373396041853, 718744, 4610, 24263),
sprintf(boba916, "% .10i5k!3%+.10hd(v%-.6f1% .3d4j% 10hi%+5hi", -317770, 11111, 6265.373396041853, 718744, 4610, 24263));
ck_assert_str_eq(boba916_s21, boba916);
}
END_TEST

START_TEST(bebasik__917) {
char boba917_s21[10000];
char boba917[10000];
ck_assert_int_eq(s21_sprintf(boba917_s21, "%+6.3iz%+hd%-6.3d%+9hi%+f%+hir-2!l% hd%-2fi%-4s% d&y%-2.5ud%-6.1u%-.6hd%+.1ie", -625580, -5814, 520857, 23203, -311.9425581486407, -11490, 10564, 1107.9549741865549, "*lv&kh`ewdlkkc7s-k", -462799, 535971, -531064, -5870, -85967),
sprintf(boba917, "%+6.3iz%+hd%-6.3d%+9hi%+f%+hir-2!l% hd%-2fi%-4s% d&y%-2.5ud%-6.1u%-.6hd%+.1ie", -625580, -5814, 520857, 23203, -311.9425581486407, -11490, 10564, 1107.9549741865549, "*lv&kh`ewdlkkc7s-k", -462799, 535971, -531064, -5870, -85967));
ck_assert_str_eq(boba917_s21, boba917);
}
END_TEST

START_TEST(bebasik__918) {
char boba918_s21[10000];
char boba918[10000];
ck_assert_int_eq(s21_sprintf(boba918_s21, "% .4hd(#n=3k$% 6.2hi%+dj8t=f=z", 30271, -18556, 157939),
sprintf(boba918, "% .4hd(#n=3k$% 6.2hi%+dj8t=f=z", 30271, -18556, 157939));
ck_assert_str_eq(boba918_s21, boba918);
}
END_TEST

START_TEST(bebasik__919) {
char boba919_s21[10000];
char boba919[10000];
ck_assert_int_eq(s21_sprintf(boba919_s21, "%+.8hi%+.4frd% .7i%+.6devi% .4i%-9uov!9#%-6dvx%-4uq", 7752, 2855.7321083677043, -331862, 147781, -232400, 936829, -727184, 672381),
sprintf(boba919, "%+.8hi%+.4frd% .7i%+.6devi% .4i%-9uov!9#%-6dvx%-4uq", 7752, 2855.7321083677043, -331862, 147781, -232400, 936829, -727184, 672381));
ck_assert_str_eq(boba919_s21, boba919);
}
END_TEST

START_TEST(bebasik__920) {
char boba920_s21[10000];
char boba920[10000];
ck_assert_int_eq(s21_sprintf(boba920_s21, "%-.9hi/%+3.3hd5% dkk%-.9hi", -9583, -29902, -596063, -30752),
sprintf(boba920, "%-.9hi/%+3.3hd5% dkk%-.9hi", -9583, -29902, -596063, -30752));
ck_assert_str_eq(boba920_s21, boba920);
}
END_TEST

START_TEST(bebasik__921) {
char boba921_s21[10000];
char boba921[10000];
ck_assert_int_eq(s21_sprintf(boba921_s21, "%+.8f% 5i% d%-f05#3% db^)% hdb", -6011.9133914253525, -488065, -2019, -2488.2768239402503, -580460, 24935),
sprintf(boba921, "%+.8f% 5i% d%-f05#3% db^)% hdb", -6011.9133914253525, -488065, -2019, -2488.2768239402503, -580460, 24935));
ck_assert_str_eq(boba921_s21, boba921);
}
END_TEST

START_TEST(bebasik__922) {
char boba922_s21[10000];
char boba922[10000];
ck_assert_int_eq(s21_sprintf(boba922_s21, "%+5d%-hi% .5hiz%-8.6hd%-.7d% 7.6fw% 4hia% hi%+7.1i% .2d%-10.6sg%-.8huuu#3%+8dwf,%+4fj!j% .3i$k7", -326151, 16433, 8747, 22971, 234071, 16647.49202650502, -15280, -27905, -980029, 20721, "0/cq!o(j&5mo!0&ai@*k663", -9100, -45533, 15854.703132739056, 282724),
sprintf(boba922, "%+5d%-hi% .5hiz%-8.6hd%-.7d% 7.6fw% 4hia% hi%+7.1i% .2d%-10.6sg%-.8huuu#3%+8dwf,%+4fj!j% .3i$k7", -326151, 16433, 8747, 22971, 234071, 16647.49202650502, -15280, -27905, -980029, 20721, "0/cq!o(j&5mo!0&ai@*k663", -9100, -45533, 15854.703132739056, 282724));
ck_assert_str_eq(boba922_s21, boba922);
}
END_TEST

START_TEST(bebasik__923) {
char boba923_s21[10000];
char boba923[10000];
ck_assert_int_eq(s21_sprintf(boba923_s21, "% hi%+.9hi175)sr577% 6hi%-hij%+5.1hi% 1ft%+i% 6.9his-8%+5f% d9% .9ilu% .1hi%-hd%+dj%+1.8hi7d%-.3i%-.5huwr3a=%+f%+dyp8%+7.3hi%+.3hi%+8.3hi8y% 4f%-hd", -12291, 6790, 25843, -18337, -19290, 15297.367522300521, 142237, 3553, 7192.767355204694, 503881, 422734, 3653, -27789, 886155, 1830, 466377, 8931, -15695.389472339588, 207240, 16157, -22284, 22257, -1980.6445947582824, 16453),
sprintf(boba923, "% hi%+.9hi175)sr577% 6hi%-hij%+5.1hi% 1ft%+i% 6.9his-8%+5f% d9% .9ilu% .1hi%-hd%+dj%+1.8hi7d%-.3i%-.5huwr3a=%+f%+dyp8%+7.3hi%+.3hi%+8.3hi8y% 4f%-hd", -12291, 6790, 25843, -18337, -19290, 15297.367522300521, 142237, 3553, 7192.767355204694, 503881, 422734, 3653, -27789, 886155, 1830, 466377, 8931, -15695.389472339588, 207240, 16157, -22284, 22257, -1980.6445947582824, 16453));
ck_assert_str_eq(boba923_s21, boba923);
}
END_TEST

START_TEST(bebasik__924) {
char boba924_s21[10000];
char boba924[10000];
ck_assert_int_eq(s21_sprintf(boba924_s21, "%-9.8in%-1.8u%-10.1hi/x%-4.8hu%+hi%+.7hdo.%+4f%+4.4hi% .4d@&dg%-f%-.2hu% 5.2f%+10hd(", -790208, 384215, -8174, 27008, 17114, 17502, 443.28793076527046, 20534, 129042, -5380.233265353312, 6507, 3669.7398133939005, -14775),
sprintf(boba924, "%-9.8in%-1.8u%-10.1hi/x%-4.8hu%+hi%+.7hdo.%+4f%+4.4hi% .4d@&dg%-f%-.2hu% 5.2f%+10hd(", -790208, 384215, -8174, 27008, 17114, 17502, 443.28793076527046, 20534, 129042, -5380.233265353312, 6507, 3669.7398133939005, -14775));
ck_assert_str_eq(boba924_s21, boba924);
}
END_TEST

START_TEST(bebasik__925) {
char boba925_s21[10000];
char boba925[10000];
ck_assert_int_eq(s21_sprintf(boba925_s21, "%+i% .6hd% .7hi%-.5hu%-2u8% 1hdhm%+1i%-1hu%+10is$%-.2s% i% .7f=% 4d% 5f#.9% 7.7hi2% .4hi7%-1d%+5dt8% .1d%+hd", -426131, 826, 29060, -16513, 914980, -6816, -868160, -16548, -500743, "=623so", -659292, 21010.84668822227, 538411, -945.2390053607539, -13617, 14646, 368019, -935402, -86564, -1989),
sprintf(boba925, "%+i% .6hd% .7hi%-.5hu%-2u8% 1hdhm%+1i%-1hu%+10is$%-.2s% i% .7f=% 4d% 5f#.9% 7.7hi2% .4hi7%-1d%+5dt8% .1d%+hd", -426131, 826, 29060, -16513, 914980, -6816, -868160, -16548, -500743, "=623so", -659292, 21010.84668822227, 538411, -945.2390053607539, -13617, 14646, 368019, -935402, -86564, -1989));
ck_assert_str_eq(boba925_s21, boba925);
}
END_TEST

START_TEST(bebasik__926) {
char boba926_s21[10000];
char boba926[10000];
ck_assert_int_eq(s21_sprintf(boba926_s21, "%+6.8hinm9%+f% 8hd%+2hdmu%-hi^%-9hu9%+5.0f1`fo,g%-.8i%+1.6d% hdd%+4d% 6.1dk%-7.10hd6c!%+4hi`i% 7hi%-3hu6,", -29972, 6623.139001182279, 16318, 8244, 19891, -3187, -27074.443014622404, -827636, -746207, 5840, -528419, -524333, 10640, -23524, -16388, -7477),
sprintf(boba926, "%+6.8hinm9%+f% 8hd%+2hdmu%-hi^%-9hu9%+5.0f1`fo,g%-.8i%+1.6d% hdd%+4d% 6.1dk%-7.10hd6c!%+4hi`i% 7hi%-3hu6,", -29972, 6623.139001182279, 16318, 8244, 19891, -3187, -27074.443014622404, -827636, -746207, 5840, -528419, -524333, 10640, -23524, -16388, -7477));
ck_assert_str_eq(boba926_s21, boba926);
}
END_TEST

START_TEST(bebasik__927) {
char boba927_s21[10000];
char boba927[10000];
ck_assert_int_eq(s21_sprintf(boba927_s21, "%+2dc%-f%+10.2hi% 10f!i.=s% f%-9c%-.8hi%-1hd% .5f%+8.8hd% .7d%+d;% .4hiyz(!%-5.0i/% d%+.6d%+8.5i.x% .10hi% .0d%-c%+i", 276852, -394.3905541546692, -29008, -5662.200422532701, -9380.952320678958, 'p', 17618, -16402, 12508.080412512387, -10403, 41581, -442140, -26313, 558216, -815662, -476072, -812903, 1, 157837, ';', 45204),
sprintf(boba927, "%+2dc%-f%+10.2hi% 10f!i.=s% f%-9c%-.8hi%-1hd% .5f%+8.8hd% .7d%+d;% .4hiyz(!%-5.0i/% d%+.6d%+8.5i.x% .10hi% .0d%-c%+i", 276852, -394.3905541546692, -29008, -5662.200422532701, -9380.952320678958, 'p', 17618, -16402, 12508.080412512387, -10403, 41581, -442140, -26313, 558216, -815662, -476072, -812903, 1, 157837, ';', 45204));
ck_assert_str_eq(boba927_s21, boba927);
}
END_TEST

START_TEST(bebasik__928) {
char boba928_s21[10000];
char boba928[10000];
ck_assert_int_eq(s21_sprintf(boba928_s21, "%+.6f9e3#%-hik% .10i", -15286.288539716987, 17748, 786658),
sprintf(boba928, "%+.6f9e3#%-hik% .10i", -15286.288539716987, 17748, 786658));
ck_assert_str_eq(boba928_s21, boba928);
}
END_TEST

START_TEST(bebasik__929) {
char boba929_s21[10000];
char boba929[10000];
ck_assert_int_eq(s21_sprintf(boba929_s21, "%+d%-3s(%+5i%-8d!%-5.3s4%+2f$t% 7dc%+hd%-6hixv% hd.k%+.1hix%-5hdd%+9hi% 7f%+hi", -150445, "&", 876127, 389359, "7@g4.#-4", -853.9916715367385, 695506, 19559, -782, 10776, 23136, 746, -31579, -9544.208497616608, 8817),
sprintf(boba929, "%+d%-3s(%+5i%-8d!%-5.3s4%+2f$t% 7dc%+hd%-6hixv% hd.k%+.1hix%-5hdd%+9hi% 7f%+hi", -150445, "&", 876127, 389359, "7@g4.#-4", -853.9916715367385, 695506, 19559, -782, 10776, 23136, 746, -31579, -9544.208497616608, 8817));
ck_assert_str_eq(boba929_s21, boba929);
}
END_TEST

START_TEST(bebasik__930) {
char boba930_s21[10000];
char boba930[10000];
ck_assert_int_eq(s21_sprintf(boba930_s21, "%-.1hu% hi% 4.0ih%-u9%-7s%-3.4hd% hd4%+6.10d/x&% .10f2%+hd", 18816, 21044, 333060, 195072, "", -30374, 31102, -560718, 157.70636790454492, -24056),
sprintf(boba930, "%-.1hu% hi% 4.0ih%-u9%-7s%-3.4hd% hd4%+6.10d/x&% .10f2%+hd", 18816, 21044, 333060, 195072, "", -30374, 31102, -560718, 157.70636790454492, -24056));
ck_assert_str_eq(boba930_s21, boba930);
}
END_TEST

START_TEST(bebasik__931) {
char boba931_s21[10000];
char boba931[10000];
ck_assert_int_eq(s21_sprintf(boba931_s21, "%-4.7i%+5hi4x*%+9hd%+10f[-c%-.7i% 7hi% .8d@k3kq%+6f% 6.4f%-10d% 5hd%+8hip", -260191, 13880, -13428, -8506.054989278196, -114981, -7000, -180711, 902.2380170643203, -19009.208793844988, -141736, -23749, 2654),
sprintf(boba931, "%-4.7i%+5hi4x*%+9hd%+10f[-c%-.7i% 7hi% .8d@k3kq%+6f% 6.4f%-10d% 5hd%+8hip", -260191, 13880, -13428, -8506.054989278196, -114981, -7000, -180711, 902.2380170643203, -19009.208793844988, -141736, -23749, 2654));
ck_assert_str_eq(boba931_s21, boba931);
}
END_TEST

START_TEST(bebasik__932) {
char boba932_s21[10000];
char boba932[10000];
ck_assert_int_eq(s21_sprintf(boba932_s21, "%-.2hi2v%+8.6hdv% 1hi%+.6d%+.3hdx=egb% 10.3f%+4hi7%-f6&%-9.3hd% izhw", -1221, 3501, -14515, 645389, 23129, -250.70808654078812, 11083, -13502.123184317059, -15208, 373627),
sprintf(boba932, "%-.2hi2v%+8.6hdv% 1hi%+.6d%+.3hdx=egb% 10.3f%+4hi7%-f6&%-9.3hd% izhw", -1221, 3501, -14515, 645389, 23129, -250.70808654078812, 11083, -13502.123184317059, -15208, 373627));
ck_assert_str_eq(boba932_s21, boba932);
}
END_TEST

START_TEST(bebasik__933) {
char boba933_s21[10000];
char boba933[10000];
ck_assert_int_eq(s21_sprintf(boba933_s21, "%+dfy3", -606382),
sprintf(boba933, "%+dfy3", -606382));
ck_assert_str_eq(boba933_s21, boba933);
}
END_TEST

START_TEST(bebasik__934) {
char boba934_s21[10000];
char boba934[10000];
ck_assert_int_eq(s21_sprintf(boba934_s21, "%+6.8f%+2.0hi*%-4.3d%-.8s% i%-.7i5% 10.1hioa0%-.8sh#kh%+3d% 1hi%-hu^uk,%+8f@%+8hd% f", -47.305214015278324, 24465, -707222, "xkwy8z)fhp21(@", -245265, -383583, -19421, "", -547, -18402, -3897, 7677.745428383906, 12972, -14078.035517481074),
sprintf(boba934, "%+6.8f%+2.0hi*%-4.3d%-.8s% i%-.7i5% 10.1hioa0%-.8sh#kh%+3d% 1hi%-hu^uk,%+8f@%+8hd% f", -47.305214015278324, 24465, -707222, "xkwy8z)fhp21(@", -245265, -383583, -19421, "", -547, -18402, -3897, 7677.745428383906, 12972, -14078.035517481074));
ck_assert_str_eq(boba934_s21, boba934);
}
END_TEST

START_TEST(bebasik__935) {
char boba935_s21[10000];
char boba935[10000];
ck_assert_int_eq(s21_sprintf(boba935_s21, "%+.7hi=j%-6hd%+djw%+9hi&%-7hi%+8f% 5hi%+i%-hu&f%-.9hd^%-3s", -27020, -10369, -406143, -18343, -11535, 2833.2624098575952, 14812, 169093, 30295, 23050, "a/@6n4w/)./.,bl;3^j$-v[^"),
sprintf(boba935, "%+.7hi=j%-6hd%+djw%+9hi&%-7hi%+8f% 5hi%+i%-hu&f%-.9hd^%-3s", -27020, -10369, -406143, -18343, -11535, 2833.2624098575952, 14812, 169093, 30295, 23050, "a/@6n4w/)./.,bl;3^j$-v[^"));
ck_assert_str_eq(boba935_s21, boba935);
}
END_TEST

START_TEST(bebasik__936) {
char boba936_s21[10000];
char boba936[10000];
ck_assert_int_eq(s21_sprintf(boba936_s21, "%+1.7i", 24175),
sprintf(boba936, "%+1.7i", 24175));
ck_assert_str_eq(boba936_s21, boba936);
}
END_TEST

START_TEST(bebasik__937) {
char boba937_s21[10000];
char boba937[10000];
ck_assert_int_eq(s21_sprintf(boba937_s21, "% 9hdta%+.10hi% 3d%-.10hu*35% 7d/% .10f#%-3.9hd", -15519, -23089, -17890, 2061, 349645, -8604.81774948609, -593),
sprintf(boba937, "% 9hdta%+.10hi% 3d%-.10hu*35% 7d/% .10f#%-3.9hd", -15519, -23089, -17890, 2061, 349645, -8604.81774948609, -593));
ck_assert_str_eq(boba937_s21, boba937);
}
END_TEST

START_TEST(bebasik__938) {
char boba938_s21[10000];
char boba938[10000];
ck_assert_int_eq(s21_sprintf(boba938_s21, "% d%+f^$% 6.3hiua7%+2hd%-.10fz% 7hin%-.0hix%-8.3i%+2.8ip;u%-.10hu7%-c%+9.2hi% .8f%+4i%-5.3f@%-6.7hi1% .8f8%+10hit-*%-.5s%+.9i)%+fh2%+.4ikw=% 2d", -53081, -11373.297414309918, 31740, 14180, -11678.46442868003, -27179, 8659, -292472, 251602, 29239, 'u', 31043, -4827.001547373484, -224520, 4275.6474205559, 23356, 6928.0207076401975, 5246, ".octz)k*rjppwkrrb", -735629, -11139.972750920006, 789586, -68087),
sprintf(boba938, "% d%+f^$% 6.3hiua7%+2hd%-.10fz% 7hin%-.0hix%-8.3i%+2.8ip;u%-.10hu7%-c%+9.2hi% .8f%+4i%-5.3f@%-6.7hi1% .8f8%+10hit-*%-.5s%+.9i)%+fh2%+.4ikw=% 2d", -53081, -11373.297414309918, 31740, 14180, -11678.46442868003, -27179, 8659, -292472, 251602, 29239, 'u', 31043, -4827.001547373484, -224520, 4275.6474205559, 23356, 6928.0207076401975, 5246, ".octz)k*rjppwkrrb", -735629, -11139.972750920006, 789586, -68087));
ck_assert_str_eq(boba938_s21, boba938);
}
END_TEST

START_TEST(bebasik__939) {
char boba939_s21[10000];
char boba939[10000];
ck_assert_int_eq(s21_sprintf(boba939_s21, "% hih% 7hd5% 7d5o%-9seu%-2.1huo2)%-.8sr% 8.7hdo%+.0f%-2hivr;% .4hd=%+3.3hd% iz% im7%-c%-huugp% 3.5i%-huzy;pq%-8hd.%+5hi%+.3hd9%+.0hdg4[1r1&% im%+4i[%-.7hu", -21350, 4200, -336466, "8l`i/;[.k$&hx1chlog@6$;i$", 10085, "ubw/y1f0ov3e0z-wni`u!3x-[^", -20762, 9879.967604163887, 26325, -20857, -29638, -105442, -753066, 'o', -8869, 131496, -617, 30647, -2077, 25643, 17708, 647331, 30026, -18491),
sprintf(boba939, "% hih% 7hd5% 7d5o%-9seu%-2.1huo2)%-.8sr% 8.7hdo%+.0f%-2hivr;% .4hd=%+3.3hd% iz% im7%-c%-huugp% 3.5i%-huzy;pq%-8hd.%+5hi%+.3hd9%+.0hdg4[1r1&% im%+4i[%-.7hu", -21350, 4200, -336466, "8l`i/;[.k$&hx1chlog@6$;i$", 10085, "ubw/y1f0ov3e0z-wni`u!3x-[^", -20762, 9879.967604163887, 26325, -20857, -29638, -105442, -753066, 'o', -8869, 131496, -617, 30647, -2077, 25643, 17708, 647331, 30026, -18491));
ck_assert_str_eq(boba939_s21, boba939);
}
END_TEST

START_TEST(bebasik__940) {
char boba940_s21[10000];
char boba940[10000];
ck_assert_int_eq(s21_sprintf(boba940_s21, "%+hi%-2.4i% i% 8hd%+.2f% d1", 17805, -327313, 935702, -4373, 12160.79198186183, -176804),
sprintf(boba940, "%+hi%-2.4i% i% 8hd%+.2f% d1", 17805, -327313, 935702, -4373, 12160.79198186183, -176804));
ck_assert_str_eq(boba940_s21, boba940);
}
END_TEST

START_TEST(bebasik__941) {
char boba941_s21[10000];
char boba941[10000];
ck_assert_int_eq(s21_sprintf(boba941_s21, "% .3hio,% hi$u%-hi%+9.9hdl.uf%-3.1f%-2his% .10hi;c% .2fp%+1hi% 1hi9iz!", -7645, 5977, 24272, 6552, -1420.9766244171692, 352, -21775, -141.191485646936, -31572, 3779),
sprintf(boba941, "% .3hio,% hi$u%-hi%+9.9hdl.uf%-3.1f%-2his% .10hi;c% .2fp%+1hi% 1hi9iz!", -7645, 5977, 24272, 6552, -1420.9766244171692, 352, -21775, -141.191485646936, -31572, 3779));
ck_assert_str_eq(boba941_s21, boba941);
}
END_TEST

START_TEST(bebasik__942) {
char boba942_s21[10000];
char boba942[10000];
ck_assert_int_eq(s21_sprintf(boba942_s21, "%-c% 2.5df%+hi%-u% .7i% 10.9hi%-.4i!y%-c% hi%-5.9uo)%+1.5it=%+1.3hd%+5.8d% hd$)q%-hi% 10.3iv%-.10i%+4d% .7i*%+fp,% 6.7hd);lu5`%+.10hd%-hu% .4hdl1", 'k', 148950, -30710, -845698, -582033, -16245, -807344, '6', 29223, 229048, 646151, 15392, -649252, 17388, -12452, -823802, 425317, 487428, 24250, 18974.84966403937, -997, 3857, 30004, -5403),
sprintf(boba942, "%-c% 2.5df%+hi%-u% .7i% 10.9hi%-.4i!y%-c% hi%-5.9uo)%+1.5it=%+1.3hd%+5.8d% hd$)q%-hi% 10.3iv%-.10i%+4d% .7i*%+fp,% 6.7hd);lu5`%+.10hd%-hu% .4hdl1", 'k', 148950, -30710, -845698, -582033, -16245, -807344, '6', 29223, 229048, 646151, 15392, -649252, 17388, -12452, -823802, 425317, 487428, 24250, 18974.84966403937, -997, 3857, 30004, -5403));
ck_assert_str_eq(boba942_s21, boba942);
}
END_TEST

START_TEST(bebasik__943) {
char boba943_s21[10000];
char boba943[10000];
ck_assert_int_eq(s21_sprintf(boba943_s21, "%-.6hu;% 5.9i", 25710, 567162),
sprintf(boba943, "%-.6hu;% 5.9i", 25710, 567162));
ck_assert_str_eq(boba943_s21, boba943);
}
END_TEST

START_TEST(bebasik__944) {
char boba944_s21[10000];
char boba944[10000];
ck_assert_int_eq(s21_sprintf(boba944_s21, "%+fo%-.7i%+10.5hdq9d% 1f%+.2hd[%-hi^o% hd% hd% hdm/e%-6.2f% 4.7hdp% .8hi", -3038.005543863024, -377653, -18252, 14836.155346265796, 29699, -1301, 25597, -5058, -12599, -5089.832670481048, 24973, 15890),
sprintf(boba944, "%+fo%-.7i%+10.5hdq9d% 1f%+.2hd[%-hi^o% hd% hd% hdm/e%-6.2f% 4.7hdp% .8hi", -3038.005543863024, -377653, -18252, 14836.155346265796, 29699, -1301, 25597, -5058, -12599, -5089.832670481048, 24973, 15890));
ck_assert_str_eq(boba944_s21, boba944);
}
END_TEST

START_TEST(bebasik__945) {
char boba945_s21[10000];
char boba945[10000];
ck_assert_int_eq(s21_sprintf(boba945_s21, "%+.10f%-8.9do%-.8hux%-8.5i%+.1hd4%+10i% .0hd% hi% 4hd!(7*(;% 8hdt%-.9hi", 12163.686018019307, 519784, 2642, 950944, -2327, 827274, 5997, 17963, 880, 8830, 8254),
sprintf(boba945, "%+.10f%-8.9do%-.8hux%-8.5i%+.1hd4%+10i% .0hd% hi% 4hd!(7*(;% 8hdt%-.9hi", 12163.686018019307, 519784, 2642, 950944, -2327, 827274, 5997, 17963, 880, 8830, 8254));
ck_assert_str_eq(boba945_s21, boba945);
}
END_TEST

START_TEST(bebasik__946) {
char boba946_s21[10000];
char boba946[10000];
ck_assert_int_eq(s21_sprintf(boba946_s21, "% 8.7hi%+3.6fu%+.0d;d% hd(%+6f% 8.9i% hdb%+3.2f% 8d@% 8f%+1.9hi%+1hi% 5f", 26633, 11420.549326205877, -551374, 31912, -214.83235488785778, 502803, 2453, -3912.205864390902, -70580, -16410.148495174562, 27200, 16951, -1626.7211044560054),
sprintf(boba946, "% 8.7hi%+3.6fu%+.0d;d% hd(%+6f% 8.9i% hdb%+3.2f% 8d@% 8f%+1.9hi%+1hi% 5f", 26633, 11420.549326205877, -551374, 31912, -214.83235488785778, 502803, 2453, -3912.205864390902, -70580, -16410.148495174562, 27200, 16951, -1626.7211044560054));
ck_assert_str_eq(boba946_s21, boba946);
}
END_TEST

START_TEST(bebasik__947) {
char boba947_s21[10000];
char boba947[10000];
ck_assert_int_eq(s21_sprintf(boba947_s21, "%+9i%+4.8hd9=s%-8.5d% 3.6hd%+.10hdgr%+.8f&%+4hdw%-.7huu%-2.8i%+.5d%-hu&% d9%+5.1hi%+2.7f% hd% 7.4f%-7.3hi[q%+.5hiqc%+ft%+8f4zgr% 9.9d", -911603, 14802, -386684, 7448, 16609, -10743.12949237744, 14190, -12670, -127214, 193722, -6172, -464307, -26175, 3484.9170338975946, -3647, -4008.0359709872305, 10595, -4923, 15090.136808348005, 6997.561916337768, -519423),
sprintf(boba947, "%+9i%+4.8hd9=s%-8.5d% 3.6hd%+.10hdgr%+.8f&%+4hdw%-.7huu%-2.8i%+.5d%-hu&% d9%+5.1hi%+2.7f% hd% 7.4f%-7.3hi[q%+.5hiqc%+ft%+8f4zgr% 9.9d", -911603, 14802, -386684, 7448, 16609, -10743.12949237744, 14190, -12670, -127214, 193722, -6172, -464307, -26175, 3484.9170338975946, -3647, -4008.0359709872305, 10595, -4923, 15090.136808348005, 6997.561916337768, -519423));
ck_assert_str_eq(boba947_s21, boba947);
}
END_TEST

START_TEST(bebasik__948) {
char boba948_s21[10000];
char boba948[10000];
ck_assert_int_eq(s21_sprintf(boba948_s21, "%+3hdu", 11028),
sprintf(boba948, "%+3hdu", 11028));
ck_assert_str_eq(boba948_s21, boba948);
}
END_TEST

START_TEST(bebasik__949) {
char boba949_s21[10000];
char boba949[10000];
ck_assert_int_eq(s21_sprintf(boba949_s21, "%+.1hi!kt% 10d=h% f% 4.10hd% 10.10i2%-4hd%+9hi)%+hi)%+.10f)huuj% .1hi% .6di%-5.2hi5ml7% .3d&% 3.5hi!%-9d% .7hi%+4.4him!% 8d% hdl@&%+.4hi% hd^%+5.2f% 2.2hixq", -3284, -353243, -10160.160837609043, -23005, -597129, 1564, -5077, 21252, 9397.878383930483, 2257, -606894, -31916, -426371, 4808, 289931, -21940, 1998, 595622, -3957, 15210, 5721, -28734.62601167175, 17691),
sprintf(boba949, "%+.1hi!kt% 10d=h% f% 4.10hd% 10.10i2%-4hd%+9hi)%+hi)%+.10f)huuj% .1hi% .6di%-5.2hi5ml7% .3d&% 3.5hi!%-9d% .7hi%+4.4him!% 8d% hdl@&%+.4hi% hd^%+5.2f% 2.2hixq", -3284, -353243, -10160.160837609043, -23005, -597129, 1564, -5077, 21252, 9397.878383930483, 2257, -606894, -31916, -426371, 4808, 289931, -21940, 1998, 595622, -3957, 15210, 5721, -28734.62601167175, 17691));
ck_assert_str_eq(boba949_s21, boba949);
}
END_TEST

START_TEST(bebasik__950) {
char boba950_s21[10000];
char boba950[10000];
ck_assert_int_eq(s21_sprintf(boba950_s21, "%+.9hd%-6hd%+.4i%-7hi% dtt%+3.7f2@cv@%+9hi$%+10.8d=n9%+.0i%-.8f%-.3f%+4.1i(7ba%+8hi% .6d%-hu3%-hiy%-8.8hiz%+hi2)", 24160, 7737, -2178, -4250, -505936, 6325.5208100913405, -15045, -844192, 354758, 250.61890413212873, 1731.8455249502726, -538511, -20202, 65477, -27350, 10860, 30801, 19903),
sprintf(boba950, "%+.9hd%-6hd%+.4i%-7hi% dtt%+3.7f2@cv@%+9hi$%+10.8d=n9%+.0i%-.8f%-.3f%+4.1i(7ba%+8hi% .6d%-hu3%-hiy%-8.8hiz%+hi2)", 24160, 7737, -2178, -4250, -505936, 6325.5208100913405, -15045, -844192, 354758, 250.61890413212873, 1731.8455249502726, -538511, -20202, 65477, -27350, 10860, 30801, 19903));
ck_assert_str_eq(boba950_s21, boba950);
}
END_TEST

START_TEST(bebasik__951) {
char boba951_s21[10000];
char boba951[10000];
ck_assert_int_eq(s21_sprintf(boba951_s21, "% 5.6hi%-7hu-d%-.7hu% 8.5dj1`o#% 7f#%-d%+3.3f%+hdm%-hi%-8f%-1.9hi% 6.5d5b% hdg%+.8hd%-.8f%-.8hd% 6.1hi% .4hi%+d", 14339, 19218, 26049, -776726, -8976.877654182794, -907779, -11481.625061884462, 10471, -23827, 6880.731146170433, 18729, 862192, 1032, 1357, 22849.357564212787, 1842, -290, 26260, -635941),
sprintf(boba951, "% 5.6hi%-7hu-d%-.7hu% 8.5dj1`o#% 7f#%-d%+3.3f%+hdm%-hi%-8f%-1.9hi% 6.5d5b% hdg%+.8hd%-.8f%-.8hd% 6.1hi% .4hi%+d", 14339, 19218, 26049, -776726, -8976.877654182794, -907779, -11481.625061884462, 10471, -23827, 6880.731146170433, 18729, 862192, 1032, 1357, 22849.357564212787, 1842, -290, 26260, -635941));
ck_assert_str_eq(boba951_s21, boba951);
}
END_TEST

START_TEST(bebasik__952) {
char boba952_s21[10000];
char boba952[10000];
ck_assert_int_eq(s21_sprintf(boba952_s21, "%-6c% dd%-.4hdo2% hitr%+1i%+5hi3c% fx%+.2d%+6flc%+6.8f%+hd% f% hib%+.7hd", 'u', 198113, -17659, -9085, -628793, 22394, -7305.708029479828, -953903, -1944.9487680896525, -9226.270455463606, 7302, 3459.076799430248, 2693, -113),
sprintf(boba952, "%-6c% dd%-.4hdo2% hitr%+1i%+5hi3c% fx%+.2d%+6flc%+6.8f%+hd% f% hib%+.7hd", 'u', 198113, -17659, -9085, -628793, 22394, -7305.708029479828, -953903, -1944.9487680896525, -9226.270455463606, 7302, 3459.076799430248, 2693, -113));
ck_assert_str_eq(boba952_s21, boba952);
}
END_TEST

START_TEST(bebasik__953) {
char boba953_s21[10000];
char boba953[10000];
ck_assert_int_eq(s21_sprintf(boba953_s21, "%+2hi%+9hd%+2.6f%+6hd%+d% 8.8hi%+.2f% 10i%-cg% 5i#g6f%-hd% 1i%+3.5hd", 29211, -19707, 12213.605698504594, 21999, 483756, -2029, 21921.05893500621, -905860, '/', -822227, -24967, -940501, 10933),
sprintf(boba953, "%+2hi%+9hd%+2.6f%+6hd%+d% 8.8hi%+.2f% 10i%-cg% 5i#g6f%-hd% 1i%+3.5hd", 29211, -19707, 12213.605698504594, 21999, 483756, -2029, 21921.05893500621, -905860, '/', -822227, -24967, -940501, 10933));
ck_assert_str_eq(boba953_s21, boba953);
}
END_TEST

START_TEST(bebasik__954) {
char boba954_s21[10000];
char boba954[10000];
ck_assert_int_eq(s21_sprintf(boba954_s21, "% 5.3f%-4.5hi^%-8.2d% 1.6hiwf7% hi2a%+3hi% .8i%-.9hu%+10.4dj%-hd5%-c*o0p%-9.5f%-9.4s% .6f&% 5.7f%-.2s% df%-.8s%+2.8hi&3% i% 10hd%+d.@", 8506.833659067626, -507, -266556, 5190, -25015, 31598, -243808, 20532, 85699, 31281, 'y', -13304.896015550657, "[bf.9h(6i", 675.7967505237245, -6225.738308333207, "lc7^h8*/w7ewh[xg9w^@d", 527612, ")ml0", -16612, -786724, -11021, 562667),
sprintf(boba954, "% 5.3f%-4.5hi^%-8.2d% 1.6hiwf7% hi2a%+3hi% .8i%-.9hu%+10.4dj%-hd5%-c*o0p%-9.5f%-9.4s% .6f&% 5.7f%-.2s% df%-.8s%+2.8hi&3% i% 10hd%+d.@", 8506.833659067626, -507, -266556, 5190, -25015, 31598, -243808, 20532, 85699, 31281, 'y', -13304.896015550657, "[bf.9h(6i", 675.7967505237245, -6225.738308333207, "lc7^h8*/w7ewh[xg9w^@d", 527612, ")ml0", -16612, -786724, -11021, 562667));
ck_assert_str_eq(boba954_s21, boba954);
}
END_TEST

START_TEST(bebasik__955) {
char boba955_s21[10000];
char boba955[10000];
ck_assert_int_eq(s21_sprintf(boba955_s21, "%+6.1hi%-6.8u% 9.0hilx% 4hi%+6.4hiu.c1j%-8hi% 4.4hd% f% .3d% .0hi%-.5hdk% 5f%+2.1do#v)%+5i%-us%+10i%-.5hden%+hd*% i%+.3dd", 13713, -810428, 12677, -26913, -15248, -22201, 26252, 10395.03578580599, 400971, 21176, 15644, -586.3034524813892, -349543, -474848, -469754, 527483, -12160, 6893, -705813, 934621),
sprintf(boba955, "%+6.1hi%-6.8u% 9.0hilx% 4hi%+6.4hiu.c1j%-8hi% 4.4hd% f% .3d% .0hi%-.5hdk% 5f%+2.1do#v)%+5i%-us%+10i%-.5hden%+hd*% i%+.3dd", 13713, -810428, 12677, -26913, -15248, -22201, 26252, 10395.03578580599, 400971, 21176, 15644, -586.3034524813892, -349543, -474848, -469754, 527483, -12160, 6893, -705813, 934621));
ck_assert_str_eq(boba955_s21, boba955);
}
END_TEST

START_TEST(bebasik__956) {
char boba956_s21[10000];
char boba956[10000];
ck_assert_int_eq(s21_sprintf(boba956_s21, "%-.5hd0w%+4.1hd% ie$%-9.2higf%-7s%-5.1f6%-.1hi!%-10.2hd(%-.9u%+i% fwi", 4606, 710, -602726, 21069, "aao0uy49i##950hki[8s", -797.5252834949601, 28911, -25423, -744801, -4776, 557.7672754407924),
sprintf(boba956, "%-.5hd0w%+4.1hd% ie$%-9.2higf%-7s%-5.1f6%-.1hi!%-10.2hd(%-.9u%+i% fwi", 4606, 710, -602726, 21069, "aao0uy49i##950hki[8s", -797.5252834949601, 28911, -25423, -744801, -4776, 557.7672754407924));
ck_assert_str_eq(boba956_s21, boba956);
}
END_TEST

START_TEST(bebasik__957) {
char boba957_s21[10000];
char boba957[10000];
ck_assert_int_eq(s21_sprintf(boba957_s21, "% 4.9hd", 24420),
sprintf(boba957, "% 4.9hd", 24420));
ck_assert_str_eq(boba957_s21, boba957);
}
END_TEST

START_TEST(bebasik__958) {
char boba958_s21[10000];
char boba958[10000];
ck_assert_int_eq(s21_sprintf(boba958_s21, "% 9.1hd%+.4i2@% .10hd% .6i% 6.0hd%+7i%+2.6hi%+1.10hd%-.1hi", -14800, -804620, 9364, 467048, 13604, -95058, 29097, -13344, 2729),
sprintf(boba958, "% 9.1hd%+.4i2@% .10hd% .6i% 6.0hd%+7i%+2.6hi%+1.10hd%-.1hi", -14800, -804620, 9364, 467048, 13604, -95058, 29097, -13344, 2729));
ck_assert_str_eq(boba958_s21, boba958);
}
END_TEST

START_TEST(bebasik__959) {
char boba959_s21[10000];
char boba959[10000];
ck_assert_int_eq(s21_sprintf(boba959_s21, "%-4.3i%-d%+7.5fn$c% .8hi%+7hd%-.9fe7%-6hua%+7f%-.2sd%+hdd%-5.9hu%-hi% hi2%-.5hi)% .6dwt%-7f% 9.1hd4%+.0hilh% d0%+i%+4.8hi%-1.9hd)w%+8hd#ag% .2hd", -659462, 370446, -8883.432909466159, -15981, -11350, -1445.2015268025764, -27071, -220.8778537010498, "^0oh39;&5mb8h#h0u,jzg", -14352, -3501, -25368, 23704, -15731, 712965, 3377.313198874448, -21735, 18993, -262485, -448344, 18239, -15170, -15244, -27384),
sprintf(boba959, "%-4.3i%-d%+7.5fn$c% .8hi%+7hd%-.9fe7%-6hua%+7f%-.2sd%+hdd%-5.9hu%-hi% hi2%-.5hi)% .6dwt%-7f% 9.1hd4%+.0hilh% d0%+i%+4.8hi%-1.9hd)w%+8hd#ag% .2hd", -659462, 370446, -8883.432909466159, -15981, -11350, -1445.2015268025764, -27071, -220.8778537010498, "^0oh39;&5mb8h#h0u,jzg", -14352, -3501, -25368, 23704, -15731, 712965, 3377.313198874448, -21735, 18993, -262485, -448344, 18239, -15170, -15244, -27384));
ck_assert_str_eq(boba959_s21, boba959);
}
END_TEST

START_TEST(bebasik__960) {
char boba960_s21[10000];
char boba960[10000];
ck_assert_int_eq(s21_sprintf(boba960_s21, "%+hdxi77l% .4hd!gllh/q$%-6.1hu% .8hd% .7hdi%-d", -30474, 18892, -3838, 20783, 8724, 585384),
sprintf(boba960, "%+hdxi77l% .4hd!gllh/q$%-6.1hu% .8hd% .7hdi%-d", -30474, 18892, -3838, 20783, 8724, 585384));
ck_assert_str_eq(boba960_s21, boba960);
}
END_TEST

START_TEST(bebasik__961) {
char boba961_s21[10000];
char boba961[10000];
ck_assert_int_eq(s21_sprintf(boba961_s21, "%+10.1i,!j/oo%-.0hi[&(`% 2i4%-.6s%+3hi% 2i%-5hi@7%+9.8hd%-3hu,%+hd%-4dju2%-hi!/%+3d% 1hd(f%+f% 1.7d%-7i9% .3f%-1c", 79787, -14510, -180274, "1)tw8fv.(n[g$2^oz-=g8zs,e", -27636, 714342, -26309, 20905, -28421, -23664, 206441, -29009, 519555, -26619, -10264.133864712217, -374247, 185539, -10145.150387859248, 'j'),
sprintf(boba961, "%+10.1i,!j/oo%-.0hi[&(`% 2i4%-.6s%+3hi% 2i%-5hi@7%+9.8hd%-3hu,%+hd%-4dju2%-hi!/%+3d% 1hd(f%+f% 1.7d%-7i9% .3f%-1c", 79787, -14510, -180274, "1)tw8fv.(n[g$2^oz-=g8zs,e", -27636, 714342, -26309, 20905, -28421, -23664, 206441, -29009, 519555, -26619, -10264.133864712217, -374247, 185539, -10145.150387859248, 'j'));
ck_assert_str_eq(boba961_s21, boba961);
}
END_TEST

START_TEST(bebasik__962) {
char boba962_s21[10000];
char boba962[10000];
ck_assert_int_eq(s21_sprintf(boba962_s21, "% .4f2%-hu[^%+1hdd6% .9ds% hi%-9u", -628.1183098960095, -2455, 20843, 125096, 21265, 49612),
sprintf(boba962, "% .4f2%-hu[^%+1hdd6% .9ds% hi%-9u", -628.1183098960095, -2455, 20843, 125096, 21265, 49612));
ck_assert_str_eq(boba962_s21, boba962);
}
END_TEST

START_TEST(bebasik__963) {
char boba963_s21[10000];
char boba963[10000];
ck_assert_int_eq(s21_sprintf(boba963_s21, "%+7.9hi!e% 4.3hdeyk5$$% 9hi%-.0i2%+1i9%+10.6hdh7%+hd%-i%+9.9hd% 3.7hdkn% 6.10i%-hi%+1.10fw% 10.0hd%-2.2hu[u`%-9.1u6", -5403, -24978, 23959, 304000, 490388, -13281, 28176, -298760, -29670, -11294, -815579, 22675, 2472.7892837306576, 5190, 14001, 449861),
sprintf(boba963, "%+7.9hi!e% 4.3hdeyk5$$% 9hi%-.0i2%+1i9%+10.6hdh7%+hd%-i%+9.9hd% 3.7hdkn% 6.10i%-hi%+1.10fw% 10.0hd%-2.2hu[u`%-9.1u6", -5403, -24978, 23959, 304000, 490388, -13281, 28176, -298760, -29670, -11294, -815579, 22675, 2472.7892837306576, 5190, 14001, 449861));
ck_assert_str_eq(boba963_s21, boba963);
}
END_TEST

START_TEST(bebasik__964) {
char boba964_s21[10000];
char boba964[10000];
ck_assert_int_eq(s21_sprintf(boba964_s21, "%+9hd%-3hu%-in%-.1s%+2i^%-3.2f% 7i% 6.8d% .6hd% .0f", -31419, -17934, -154148, "0oh/c6j$-a[xe$;bo", -873071, -13208.353599865231, -406272, -327819, 18784, -1049.4943262680656),
sprintf(boba964, "%+9hd%-3hu%-in%-.1s%+2i^%-3.2f% 7i% 6.8d% .6hd% .0f", -31419, -17934, -154148, "0oh/c6j$-a[xe$;bo", -873071, -13208.353599865231, -406272, -327819, 18784, -1049.4943262680656));
ck_assert_str_eq(boba964_s21, boba964);
}
END_TEST

START_TEST(bebasik__965) {
char boba965_s21[10000];
char boba965[10000];
ck_assert_int_eq(s21_sprintf(boba965_s21, "%-i% .2i%+8hi%+2.0hieh5%+ire2x% 8.10f%-.9ic%+4d3l^%-hi!8kw% 2.10hi#h%+5.5i#%-i`oa", -865395, 29130, -4041, -2323, 948198, 30115.034786057295, -253091, 546956, -27261, 26827, -243729, -329696),
sprintf(boba965, "%-i% .2i%+8hi%+2.0hieh5%+ire2x% 8.10f%-.9ic%+4d3l^%-hi!8kw% 2.10hi#h%+5.5i#%-i`oa", -865395, 29130, -4041, -2323, 948198, 30115.034786057295, -253091, 546956, -27261, 26827, -243729, -329696));
ck_assert_str_eq(boba965_s21, boba965);
}
END_TEST

START_TEST(bebasik__966) {
char boba966_s21[10000];
char boba966[10000];
ck_assert_int_eq(s21_sprintf(boba966_s21, "% .2i8%-3hdu%+d% .4d%-6f% .4i%+2.4hd9% i.2%-hd%+3.3du% 4.8hi&%-.4hd!f%+1hie%+4.2hd6%+8.8hd%-.1i", -44747, -26539, 727600, -396491, 19032.98830184334, 657012, -26753, 684476, -29217, -30693, 11896, -28662, 23938, 24933, 13467, 497943),
sprintf(boba966, "% .2i8%-3hdu%+d% .4d%-6f% .4i%+2.4hd9% i.2%-hd%+3.3du% 4.8hi&%-.4hd!f%+1hie%+4.2hd6%+8.8hd%-.1i", -44747, -26539, 727600, -396491, 19032.98830184334, 657012, -26753, 684476, -29217, -30693, 11896, -28662, 23938, 24933, 13467, 497943));
ck_assert_str_eq(boba966_s21, boba966);
}
END_TEST

START_TEST(bebasik__967) {
char boba967_s21[10000];
char boba967[10000];
ck_assert_int_eq(s21_sprintf(boba967_s21, "%+9.2him%-5.3s*% 4ii%-s% 8.7f%-hu1-w-3-%-.0i%+9ih%-hu%-.10hd[f%+hi.n%+4hd^%+.1i%+hd% 4.6hi5%-1c`p0e%-darr4e*4d%-1ib%-.6s", -14736, "w/m^nsq)m39ns1a&j", 787404, ";qdrbwn`82(.1n7ly-.z0/1!", 1753.481354132736, -20251, 770957, -992077, 17984, -17722, 26425, 27124, -524016, 7848, -17526, '8', -577699, -602788, "g98f=@!"),
sprintf(boba967, "%+9.2him%-5.3s*% 4ii%-s% 8.7f%-hu1-w-3-%-.0i%+9ih%-hu%-.10hd[f%+hi.n%+4hd^%+.1i%+hd% 4.6hi5%-1c`p0e%-darr4e*4d%-1ib%-.6s", -14736, "w/m^nsq)m39ns1a&j", 787404, ";qdrbwn`82(.1n7ly-.z0/1!", 1753.481354132736, -20251, 770957, -992077, 17984, -17722, 26425, 27124, -524016, 7848, -17526, '8', -577699, -602788, "g98f=@!"));
ck_assert_str_eq(boba967_s21, boba967);
}
END_TEST

START_TEST(bebasik__968) {
char boba968_s21[10000];
char boba968[10000];
ck_assert_int_eq(s21_sprintf(boba968_s21, "%-1i% hd% 9i% hib[%-s% 3hi% .0hi%+hd%-hu%+2.8hd%-1.10u% 5d78%+.9hi.%+6.3i%+d^%+.7hd4,@0*f% 9.5it% 3.1hdg7% hd1e% 5hd% 7.2f!;% 2hdj%+5.0d", 507602, 18238, -509669, -12845, ".,`^;7&n.8/!ih", -18062, 25522, -11226, 28900, 29012, 82512, 527055, 7056, -892350, 563620, -8289, 760578, 23557, -31763, -29553, 13365.054644940417, -21132, -685965),
sprintf(boba968, "%-1i% hd% 9i% hib[%-s% 3hi% .0hi%+hd%-hu%+2.8hd%-1.10u% 5d78%+.9hi.%+6.3i%+d^%+.7hd4,@0*f% 9.5it% 3.1hdg7% hd1e% 5hd% 7.2f!;% 2hdj%+5.0d", 507602, 18238, -509669, -12845, ".,`^;7&n.8/!ih", -18062, 25522, -11226, 28900, 29012, 82512, 527055, 7056, -892350, 563620, -8289, 760578, 23557, -31763, -29553, 13365.054644940417, -21132, -685965));
ck_assert_str_eq(boba968_s21, boba968);
}
END_TEST

START_TEST(bebasik__969) {
char boba969_s21[10000];
char boba969[10000];
ck_assert_int_eq(s21_sprintf(boba969_s21, "% 7.0hdo.i%-10.10hi$n%+3.2hipwz@2%-1dt%+1.1hdh%+hd%-hi%-6hu%-8.4hu-6jzk%+hd% 8.4d*%+i/&*% d%+8.3f%-3u2i%+2i%+10i;%-hi#%-.0f0x", 3488, -5623, -29770, 577663, 5477, -27982, 29490, -31738, -2722, -12876, -991533, -102063, 299300, 16494.146577703126, -670316, -336684, -182491, 10458, 27729.292743794525),
sprintf(boba969, "% 7.0hdo.i%-10.10hi$n%+3.2hipwz@2%-1dt%+1.1hdh%+hd%-hi%-6hu%-8.4hu-6jzk%+hd% 8.4d*%+i/&*% d%+8.3f%-3u2i%+2i%+10i;%-hi#%-.0f0x", 3488, -5623, -29770, 577663, 5477, -27982, 29490, -31738, -2722, -12876, -991533, -102063, 299300, 16494.146577703126, -670316, -336684, -182491, 10458, 27729.292743794525));
ck_assert_str_eq(boba969_s21, boba969);
}
END_TEST

START_TEST(bebasik__970) {
char boba970_s21[10000];
char boba970[10000];
ck_assert_int_eq(s21_sprintf(boba970_s21, "% 9d%+iz%-i03%-8hd%+.5f%-2hi%+hi% hd%+2.4hd!% 7hd#a%+.3hi%+fe% .4f%+4hd", -888656, 972139, -157988, -15806, 524.9472159664015, -6813, -785, 21992, -3150, -18769, -4939, 15213.253122762355, -2761.027427950291, 13966),
sprintf(boba970, "% 9d%+iz%-i03%-8hd%+.5f%-2hi%+hi% hd%+2.4hd!% 7hd#a%+.3hi%+fe% .4f%+4hd", -888656, 972139, -157988, -15806, 524.9472159664015, -6813, -785, 21992, -3150, -18769, -4939, 15213.253122762355, -2761.027427950291, 13966));
ck_assert_str_eq(boba970_s21, boba970);
}
END_TEST

START_TEST(bebasik__971) {
char boba971_s21[10000];
char boba971[10000];
ck_assert_int_eq(s21_sprintf(boba971_s21, "% 2.1ik%+6hil4v@%-hd%-7hd%-6.7hu%+4.2fy% hi% d% .9hio% 1d%+d% 9hi@%-.0hdz%+6.8i5mcb%-7.2itf=", -349096, -30667, 29708, -18084, 30189, 15660.325651158073, 21059, 440443, -13874, -709154, -239795, 2696, -1119, -603158, 562119),
sprintf(boba971, "% 2.1ik%+6hil4v@%-hd%-7hd%-6.7hu%+4.2fy% hi% d% .9hio% 1d%+d% 9hi@%-.0hdz%+6.8i5mcb%-7.2itf=", -349096, -30667, 29708, -18084, 30189, 15660.325651158073, 21059, 440443, -13874, -709154, -239795, 2696, -1119, -603158, 562119));
ck_assert_str_eq(boba971_s21, boba971);
}
END_TEST

START_TEST(bebasik__972) {
char boba972_s21[10000];
char boba972[10000];
ck_assert_int_eq(s21_sprintf(boba972_s21, "%+f8% hi%+f[(z5,i%-.10hd0%+ih%+7hdr%+6hi%-.7f@%+2.8hio% 10.2hi8%+hi%-.9u% .9f% daq% 9.5hirc%+hij%-hd%-.5hd% hd^(jo% 1.0hd%+8.10hieno% .1i%+hi", 10329.169965438836, 29383, -7779.6359983289685, -3734, 950487, -3694, -13476, 5412.360947171494, -5390, -16948, -13579, -5605, -1095.6584311710583, -872520, 20276, -11738, 12750, 1201, 19316, -18158, 23057, -747482, -6890),
sprintf(boba972, "%+f8% hi%+f[(z5,i%-.10hd0%+ih%+7hdr%+6hi%-.7f@%+2.8hio% 10.2hi8%+hi%-.9u% .9f% daq% 9.5hirc%+hij%-hd%-.5hd% hd^(jo% 1.0hd%+8.10hieno% .1i%+hi", 10329.169965438836, 29383, -7779.6359983289685, -3734, 950487, -3694, -13476, 5412.360947171494, -5390, -16948, -13579, -5605, -1095.6584311710583, -872520, 20276, -11738, 12750, 1201, 19316, -18158, 23057, -747482, -6890));
ck_assert_str_eq(boba972_s21, boba972);
}
END_TEST

START_TEST(bebasik__973) {
char boba973_s21[10000];
char boba973[10000];
ck_assert_int_eq(s21_sprintf(boba973_s21, "%+4fq/%+.3ie%+.0dh%+8.0hiu% 10hd% .4hdw", -1246.6003802391813, -162137, 420461, 13323, 6688, -18114),
sprintf(boba973, "%+4fq/%+.3ie%+.0dh%+8.0hiu% 10hd% .4hdw", -1246.6003802391813, -162137, 420461, 13323, 6688, -18114));
ck_assert_str_eq(boba973_s21, boba973);
}
END_TEST

START_TEST(bebasik__974) {
char boba974_s21[10000];
char boba974[10000];
ck_assert_int_eq(s21_sprintf(boba974_s21, "% .7i%+6hi%-6.6d% .6d(d%+hi% 6.7hi% 10hdpwo% 9hd% 6d2,%-2.0hd2% .5f% 9hd% f% 8d%+10.9hd% .0hd%-.1u%+hdk% 5.2hd4%-4s", -510007, 22084, 339972, 261307, -22882, -28015, 23687, -2036, 220198, 942, -898.3872318825503, -16918, -5475.623704683714, -64626, 3848, -29870, -802648, -17936, -11603, "8blq(56!av"),
sprintf(boba974, "% .7i%+6hi%-6.6d% .6d(d%+hi% 6.7hi% 10hdpwo% 9hd% 6d2,%-2.0hd2% .5f% 9hd% f% 8d%+10.9hd% .0hd%-.1u%+hdk% 5.2hd4%-4s", -510007, 22084, 339972, 261307, -22882, -28015, 23687, -2036, 220198, 942, -898.3872318825503, -16918, -5475.623704683714, -64626, 3848, -29870, -802648, -17936, -11603, "8blq(56!av"));
ck_assert_str_eq(boba974_s21, boba974);
}
END_TEST

START_TEST(bebasik__975) {
char boba975_s21[10000];
char boba975[10000];
ck_assert_int_eq(s21_sprintf(boba975_s21, "%-1.3hdk%+2.10d7%-c%-6hu`%-3s%+8.4hd%+hd%-dchz%-hd`% hi% .3hi% 6.7hd% 1.3hdg!% hi%+.4d% 8.2hd%+.10hi@%-10.10u%-f@ue`ec&x^% 8d(% 7.1hir% 5.2f9k6n/y%+10hi%+.10fl", 22077, -872491, '3', -27805, "b5)/$rosb5)1)!,4", 3575, 4661, 457277, -8032, 11260, -24300, 519, 15708, -26355, 596506, 4152, 30329, -837805, 3148.372080855121, 718694, -30455, -99.10682215461505, -410, 9007.202507418053),
sprintf(boba975, "%-1.3hdk%+2.10d7%-c%-6hu`%-3s%+8.4hd%+hd%-dchz%-hd`% hi% .3hi% 6.7hd% 1.3hdg!% hi%+.4d% 8.2hd%+.10hi@%-10.10u%-f@ue`ec&x^% 8d(% 7.1hir% 5.2f9k6n/y%+10hi%+.10fl", 22077, -872491, '3', -27805, "b5)/$rosb5)1)!,4", 3575, 4661, 457277, -8032, 11260, -24300, 519, 15708, -26355, 596506, 4152, 30329, -837805, 3148.372080855121, 718694, -30455, -99.10682215461505, -410, 9007.202507418053));
ck_assert_str_eq(boba975_s21, boba975);
}
END_TEST

START_TEST(bebasik__976) {
char boba976_s21[10000];
char boba976[10000];
ck_assert_int_eq(s21_sprintf(boba976_s21, "%-7.6hi% 1d5%+.2d%+1.7hdsc% 8hd% 4hix%+8.5hd6% f% .5f%+.6hiu1%+4.4f% .5i%+6hiqh% 7hi", 21832, 649144, 826251, -17891, 23039, 10769, 27648, 6422.432628702572, -7145.991985275402, -7339, -12030.843325126372, -235524, 1470, 30498),
sprintf(boba976, "%-7.6hi% 1d5%+.2d%+1.7hdsc% 8hd% 4hix%+8.5hd6% f% .5f%+.6hiu1%+4.4f% .5i%+6hiqh% 7hi", 21832, 649144, 826251, -17891, 23039, 10769, 27648, 6422.432628702572, -7145.991985275402, -7339, -12030.843325126372, -235524, 1470, 30498));
ck_assert_str_eq(boba976_s21, boba976);
}
END_TEST

START_TEST(bebasik__977) {
char boba977_s21[10000];
char boba977[10000];
ck_assert_int_eq(s21_sprintf(boba977_s21, "%+hi!s%-.1f%+8.1hd4,(x2ba%+6.4fw% 5.9hdz%+6.1hi%+hd% hdqa,kt%-8.3s%-5.9hibi%+d(-9%-5.2hi%+.9hi%-9hd% .7hd%+9.2hi% .6i1y", 9564, 3124.2085882367974, -20281, -89.5570315979294, -3137, 5569, 22367, -16593, "`", -3571, 648708, -30848, 5320, 26788, 13139, -12830, -22204),
sprintf(boba977, "%+hi!s%-.1f%+8.1hd4,(x2ba%+6.4fw% 5.9hdz%+6.1hi%+hd% hdqa,kt%-8.3s%-5.9hibi%+d(-9%-5.2hi%+.9hi%-9hd% .7hd%+9.2hi% .6i1y", 9564, 3124.2085882367974, -20281, -89.5570315979294, -3137, 5569, 22367, -16593, "`", -3571, 648708, -30848, 5320, 26788, 13139, -12830, -22204));
ck_assert_str_eq(boba977_s21, boba977);
}
END_TEST

START_TEST(bebasik__978) {
char boba978_s21[10000];
char boba978[10000];
ck_assert_int_eq(s21_sprintf(boba978_s21, "%+2f%-7hi% .3hi%-6.1hi%-2ib%-.10u", 259.97327150587864, -8375, 16356, -12813, 946704, 587317),
sprintf(boba978, "%+2f%-7hi% .3hi%-6.1hi%-2ib%-.10u", 259.97327150587864, -8375, 16356, -12813, 946704, 587317));
ck_assert_str_eq(boba978_s21, boba978);
}
END_TEST

START_TEST(bebasik__979) {
char boba979_s21[10000];
char boba979[10000];
ck_assert_int_eq(s21_sprintf(boba979_s21, "% 8.10d%+hd% 8.2hd9u0%+7i% 9hi*q%-2.2hi4k%-8hd%-4hu% 4.1f% .5f%+.1hi[%+7.8hib%+6.1hi%-5d1=% fw%+5.5hd%-6hi%+8.1ds%+5hi%-8ukw% .9in`d% hi", 635502, -30869, -7563, -597760, -10053, -21504, 31243, 19687, -16434.57233701411, 5907.1762164930215, 22363, -9982, 26959, 143169, -1763.1762268931616, 28201, 15910, 44307, 3703, 848573, -244389, 8597),
sprintf(boba979, "% 8.10d%+hd% 8.2hd9u0%+7i% 9hi*q%-2.2hi4k%-8hd%-4hu% 4.1f% .5f%+.1hi[%+7.8hib%+6.1hi%-5d1=% fw%+5.5hd%-6hi%+8.1ds%+5hi%-8ukw% .9in`d% hi", 635502, -30869, -7563, -597760, -10053, -21504, 31243, 19687, -16434.57233701411, 5907.1762164930215, 22363, -9982, 26959, 143169, -1763.1762268931616, 28201, 15910, 44307, 3703, 848573, -244389, 8597));
ck_assert_str_eq(boba979_s21, boba979);
}
END_TEST

START_TEST(bebasik__980) {
char boba980_s21[10000];
char boba980[10000];
ck_assert_int_eq(s21_sprintf(boba980_s21, "%-.0u-% 8.0d%+2d%-6.3hd% .4i[9=adu%-hi@%-hi%-3hdue% hd9y;t%-9hi% fg`% .6i", 212750, 896842, -650945, 1200, 905083, 31802, -16163, 6984, 10330, -294, -3009.6997268354385, 37557),
sprintf(boba980, "%-.0u-% 8.0d%+2d%-6.3hd% .4i[9=adu%-hi@%-hi%-3hdue% hd9y;t%-9hi% fg`% .6i", 212750, 896842, -650945, 1200, 905083, 31802, -16163, 6984, 10330, -294, -3009.6997268354385, 37557));
ck_assert_str_eq(boba980_s21, boba980);
}
END_TEST

START_TEST(bebasik__981) {
char boba981_s21[10000];
char boba981[10000];
ck_assert_int_eq(s21_sprintf(boba981_s21, "%+.10hd-n% .9hd%-.8d%+7.3d0%+.10im", 110, -13156, 845110, -124677, 933480),
sprintf(boba981, "%+.10hd-n% .9hd%-.8d%+7.3d0%+.10im", 110, -13156, 845110, -124677, 933480));
ck_assert_str_eq(boba981_s21, boba981);
}
END_TEST

START_TEST(bebasik__982) {
char boba982_s21[10000];
char boba982[10000];
ck_assert_int_eq(s21_sprintf(boba982_s21, "% .1hd7%+ig40wi% .2hi% .10hd%+5.8d/f&&z%-hu%-9.0u", -4264, -422852, 5701, -2104, -895300, -10110, -35080),
sprintf(boba982, "% .1hd7%+ig40wi% .2hi% .10hd%+5.8d/f&&z%-hu%-9.0u", -4264, -422852, 5701, -2104, -895300, -10110, -35080));
ck_assert_str_eq(boba982_s21, boba982);
}
END_TEST

START_TEST(bebasik__983) {
char boba983_s21[10000];
char boba983[10000];
ck_assert_int_eq(s21_sprintf(boba983_s21, "%+8.7hi^%-5.5hi%-4hij6%+.0d%+4hi^y%-hd.", 577, 10790, 19397, -936530, -15321, -28383),
sprintf(boba983, "%+8.7hi^%-5.5hi%-4hij6%+.0d%+4hi^y%-hd.", 577, 10790, 19397, -936530, -15321, -28383));
ck_assert_str_eq(boba983_s21, boba983);
}
END_TEST

START_TEST(bebasik__984) {
char boba984_s21[10000];
char boba984[10000];
ck_assert_int_eq(s21_sprintf(boba984_s21, "%-7.6hu%+5hi% 3.2hd;% 10.2i% 9.10ir%-.9f%-huiy%+.7hdfz%-4.5ub% 1hi-e%-8f%-3.5d%+5hd%+1.5i% .3hi%+8hd%-10d% 10.5i@", 28215, 25383, -5775, -508826, -954390, 6019.3425766818555, -28420, 11856, -311759, 23219, 22164.108965973453, -133358, -16705, 725167, 23560, -11471, 749699, 853478),
sprintf(boba984, "%-7.6hu%+5hi% 3.2hd;% 10.2i% 9.10ir%-.9f%-huiy%+.7hdfz%-4.5ub% 1hi-e%-8f%-3.5d%+5hd%+1.5i% .3hi%+8hd%-10d% 10.5i@", 28215, 25383, -5775, -508826, -954390, 6019.3425766818555, -28420, 11856, -311759, 23219, 22164.108965973453, -133358, -16705, 725167, 23560, -11471, 749699, 853478));
ck_assert_str_eq(boba984_s21, boba984);
}
END_TEST

START_TEST(bebasik__985) {
char boba985_s21[10000];
char boba985[10000];
ck_assert_int_eq(s21_sprintf(boba985_s21, "%-.2i%-4hu8%-2.2hd!u% .7hi2g%+2hd%+5d%+1.0f%-9.8hi%-.0huj%+.9hdu%-.0s&u%+4f%-10hur=9#[pkn2% 2d% 6.8hd7% hi%+.6d%+10.4i%+6.4fs%+4.2i,%-10.7s7% 1hd4", 836930, 14788, -21196, -9126, -20704, -188584, 19396.798537077597, -5950, -24902, -4664, "$i2ddi*l*cr", -1892.623104546115, -31577, 549522, -22704, -27482, -447899, 739430, 2762.554131876551, -988449, "pv*0;7aa^.z=1hncvf#", -23554),
sprintf(boba985, "%-.2i%-4hu8%-2.2hd!u% .7hi2g%+2hd%+5d%+1.0f%-9.8hi%-.0huj%+.9hdu%-.0s&u%+4f%-10hur=9#[pkn2% 2d% 6.8hd7% hi%+.6d%+10.4i%+6.4fs%+4.2i,%-10.7s7% 1hd4", 836930, 14788, -21196, -9126, -20704, -188584, 19396.798537077597, -5950, -24902, -4664, "$i2ddi*l*cr", -1892.623104546115, -31577, 549522, -22704, -27482, -447899, 739430, 2762.554131876551, -988449, "pv*0;7aa^.z=1hncvf#", -23554));
ck_assert_str_eq(boba985_s21, boba985);
}
END_TEST

START_TEST(bebasik__986) {
char boba986_s21[10000];
char boba986[10000];
ck_assert_int_eq(s21_sprintf(boba986_s21, "%+3.2f% fn%+10.9hig% itlxo^&%-hd%-2sk% 9.7hi%-2hd%+fb4% hi%-3f%+4.2i", 4726.725820684111, 6906.077987940732, 5519, -974864, 16556, "hv#,g08;`ck$89xla7*om", -84, 30752, -2229.122717434639, -14417, 2238.6004452353855, 867098),
sprintf(boba986, "%+3.2f% fn%+10.9hig% itlxo^&%-hd%-2sk% 9.7hi%-2hd%+fb4% hi%-3f%+4.2i", 4726.725820684111, 6906.077987940732, 5519, -974864, 16556, "hv#,g08;`ck$89xla7*om", -84, 30752, -2229.122717434639, -14417, 2238.6004452353855, 867098));
ck_assert_str_eq(boba986_s21, boba986);
}
END_TEST

START_TEST(bebasik__987) {
char boba987_s21[10000];
char boba987[10000];
ck_assert_int_eq(s21_sprintf(boba987_s21, "%-10.1him%+f,% .8d% 10.4i%+.9i%+3.1d3t!&% frg%-.3d% d%+.3f/8%-hi% 9.7f`%-1.8i%+hi% 5.2f%-9.8d2%-.2f% 2f!e%-8.0hd`% i", -7299, 14742.028041972704, -699211, 536757, -339361, 25460, 13327.103429971577, -65513, -19249, -2008.5586048014902, 15702, 24097.69812931175, 449718, 4922, 15435.732500930228, 585593, -9481.983385634552, -12369.924988740104, -6550, -19417),
sprintf(boba987, "%-10.1him%+f,% .8d% 10.4i%+.9i%+3.1d3t!&% frg%-.3d% d%+.3f/8%-hi% 9.7f`%-1.8i%+hi% 5.2f%-9.8d2%-.2f% 2f!e%-8.0hd`% i", -7299, 14742.028041972704, -699211, 536757, -339361, 25460, 13327.103429971577, -65513, -19249, -2008.5586048014902, 15702, 24097.69812931175, 449718, 4922, 15435.732500930228, 585593, -9481.983385634552, -12369.924988740104, -6550, -19417));
ck_assert_str_eq(boba987_s21, boba987);
}
END_TEST

START_TEST(bebasik__988) {
char boba988_s21[10000];
char boba988[10000];
ck_assert_int_eq(s21_sprintf(boba988_s21, "% d%+8.2hi%-5.8dv%+.8hdaik4%+.0hd4auo-1%-5s@6%+f@%+hi%-i9[", -667275, 24219, -64008, 13925, 21901, "q;,a6/8h0v!8y0z6[c4$#iwn0", 12754.8085198986, -18758, 461393),
sprintf(boba988, "% d%+8.2hi%-5.8dv%+.8hdaik4%+.0hd4auo-1%-5s@6%+f@%+hi%-i9[", -667275, 24219, -64008, 13925, 21901, "q;,a6/8h0v!8y0z6[c4$#iwn0", 12754.8085198986, -18758, 461393));
ck_assert_str_eq(boba988_s21, boba988);
}
END_TEST

START_TEST(bebasik__989) {
char boba989_s21[10000];
char boba989[10000];
ck_assert_int_eq(s21_sprintf(boba989_s21, "%+hi% 4.0hi% .6hi0%+3i%-4.8hi&h% hd/dl,% 2.2fb% 4hd% .9f`r*%+5.3hd% 2i% 8f", -15114, 4711, -31534, 936826, 10319, -19789, 14772.02441201783, -25765, 2708.7279774465787, -22052, 950449, 2366.3908334329153),
sprintf(boba989, "%+hi% 4.0hi% .6hi0%+3i%-4.8hi&h% hd/dl,% 2.2fb% 4hd% .9f`r*%+5.3hd% 2i% 8f", -15114, 4711, -31534, 936826, 10319, -19789, 14772.02441201783, -25765, 2708.7279774465787, -22052, 950449, 2366.3908334329153));
ck_assert_str_eq(boba989_s21, boba989);
}
END_TEST

START_TEST(bebasik__990) {
char boba990_s21[10000];
char boba990[10000];
ck_assert_int_eq(s21_sprintf(boba990_s21, "% .10hd;% .8iswf%-6.1hd,%+.4dx% .5i47%-10.4hd% hds%-6hi%-7d%+.2hd3b%+i%-10io&i9% hd%-2.3hdj%+hi%+4d%+.10hdcbx%+i%+9.3hi% .0f", 26507, 585525, -6840, 630367, -161970, -13192, -21285, 706, -741680, 577, -316990, 849158, 31923, 11500, -7459, 762065, 20528, 761463, 3095, 9697.372798929018),
sprintf(boba990, "% .10hd;% .8iswf%-6.1hd,%+.4dx% .5i47%-10.4hd% hds%-6hi%-7d%+.2hd3b%+i%-10io&i9% hd%-2.3hdj%+hi%+4d%+.10hdcbx%+i%+9.3hi% .0f", 26507, 585525, -6840, 630367, -161970, -13192, -21285, 706, -741680, 577, -316990, 849158, 31923, 11500, -7459, 762065, 20528, 761463, 3095, 9697.372798929018));
ck_assert_str_eq(boba990_s21, boba990);
}
END_TEST

START_TEST(bebasik__991) {
char boba991_s21[10000];
char boba991[10000];
ck_assert_int_eq(s21_sprintf(boba991_s21, "%+6i%+6f$.s% 4f7% 8hd%-hi@@h% .4hi%-.6u% 5.9hi% iw%-.0fx74%+3d(;", -751857, 21059.90281021118, 14356.06820613827, 17514, -3917, 208, 382966, -2331, -492583, -135.64636633680567, 257295),
sprintf(boba991, "%+6i%+6f$.s% 4f7% 8hd%-hi@@h% .4hi%-.6u% 5.9hi% iw%-.0fx74%+3d(;", -751857, 21059.90281021118, 14356.06820613827, 17514, -3917, 208, 382966, -2331, -492583, -135.64636633680567, 257295));
ck_assert_str_eq(boba991_s21, boba991);
}
END_TEST

START_TEST(bebasik__992) {
char boba992_s21[10000];
char boba992[10000];
ck_assert_int_eq(s21_sprintf(boba992_s21, "% 8.6hd", -23876),
sprintf(boba992, "% 8.6hd", -23876));
ck_assert_str_eq(boba992_s21, boba992);
}
END_TEST

START_TEST(bebasik__993) {
char boba993_s21[10000];
char boba993[10000];
ck_assert_int_eq(s21_sprintf(boba993_s21, "% i;pn%-3sw", -161472, "!r3wc@h36[yy-2tuqgzga=818"),
sprintf(boba993, "% i;pn%-3sw", -161472, "!r3wc@h36[yy-2tuqgzga=818"));
ck_assert_str_eq(boba993_s21, boba993);
}
END_TEST

START_TEST(bebasik__994) {
char boba994_s21[10000];
char boba994[10000];
ck_assert_int_eq(s21_sprintf(boba994_s21, "% 5hd% 3.4i.v%+i%+3.10hd%-3.8hu%+8.9i.&%+10d% 7d%-d%+hi%+5hi", -29276, 91740, -967701, 25319, -16381, 5526, 112016, 583515, 442820, -26367, -121),
sprintf(boba994, "% 5hd% 3.4i.v%+i%+3.10hd%-3.8hu%+8.9i.&%+10d% 7d%-d%+hi%+5hi", -29276, 91740, -967701, 25319, -16381, 5526, 112016, 583515, 442820, -26367, -121));
ck_assert_str_eq(boba994_s21, boba994);
}
END_TEST

START_TEST(bebasik__995) {
char boba995_s21[10000];
char boba995[10000];
ck_assert_int_eq(s21_sprintf(boba995_s21, "%-5.5dd% f5.%-6.2uan% .5hi%+.4hdl%-9caw% f%-hddo%-.1i5% 9.9f6u%-4.1hi.% 3i% 2.2hd", -194177, -8438.423778110231, 297853, -29722, 16193, 'z', 6136.313697884323, 21210, 735159, 1459.0214361876065, -24314, 952180, -19952),
sprintf(boba995, "%-5.5dd% f5.%-6.2uan% .5hi%+.4hdl%-9caw% f%-hddo%-.1i5% 9.9f6u%-4.1hi.% 3i% 2.2hd", -194177, -8438.423778110231, 297853, -29722, 16193, 'z', 6136.313697884323, 21210, 735159, 1459.0214361876065, -24314, 952180, -19952));
ck_assert_str_eq(boba995_s21, boba995);
}
END_TEST

START_TEST(bebasik__996) {
char boba996_s21[10000];
char boba996[10000];
ck_assert_int_eq(s21_sprintf(boba996_s21, "%-hd%+f%-1.2hu%-6d-8%+2hd% 4.5f%-.10hd^%-2.1u9yn%-4d@!%-5c4j%-hi%-5s=k%-9s% .9hi-p*", -11941, -5285.340117286119, 8995, 78597, -7276, -24022.660054829234, -17377, -231718, -808025, '!', 23175, "0qjhk4g/", "t!44,s6$fr)jk9-ia*&p#et", 26566),
sprintf(boba996, "%-hd%+f%-1.2hu%-6d-8%+2hd% 4.5f%-.10hd^%-2.1u9yn%-4d@!%-5c4j%-hi%-5s=k%-9s% .9hi-p*", -11941, -5285.340117286119, 8995, 78597, -7276, -24022.660054829234, -17377, -231718, -808025, '!', 23175, "0qjhk4g/", "t!44,s6$fr)jk9-ia*&p#et", 26566));
ck_assert_str_eq(boba996_s21, boba996);
}
END_TEST

START_TEST(bebasik__997) {
char boba997_s21[10000];
char boba997[10000];
ck_assert_int_eq(s21_sprintf(boba997_s21, "%+9.7hi% 4.7i%-6.8hd/% .5d%-6.0hd$% 10.10d% .8hd0% i/-% 9d%+.5i%-3hd)%-9.0hi% hi% i% hd^0x%+.0hi^% 8i=%-cs% 4hdd0", 11583, 386335, 24071, -250878, -25047, 428200, -25679, 932389, -978292, 607407, 29721, 6731, 29026, 686187, -25577, -713, 805467, 'f', 27250),
sprintf(boba997, "%+9.7hi% 4.7i%-6.8hd/% .5d%-6.0hd$% 10.10d% .8hd0% i/-% 9d%+.5i%-3hd)%-9.0hi% hi% i% hd^0x%+.0hi^% 8i=%-cs% 4hdd0", 11583, 386335, 24071, -250878, -25047, 428200, -25679, 932389, -978292, 607407, 29721, 6731, 29026, 686187, -25577, -713, 805467, 'f', 27250));
ck_assert_str_eq(boba997_s21, boba997);
}
END_TEST

START_TEST(bebasik__998) {
char boba998_s21[10000];
char boba998[10000];
ck_assert_int_eq(s21_sprintf(boba998_s21, "%+8hi@", 9014),
sprintf(boba998, "%+8hi@", 9014));
ck_assert_str_eq(boba998_s21, boba998);
}
END_TEST

START_TEST(bebasik__999) {
char boba999_s21[10000];
char boba999[10000];
ck_assert_int_eq(s21_sprintf(boba999_s21, "%+1.9hi1%+2hi9r#%+3.6hd%+hi% 3.3hic%-5c%-.4s%+hd%+.4fw%-.9hi%-hi%-9s%-7.1hd%+9.4f%-10u/^% .8hd#% 3.6hi9%+3dic%+.1d% d% 9hd9remz% .8hik5% .1f`#8% 9.5d", 523, -31034, -17690, 26959, 10800, '7', "43(,-f-g@&6&jd/oo[y,xmwbl7", -11801, -14570.065309586853, -7250, -31753, "rp8uu#8&x,gaa", -5687, -14.198472410656155, 138834, 31213, 919, -187258, 429529, -820422, -11426, -4214, 738.3926242045032, -760904),
sprintf(boba999, "%+1.9hi1%+2hi9r#%+3.6hd%+hi% 3.3hic%-5c%-.4s%+hd%+.4fw%-.9hi%-hi%-9s%-7.1hd%+9.4f%-10u/^% .8hd#% 3.6hi9%+3dic%+.1d% d% 9hd9remz% .8hik5% .1f`#8% 9.5d", 523, -31034, -17690, 26959, 10800, '7', "43(,-f-g@&6&jd/oo[y,xmwbl7", -11801, -14570.065309586853, -7250, -31753, "rp8uu#8&x,gaa", -5687, -14.198472410656155, 138834, 31213, 919, -187258, 429529, -820422, -11426, -4214, 738.3926242045032, -760904));
ck_assert_str_eq(boba999_s21, boba999);
}
END_TEST

START_TEST(bebasik__1000) {
char boba1000_s21[10000];
char boba1000[10000];
ck_assert_int_eq(s21_sprintf(boba1000_s21, "%+10.4i% .2hi[k% 6.0hd!%+6hd3;ddp%-.3i%-hi9%-3hd%-9.1ie% f%+.5f% f% in75[1%+6hi!%+.8hdii%+.1hd%+1db)2!% .8i%+.8hi%+3fut% d% .7hd%+2.4hdv", -390186, -2410, -25871, 8520, -931, -13354, 23507, -228090, 1678.3288087264568, 6881.335454360994, -3452.9575521596585, 510107, -13165, -8743, 332, -950816, 631505, 21168, 18787.62510661798, -194578, 10748, 31648),
sprintf(boba1000, "%+10.4i% .2hi[k% 6.0hd!%+6hd3;ddp%-.3i%-hi9%-3hd%-9.1ie% f%+.5f% f% in75[1%+6hi!%+.8hdii%+.1hd%+1db)2!% .8i%+.8hi%+3fut% d% .7hd%+2.4hdv", -390186, -2410, -25871, 8520, -931, -13354, 23507, -228090, 1678.3288087264568, 6881.335454360994, -3452.9575521596585, 510107, -13165, -8743, 332, -950816, 631505, 21168, 18787.62510661798, -194578, 10748, 31648));
ck_assert_str_eq(boba1000_s21, boba1000);
}
END_TEST


Suite *suite_sprintf(void) {
    Suite *s = suite_create("suite_sprintf");
    TCase *tc = tcase_create("sprintf_tc");



tcase_add_test(tc, bebasik__1);
tcase_add_test(tc, bebasik__2);
tcase_add_test(tc, bebasik__3);
tcase_add_test(tc, bebasik__4);
tcase_add_test(tc, bebasik__5);
tcase_add_test(tc, bebasik__6);
tcase_add_test(tc, bebasik__7);
tcase_add_test(tc, bebasik__8);
tcase_add_test(tc, bebasik__9);
tcase_add_test(tc, bebasik__10);
tcase_add_test(tc, bebasik__11);
tcase_add_test(tc, bebasik__12);
tcase_add_test(tc, bebasik__13);
tcase_add_test(tc, bebasik__14);
tcase_add_test(tc, bebasik__15);
tcase_add_test(tc, bebasik__16);
tcase_add_test(tc, bebasik__17);
tcase_add_test(tc, bebasik__18);
tcase_add_test(tc, bebasik__19);
tcase_add_test(tc, bebasik__20);
tcase_add_test(tc, bebasik__21);
tcase_add_test(tc, bebasik__22);
tcase_add_test(tc, bebasik__23);
tcase_add_test(tc, bebasik__24);
tcase_add_test(tc, bebasik__25);
tcase_add_test(tc, bebasik__26);
tcase_add_test(tc, bebasik__27);
tcase_add_test(tc, bebasik__28);
tcase_add_test(tc, bebasik__29);
tcase_add_test(tc, bebasik__30);
tcase_add_test(tc, bebasik__31);
tcase_add_test(tc, bebasik__32);
tcase_add_test(tc, bebasik__33);
tcase_add_test(tc, bebasik__34);
tcase_add_test(tc, bebasik__35);
tcase_add_test(tc, bebasik__36);
tcase_add_test(tc, bebasik__37);
tcase_add_test(tc, bebasik__38);
tcase_add_test(tc, bebasik__39);
tcase_add_test(tc, bebasik__40);
tcase_add_test(tc, bebasik__41);
tcase_add_test(tc, bebasik__42);
tcase_add_test(tc, bebasik__43);
tcase_add_test(tc, bebasik__44);
tcase_add_test(tc, bebasik__45);
tcase_add_test(tc, bebasik__46);
tcase_add_test(tc, bebasik__47);
tcase_add_test(tc, bebasik__48);
tcase_add_test(tc, bebasik__49);
tcase_add_test(tc, bebasik__50);
tcase_add_test(tc, bebasik__51);
tcase_add_test(tc, bebasik__52);
tcase_add_test(tc, bebasik__53);
tcase_add_test(tc, bebasik__54);
tcase_add_test(tc, bebasik__55);
tcase_add_test(tc, bebasik__56);
tcase_add_test(tc, bebasik__57);
tcase_add_test(tc, bebasik__58);
tcase_add_test(tc, bebasik__59);
tcase_add_test(tc, bebasik__60);
tcase_add_test(tc, bebasik__61);
tcase_add_test(tc, bebasik__62);
tcase_add_test(tc, bebasik__63);
tcase_add_test(tc, bebasik__64);
tcase_add_test(tc, bebasik__65);
tcase_add_test(tc, bebasik__66);
tcase_add_test(tc, bebasik__67);
tcase_add_test(tc, bebasik__68);
tcase_add_test(tc, bebasik__69);
tcase_add_test(tc, bebasik__70);
tcase_add_test(tc, bebasik__71);
tcase_add_test(tc, bebasik__72);
tcase_add_test(tc, bebasik__73);
tcase_add_test(tc, bebasik__74);
tcase_add_test(tc, bebasik__75);
tcase_add_test(tc, bebasik__76);
tcase_add_test(tc, bebasik__77);
tcase_add_test(tc, bebasik__78);
tcase_add_test(tc, bebasik__79);
tcase_add_test(tc, bebasik__80);
tcase_add_test(tc, bebasik__81);
tcase_add_test(tc, bebasik__82);
tcase_add_test(tc, bebasik__83);
tcase_add_test(tc, bebasik__84);
tcase_add_test(tc, bebasik__85);
tcase_add_test(tc, bebasik__86);
tcase_add_test(tc, bebasik__87);
tcase_add_test(tc, bebasik__88);
tcase_add_test(tc, bebasik__89);
tcase_add_test(tc, bebasik__90);
tcase_add_test(tc, bebasik__91);
tcase_add_test(tc, bebasik__92);
tcase_add_test(tc, bebasik__93);
tcase_add_test(tc, bebasik__94);
tcase_add_test(tc, bebasik__95);
tcase_add_test(tc, bebasik__96);
tcase_add_test(tc, bebasik__97);
tcase_add_test(tc, bebasik__98);
tcase_add_test(tc, bebasik__99);
tcase_add_test(tc, bebasik__100);
tcase_add_test(tc, bebasik__101);
tcase_add_test(tc, bebasik__102);
tcase_add_test(tc, bebasik__103);
tcase_add_test(tc, bebasik__104);
tcase_add_test(tc, bebasik__105);
tcase_add_test(tc, bebasik__106);
tcase_add_test(tc, bebasik__107);
tcase_add_test(tc, bebasik__108);
tcase_add_test(tc, bebasik__109);
tcase_add_test(tc, bebasik__110);
tcase_add_test(tc, bebasik__111);
tcase_add_test(tc, bebasik__112);
tcase_add_test(tc, bebasik__113);
tcase_add_test(tc, bebasik__114);
tcase_add_test(tc, bebasik__115);
tcase_add_test(tc, bebasik__116);
tcase_add_test(tc, bebasik__117);
tcase_add_test(tc, bebasik__118);
tcase_add_test(tc, bebasik__119);
tcase_add_test(tc, bebasik__120);
tcase_add_test(tc, bebasik__121);
tcase_add_test(tc, bebasik__122);
tcase_add_test(tc, bebasik__123);
tcase_add_test(tc, bebasik__124);
tcase_add_test(tc, bebasik__125);
tcase_add_test(tc, bebasik__126);
tcase_add_test(tc, bebasik__127);
tcase_add_test(tc, bebasik__128);
tcase_add_test(tc, bebasik__129);
tcase_add_test(tc, bebasik__130);
tcase_add_test(tc, bebasik__131);
tcase_add_test(tc, bebasik__132);
tcase_add_test(tc, bebasik__133);
tcase_add_test(tc, bebasik__134);
tcase_add_test(tc, bebasik__135);
tcase_add_test(tc, bebasik__136);
tcase_add_test(tc, bebasik__137);
tcase_add_test(tc, bebasik__138);
tcase_add_test(tc, bebasik__139);
tcase_add_test(tc, bebasik__140);
tcase_add_test(tc, bebasik__141);
tcase_add_test(tc, bebasik__142);
tcase_add_test(tc, bebasik__143);
tcase_add_test(tc, bebasik__144);
tcase_add_test(tc, bebasik__145);
tcase_add_test(tc, bebasik__146);
tcase_add_test(tc, bebasik__147);
tcase_add_test(tc, bebasik__148);
tcase_add_test(tc, bebasik__149);
tcase_add_test(tc, bebasik__150);
tcase_add_test(tc, bebasik__151);
tcase_add_test(tc, bebasik__152);
tcase_add_test(tc, bebasik__153);
tcase_add_test(tc, bebasik__154);
tcase_add_test(tc, bebasik__155);
tcase_add_test(tc, bebasik__156);
tcase_add_test(tc, bebasik__157);
tcase_add_test(tc, bebasik__158);
tcase_add_test(tc, bebasik__159);
tcase_add_test(tc, bebasik__160);
tcase_add_test(tc, bebasik__161);
tcase_add_test(tc, bebasik__162);
tcase_add_test(tc, bebasik__163);
tcase_add_test(tc, bebasik__164);
tcase_add_test(tc, bebasik__165);
tcase_add_test(tc, bebasik__166);
tcase_add_test(tc, bebasik__167);
tcase_add_test(tc, bebasik__168);
tcase_add_test(tc, bebasik__169);
tcase_add_test(tc, bebasik__170);
tcase_add_test(tc, bebasik__171);
tcase_add_test(tc, bebasik__172);
tcase_add_test(tc, bebasik__173);
tcase_add_test(tc, bebasik__174);
tcase_add_test(tc, bebasik__175);
tcase_add_test(tc, bebasik__176);
tcase_add_test(tc, bebasik__177);
tcase_add_test(tc, bebasik__178);
tcase_add_test(tc, bebasik__179);
tcase_add_test(tc, bebasik__180);
tcase_add_test(tc, bebasik__181);
tcase_add_test(tc, bebasik__182);
tcase_add_test(tc, bebasik__183);
tcase_add_test(tc, bebasik__184);
tcase_add_test(tc, bebasik__185);
tcase_add_test(tc, bebasik__186);
tcase_add_test(tc, bebasik__187);
tcase_add_test(tc, bebasik__188);
tcase_add_test(tc, bebasik__189);
tcase_add_test(tc, bebasik__190);
tcase_add_test(tc, bebasik__191);
tcase_add_test(tc, bebasik__192);
tcase_add_test(tc, bebasik__193);
tcase_add_test(tc, bebasik__194);
tcase_add_test(tc, bebasik__195);
tcase_add_test(tc, bebasik__196);
tcase_add_test(tc, bebasik__197);
tcase_add_test(tc, bebasik__198);
tcase_add_test(tc, bebasik__199);
tcase_add_test(tc, bebasik__200);
tcase_add_test(tc, bebasik__201);
tcase_add_test(tc, bebasik__202);
tcase_add_test(tc, bebasik__203);
tcase_add_test(tc, bebasik__204);
tcase_add_test(tc, bebasik__205);
tcase_add_test(tc, bebasik__206);
tcase_add_test(tc, bebasik__207);
tcase_add_test(tc, bebasik__208);
tcase_add_test(tc, bebasik__209);
tcase_add_test(tc, bebasik__210);
tcase_add_test(tc, bebasik__211);
tcase_add_test(tc, bebasik__212);
tcase_add_test(tc, bebasik__213);
tcase_add_test(tc, bebasik__214);
tcase_add_test(tc, bebasik__215);
tcase_add_test(tc, bebasik__216);
tcase_add_test(tc, bebasik__217);
tcase_add_test(tc, bebasik__218);
tcase_add_test(tc, bebasik__219);
tcase_add_test(tc, bebasik__220);
tcase_add_test(tc, bebasik__221);
tcase_add_test(tc, bebasik__222);
tcase_add_test(tc, bebasik__223);
tcase_add_test(tc, bebasik__224);
tcase_add_test(tc, bebasik__225);
tcase_add_test(tc, bebasik__226);
tcase_add_test(tc, bebasik__227);
tcase_add_test(tc, bebasik__228);
tcase_add_test(tc, bebasik__229);
tcase_add_test(tc, bebasik__230);
tcase_add_test(tc, bebasik__231);
tcase_add_test(tc, bebasik__232);
tcase_add_test(tc, bebasik__233);
tcase_add_test(tc, bebasik__234);
tcase_add_test(tc, bebasik__235);
tcase_add_test(tc, bebasik__236);
tcase_add_test(tc, bebasik__237);
tcase_add_test(tc, bebasik__238);
tcase_add_test(tc, bebasik__239);
tcase_add_test(tc, bebasik__240);
tcase_add_test(tc, bebasik__241);
tcase_add_test(tc, bebasik__242);
tcase_add_test(tc, bebasik__243);
tcase_add_test(tc, bebasik__244);
tcase_add_test(tc, bebasik__245);
tcase_add_test(tc, bebasik__246);
tcase_add_test(tc, bebasik__247);
tcase_add_test(tc, bebasik__248);
tcase_add_test(tc, bebasik__249);
tcase_add_test(tc, bebasik__250);
tcase_add_test(tc, bebasik__251);
tcase_add_test(tc, bebasik__252);
tcase_add_test(tc, bebasik__253);
tcase_add_test(tc, bebasik__254);
tcase_add_test(tc, bebasik__255);
tcase_add_test(tc, bebasik__256);
tcase_add_test(tc, bebasik__257);
tcase_add_test(tc, bebasik__258);
tcase_add_test(tc, bebasik__259);
tcase_add_test(tc, bebasik__260);
tcase_add_test(tc, bebasik__261);
tcase_add_test(tc, bebasik__262);
tcase_add_test(tc, bebasik__263);
tcase_add_test(tc, bebasik__264);
tcase_add_test(tc, bebasik__265);
tcase_add_test(tc, bebasik__266);
tcase_add_test(tc, bebasik__267);
tcase_add_test(tc, bebasik__268);
tcase_add_test(tc, bebasik__269);
tcase_add_test(tc, bebasik__270);
tcase_add_test(tc, bebasik__271);
tcase_add_test(tc, bebasik__272);
tcase_add_test(tc, bebasik__273);
tcase_add_test(tc, bebasik__274);
tcase_add_test(tc, bebasik__275);
tcase_add_test(tc, bebasik__276);
tcase_add_test(tc, bebasik__277);
tcase_add_test(tc, bebasik__278);
tcase_add_test(tc, bebasik__279);
tcase_add_test(tc, bebasik__280);
tcase_add_test(tc, bebasik__281);
tcase_add_test(tc, bebasik__282);
tcase_add_test(tc, bebasik__283);
tcase_add_test(tc, bebasik__284);
tcase_add_test(tc, bebasik__285);
tcase_add_test(tc, bebasik__286);
tcase_add_test(tc, bebasik__287);
tcase_add_test(tc, bebasik__288);
tcase_add_test(tc, bebasik__289);
tcase_add_test(tc, bebasik__290);
tcase_add_test(tc, bebasik__291);
tcase_add_test(tc, bebasik__292);
tcase_add_test(tc, bebasik__293);
tcase_add_test(tc, bebasik__294);
tcase_add_test(tc, bebasik__295);
tcase_add_test(tc, bebasik__296);
tcase_add_test(tc, bebasik__297);
tcase_add_test(tc, bebasik__298);
tcase_add_test(tc, bebasik__299);
tcase_add_test(tc, bebasik__300);
tcase_add_test(tc, bebasik__301);
tcase_add_test(tc, bebasik__302);
tcase_add_test(tc, bebasik__303);
tcase_add_test(tc, bebasik__304);
tcase_add_test(tc, bebasik__305);
tcase_add_test(tc, bebasik__306);
tcase_add_test(tc, bebasik__307);
tcase_add_test(tc, bebasik__308);
tcase_add_test(tc, bebasik__309);
tcase_add_test(tc, bebasik__310);
tcase_add_test(tc, bebasik__311);
tcase_add_test(tc, bebasik__312);
tcase_add_test(tc, bebasik__313);
tcase_add_test(tc, bebasik__314);
tcase_add_test(tc, bebasik__315);
tcase_add_test(tc, bebasik__316);
tcase_add_test(tc, bebasik__317);
tcase_add_test(tc, bebasik__318);
tcase_add_test(tc, bebasik__319);
tcase_add_test(tc, bebasik__320);
tcase_add_test(tc, bebasik__321);
tcase_add_test(tc, bebasik__322);
tcase_add_test(tc, bebasik__323);
tcase_add_test(tc, bebasik__324);
tcase_add_test(tc, bebasik__325);
tcase_add_test(tc, bebasik__326);
tcase_add_test(tc, bebasik__327);
tcase_add_test(tc, bebasik__328);
tcase_add_test(tc, bebasik__329);
tcase_add_test(tc, bebasik__330);
tcase_add_test(tc, bebasik__331);
tcase_add_test(tc, bebasik__332);
tcase_add_test(tc, bebasik__333);
tcase_add_test(tc, bebasik__334);
tcase_add_test(tc, bebasik__335);
tcase_add_test(tc, bebasik__336);
tcase_add_test(tc, bebasik__337);
tcase_add_test(tc, bebasik__338);
tcase_add_test(tc, bebasik__339);
tcase_add_test(tc, bebasik__340);
tcase_add_test(tc, bebasik__341);
tcase_add_test(tc, bebasik__342);
tcase_add_test(tc, bebasik__343);
tcase_add_test(tc, bebasik__344);
tcase_add_test(tc, bebasik__345);
tcase_add_test(tc, bebasik__346);
tcase_add_test(tc, bebasik__347);
tcase_add_test(tc, bebasik__348);
tcase_add_test(tc, bebasik__349);
tcase_add_test(tc, bebasik__350);
tcase_add_test(tc, bebasik__351);
tcase_add_test(tc, bebasik__352);
tcase_add_test(tc, bebasik__353);
tcase_add_test(tc, bebasik__354);
tcase_add_test(tc, bebasik__355);
tcase_add_test(tc, bebasik__356);
tcase_add_test(tc, bebasik__357);
tcase_add_test(tc, bebasik__358);
tcase_add_test(tc, bebasik__359);
tcase_add_test(tc, bebasik__360);
tcase_add_test(tc, bebasik__361);
tcase_add_test(tc, bebasik__362);
tcase_add_test(tc, bebasik__363);
tcase_add_test(tc, bebasik__364);
tcase_add_test(tc, bebasik__365);
tcase_add_test(tc, bebasik__366);
tcase_add_test(tc, bebasik__367);
tcase_add_test(tc, bebasik__368);
tcase_add_test(tc, bebasik__369);
tcase_add_test(tc, bebasik__370);
tcase_add_test(tc, bebasik__371);
tcase_add_test(tc, bebasik__372);
tcase_add_test(tc, bebasik__373);
tcase_add_test(tc, bebasik__374);
tcase_add_test(tc, bebasik__375);
tcase_add_test(tc, bebasik__376);
tcase_add_test(tc, bebasik__377);
tcase_add_test(tc, bebasik__378);
tcase_add_test(tc, bebasik__379);
tcase_add_test(tc, bebasik__380);
tcase_add_test(tc, bebasik__381);
tcase_add_test(tc, bebasik__382);
tcase_add_test(tc, bebasik__383);
tcase_add_test(tc, bebasik__384);
tcase_add_test(tc, bebasik__385);
tcase_add_test(tc, bebasik__386);
tcase_add_test(tc, bebasik__387);
tcase_add_test(tc, bebasik__388);
tcase_add_test(tc, bebasik__389);
tcase_add_test(tc, bebasik__390);
tcase_add_test(tc, bebasik__391);
tcase_add_test(tc, bebasik__392);
tcase_add_test(tc, bebasik__393);
tcase_add_test(tc, bebasik__394);
tcase_add_test(tc, bebasik__395);
tcase_add_test(tc, bebasik__396);
tcase_add_test(tc, bebasik__397);
tcase_add_test(tc, bebasik__398);
tcase_add_test(tc, bebasik__399);
tcase_add_test(tc, bebasik__400);
tcase_add_test(tc, bebasik__401);
tcase_add_test(tc, bebasik__402);
tcase_add_test(tc, bebasik__403);
tcase_add_test(tc, bebasik__404);
tcase_add_test(tc, bebasik__405);
tcase_add_test(tc, bebasik__406);
tcase_add_test(tc, bebasik__407);
tcase_add_test(tc, bebasik__408);
tcase_add_test(tc, bebasik__409);
tcase_add_test(tc, bebasik__410);
tcase_add_test(tc, bebasik__411);
tcase_add_test(tc, bebasik__412);
tcase_add_test(tc, bebasik__413);
tcase_add_test(tc, bebasik__414);
tcase_add_test(tc, bebasik__415);
tcase_add_test(tc, bebasik__416);
tcase_add_test(tc, bebasik__417);
tcase_add_test(tc, bebasik__418);
tcase_add_test(tc, bebasik__419);
tcase_add_test(tc, bebasik__420);
tcase_add_test(tc, bebasik__421);
tcase_add_test(tc, bebasik__422);
tcase_add_test(tc, bebasik__423);
tcase_add_test(tc, bebasik__424);
tcase_add_test(tc, bebasik__425);
tcase_add_test(tc, bebasik__426);
tcase_add_test(tc, bebasik__427);
tcase_add_test(tc, bebasik__428);
tcase_add_test(tc, bebasik__429);
tcase_add_test(tc, bebasik__430);
tcase_add_test(tc, bebasik__431);
tcase_add_test(tc, bebasik__432);
tcase_add_test(tc, bebasik__433);
tcase_add_test(tc, bebasik__434);
tcase_add_test(tc, bebasik__435);
tcase_add_test(tc, bebasik__436);
tcase_add_test(tc, bebasik__437);
tcase_add_test(tc, bebasik__438);
tcase_add_test(tc, bebasik__439);
tcase_add_test(tc, bebasik__440);
tcase_add_test(tc, bebasik__441);
tcase_add_test(tc, bebasik__442);
tcase_add_test(tc, bebasik__443);
tcase_add_test(tc, bebasik__444);
tcase_add_test(tc, bebasik__445);
tcase_add_test(tc, bebasik__446);
tcase_add_test(tc, bebasik__447);
tcase_add_test(tc, bebasik__448);
tcase_add_test(tc, bebasik__449);
tcase_add_test(tc, bebasik__450);
tcase_add_test(tc, bebasik__451);
tcase_add_test(tc, bebasik__452);
tcase_add_test(tc, bebasik__453);
tcase_add_test(tc, bebasik__454);
tcase_add_test(tc, bebasik__455);
tcase_add_test(tc, bebasik__456);
tcase_add_test(tc, bebasik__457);
tcase_add_test(tc, bebasik__458);
tcase_add_test(tc, bebasik__459);
tcase_add_test(tc, bebasik__460);
tcase_add_test(tc, bebasik__461);
tcase_add_test(tc, bebasik__462);
tcase_add_test(tc, bebasik__463);
tcase_add_test(tc, bebasik__464);
tcase_add_test(tc, bebasik__465);
tcase_add_test(tc, bebasik__466);
tcase_add_test(tc, bebasik__467);
tcase_add_test(tc, bebasik__468);
tcase_add_test(tc, bebasik__469);
tcase_add_test(tc, bebasik__470);
tcase_add_test(tc, bebasik__471);
tcase_add_test(tc, bebasik__472);
tcase_add_test(tc, bebasik__473);
tcase_add_test(tc, bebasik__474);
tcase_add_test(tc, bebasik__475);
tcase_add_test(tc, bebasik__476);
tcase_add_test(tc, bebasik__477);
tcase_add_test(tc, bebasik__478);
tcase_add_test(tc, bebasik__479);
tcase_add_test(tc, bebasik__480);
tcase_add_test(tc, bebasik__481);
tcase_add_test(tc, bebasik__482);
tcase_add_test(tc, bebasik__483);
tcase_add_test(tc, bebasik__484);
tcase_add_test(tc, bebasik__485);
tcase_add_test(tc, bebasik__486);
tcase_add_test(tc, bebasik__487);
tcase_add_test(tc, bebasik__488);
tcase_add_test(tc, bebasik__489);
tcase_add_test(tc, bebasik__490);
tcase_add_test(tc, bebasik__491);
tcase_add_test(tc, bebasik__492);
tcase_add_test(tc, bebasik__493);
tcase_add_test(tc, bebasik__494);
tcase_add_test(tc, bebasik__495);
tcase_add_test(tc, bebasik__496);
tcase_add_test(tc, bebasik__497);
tcase_add_test(tc, bebasik__498);
tcase_add_test(tc, bebasik__499);
tcase_add_test(tc, bebasik__500);
tcase_add_test(tc, bebasik__501);
tcase_add_test(tc, bebasik__502);
tcase_add_test(tc, bebasik__503);
tcase_add_test(tc, bebasik__504);
tcase_add_test(tc, bebasik__505);
tcase_add_test(tc, bebasik__506);
tcase_add_test(tc, bebasik__507);
tcase_add_test(tc, bebasik__508);
tcase_add_test(tc, bebasik__509);
tcase_add_test(tc, bebasik__510);
tcase_add_test(tc, bebasik__511);
tcase_add_test(tc, bebasik__512);
tcase_add_test(tc, bebasik__513);
tcase_add_test(tc, bebasik__514);
tcase_add_test(tc, bebasik__515);
tcase_add_test(tc, bebasik__516);
tcase_add_test(tc, bebasik__517);
tcase_add_test(tc, bebasik__518);
tcase_add_test(tc, bebasik__519);
tcase_add_test(tc, bebasik__520);
tcase_add_test(tc, bebasik__521);
tcase_add_test(tc, bebasik__522);
tcase_add_test(tc, bebasik__523);
tcase_add_test(tc, bebasik__524);
tcase_add_test(tc, bebasik__525);
tcase_add_test(tc, bebasik__526);
tcase_add_test(tc, bebasik__527);
tcase_add_test(tc, bebasik__528);
tcase_add_test(tc, bebasik__529);
tcase_add_test(tc, bebasik__530);
tcase_add_test(tc, bebasik__531);
tcase_add_test(tc, bebasik__532);
tcase_add_test(tc, bebasik__533);
tcase_add_test(tc, bebasik__534);
tcase_add_test(tc, bebasik__535);
tcase_add_test(tc, bebasik__536);
tcase_add_test(tc, bebasik__537);
tcase_add_test(tc, bebasik__538);
tcase_add_test(tc, bebasik__539);
tcase_add_test(tc, bebasik__540);
tcase_add_test(tc, bebasik__541);
tcase_add_test(tc, bebasik__542);
tcase_add_test(tc, bebasik__543);
tcase_add_test(tc, bebasik__544);
tcase_add_test(tc, bebasik__545);
tcase_add_test(tc, bebasik__546);
tcase_add_test(tc, bebasik__547);
tcase_add_test(tc, bebasik__548);
tcase_add_test(tc, bebasik__549);
tcase_add_test(tc, bebasik__550);
tcase_add_test(tc, bebasik__551);
tcase_add_test(tc, bebasik__552);
tcase_add_test(tc, bebasik__553);
tcase_add_test(tc, bebasik__554);
tcase_add_test(tc, bebasik__555);
tcase_add_test(tc, bebasik__556);
tcase_add_test(tc, bebasik__557);
tcase_add_test(tc, bebasik__558);
tcase_add_test(tc, bebasik__559);
tcase_add_test(tc, bebasik__560);
tcase_add_test(tc, bebasik__561);
tcase_add_test(tc, bebasik__562);
tcase_add_test(tc, bebasik__563);
tcase_add_test(tc, bebasik__564);
tcase_add_test(tc, bebasik__565);
tcase_add_test(tc, bebasik__566);
tcase_add_test(tc, bebasik__567);
tcase_add_test(tc, bebasik__568);
tcase_add_test(tc, bebasik__569);
tcase_add_test(tc, bebasik__570);
tcase_add_test(tc, bebasik__571);
tcase_add_test(tc, bebasik__572);
tcase_add_test(tc, bebasik__573);
tcase_add_test(tc, bebasik__574);
tcase_add_test(tc, bebasik__575);
tcase_add_test(tc, bebasik__576);
tcase_add_test(tc, bebasik__577);
tcase_add_test(tc, bebasik__578);
tcase_add_test(tc, bebasik__579);
tcase_add_test(tc, bebasik__580);
tcase_add_test(tc, bebasik__581);
tcase_add_test(tc, bebasik__582);
tcase_add_test(tc, bebasik__583);
tcase_add_test(tc, bebasik__584);
tcase_add_test(tc, bebasik__585);
tcase_add_test(tc, bebasik__586);
tcase_add_test(tc, bebasik__587);
tcase_add_test(tc, bebasik__588);
tcase_add_test(tc, bebasik__589);
tcase_add_test(tc, bebasik__590);
tcase_add_test(tc, bebasik__591);
tcase_add_test(tc, bebasik__592);
tcase_add_test(tc, bebasik__593);
tcase_add_test(tc, bebasik__594);
tcase_add_test(tc, bebasik__595);
tcase_add_test(tc, bebasik__596);
tcase_add_test(tc, bebasik__597);
tcase_add_test(tc, bebasik__598);
tcase_add_test(tc, bebasik__599);
tcase_add_test(tc, bebasik__600);
tcase_add_test(tc, bebasik__601);
tcase_add_test(tc, bebasik__602);
tcase_add_test(tc, bebasik__603);
tcase_add_test(tc, bebasik__604);
tcase_add_test(tc, bebasik__605);
tcase_add_test(tc, bebasik__606);
tcase_add_test(tc, bebasik__607);
tcase_add_test(tc, bebasik__608);
tcase_add_test(tc, bebasik__609);
tcase_add_test(tc, bebasik__610);
tcase_add_test(tc, bebasik__611);
tcase_add_test(tc, bebasik__612);
tcase_add_test(tc, bebasik__613);
tcase_add_test(tc, bebasik__614);
tcase_add_test(tc, bebasik__615);
tcase_add_test(tc, bebasik__616);
tcase_add_test(tc, bebasik__617);
tcase_add_test(tc, bebasik__618);
tcase_add_test(tc, bebasik__619);
tcase_add_test(tc, bebasik__620);
tcase_add_test(tc, bebasik__621);
tcase_add_test(tc, bebasik__622);
tcase_add_test(tc, bebasik__623);
tcase_add_test(tc, bebasik__624);
tcase_add_test(tc, bebasik__625);
tcase_add_test(tc, bebasik__626);
tcase_add_test(tc, bebasik__627);
tcase_add_test(tc, bebasik__628);
tcase_add_test(tc, bebasik__629);
tcase_add_test(tc, bebasik__630);
tcase_add_test(tc, bebasik__631);
tcase_add_test(tc, bebasik__632);
tcase_add_test(tc, bebasik__633);
tcase_add_test(tc, bebasik__634);
tcase_add_test(tc, bebasik__635);
tcase_add_test(tc, bebasik__636);
tcase_add_test(tc, bebasik__637);
tcase_add_test(tc, bebasik__638);
tcase_add_test(tc, bebasik__639);
tcase_add_test(tc, bebasik__640);
tcase_add_test(tc, bebasik__641);
tcase_add_test(tc, bebasik__642);
tcase_add_test(tc, bebasik__643);
tcase_add_test(tc, bebasik__644);
tcase_add_test(tc, bebasik__645);
tcase_add_test(tc, bebasik__646);
tcase_add_test(tc, bebasik__647);
tcase_add_test(tc, bebasik__648);
tcase_add_test(tc, bebasik__649);
tcase_add_test(tc, bebasik__650);
tcase_add_test(tc, bebasik__651);
tcase_add_test(tc, bebasik__652);
tcase_add_test(tc, bebasik__653);
tcase_add_test(tc, bebasik__654);
tcase_add_test(tc, bebasik__655);
tcase_add_test(tc, bebasik__656);
tcase_add_test(tc, bebasik__657);
tcase_add_test(tc, bebasik__658);
tcase_add_test(tc, bebasik__659);
tcase_add_test(tc, bebasik__660);
tcase_add_test(tc, bebasik__661);
tcase_add_test(tc, bebasik__662);
tcase_add_test(tc, bebasik__663);
tcase_add_test(tc, bebasik__664);
tcase_add_test(tc, bebasik__665);
tcase_add_test(tc, bebasik__666);
tcase_add_test(tc, bebasik__667);
tcase_add_test(tc, bebasik__668);
tcase_add_test(tc, bebasik__669);
tcase_add_test(tc, bebasik__670);
tcase_add_test(tc, bebasik__671);
tcase_add_test(tc, bebasik__672);
tcase_add_test(tc, bebasik__673);
tcase_add_test(tc, bebasik__674);
tcase_add_test(tc, bebasik__675);
tcase_add_test(tc, bebasik__676);
tcase_add_test(tc, bebasik__677);
tcase_add_test(tc, bebasik__678);
tcase_add_test(tc, bebasik__679);
tcase_add_test(tc, bebasik__680);
tcase_add_test(tc, bebasik__681);
tcase_add_test(tc, bebasik__682);
tcase_add_test(tc, bebasik__683);
tcase_add_test(tc, bebasik__684);
tcase_add_test(tc, bebasik__685);
tcase_add_test(tc, bebasik__686);
tcase_add_test(tc, bebasik__687);
tcase_add_test(tc, bebasik__688);
tcase_add_test(tc, bebasik__689);
tcase_add_test(tc, bebasik__690);
tcase_add_test(tc, bebasik__691);
tcase_add_test(tc, bebasik__692);
tcase_add_test(tc, bebasik__693);
tcase_add_test(tc, bebasik__694);
tcase_add_test(tc, bebasik__695);
tcase_add_test(tc, bebasik__696);
tcase_add_test(tc, bebasik__697);
tcase_add_test(tc, bebasik__698);
tcase_add_test(tc, bebasik__699);
tcase_add_test(tc, bebasik__700);
tcase_add_test(tc, bebasik__701);
tcase_add_test(tc, bebasik__702);
tcase_add_test(tc, bebasik__703);
tcase_add_test(tc, bebasik__704);
tcase_add_test(tc, bebasik__705);
tcase_add_test(tc, bebasik__706);
tcase_add_test(tc, bebasik__707);
tcase_add_test(tc, bebasik__708);
tcase_add_test(tc, bebasik__709);
tcase_add_test(tc, bebasik__710);
tcase_add_test(tc, bebasik__711);
tcase_add_test(tc, bebasik__712);
tcase_add_test(tc, bebasik__713);
tcase_add_test(tc, bebasik__714);
tcase_add_test(tc, bebasik__715);
tcase_add_test(tc, bebasik__716);
tcase_add_test(tc, bebasik__717);
tcase_add_test(tc, bebasik__718);
tcase_add_test(tc, bebasik__719);
tcase_add_test(tc, bebasik__720);
tcase_add_test(tc, bebasik__721);
tcase_add_test(tc, bebasik__722);
tcase_add_test(tc, bebasik__723);
tcase_add_test(tc, bebasik__724);
tcase_add_test(tc, bebasik__725);
tcase_add_test(tc, bebasik__726);
tcase_add_test(tc, bebasik__727);
tcase_add_test(tc, bebasik__728);
tcase_add_test(tc, bebasik__729);
tcase_add_test(tc, bebasik__730);
tcase_add_test(tc, bebasik__731);
tcase_add_test(tc, bebasik__732);
tcase_add_test(tc, bebasik__733);
tcase_add_test(tc, bebasik__734);
tcase_add_test(tc, bebasik__735);
tcase_add_test(tc, bebasik__736);
tcase_add_test(tc, bebasik__737);
tcase_add_test(tc, bebasik__738);
tcase_add_test(tc, bebasik__739);
tcase_add_test(tc, bebasik__740);
tcase_add_test(tc, bebasik__741);
tcase_add_test(tc, bebasik__742);
tcase_add_test(tc, bebasik__743);
tcase_add_test(tc, bebasik__744);
tcase_add_test(tc, bebasik__745);
tcase_add_test(tc, bebasik__746);
tcase_add_test(tc, bebasik__747);
tcase_add_test(tc, bebasik__748);
tcase_add_test(tc, bebasik__749);
tcase_add_test(tc, bebasik__750);
tcase_add_test(tc, bebasik__751);
tcase_add_test(tc, bebasik__752);
tcase_add_test(tc, bebasik__753);
tcase_add_test(tc, bebasik__754);
tcase_add_test(tc, bebasik__755);
tcase_add_test(tc, bebasik__756);
tcase_add_test(tc, bebasik__757);
tcase_add_test(tc, bebasik__758);
tcase_add_test(tc, bebasik__759);
tcase_add_test(tc, bebasik__760);
tcase_add_test(tc, bebasik__761);
tcase_add_test(tc, bebasik__762);
tcase_add_test(tc, bebasik__763);
tcase_add_test(tc, bebasik__764);
tcase_add_test(tc, bebasik__765);
tcase_add_test(tc, bebasik__766);
tcase_add_test(tc, bebasik__767);
tcase_add_test(tc, bebasik__768);
tcase_add_test(tc, bebasik__769);
tcase_add_test(tc, bebasik__770);
tcase_add_test(tc, bebasik__771);
tcase_add_test(tc, bebasik__772);
tcase_add_test(tc, bebasik__773);
tcase_add_test(tc, bebasik__774);
tcase_add_test(tc, bebasik__775);
tcase_add_test(tc, bebasik__776);
tcase_add_test(tc, bebasik__777);
tcase_add_test(tc, bebasik__778);
tcase_add_test(tc, bebasik__779);
tcase_add_test(tc, bebasik__780);
tcase_add_test(tc, bebasik__781);
tcase_add_test(tc, bebasik__782);
tcase_add_test(tc, bebasik__783);
tcase_add_test(tc, bebasik__784);
tcase_add_test(tc, bebasik__785);
tcase_add_test(tc, bebasik__786);
tcase_add_test(tc, bebasik__787);
tcase_add_test(tc, bebasik__788);
tcase_add_test(tc, bebasik__789);
tcase_add_test(tc, bebasik__790);
tcase_add_test(tc, bebasik__791);
tcase_add_test(tc, bebasik__792);
tcase_add_test(tc, bebasik__793);
tcase_add_test(tc, bebasik__794);
tcase_add_test(tc, bebasik__795);
tcase_add_test(tc, bebasik__796);
tcase_add_test(tc, bebasik__797);
tcase_add_test(tc, bebasik__798);
tcase_add_test(tc, bebasik__799);
tcase_add_test(tc, bebasik__800);
tcase_add_test(tc, bebasik__801);
tcase_add_test(tc, bebasik__802);
tcase_add_test(tc, bebasik__803);
tcase_add_test(tc, bebasik__804);
tcase_add_test(tc, bebasik__805);
tcase_add_test(tc, bebasik__806);
tcase_add_test(tc, bebasik__807);
tcase_add_test(tc, bebasik__808);
tcase_add_test(tc, bebasik__809);
tcase_add_test(tc, bebasik__810);
tcase_add_test(tc, bebasik__811);
tcase_add_test(tc, bebasik__812);
tcase_add_test(tc, bebasik__813);
tcase_add_test(tc, bebasik__814);
tcase_add_test(tc, bebasik__815);
tcase_add_test(tc, bebasik__816);
tcase_add_test(tc, bebasik__817);
tcase_add_test(tc, bebasik__818);
tcase_add_test(tc, bebasik__819);
tcase_add_test(tc, bebasik__820);
tcase_add_test(tc, bebasik__821);
tcase_add_test(tc, bebasik__822);
tcase_add_test(tc, bebasik__823);
tcase_add_test(tc, bebasik__824);
tcase_add_test(tc, bebasik__825);
tcase_add_test(tc, bebasik__826);
tcase_add_test(tc, bebasik__827);
tcase_add_test(tc, bebasik__828);
tcase_add_test(tc, bebasik__829);
tcase_add_test(tc, bebasik__830);
tcase_add_test(tc, bebasik__831);
tcase_add_test(tc, bebasik__832);
tcase_add_test(tc, bebasik__833);
tcase_add_test(tc, bebasik__834);
tcase_add_test(tc, bebasik__835);
tcase_add_test(tc, bebasik__836);
tcase_add_test(tc, bebasik__837);
tcase_add_test(tc, bebasik__838);
tcase_add_test(tc, bebasik__839);
tcase_add_test(tc, bebasik__840);
tcase_add_test(tc, bebasik__841);
tcase_add_test(tc, bebasik__842);
tcase_add_test(tc, bebasik__843);
tcase_add_test(tc, bebasik__844);
tcase_add_test(tc, bebasik__845);
tcase_add_test(tc, bebasik__846);
tcase_add_test(tc, bebasik__847);
tcase_add_test(tc, bebasik__848);
tcase_add_test(tc, bebasik__849);
tcase_add_test(tc, bebasik__850);
tcase_add_test(tc, bebasik__851);
tcase_add_test(tc, bebasik__852);
tcase_add_test(tc, bebasik__853);
tcase_add_test(tc, bebasik__854);
tcase_add_test(tc, bebasik__855);
tcase_add_test(tc, bebasik__856);
tcase_add_test(tc, bebasik__857);
tcase_add_test(tc, bebasik__858);
tcase_add_test(tc, bebasik__859);
tcase_add_test(tc, bebasik__860);
tcase_add_test(tc, bebasik__861);
tcase_add_test(tc, bebasik__862);
tcase_add_test(tc, bebasik__863);
tcase_add_test(tc, bebasik__864);
tcase_add_test(tc, bebasik__865);
tcase_add_test(tc, bebasik__866);
tcase_add_test(tc, bebasik__867);
tcase_add_test(tc, bebasik__868);
tcase_add_test(tc, bebasik__869);
tcase_add_test(tc, bebasik__870);
tcase_add_test(tc, bebasik__871);
tcase_add_test(tc, bebasik__872);
tcase_add_test(tc, bebasik__873);
tcase_add_test(tc, bebasik__874);
tcase_add_test(tc, bebasik__875);
tcase_add_test(tc, bebasik__876);
tcase_add_test(tc, bebasik__877);
tcase_add_test(tc, bebasik__878);
tcase_add_test(tc, bebasik__879);
tcase_add_test(tc, bebasik__880);
tcase_add_test(tc, bebasik__881);
tcase_add_test(tc, bebasik__882);
tcase_add_test(tc, bebasik__883);
tcase_add_test(tc, bebasik__884);
tcase_add_test(tc, bebasik__885);
tcase_add_test(tc, bebasik__886);
tcase_add_test(tc, bebasik__887);
tcase_add_test(tc, bebasik__888);
tcase_add_test(tc, bebasik__889);
tcase_add_test(tc, bebasik__890);
tcase_add_test(tc, bebasik__891);
tcase_add_test(tc, bebasik__892);
tcase_add_test(tc, bebasik__893);
tcase_add_test(tc, bebasik__894);
tcase_add_test(tc, bebasik__895);
tcase_add_test(tc, bebasik__896);
tcase_add_test(tc, bebasik__897);
tcase_add_test(tc, bebasik__898);
tcase_add_test(tc, bebasik__899);
tcase_add_test(tc, bebasik__900);
tcase_add_test(tc, bebasik__901);
tcase_add_test(tc, bebasik__902);
tcase_add_test(tc, bebasik__903);
tcase_add_test(tc, bebasik__904);
tcase_add_test(tc, bebasik__905);
tcase_add_test(tc, bebasik__906);
tcase_add_test(tc, bebasik__907);
tcase_add_test(tc, bebasik__908);
tcase_add_test(tc, bebasik__909);
tcase_add_test(tc, bebasik__910);
tcase_add_test(tc, bebasik__911);
tcase_add_test(tc, bebasik__912);
tcase_add_test(tc, bebasik__913);
tcase_add_test(tc, bebasik__914);
tcase_add_test(tc, bebasik__915);
tcase_add_test(tc, bebasik__916);
tcase_add_test(tc, bebasik__917);
tcase_add_test(tc, bebasik__918);
tcase_add_test(tc, bebasik__919);
tcase_add_test(tc, bebasik__920);
tcase_add_test(tc, bebasik__921);
tcase_add_test(tc, bebasik__922);
tcase_add_test(tc, bebasik__923);
tcase_add_test(tc, bebasik__924);
tcase_add_test(tc, bebasik__925);
tcase_add_test(tc, bebasik__926);
tcase_add_test(tc, bebasik__927);
tcase_add_test(tc, bebasik__928);
tcase_add_test(tc, bebasik__929);
tcase_add_test(tc, bebasik__930);
tcase_add_test(tc, bebasik__931);
tcase_add_test(tc, bebasik__932);
tcase_add_test(tc, bebasik__933);
tcase_add_test(tc, bebasik__934);
tcase_add_test(tc, bebasik__935);
tcase_add_test(tc, bebasik__936);
tcase_add_test(tc, bebasik__937);
tcase_add_test(tc, bebasik__938);
tcase_add_test(tc, bebasik__939);
tcase_add_test(tc, bebasik__940);
tcase_add_test(tc, bebasik__941);
tcase_add_test(tc, bebasik__942);
tcase_add_test(tc, bebasik__943);
tcase_add_test(tc, bebasik__944);
tcase_add_test(tc, bebasik__945);
tcase_add_test(tc, bebasik__946);
tcase_add_test(tc, bebasik__947);
tcase_add_test(tc, bebasik__948);
tcase_add_test(tc, bebasik__949);
tcase_add_test(tc, bebasik__950);
tcase_add_test(tc, bebasik__951);
tcase_add_test(tc, bebasik__952);
tcase_add_test(tc, bebasik__953);
tcase_add_test(tc, bebasik__954);
tcase_add_test(tc, bebasik__955);
tcase_add_test(tc, bebasik__956);
tcase_add_test(tc, bebasik__957);
tcase_add_test(tc, bebasik__958);
tcase_add_test(tc, bebasik__959);
tcase_add_test(tc, bebasik__960);
tcase_add_test(tc, bebasik__961);
tcase_add_test(tc, bebasik__962);
tcase_add_test(tc, bebasik__963);
tcase_add_test(tc, bebasik__964);
tcase_add_test(tc, bebasik__965);
tcase_add_test(tc, bebasik__966);
tcase_add_test(tc, bebasik__967);
tcase_add_test(tc, bebasik__968);
tcase_add_test(tc, bebasik__969);
tcase_add_test(tc, bebasik__970);
tcase_add_test(tc, bebasik__971);
tcase_add_test(tc, bebasik__972);
tcase_add_test(tc, bebasik__973);
tcase_add_test(tc, bebasik__974);
tcase_add_test(tc, bebasik__975);
tcase_add_test(tc, bebasik__976);
tcase_add_test(tc, bebasik__977);
tcase_add_test(tc, bebasik__978);
tcase_add_test(tc, bebasik__979);
tcase_add_test(tc, bebasik__980);
tcase_add_test(tc, bebasik__981);
tcase_add_test(tc, bebasik__982);
tcase_add_test(tc, bebasik__983);
tcase_add_test(tc, bebasik__984);
tcase_add_test(tc, bebasik__985);
tcase_add_test(tc, bebasik__986);
tcase_add_test(tc, bebasik__987);
tcase_add_test(tc, bebasik__988);
tcase_add_test(tc, bebasik__989);
tcase_add_test(tc, bebasik__990);
tcase_add_test(tc, bebasik__991);
tcase_add_test(tc, bebasik__992);
tcase_add_test(tc, bebasik__993);
tcase_add_test(tc, bebasik__994);
tcase_add_test(tc, bebasik__995);
tcase_add_test(tc, bebasik__996);
tcase_add_test(tc, bebasik__997);
tcase_add_test(tc, bebasik__998);
tcase_add_test(tc, bebasik__999);
tcase_add_test(tc, bebasik__1000);



    tcase_add_test(tc, simple_int);
    tcase_add_test(tc, precise_int);
    tcase_add_test(tc, width_int);
    tcase_add_test(tc, minus_width_int);
    tcase_add_test(tc, plus_width_int);
    // tcase_add_test(tc, padding_int);
    // tcase_add_test(tc, star_width_int);
    // tcase_add_test(tc, star_precision_int);
    // tcase_add_test(tc, many_flags_many_ints);
    tcase_add_test(tc, flags_long_int);
    //tcase_add_test(tc, flags_short_int);
    //tcase_add_test(tc, flags_another_long_int);
    tcase_add_test(tc, zero_precision_zero_int);
    tcase_add_test(tc, space_flag_int);
    tcase_add_test(tc, unsigned_val);
    tcase_add_test(tc, unsigned_val_width);
    tcase_add_test(tc, unsigned_val_flags);
    tcase_add_test(tc, unsigned_val_precision);
    tcase_add_test(tc, unsigned_val_many_flags);
    tcase_add_test(tc, unsigned_val_short);
    tcase_add_test(tc, unsigned_val_long);
    tcase_add_test(tc, unsigned_val_many);
    // tcase_add_test(tc, octal);
    // tcase_add_test(tc, octal_width);
    // tcase_add_test(tc, octal_flags);
    // tcase_add_test(tc, octal_precision);
    // tcase_add_test(tc, octal_many_flags);
    // tcase_add_test(tc, octal_short);
    // tcase_add_test(tc, octal_long);
    // tcase_add_test(tc, octal_many);
    // tcase_add_test(tc, octal_zero);
    // tcase_add_test(tc, octal_hash);
    tcase_add_test(tc, unsigned_zero);
    // tcase_add_test(tc, hex_width);
    // tcase_add_test(tc, hex_flags);
    // tcase_add_test(tc, hex_precision);
    // tcase_add_test(tc, hex_many);
    // tcase_add_test(tc, hex_many_flags);
    // tcase_add_test(tc, hex_zero);
    // tcase_add_test(tc, hex_huge);
    // tcase_add_test(tc, hex_short);
    // tcase_add_test(tc, hex_long);
    // tcase_add_test(tc, hex_one_longer_width);
    // tcase_add_test(tc, hex_two_longer_width);
    tcase_add_test(tc, one_char);
    tcase_add_test(tc, one_precision);
    tcase_add_test(tc, one_flags);
    tcase_add_test(tc, one_width);
    tcase_add_test(tc, one_many);
    tcase_add_test(tc, one_many_flags);
    tcase_add_test(tc, string2);
    tcase_add_test(tc, string_precision);
    tcase_add_test(tc, string_width);
    tcase_add_test(tc, string_flags);
    tcase_add_test(tc, string_long);
    tcase_add_test(tc, string_many);
    // tcase_add_test(tc, ptr);
    // tcase_add_test(tc, ptr_width);
    // tcase_add_test(tc, ptr_precision);
    // tcase_add_test(tc, null_ptr);
    // tcase_add_test(tc, n_specifier);
    tcase_add_test(tc, string_width_huge);
    // tcase_add_test(tc, float_precision);
    // tcase_add_test(tc, float_width);
    // tcase_add_test(tc, float_precision_zero);
    // tcase_add_test(tc, float_precision_empty);
    // tcase_add_test(tc, float_precision_huge);
    // tcase_add_test(tc, float_precision_huge_negative);
    // tcase_add_test(tc, float_huge);
    tcase_add_test(tc, float_flags);
    //tcase_add_test(tc, float_many);
    // tcase_add_test(tc, e_precision);
    // tcase_add_test(tc, e_precision_zero);
    // tcase_add_test(tc, e_precision_empty);
    // tcase_add_test(tc, e_precision_huge);
    // tcase_add_test(tc, e_precision_huge_negative);
    // tcase_add_test(tc, e_huge);
    // tcase_add_test(tc, e_many);
    // tcase_add_test(tc, e_width);
    // tcase_add_test(tc, e_flags);
    // tcase_add_test(tc, E_int);
    tcase_add_test(tc, all_empty1);
    tcase_add_test(tc, empty_format_and_parameters);
    tcase_add_test(tc, test_one_char);
    tcase_add_test(tc, test_many_char);
    tcase_add_test(tc, test_one_string);
    tcase_add_test(tc, test_many_string);
    tcase_add_test(tc, test_one_dec);
    tcase_add_test(tc, test_many_dec);
    tcase_add_test(tc, test_one_int);
    tcase_add_test(tc, test_many_int);
    tcase_add_test(tc, test_one_float);
    tcase_add_test(tc, test_many_float);
    tcase_add_test(tc, test_one_unsigned_dec);
    tcase_add_test(tc, test_many_unsigned_dec);
    tcase_add_test(tc, test_one_char_with_alignment_left);
    tcase_add_test(tc, test_one_char_with_alignment_right);
    tcase_add_test(tc, test_many_char_with_alignment);
    // tcase_add_test(tc, test_one_hex_lower);
    // tcase_add_test(tc, test_one_hex_upper);
    // tcase_add_test(tc, test_many_hex_lower);
    // tcase_add_test(tc, test_many_hex_upper);
    // tcase_add_test(tc, test_one_hex_lower_with_alignment_left);
    // tcase_add_test(tc, test_one_hex_lower_with_alignment_right);
    // tcase_add_test(tc, test_one_hex_upper_with_alignment_left);
    // tcase_add_test(tc, test_one_hex_upper_with_alignment_right);
    // tcase_add_test(tc, test_many_hex_lower_with_alignment);
    // tcase_add_test(tc, test_many_hex_upper_with_alignment);
    // tcase_add_test(tc, test_one_hex_with_hashtag);
    // tcase_add_test(tc, test_one_hex_upper_with_hashtag);
    // tcase_add_test(tc, test_many_hex_lower_with_hashtag_and_alignm);
    // tcase_add_test(tc, test_many_hex_upper_with_hashtag_and_alignm);
    // tcase_add_test(tc, test_one_hex_lower_with_width_star);
    // tcase_add_test(tc, test_one_hex_upper_with_width_star);
    // tcase_add_test(tc,
    //                test_many_hex_lower_with_width_star_and_align_and_hashtag);
    // tcase_add_test(tc, test_many_hex_upper_with_width_star);
    // tcase_add_test(tc, test_one_hex_lower_with_precision);
    // tcase_add_test(tc, test_one_hex_upper_with_precision);
    // tcase_add_test(tc, test_many_hex_lower_with_precision_and_other);
    // tcase_add_test(tc, test_many_hex_upper_with_precision_and_other);
    // tcase_add_test(tc, test_one_hex_lower_with_length);
    // tcase_add_test(tc, test_one_hex_upper_with_length);
    tcase_add_test(tc, test_sprintf1);
    tcase_add_test(tc, test_sprintf2);
    tcase_add_test(tc, test_sprintf3);
    tcase_add_test(tc, test_sprintf4);
    tcase_add_test(tc, test_sprintf6);
    tcase_add_test(tc, test_sprintf7);
    tcase_add_test(tc, test_sprintf8);
    tcase_add_test(tc, test_sprintf9);
    tcase_add_test(tc, test_sprintf10);
    tcase_add_test(tc, test_sprintf11);
    //tcase_add_test(tc, test_sprintf12);
    tcase_add_test(tc, test_sprintf14);
    tcase_add_test(tc, test_sprintf15);
    tcase_add_test(tc, test_sprintf16);
    tcase_add_test(tc, test_sprintf17);
    tcase_add_test(tc, test_sprintf18);
    tcase_add_test(tc, test_sprintf19);
    tcase_add_test(tc, test_sprintf20);
    tcase_add_test(tc, test_sprintf24);
    tcase_add_test(tc, test_sprintf25);
    // tcase_add_test(tc, test_sprintf28);
    tcase_add_test(tc, test_sprintf29);
    tcase_add_test(tc, test_sprintf30);
    // tcase_add_test(tc, test_sprintf31);
    // tcase_add_test(tc, test_sprintf32);
    // tcase_add_test(tc, test_sprintf33);
    // tcase_add_test(tc, test_sprintf35);
    // tcase_add_test(tc, test_sprintf36);
    // tcase_add_test(tc, test_sprintf37);
    // tcase_add_test(tc, test_sprintf38);
    // tcase_add_test(tc, test_sprintf39);
    // tcase_add_test(tc, test_sprintf40);
    //tcase_add_test(tc, test_sprintf41);
    // tcase_add_test(tc, test_sprintf42);
    // tcase_add_test(tc, test_sprintf43);
    // tcase_add_test(tc, test_sprintf44);
    // tcase_add_test(tc, g_trailing_zero);
    // tcase_add_test(tc, g_large);
    // tcase_add_test(tc, g_small);
    // tcase_add_test(tc, g_precision);
    // tcase_add_test(tc, g_precision_zero);
    // tcase_add_test(tc, g_precision_missing);
    // tcase_add_test(tc, g_many_zeroes_in_front);
    // tcase_add_test(tc, g_one_zero);
    // tcase_add_test(tc, g_mantiss);
    // tcase_add_test(tc, g_mantiss_flags);
    // tcase_add_test(tc, g_short_no_mantiss);
    // tcase_add_test(tc, LG);
    // tcase_add_test(tc, g_many);
    // tcase_add_test(tc, g_zero);
    // tcase_add_test(tc, wide_char);
    // tcase_add_test(tc, width_char);
    // tcase_add_test(tc, minus_wide_char);
    // tcase_add_test(tc, wide_string);
    // tcase_add_test(tc, wide_string1);
    // tcase_add_test(tc, wide_string2);
    // tcase_add_test(tc, wide_string3);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(Hello_aboba) {
    char src[] = " aboba!!!";
    char res[5 + 10] = "Hello";
    char expected[5 + 10] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(zero_first) {
    char src[] = " aboba!!!";
    char res[0 + 10] = "";
    char expected[0 + 10] = "";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(zero_last) {
    char src[] = "";
    char res[] = "Hello";
    char expected[] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(any_letters_with_register) {
    char src[] = "asdfj  asdf aisdfjaiushdfASD SAD asDSad ASDAsdwqqeAS";
    char res[5 + 53] = "Hello";
    char expected[5 + 53] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(any_letters_with_register_and_num) {
    char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS";
    char res[5 + 59] = "Hello";
    char expected[5 + 59] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(any_letters_with_register_and_num_and_sim) {
    char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";
    char res[5 + 65] = "Hello";
    char expected[5 + 65] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

Suite *suite_strcat(void) {
    Suite *s = suite_create("suite_strcat");
    TCase *tc = tcase_create("strcat_tc");

    tcase_add_test(tc, Hello_aboba);
    tcase_add_test(tc, zero_first);
    tcase_add_test(tc, zero_last);
    tcase_add_test(tc, any_letters_with_register);
    tcase_add_test(tc, any_letters_with_register_and_num);
    tcase_add_test(tc, any_letters_with_register_and_num_and_sim);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(abobasnutsa_find_a) {
    char src[] = "abobasnutsa";
    char find = 'a';

    ck_assert_pstr_eq(s21_strchr(src, find),
                     strchr(src, find));
} END_TEST

START_TEST(abobasnutAsa_find_A) {
    char src[] = "abobasnutAsa";
    char find = 'A';

    ck_assert_pstr_eq(s21_strchr(src, find),
                     strchr(src, find));
} END_TEST

START_TEST(abobasnutA1sa_find_1) {
    char src[] = "abobasnutA1sa";
    char find = '1';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(abobasnutAsa_find_Z) {
    char src[] = "abobasnutAsa";
    char find = 'Z';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(abobasnutAsa_find_3) {
    char src[] = "abobasnutAsa";
    char find = '3';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(empty_src2) {
    char src[] = "";
    char find = '3';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

Suite *suite_strchr(void) {
    Suite *s = suite_create("suite_strchr");
    TCase *tc = tcase_create("strchr_tc");

    tcase_add_test(tc, abobasnutsa_find_a);
    tcase_add_test(tc, abobasnutAsa_find_A);
    tcase_add_test(tc, abobasnutA1sa_find_1);
    tcase_add_test(tc, abobasnutAsa_find_Z);
    tcase_add_test(tc, abobasnutAsa_find_3);
    tcase_add_test(tc, empty_src2);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(Heloboba_Heloboba) {
    char a[] = "Heloboba";
    char b[] = "Heloboba";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(HEloboba_Heloboba) {
    char a[] = "HEloboba";
    char b[] = "Heloboba";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(Hel0boba_Helob0ba) {
    char a[] = "Hel0boba";
    char b[] = "Helob0ba";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(Heloboba_) {
    char a[] = "Heloboba";
    char b[] = "";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(_Heloboba) {
    char a[] = "";
    char b[] = "Heloboba";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(Heloboba) {
    char a[] = "L(8)L";
    char b[] = "L(8)L";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(empty2) {
    char a[] = "";
    char b[] = "";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(only_num) {
    char a[] = "1234567890";
    char b[] = "1234567890";

    int got = s21_strcmp(a, b);
    int expected = strcmp(a, b);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

Suite *suite_strcmp(void) {
    Suite *s = suite_create("suite_strcmp");
    TCase *tc = tcase_create("strcmp_tc");

    tcase_add_test(tc, Heloboba_Heloboba);
    tcase_add_test(tc, HEloboba_Heloboba);
    tcase_add_test(tc, Hel0boba_Helob0ba);
    tcase_add_test(tc, Heloboba_);
    tcase_add_test(tc, _Heloboba);
    tcase_add_test(tc, Heloboba);
    tcase_add_test(tc, empty2);
    tcase_add_test(tc, only_num);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(aboba_floppa) {
    char src[] = " floppa!!!";
    char res[5 + 15] = "aboba ";
    char expected[5 + 15] = "aboba ";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(_floppa1) {
    char src[] = "Floppa!!!";
    char res[5 + 15] = "";
    char expected[5 + 15] = "";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(aboba_) {
    char src[] = "";
    char res[5 + 15] = "abobas";
    char expected[5 + 15] = "abobas";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(empty3) {
    char src[] = "";
    char res[5 + 15] = "";
    char expected[5 + 15] = "";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(empty_num) {
    char src[] = "1";
    char res[5 + 15] = "";
    char expected[5 + 15] = "";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(hello) {
    char src[] = " my dear friend\"";
    char res[5 + 15] = "Hello";
    char expected[5 + 15] = "Hello";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(over_string) {
    char src[] = "ab\0ba";
    char res[10 + 9] = "Gre\0t";
    char expected[10 + 9] = "Gre\0t";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(hard_test) {
    char src[] = "ad[sofijpoiajsdf pj98981h23 p9h floppa!!!";
    char res[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
    char expected[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";

    s21_strcpy(res, src);
    strcpy(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

Suite *suite_strcpy(void) {
    Suite *s = suite_create("suite_strcpy");
    TCase *tc = tcase_create("strcpy_tc");

    tcase_add_test(tc, aboba_floppa);
    tcase_add_test(tc, _floppa1);
    tcase_add_test(tc, aboba_);
    tcase_add_test(tc, empty3);
    tcase_add_test(tc, empty_num);
    tcase_add_test(tc, hard_test);
    tcase_add_test(tc, hello);
    tcase_add_test(tc, over_string);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty4) {
    char src[] = "";
    char res[] = "";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(gora_1) {
    char src[] = "gora";
    char res[] = "";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(_gora1) {
    char src[] = "";
    char res[] = "gora";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(any_register2) {
    char src[] = "gora";
    char res[] = "gOra";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_num1) {
    char src[] = "123";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(long_num_num1) {
    char src[] = "12345";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_long_num1) {
    char src[] = "123";
    char res[] = "12345";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(any_num1) {
    char src[] = "1234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_with_letter1) {
    char src[] = "1A2A3A4A5A";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(num_with_letter21) {
    char src[] = "a1aaa23aaa41235";
    char res[] = "123";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(basic_test2) {
    char src[] = "absD";
    char res[] = "aD";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(any_sim1) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(upper_letter1) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(lower_letter1) {
    char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

START_TEST(not_uniq_sim1) {
    char src[] = "33333333333333333333333333333333333333333333333333333333333333333333333333333333333333";
    char res[] = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111113";

    ck_assert_int_eq(s21_strcspn(res, src),
                     strcspn(res, src));
} END_TEST

Suite *suite_strcspn(void) {
    Suite *s = suite_create("suite_strcspn");
    TCase *tc = tcase_create("strcspn_tc");

    tcase_add_test(tc, empty4);
    tcase_add_test(tc, gora_1);
    tcase_add_test(tc, _gora1);
    tcase_add_test(tc, any_register2);
    tcase_add_test(tc, num_num1);
    tcase_add_test(tc, long_num_num1);
    tcase_add_test(tc, num_long_num1);
    tcase_add_test(tc, any_num1);
    tcase_add_test(tc, num_with_letter1);
    tcase_add_test(tc, num_with_letter21);
    tcase_add_test(tc, basic_test2);
    tcase_add_test(tc, any_sim1);
    tcase_add_test(tc, upper_letter1);
    tcase_add_test(tc, lower_letter1);
    tcase_add_test(tc, not_uniq_sim1);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(all_std_errors) {
    for (int i = -1000; i < 150; i++) {
        char *got = s21_strerror(i);
        char *expected = strerror(i);
        ck_assert_str_eq(got, expected);
    }
}
END_TEST

START_TEST(negative_err_code) {
    const char *got = s21_strerror(-1);
    char *expected = strerror(-1);
    ck_assert_str_eq(got, expected);
}
END_TEST

Suite *suite_strerror(void) {
    Suite *s;
    TCase *tc;
    s = suite_create("suite_strerror");
    tc = tcase_create("strerror_tc");
    tcase_add_test(tc, all_std_errors);
    tcase_add_test(tc, negative_err_code);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty9) {
    char src[] = "";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(abosal) {
    char src[] = "abosal";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(num) {
    char src[] = "987623456124678";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(string4) {
    char src[] = "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(abosal_no_dal) {
    char src[] = "abosal\0no_dal";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(dai_mne_pen) {
    char src[] = "dai_mne_pen(321321)...123...123";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(Floppy_disk) {
    char src[] = "Floppy_disk";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(Russky_kot_Shlepa) {
    char src[] = "Russky_kot_Shlepa";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(kot_Vasily) {
    char src[] = "kot Vasily";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(floppa) {
    char src[] = "floppa";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST


Suite *suite_strlen(void) {
    Suite *s = suite_create("suite_strlen");
    TCase *tc = tcase_create("strlen_tc");

    tcase_add_test(tc, empty9);
    tcase_add_test(tc, abosal);
    tcase_add_test(tc, num);
    tcase_add_test(tc, string4);
    tcase_add_test(tc, abosal_no_dal);
    tcase_add_test(tc, dai_mne_pen);
    tcase_add_test(tc, Floppy_disk);
    tcase_add_test(tc, floppa);
    tcase_add_test(tc, kot_Vasily);
    tcase_add_test(tc, Russky_kot_Shlepa);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(all_empty2) {
    char src[] = "";
    char res[] = "";
    char expected[] = "";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(zero_byte5) {
    char src[] = "abosal";
    char res[10] = "";
    char expected[10] = "";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(empty_src4) {
    char src[] = "";
    char res[10] = "cd";
    char expected[10] = "cd";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST


START_TEST(cd_abosa) {
    char src[] = "abosal";
    char res[10] = "cd";
    char expected[10] = "cd";
    s21_size_t n_byte = 5;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(string6) {
    char src[] = "abosal";
    char res[25] = "koleka";
    char expected[25] = "koleka";
    s21_size_t n_byte = 6;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 5;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA2) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA3) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 1;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA4) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 10;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(zero_char) {
    char src[] = "\0";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 1;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST


Suite *suite_strncat(void) {
    Suite *s = suite_create("suite_strncat");
    TCase *tc = tcase_create("strncat_tc");

    tcase_add_test(tc, all_empty2);
    tcase_add_test(tc, zero_byte5);
    tcase_add_test(tc, empty_src4);
    tcase_add_test(tc, cd_abosa);
    tcase_add_test(tc, string6);
    tcase_add_test(tc, BIGFLOPPA);
    tcase_add_test(tc, BIGFLOPPA2);
    tcase_add_test(tc, BIGFLOPPA3);
    tcase_add_test(tc, BIGFLOPPA4);
    tcase_add_test(tc, zero_char);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty7) {
    char str1[] = "";
    char str2[] = "";
    s21_size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_) {
    char str1[] = "floppa";
    char str2[] = "";
    s21_size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(_floppa) {
    char str1[] = "";
    char str2[] = "floppa";
    s21_size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa) {
    char str1[] = "floppa";
    char str2[] = "floppa";
    s21_size_t n_byte = 6;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa_zero_byte) {
    char str1[] = "floppabazbazkotya";
    char str2[] = "floppabaz";
    s21_size_t n_byte = 10;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa_one_byte) {
    char str1[] = "floppa";
    char str2[] = "floppa";
    s21_size_t n_byte = 1;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

Suite *suite_strncmp(void) {
    Suite *s = suite_create("suite_strncmp");
    TCase *tc = tcase_create("strncmp_tc");

    tcase_add_test(tc, empty7);
    tcase_add_test(tc, floppa_);
    tcase_add_test(tc, _floppa);
    tcase_add_test(tc, floppa_floppa);
    tcase_add_test(tc, floppa_floppa_zero_byte);
    tcase_add_test(tc, floppa_floppa_one_byte);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty8) {
    char src[] = "";
    char res[] = "";
    char exp[] = "";
    s21_size_t n_byte = 0;

    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);

    ck_assert_str_eq(res, exp);
} END_TEST

START_TEST(zero_byte) {
    char src[] = "123";
    char res[] = "123";
    char exp[] = "123";
    s21_size_t n_byte = 0;

    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);

    ck_assert_str_eq(res, exp);
} END_TEST

START_TEST(empty_src) {
    char src[] = "";
    char res[] = "123";
    char exp[] = "123";
    s21_size_t n_byte = 0;

    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);

    ck_assert_str_eq(res, exp);
} END_TEST

START_TEST(one_byte) {
    char src[] = "123";
    char res[5] = "123";
    char exp[5] = "123";
    s21_size_t n_byte = 1;

    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);

    ck_assert_str_eq(res, exp);
} END_TEST

START_TEST(two_byte) {
    char src[] = "123";
    char res[7] = "123";
    char exp[7] = "123";
    s21_size_t n_byte = 2;

    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);

    ck_assert_str_eq(res, exp);
} END_TEST

START_TEST(string) {
    char src[] = "Str1ng";
    char res[7 + 7] = "Str1ng";
    char exp[7 + 7] = "Str1ng";
    s21_size_t n_byte = 7;

    s21_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);

    ck_assert_str_eq(res, exp);
} END_TEST

Suite *suite_strncpy(void) {
    Suite *s = suite_create("suite_strncpy");
    TCase *tc = tcase_create("strncpy_tc");

    tcase_add_test(tc, empty8);
    tcase_add_test(tc, zero_byte);
    tcase_add_test(tc, empty_src);
    tcase_add_test(tc, one_byte);
    tcase_add_test(tc, two_byte);
    tcase_add_test(tc, string);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty6) {
    char str1[] = "";
    char str2[] = "";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(floppy_2) {
    char str1[] = "floppy";
    char str2[] = "";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(_floppy2) {
    char str1[] = "";
    char str2[] = "floppy";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(poki_doki_o2) {
    char str1[] = "poki doki";
    char str2[] = "o";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(poki_doki_i2) {
    char str1[] = "poki doki";
    char str2[] = "i";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(poki_doki_p2) {
    char str1[] = "poki doki";
    char str2[] = "p";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(find_big_P1) {
    char str1[] = "ppppppppppppP";
    char str2[] = "P";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(find_zero1) {
    char str1[] = "ppppppppppppP";
    char str2[] = "\0";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST


Suite *suite_strpbrk(void) {
    Suite *s = suite_create("suite_strpbrk");
    TCase *tc = tcase_create("strpbrk_tc");

    tcase_add_test(tc, empty6);
    tcase_add_test(tc, floppy_2);
    tcase_add_test(tc, _floppy2);
    tcase_add_test(tc, poki_doki_o2);
    tcase_add_test(tc, poki_doki_i2);
    tcase_add_test(tc, poki_doki_p2);
    tcase_add_test(tc, find_big_P1);
    tcase_add_test(tc, find_zero1);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty5) {
    char str1[] = "";
    char str2 = '\0';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST

START_TEST(floppy_) {
    char str1[] = "floppy";
    char str2 = '\0';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST

START_TEST(_floppy) {
    char str1[] = "";
    char str2 = 'f';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST

START_TEST(poki_doki_o) {
    char str1[] = "poki doki";
    char str2 = 'o';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST

START_TEST(poki_doki_i) {
    char str1[] = "poki doki";
    char str2 = 'i';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST

START_TEST(poki_doki_p) {
    char str1[] = "poki p dokip";
    char str2 = 'p';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST

START_TEST(find_big_P) {
    char str1[] = "ppPpppppppppP";
    char str2 = 'P';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST

START_TEST(find_zero) {
    char str1[] = "123456789";
    char str2 = '0';

    ck_assert_pstr_eq(s21_strrchr(str1, str2),
                      strrchr(str1, str2));
} END_TEST


Suite *suite_strrchr(void) {
    Suite *s = suite_create("suite_strrchr");
    TCase *tc = tcase_create("strrchr_tc");

    tcase_add_test(tc, empty5);
    tcase_add_test(tc, floppy_);
    tcase_add_test(tc, _floppy);
    tcase_add_test(tc, poki_doki_o);
    tcase_add_test(tc, poki_doki_i);
    tcase_add_test(tc, poki_doki_p);
    tcase_add_test(tc, find_big_P);
    tcase_add_test(tc, find_zero);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty) {
    char src[] = "";
    char res[] = "";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(gora_) {
    char src[] = "gora";
    char res[] = "";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(_gora) {
    char src[] = "";
    char res[] = "gora";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_register) {
    char src[] = "gora";
    char res[] = "gOra";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_num) {
    char src[] = "123";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(long_num_num) {
    char src[] = "12345";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_long_num) {
    char src[] = "123";
    char res[] = "12345";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_num) {
    char src[] = "1234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_with_letter) {
    char src[] = "1A2A3A4A5A";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_with_letter2) {
    char src[] = "a1aaa23aaa41235";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(basic_test) {
    char src[] = "absD";
    char res[] = "aD";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_sim) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(upper_letter) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(lower_letter) {
    char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(not_uniq_sim) {
    char src[] = "33333333333333333333333333333333333333333333333333333333333333333333333333333333333333";
    char res[] = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111113";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

Suite *suite_strspn(void) {
    Suite *s = suite_create("suite_strspn");
    TCase *tc = tcase_create("strspn_tc");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, gora_);
    tcase_add_test(tc, _gora);
    tcase_add_test(tc, any_register);
    tcase_add_test(tc, num_num);
    tcase_add_test(tc, long_num_num);
    tcase_add_test(tc, num_long_num);
    tcase_add_test(tc, any_num);
    tcase_add_test(tc, num_with_letter);
    tcase_add_test(tc, num_with_letter2);
    tcase_add_test(tc, basic_test);
    tcase_add_test(tc, any_sim);
    tcase_add_test(tc, upper_letter);
    tcase_add_test(tc, lower_letter);
    tcase_add_test(tc, not_uniq_sim);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(empty_string_haystack_and_needle) {
    char haystack[] = "";
    char needle[] = "";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
            strstr(haystack, needle));
} END_TEST

START_TEST(empty_string_haystack) {
    char haystack[] = "";
    char needle[] = "jho1faQsdkjnSa3aefwf8hiuJafeHioj";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(empty_string_needle) {
    char haystack[] = "safQhilufas7MaSef2345wknwefnkjHawe2fhilu";
    char needle[] = "";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(toxic_test) {
    char haystack[] = "You are toxic!";
    char needle[] = "toxic";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(not_word_in_haystack) {
    char haystack[] = "There is no right word in this test!";
    char needle[] = "NOT";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(words_with_any_register) {
    char haystack[] = "AbOBosNyTSa";
    char needle[] = "aBoboSNYTsa";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(repeated_words) {
    char haystack[] = "AD AD AD";
    char needle[] = "AD";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(word_at_end) {
    char haystack[] = "22 321 123";
    char needle[] = "123";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(one_simbol_in_needle_and_haystack) {
    char haystack[] = "1";
    char needle[] = "1";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(one_simbol_in_needle) {
    char haystack[] = "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
    char needle[] = " ";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

START_TEST(one_simbol_in_haystack) {
    char haystack[] = "-";
    char needle[] = "1234567890qwertyuiopasdfghjk-";

    ck_assert_pstr_eq(s21_strstr(haystack, needle),
                      strstr(haystack, needle));
} END_TEST

Suite *suite_strstr(void) {
    Suite *s = suite_create("suite_strstr");
    TCase *tc = tcase_create("strstr_tc");

    tcase_add_test(tc, empty_string_haystack_and_needle);
    tcase_add_test(tc, empty_string_haystack);
    tcase_add_test(tc, empty_string_needle);
    tcase_add_test(tc, toxic_test);
    tcase_add_test(tc, not_word_in_haystack);
    tcase_add_test(tc, words_with_any_register);
    tcase_add_test(tc, repeated_words);
    tcase_add_test(tc, word_at_end);
    tcase_add_test(tc, one_simbol_in_needle_and_haystack);
    tcase_add_test(tc, one_simbol_in_needle);
    tcase_add_test(tc, one_simbol_in_haystack);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(correct_token_string) {
    char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
    char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);


    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);


    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(hard_token_string) {
    char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
    char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(unary_delimiters) {
    char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
    char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(no_delims) {
    char str1[] = "AbobaHasNoDelims";
    char str2[] = "AbobaHasNoDelims";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);


        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(only_delims) {
    char str1[] = "++++++++";
    char str2[] = "++++++++";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_ptr_null(got);
    ck_assert_ptr_null(expected);
} END_TEST


START_TEST(too_many_uses_non_segfault) {
    char str1[] = "Aboba_Floppa_Roba";
    char str2[] = "Aboba_Floppa_Roba";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    int i = 5;
    while (i) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);
        i--;

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(even_n_of_delims) {
    char str1[] = "Roba++++Kepa++A++++B__V";
    char str2[] = "Roba++++Kepa++A++++B__V";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(odd_n_of_delims) {
    char str1[] = "Aboba__+Floppa_  Roba";
    char str2[] = "Aboba__+Floppa_  Roba";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(mixed_n_of_delims) {
    char str1[] = "Aboba__Floppa_+++Roba_Kepa";
    char str2[] = "Aboba__Floppa_+++Roba_Kepa";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(hard_mixed) {
    char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
    char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got || expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(mixed_hard_incorrect) {
    char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
    char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got || expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(very_hard_mixed) {
    char str1[] = "!       A!B!C!D!E!!F!!G";
    char str2[] = "!       A!B!C!D!E!!F!!G";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    //ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got || expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        if (got || expected) {
            ck_assert_str_eq(got, expected);
           // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST



Suite *suite_strtok(void) {
    Suite *s = suite_create("suite_strtok");
    TCase *tc = tcase_create("strtok_tc");

    tcase_add_test(tc, correct_token_string);
    tcase_add_test(tc, hard_token_string);
    tcase_add_test(tc, only_delims);
    tcase_add_test(tc, even_n_of_delims);
    tcase_add_test(tc, odd_n_of_delims);
    tcase_add_test(tc, mixed_n_of_delims);
    tcase_add_test(tc, too_many_uses_non_segfault);
    tcase_add_test(tc, hard_mixed);
    tcase_add_test(tc, mixed_hard_incorrect);
    tcase_add_test(tc, very_hard_mixed);
    tcase_add_test(tc, unary_delimiters);
    tcase_add_test(tc, no_delims);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(to_lower_test1) {
    char str[] = "ShLePa V TaZ1Ke?";
    char expected[] = "shlepa v taz1ke?";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

START_TEST(to_lower_test2) {
    char str[] = "123456789Q";
    char expected[] = "123456789q";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(to_lower_test3) {
    char str[] = "Space created";
    char expected[] = "space created";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(to_lower_test4) {
    char str[] = "";
    char expected[] = "";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(to_lower_test5) {
    char str[] = "";
    char expected[] = "";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


Suite *suite_to_lower(void) {
    Suite *s = suite_create("suite_to_lower");
    TCase *tc = tcase_create("to_lower_tc");

    tcase_add_test(tc, to_lower_test1);
    tcase_add_test(tc, to_lower_test2);
    tcase_add_test(tc, to_lower_test3);
    tcase_add_test(tc, to_lower_test4);
    tcase_add_test(tc, to_lower_test5);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(to_upper_test1) {
    char str[] = "good job";
    char expected[] = "GOOD JOB";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

START_TEST(to_upper_test2) {
    char str[] = "empty";
    char expected[] = "EMPTY";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

START_TEST(to_upper_test3) {
    char str[] = "1+1*1";
    char expected[] = "1+1*1";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(to_upper_test4) {
    char str[] = " ";
    char expected[] = " ";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(to_upper_test5) {
    char str[] = "";
    char expected[] = "";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

Suite *suite_to_upper(void) {
    Suite *s = suite_create("suite_to_upper");
    TCase *tc = tcase_create("to_upper_tc");

    tcase_add_test(tc, to_upper_test1);
    tcase_add_test(tc, to_upper_test2);
    tcase_add_test(tc, to_upper_test3);
    tcase_add_test(tc, to_upper_test4);
    tcase_add_test(tc, to_upper_test5);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(all_empty) {
    char str[] = "";
    char trim_ch[] = "";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(str_empty) {
    char str[] = "";
    char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_empty) {
    char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char trim_ch[] = "";
    char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
    char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test1) {
    char str[] = "+!!++Abo+ba++00";
    char trim_ch[] = "+!0-";
    char expected[] = "Abo+ba";
    char *got = (char *)s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test2) {
    char str[] = "Ab000cd0";
    char trim_ch[] = "003";
    char expected[] = "Ab000cd";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test3) {
    char str[] = "DoNotTouch";
    char trim_ch[] = "Not";
    char expected[] = "DoNotTouch";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test4) {
    char str[] = "&* !!sc21 * **";
    char trim_ch[] = "&!* ";
    char expected[] = "sc21";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test5) {
    char str[] = " Good morning!    ";
    char trim_ch[] = " ";
    char expected[] = "Good morning!";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(empty_spaces) {
    char str[] = "        abc         ";
    char trim_ch[] = "";
    char expected[] = "abc";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(null_ptr_trim_chars) {
    char str[] = "        abc         ";
    char *trim_ch = NULL;
    char expected[] = "abc";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

Suite *suite_trim(void) {
    Suite *s = suite_create("suite_trim");
    TCase *tc = tcase_create("trim_tc");

    tcase_add_test(tc, all_empty);
    tcase_add_test(tc, str_empty);
    tcase_add_test(tc, trim_empty);
    tcase_add_test(tc, trim_and_str_eq);

    tcase_add_test(tc, trim_test1);
    tcase_add_test(tc, trim_test2);
    tcase_add_test(tc, trim_test3);
    tcase_add_test(tc, trim_test4);
    tcase_add_test(tc, trim_test5);
    tcase_add_test(tc, empty_spaces);
    tcase_add_test(tc, null_ptr_trim_chars);

    suite_add_tcase(s, tc);
    return s;
}

void run_testcase(Suite *testcase) {
    setlocale(LC_ALL, "");
    static int counter_testcase = 1;

    if (counter_testcase > 1)
        putchar('\n');
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;

    SRunner *sr = srunner_create(testcase);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
    // sleep(1);
}

void run_tests(void) {
    Suite *list_cases[] = {
        suite_memchr(), suite_memcmp(), suite_memcpy(),
        suite_memmove(), suite_memset(), suite_strcat(),
        suite_strncat(), suite_strchr(), suite_strcmp(),
        suite_strncmp(), suite_strcpy(), suite_strncpy(),
        suite_strcspn(), suite_strerror(), suite_strlen(),
        suite_strpbrk(), suite_strrchr(), suite_strspn(),
        suite_strstr(), suite_insert(), suite_to_lower(),
        suite_to_upper(), suite_trim(), suite_strtok(),
        suite_sprintf(), NULL};

    for (Suite **current_testcase = list_cases; *current_testcase != NULL;
         current_testcase++) {
        run_testcase(*current_testcase);
    }
}
