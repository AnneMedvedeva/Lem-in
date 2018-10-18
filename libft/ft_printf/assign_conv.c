/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:52:16 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:52:22 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include <inttypes.h>
#include "libftprintf.h"

int				process_invalid(t_env *p, int i)
{
	if (!p->width)
	{
		ft_putchar(p->conv);
		return (1);
	}
	else if (p->zero && !p->minus)
	{
		while (--i > 0)
			ft_putchar('0');
		ft_putchar(p->conv);
	}
	else if (p->minus)
	{
		ft_putchar(p->conv);
		while (--i > 0)
			ft_putchar(' ');
	}
	else
	{
		while (--i > 0)
			ft_putchar(' ');
		ft_putchar(p->conv);
	}
	return (p->width);
}

int				assign_conv(va_list ap, t_env *p)
{
	int ret;

	ret = 0;
	if (!(ft_strchr(CONV, p->conv)))
		ret = process_invalid(p, p->width);
	else if (p->conv == 's' || p->conv == 'S')
		ret = treat_s_conv(p, ap);
	else if (p->conv == 'p')
		ret = treat_p_conv(p, ap);
	else if (p->conv == 'c' || p->conv == 'C')
		ret = treat_c_conv(p, ap);
	else if (p->conv == '%')
		ret = treat_no_conv(p, 0);
	else if (p->conv == 'o' || p->conv == 'O')
		ret = treat_o_conv(p, ap);
	else if (p->conv == 'u' || p->conv == 'U')
		ret = treat_u_conv(p, ap);
	else if (p->conv == 'x' || p->conv == 'X')
		ret = treat_x_conv(p, ap);
	else if (p->conv == 'd' || p->conv == 'i' || p->conv == 'D')
		ret = treat_d_conv(p, ap);
	return (ret);
}
