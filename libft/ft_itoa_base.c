/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:22:25 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/26 18:22:26 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(unsigned int n, int base)
{
	int compt;

	compt = 0;
	while (n != 0)
	{
		n = n / base;
		compt++;
	}
	return (compt);
}

char			*ft_itoa_base(int n, int base)
{
	char			*str;
	char			*bse;
	t_cheat			c;

	c.i = 0;
	c.s = 0;
	bse = "0123456789ABCDEF";
	if (base == 10 && n < 0)
		c.s = 1;
	c.p = (n < 0 ? -(n) : n);
	c.len = ft_len(c.p, base);
	if (!(base >= 2 && base <= 16))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (c.len + c.s + 1 + (n == 0)))))
		return (NULL);
	str[c.len + c.s] = '\0';
	str[0] = (c.s == 1 ? '-' : '0');
	c.i = c.len + c.s - 1;
	while (c.p > 0)
	{
		str[c.i] = bse[c.p % base];
		c.p = c.p / base;
		c.i--;
	}
	return (str);
}
