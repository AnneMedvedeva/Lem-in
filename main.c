/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:20:55 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:56 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ants_parse(int ret_val)
{
	char		*tab;

	while (1)
	{
		ret_val = get_next_line(g_lemin->fd, &tab);
		ft_putendl(tab);
		if (!tab && (('#' == tab[0]) || !ft_strequ(tab, "##start")
			|| !ft_strequ(tab, "##end")))
			ft_strdel(&tab);
		if (tab && (('#' != tab[0]) || ft_strequ(tab, "##start")
			|| ft_strequ(tab, "##end")))
		{
			if (ft_strequ(tab, "##start") || ft_strequ(tab, "##end"))
				ft_error("ERROR! Command in start of file");
			if (!ft_str_digit(tab))
				ft_error("ERROR! Wrong ants");
			if (ft_str_digit(tab))
				g_lemin->amount = ft_atoi(tab);
		}
		ft_strdel(&tab);
		if ((g_lemin->amount != -1) || (ret_val <= 0))
			break ;
	}
	if ((INT_MAX <= g_lemin->amount) || (0 >= g_lemin->amount))
		ft_error("ERROR! Wrong ants");
}

static void		fill_lemin(void)
{
	g_lemin->st_r = 0;
	g_lemin->fin_r = 0;
	g_lemin->way = 0;
}

static void		lem_in(void)
{
	char	*tab;
	t_room	*rooms;

	fill_lemin();
	g_lemin->amount = -1;
	ants_parse(1);
	rooms = NULL;
	tab = validate_room_and_cmd(&rooms, 1);
	path_parse(&rooms, 1);
	clear_list_r(&rooms);
}

int				main(int ac, char **av)
{
	int		i;

	g_lemin = malloc(sizeof(t_lemin));
	if (ac < 2)
	{
		g_lemin->fd = 0;
		lem_in();
		free(g_lemin);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if ((g_lemin->fd = open(av[i], O_RDONLY)) < 0)
		{
			ft_printf("Failed opening [%s].\n", av[i]);
			return (-1);
		}
		ft_printf("\n-------------------------------Result-of---%s\n\n", av[i]);
		lem_in();
		i++;
	}
	free(g_lemin);
	return (0);
}
