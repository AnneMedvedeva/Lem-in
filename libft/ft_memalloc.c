/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:25:10 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:25:11 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*p;

	if ((p = malloc(size * sizeof(void*))) != NULL)
	{
		ft_bzero(p, size);
		return (p);
	}
	return (NULL);
}
