/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:44:06 by esmoreau          #+#    #+#             */
/*   Updated: 2019/04/24 18:37:31 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	change_angles(int keycode, t_data_glo *data)
{
	if (keycode == 18)
	{
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	else
	{
		data->angle_x = 0.78;
		data->angle_y = 0.78;
		data->angle_z = -0.78;
	}
}

static void	modif_data(int keycode, t_data_glo *data)
{
	if (keycode == 126)
		data->angle_x = data->angle_x + 0.1;
	else if (keycode == 125)
		data->angle_x = data->angle_x - 0.1;
	else if (keycode == 123)
		data->angle_z = data->angle_z - 0.1;
	else if (keycode == 124)
		data->angle_z = data->angle_z + 0.1;
	else if (keycode == 38)
		data->angle_y = data->angle_y - 0.1;
	else if (keycode == 37)
		data->angle_y = data->angle_y + 0.1;
	else if (keycode == 27)
		data->reso = data->reso + 0.5;
	else if (keycode == 24)
		data->reso = data->reso - 0.5;
	else if (keycode == 13)
		data->reso_z = data->reso_z - 0.5;
	else if (keycode == 1)
		data->reso_z = data->reso_z + 0.5;
	else if (keycode == 18 || keycode == 19)
		change_angles(keycode, data);
}

int			ft_key_pressed(int keycode, void *param)
{
	t_data_glo		*data;
	t_data_point	**tmp;
	int				i;

	i = 0;
	data = (t_data_glo *)param;
	if (keycode == 53)
	{
		free_tab_2(data);
		exit(0);
	}
	modif_data(keycode, data);
	mlx_clear_window(data->mlx, data->win);
	free_tab_2(data);
	data->n = ft_create_tab(data->file, *data);
	tmp = rotate_all(data->n, *data);
	ft_print_map(tmp, *data);
	while (i != data->hei_map)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (0);
}
