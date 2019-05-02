/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:47:49 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/15 13:48:31 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_d;
	size_t len_s;
	size_t i;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if ((len_d + 1) > size)
		return (len_s + size);
	while (src[i] != '\0' && (len_d + 1) < size)
	{
		dst[len_d + i] = src[i];
		i++;
		size--;
	}
	dst[len_d + i] = '\0';
	if (src[i] == '\0')
		return (i + len_d);
	return (len_d + len_s);
}
