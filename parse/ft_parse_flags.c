/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:28:10 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/21 15:20:20 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_is_flag(char *str)
{
	if (str[0] == '-' && str[1] == '-')
		return (1);
	return (0);
}

static void	ft_set_strategy(t_flags *flags, char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		flags->strategy = SIMPLE;
	else if (ft_strcmp(str, "--medium") == 0)
		flags->strategy = MEDIUM;
	else if (ft_strcmp(str, "--complex") == 0)
		flags->strategy = COMPLEX;
	else if (ft_strcmp(str, "--adaptive") == 0)
		flags->strategy = ADAPTIVE;
	else if (ft_strcmp(str, "--bench") == 0)
		flags->bench = 1;
	else
		flags->strategy = FLAG_ERROR;
}

t_flags	ft_parse_flags(char **argv, int *start)
{
	t_flags	flags;
	int		i;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	flags.print = 0;
	i = 1;
	while (argv[i] && ft_is_flag(argv[i]))
	{
		ft_set_strategy(&flags, argv[i]);
		if (flags.strategy == FLAG_ERROR)
			return (flags);
		i++;
	}
	*start = i;
	return (flags);
}
