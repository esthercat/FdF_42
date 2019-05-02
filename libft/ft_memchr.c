/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:33:44 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/15 13:33:47 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	p;
	unsigned char	*str;
	size_t			i;

	p = (unsigned char)c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (str[i] != p)
			i++;
		else
			return (&str[i]);
	}
	return (NULL);
}
