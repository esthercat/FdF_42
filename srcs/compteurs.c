/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteurs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:00:26 by esmoreau          #+#    #+#             */
/*   Updated: 2019/03/25 17:00:28 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_len_j(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int				ft_len_i(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i])
				word++;
			while (s[i] != c && s[i])
				i++;
		}
		return (word);
	}
	return (0);
}

char			*ft_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

t_data_point	**malloc_tab_data(t_data_glo data)
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
	return (n);
}
