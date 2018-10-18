/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_a.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:20:24 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:26 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_A_H
# define LEMIN_A_H

# include "lemin.h"

typedef struct s_list_r	t_room;

/*
** l_n - ant number
**	room - ant's room
*/

typedef struct		s_lem
{
	int				l_n;
	t_room			*room;
}					t_lem;

#endif
