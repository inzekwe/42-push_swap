/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:23:49 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:23:52 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_isqrt(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

int	ft_get_rank(int val, t_rank_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map[i].value == val)
			return (map[i].rank);
		i++;
	}
	return (-1);
}

int	ft_in_chunk(int rank, int chunk, int chunk_size)
{
	return (rank >= chunk * chunk_size
		&& rank <= chunk * chunk_size + chunk_size - 1);
}
