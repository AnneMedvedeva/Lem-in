/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:30:11 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:30:13 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		l;

	l = ft_strlen(src);
	i = -1;
	copy = NULL;
	if (src)
	{
		if (!(copy = (char*)malloc(l + 1)))
			return (NULL);
		while (++i < l)
		{
			copy[i] = src[i];
		}
		copy[i] = '\0';
	}
	return (copy);
}
