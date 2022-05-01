CC=gcc
CFLAGS=-Wall -Werror -Wextra

SRCS = ft_hooks.c \
		ft_init_objects.c \
		ft_init_objects2.c \
		ft_objects_get_normal.c \
		ft_objects_intersect.c \
		ft_render.c \
		ft_utils.c \
		ft_utils2.c \
		main.c \
		ft_compute_light.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror
NAME = s21_string


all: $(NAME)

%.o: %.c s21_string.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)


clean:
	rm -rf $(OBJS)

test:
s21_string.a:

gcov_report:






