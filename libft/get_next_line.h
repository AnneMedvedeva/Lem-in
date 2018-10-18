/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:33:21 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:33:23 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "stdlib.h"
# include "libft.h"
# define BUFF_SIZE 1

typedef	struct			s_list_gnl
{
	int					fd;
	char				*rst;
	struct s_list_gnl	*next;
}						t_list_gnl;

char					*ft_strsub(const char *s, unsigned int start,
	size_t len);
void					ft_strdel(char **as);
char					*ft_strjoin(const char *s1, const char *s2);
size_t					ft_strlen(const char *str);
int						get_next_line(const int fd, char **line);
char					*ft_strdup(char *src);
char					*ft_strnew(size_t size);
void					ft_bzero(void *s, size_t n);
#endif
