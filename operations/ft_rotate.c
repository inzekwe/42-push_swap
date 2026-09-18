/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:51:21 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:51:23 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	do_ra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->size_a < 2)
		return ;
	tmp = stack->a[0];
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = tmp;
}

static void	do_rb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = tmp;
}

void	ra(t_stack *stack)
{
	do_ra(stack);
	if (!stack->total_count)
		ft_dprintf(1, "ra\n");
	count_operation(stack->counter, RA);
}

void	rb(t_stack *stack)
{
	do_rb(stack);
	if (!stack->total_count)
		ft_dprintf(1, "rb\n");
	count_operation(stack->counter, RB);
}

void	rr(t_stack *stack)
{
	do_ra(stack);
	do_rb(stack);
	if (!stack->total_count)
		ft_dprintf(1, "rr\n");
	count_operation(stack->counter, RR);
}
