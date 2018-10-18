/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_x_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:56:15 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:56:17 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "libftprintf.h"

static	char	*format_x(t_env *p, va_list ap)
{
	uintmax_t	nbr;
	int			reg;

	nbr = 0;
	reg = (p->conv == 'x') ? 1 : 0;
	if ((ft_strequ(p->len, "l")) || p->conv == 'O')
		nbr = (unsigned long)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "j"))
		nbr = (uintmax_t)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "z"))
		nbr = (size_t)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "ll"))
		nbr = (unsigned long long)va_arg(ap, uintmax_t);
	else if (!p->len)
		nbr = (unsigned int)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "hh"))
		nbr = (unsigned char)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "h"))
		nbr = (unsigned short)va_arg(ap, uintmax_t);
	return (ft_itoabase_r(nbr, 16, reg));
}

static	int		x_fill_space(t_env *p, char *x_num, int space)
{
	int		ret;
	char	s_fill;

	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	if (p->width < (int)(ft_strlen(x_num)))
		return (ft_strlen(x_num));
	space = p->width - ft_strlen(x_num);
	if (((int)ft_strlen(x_num) < p->acc) && (p->acc >= 0))
		space -= p->acc - ft_strlen(x_num);
	(p->sharp) ? space -= 2 : space;
	while (space-- > 0)
		ft_putchar(s_fill);
	if (p->width > p->acc)
		ret = p->width;
	else
		ret = ft_strlen(x_num);
	return (ret);
}

static	void	printx(t_env *p, char *x_num, int space)
{
	if ((p->acc < (int)ft_strlen(x_num)) || p->acc == -1)
	{
		ft_putstr(x_num);
		return ;
	}
	else if (((int)ft_strlen(x_num) < p->acc) && (p->acc >= 0))
	{
		space = p->acc - ft_strlen(x_num);
		while (space--)
			ft_putchar('0');
		ft_putstr(x_num);
		return ;
	}
	else
		ft_putstr(x_num);
}

static	int		x_width_handle(t_env *p, char *x_num)
{
	int ret;

	if (((ft_strlen(x_num) != 1 || x_num[0] != '0') && p->sharp)
		&& (p->minus || p->zero))
		(p->conv == 'x') ? ft_putstr("0x") : ft_putstr("0X");
	if (p->zero && !p->minus)
	{
		ret = x_fill_space(p, x_num, 0);
		printx(p, x_num, 0);
		return (ret);
	}
	if (p->minus)
	{
		printx(p, x_num, 0);
		ret = x_fill_space(p, x_num, 0);
		return (ret);
	}
	ret = x_fill_space(p, x_num, 0);
	if ((ft_strlen(x_num) != 1 || x_num[0] != '0') && p->sharp)
		(p->conv == 'x') ? ft_putstr("0x") : ft_putstr("0X");
	printx(p, x_num, 0);
	if (((int)ft_strlen(x_num) < p->acc) && (p->acc >= 0))
		ret = ret + (p->acc - ft_strlen(x_num));
	return (ret);
}

int				treat_x_conv(t_env *p, va_list ap)
{
	int			ret;
	char		*x_num;

	ret = 0;
	x_num = format_x(p, ap);
	if ((x_num == NULL) || ((ret = ft_empty(p, ft_atoi(x_num))) >= 0))
		return (ret);
	ret = ft_strlen(x_num);
	if (!(p->width))
	{
		if ((ft_strlen(x_num) != 1 || x_num[0] != '0') && p->sharp)
			(p->conv == 'x') ? ft_putstr("0x") : ft_putstr("0X");
		printx(p, x_num, 0);
		if (((int)ft_strlen(x_num) < p->acc) && (p->acc >= 0))
			ret = ret + (p->acc - ft_strlen(x_num));
	}
	else
		ret = x_width_handle(p, x_num);
	if ((ft_strlen(x_num) != 1 || x_num[0] != '0') && p->sharp)
		ret = ret + 2;
	if (p->width > p->acc && ((int)ft_strlen(x_num) < p->width))
		ret = p->width;
	free(x_num);
	return (ret);
}
