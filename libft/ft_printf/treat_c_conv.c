/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:54:03 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:54:10 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libftprintf.h"

static	int		treat_cc_conv(t_env *p, va_list ap)
{
	wint_t	elem;
	int		ret;

	elem = va_arg(ap, wint_t);
	if (!(p->width))
	{
		unicode_conv(elem);
		ret = get_bytes(elem);
		return (ret);
	}
	if (get_bytes(elem) == 1)
		ret = p->width - 1;
	else
		ret = p->width - get_bytes(elem);
	(p->minus) ? unicode_conv(elem) : 0;
	while (ret-- > 0)
		ft_putchar(' ');
	(!p->minus) ? unicode_conv(elem) : 0;
	ret = get_bytes(elem);
	ret = (ret > p->width) ? ret : p->width;
	return (ret);
}

int				treat_c_conv(t_env *p, va_list ap)
{
	int			elem;
	int			space;
	int			s_fill;

	if (p->conv == 'C' || (p->len && !ft_strcmp(p->len, "l")))
		return (treat_cc_conv(p, ap));
	elem = va_arg(ap, int);
	space = p->width - 1;
	if (!(p->width))
	{
		ft_putchar(elem);
		return (1);
	}
	(p->minus) ? ft_putchar(elem) : 0;
	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	while (space--)
		ft_putchar(s_fill);
	(!p->minus) ? ft_putchar(elem) : 0;
	return (p->width);
}
