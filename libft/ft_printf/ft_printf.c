/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:53:30 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:53:35 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_env		*set_var(t_env *p)
{
	p->len = 0;
	p->width = 0;
	p->acc = -1;
	p->space = 0;
	p->plus = 0;
	p->minus = 0;
	p->zero = 0;
	p->sharp = 0;
	p->conv = 0;
	return (p);
}

int			check_solve(va_list ap, char **f)
{
	t_env	*p;
	int		ret;

	p = (t_env*)malloc(sizeof(t_env));
	p = set_var(p);
	(*f)++;
	while (1)
	{
		if ((*f == '\0') || (!(fill_flag(p, f))) || (!fill_width(p, f))
			|| (!fill_acc(p, f)) || (!fill_len(p, f))
			|| (!fill_conv(p, f)))
		{
			if (p->len)
				free(p->len);
			free(p);
			return (0);
		}
		if (!(ft_strchr(FLAGS, p->conv)))
			break ;
	}
	ret = assign_conv(ap, p);
	if (p->len)
		free(p->len);
	free(p);
	return (ret);
}

int			process_evr(va_list ap, char *f)
{
	char		*cut;
	int			ret;

	ret = 0;
	while (f)
	{
		if (*f == '\0')
			break ;
		cut = ft_strchr(f, '%');
		if (!cut)
		{
			ft_putstr(f);
			ret = ft_strlen(f) + ret;
			break ;
		}
		if (cut > f)
		{
			ft_putnstr(f, cut - f);
			ret += (cut - f);
			f = cut;
		}
		if (cut <= f)
			ret += check_solve(ap, &f);
	}
	return (ret);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	if (!format)
		return (0);
	va_start(ap, format);
	ret = process_evr(ap, (char*)format);
	va_end(ap);
	return (ret);
}
