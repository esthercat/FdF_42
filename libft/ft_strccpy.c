/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:12:32 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/26 19:12:33 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *src, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i] && src[i] != c)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = src[i];
	new[i + 1] = '\0';
	return (new);
}
