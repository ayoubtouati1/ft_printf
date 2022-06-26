/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:35:02 by atouati           #+#    #+#             */
/*   Updated: 2021/12/07 00:09:03 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	len_n(unsigned long n)
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

int	ft_pointer(unsigned long n)
{
	char	*str;
	int		len;

	len = len_n(n);
	str = "0123456789abcdef";
	if (n >= 16)
		ft_pointer(n / 16);
	ft_putchar(str[n % 16]);
	return (len);
}
