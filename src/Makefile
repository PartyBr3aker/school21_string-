CC=gcc
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
DIR_OUT=../s21_string/
SRCS =  s21_string/s21_memchr.c \
		s21_string/s21_memcmp.c \
		s21_string/s21_memcpy.c \
		s21_string/s21_memmove.c \
		s21_string/s21_strcat.c \
		s21_string/s21_strchr.c \
		s21_string/s21_strcmp.c \
		s21_string/s21_strcpy.c \
		s21_string/s21_strcspn.c \
		s21_string/s21_strerror.c \
		s21_string/s21_strlen.c \
		s21_string/s21_strncat.c \
		s21_string/s21_strncpy.c \
		s21_string/s21_strpbrk.c \
		s21_string/s21_strrchr.c \
		s21_string/s21_strspn.c \
		s21_string/s21_strstr.c \
		s21_string_tests/s21_string_tests.c
OBJS = $(SRCS:.c=.o)
NAME = test
REPORT_NAME = report

all: s21_string.a gcov_report
	make test
%.o: %.c
	$(CC) $(CFLAGS) $(CHECK_FLAGS) -c $< -o $@
test: $(OBJS)
	$(CC) $(CFLAGS) $(CHECK_FLAGS) $(OBJS) -o $(NAME)
	make clean
clean_all:
	rm -rf $(OBJS)
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
	rm $(NAME)
	rm -rf *.a
	rm -rf $(REPORT_NAME)
clean:
	rm -rf $(OBJS)
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
s21_string.a: $(OBJS)
	ar rc s21_string.a $(OBJS)
	ranlib s21_string.a
gcov_report:
	$(CC) -o $(NAME) $(SRCS) $(ALL_FLAGS)
	./$(NAME)
	~/homebrew/bin/lcov -t "gcov_report" -o s21_string_tests.info -c -d .
	~/homebrew/bin/genhtml -o $(REPORT_NAME) s21_string_tests.info
	rm $(NAME)
	make clean
