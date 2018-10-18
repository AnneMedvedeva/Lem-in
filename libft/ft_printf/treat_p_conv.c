/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_p_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:55:18 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:55:20 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static	int		p_fill_space(t_env *p, char *p_num)
{
	int		space;
	char	s_fill;

	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	if (p->width < 2 + (int)ft_strlen(p_num))
		return (ft_strlen(p_num) + 2);
	space = p->width - 2 - ft_strlen(p_num);
	while (space-- > 0)
		ft_putchar(s_fill);
	return (p->width);
}

static	void	printp(t_env *p, char *p_num, int space)
{
	if ((p->acc < (int)ft_strlen(p_num)) || p->acc == -1)
	{
		ft_putstr(p_num);
		return ;
	}
	else if (((int)ft_strlen(p_num) < p->acc) && (p->acc >= 0))
	{
		space = p->acc - ft_strlen(p_num);
		while (space--)
			ft_putchar('0');
		ft_putstr(p_num);
		return ;
	}
	else
		ft_putstr(p_num);
}

static	int		p_width_handle(t_env *p, char *p_num)
{
	int ret;

	if (p->zero || p->minus)
		ft_putstr("0x");
	if (p->zero && !p->minus)
	{
		ret = p_fill_space(p, p_num);
		printp(p, p_num, 0);
		return (ret);
	}
	if (p->minus)
	{
		printp(p, p_num, 0);
		return (p_fill_space(p, p_num));
	}
	ret = p_fill_space(p, p_num);
	if (((int)ft_strlen(p_num) < p->acc) && (p->acc >= 0))
		ret += p->acc - ft_strlen(p_num);
	ft_putstr("0x");
	printp(p, p_num, 0);
	return (ret);
}

int				treat_p_conv(t_env *p, va_list ap)
{
	char	*p_num;
	int		ret;

	ret = 0;
	p_num = ft_itoabase_r((unsigned long)va_arg(ap, void*), 16, 1);
	if (p->acc || (ft_strlen(p_num) != 1 || p_num[0] != '0'))
	{
		if (!(p->width))
		{
			ft_putstr("0x");
			printp(p, p_num, 0);
			ret = ft_strlen(p_num) + 2;
			if (((int)ft_strlen(p_num) < p->acc) && (p->acc >= 0))
				ret = ret + p->acc - ft_strlen(p_num);
		}
		else
			ret = p_width_handle(p, p_num);
		free(p_num);
		return (ret);
	}
	ret = p->width > ret ? p->width + 2 : ret + 2;
	while (p->width-- > 0)
		ft_putchar(' ');
	ft_putstr("0x");
	return (ret);
}
