/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_room_and_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:21:40 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:21:42 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static short	*check_double_comm(t_room **room, short s, short e)
{
	static short	check[2];

	check[0] = s;
	check[1] = e;
	if ((1 >= check[0]) && ft_strequ(START, TAB))
		check[0]++;
	if ((2 <= check[0]) && ft_strequ(START, TAB))
	{
		ft_strdel(&TAB);
		ft_error("ERROR! ##start is repeated");
	}
	if ((1 >= check[1]) && ft_strequ(END, TAB))
		check[1]++;
	if ((2 <= check[1]) && ft_strequ(END, TAB))
	{
		ft_strdel(&TAB);
		ft_error("ERROR! ##end is repeated");
	}
	if (TAB && (TAB[0] == '#'))
		return (check);
	if (TAB && (TAB[0] != '#'))
		*room = room_validation(room, check, 0);
	return (check);
}

char			*validate_room_and_cmd(t_room **room, short ret_val)
{
	short	*sf;
	short	s;
	short	e;

	s = 0;
	e = 0;
	while (1)
	{
		ret_val = get_next_line(g_lemin->fd, &TAB);
		if (!ft_strchr(TAB, '-'))
		{
			ft_putendl(TAB);
			sf = check_double_comm(room, s, e);
			s = sf[0];
			e = sf[1];
			ft_strdel(&TAB);
		}
		else
			return (TAB);
		if (ret_val <= 0)
			break ;
	}
	return (0);
}
