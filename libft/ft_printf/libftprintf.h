/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:57:00 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/08 12:57:02 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include "../libft.h"
# define CONV "sSpdDioOuUxXcC%"
# define FLAGS "1234567890.lhjz# -+"
# define LEN "hljz"

/*
** ------------------------------ Structure ------------------------------------
*/

typedef struct		s_env
{
	char			*len;
	int				width;
	int				acc;
	int				space;
	int				plus;
	int				minus;
	int				zero;
	int				sharp;
	char			conv;
}					t_env;

/*
** -------------------------------- Format -------------------------------------
*/

uintmax_t			format_u(t_env *p, va_list ap);
intmax_t			format_d(t_env *p, va_list ap);

/*
** -------------------------- Conversion Selector ------------------------------
*/

int					assign_conv(va_list ap, t_env *p);

/*
** ------------------------------- ft_printf -----------------------------------
*/

int					ft_printf(const char *restrict format, ...);

/*
** ------------------------------- Conversion ----------------------------------
*/

int					treat_o_conv(t_env *p, va_list ap);
int					treat_u_conv(t_env *p, va_list ap);
int					treat_ss_conv(t_env *p, va_list ap);
int					treat_d_conv(t_env *p, va_list ap);
int					treat_p_conv(t_env *p, va_list ap);
int					treat_no_conv(t_env *p, int space);
int					treat_c_conv(t_env *p, va_list ap);
int					treat_s_conv(t_env *p, va_list ap);
int					treat_x_conv(t_env *p, va_list ap);

/*
** ------------------------------- Additional ----------------------------------
*/

int					ft_empty(t_env *p, uintmax_t nbr);
int					null_width_handle(t_env *p);

/*
** -------------------------------- Parser -------------------------------------
*/

char				*fill_conv(t_env *p, char **f);
char				*fill_flag(t_env *p, char **f);
char				*fill_len(t_env *p, char **f);
char				*fill_acc(t_env *p, char **f);
char				*fill_width(t_env *p, char **f);

/*
** ------------------------------- Unicode -------------------------------------
*/

void				unicode_conv(wchar_t elem);
int					get_bytes(wchar_t elem);

#endif
