/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:31:35 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:36 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack **a, t_bench *bench)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	bench->sa++;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **b, t_bench *bench)
{
	t_stack	*first;
	t_stack	*second;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	bench->sb++;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*first;
	t_stack	*second;

	if (*a != NULL && (*a)->next != NULL)
	{
		first = *a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		first = *b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	bench->ss++;
	ft_putstr_fd("ss\n", 1);
}
