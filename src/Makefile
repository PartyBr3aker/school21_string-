all:test
test:s21_string.a test.o 
	gcc -Wall -Werror -Wextra string_test.o -o test.out -lcheck -lm -pthread -lrt -L. -ls21
test.o:
	gcc -Wall -Werror -Wextra -c string_test.c
rebuild:clean test
clean:
	rm -rf *.o *.out *.a
s21_string.a:
	gcc -c s21*.c
	ar rc libs21.a s21*.o
	ranlib libs21.a
