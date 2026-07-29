/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:30:52 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:30:53 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_reverse_rotate_stack(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *stack;
	second_last->next = NULL;
	*stack = last;
}

void	ft_rra(t_stack **a, t_bench *bench)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	ft_reverse_rotate_stack(a);
	bench->rra++;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **b, t_bench *bench)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	ft_reverse_rotate_stack(b);
	bench->rrb++;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	if (*a != NULL && (*a)->next != NULL)
		ft_reverse_rotate_stack(a);
	if (*b != NULL && (*b)->next != NULL)
		ft_reverse_rotate_stack(b);
	bench->rrr++;
	ft_putstr_fd("rrr\n", 1);
}
