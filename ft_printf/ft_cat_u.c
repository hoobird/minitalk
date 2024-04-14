/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:29:09 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 03:33:55 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countdigits(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*output;
	int		ind;
	long	nn;

	size = countdigits(n);
	output = malloc(sizeof(char) * (size + 1));
	if (output == NULL)
		return (NULL);
	output[size] = 0;
	ind = 0;
	nn = (long) n;
	while (size > ind)
	{
		output[--size] = '0' + (nn % 10);
		nn /= 10;
	}
	return (output);
}

int	ft_putunint(unsigned int ui)
{
	char	*str;
	int		val;

	str = ft_uitoa(ui);
	val = ft_putstr(str);
	free(str);
	return (val);
}
