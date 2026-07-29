/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:31:28 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:29 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rotate_stack(t_stack **stack)
{
	t_stack	*old_first;
	t_stack	*current;

	old_first = *stack;
	current = old_first->next;
	*stack = current;
	while (current->next != NULL)
		current = current->next;
	current->next = old_first;
	old_first->next = NULL;
}

void	ft_ra(t_stack **a, t_bench *bench)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	ft_rotate_stack(a);
	bench->ra++;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **b, t_bench *bench)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	ft_rotate_stack(b);
	bench->rb++;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **a, t_stack **b, t_bench *bench)
{
	if (*a != NULL && (*a)->next != NULL)
		ft_rotate_stack(a);
	if (*b != NULL && (*b)->next != NULL)
		ft_rotate_stack(b);
	bench->rr++;
	ft_putstr_fd("rr\n", 1);
}
