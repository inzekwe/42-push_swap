/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inzekwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:25:48 by inzekwe           #+#    #+#             */
/*   Updated: 2026/08/21 15:25:56 by inzekwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_dprintf(int fd, const char *format, ...);
int	ft_print_char(char c, int fd);
int	ft_print_per(int fd);
int	ft_print_str(char *s, int fd);
int	ft_print_decimal(long long n, int fd);
int	ft_print_unsigned(unsigned int n, int fd);
int	ft_print_hex(unsigned int n, int uppercase, int fd);
int	ft_print_ptr(unsigned long long n, int fd);

#endif
