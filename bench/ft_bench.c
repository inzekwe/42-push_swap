/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:22:55 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/11 17:28:21 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_print_disorder(float disorder)

{
	int	decimal;
	int	pdecimal;

	decimal = (int)(disorder * 100);
	pdecimal = (int)(disorder * 10000) % 100;
	if (pdecimal < 10)
		ft_dprintf(2, "[bench] disorder: %d.0%d%%\n", decimal, pdecimal);
	else
		ft_dprintf(2, "[bench] disorder: %d.%d%%\n", decimal, pdecimal);
}

static char	*ft_get_strategy_name(int strategy, float disorder)
{
	if (strategy == SIMPLE)
		return ("Select-Sort / O(n²)");
	if (strategy == MEDIUM)
		return ("Chunk-sort / O(n√n)");
	if (strategy == COMPLEX)
		return ("Radix-lsd / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

void	ft_print_bench(int *counter, int strategy, float disorder)
{
	char	*name;

	name = ft_get_strategy_name(strategy, disorder);
	ft_print_disorder(disorder);
	ft_dprintf(2, "[bench] strategy: %s\n", name);
	ft_dprintf(2, "[bench] total_ops: %d\n", counter[TOTAL_OPS]);
	ft_dprintf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		counter[SA], counter[SB], counter[SS], counter[PA], counter[PB]);
	ft_dprintf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		counter[RA], counter[RB], counter[RR], counter[RRA], counter[RRB],
		counter[RRR]);
}

void	ft_print_count(int *counter)
{
	ft_dprintf(2, "[count] total_ops: %d\n", counter[TOTAL_OPS]);
}
