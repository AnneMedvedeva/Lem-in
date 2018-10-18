/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_ss_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:55:40 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:55:42 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libftprintf.h"

static	int		bytes_in_str(wchar_t *ss_val, int count)
{
	int len;

	len = 0;
	while (ss_val[count])
		len = get_bytes(ss_val[count++]) + len;
	return (len);
}

static	void	printss(wchar_t *ss_val, int len)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ss_val[i])
	{
		if (len > count)
		{
			unicode_conv(ss_val[i++]);
			count = get_bytes(ss_val[i]) + count;
		}
		else
			break ;
	}
}

static	int		ss_acc_handle(t_env *p, wchar_t *ss_val, int len)
{
	int		ret;
	char	s_fill;

	ret = 0;
	if (p->acc && ss_val)
		while ((p->acc >= (get_bytes(ss_val[len]) + ret))
			&& (ss_val[len]))
			ret = get_bytes(ss_val[len++]) + ret;
	if (!p->width)
	{
		printss(ss_val, ret);
		return (ret);
	}
	(p->minus) ? printss(ss_val, ret) : 0;
	len = p->width - ret;
	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	while (len-- > 0)
		ft_putchar(s_fill);
	(!p->minus) ? printss(ss_val, ret) : 0;
	ret = (ret > p->width) ? ret : p->width;
	return (ret);
}

static	int		ss_width_handle(t_env *p, wchar_t *ss_val)
{
	int		len;
	int		ret;
	int		space;
	char	s_fill;

	len = bytes_in_str(ss_val, 0);
	(p->minus) ? printss(ss_val, len) : 0;
	space = p->width - bytes_in_str(ss_val, 0);
	s_fill = (p->zero && !p->minus) ? '0' : ' ';
	while (space-- > 0)
		ft_putchar(s_fill);
	(!p->minus) ? printss(ss_val, len) : 0;
	ret = bytes_in_str(ss_val, 0);
	ret = (ret > p->width) ? ret : p->width;
	return (ret);
}

int				treat_ss_conv(t_env *p, va_list ap)
{
	wchar_t	*ss_val;
	int		ret;
	int		len;

	ret = 0;
	ss_val = va_arg(ap, wchar_t*);
	if (ss_val)
	{
		if (p->acc == -1 && p->width)
			return (ss_width_handle(p, ss_val));
		if (p->acc != -1)
			return (ss_acc_handle(p, ss_val, 0));
		len = bytes_in_str(ss_val, 0);
		printss(ss_val, len);
		ret = bytes_in_str(ss_val, 0);
		ret = (ret > p->width) ? ret : p->width;
		return (ret);
	}
	return (null_width_handle(p));
}
