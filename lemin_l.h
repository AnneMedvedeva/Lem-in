/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_l.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:20:33 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:35 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_L_H
# define LEMIN_L_H

# include "lemin.h"

/*
**	amount - amount of ants
**	st_r - (start room)
**	fin_r - (finish room)
**	way - declares if the cnnection between start and end is found
**	tab - get_next_line line
*/

typedef struct		s_struct
{
	int				amount;
	int				fd;
	short			st_r;
	short			fin_r;
	short			way;
	char			*tab;
}					t_lemin;
#endif
