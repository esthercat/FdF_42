/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:56:27 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/09 17:56:29 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
	{
		new[j] = s1[i];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
