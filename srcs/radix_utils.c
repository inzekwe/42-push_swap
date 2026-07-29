/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:31:49 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:50 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_set_rank(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = a;
	while (i != NULL)
	{
		rank = 0;
		j = a;
		while (j != NULL)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

int	ft_max_bits(int size)
{
	int	bits;
	int	max_index;

	max_index = size - 1;
	bits = 0;
	while ((1 << bits) <= max_index)
		bits++;
	return (bits);
}
