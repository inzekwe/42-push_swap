/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarbosa <sbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:31:40 by sbarbosa          #+#    #+#             */
/*   Updated: 2026/07/21 16:25:26 by sbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_check_overflow(long value, int negative)
{
	if (!negative && value > INT_MAX)
		return (0);
	if (negative && value > (long)INT_MAX + 1)
		return (0);
	return (1);
}

int	ft_is_valid_number(char *str)
{
	int		i;
	long	value;
	int		negative;

	i = 0;
	negative = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	value = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		value = value * 10 + (str[i] - '0');
		if (!ft_check_overflow(value, negative))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_strategy(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}

int	ft_validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!ft_is_strategy(argv[i]))
				return (0);
		}
		else if (!ft_is_valid_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
