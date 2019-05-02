/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_doubletab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:29:57 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/26 19:29:58 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_doubletab(void **tab, int a)
{
	int i;

	i = 0;
	while (tab && i < a)
	{
		ft_memdel(&(tab[i]));
		i++;
	}
	free(tab);
	tab = NULL;
}
