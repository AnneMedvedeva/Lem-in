/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:27:32 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:27:33 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_putchar(s[i]);
		ft_putchar('\n');
	}
}
