/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:04:24 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/16 17:04:25 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t len)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	if (!(aiguille[0]))
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] && i < len)
	{
		n = 0;
		j = i;
		while (aiguille[n] == meule_de_foin[j] && j < len)
		{
			n++;
			j++;
			if (!(aiguille[n]))
				return ((char *)&meule_de_foin[i]);
		}
		i++;
	}
	return (NULL);
}
