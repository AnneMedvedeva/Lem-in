/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:23:52 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:23:54 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_cntr(intmax_t n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(intmax_t n)
{
	char		*new;
	int			c_count;
	intmax_t	nn;
	int			c;
	int			div;

	c_count = ft_itoa_cntr(n);
	c = c_count;
	nn = n;
	if ((new = ft_strnew(c_count)) != NULL)
	{
		if (nn < 0)
			n *= -1;
		while (c_count)
		{
			if (n % 10 > 0)
				div = n % 10;
			else
				div = n % 10 * -1;
			new[--c_count] = div + '0';
			n /= 10;
		}
		new[c] = '\0';
	}
	return (new);
}
