/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:32:17 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:32:19 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i == 0)
		return (NULL);
	if (c == '\0')
		return ((char*)&s[i]);
	while (--i != -1)
		if (s[i] == c)
			return ((char*)&s[i]);
	return (NULL);
}
