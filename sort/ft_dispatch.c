/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:55:33 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:55:37 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	small_case(t_stack *stack)
{
	if (ft_is_sorted(stack->a, stack->size_a))
		return (1);
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
		return (1);
	}
	if (stack->size_a == 3)
	{
		ft_sort_three(stack);
		return (1);
	}
	return (0);
}

void	ft_dispatch(t_stack *stack, t_flags *flags)
{
	float	disorder;

	disorder = ft_compute_disorder(stack->a, stack->size_a);
	if (!small_case(stack))
	{
		if (flags->strategy == SIMPLE)
			ft_push_swap(stack);
		else if (flags->strategy == MEDIUM)
			ft_push_swap_medium(stack);
		else if (flags->strategy == COMPLEX)
			ft_push_swap_complex(stack);
		else
			ft_push_swap_adaptive(stack, disorder);
	}
	if (flags->bench)
		ft_print_bench(stack->counter, flags->strategy, disorder);
	if (flags->print)
		ft_print_count(stack->counter);
}
