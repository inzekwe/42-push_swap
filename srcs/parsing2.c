/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:31:45 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:46 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_has_duplicate(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static void	ft_stack_append(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

t_stack	*ft_create_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || argv[i][1] != '-')
		{
			new_node = ft_new_node(ft_atoi(argv[i]));
			if (new_node == NULL)
				return (NULL);
			ft_stack_append(&stack, new_node);
		}
		i++;
	}
	return (stack);
}
