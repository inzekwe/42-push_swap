/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenhuama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:48:59 by kenhuama          #+#    #+#             */
/*   Updated: 2026/08/05 12:49:04 by kenhuama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_strdup( const char *s)
{
	int		i;
	char	*copy;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	copy = malloc (sizeof(char) * (size_t)i + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
