/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:30:14 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:30:15 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_total_operations(t_bench *bench)
{
	return (bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra
		+ bench->rrb + bench->rrr);
}

static char	*ft_get_complexity(char *strategy)
{
	if (ft_strcmp(strategy, "simple") == 0)
		return ("O(n^2)");
	else if (ft_strcmp(strategy, "medium") == 0)
		return ("O(n * sqrt(n))");
	else if (ft_strcmp(strategy, "complex") == 0)
		return ("O(n log n)");
	return ("Adaptive");
}

void	ft_print_bench_header(t_bench *bench, float disorder, char *strategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_put_disorder(disorder, 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(ft_get_complexity(strategy), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(ft_total_operations(bench), 2);
	ft_putstr_fd("\n[bench] ", 2);
}
