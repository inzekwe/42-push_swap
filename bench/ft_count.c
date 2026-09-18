/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:23:34 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/06 17:34:14 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_counter(int *counter)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		counter[i] = 0;
		i++;
	}
}

void	count_operation(int *counter, int op)
{
	counter[op]++;
	counter[TOTAL_OPS]++;
}
