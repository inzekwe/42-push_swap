/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:30:22 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:30:23 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_fill_bench_values(t_bench *bench, int *values)
{
	values[0] = bench->sa;
	values[1] = bench->sb;
	values[2] = bench->ss;
	values[3] = bench->pa;
	values[4] = bench->pb;
	values[5] = bench->ra;
	values[6] = bench->rb;
	values[7] = bench->rr;
	values[8] = bench->rra;
	values[9] = bench->rrb;
	values[10] = bench->rrr;
}

static void	ft_fill_bench_labels(char **labels)
{
	labels[0] = "sa: ";
	labels[1] = "sb: ";
	labels[2] = "ss: ";
	labels[3] = "pa: ";
	labels[4] = "pb: ";
	labels[5] = "ra: ";
	labels[6] = "rb: ";
	labels[7] = "rr: ";
	labels[8] = "rra: ";
	labels[9] = "rrb: ";
	labels[10] = "rrr: ";
}

static void	ft_print_bench_counts(int *values)
{
	char	*labels[11];
	int		i;

	ft_fill_bench_labels(labels);
	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(labels[i], 2);
		ft_putnbr_fd(values[i], 2);
		ft_putstr_fd(" ", 2);
		i++;
	}
}

void	ft_print_bench(t_bench *bench, float disorder, char *strategy)
{
	int	values[11];

	ft_print_bench_header(bench, disorder, strategy);
	ft_fill_bench_values(bench, values);
	ft_print_bench_counts(values);
	ft_putstr_fd("\n", 2);
}
