/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:19:38 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:19:39 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	void	go_in_depth(t_room **room, int i)
{
	int		count;
	t_room	*check;
	t_room	*tmp_room;

	tmp_room = *room;
	check = tmp_room->path[i];
	count = 1;
	while (check->path[count] && (count <= 2))
		count++;
	if (count >= 2)
	{
		if (tmp_room->depth + 1 < tmp_room->path[i]->depth)
			tmp_room->path[i]->depth = tmp_room->depth + 1;
		find_way_and_place_depth(&tmp_room->path[i]);
	}
}

int				find_way_and_place_depth(t_room **room)
{
	int		i;
	short	ret;
	t_room	*tmp_room;

	i = 0;
	ret = 0;
	tmp_room = *room;
	tmp_room->flag = 1;
	while ((i < 200) && tmp_room->path && (tmp_room->path[i] != 0))
	{
		if ((0 == tmp_room->path[i]->start) && (0 == tmp_room->path[i]->finish)
		&& (0 == tmp_room->path[i]->flag))
			go_in_depth(&tmp_room, i);
		if (0 != tmp_room->path[i]->start)
		{
			tmp_room->path[i]->flag = 0;
			g_lemin->way = 1;
		}
		i++;
	}
	(tmp_room->path != 0) ? tmp_room->path[i - 1]->flag = 0 : 0;
	ret = g_lemin->way;
	return (ret);
}

int				explore_way(t_room **room)
{
	int		ret;
	t_room	*fin;

	ret = 1;
	fin = *room;
	if (fin)
	{
		while (fin && (0 == fin->finish))
			fin = fin->next;
		fin = (fin && 0 == fin->finish) ? 0 : fin;
	}
	if (find_way_and_place_depth(&fin) == 1)
		place_ants(room);
	else
	{
		clear_list_r(room);
		ft_error("ERROR! Start and end are disconnected");
	}
	return (ret);
}
