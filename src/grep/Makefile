CC=gcc
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS =-lcheck
SRC_GREP = s21_grep.c
SRC_TEST = s21_grep_test.c
OBJS_GREP =$(SRC_GREP:.c=.o)
OBJS_TEST =$(SRC_TEST:.c=.o)
NAME_GREP = s21_grep
NAME_TEST = test
all: s21_grep
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
s21_grep: $(OBJS_GREP)
	$(CC) $(CFLAGS) -o $(NAME_GREP) $(OBJS_GREP)
test_grep: s21_grep $(OBJS_TEST)
	$(CC) $(CFLAGS) $(CHECK_FLAGS) -o $(NAME_TEST) $(OBJS_TEST)
	./$(NAME_TEST)
report:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $(SRC_GREP) -o $(OBJS_GREP)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS) -c $(SRC_TEST) -o $(OBJS_TEST)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $(NAME_GREP) $(OBJS_GREP)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS) -o $(NAME_TEST) $(OBJS_TEST)
	./$(NAME_TEST)
	geninfo *.gcda *.gcno -b . -o check_res 
	genhtml check_res -o gcov_test
clean:
	rm -rf $(OBJS_GREP)
	rm -rf $(OBJS_TEST)
	rm -rf $(NAME_GREP)
	rm -rf $(NAME_TEST)
	rm -rf a
	rm -rf b
	rm -rf check_res
	rm -rf gcov_test
	rm -rf *.gcda *.gcno
