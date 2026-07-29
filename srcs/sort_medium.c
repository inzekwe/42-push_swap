/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:32:02 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:32:03 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_coarse_pass(t_data *data, int size, int bit)
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

static void	ft_coarse_group(t_data *data, int size)
{
	int	total_bits;
	int	half_bits;
	int	bit;

	total_bits = ft_max_bits(size);
	half_bits = (total_bits + 1) / 2;
	bit = total_bits - 1;
	while (bit >= total_bits - half_bits && bit >= 0)
	{
		ft_coarse_pass(data, size, bit);
		bit--;
	}
}

void	ft_sort_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	t_data	data;
	int		size;

	data.a = a;
	data.b = b;
	data.bench = bench;
	size = ft_size(*a);
	ft_set_rank(*a);
	ft_coarse_group(&data, size);
	ft_sort_simple(a, b, bench);
}
