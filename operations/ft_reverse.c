/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:51:32 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:51:33 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	do_rra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_a < 2)
		return ;
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
}

static void	do_rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b < 2)
		return ;
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
}

void	rra(t_stack *stack)
{
	do_rra(stack);
	if (!stack->total_count)
		ft_dprintf(1, "rra\n");
	count_operation(stack->counter, RRA);
}

void	rrb(t_stack *stack)
{
	do_rrb(stack);
	if (!stack->total_count)
		ft_dprintf(1, "rrb\n");
	count_operation(stack->counter, RRB);
}

void	rrr(t_stack *stack)
{
	do_rra(stack);
	do_rrb(stack);
	if (!stack->total_count)
		ft_dprintf(1, "rrr\n");
	count_operation(stack->counter, RRR);
}
