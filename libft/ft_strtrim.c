/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:23:40 by esmoreau          #+#    #+#             */
/*   Updated: 2018/11/15 16:23:41 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == ft_strlen(s))
			return (ft_strdup("\0"));
		len = ft_strlen(s) - 1;
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			len--;
		return (ft_strsub(s, i, (len - i + 1)));
	}
	return (NULL);
}
