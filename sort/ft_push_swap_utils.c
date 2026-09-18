/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:57:00 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/20 14:04:02 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_sorted(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_min_index(int *a, int size_a)
{
	int	i;
	int	min_i;

	min_i = 0;
	i = 1;
	while (i < size_a)
	{
		if (a[i] < a[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

void	ft_sort_three(t_stack *stack)
{
	int	*a;

	a = stack->a;
	if (a[0] < a[1] && a[1] < a[2])
		return ;
	if (a[1] < a[0] && a[0] < a[2])
		sa(stack);
	else if (a[2] < a[1] && a[1] < a[0])
	{
		sa(stack);
		rra(stack);
	}
	else if (a[2] < a[0] && a[0] < a[1])
		rra(stack);
	else if (a[1] < a[2] && a[2] < a[0])
		ra(stack);
	else
	{
		rra(stack);
		sa(stack);
	}
}
