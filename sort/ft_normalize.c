/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:55:48 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:55:50 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*ft_normalize(int *a, int size)
{
	int	*rank;
	int	i;
	int	j;
	int	count;

	rank = malloc(sizeof(int) * size);
	if (!rank)
		return (NULL);
	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (a[j] < a[i])
				count++;
			j++;
		}
		rank[i] = count;
		i++;
	}
	return (rank);
}
