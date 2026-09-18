/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:26:56 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:26:58 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_dprintf.h"

int	ft_print_hex(unsigned int n, int uppercase, int fd)
{
	char	*base;
	int		r;

	r = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		r += ft_print_hex(n / 16, uppercase, fd);
	r += ft_print_char(base[n % 16], fd);
	return (r);
}
