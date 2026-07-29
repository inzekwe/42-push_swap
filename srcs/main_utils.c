/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:30:35 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/21 18:45:06 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

char	*ft_get_strategy(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			return ("simple");
		if (ft_strcmp(argv[i], "--medium") == 0)
			return ("medium");
		if (ft_strcmp(argv[i], "--complex") == 0)
			return ("complex");
		if (ft_strcmp(argv[i], "--adaptive") == 0)
			return ("adaptive");
		i++;
	}
	return ("adaptive");
}

int	ft_has_flag(int argc, char **argv, char *flag)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], flag) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_strategy_flags(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0
			|| ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0
			|| ft_strcmp(argv[i], "--adaptive") == 0)
			count++;
		i++;
	}
	return (count);
}

void	ft_print_count(t_bench *bench)
{
	ft_putnbr_fd(ft_total_operations(bench), 1);
	ft_putstr_fd("\n", 1);
}
