/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:27:18 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/15 14:38:51 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_dprintf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef MOVES
#  define SA 0
#  define SB 1
#  define SS 2
#  define PA 3
#  define PB 4
#  define RA 5
#  define RB 6
#  define RR 7
#  define RRA 8
#  define RRB 9
#  define RRR 10
#  define TOTAL_OPS 11
#  define UP 1
#  define DOWN -1
#  define FLAG_ERROR -1
# endif

/* strategy */

# ifndef STRATEGY
#  define SIMPLE 0
#  define MEDIUM 1
#  define COMPLEX 2
#  define ADAPTIVE 3
# endif

/* struct */

typedef struct s_rotate
{
	int			qty;
	int			dir;
}				t_rotate;

typedef struct s_stack
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	int			counter[TOTAL_OPS + 1];
	int			total_count;
}				t_stack;

typedef struct s_flags
{
	int			strategy;
	int			bench;
	int			print;
}				t_flags;

/* flags */

t_flags			ft_parse_flags(char **argv, int *start);

/* rank of the values*/

typedef struct s_rank_map
{
	int			value;
	int			rank;
}				t_rank_map;

/* operations */

void			sa(t_stack *stash);
void			sb(t_stack *stash);
void			ss(t_stack *stash);
void			pa(t_stack *stash);
void			pb(t_stack *stash);
void			ra(t_stack *stash);
void			rb(t_stack *stash);
void			rr(t_stack *stash);
void			rra(t_stack *stash);
void			rrb(t_stack *stash);
void			rrr(t_stack *stash);

/* parser */

int				is_valid_number(char *str);
long			parse_long(char *str);
int				has_duplicate(int *arr, int size, int num);
int				*ft_parse_args(char **argv, int start, int *size);
char			*join_args(char **argv, int start);

/* benchmark */

void			init_counter(int *counter);
void			count_operation(int *counter, int op);
float			ft_compute_disorder(int *a, int size);
void			ft_print_bench(int *counter, int strategy, float disorder);
void			ft_print_count(int *counter);

/* dispatcher */

void			ft_dispatch(t_stack *stack, t_flags *flags);

/* sort - strategies */

void			ft_push_swap(t_stack *stash);
void			ft_push_swap_medium(t_stack *stack);
void			ft_push_chunks(t_stack *stack, t_rank_map *map);
void			ft_push_swap_complex(t_stack *stack);
void			ft_radix_lsd(t_stack *stack, int *normalized, int size);
void			ft_push_swap_adaptive(t_stack *stack, float disorder);

/* sort - helper strategies */

t_rank_map		*ft_build_map(int *a, int *ranks, int size);
int				*ft_normalize(int *a, int size);

/* sort - helpers */

void			ft_sort_three(t_stack *stash);
int				ft_find_min_index(int *a, int size_a);
int				ft_is_sorted(int *a, int size_a);

/* rotate execution */

t_rotate		ft_get_rotate(int index, int size);
void			ft_rotate_remaining_b(t_stack *stack, t_rotate rot);

/* chunks */

typedef struct s_chunk
{
	int	original_size;
	int	chunk_count;
	int	chunk_size;
	int	current;
}	t_chunk;

void			ft_push_chunks(t_stack *stack, t_rank_map *map);
void			ft_restore_max(t_stack *stack);
int				ft_isqrt(int size);
int				ft_get_rank(int val, t_rank_map *map, int size);
int				ft_in_chunk(int rank, int chunk, int chunk_size);

/* utils */

size_t			ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strcmp(char *s1, char *s2);

#endif
