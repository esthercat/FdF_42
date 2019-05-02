/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:14:47 by esmoreau          #+#    #+#             */
/*   Updated: 2019/01/22 20:15:50 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_open(char *name)
{
	int	fd;

	if ((fd = open(name, O_RDONLY)) < 0)
		exit(0);
	return (fd);
}

static void	copy(char **new, char *line, int i)
{
	int j;

	j = 0;
	while (line[j])
	{
		new[0][i] = line[j];
		i++;
		j++;
	}
	new[0][i] = '\n';
}

/*
** Cree la map finale en chaine de characteres simple qui sera envoyee dans
** les tests d'erreur.
** Pour cela, ré-ouvre le fichier dans un nouvel fd puis appelle GNL pour qu'a
** chaque passage de GNL sur 1 ligne, on appelle copy pour copier cette ligne
** dans la nouvelle string qui sera la map finale.
*/

static char	*final_file(char *file, int total_len)
{
	int		fd;
	char	*new;
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = 0;
	fd = ft_open(file);
	if (!(new = (char *)malloc(sizeof(char) * total_len + 1)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		copy(&new, line, i);
		len = ft_strlen(line) + 1;
		i += len;
		free(line);
	}
	new[i] = '\0';
	return (new);
}

/*
** Verifie que chaque char est bon
*/

static int	is_good_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == 32 || c == '\n' || c == '\0' || c == ',' || c == '-')
		return (1);
	else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
** ouvre le fichier une premiere fois puis appelle GNL pour verifier que le
** fichier n'est pas infini et compte la longueur du fichier ligne par ligne
** appelle is_good_char a chaque charactere pour premier test d'erreur
** Appelle final_file pour creer une chaine de characteres dans laquelle il y
** aura tout le fichier (chaine de characteres qu'on appelle ensuite dans les
** tests d'erreur, ie la map)
*/

char		*ft_read(char *file)
{
	int		fd;
	char	*line;
	int		total_len;
	int		gnl_value;
	int		i;

	total_len = 0;
	fd = ft_open(file);
	while ((gnl_value = get_next_line(fd, &line)) > 0)
	{
		i = -1;
		while (line[++i])
		{
			if (is_good_char(line[i]) == 0)
				quit_program(1);
		}
		total_len += ft_strlen(line) + 1;
		free(line);
	}
	if (gnl_value == 0 && total_len == 0)
		quit_program(5);
	if (gnl_value == -1)
		exit(0);
	close(fd);
	return (final_file(file, total_len));
}
