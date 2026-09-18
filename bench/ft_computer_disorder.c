/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_computer_disorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:23:16 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 11:23:18 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

float	ft_compute_disorder(int *a, int size)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}
