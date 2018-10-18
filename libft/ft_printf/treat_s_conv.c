/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_s_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:55:29 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:55:31 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	prints(t_env *p, char *s_val)
{
	int space;
	int i;

	i = 0;
	space = p->acc;
	if (!((int)ft_strlen(s_val) > p->acc) || !(p->acc >= 0))
	{
		ft_putstr(s_val);
		return ;
	}
	while (space--)
	{
		ft_putchar(s_val[i]);
		i++;
	}
}

int				null_width_handle(t_env *p)
{
	int		space;
	char	s_fill;

	space = p->width;
	(p->minus) ? prints(p, "(null)") : 0;
	if (p->width < 6 && (p->width < p->acc || p->acc == -1))
	{
		(!p->minus) ? prints(p, "(null)") : 0;
		return (6);
	}
	if (p->acc < 6 && (p->acc >= 0))
		space = space + (6 - p->acc);
	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	while (space-- > 6)
		ft_putchar(s_fill);
	(!p->minus) ? prints(p, "(null)") : 0;
	return (p->width);
}

static	int		s_width_handle(t_env *p, char *s_val)
{
	int		space;
	int		ret;
	char	s_fill;

	ret = ft_strlen(s_val);
	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	space = p->width;
	(p->minus) ? prints(p, s_val) : 0;
	if (((int)ft_strlen(s_val) > p->acc) && (p->acc >= 0))
		ret = p->acc;
	while (space-- > ret)
		ft_putchar(s_fill);
	(!p->minus) ? prints(p, s_val) : 0;
	(p->width > ret) ? ret = p->width : 0;
	return (ret);
}

int				treat_s_conv(t_env *p, va_list ap)
{
	int		ret;
	char	*s_val;

	if (p->conv == 'S' || (p->len && !ft_strcmp(p->len, "l")))
		return (treat_ss_conv(p, ap));
	s_val = va_arg(ap, char*);
	if (s_val)
	{
		if ((p->width < (int)ft_strlen(s_val)) && (p->width < p->acc))
		{
			ret = ft_strlen(s_val);
			prints(p, s_val);
			if (p->acc < (int)ft_strlen(s_val) && (p->acc >= 0))
				ret = p->acc;
			return (ret);
		}
		return (s_width_handle(p, s_val));
	}
	return (null_width_handle(p));
}
