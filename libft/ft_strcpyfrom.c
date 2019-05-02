/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyfrom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:05:24 by esmoreau          #+#    #+#             */
/*   Updated: 2019/03/19 16:05:26 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyfrom(char *src, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i] && src[i] != c)
		i++;
	i++;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
