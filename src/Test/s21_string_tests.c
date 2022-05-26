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
#include "../s21_string.h"

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
START_TEST(float_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "% .0f %.lf %Lf %f %lf %Lf";
    float val = 0;
    double val1 = 0;
    long double val2 = 3515315.153151;
    float val3 = 5.5;
    double val4 = 9851.51351;
    long double val5 = 95919539159.53151351131;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
        sprintf(str2, format, val, val1, val2, val3, val4, val5));

    ck_assert_str_eq(str1, str2);
}
END_TEST
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
Suite *suite_sprintf(void) {
    Suite *s = suite_create("suite_sprintf");
    TCase *tc = tcase_create("sprintf_tc");
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
    tcase_add_test(tc, float_many);
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