/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:27:40 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/22 18:27:41 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	list = NULL;
	if (lst)
	{
		list = ft_lstnew(lst->content, lst->content_size);
		list = f(lst);
		list->next = ft_lstmap(lst->next, f);
	}
	return (list);
}
