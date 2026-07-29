/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:32:14 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:32:15 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_move_to_top(t_stack **a, int position, int size, t_bench *bench)
{
	int	i;

	if (position <= size / 2)
	{
		i = 0;
		while (i < position)
		{
			ft_ra(a, bench);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (size - position))
		{
			ft_rra(a, bench);
			i++;
		}
	}
}
