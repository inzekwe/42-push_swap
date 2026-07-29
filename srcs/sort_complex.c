/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:31:58 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:59 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_process_bit(t_data *data, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*(data->a))->index >> bit) & 1)
			ft_ra(data->a, data->bench);
		else
			ft_pb(data->a, data->b, data->bench);
		i++;
	}
	while (*(data->b) != NULL)
		ft_pa(data->a, data->b, data->bench);
}

void	ft_sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	t_data	data;
	int		size;
	int		bits;
	int		bit;

	data.a = a;
	data.b = b;
	data.bench = bench;
	size = ft_size(*a);
	ft_set_rank(*a);
	bits = ft_max_bits(size);
	bit = 0;
	while (bit < bits)
	{
		ft_process_bit(&data, size, bit);
		bit++;
	}
}
