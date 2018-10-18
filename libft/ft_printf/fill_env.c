/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:52:41 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:52:51 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

char	*fill_len(t_env *p, char **f)
{
	int		check;

	check = **f;
	if (p->len)
	{
		if (**f < p->len[0])
			(*f)++;
		if (**f < p->len[0])
			check = 0;
		if (ft_strchr(LEN, check) && (check > p->len[0]))
			free(p->len);
	}
	if (!check || !(ft_strchr(LEN, check)))
		return (*f);
	p->len = ft_strnew(3);
	p->len[0] = **f;
	if ((*(*f + 1) == 'l' && **f == 'l') || (*(*f + 1) == 'h' && **f == 'h'))
		p->len[1] = (**f == 'l') ? 'l' : 'h';
	if (p->len[1] != '\0')
		(*f)++;
	(*f)++;
	return (*f);
}

char	*fill_width(t_env *p, char **f)
{
	char	*tab_end;
	char	*tab;

	if (!f || !p)
		return (0);
	if (ft_isdigit(**f))
	{
		tab_end = *f;
		while (ft_isdigit(*tab_end))
			tab_end++;
		tab = ft_strsub(*f, 0, tab_end - *f);
		while (ft_isdigit(**f))
			(*f)++;
		p->width = ft_atoi(tab);
		free(tab);
	}
	return (*f);
}

char	*fill_acc(t_env *p, char **f)
{
	char	*tab_end;
	char	*tab;

	if (**f == '.')
	{
		p->acc = 0;
		(*f)++;
		if (ft_isdigit(**f))
		{
			tab_end = *f;
			while (ft_isdigit(*tab_end))
				tab_end++;
			tab = ft_strsub(*f, 0, tab_end - *f);
			while (ft_isdigit(**f))
				(*f)++;
			p->acc = ft_atoi(tab);
			free(tab);
		}
	}
	return (*f);
}

char	*fill_flag(t_env *p, char **f)
{
	while (f)
	{
		if (**f == '#' || **f == '0' || **f == '-' || **f == '+' || **f == ' ')
		{
			if (**f == '#')
				p->sharp = 1;
			if (**f == '-')
				p->minus = 1;
			if (**f == '0')
				p->zero = 1;
			if (**f == '+')
				p->plus = 1;
			if (**f == ' ')
				p->space = 1;
			(*f)++;
		}
		else
			break ;
	}
	return (*f);
}

char	*fill_conv(t_env *p, char **f)
{
	char	c;

	c = **f;
	if (!c)
		return (0);
	p->conv = **f;
	if (!(ft_strchr(FLAGS, p->conv)))
		(*f)++;
	return (*f);
}
