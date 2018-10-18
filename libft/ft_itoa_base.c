/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:24:01 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:24:03 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_cntr(uintmax_t n, uintmax_t base)
{
	int			i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char			*ft_itoa_base(uintmax_t value, uintmax_t base)
{
	uintmax_t	i;
	char		*nbr;
	int			neg;
	int			div;

	i = 1;
	neg = 0;
	i = ft_itoa_cntr(value, base);
	nbr = (char*)malloc(i + 1);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		div = value % base;
		if (div < 0)
			div *= -1;
		nbr[i + neg] = div + (div > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
