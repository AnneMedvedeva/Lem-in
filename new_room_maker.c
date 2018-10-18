/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:21:04 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:21:05 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static short	init_sf_and_ant_amount(short *se, t_room **room)
{
	t_room	*tmp_r;

	tmp_r = *room;
	if ((g_lemin->fin_r == 0) && (se[1] == 1))
		tmp_r->finish = 1;
	else
		tmp_r->finish = 0;
	if ((g_lemin->st_r == 0) && (se[0] == 1))
		tmp_r->start = 1;
	else
		tmp_r->start = 0;
	if ((g_lemin->st_r == 0) && se[0])
	{
		g_lemin->st_r = 1;
		tmp_r->ants = g_lemin->amount;
	}
	else if ((g_lemin->fin_r == 0) && se[1])
	{
		g_lemin->fin_r = 1;
		tmp_r->ants = 0;
	}
	else
		tmp_r->ants = 0;
	return (0);
}

static void		ft_room_init(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	tmp->next = NULL;
	tmp->flag = 0;
	tmp->path = NULL;
}

int				new_room_maker(char *room_id, int *coord,
	short *se, t_room **room)
{
	t_room	*tmp;
	t_room	*tmp_old;
	int		i;

	i = 0;
	tmp_old = *room;
	tmp = (t_room *)malloc(sizeof(t_room));
	ft_room_init(&tmp);
	tmp->room_id = ft_strdup(room_id);
	tmp->coord[1] = coord[1];
	tmp->coord[0] = coord[0];
	init_sf_and_ant_amount(se, &tmp);
	tmp->depth = (tmp->finish ? 0 : INT_MAX);
	if (tmp_old != NULL)
	{
		while (tmp_old->next)
			tmp_old = tmp_old->next;
		tmp_old->next = tmp;
	}
	else
		*room = tmp;
	return (i);
}
