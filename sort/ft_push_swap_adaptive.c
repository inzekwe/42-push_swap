/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_adaptive.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:56:23 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:56:24 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_swap_adaptive(t_stack *stack, float disorder)
{
	if (disorder < 0.20)
		ft_push_swap(stack);
	else if (disorder < 0.50)
		ft_push_swap_medium(stack);
	else
		ft_push_swap_complex(stack);
}
