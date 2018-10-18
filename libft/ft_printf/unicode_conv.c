/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:56:30 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:56:31 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				get_bytes(wchar_t elem)
{
	if ((elem >> 16) > 0)
		return (4);
	else if ((elem >> 11) > 0)
		return (3);
	else if ((elem >> 7) > 0)
		return (2);
	else
		return (1);
}

static	void	two_bytes(wchar_t elem)
{
	unsigned int	v;
	unsigned char	o;
	unsigned char	o1;
	unsigned char	o2;

	v = elem;
	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	o = ((unsigned int)49280 >> 8) | o1;
	ft_putchar(o);
	o = (((unsigned int)49280 << 24) >> 24) | o2;
	ft_putchar(o);
}

static	void	three_bytes(wchar_t elem)
{
	unsigned int	v;
	unsigned char	o;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	v = elem;
	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	o = ((unsigned int)14712960 >> 16) | o1;
	ft_putchar(o);
	o = (((unsigned int)14712960 << 16) >> 24) | o2;
	ft_putchar(o);
	o = (((unsigned int)14712960 << 24) >> 24) | o3;
	ft_putchar(o);
}

static	void	four_bytes(wchar_t elem)
{
	unsigned char	o;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	o4 = (elem << 26) >> 26;
	o3 = ((elem >> 6) << 26) >> 26;
	o2 = ((elem >> 12) << 26) >> 26;
	o1 = ((elem >> 18) << 29) >> 29;
	o = ((unsigned int)4034953344 >> 24) | o1;
	ft_putchar(o);
	o = (((unsigned int)4034953344 << 8) >> 24) | o2;
	ft_putchar(o);
	o = (((unsigned int)4034953344 << 16) >> 24) | o3;
	ft_putchar(o);
	o = (((unsigned int)4034953344 << 24) >> 24) | o4;
	ft_putchar(o);
}

void			unicode_conv(wchar_t elem)
{
	if ((elem >> 16) != 0)
		four_bytes(elem);
	else if ((elem >> 11) != 0)
		three_bytes(elem);
	else if ((elem >> 7) != 0)
		two_bytes(elem);
	else
		ft_putchar(elem);
}
