all:s21_string.a test
	gcc -Wall -Werror -Wextra main.o -o main.out
test:s21_string.o test.o
	gcc -Wall -Werror -Wextra main.o string_test.o -o test.out -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
test.o:
	gcc -Wall -Werror -Wextra -c string_test.c
s21_string.a:s21_string.o
	gcc -Wall -Werror -Wextra main.o -o main.out
s21_string.o:
	gcc -Wall -Werror -Wextra -c main.c
rebuild:clean test
clean:
	rm -rf *.o *.out