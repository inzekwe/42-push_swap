/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_medium.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:00:13 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 13:00:16 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_swap_medium(t_stack *stack)
{
	int			*ranks;
	t_rank_map	*rank_map;

	ranks = ft_normalize(stack->a, stack->size_a);
	if (!ranks)
		return ;
	rank_map = ft_build_map(stack->a, ranks, stack->size_a);
	free(ranks);
	if (!rank_map)
		return ;
	ft_push_chunks(stack, rank_map);
	ft_sort_three(stack);
	ft_restore_max(stack);
	free(rank_map);
}
