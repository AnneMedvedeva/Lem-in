/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:30:58 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:31:00 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}
