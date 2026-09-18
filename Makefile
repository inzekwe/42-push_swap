NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude -Ilibftprintf

SRCS = main.c \
       bench/ft_count.c \
	   bench/ft_bench.c \
	   bench/ft_computer_disorder.c \
       operations/ft_swap.c \
       operations/ft_push.c \
       operations/ft_rotate.c \
       operations/ft_reverse.c \
	   parse/ft_parse_args.c \
	   parse/ft_parse_utils.c \
	   parse/ft_parse_flags.c \
	   utils/ft_strdup.c \
       utils/ft_strjoin.c \
       utils/ft_split.c \
	   utils/ft_substr.c \
	   utils/ft_strlen.c \
	   utils/ft_strcmp.c \
	   sort/ft_push_swap.c \
	   sort/ft_build_rank_map.c \
	   sort/ft_chunks_helper.c \
	   sort/ft_push_chunks.c \
	   sort/ft_push_swap_medium.c \
	   sort/ft_restore_max.c \
	   sort/ft_dispatch.c \
	   sort/ft_normalize.c \
	   sort/ft_push_swap_adaptive.c \
	   sort/ft_rotate_exec.c \
	   sort/ft_push_swap_complex.c \
	   sort/ft_radix_lsd.c \
	   sort/ft_push_swap_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libftprintf
	$(CC) $(CFLAGS) $(OBJS) libftprintf/libftprintf.a -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libftprintf

fclean: clean
	rm -f $(NAME)
	make fclean -C libftprintf

re: fclean all