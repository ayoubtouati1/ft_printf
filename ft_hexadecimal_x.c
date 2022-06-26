/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:05:37 by atouati           #+#    #+#             */
/*   Updated: 2021/12/05 22:43:13 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	len_n(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_hexadecimal_x(unsigned int n, char base)
{
	char	*str;
	int		len;

	len = len_n(n);
	if (base == 'x')
	{
		str = "0123456789abcdef";
	}
	if (base == 'X')
	{
		str = "0123456789ABCDEF";
	}
	if (n >= 16)
		ft_hexadecimal_x(n / 16, base);
	ft_putchar(str[n % 16]);
	return (len);
}
