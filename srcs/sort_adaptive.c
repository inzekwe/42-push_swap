/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:31:53 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:54 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_adaptive(t_data *data)
{
	if (data->disorder < 0.2)
	{
		data->used_strategy = "simple";
		ft_sort_simple(data->a, data->b, data->bench);
	}
	else if (data->disorder < 0.5)
	{
		data->used_strategy = "medium";
		ft_sort_medium(data->a, data->b, data->bench);
	}
	else
	{
		data->used_strategy = "complex";
		ft_sort_complex(data->a, data->b, data->bench);
	}
}
