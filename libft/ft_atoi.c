/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:22:09 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:22:11 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	at_hlp(int i, char *str, int sign)
{
	unsigned long int result;

	result = 0;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
		}
		else
			break ;
		++i;
	}
	if ((result > 922337203685477580 || (result == 922337203685477580
		&& (str[i] - '0') > 7)) && sign == 1)
		return (-1);
	else if ((result > 922337203685477580 || (result == 922337203685477580
		&& (str[i] - '0') > 8)) && sign == -1)
		return (0);
	return (result);
}

int			ft_atoi(char *str)
{
	int	i;
	int	k;
	int	sign;

	i = 0;
	k = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if ((str[i] == '+' || str[i] == '-') &&
		!(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		k = i;
		i++;
	}
	if (str[k] == '-')
	{
		sign = -1;
		return (at_hlp(i, str, sign) * sign);
	}
	return (at_hlp(i, str, sign));
}
