/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:43:15 by esmoreau          #+#    #+#             */
/*   Updated: 2019/04/24 16:43:17 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_data_centre	find_size(t_data_point **n, t_data_glo data)
{
	t_data_centre	b;
	int				i;
	int				j;

	b.x_max = 0;
	b.y_max = 0;
	j = -1;
	while (++j < data.hei_map)
	{
		i = -1;
		while (++i < data.len_map)
		{
			if (n[j][i].x > b.x_max)
				b.x_max = n[j][i].x;
			if (n[j][i].y > b.y_max)
				b.y_max = n[j][i].y;
		}
	}
	return (b);
}

void			ft_put_centre(t_data_point **n, t_data_glo data)
{
	t_data_centre	b;
	int				i;
	int				j;

	b = find_size(n, data);
	j = -1;
	while (++j < data.hei_map)
	{
		i = -1;
		while (++i < data.len_map)
		{
			n[j][i].y = ((b.y_max - n[j][i].y) + 50);
			n[j][i].x = ((b.x_max - n[j][i].x) + 50);
		}
	}
}

t_data_glo		set_res(t_data_glo data)
{
	int i;
	int j;

	j = 1;
	i = 1;
	data.reso = -1;
	if (data.hei_map < 800 || data.len_map < 800)
	{
		while (((i++ * data.hei_map) < 800) && ((i * data.len_map) < 800))
			if (!(i % 10))
				j++;
		data.reso = -i;
		data.reso_z = -j;
	}
	else
	{
		while ((((data.reso * data.hei_map) < 800)
				|| ((data.reso * data.len_map) < 800)) && (data.reso >= 0.1))
			data.reso += 0.1;
		data.reso_z = -0.1;
	}
	return (data);
}

t_data_glo		dataset(char *file)
{
	t_data_glo	data;

	data.split_line = ft_strsplit(file, '\n');
	data.hei_map = ft_len_j(data.split_line);
	data.len_map = ft_len_i(data.split_line[0], 32);
	data.angle_x = 0.78;
	data.angle_y = 0.78;
	data.angle_z = -0.78;
	data.file = file;
	data.file = ft_capitalizer(file);
	data.win_len = 1600;
	data.win_hei = 1200;
	data = set_res(data);
	return (data);
}
