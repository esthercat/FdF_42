/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spenter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:25:57 by esmoreau          #+#    #+#             */
/*   Updated: 2019/03/25 14:25:59 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		comptmots(const char *s, char c, char n)
{
	int	compt;
	int	i;

	compt = 0;
	i = 0;
	if (!(s))
		return (0);
	while (s[i])
	{
		while ((s[i] == c || s[i] == n) && s[i])
			i++;
		if (s[i] != c && s[i] != n && s[i])
			compt++;
		while (s[i] != c && s[i] != n && s[i])
			i++;
	}
	return (compt);
}

static int		comptl(const char *str, char c, char n, int i)
{
	int compt;

	compt = 0;
	while (str[i] != c && str[i] != n && str[i])
	{
		i++;
		compt++;
	}
	return (compt);
}

static char		**ft_magic(char const *str, char c, char n, char **tab)
{
	t_var	a;

	a.j = 0;
	a.i = 0;
	while (str[a.i])
	{
		while ((str[a.i] == c || str[a.i] == n) && str[a.i])
			a.i++;
		if (str[a.i])
		{
			a.k = 0;
			if (!(tab[a.j] = (char *)malloc(sizeof(char)
				* (comptl(str, c, n, a.i) + 1))))
				return (NULL);
			while (str[a.i] != c && str[a.i] != n && str[a.i])
			{
				tab[a.j][a.k] = str[a.i];
				a.k++;
				a.i++;
			}
			tab[a.j++][a.k] = '\0';
		}
	}
	tab[a.j] = 0;
	return (tab);
}

char			**ft_split_spenter(char const *str, char c, char n)
{
	char	**tab;

	if (!(str))
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (comptmots(str, c, n) + 1))))
		return (NULL);
	tab = ft_magic(str, c, n, tab);
	return (tab);
}
