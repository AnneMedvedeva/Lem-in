/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:31:12 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:31:13 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	if (s)
	{
		if ((new = ft_strnew(ft_strlen(s))) != NULL)
		{
			i = -1;
			while (s[++i] != '\0')
				new[i] = (*f)(i, s[i]);
		}
		return (new);
	}
	return (NULL);
}
