/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:57:58 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 03:58:35 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned long long pt)
{
	if (pt >= 16)
	{
		ft_printhex(pt / 16);
		ft_printhex(pt % 16);
	}
	else if (pt >= 10)
		ft_putchar((char)(pt + 87));
	else
		ft_putchar((char)(pt + 48));
}

int	ft_putpointer(unsigned long long pt)
{
	int	len;

	if (pt == 0)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	ft_printhex(pt);
	while (pt > 0)
	{
		pt /= 16;
		len++;
	}
	return (len);
}
