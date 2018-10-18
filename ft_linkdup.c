/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:19:47 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:19:49 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_linkdup(t_room **room, t_room *new_room, int i)
{
	t_room	*tmp_room;
	t_room	**new_list;
	t_room	**old_list;

	tmp_room = *room;
	if (tmp_room->path)
	{
		while (tmp_room->path[i] != NULL)
			i++;
		old_list = tmp_room->path;
		new_list = malloc(sizeof(t_room*) * (2 + i));
		i = -1;
		while (old_list[++i])
			new_list[i] = old_list[i];
		new_list[i] = new_room;
		new_list[++i] = NULL;
		tmp_room->path = new_list;
		free(old_list);
		return (0);
	}
	tmp_room->path = malloc(sizeof(t_room*) * 2);
	tmp_room->path[i] = new_room;
	tmp_room->path[++i] = NULL;
	return (0);
}
