/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:26:41 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:26:44 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_dprintf.h"

int	ft_print_decimal(long long n, int fd)
{
	long long	num;
	int			r;

	r = 0;
	num = 0;
	if (n < 0)
	{
		r++;
		write (fd, "-", 1);
		num = n * -1;
	}
	else
		num = n;
	if (num >= 10)
		r += ft_print_decimal (num / 10, fd);
	r += ft_print_char ((num % 10 + '0'), fd);
	return (r);
}
