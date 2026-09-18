/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:59:40 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/20 16:16:06 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_is_top3(int rank, int original_size)
{
	return (rank >= original_size - 3);
}

static void	ft_push_one_chunk(t_stack *stack, t_rank_map *map,
	t_chunk *chunk)
{
	int	mid;
	int	to_scan;
	int	rank;

	to_scan = stack->size_a;
	mid = (chunk->current * chunk->chunk_size) + (chunk->chunk_size / 2);
	while (stack->size_a > 3 && to_scan > 0)
	{
		rank = ft_get_rank(stack->a[0], map, chunk->original_size);
		if (ft_in_chunk(rank, chunk->current, chunk->chunk_size)
			&& !ft_is_top3(rank, chunk->original_size))
		{
			pb (stack);
			if (rank < mid)
				rb(stack);
		}
		else
			ra(stack);
		to_scan--;
	}
}

void	ft_push_chunks(t_stack *stack, t_rank_map *map)
{
	t_chunk	chunk;

	chunk.original_size = stack->size_a;
	chunk.chunk_count = ft_isqrt(chunk.original_size);
	chunk.chunk_size = (chunk.original_size + chunk.chunk_count - 1)
		/ chunk.chunk_count;
	chunk.current = 0;
	while (chunk.current < chunk.chunk_count)
	{
		ft_push_one_chunk(stack, map, &chunk);
		chunk.current++;
	}
}
