/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:24:10 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:24:12 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	get_size(unsigned long nbr, int base)
{
	int i;

	if (!nbr)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

static char		*set_tab_maj(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 16);
	str[0] = '0';
	str[1] = '1';
	str[2] = '2';
	str[3] = '3';
	str[4] = '4';
	str[5] = '5';
	str[6] = '6';
	str[7] = '7';
	str[8] = '8';
	str[9] = '9';
	str[10] = 'A';
	str[11] = 'B';
	str[12] = 'C';
	str[13] = 'D';
	str[14] = 'E';
	str[15] = 'F';
	return (str);
}

static char		*set_tab_min(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 16);
	str[0] = '0';
	str[1] = '1';
	str[2] = '2';
	str[3] = '3';
	str[4] = '4';
	str[5] = '5';
	str[6] = '6';
	str[7] = '7';
	str[8] = '8';
	str[9] = '9';
	str[10] = 'a';
	str[11] = 'b';
	str[12] = 'c';
	str[13] = 'd';
	str[14] = 'e';
	str[15] = 'f';
	return (str);
}

char			*ft_itoabase_r(unsigned long nbr, int base, char min)
{
	char	*tab;
	char	*str;
	int		i;
	int		size;

	if (!base)
		return (NULL);
	if (min)
		tab = set_tab_min();
	else
		tab = set_tab_maj();
	size = get_size(nbr, base);
	str = (char*)malloc(sizeof(char) * (size + 1));
	i = size - 1;
	if (!nbr)
		str[i--] = tab[nbr % base];
	while (nbr)
	{
		str[i--] = tab[nbr % base];
		nbr /= base;
	}
	str[size] = '\0';
	free(tab);
	return (str);
}
