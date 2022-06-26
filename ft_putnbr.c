/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:08:01 by atouati           #+#    #+#             */
/*   Updated: 2021/12/06 10:54:48 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	len_n(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = len_n(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (len);
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n < 10)
	{
		n = n + 48;
		ft_putchar(n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (len);
}
