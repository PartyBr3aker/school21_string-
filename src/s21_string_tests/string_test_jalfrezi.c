#include <check.h>
#include "s21_string.h"
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>


START_TEST (test_s21_strlen) {    
  extern s21_size_t s21_strlen(const char *str);
  ck_assert_int_eq(s21_strlen("a"), strlen("a")); 
} END_TEST 

START_TEST (test_s21_strlen2) {    
  extern s21_size_t s21_strlen(const char *str);
  ck_assert_int_eq(s21_strlen(""), strlen("")); 
} END_TEST 

Suite *string_suite(void) {       
  Suite *s;                      
  TCase *tc_core;                
  s = suite_create("String");     
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_strlen); 
  tcase_add_test(tc_core, test_s21_strlen2); 
  suite_add_tcase(s, tc_core);                
  return s;
}

int main(void) {
  int no_failed = 0;                   
  Suite *first_suite;                            
  SRunner *runner;                     
  first_suite = string_suite();                   
  runner = srunner_create(first_suite);          
  srunner_run_all(runner, CK_NORMAL);  
  no_failed = srunner_ntests_failed(runner); 
  srunner_free(runner);                      
  return (no_failed == 0) ? 0 : 1; 
}

