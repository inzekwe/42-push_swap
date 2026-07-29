/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:30:28 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:30:29 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_count_mistakes(t_stack *i, int *mistakes, int *total_pairs)
{
	t_stack	*j;

	j = i->next;
	while (j != NULL)
	{
		(*total_pairs)++;
		if (i->value > j->value)
			(*mistakes)++;
		j = j->next;
	}
}

float	ft_disorder(t_stack *a)
{
	t_stack	*i;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	while (i != NULL)
	{
		ft_count_mistakes(i, &mistakes, &total_pairs);
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / (float)total_pairs);
}
