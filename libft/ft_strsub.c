/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:32:40 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:32:42 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*new;

	if (s)
	{
		if ((new = ft_strnew(len)) != NULL)
		{
			i = -1;
			while (len--)
				new[++i] = s[start++];
			return (new);
		}
	}
	return (NULL);
}
