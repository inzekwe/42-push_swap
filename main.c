/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:27:34 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/15 14:37:18 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"

static int	ft_init_stack(t_stack *stack, char **argv, int start)
{
	stack->a = ft_parse_args(argv, start, &stack->size_a);
	if (!stack->a)
		return (0);
	stack->b = malloc(sizeof(int) * stack->size_a);
	if (!stack->b)
	{
		free(stack->a);
		return (0);
	}
	stack->size_b = 0;
	init_counter(stack->counter);
	return (1);
}

static int	ft_check_flags(char **argv, t_flags *flags, int *start)
{
	*flags = ft_parse_flags(argv, start);
	if (flags->strategy == FLAG_ERROR)
		return (0);
	if (!argv[*start])
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_flags	flags;
	int		start;

	if (argc < 2)
		return (0);
	if (!ft_check_flags(argv, &flags, &start))
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	if (!ft_init_stack(&stack, argv, start))
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	stack.total_count = flags.print;
	ft_dispatch(&stack, &flags);
	free(stack.a);
	free(stack.b);
	return (0);
}
