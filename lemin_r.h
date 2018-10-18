/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_r.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:20:40 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:42 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_R_H
# define LEMIN_R_H

# include "lemin.h"

/*
**	path - all links of the room
**	room_id - name of the room
**	start - is it the starting point
**	finish - is it the finishing point
**	ants - how many ants in there
**	depth - how far away the room is placed
**	flag - was this room given it's depth
**	coord[2] - coordinates of the room
*/

typedef struct		s_list_r
{
	struct s_list_r	**path;
	struct s_list_r	*next;
	char			*room_id;
	short			start;
	short			finish;
	int				ants;
	int				depth;
	short			flag;
	int				coord[2];
}					t_room;

#endif
