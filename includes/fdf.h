/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:17:43 by esmoreau          #+#    #+#             */
/*   Updated: 2019/01/22 19:17:44 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_struct_data_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_data_point;

typedef struct	s_varxyz
{
	int	j;
	int i;
	int x;
	int y;
	int z;
}				t_varxyz;

typedef struct	s_struct_data_centre
{
	int	x_max;
	int	y_max;

}				t_data_centre;

typedef struct	s_struct_draw
{
	int dx;
	int dy;
	int sx;
	int sy;
	int e;
	int e2;
}				t_draw;
typedef struct	s_struct_data_glo
{
	void			*mlx;
	void			*win;
	int				len_map;
	int				hei_map;
	int				win_len;
	int				win_hei;
	double			reso;
	double			reso_z;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	char			*file;
	char			**split_line;
	t_data_point	**n;
}				t_data_glo;

int				main(int argc, char **argv);
int				ft_open(char *name);
char			*ft_read(char *file);
t_data_glo		dataset(char *file);
int				is_error(char *map, t_data_glo data);
t_data_point	**ft_create_tab(char *file, t_data_glo data);
t_data_point	**malloc_tab_data(t_data_glo data);
void			translate_color(char *tab, t_data_point **n, int i_save, int j);
int				get_next_line(const int fd, char **line);
void			quit_program(int a);
void			stock_data(char *map, t_data_point **n, t_data_glo data);
int				ft_len_i(char const *s, char c);
int				ft_len_j(char **tab);
char			*ft_capitalizer(char *str);
t_data_point	ft_rotate(t_data_point n, t_data_glo data);
t_data_point	**rotate_all(t_data_point **n, t_data_glo data);
void			ft_print_map(t_data_point **n, t_data_glo data);
int				ft_key_pressed(int keycode, void *param);
void			ft_put_centre(t_data_point **n, t_data_glo data);
t_data_centre	find_size(t_data_point **n, t_data_glo data);
void			ft_bresenham(t_data_point a, t_data_point b,
				t_data_glo data);
void			free_tab_1(char **tab);
void			free_tab_2(t_data_glo *data);
void			put_pixel_image(t_data_point n, t_data_glo data, char *str);

#endif
