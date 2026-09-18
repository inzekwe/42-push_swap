/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <inzekwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:27:57 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/15 16:13:29 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	validate_arg(char *str, int *arr, int idx, int *num)
{
	long	value;

	if (!is_valid_number(str))
		return (0);
	value = parse_long(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (has_duplicate(arr, idx, (int)value))
		return (0);
	*num = (int)value;
	return (1);
}

static int	*build_array(char **words, int *size)
{
	int	i;
	int	*arr;
	int	num;

	i = 0;
	while (words[i])
		i++;
	*size = i;
	arr = malloc(sizeof(int) * i);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		if (!validate_arg(words[i], arr, i, &num))
		{
			free(arr);
			return (NULL);
		}
		arr[i] = num;
		i++;
	}
	return (arr);
}

static void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	*ft_parse_args(char **argv, int start, int *size)
{
	char	*joined;
	char	**words;
	int		*arr;

	joined = join_args(argv, start);
	if (!joined)
		return (NULL);
	words = ft_split(joined, ' ');
	free(joined);
	if (!words)
		return (NULL);
	arr = build_array(words, size);
	free_words(words);
	return (arr);
}
