/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:21:00 by esmoreau          #+#    #+#             */
/*   Updated: 2019/02/18 17:21:01 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			translate_color(char *tab, t_data_point **n, int i_save, int j)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = ft_strnew(7);
	while (tab[i] && tab[i] != 'X')
		i++;
	if (tab[i] == 'X')
	{
		i++;
		while (tab[i])
		{
			str[k] = tab[i];
			k++;
			i++;
		}
		n[j][i_save].color = ft_atoi_base(str, 16);
	}
	else
		n[j][i_save].color = 16777215;
	free(str);
}

/*
** Stock_data permet de stocker le x, le y, le z dans le double tableau de
** structures et appelle translate_color pour y stocker la couleur en la
** traduisant en decimal avec atoi_base.
*/

void			stock_data(char *map, t_data_point **n, t_data_glo data)
{
	int		i;
	int		j;
	int		p;
	char	**tab;

	i = 0;
	j = 0;
	p = 0;
	tab = ft_split_spenter(map, 32, '\n');
	while (j != data.hei_map)
	{
		n[j][i].x = i;
		n[j][i].y = j;
		n[j][i].z = ft_atoi(tab[p]);
		translate_color(tab[p], n, i, j);
		i++;
		p++;
		if (i == data.len_map)
		{
			j++;
			i = 0;
		}
	}
	free_tab_1(tab);
}

/*
** malloc un nouveau double tableau de structures pour mettre chaque valeur
** de la map dedans: le x, le y, le z et la couleur.
** le nombre de lignes a été calculé dans data.hei_map
** la longueur des lignes a été calculée dans data.len_map
** appelle stock_data pour stocker les valeurs dans le double tableau
*/

t_data_point	**ft_create_tab(char *file, t_data_glo data)
{
	int				i;
	t_data_point	**n;

	if (!(n = (t_data_point **)malloc(sizeof(t_data_point *) * (data.hei_map))))
		quit_program(4);
	i = -1;
	while (++i < data.hei_map)
	{
		if (!(n[i] = (t_data_point *)malloc(sizeof(t_data_point)
			* (data.len_map + 1))))
		{
			free(n);
			quit_program(4);
		}
	}
	stock_data(file, n, data);
	return (n);
}
