/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:30:41 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/21 18:44:45 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_run_strategy(t_data *data)
{
	data->used_strategy = data->strategy;
	if (ft_strcmp(data->strategy, "simple") == 0)
		ft_sort_simple(data->a, data->b, data->bench);
	else if (ft_strcmp(data->strategy, "medium") == 0)
		ft_sort_medium(data->a, data->b, data->bench);
	else if (ft_strcmp(data->strategy, "complex") == 0)
		ft_sort_complex(data->a, data->b, data->bench);
	else
		ft_sort_adaptive(data);
}

static void	ft_finalize(t_data *data)
{
	if (ft_has_flag(data->argc, data->argv, "--bench"))
		ft_print_bench(data->bench, data->disorder, data->used_strategy);
	ft_free_stack(data->a);
}

static void	ft_init_data(t_data *data, t_stack **a, t_stack **b,
				t_bench *bench)
{
	data->a = a;
	data->b = b;
	data->bench = bench;
}

static t_stack	*ft_parse_or_die(int argc, char **argv)
{
	t_stack	*a;

	if (ft_count_strategy_flags(argc, argv) > 1)
		ft_error();
	if (!ft_validate_args(argc, argv))
		ft_error();
	a = ft_create_stack(argc, argv);
	if (a == NULL)
		return (NULL);
	if (ft_has_duplicate(a))
	{
		ft_free_stack(&a);
		ft_error();
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	t_data	data;

	if (argc == 1)
		return (0);
	a = ft_parse_or_die(argc, argv);
	if (a == NULL)
		return (0);
	bench = (t_bench){0};
	b = NULL;
	ft_init_data(&data, &a, &b, &bench);
	data.argc = argc;
	data.argv = argv;
	data.strategy = ft_get_strategy(argc, argv);
	data.used_strategy = data.strategy;
	data.disorder = ft_disorder(a);
	if (!ft_is_sorted(a))
		ft_run_strategy(&data);
	ft_finalize(&data);
	return (0);
}
