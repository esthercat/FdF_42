/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:44:12 by esmoreau          #+#    #+#             */
/*   Updated: 2019/04/24 16:44:13 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_tab_2(t_data_glo *data)
{
	int i;

	i = 0;
	while (i != data->hei_map)
	{
		free(data->n[i]);
		i++;
	}
	free(data->n);
}

void	free_tab_1(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
