/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:27:40 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/09 17:27:41 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		ft_putchar('\n');
	}
}
