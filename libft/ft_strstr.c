/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:22:12 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/15 14:22:13 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int i;
	int n;
	int p;

	i = 0;
	if (!(aiguille[i]))
		return ((char *)meule_de_foin);
	while (meule_de_foin[i])
	{
		n = 0;
		p = i;
		while (aiguille[n] == meule_de_foin[p])
		{
			n++;
			p++;
			if (!(aiguille[n]))
				return ((char *)&meule_de_foin[i]);
		}
		i++;
	}
	return (NULL);
}
