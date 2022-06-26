/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:53:02 by atouati           #+#    #+#             */
/*   Updated: 2021/12/07 00:11:04 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_print_all(const char *str, va_list arg, int i)
{
	if (str[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (str[i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (str[i] == 'x')
		return (ft_hexadecimal_x(va_arg(arg, unsigned int), 'x'));
	else if (str[i] == 'X')
		return (ft_hexadecimal_x(va_arg(arg, unsigned int), 'X'));
	else if (str[i] == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int)));
	else if (str[i] == 'p')
	{
		ft_putstr("0x");
		return (ft_pointer(va_arg(arg, unsigned long)) + 2);
	}
	else if (str[i] == '%')
		return (ft_putchar(str[i]));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_print_all(str, arg, i);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

//int	main(void)
//{
//	//int	i = 14514;
//	printf("\nthis is len  %d\n", printf("%s  %x tttttt %%", NULL, -3));
//}
//