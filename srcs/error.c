/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:19:34 by esmoreau          #+#    #+#             */
/*   Updated: 2019/02/14 13:54:11 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	quit_program(int a)
{
	if (a == 1)
		ft_putstr("One of the characters is wrong.\n");
	if (a == 2)
		ft_putstr("No file found.\n");
	if (a == 3)
		ft_putstr("File not well formatted\n");
	if (a == 4)
		ft_putstr("A malloc failed\n");
	if (a == 5)
		ft_putstr("Empty file\n");
	exit(0);
}

/*
** Fonction qui compte le nombre d'espaces de la premiere ligne et compare avec
** les lignes d'apres pour voir s'il y a bien le meme nombre
*/

int		compare_spaces(char **test, t_data_glo data)
{
	int j;

	j = 0;
	if (data.len_map == 0 || data.hei_map == 0)
		return (0);
	while (test[j])
	{
		if (ft_len_i(test[j], ' ') != data.len_map)
			return (-1);
		j++;
	}
	return (0);
}

/*
** Verifie qu'il n'y a que des chiffres, espaces, \n et \0 dans le fichier
** Si il y a un espace, verifie qu'il y a bien un chiffre apres cet espace et
** rien d'autre
** Verifie le cas ou le fichier comporte juste un \n  OU UN ESPACE suivi d'un
** \0
** Appelle compt_spaces pour verifier qu'il y a le meme nombre d'espaces a
** chaque ligne
*/

int		is_error(char *map, t_data_glo data)
{
	int i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		if (map[i] == '\n' && map[i - 1] == 32)
		{
			return (0);
		}
		if (map[i] == 32 || map[i] == '\n')
		{
			while ((map[i] == 32 || map[i] == '\n') && (map[i + 1] != '\0'))
				i++;
			if (map[i] == '\n' && map[i + 1] == '\0')
				break ;
			if ((map[i] < '0' || map[i] > '9') && (map[i] != '-'))
				return (0);
		}
		i++;
	}
	if (compare_spaces(data.split_line, data) == -1)
		return (0);
	return (1);
}
