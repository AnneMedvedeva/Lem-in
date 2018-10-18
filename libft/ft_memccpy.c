/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:25:26 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:25:27 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memccpy(void *dst, void *src, int c, int len)
{
	int		i;
	char	*s;
	char	*d;

	i = -1;
	s = src;
	d = dst;
	while (++i < len)
	{
		d[i] = s[i];
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&d[i + 1]);
	}
	return (NULL);
}
