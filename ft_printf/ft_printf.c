/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:39:25 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 02:28:36 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkformat(va_list args, const char format)
{
	int	lettercount;

	lettercount = 0;
	if (format == 'c')
		lettercount += ft_putchar(va_arg(args, int));
	else if (format == 's')
		lettercount += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		lettercount += ft_putpointer(va_arg(args, unsigned long long));
	else if (format == 'i' || format == 'd')
		lettercount += ft_putint(va_arg(args, int));
	else if (format == 'u')
		lettercount += ft_putunint(va_arg(args, unsigned int));
	else if (format == 'x')
		lettercount += ft_puthex(va_arg(args, unsigned long), 0);
	else if (format == 'X')
		lettercount += ft_puthex(va_arg(args, unsigned long), 1);
	else if (format == '%')
		lettercount += ft_putpercent();
	return (lettercount);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		lettercount;
	va_list	args;

	i = 0;
	lettercount = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			lettercount += checkformat(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			lettercount++;
		}
		i++;
	}
	return (lettercount);
}
