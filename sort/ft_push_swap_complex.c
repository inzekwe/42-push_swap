/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_complex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:56:45 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/21 13:09:25 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_swap_complex(t_stack *stack)
{
	int	*rank;
	int	size;

	size = stack->size_a;
	rank = ft_normalize(stack->a, size);
	if (!rank)
		return ;
	ft_radix_lsd(stack, rank, size);
	free(rank);
}
