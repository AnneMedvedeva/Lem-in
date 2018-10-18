/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:26:17 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:26:19 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memmove(void *dest, void *src, int len)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	if (d > s)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
		while (len--)
			*(d++) = *(s++);
	return (&dest[0]);
}
