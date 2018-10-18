/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:24:52 by amedvedi          #+#    #+#             */
/*   Updated: 2018/09/27 14:24:53 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;

	ret = NULL;
	if (lst && f)
	{
		ret = (*f)(lst);
		tmp = ret;
		lst = lst->next;
		while (lst)
		{
			tmp->next = (*f)(lst);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (ret);
}
