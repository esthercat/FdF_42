/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:49:01 by esmoreau          #+#    #+#             */
/*   Updated: 2019/04/03 15:35:41 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham(t_data_point a, t_data_point b, t_data_glo data)
{
	t_draw draw;

	draw.dx = abs(b.x - a.x);
	draw.sx = a.x < b.x ? 1 : -1;
	draw.dy = abs(b.y - a.y);
	draw.sy = a.y < b.y ? 1 : -1;
	draw.e = (draw.dx > draw.dy ? draw.dx : -draw.dy) / 2;
	while (1)
	{
		mlx_pixel_put(data.mlx, data.win, a.x, a.y, b.color);
		if (a.x == b.x && a.y == b.y)
			break ;
		draw.e2 = draw.e;
		if (draw.e2 > -draw.dx)
		{
			draw.e -= draw.dy;
			a.x += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.e += draw.dx;
			a.y += draw.sy;
		}
	}
}

void	ft_print_map(t_data_point **n, t_data_glo data)
{
	int x	;
	int y;

	y = 0;
	ft_put_centre(n, data);
	while (y != data.hei_map)
	{
		x = 0;
		while (x != data.len_map - 1)
		{
			ft_bresenham(n[y][x], n[y][x + 1], data);
			if (y != data.hei_map - 1)
			{
				ft_bresenham(n[y][x], n[y + 1][x], data);
			}
			x++;
		}
		if (y != data.hei_map - 1)
			ft_bresenham(n[y][x], n[y + 1][x], data);
		y++;
	}
}
