/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:21:13 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:21:15 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static short	check_path_names(t_room *l_link, t_room *r_link, int i)
{
	if (!r_link)
	{
		ft_putendl("ERROR! Room name was not declared");
		ft_putendl("Finished reading data");
	}
	else if (!l_link)
	{
		ft_putendl("ERROR! Room name was not declared");
		ft_putendl("Finished reading data");
	}
	else
	{
		if (!ft_strequ(l_link->room_id, r_link->room_id))
		{
			ft_linkdup(&r_link, l_link, i);
			ft_linkdup(&l_link, r_link, i);
			return (1);
		}
		else
			ft_putendl("ERROR! Room linked to itself");
	}
	return (0);
}

static t_room	*is_listed(t_room ****room, char *room_id)
{
	t_room		*tmp_room;

	tmp_room = ***room;
	if (!room_id)
		return (NULL);
	while (tmp_room)
	{
		if (ft_strequ(room_id, tmp_room->room_id))
			return (tmp_room);
		else
			tmp_room = tmp_room->next;
	}
	return (NULL);
}

static short	path_check(t_room ***room, int count_elem)
{
	char	**room_names;
	t_room	*l_link;
	t_room	*r_link;

	room_names = ft_strsplit(TAB, '-');
	if (room_names)
		while (room_names && NULL != room_names[count_elem])
			count_elem++;
	if (count_elem == 2)
	{
		r_link = is_listed(&room, room_names[1]);
		l_link = is_listed(&room, room_names[0]);
		clear_2_arr(&room_names);
		if (check_path_names(l_link, r_link, 0) == 1)
			return (1);
	}
	else
	{
		clear_2_arr(&room_names);
		ft_putendl("ERROR! Wrong link");
		ft_putendl("Finished reading data");
	}
	return (0);
}

static int		comm_cmd_check(void)
{
	if (TAB)
		if (TAB[0] == '#')
			return (1);
	return (0);
}

short			path_parse(t_room **room, short ret_val)
{
	if ((g_lemin->st_r != 0) && (g_lemin->fin_r != 0))
	{
		while (1)
		{
			ft_putendl(TAB);
			if ((1 != comm_cmd_check()) && (1 != path_check(&room, 0)))
			{
				ft_strdel(&TAB);
				break ;
			}
			ft_strdel(&TAB);
			if ((ret_val = get_next_line(g_lemin->fd, &TAB)) <= 0)
				break ;
		}
		explore_way(room);
	}
	else
	{
		ft_strdel(&TAB);
		clear_list_r(room);
		ft_error("ERROR! No start or end room");
	}
	return (ret_val);
}
