/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:27:28 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:27:30 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_dprintf.h"

static int	ft_print_aux_ptr(unsigned long n, int fd)
{
	char	*base;
	int		r;

	base = "0123456789abcdef";
	r = 0;
	if (n >= 16)
		r += ft_print_aux_ptr(n / 16, fd);
	r += ft_print_char(base[n % 16], fd);
	return (r);
}

int	ft_print_ptr(unsigned long long n, int fd)
{
	int	sgn;

	sgn = 0;
	if (n == 0)
	{
		write (fd, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	sgn = ft_print_aux_ptr(n, fd);
	return (sgn + 2);
}
