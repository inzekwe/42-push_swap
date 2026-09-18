/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:51:00 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/06 18:07:50 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pb(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	if (stack->size_a < 1)
		return ;
	tmp = stack->a[0];
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	(stack->size_a)--;
	(stack->size_b)++;
	if (!stack->total_count)
		ft_dprintf(1, "pb\n");
	count_operation(stack->counter, PB);
}

void	pa(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	if (stack->size_b < 1)
		return ;
	tmp = stack->b[0];
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	i = stack->size_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	(stack->size_a)++;
	(stack->size_b)--;
	if (!stack->total_count)
		ft_dprintf(1, "pa\n");
	count_operation(stack->counter, PA);
}
