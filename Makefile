NAME = push_swap

SRCS = srcs/main.c \
       srcs/main_utils.c \
       srcs/utils.c \
       srcs/utils2.c \
       srcs/utils3.c \
       srcs/utils4.c \
       srcs/operations_swap.c \
       srcs/operations_push.c \
       srcs/operations_rotate.c \
       srcs/operations_reverse_rotate.c \
       srcs/parsing.c \
       srcs/parsing2.c \
       srcs/disorder.c \
       srcs/sort_simple.c \
       srcs/sort_medium.c \
       srcs/sort_complex.c \
       srcs/radix_utils.c \
       srcs/sort_adaptive.c \
       srcs/sort_utils.c \
       srcs/bench.c \
       srcs/bench2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
