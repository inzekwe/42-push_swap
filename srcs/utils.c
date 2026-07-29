/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:32:18 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:32:19 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_min_position(t_stack *stack, int *position)
{
	int	i;
	int	min;

	i = 0;
	min = stack->value;
	*position = 0;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			*position = i;
		}
		stack = stack->next;
		i++;
	}
	return (min);
}

int	ft_min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	ft_max_value(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	ft_isqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i);
}
