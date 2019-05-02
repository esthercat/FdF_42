/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:37:02 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/22 17:37:04 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*new;
	t_list	*tmp;

	new = *alst;
	while (new)
	{
		tmp = new;
		del(new->content, new->content_size);
		free(new);
		new = tmp->next;
	}
	*alst = NULL;
}
