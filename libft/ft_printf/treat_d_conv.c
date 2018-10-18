/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_d_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:54:25 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:54:28 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <inttypes.h>

static	int		d_fill_space(t_env *p, intmax_t d_num, int bytes)
{
	int	s_fill;
	int space;
	int ret;

	ret = bytes;
	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	s_fill = (p->zero && !p->minus && p->acc != -1) ? ' ' : s_fill;
	if ((ret + p->width) < ft_countnbr(d_num))
	{
		ret += ft_countnbr(d_num);
		return (ret);
	}
	if (p->space && p->acc <= ft_countnbr(d_num) && p->sharp && !p->minus)
		p->width--;
	if (p->acc < ft_countnbr(d_num))
		space = p->width - ft_countnbr(d_num) - ret;
	else
	{
		space = p->width - p->acc - ret;
		if (d_num < 0)
			space--;
	}
	while (space-- > 0)
		ft_putchar(s_fill);
	return (p->width);
}

static	void	printd(t_env *p, intmax_t d_num, int space)
{
	if ((d_num || p->acc) && p->acc <= 0)
	{
		ft_putnbr(d_num);
		return ;
	}
	(d_num < 0) ? ft_putchar('-') : 0;
	d_num = (d_num < 0) ? d_num * -1 : d_num;
	space = p->acc - ft_countnbr(d_num);
	while (space-- > 0)
		ft_putchar('0');
	(d_num || p->acc) ? ft_putnbr(d_num) : 0;
}

static	int		d_width_handle_plus(t_env *p, intmax_t d_num, int ret)
{
	(p->acc != -1) ? ret = d_fill_space(p, d_num, ret) : 0;
	if ((d_num >= 0 && p->space) || (d_num >= 0 && p->plus))
		ret++;
	if ((d_num >= 0 && p->space) || (d_num >= 0 && p->plus))
		ft_putchar((p->plus) ? '+' : ' ');
	(d_num >= 0) ? 0 : ft_putchar('-');
	(p->acc < 0) ? ret = d_fill_space(p, d_num, ret) : 0;
	d_num = (d_num >= 0) ? d_num : d_num * -1;
	printd(p, d_num, 0);
	return (ret);
}

static	int		d_width_handle(t_env *p, intmax_t d_num, int ret)
{
	if (p->zero && !p->minus)
		return (d_width_handle_plus(p, d_num, ret));
	if ((d_num >= 0 && p->space) || (d_num >= 0 && p->plus))
		ret++;
	if (p->minus)
	{
		if ((d_num >= 0 && p->space) || (d_num >= 0 && p->plus))
			ft_putchar((p->plus) ? '+' : ' ');
		printd(p, d_num, 0);
		return (d_fill_space(p, d_num, ret));
	}
	ret = d_fill_space(p, d_num, ret);
	if ((d_num >= 0 && p->space) || (d_num >= 0 && p->plus))
		ft_putchar((p->plus) ? '+' : ' ');
	if (((p->space) && d_num >= 0) || ((p->minus) && d_num >= 0))
		(p->space) ? ret++ : ret--;
	if (ft_countnbr(d_num) < p->acc && d_num)
		ret = (d_num >= 0) ? p->acc : p->acc + 1;
	printd(p, d_num, 0);
	return (ret);
}

int				treat_d_conv(t_env *p, va_list ap)
{
	intmax_t	d_num;
	long		ret;

	d_num = format_d(p, ap);
	if ((ret = ft_empty(p, d_num)) >= 0)
		return (ret);
	if (!(p->width))
	{
		ret = ft_countnbr(d_num);
		if ((d_num >= 0 && p->space) || (d_num >= 0 && p->plus))
			ret++;
		if ((d_num >= 0 && p->space) || (d_num >= 0 && p->plus))
			ft_putchar((p->plus) ? '+' : ' ');
		printd(p, d_num, 0);
		if (ft_countnbr(d_num) <= p->acc)
			ret++;
		if (ft_countnbr(d_num) < p->acc && d_num)
			ret = (d_num >= 0) ? p->acc : p->acc + 1;
		return (ret);
	}
	ret = d_width_handle(p, d_num, 0);
	if (ft_countnbr(d_num) < p->acc && d_num && p->acc < p->width)
		ret = p->width;
	return (ret);
}
