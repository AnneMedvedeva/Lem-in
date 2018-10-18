/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:31:43 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:31:44 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	if (!n)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		a = s1[i];
		b = s2[i];
		while (a == b)
		{
			if ((a == '\0' && b == '\0') || n == 1)
				return (1);
			--n;
			a = s1[++i];
			b = s2[i];
		}
	}
	return (0);
}
