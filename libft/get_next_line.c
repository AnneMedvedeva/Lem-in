/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:33:15 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:33:17 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>

static int				ft_buf2_join(char **buf2, char **rst, int *ska)
{
	int					i;
	char				*f;

	*ska = 0;
	f = NULL;
	i = 0;
	buf2[0] = ft_strnew(0);
	f = *buf2;
	*buf2 = ft_strdup(rst[0]);
	ft_strdel(&f);
	while (rst[0][i] != '\n' && rst[0][i] != '\0')
		i++;
	if (rst[0][i] == '\n')
		*ska = 1;
	if (rst[0])
		ft_bzero(rst[0], ft_strlen(rst[0]));
	return (i);
}

static int				ft_buf_read(char **buf2, int fd, int *i)
{
	char				*buf;
	char				*f;

	f = NULL;
	buf = ft_strnew(BUFF_SIZE);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		*i = 0;
		if (!*buf2)
			*buf2 = ft_strnew(0);
		f = *buf2;
		*buf2 = ft_strjoin(*buf2, buf);
		while (buf2[0][*i] != '\n' && buf2[0][*i] != '\0')
			*i += 1;
		ft_strdel(&f);
		if (buf2[0][*i] == '\n')
			break ;
		ft_bzero(buf, BUFF_SIZE);
	}
	ft_strdel(&buf);
	return (*i);
}

static t_list_gnl		*ft_find_fd(const int fd, t_list_gnl **head)
{
	t_list_gnl			*tmp;
	t_list_gnl			*tmp2;

	tmp = *head;
	tmp2 = tmp;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!tmp)
	{
		if ((tmp = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		{
			tmp->fd = fd;
			tmp->next = NULL;
			tmp->rst = NULL;
			while (tmp2 && tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
	}
	return (tmp);
}

static t_list_gnl		*ft_n_g_lst(const int fd)
{
	t_list_gnl			*list;

	list = NULL;
	if ((list = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
	{
		list->fd = fd;
		list->next = NULL;
		list->rst = NULL;
	}
	return (list);
}

int						get_next_line(const int fd, char **line)
{
	static t_list_gnl	*list = NULL;
	t_list_gnl			*tmp;
	int					ska;
	char				*b2;
	int					i;

	if (read(fd, NULL, 0) < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if ((ska = 0) == 0 && !list)
		list = ft_n_g_lst(fd);
	b2 = NULL;
	tmp = ft_find_fd(fd, &list);
	if (tmp->rst && tmp->rst[0] != '\0')
		i = ft_buf2_join(&b2, &tmp->rst, &ska);
	if (ska != 1)
		i = ft_buf_read(&b2, fd, &i);
	if (read(fd, NULL, 0) == 0 && !b2)
		return (0);
	if (b2)
		*line = ft_strsub(b2, 0, i);
	b2 && b2[i] == '\n' ? ft_strdel(&tmp->rst) : ft_strdel(&b2);
	if (b2 && b2[i] == '\n')
		tmp->rst = ft_strdup(&b2[i + 1]);
	ft_strdel(&b2);
	return (1);
}
