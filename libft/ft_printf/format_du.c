/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_du.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:53:02 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:53:09 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include <inttypes.h>
#include "libftprintf.h"

int				ft_empty(t_env *p, uintmax_t nbr)
{
	int ret;

	ret = 0;
	if ((!nbr && !p->acc && (p->conv == 'x' || p->conv == 'X')) ||
		(!nbr && !p->acc && !p->sharp && (p->conv == 'o' ||
		p->conv == 'O')) || (!nbr && !p->acc && (p->conv == 'd' ||
		p->conv == 'D' || p->conv == 'i')))
	{
		ret = p->width;
		while (p->width-- > 0)
			ft_putchar(' ');
		return (ret);
	}
	else
		return (-1);
}

intmax_t		format_d(t_env *p, va_list ap)
{
	intmax_t nbr;

	nbr = 0;
	if ((ft_strequ(p->len, "l")) || (p->conv == 'D'))
		nbr = (long)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "j"))
		nbr = (intmax_t)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "z"))
		nbr = (ssize_t)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "ll"))
		nbr = (long long)va_arg(ap, uintmax_t);
	else if (!p->len)
		nbr = (int)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "hh"))
		nbr = (char)va_arg(ap, uintmax_t);
	else if (ft_strequ(p->len, "h"))
		nbr = (short)va_arg(ap, uintmax_t);
	return (nbr);
}

uintmax_t		format_u(t_env *p, va_list ap)
{
	uintmax_t	nbr;

	nbr = 0;
	if ((ft_strequ(p->len, "l")) || p->conv == 'U')
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
	return (nbr);
}
