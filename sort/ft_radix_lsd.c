/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_lsd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:57:16 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/21 13:36:14 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_count_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

static void	ft_radix_pass(t_stack *stack, int bit)
{
	int	i;
	int	size;

	size = stack->size_a + stack->size_b;
	i = 0;
	while (i < size)
	{
		if (((stack->a[0] >> bit) & 1) == 0)
			pb(stack);
		else
			ra(stack);
		i++;
	}
	while (stack->size_b > 0)
		pa(stack);
}

void	ft_radix_lsd(t_stack *stack, int *rank, int size)
{
	int	bits;
	int	bit;
	int	i;

	i = 0;
	while (i < size)
	{
		stack->a[i] = rank[i];
		i++;
	}
	bits = ft_count_bits(size);
	bit = 0;
	while (bit < bits)
	{
		ft_radix_pass(stack, bit);
		bit++;
	}
}
