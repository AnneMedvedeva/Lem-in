/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:20:14 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:16 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <fcntl.h>
# include <zconf.h>
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include "libft/ft_printf/libftprintf.h"
# include "lemin_l.h"
# include "lemin_a.h"
# include "lemin_r.h"

# define INT_MAX 2147483647
# define START "##start"
# define END "##end"
# define TAB g_lemin->tab

typedef struct s_struct	t_lemin;

typedef struct s_lem	t_lem;

typedef struct s_list_r	t_room;

t_lemin				*g_lemin;

/*
**----------------------error.c
*/
void		ft_error(char *info);

/*
**----------------------del.c
*/
void		clear_ant_struct(t_lem ***ants);
void		clear_list_r(t_room **head);
void		clear_2_arr(char ***arr);

/*
**----------------------validate_room_and_cmd.c
*/
char		*validate_room_and_cmd(t_room **room, short ret_val);

/*
**----------------------path_parse.c
*/
short		path_parse(t_room **head, short ret_val);

/*
**----------------------ft_linkdup.c
*/
int			ft_linkdup(t_room **room, t_room *new_room, int i);

/*
**----------------------place_ants.c
*/
int			place_ants(t_room **room);

/*
**----------------------explore_way.c
*/
int			explore_way(t_room **room);
int			find_way_and_place_depth(t_room **room);

/*
**----------------------new_room_maker.c
*/
int			new_room_maker(char *room_id, int *coord, short *se, t_room **room);

/*
**----------------------room_validation.c
*/
t_room		*room_validation(t_room **room, short *se, int count);

#endif
