CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
SRC_CAT = s21_cat.c
OBJS_CAT = $(SRC_CAT:.c=.o)
NAME_CAT = s21_cat 
all: s21_cat
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
s21_cat: $(OBJS_CAT)
	$(CC) $(CFLAGS) -o $(NAME_CAT) $(OBJS_CAT)
s21_cat_test: s21_cat
	sh s21_cat_test.sh
clean:
	rm -rf $(OBJS_CAT)
	rm -rf $(NAME_CAT)
	rm -rf log.txt