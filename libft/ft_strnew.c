/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:30:50 by esmoreau          #+#    #+#             */
/*   Updated: 2019/03/18 17:00:06 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (++i < size + 1)
		str[i] = '\0';
	return (str);
}
