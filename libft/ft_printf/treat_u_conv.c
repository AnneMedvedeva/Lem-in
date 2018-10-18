/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_u_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:55:58 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:56:02 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <inttypes.h>

short			countnbr_u(uintmax_t u_num)
{
	int i;

	i = 0;
	if (!u_num)
		return (1);
	i = 0;
	while (u_num)
	{
		u_num /= 10;
		i++;
	}
	return (i);
}

static int		u_fill_space(t_env *p, uintmax_t u_num, int bytes)
{
	int		ret;
	int		space;
	char	s_fill;

	ret = bytes;
	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	if ((ret + p->width) < ft_countnbr(u_num))
	{
		ret += countnbr_u(u_num);
		return (ret);
	}
	space = p->width - p->acc - ret;
	if (p->acc < countnbr_u(u_num))
	{
		space = p->width - countnbr_u(u_num) - ret;
		while (space-- > 0)
			ft_putchar(s_fill);
		return (p->width);
	}
	while (space-- > 0)
		ft_putchar(s_fill);
	return (p->width);
}

static void		putnbr_u(uintmax_t n)
{
	if (n <= 9)
	{
		ft_putchar((int)(n + '0'));
	}
	else
	{
		putnbr_u(n / 10);
		ft_putchar((int)((n % 10) + '0'));
	}
}

static void		printu(t_env *p, uintmax_t u_num, int space)
{
	if (p->acc <= 0)
	{
		if (!u_num && !p->acc)
			return ;
		putnbr_u(u_num);
		return ;
	}
	space = p->acc - countnbr_u(u_num);
	while (space-- > 0)
		ft_putchar('0');
	if (!u_num && !p->acc)
		return ;
	putnbr_u(u_num);
}

int				treat_u_conv(t_env *p, va_list ap)
{
	uintmax_t	u_num;
	int			ret;

	u_num = format_u(p, ap);
	ret = 0;
	if (p->acc || u_num)
	{
		if (!(p->width))
		{
			ret = countnbr_u(u_num);
			printu(p, u_num, 0);
			if (p->acc == countnbr_u(u_num))
				ret++;
			if (p->acc > countnbr_u(u_num))
				ret = (p->width > p->acc) ? p->width : p->acc;
			return (ret);
		}
		(p->minus) ? printu(p, u_num, 0) : 0;
		ret = u_fill_space(p, u_num, ret);
		(!p->minus) ? printu(p, u_num, 0) : 0;
		if (p->acc > countnbr_u(u_num))
			ret = (p->width > p->acc) ? p->width : p->acc;
	}
	return (ret);
}
