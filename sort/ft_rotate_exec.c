/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:24:22 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:24:24 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate_remaining_b(t_stack *stack, t_rotate rot)
{
	while (rot.qty > 0)
	{
		if (rot.dir == UP)
			rb(stack);
		else
			rrb(stack);
		rot.qty--;
	}
}

t_rotate	ft_get_rotate(int index, int size)
{
	t_rotate	rot;

	if (index <= size / 2)
	{
		rot.qty = index;
		rot.dir = UP;
	}
	else
	{
		rot.qty = size - index;
		rot.dir = DOWN;
	}
	return (rot);
}
