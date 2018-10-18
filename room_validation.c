/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:21:32 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:21:33 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static short	check_room_id(t_room *room, char *id)
{
	t_room *tmp_r;

	tmp_r = room;
	if (tmp_r)
	{
		while (tmp_r)
		{
			if (0 != ft_strequ(id, tmp_r->room_id))
				return (1);
			if (0 == ft_strequ(id, tmp_r->room_id))
				tmp_r = tmp_r->next;
		}
	}
	return (0);
}

/*
** lr - coordinates(left, right)
*/

static int		double_coord(int *lr, t_room *room)
{
	if (room)
	{
		while (room)
		{
			if ((lr[1] == room->coord[1]) && (lr[0] == room->coord[0]))
				return (1);
			if (((lr[0] == room->coord[0]) && (lr[1] != room->coord[1]))
				|| ((lr[1] == room->coord[1]) && (lr[0] != room->coord[0])) ||
				((lr[1] != room->coord[1]) && (lr[0] != room->coord[0])))
				room = room->next;
		}
	}
	return (0);
}

static void		check_room_elements(char **elem, int count)
{
	if (elem && *elem)
	{
		if ('L' == elem[0][0])
		{
			clear_2_arr(&elem);
			ft_error("ERROR! 'L' starting the room name");
		}
		if ((count == 3) && ((0 == ft_str_digit(elem[2]))
		|| (0 == ft_str_digit(elem[1]))))
		{
			clear_2_arr(&elem);
			ft_error("ERROR! Coordinates not valid");
		}
		if ((count > 3) || (count < 3))
		{
			clear_2_arr(&elem);
			ft_error("ERROR! Not a room");
		}
	}
}

static short	space_check(int ret)
{
	int		i;

	i = 0;
	if (TAB != 0)
	{
		while (TAB[i])
		{
			if (TAB[i] == ' ')
				ret++;
			i++;
		}
	}
	return (ret == 2) ? (1) : (0);
}

t_room			*room_validation(t_room **room, short *se, int count)
{
	char	**r_elem;
	int		coord[2];

	if (space_check(0) != 0)
	{
		r_elem = ft_strsplit(TAB, ' ');
		if (r_elem)
		{
			while (r_elem && (r_elem[count] != NULL))
				count++;
			check_room_elements(r_elem, count);
			coord[0] = ft_atoi(r_elem[1]);
			coord[1] = ft_atoi(r_elem[2]);
		}
		if (check_room_id(*room, r_elem[0]))
			ft_error("ERROR! Room is already declared");
		if (double_coord(coord, *room))
			ft_error("ERROR! Already used coordinates");
		new_room_maker(r_elem[0], coord, se, &*room);
		clear_2_arr(&r_elem);
	}
	else
		ft_error("ERROR! Not valid space amount");
	return (*room);
}
