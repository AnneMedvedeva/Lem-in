/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:19:59 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:00 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		clear_list_r(t_room **room)
{
	if (room && *room)
	{
		free((*room)->room_id);
		free((*room)->path);
		if ((*room)->next)
			clear_list_r(&(*room)->next);
		free(*room);
	}
}

void		clear_2_arr(char ***str)
{
	char	**tmp_str;
	int		i;

	i = 0;
	tmp_str = *str;
	if (tmp_str)
	{
		while (tmp_str[i])
		{
			ft_strdel(&tmp_str[i]);
			i++;
		}
		if (tmp_str != NULL)
			free(tmp_str);
	}
}

void		clear_ant_struct(t_lem ***ant)
{
	t_lem	**tmp_ant;
	int		i;

	i = 0;
	tmp_ant = *ant;
	while (tmp_ant[i])
	{
		free(tmp_ant[i]);
		i++;
	}
	if (tmp_ant != NULL)
		free(tmp_ant);
}
