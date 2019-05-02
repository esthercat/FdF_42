/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:43:45 by esmoreau          #+#    #+#             */
/*   Updated: 2019/04/24 16:44:46 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_data_point	ft_rotate(t_data_point n, t_data_glo data)
{
	int				x;
	int				y;
	int				z;
	t_data_point	v;

	v.x = n.x * data.reso;
	v.y = n.y * data.reso;
	v.z = n.z * data.reso_z;
	x = v.x;
	z = v.z;
	v.x = cos(data.angle_y) * x + sin(data.angle_y) * z;
	v.z = -sin(data.angle_y) * x + cos(data.angle_y) * z;
	y = v.y;
	z = v.z;
	v.y = cos(data.angle_x) * y - sin(data.angle_x) * z;
	v.z = sin(data.angle_x) * y + cos(data.angle_x) * z;
	x = v.x;
	y = v.y;
	v.x = cos(data.angle_z) * x - sin(data.angle_z) * y;
	v.y = sin(data.angle_z) * x + cos(data.angle_z) * y;
	v.color = n.color;
	return (v);
}

t_data_point	**rotate_all(t_data_point **n, t_data_glo data)
{
	int				i;
	int				j;
	t_data_point	**rotate_point;

	if (!(rotate_point = malloc_tab_data(data)))
	{
		free_tab_2(&data);
		return (NULL);
	}
	j = -1;
	while (++j < data.hei_map)
	{
		i = -1;
		while (++i < data.len_map)
			rotate_point[j][i] = ft_rotate(n[j][i], data);
	}
	return (rotate_point);
}
