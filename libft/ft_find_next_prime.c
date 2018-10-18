/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:22:45 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:22:47 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	nb++;
	while (i != 1)
	{
		if (ft_isprime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}