/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:51:10 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:51:12 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	do_sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
}

static void	do_sb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
}

void	sa(t_stack *stack)
{
	do_sa(stack);
	if (!stack->total_count)
		ft_dprintf(1, "sa\n");
	count_operation(stack->counter, SA);
}

void	sb(t_stack *stack)
{
	do_sb(stack);
	if (!stack->total_count)
		ft_dprintf(1, "sb\n");
	count_operation(stack->counter, SB);
}

void	ss(t_stack *stack)
{
	do_sa(stack);
	do_sb(stack);
	if (!stack->total_count)
		ft_dprintf(1, "ss\n");
	count_operation(stack->counter, SS);
}
