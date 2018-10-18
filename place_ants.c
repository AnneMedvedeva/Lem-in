/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:21:23 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:21:25 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		name_lems(t_lem **new, t_room *start, int count)
{
	int ant_num;

	ant_num = 1;
	while (g_lemin->amount >= ant_num)
	{
		new[++count] = malloc(sizeof(t_lem));
		new[count]->room = start;
		new[count]->l_n = ant_num;
		ant_num++;
	}
	return (count);
}

static t_lem	**deliver_lems_list(t_room **room, int i)
{
	t_lem		**new;
	t_room		*start;

	start = *room;
	if (room && *room)
	{
		while (start && 0 == start->start)
			start = start->next;
		start = (start && 0 == start->start) ? 0 : start;
	}
	else
		start = 0;
	if (!(new = malloc(sizeof(t_lem*) * (g_lemin->amount + 1))))
		ft_error("ERROR! Memory allocation error");
	i = name_lems(new, start, i);
	new[++i] = NULL;
	return (new);
}

static int		best_room(t_room *room, int *pos_tab)
{
	int			best_pos;
	int			count;
	int			i;
	int			len;

	i = -1;
	len = -1;
	while (room->path[++i])
	{
		if (room->path[i]->finish == 0)
			if (room->path[i]->ants == 0 && room->path[i]->depth != INT_MAX)
				pos_tab[++len] = i;
		if (room->path[i]->finish == 1)
			return (i);
	}
	count = 0;
	if (pos_tab[count] != -1)
	{
		best_pos = pos_tab[count];
		while ((len > count) && (-1 != pos_tab[count]) && (pos_tab[++count]))
			if (room->path[best_pos]->depth > room->path[pos_tab[count]]->depth)
				best_pos = pos_tab[count];
		return (best_pos);
	}
	return (-1);
}

static void		send_ants(t_lem **lems, int i, int best_pos, int j)
{
	int			*pos_tab;
	int			path_amount;

	while (lems[i])
	{
		path_amount = 0;
		while (lems[i]->room->path[path_amount])
			path_amount++;
		pos_tab = malloc(sizeof(int) * path_amount);
		j = -1;
		while (++j < path_amount)
			pos_tab[j] = -1;
		free(pos_tab);
		best_pos = best_room(lems[i]->room, pos_tab);
		if ((best_pos != -1) && (lems[i]->room->finish != 1))
		{
			lems[i]->room->ants--;
			lems[i]->room = lems[i]->room->path[best_pos];
			ft_printf("L%d-%s ", lems[i]->l_n, lems[i]->room->room_id);
			(lems[i]->room->finish != 1) ? lems[i]->room->ants = 1
			: lems[i]->room->ants++;
		}
		i++;
	}
	ft_putchar('\n');
}

int				place_ants(t_room **room)
{
	t_room		*fin;
	t_lem		**lems;

	fin = *room;
	while (fin && (0 == fin->finish))
		fin = fin->next;
	fin = (fin && 0 == fin->finish) ? 0 : fin;
	lems = deliver_lems_list(room, -1);
	ft_putchar('\n');
	while (fin->ants < g_lemin->amount)
		send_ants(lems, 0, -1, -1);
	clear_ant_struct(&lems);
	return (0);
}
