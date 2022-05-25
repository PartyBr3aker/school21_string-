CC=gcc
CFLAGS=-Wall -Werror -Wextra -fsanitize=address
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
SRCS =  ../C2_s21_stringplus-0/src/s21_memchr.c \
		../C2_s21_stringplus-0/src/s21_memcmp.c \
		../C2_s21_stringplus-0/src/s21_memcpy.c \
		../C2_s21_stringplus-0/src/s21_memmove.c \
		../C2_s21_stringplus-0/src/s21_memset.c \
		../C2_s21_stringplus-0/src/s21_strcat.c \
		../C2_s21_stringplus-0/src/s21_strchr.c \
		../C2_s21_stringplus-0/src/s21_strcmp.c \
		../C2_s21_stringplus-0/src/s21_strncmp.c \
		../C2_s21_stringplus-0/src/s21_strcpy.c \
		../C2_s21_stringplus-0/src/s21_strcspn.c \
		../C2_s21_stringplus-0/src/s21_strerror.c \
		../C2_s21_stringplus-0/src/s21_strlen.c \
		../C2_s21_stringplus-0/src/s21_strncat.c \
		../C2_s21_stringplus-0/src/s21_strncpy.c \
		../C2_s21_stringplus-0/src/s21_strpbrk.c \
		../C2_s21_stringplus-0/src/s21_strrchr.c \
		../C2_s21_stringplus-0/src/s21_strspn.c \
		../C2_s21_stringplus-0/src/s21_strstr.c \
		../C2_s21_stringplus-0/src/s21_strtok.c \
		../C2_s21_stringplus-0/src/s21_to_upper.c \
		../C2_s21_stringplus-0/src/s21_to_lower.c \
		../C2_s21_stringplus-0/src/s21_insert.c \
		../C2_s21_stringplus-0/src/s21_trim.c \
		../C2_s21_stringplus-0/src/s21_sprintf.c
OBJS = $(SRCS:.c=.o) s21_string_tests.o
OBJST = $(SRCS:.c=.o)
NAME = test
REPORT_NAME = report

all: s21_string.a
	make test
# %.o: %.c
# $(CC) $(CFLAGS) $(CHECK_FLAGS) -c $< -o $@
test: $(OBJS)
	$(CC) $(CFLAGS) $(CHECK_FLAGS) $(OBJS) -o $(NAME)
	make clean
clean_all:
	rm -rf $(OBJS)
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.a
	rm -rf $(REPORT_NAME)
	rm $(NAME)
clean:
	rm -rf $(OBJS)
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
s21_string.a: $(OBJST)
	ar rc s21_string.a $(OBJST)
	ranlib s21_string.a
gcov_report:
	$(CC) -o $(NAME) $(SRCS) s21_string_tests.c $(ALL_FLAGS)
	./$(NAME)
	lcov -t "gcov_report" -o s21_string_tests.info -c -d .
	genhtml -o $(REPORT_NAME) s21_string_tests.info
	rm $(NAME)
	make clean