/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:30:19 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:30:21 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strequ(const char *s1, const char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		a = s1[i];
		b = s2[i];
		while (a == b)
		{
			i++;
			a = s1[i];
			b = s2[i];
			if (a == '\0' && b == '\0')
				return (1);
		}
	}
	return (0);
}
