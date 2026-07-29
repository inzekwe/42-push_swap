/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:29:30 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/21 18:44:03 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_data
{
	t_stack	**a;
	t_stack	**b;
	t_bench	*bench;
	int		argc;
	char	**argv;
	char	*strategy;
	char	*used_strategy;
	float	disorder;
}	t_data;

/* utils.c */
int			ft_size(t_stack *stack);
int			ft_min_position(t_stack *stack, int *position);
int			ft_min_value(t_stack *stack);
int			ft_max_value(t_stack *stack);
int			ft_isqrt(int n);

/* utils2.c */
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(long n, int fd);
void		ft_put_disorder(float disorder, int fd);

/* utils3.c */
void		ft_free_stack(t_stack **stack);

/* utils4.c */
int			ft_is_sorted(t_stack *a);

/* operations_swap.c */
void		ft_sa(t_stack **a, t_bench *bench);
void		ft_sb(t_stack **b, t_bench *bench);
void		ft_ss(t_stack **a, t_stack **b, t_bench *bench);

/* operations_push.c */
void		ft_pa(t_stack **a, t_stack **b, t_bench *bench);
void		ft_pb(t_stack **a, t_stack **b, t_bench *bench);

/* operations_rotate.c */
void		ft_ra(t_stack **a, t_bench *bench);
void		ft_rb(t_stack **b, t_bench *bench);
void		ft_rr(t_stack **a, t_stack **b, t_bench *bench);

/* operations_reverse_rotate.c */
void		ft_rra(t_stack **a, t_bench *bench);
void		ft_rrb(t_stack **b, t_bench *bench);
void		ft_rrr(t_stack **a, t_stack **b, t_bench *bench);

/* parsing.c */
int			ft_is_valid_number(char *str);
int			ft_validate_args(int argc, char **argv);

/* parsing2.c */
int			ft_has_duplicate(t_stack *a);
t_stack		*ft_new_node(int value);
t_stack		*ft_create_stack(int argc, char **argv);

/* disorder.c */
float		ft_disorder(t_stack *a);

/* sort_simple.c */
void		ft_sort_simple(t_stack **a, t_stack **b, t_bench *bench);

/* sort_medium.c */
void		ft_sort_medium(t_stack **a, t_stack **b, t_bench *bench);

/* radix_utils.c */
void		ft_set_rank(t_stack *a);
int			ft_max_bits(int size);

/* sort_complex.c */
void		ft_sort_complex(t_stack **a, t_stack **b, t_bench *bench);

/* sort_adaptive.c */
void		ft_sort_adaptive(t_data *data);

/* sort_utils.c */
void		ft_move_to_top(t_stack **a, int position, int size,
				t_bench *bench);

/* bench.c */
int			ft_total_operations(t_bench *bench);
void		ft_print_bench_header(t_bench *bench, float disorder,
				char *strategy);

/* bench2.c */
void		ft_print_bench(t_bench *bench, float disorder, char *strategy);

/* main_utils.c */
void		ft_error(void);
char		*ft_get_strategy(int argc, char **argv);
int			ft_has_flag(int argc, char **argv, char *flag);
int			ft_count_strategy_flags(int argc, char **argv);
void		ft_print_count(t_bench *bench);

#endif
