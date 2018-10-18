/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_o_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:55:06 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:55:08 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "libftprintf.h"

static	char	*format_o(va_list ap, t_env *p)
{
	uintmax_t	nbr;

	nbr = 0;
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
	return (ft_itoabase_r(nbr, 8, 0));
}

static	int		o_fill_space(t_env *p, char *o_num, int space)
{
	int		ret;
	char	s_fill;

	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	if (p->width < (int)(ft_strlen(o_num)))
		return (ft_strlen(o_num));
	space = p->width - ft_strlen(o_num);
	if (((int)ft_strlen(o_num) < p->acc) && p->acc >= 0)
		space -= p->acc - ft_strlen(o_num);
	(p->sharp) ? space -= 1 : space;
	while (space-- > 0)
		ft_putchar(s_fill);
	if (p->width > p->acc && ((int)ft_strlen(o_num) < p->width))
		ret = p->width;
	else
		ret = ft_strlen(o_num);
	return (ret);
}

static void		printo(t_env *p, char *o_num, int space)
{
	if ((int)ft_strlen(o_num) > p->acc &&
		((ft_strlen(o_num) != 1 || o_num[0] != '0') && p->sharp))
	{
		ft_putchar('0');
		ft_putstr(o_num);
		return ;
	}
	if (((int)ft_strlen(o_num) < p->acc) && (p->acc >= 0))
	{
		space = p->acc - ft_strlen(o_num);
		while (space--)
			ft_putchar('0');
		ft_putstr(o_num);
		return ;
	}
	else
		ft_putstr(o_num);
}

static	int		o_width_handle(t_env *p, char *o_num)
{
	int ret;

	if (p->zero && !p->minus)
	{
		ret = o_fill_space(p, o_num, 0);
		printo(p, o_num, 0);
		return (ret);
	}
	if (p->minus)
	{
		printo(p, o_num, 0);
		return (o_fill_space(p, o_num, 0));
	}
	ret = o_fill_space(p, o_num, 0);
	printo(p, o_num, 0);
	return (ret);
}

int				treat_o_conv(t_env *p, va_list ap)
{
	int			ret;
	char		*o_num;

	ret = 0;
	o_num = format_o(ap, p);
	if ((o_num == NULL) || ((ret = ft_empty(p, ft_atoi(o_num))) >= 0))
		return (ret);
	ret = ft_strlen(o_num);
	if (!(p->width))
		printo(p, o_num, 0);
	else
		ret = o_width_handle(p, o_num);
	if (((int)ft_strlen(o_num) < p->acc) && (p->acc >= 0))
		ret = ret + (p->acc - ft_strlen(o_num));
	if (!(o_num[0] == '0' || p->acc > (int)ft_strlen(o_num)) && p->sharp)
		ret += 1;
	if (p->width > p->acc && ((int)ft_strlen(o_num) < p->width))
		ret = p->width;
	free(o_num);
	return (ret);
}
