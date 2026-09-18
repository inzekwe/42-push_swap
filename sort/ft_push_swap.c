/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:56:05 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:56:07 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_rotate_to_top(t_stack *stack, int index)
{
	int	rotations;

	if (index <= stack->size_a / 2)
	{
		rotations = index;
		while (rotations-- > 0)
			ra(stack);
	}
	else
	{
		rotations = stack->size_a - index;
		while (rotations-- > 0)
			rra(stack);
	}
}

static void	ft_selection_sort_push(t_stack *stack)
{
	int	min_index;

	while (stack->size_a > 3)
	{
		min_index = ft_find_min_index(stack->a, stack->size_a);
		ft_rotate_to_top(stack, min_index);
		pb(stack);
	}
}

void	ft_push_swap(t_stack *stack)
{
	ft_selection_sort_push(stack);
	ft_sort_three(stack);
	while (stack->size_b > 0)
		pa(stack);
}
