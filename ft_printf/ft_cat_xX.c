/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 04:04:24 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 04:08:47 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex(unsigned int i, int whatcase)
{
	if (i >= 16)
	{
		ft_printhex(i / 16, whatcase);
		ft_printhex(i % 16, whatcase);
	}
	else if (i >= 10)
	{
		if (whatcase == 0)
			ft_putchar((char)(i + 87));
		else
			ft_putchar((char)(i + 55));
	}
	else
		ft_putchar((char)(i + 48));
}

int	ft_puthex(unsigned int i, int whatcase)
{
	int	len;

	len = 0;
	ft_printhex(i, whatcase);
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}
