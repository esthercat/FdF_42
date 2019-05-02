/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:16:05 by esmoreau          #+#    #+#             */
/*   Updated: 2019/01/22 20:15:31 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	char		*file;
	t_data_glo	data;

	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename>\n");
		return (0);
	}
	file = ft_read(argv[1]);
	data = dataset(file);
	if (is_error(file, data) != 1)
		quit_program(3);
	free_tab_1(data.split_line);
	data.n = ft_create_tab(data.file, data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_len, data.win_hei, "FDF");
	data.n = rotate_all(data.n, data);
	ft_print_map(data.n, data);
	mlx_hook(data.win, 2, 0, ft_key_pressed, &data);
	mlx_loop(data.mlx);
	return (0);
}
