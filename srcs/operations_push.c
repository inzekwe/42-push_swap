/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:30:46 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:30:47 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*top_a;
	t_stack	*top_b;

	if (*b == NULL)
		return ;
	top_a = *a;
	top_b = *b;
	*b = top_b->next;
	top_b->next = top_a;
	*a = top_b;
	bench->pa++;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*top_a;
	t_stack	*top_b;

	if (*a == NULL)
		return ;
	top_a = *a;
	top_b = *b;
	*a = top_a->next;
	top_a->next = top_b;
	*b = top_a;
	bench->pb++;
	ft_putstr_fd("pb\n", 1);
}
