#include "s21_grep.h"

#include <check.h>

START_TEST(empty_option) {
  system("grep include s21_grep.h > a");
  system("./s21_grep include s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option1) {
  system("grep -e include s21_grep.h > a");
  system("./s21_grep -e include s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option2) {
  system("grep -e include -e end s21_grep.h > a");
  system("./s21_grep -e include -e end s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option3) {
  system("grep -e include -e end -e aaa s21_grep.h > a");
  system("./s21_grep -e include -e end -e aaa s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option4) {
  system("grep s21_grep.h -e include > a");
  system("./s21_grep s21_grep.h -e include > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option5) {
  system("grep s21_grep.h -e incl.de -e end > a");
  system("./s21_grep s21_grep.h -e incl.de -e end > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option6) {
  system("grep -e include s21_grep.h s21_grep.c > a");
  system("./s21_grep -e include s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option7) {
  system("grep -e include -e end s21_grep.h s21_grep.c > a");
  system("./s21_grep -e include -e end s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option8) {
  system("grep -e include -e end -e aaa s21_grep.h s21_grep.c > a");
  system("./s21_grep -e include -e end -e aaa s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option9) {
  system("grep s21_grep.h -e include s21_grep.c > a");
  system("./s21_grep s21_grep.h -e include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(e_option10) {
  system("grep s21_grep.h -e incl.de -e end s21_grep.c > a");
  system("./s21_grep s21_grep.h -e incl.de -e end s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(i_option1) {
  system("grep -i include s21_grep.h > a");
  system("./s21_grep -i include s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(i_option2) {
  system("grep -i incLudE s21_grep.h > a");
  system("./s21_grep -i incLudE s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(i_option3) {
  system("grep -i incL.dE s21_grep.h > a");
  system("./s21_grep -i incL.dE s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(i_option4) {
  system("grep -i include s21_grep.h s21_grep.c > a");
  system("./s21_grep -i include s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(i_option5) {
  system("grep -i incLudE s21_grep.h s21_grep.c > a");
  system("./s21_grep -i incLudE s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(i_option6) {
  system("grep -i incL.dE s21_grep.h s21_grep.c > a");
  system("./s21_grep -i incL.dE s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(v_option1) {
  system("grep -v include s21_grep.h > a");
  system("./s21_grep -v include s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(v_option2) {
  system("grep -v inclue s21_grep.h > a");
  system("./s21_grep -v inclue s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(v_option3) {
  system("grep -v int s21_grep.c > a");
  system("./s21_grep -v int s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(v_option4) {
  system("grep -v include s21_grep.h s21_grep.c > a");
  system("./s21_grep -v include s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(v_option5) {
  system("grep -v inclue s21_grep.h s21_grep.c > a");
  system("./s21_grep -v inclue s21_grep.h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(v_option6) {
  system("grep -v int s21_grep.c s21_grep.c > a");
  system("./s21_grep -v int s21_grep.c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(c_option1) {
  system("grep -c int s21_grep.c > a");
  system("./s21_grep -c int s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(c_option2) {
  system("grep -c include s21_grep.c > a");
  system("./s21_grep -c include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(c_option3) {
  system("grep -c aaa s21_grep.c > a");
  system("./s21_grep -c aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(c_option4) {
  system("grep -c int s21_grep.c s21_grep.h > a");
  system("./s21_grep -c int s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(c_option5) {
  system("grep -c include s21_grep.c s21_grep.h > a");
  system("./s21_grep -c include s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(c_option6) {
  system("grep -c aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -c aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(n_option1) {
  system("grep -n aaa s21_grep.c > a");
  system("./s21_grep -n aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(n_option2) {
  system("grep -n include s21_grep.c > a");
  system("./s21_grep -n include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(n_option3) {
  system("grep -n -e include -e end s21_grep.c > a");
  system("./s21_grep -n -e include -e end s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(n_option4) {
  system("grep -n aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -n aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(n_option5) {
  system("grep -n include s21_grep.c s21_grep.h > a");
  system("./s21_grep -n include s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(n_option6) {
  system("grep -n -e include -e end s21_grep.c s21_grep.h > a");
  system("./s21_grep -n -e include -e end s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(l_option1) {
  system("grep -l aaa s21_grep.c > a");
  system("./s21_grep -l aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(l_option2) {
  system("grep -l include s21_grep.c > a");
  system("./s21_grep -l include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(l_option3) {
  system("grep -l -e include -e end s21_grep.c > a");
  system("./s21_grep -l -e include -e end s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(l_option4) {
  system("grep -l aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -l aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(l_option5) {
  system("grep -l include s21_grep.c s21_grep.h > a");
  system("./s21_grep -l include s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(l_option6) {
  system("grep -l -e include -e end s21_grep.c s21_grep.h > a");
  system("./s21_grep -l -e include -e end s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ei_option1) {
  system("grep -i -e incLude -e enD s21_grep.c > a");
  system("./s21_grep -i -e incLude -e enD s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ei_option2) {
  system("grep -i -e incLude s21_grep.c -e enD > a");
  system("./s21_grep -i -e incLude s21_grep.c -e enD > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ei_option3) {
  system("grep -i -e incLude s21_grep.c -e enD s21_grep.h > a");
  system("./s21_grep -i -e incLude s21_grep.c -e enD s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ei_option4) {
  system("grep -i -e incLude -e enD s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -e incLude -e enD s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ei_option5) {
  system("grep -i -e incLude s21_grep.c -e enD s21_grep.h> a");
  system("./s21_grep -i -e incLude s21_grep.c -e enD s21_grep.h> b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ei_option6) {
  system("grep -i -e incLude s21_grep.c -e enD s21_grep.h > a");
  system("./s21_grep -i -e incLude s21_grep.c -e enD s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ev_option1) {
  system("grep -v -e incLude s21_grep.c -e enD s21_grep.h > a");
  system("./s21_grep -v -e incLude s21_grep.c -e enD s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ev_option2) {
  system("grep -v -e incLude -e enD s21_grep.c > a");
  system("./s21_grep -v -e incLude -e enD s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ev_option3) {
  system("grep -v -e ' ' s21_grep.c -e enD > a");
  system("./s21_grep -v -e ' ' s21_grep.c -e enD > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ec_option1) {
  system("grep -c -e . s21_grep.c -e '.' > a");
  system("./s21_grep -c -e . s21_grep.c -e '.' > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ec_option2) {
  system("grep -c -e . s21_grep.c -e '.' s21_grep.h > a");
  system("./s21_grep -c -e . s21_grep.c -e '.' s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(iv_option1) {
  system("grep -i -v . s21_grep.c > a");
  system("./s21_grep -i -v . s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(iv_option2) {
  system("grep -i -v inClude s21_grep.c > a");
  system("./s21_grep -i -v inClude s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(iv_option3) {
  system("grep -i -v aaa s21_grep.c > a");
  system("./s21_grep -i -v aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(iv_option4) {
  system("grep -i -v . s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -v . s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(iv_option5) {
  system("grep -i -v inClude s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -v inClude s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(iv_option6) {
  system("grep -i -v aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -v aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ic_option1) {
  system("grep -i -c aaa s21_grep.c > a");
  system("./s21_grep -i -c aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ic_option2) {
  system("grep -i -c inClu.e s21_grep.c > a");
  system("./s21_grep -i -c inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ic_option3) {
  system("grep inClu.e -i -c s21_grep.c  > a");
  system("./s21_grep inClu.e -i -c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ic_option4) {
  system("grep -i -c aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -c aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ic_option5) {
  system("grep -i -c inClu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -c inClu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ic_option6) {
  system("grep inClu.e -i -c s21_grep.c s21_grep.h > a");
  system("./s21_grep inClu.e -i -c s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(il_option1) {
  system("grep -i -l aaa s21_grep.c > a");
  system("./s21_grep -i -l aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(il_option2) {
  system("grep -i -l inClu.e s21_grep.c > a");
  system("./s21_grep -i -l inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(il_option3) {
  system("grep inClu.e s21_grep.c -i -l > a");
  system("./s21_grep inClu.e s21_grep.c -i -l > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(il_option4) {
  system("grep -i -l aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -l aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(il_option5) {
  system("grep -i -l inClu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -l inClu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(il_option6) {
  system("grep inClu.e s21_grep.c -i -l s21_grep.h > a");
  system("./s21_grep inClu.e s21_grep.c -i -l s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(in_option1) {
  system("grep -i -n aaa s21_grep.c > a");
  system("./s21_grep -i -n aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(in_option2) {
  system("grep -i -n inClu.e s21_grep.c > a");
  system("./s21_grep -i -n inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(in_option3) {
  system("grep inClu.e s21_grep.c -i -n > a");
  system("./s21_grep inClu.e s21_grep.c -i -n > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(in_option4) {
  system("grep -i -n aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -n aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(in_option5) {
  system("grep -i -n inClu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -i -n inClu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(in_option6) {
  system("grep inClu.e s21_grep.c -i -n s21_grep.h > a");
  system("./s21_grep inClu.e s21_grep.c -i -n s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vc_option1) {
  system("grep -v -c aaa s21_grep.c > a");
  system("./s21_grep -v -c aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vc_option2) {
  system("grep -v -c inClu.e s21_grep.c > a");
  system("./s21_grep -v -c inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vc_option3) {
  system("grep inClu.e s21_grep.c -v -c > a");
  system("./s21_grep inClu.e s21_grep.c -v -c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vc_option4) {
  system("grep -v -c aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -v -c aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vc_option5) {
  system("grep -v -c inClu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -v -c inClu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vc_option6) {
  system("grep inClu.e s21_grep.c -v -c s21_grep.h > a");
  system("./s21_grep inClu.e s21_grep.c -v -c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vl_option1) {
  system("grep -v -l aaa s21_grep.c > a");
  system("./s21_grep -v -l aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vl_option2) {
  system("grep -v -l inClu.e s21_grep.c > a");
  system("./s21_grep -v -l inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vl_option3) {
  system("grep inClu.e s21_grep.c -v -l > a");
  system("./s21_grep inClu.e s21_grep.c -v -l > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vl_option4) {
  system("grep -v -l aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -v -l aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vl_option5) {
  system("grep -v -l inClu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -v -l inClu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vl_option6) {
  system("grep inClu.e s21_grep.c -v -l s21_grep.h > a");
  system("./s21_grep inClu.e s21_grep.c -v -l s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vn_option1) {
  system("grep -v -n aaa s21_grep.c > a");
  system("./s21_grep -v -n aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vn_option2) {
  system("grep -v -n inClu.e s21_grep.c > a");
  system("./s21_grep -v -n inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(vn_option3) {
  system("grep inClu.e s21_grep.c -v -n > a");
  system("./s21_grep inClu.e s21_grep.c -v -n > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(cl_option1) {
  system("grep -c -l aaa s21_grep.c > a");
  system("./s21_grep -c -l aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(cl_option2) {
  system("grep -c -l inClu.e s21_grep.c > a");
  system("./s21_grep -c -l inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(cl_option3) {
  system("grep inClu.e s21_grep.c -c -l > a");
  system("./s21_grep inClu.e s21_grep.c -c -l > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(cn_option1) {
  system("grep -c -n aaa s21_grep.c > a");
  system("./s21_grep -c -n aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(cn_option2) {
  system("grep -c -n inClu.e s21_grep.c > a");
  system("./s21_grep -c -n inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(cn_option3) {
  system("grep inClu.e s21_grep.c -c -n > a");
  system("./s21_grep inClu.e s21_grep.c -c -n > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ln_option1) {
  system("grep -n -l aaa s21_grep.c > a");
  system("./s21_grep -n -l aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ln_option2) {
  system("grep -n -l inClu.e s21_grep.c > a");
  system("./s21_grep -n -l inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(nl_option3) {
  system("grep inClu.e s21_grep.c -n -l > a");
  system("./s21_grep inClu.e s21_grep.c -n -l > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(he_option1) {
  system("grep -h -e aaa s21_grep.c > a");
  system("./s21_grep -h -e aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(he_option2) {
  system("grep -h -e inclu.e s21_grep.c > a");
  system("./s21_grep -h -e inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(he_option3) {
  system("grep -e inclu.e s21_grep.c -h > a");
  system("./s21_grep -e inclu.e s21_grep.c -h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(he_option4) {
  system("grep -h -e aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -e aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(he_option5) {
  system("grep -h -e inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -e inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(he_option6) {
  system("grep -e inclu.e s21_grep.c -h s21_grep.h > a");
  system("./s21_grep -e inclu.e s21_grep.c -h s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hi_option1) {
  system("grep -h -i aaa s21_grep.c > a");
  system("./s21_grep -h -i aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hi_option2) {
  system("grep -h -i inClu.e s21_grep.c > a");
  system("./s21_grep -h -i inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hi_option3) {
  system("grep -i inClu.e s21_grep.c -h > a");
  system("./s21_grep -i inClu.e s21_grep.c -h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hi_option4) {
  system("grep -h -i aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -i aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hi_option5) {
  system("grep -h -i inClu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -i inClu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hi_option6) {
  system("grep -i inClu.e s21_grep.c -h s21_grep.h > a");
  system("./s21_grep -i inClu.e s21_grep.c -h s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hv_option1) {
  system("grep -h -v aaa s21_grep.c > a");
  system("./s21_grep -h -v aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hv_option2) {
  system("grep -h -v inclu.e s21_grep.c > a");
  system("./s21_grep -h -v inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hv_option6) {
  system("grep -v inclu.e s21_grep.c -h > a");
  system("./s21_grep -v inclu.e s21_grep.c -h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hv_option3) {
  system("grep -h -v aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -v aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hv_option4) {
  system("grep -h -v inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -v inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hv_option5) {
  system("grep -v inClu.e s21_grep.c -h s21_grep.h > a");
  system("./s21_grep -v inClu.e s21_grep.c -h s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hc_option1) {
  system("grep -h -c aaa s21_grep.c > a");
  system("./s21_grep -h -c aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hc_option2) {
  system("grep -h -c inclu.e s21_grep.c > a");
  system("./s21_grep -h -c inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hc_option6) {
  system("grep -c inclu.e s21_grep.c -h > a");
  system("./s21_grep -c inclu.e s21_grep.c -h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hc_option3) {
  system("grep -h -c aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -c aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hc_option4) {
  system("grep -h -c inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -c inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hc_option5) {
  system("grep -c inClu.e s21_grep.c -h s21_grep.h > a");
  system("./s21_grep -c inClu.e s21_grep.c -h s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hl_option1) {
  system("grep -h -l aaa s21_grep.c > a");
  system("./s21_grep -h -l aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hl_option2) {
  system("grep -h -l inclu.e s21_grep.c > a");
  system("./s21_grep -h -l inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hl_option6) {
  system("grep -l inclu.e s21_grep.c -h > a");
  system("./s21_grep -l inclu.e s21_grep.c -h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hl_option3) {
  system("grep -h -l aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -l aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hl_option4) {
  system("grep -h -l inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -l inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hl_option5) {
  system("grep -l inClu.e s21_grep.c -h s21_grep.h > a");
  system("./s21_grep -l inClu.e s21_grep.c -h s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hn_option1) {
  system("grep -h -n aaa s21_grep.c > a");
  system("./s21_grep -h -n aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hn_option2) {
  system("grep -h -n inclu.e s21_grep.c > a");
  system("./s21_grep -h -n inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hn_option6) {
  system("grep -n inclu.e s21_grep.c -h > a");
  system("./s21_grep -n inclu.e s21_grep.c -h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hn_option3) {
  system("grep -h -n aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -n aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hn_option4) {
  system("grep -h -n inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -h -n inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(hn_option5) {
  system("grep -n inClu.e s21_grep.c -h s21_grep.h > a");
  system("./s21_grep -n inClu.e s21_grep.c -h s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(se_option1) {
  system("grep -s -e aaa s21_grep.c > a");
  system("./s21_grep -s -e aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(se_option2) {
  system("grep -s -e inclu.e s21_grep.c > a");
  system("./s21_grep -s -e inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(se_option6) {
  system("grep -e inclu.e s21_grep.c -s > a");
  system("./s21_grep -e inclu.e s21_grep.c -s > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(se_option3) {
  system("grep -s -e aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -e aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(se_option4) {
  system("grep -s -e inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -e inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(se_option5) {
  system("grep -e inclu.e s21_grep.c -s s21_grep.h > a");
  system("./s21_grep -e inclu.e s21_grep.c -s s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(si_option1) {
  system("grep -s -i aaa s21_grep.c > a");
  system("./s21_grep -s -i aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(si_option2) {
  system("grep -s -i inClu.e s21_grep.c > a");
  system("./s21_grep -s -i inClu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(si_option6) {
  system("grep -i inClu.e s21_grep.c -s > a");
  system("./s21_grep -i inClu.e s21_grep.c -s > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(si_option3) {
  system("grep -s -i aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -i aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(si_option4) {
  system("grep -s -i inClu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -i inClu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(si_option5) {
  system("grep -i inClu.e s21_grep.c -s s21_grep.h > a");
  system("./s21_grep -i inClu.e s21_grep.c -s s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sv_option1) {
  system("grep -s -v aaa s21_grep.c > a");
  system("./s21_grep -s -v aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sv_option2) {
  system("grep -s -v inclu.e s21_grep.c > a");
  system("./s21_grep -s -v inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sv_option6) {
  system("grep -v inclu.e s21_grep.c -s > a");
  system("./s21_grep -v inclu.e s21_grep.c -s > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sv_option3) {
  system("grep -s -v aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -v aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sv_option4) {
  system("grep -s -v inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -v inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sv_option5) {
  system("grep -v inClu.e s21_grep.c -s s21_grep.h > a");
  system("./s21_grep -v inClu.e s21_grep.c -s s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sc_option1) {
  system("grep -s -c aaa s21_grep.c > a");
  system("./s21_grep -s -c aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sc_option2) {
  system("grep -s -c inclu.e s21_grep.c > a");
  system("./s21_grep -s -c inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sc_option3) {
  system("grep -c inclu.e s21_grep.c -s > a");
  system("./s21_grep -c inclu.e s21_grep.c -s > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sc_option6) {
  system("grep -s -c aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -c aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sc_option4) {
  system("grep -s -c inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -c inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sc_option5) {
  system("grep -c inClu.e s21_grep.c -s s21_grep.h > a");
  system("./s21_grep -c inClu.e s21_grep.c -s s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sl_option1) {
  system("grep -s -l aaa s21_grep.c > a");
  system("./s21_grep -s -l aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sl_option2) {
  system("grep -s -l inclu.e s21_grep.c > a");
  system("./s21_grep -s -l inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sl_option3) {
  system("grep -l inclu.e s21_grep.c -s > a");
  system("./s21_grep -l inclu.e s21_grep.c -s > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sl_option6) {
  system("grep -s -l aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -l aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sl_option4) {
  system("grep -s -l inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -l inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sl_option5) {
  system("grep -l inClu.e s21_grep.c -s s21_grep.h > a");
  system("./s21_grep -l inClu.e s21_grep.c -s s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sn_option1) {
  system("grep -s -n aaa s21_grep.c > a");
  system("./s21_grep -s -n aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sn_option2) {
  system("grep -s -n inclu.e s21_grep.c > a");
  system("./s21_grep -s -n inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sn_option3) {
  system("grep -n inclu.e s21_grep.c -s > a");
  system("./s21_grep -n inclu.e s21_grep.c -s > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sn_option6) {
  system("grep -s -n aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -n aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sn_option4) {
  system("grep -s -n inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -n inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sn_option5) {
  system("grep -n inClu.e s21_grep.c -s s21_grep.h > a");
  system("./s21_grep -n inClu.e s21_grep.c -s s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sh_option1) {
  system("grep -s -h aaa s21_grep.c > a");
  system("./s21_grep -s -h aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sh_option2) {
  system("grep -s -h inclu.e s21_grep.c > a");
  system("./s21_grep -s -h inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sh_option3) {
  system("grep -h inclu.e s21_grep.c -s > a");
  system("./s21_grep -h inclu.e s21_grep.c -s > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sh_option6) {
  system("grep -s -h aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -h aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sh_option4) {
  system("grep -s -h inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -s -h inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(sh_option5) {
  system("grep -h inClu.e s21_grep.c -s s21_grep.h > a");
  system("./s21_grep -h inClu.e s21_grep.c -s s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ef_option1) {
  system("grep -f pattern_file.txt -e aaa s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -e aaa s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ef_option2) {
  system("grep -f pattern_file.txt -e inclu.e s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -e inclu.e s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ef_option3) {
  system("grep -e inclu.e s21_grep.c -f pattern_file.txt > a");
  system("./s21_grep -e inclu.e s21_grep.c -f pattern_file.txt > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ef_option6) {
  system("grep -f pattern_file.txt -e aaa s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -e aaa s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ef_option4) {
  system("grep -f pattern_file.txt -e inclu.e s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -e inclu.e s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ef_option5) {
  system("grep -e inclu.e s21_grep.c -f pattern_file.txt s21_grep.h > a");
  system("./s21_grep -e inclu.e s21_grep.c -f pattern_file.txt s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fi_option1) {
  system("grep -f pattern_file.txt -i s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -i s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fi_option2) {
  system("grep -f pattern_file.txt -i s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -i s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fi_option3) {
  system("grep -i s21_grep.c -f pattern_file.txt > a");
  system("./s21_grep -i s21_grep.c -f pattern_file.txt > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fi_option6) {
  system("grep -f pattern_file.txt -i s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -i s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fi_option4) {
  system("grep -f pattern_file.txt -i s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -i s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fi_option5) {
  system("grep -i s21_grep.c -f pattern_file.txt s21_grep.h > a");
  system("./s21_grep -i s21_grep.c -f pattern_file.txt s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fv_option1) {
  system("grep -f pattern_file.txt -v s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -v s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fv_option2) {
  system("grep -f pattern_file.txt -v s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -v s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fv_option3) {
  system("grep -v s21_grep.c -f pattern_file.txt > a");
  system("./s21_grep -v s21_grep.c -f pattern_file.txt > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fv_option6) {
  system("grep -f pattern_file.txt -v s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -v s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fv_option4) {
  system("grep -f pattern_file.txt -v s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -v s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fv_option5) {
  system("grep -v s21_grep.c -f pattern_file.txt s21_grep.h > a");
  system("./s21_grep -v s21_grep.c -f pattern_file.txt s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fc_option1) {
  system("grep -f pattern_file.txt -c s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fc_option2) {
  system("grep -f pattern_file.txt -c s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fc_option3) {
  system("grep -c s21_grep.c -f pattern_file.txt > a");
  system("./s21_grep -c s21_grep.c -f pattern_file.txt > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fc_option6) {
  system("grep -f pattern_file.txt -c s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -c s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fc_option4) {
  system("grep -f pattern_file.txt -c s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -c s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fc_option5) {
  system("grep -c s21_grep.c -f pattern_file.txt s21_grep.h > a");
  system("./s21_grep -c s21_grep.c -f pattern_file.txt s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fl_option1) {
  system("grep -f pattern_file.txt -l s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -l s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fl_option2) {
  system("grep -f pattern_file.txt -l s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -l s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fl_option3) {
  system("grep -l s21_grep.c -f pattern_file.txt > a");
  system("./s21_grep -l s21_grep.c -f pattern_file.txt > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fl_option6) {
  system("grep -f pattern_file.txt -l s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -l s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fl_option4) {
  system("grep -f pattern_file.txt -l s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -l s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fl_option5) {
  system("grep -l s21_grep.c -f pattern_file.txt s21_grep.h > a");
  system("./s21_grep -l s21_grep.c -f pattern_file.txt s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fn_option1) {
  system("grep -f pattern_file.txt -n s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -n s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fn_option2) {
  system("grep -f pattern_file.txt -n s21_grep.c > a");
  system("./s21_grep -f pattern_file.txt -n s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fn_option3) {
  system("grep -n s21_grep.c -f pattern_file.txt > a");
  system("./s21_grep -n s21_grep.c -f pattern_file.txt > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fn_option6) {
  system("grep -f pattern_file.txt -n s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -n s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fn_option4) {
  system("grep -f pattern_file.txt -n s21_grep.c s21_grep.h > a");
  system("./s21_grep -f pattern_file.txt -n s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fn_option5) {
  system("grep -n s21_grep.c -f pattern_file.txt s21_grep.h > a");
  system("./s21_grep -n s21_grep.c -f pattern_file.txt s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fh_option1) {
  system("grep -fpattern_file.txt -h s21_grep.c > a");
  system("./s21_grep -fpattern_file.txt -h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fh_option2) {
  system("grep -fpattern_file.txt -h s21_grep.c > a");
  system("./s21_grep -fpattern_file.txt -h s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fh_option3) {
  system("grep -h s21_grep.c -fpattern_file.txt > a");
  system("./s21_grep -h s21_grep.c -fpattern_file.txt > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fh_option6) {
  system("grep -fpattern_file.txt -h s21_grep.c s21_grep.h > a");
  system("./s21_grep -fpattern_file.txt -h s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fh_option4) {
  system("grep -fpattern_file.txt -h s21_grep.c s21_grep.h > a");
  system("./s21_grep -fpattern_file.txt -h s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(fh_option5) {
  system("grep -h s21_grep.c -fpattern_file.txt s21_grep.h > a");
  system("./s21_grep -h s21_grep.c -fpattern_file.txt s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(o_option1) {
  system("grep -o include s21_grep.c > a");
  system("./s21_grep -o include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(o_option2) {
  system("grep -o int s21_grep.c > a");
  system("./s21_grep -o int s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(o_option3) {
  system("grep -o incLude s21_grep.c > a");
  system("./s21_grep -o incLude s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(o_option6) {
  system("grep -o Void s21_grep.c s21_grep.h > a");
  system("./s21_grep -o Void s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(o_option4) {
  system("grep -o 'int ' s21_grep.c s21_grep.h > a");
  system("./s21_grep -o 'int ' s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(o_option5) {
  system("grep -o 'else iF' s21_grep.c s21_grep.h > a");
  system("./s21_grep -o 'else iF' s21_grep.c s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oe_option1) {
  system("grep -o -e include s21_grep.c > a");
  system("./s21_grep -o -e include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oe_option2) {
  system("grep -o -e int -e int s21_grep.c > a");
  system("./s21_grep -o -e int -e int s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oe_option3) {
  system("grep -o -e incLude -e eee -e int s21_grep.c > a");
  system("./s21_grep -o -e incLude -e eee -e int s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oe_option6) {
  system("grep -o -e if s21_grep.c -e else s21_grep.h > a");
  system("./s21_grep -o -e if s21_grep.c -e else s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oe_option4) {
  system("grep -o -e int s21_grep.c -e int s21_grep.h > a");
  system("./s21_grep -o -e int s21_grep.c -e int s21_grep.h > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oi_option1) {
  system("grep -o -i incLUde s21_grep.c > a");
  system("./s21_grep -o -i incLUde s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oi_option2) {
  system("grep -o -i VOId s21_grep.c > a");
  system("./s21_grep -o -i VOId s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oi_option3) {
  system("grep -o -i Int s21_grep.c s21_grep.c > a");
  system("./s21_grep -o -i Int s21_grep.c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ov_option1) {
  system("grep -o -v include s21_grep.c > a");
  system("./s21_grep -o -v include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ov_option2) {
  system("grep -o -v void s21_grep.c > a");
  system("./s21_grep -o -v void s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ov_option3) {
  system("grep -o -v -e int -e int s21_grep.c s21_grep.c > a");
  system("./s21_grep -o -v -e int -e int s21_grep.c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ol_option1) {
  system("grep -o -l include s21_grep.c > a");
  system("./s21_grep -o -l include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ol_option2) {
  system("grep -o -l void s21_grep.c > a");
  system("./s21_grep -o -l void s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(ol_option3) {
  system("grep -o -l -e int -e int s21_grep.c s21_grep.c > a");
  system("./s21_grep -o -l -e int -e int s21_grep.c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(on_option1) {
  system("grep -o -n include s21_grep.c > a");
  system("./s21_grep -o -n include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(on_option2) {
  system("grep -o -n void s21_grep.c > a");
  system("./s21_grep -o -n void s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(on_option3) {
  system("grep -o -n -e int -e int s21_grep.c s21_grep.c > a");
  system("./s21_grep -o -n -e int -e int s21_grep.c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oh_option1) {
  system("grep -o -h include s21_grep.c > a");
  system("./s21_grep -o -h include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oh_option2) {
  system("grep -o -h void s21_grep.c > a");
  system("./s21_grep -o -h void s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(oh_option3) {
  system("grep -o -h -e int -e int s21_grep.c s21_grep.c > a");
  system("./s21_grep -o -h -e int -e int s21_grep.c s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(os_option1) {
  system("grep -o -s include s21_grep.c > a");
  system("./s21_grep -o -s include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(os_option2) {
  system("grep -o -s void s21_grep.cpp > a");
  system("./s21_grep -o -s void s21_grep.cpp > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(os_option3) {
  system("grep -o -s -e int -e int s21_grep.c s21_grep.cpp > a");
  system("./s21_grep -o -s -e int -e int s21_grep.c s21_grep.cpp > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(of_option1) {
  system("grep -o -fpattern_file.txt include s21_grep.c > a");
  system("./s21_grep -o -fpattern_file.txt include s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(of_option2) {
  system("grep -o -fpattern_file.txt void s21_grep.c > a");
  system("./s21_grep -o -fpattern_file.txt void s21_grep.c > b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

START_TEST(of_option3) {
  system("grep -o -fpattern_file.txt -e int -e int s21_grep.c s21_grep.c > a");
  system(
      "./s21_grep -o -fpattern_file.txt -e int -e int s21_grep.c s21_grep.c "
      "> b");
  ck_assert_int_eq(system("cmp a b"), 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, empty_option);
  tcase_add_test(tc1_1, e_option1);
  tcase_add_test(tc1_1, e_option2);
  tcase_add_test(tc1_1, e_option3);
  tcase_add_test(tc1_1, e_option4);
  tcase_add_test(tc1_1, e_option5);
  tcase_add_test(tc1_1, e_option6);
  tcase_add_test(tc1_1, e_option7);
  tcase_add_test(tc1_1, e_option8);
  tcase_add_test(tc1_1, e_option9);
  tcase_add_test(tc1_1, e_option10);
  tcase_add_test(tc1_1, i_option1);
  tcase_add_test(tc1_1, i_option2);
  tcase_add_test(tc1_1, i_option3);
  tcase_add_test(tc1_1, i_option4);
  tcase_add_test(tc1_1, i_option5);
  tcase_add_test(tc1_1, i_option6);
  tcase_add_test(tc1_1, v_option1);
  tcase_add_test(tc1_1, v_option2);
  tcase_add_test(tc1_1, v_option3);
  tcase_add_test(tc1_1, v_option4);
  tcase_add_test(tc1_1, v_option5);
  tcase_add_test(tc1_1, v_option6);
  tcase_add_test(tc1_1, c_option1);
  tcase_add_test(tc1_1, c_option2);
  tcase_add_test(tc1_1, c_option3);
  tcase_add_test(tc1_1, c_option4);
  tcase_add_test(tc1_1, c_option5);
  tcase_add_test(tc1_1, c_option6);
  tcase_add_test(tc1_1, n_option1);
  tcase_add_test(tc1_1, n_option2);
  tcase_add_test(tc1_1, n_option3);
  tcase_add_test(tc1_1, n_option4);
  tcase_add_test(tc1_1, n_option5);
  tcase_add_test(tc1_1, n_option6);
  tcase_add_test(tc1_1, l_option1);
  tcase_add_test(tc1_1, l_option2);
  tcase_add_test(tc1_1, l_option3);
  tcase_add_test(tc1_1, l_option4);
  tcase_add_test(tc1_1, l_option5);
  tcase_add_test(tc1_1, l_option6);
  tcase_add_test(tc1_1, ei_option1);
  tcase_add_test(tc1_1, ei_option2);
  tcase_add_test(tc1_1, ei_option3);
  tcase_add_test(tc1_1, ei_option4);
  tcase_add_test(tc1_1, ei_option5);
  tcase_add_test(tc1_1, ei_option6);
  tcase_add_test(tc1_1, ev_option1);
  tcase_add_test(tc1_1, ev_option2);
  tcase_add_test(tc1_1, ev_option3);
  tcase_add_test(tc1_1, ec_option1);
  tcase_add_test(tc1_1, ec_option2);
  tcase_add_test(tc1_1, iv_option1);
  tcase_add_test(tc1_1, iv_option2);
  tcase_add_test(tc1_1, iv_option3);
  tcase_add_test(tc1_1, iv_option4);
  tcase_add_test(tc1_1, iv_option5);
  tcase_add_test(tc1_1, iv_option6);
  tcase_add_test(tc1_1, ic_option1);
  tcase_add_test(tc1_1, ic_option2);
  tcase_add_test(tc1_1, ic_option3);
  tcase_add_test(tc1_1, ic_option4);
  tcase_add_test(tc1_1, ic_option5);
  tcase_add_test(tc1_1, ic_option6);
  tcase_add_test(tc1_1, il_option1);
  tcase_add_test(tc1_1, il_option2);
  tcase_add_test(tc1_1, il_option3);
  tcase_add_test(tc1_1, il_option4);
  tcase_add_test(tc1_1, il_option5);
  tcase_add_test(tc1_1, il_option6);
  tcase_add_test(tc1_1, in_option1);
  tcase_add_test(tc1_1, in_option2);
  tcase_add_test(tc1_1, in_option3);
  tcase_add_test(tc1_1, in_option4);
  tcase_add_test(tc1_1, in_option5);
  tcase_add_test(tc1_1, in_option6);
  tcase_add_test(tc1_1, vc_option1);
  tcase_add_test(tc1_1, vc_option2);
  tcase_add_test(tc1_1, vc_option3);
  tcase_add_test(tc1_1, vc_option4);
  tcase_add_test(tc1_1, vc_option5);
  tcase_add_test(tc1_1, vc_option6);
  tcase_add_test(tc1_1, vl_option1);
  tcase_add_test(tc1_1, vl_option2);
  tcase_add_test(tc1_1, vl_option3);
  tcase_add_test(tc1_1, vl_option4);
  tcase_add_test(tc1_1, vl_option5);
  tcase_add_test(tc1_1, vl_option6);
  tcase_add_test(tc1_1, vn_option1);
  tcase_add_test(tc1_1, vn_option2);
  tcase_add_test(tc1_1, vn_option3);
  tcase_add_test(tc1_1, cl_option1);
  tcase_add_test(tc1_1, cl_option2);
  tcase_add_test(tc1_1, cl_option3);
  tcase_add_test(tc1_1, cn_option1);
  tcase_add_test(tc1_1, cn_option2);
  tcase_add_test(tc1_1, cn_option3);
  tcase_add_test(tc1_1, ln_option1);
  tcase_add_test(tc1_1, ln_option2);
  tcase_add_test(tc1_1, nl_option3);
  tcase_add_test(tc1_1, he_option1);
  tcase_add_test(tc1_1, he_option2);
  tcase_add_test(tc1_1, he_option3);
  tcase_add_test(tc1_1, he_option4);
  tcase_add_test(tc1_1, he_option5);
  tcase_add_test(tc1_1, he_option6);
  tcase_add_test(tc1_1, hi_option1);
  tcase_add_test(tc1_1, hi_option2);
  tcase_add_test(tc1_1, hi_option3);
  tcase_add_test(tc1_1, hi_option4);
  tcase_add_test(tc1_1, hi_option5);
  tcase_add_test(tc1_1, hi_option6);
  tcase_add_test(tc1_1, hv_option1);
  tcase_add_test(tc1_1, hv_option2);
  tcase_add_test(tc1_1, hv_option6);
  tcase_add_test(tc1_1, hv_option3);
  tcase_add_test(tc1_1, hv_option4);
  tcase_add_test(tc1_1, hv_option5);
  tcase_add_test(tc1_1, hc_option1);
  tcase_add_test(tc1_1, hc_option2);
  tcase_add_test(tc1_1, hc_option6);
  tcase_add_test(tc1_1, hc_option3);
  tcase_add_test(tc1_1, hc_option4);
  tcase_add_test(tc1_1, hc_option5);
  tcase_add_test(tc1_1, hl_option1);
  tcase_add_test(tc1_1, hl_option2);
  tcase_add_test(tc1_1, hl_option6);
  tcase_add_test(tc1_1, hl_option3);
  tcase_add_test(tc1_1, hl_option4);
  tcase_add_test(tc1_1, hl_option5);
  tcase_add_test(tc1_1, hn_option1);
  tcase_add_test(tc1_1, hn_option2);
  tcase_add_test(tc1_1, hn_option6);
  tcase_add_test(tc1_1, hn_option3);
  tcase_add_test(tc1_1, hn_option4);
  tcase_add_test(tc1_1, hn_option5);
  tcase_add_test(tc1_1, se_option1);
  tcase_add_test(tc1_1, se_option2);
  tcase_add_test(tc1_1, se_option6);
  tcase_add_test(tc1_1, se_option3);
  tcase_add_test(tc1_1, se_option4);
  tcase_add_test(tc1_1, se_option5);
  tcase_add_test(tc1_1, si_option1);
  tcase_add_test(tc1_1, si_option2);
  tcase_add_test(tc1_1, si_option6);
  tcase_add_test(tc1_1, si_option3);
  tcase_add_test(tc1_1, si_option4);
  tcase_add_test(tc1_1, si_option5);
  tcase_add_test(tc1_1, sv_option1);
  tcase_add_test(tc1_1, sv_option2);
  tcase_add_test(tc1_1, sv_option6);
  tcase_add_test(tc1_1, sv_option3);
  tcase_add_test(tc1_1, sv_option4);
  tcase_add_test(tc1_1, sv_option5);
  tcase_add_test(tc1_1, sc_option1);
  tcase_add_test(tc1_1, sc_option2);
  tcase_add_test(tc1_1, sc_option3);
  tcase_add_test(tc1_1, sc_option6);
  tcase_add_test(tc1_1, sc_option4);
  tcase_add_test(tc1_1, sc_option5);
  tcase_add_test(tc1_1, sl_option1);
  tcase_add_test(tc1_1, sl_option2);
  tcase_add_test(tc1_1, sl_option3);
  tcase_add_test(tc1_1, sl_option6);
  tcase_add_test(tc1_1, sl_option4);
  tcase_add_test(tc1_1, sl_option5);
  tcase_add_test(tc1_1, sn_option1);
  tcase_add_test(tc1_1, sn_option2);
  tcase_add_test(tc1_1, sn_option3);
  tcase_add_test(tc1_1, sn_option6);
  tcase_add_test(tc1_1, sn_option4);
  tcase_add_test(tc1_1, sn_option5);
  tcase_add_test(tc1_1, sh_option1);
  tcase_add_test(tc1_1, sh_option2);
  tcase_add_test(tc1_1, sh_option3);
  tcase_add_test(tc1_1, sh_option6);
  tcase_add_test(tc1_1, sh_option4);
  tcase_add_test(tc1_1, sh_option5);
  tcase_add_test(tc1_1, ef_option1);
  tcase_add_test(tc1_1, ef_option2);
  tcase_add_test(tc1_1, ef_option3);
  tcase_add_test(tc1_1, ef_option6);
  tcase_add_test(tc1_1, ef_option4);
  tcase_add_test(tc1_1, ef_option5);
  tcase_add_test(tc1_1, fi_option1);
  tcase_add_test(tc1_1, fi_option2);
  tcase_add_test(tc1_1, fi_option3);
  tcase_add_test(tc1_1, fi_option6);
  tcase_add_test(tc1_1, fi_option4);
  tcase_add_test(tc1_1, fi_option5);
  tcase_add_test(tc1_1, fv_option1);
  tcase_add_test(tc1_1, fv_option2);
  tcase_add_test(tc1_1, fv_option3);
  tcase_add_test(tc1_1, fv_option6);
  tcase_add_test(tc1_1, fv_option4);
  tcase_add_test(tc1_1, fv_option5);
  tcase_add_test(tc1_1, fc_option1);
  tcase_add_test(tc1_1, fc_option2);
  tcase_add_test(tc1_1, fc_option3);
  tcase_add_test(tc1_1, fc_option6);
  tcase_add_test(tc1_1, fc_option4);
  tcase_add_test(tc1_1, fc_option5);
  tcase_add_test(tc1_1, fl_option1);
  tcase_add_test(tc1_1, fl_option2);
  tcase_add_test(tc1_1, fl_option3);
  tcase_add_test(tc1_1, fl_option6);
  tcase_add_test(tc1_1, fl_option4);
  tcase_add_test(tc1_1, fl_option5);
  tcase_add_test(tc1_1, fn_option1);
  tcase_add_test(tc1_1, fn_option2);
  tcase_add_test(tc1_1, fn_option3);
  tcase_add_test(tc1_1, fn_option6);
  tcase_add_test(tc1_1, fn_option4);
  tcase_add_test(tc1_1, fn_option5);
  tcase_add_test(tc1_1, fh_option1);
  tcase_add_test(tc1_1, fh_option2);
  tcase_add_test(tc1_1, fh_option3);
  tcase_add_test(tc1_1, fh_option6);
  tcase_add_test(tc1_1, fh_option4);
  tcase_add_test(tc1_1, fh_option5);
  tcase_add_test(tc1_1, o_option1);
  tcase_add_test(tc1_1, o_option2);
  tcase_add_test(tc1_1, o_option3);
  tcase_add_test(tc1_1, o_option6);
  tcase_add_test(tc1_1, o_option4);
  tcase_add_test(tc1_1, o_option5);
  tcase_add_test(tc1_1, oe_option1);
  tcase_add_test(tc1_1, oe_option2);
  tcase_add_test(tc1_1, oe_option3);
  tcase_add_test(tc1_1, oe_option6);
  tcase_add_test(tc1_1, oe_option4);
  tcase_add_test(tc1_1, oi_option1);
  tcase_add_test(tc1_1, oi_option2);
  tcase_add_test(tc1_1, oi_option3);
  tcase_add_test(tc1_1, ov_option1);
  tcase_add_test(tc1_1, ov_option2);
  tcase_add_test(tc1_1, ov_option3);
  tcase_add_test(tc1_1, ol_option1);
  tcase_add_test(tc1_1, ol_option2);
  tcase_add_test(tc1_1, ol_option3);
  tcase_add_test(tc1_1, on_option1);
  tcase_add_test(tc1_1, on_option2);
  tcase_add_test(tc1_1, on_option3);
  tcase_add_test(tc1_1, oh_option1);
  tcase_add_test(tc1_1, oh_option2);
  tcase_add_test(tc1_1, oh_option3);
  tcase_add_test(tc1_1, os_option1);
  tcase_add_test(tc1_1, os_option2);
  tcase_add_test(tc1_1, os_option3);
  tcase_add_test(tc1_1, of_option1);
  tcase_add_test(tc1_1, of_option2);
  tcase_add_test(tc1_1, of_option3);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
