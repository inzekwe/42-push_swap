/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restore_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:57:24 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:57:26 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_find_max_index_b(t_stack *stack)
{
	int	i;
	int	max_i;

	max_i = 0;
	i = 1;
	while (i < stack->size_b)
	{
		if (stack->b[i] > stack->b[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}

void	ft_restore_max(t_stack *stack)
{
	t_rotate	rot;
	int			max_i;

	while (stack->size_b > 0)
	{
		max_i = ft_find_max_index_b(stack);
		rot = ft_get_rotate(max_i, stack->size_b);
		ft_rotate_remaining_b(stack, rot);
		pa(stack);
	}
}
