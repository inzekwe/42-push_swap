/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:25:28 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:25:31 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	aux_specifier(int fd, char s, va_list *args)
{
	if (s == 'c')
		return (ft_print_char(va_arg(*args, int), fd));
	else if (s == 's')
		return (ft_print_str(va_arg(*args, char *), fd));
	else if (s == 'd')
		return (ft_print_decimal(va_arg(*args, int), fd));
	else if (s == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int), fd));
	else if (s == 'i')
		return (ft_print_decimal(va_arg(*args, int), fd));
	else if (s == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0, fd));
	else if (s == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1, fd));
	else if (s == '%')
		return (ft_print_per(fd));
	else if (s == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(*args, void *), fd));
	return (0);
}

int	ft_dprintf(int fd, const char *specifier, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, specifier);
	while (*specifier)
	{
		if (*specifier == '%')
		{
			specifier++;
			count += aux_specifier(fd, *specifier, &args);
		}
		else
		{
			count++;
			write(fd, &(*specifier), 1);
		}
		specifier++;
	}
	va_end(args);
	return (count);
}
