/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_no_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:54:49 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:54:51 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		treat_no_conv(t_env *p, int space)
{
	space = p->width;
	if (!(p->width))
	{
		ft_putchar('%');
		return (1);
	}
	else if (p->zero && !p->minus)
	{
		while (--space > 0)
			ft_putchar('0');
		ft_putchar('%');
	}
	else if (p->minus)
	{
		ft_putchar('%');
		while (--space > 0)
			ft_putchar(' ');
	}
	else
	{
		while (--space > 0)
			ft_putchar(' ');
		ft_putchar('%');
	}
	return (p->width);
}
