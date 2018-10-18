/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:32:47 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:32:48 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	char	*new;
	int		i;
	int		e;
	int		j;

	new = NULL;
	if (s)
	{
		i = 0;
		j = -1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		e = ft_strlen(s) - 1;
		while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
			e--;
		if (s[i] == '\0' || (size_t)(i - 1) == ft_strlen(s))
		{
			new = ft_strnew(1);
			new[0] = '\0';
			return (new);
		}
		if ((new = ft_strnew(e - i + 1)) != NULL)
			new = ft_strsub(s, i, e - i + 1);
	}
	return (new);
}
