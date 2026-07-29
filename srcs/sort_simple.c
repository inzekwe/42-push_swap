/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:32:09 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:32:10 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	position;

	size = ft_size(*a);
	while (size > 1)
	{
		ft_min_position(*a, &position);
		ft_move_to_top(a, position, size, bench);
		ft_pb(a, b, bench);
		size--;
	}
	while (*b != NULL)
		ft_pa(a, b, bench);
}
