/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:28:23 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/15 15:54:51 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	parse_long(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	has_duplicate(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

char	*join_args(char **argv, int start)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup(argv[start]);
	if (!result)
		return (NULL);
	i = start + 1;
	while (argv[i])
	{
		tmp = result;
		result = ft_strjoin(result, " ");
		free(tmp);
		if (!result)
			return (NULL);
		tmp = result;
		result = ft_strjoin(result, argv[i]);
		free(tmp);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}
