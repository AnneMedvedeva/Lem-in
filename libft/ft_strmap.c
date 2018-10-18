/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:31:06 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:31:07 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (s)
	{
		if ((new = ft_strnew(ft_strlen(s))) != NULL)
		{
			i = -1;
			while (s[++i] != '\0')
				new[i] = (*f)(s[i]);
		}
		return (new);
	}
	return (NULL);
}
