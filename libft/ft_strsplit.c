/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:44:26 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/15 17:44:27 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		comptmots(const char *s, char c)
{
	int	compt;
	int	i;

	compt = 0;
	i = 0;
	if (!(s))
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			compt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (compt);
}

static int		comptl(const char *str, char c, int i)
{
	int compt;

	compt = 0;
	while (str[i] != c && str[i])
	{
		i++;
		compt++;
	}
	return (compt);
}

static char		**ft_magic(char const *str, char c, int i, char **tab)
{
	int k;
	int j;

	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) *\
				(comptl(str, c, i) + 1))))
				return (NULL);
			while (str[i] != c && str[i])
			{
				tab[j][k] = str[i];
				k++;
				i++;
			}
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(str))
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (comptmots(str, c) + 1))))
		return (NULL);
	tab = ft_magic(str, c, i, tab);
	return (tab);
}
