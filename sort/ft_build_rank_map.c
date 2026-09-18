/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_rank_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:52:17 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:52:19 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_rank_map	*ft_build_map(int *a, int *ranks, int size)
{
	t_rank_map	*map;
	int			i;

	map = malloc(sizeof(t_rank_map) * size);
	if (!map)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i].value = a[i];
		map[i].rank = ranks[i];
		i++;
	}
	return (map);
}
