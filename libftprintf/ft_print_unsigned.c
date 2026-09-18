/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:27:54 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:27:56 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_dprintf.h"

int	ft_print_unsigned(unsigned int n, int fd)
{
	int				r;
	unsigned long	num;

	r = 0;
	num = 0;
	num = n;
	if (num >= 10)
		r += ft_print_unsigned(num / 10, fd);
	r += ft_print_char(num % 10 + '0', fd);
	return (r);
}
