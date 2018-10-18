/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:30:42 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:30:43 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		l;
	int		ll;
	int		i;

	if (s1 && s2)
	{
		l = ft_strlen(s1);
		ll = ft_strlen(s2);
		i = 0;
		if ((new = ft_strnew(l + ll)) != NULL)
		{
			while (l--)
				new[i++] = *s1++;
			while (ll--)
				new[i++] = *s2++;
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
