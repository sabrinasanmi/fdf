/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:08:41 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/26 18:42:07 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "mlx.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800
# define KEY_ESC 65307
# define KEY_P 112
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_NUMPAD_P 65451
# define KEY_NUMPAD_M 65453
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define DEFAULT_COLOR 0xFFFFFF

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**matrix;
	int	z_min;
	int	z_max;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		zoom;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		offset_x;
	int		offset_y;
	int		projection;
}	t_vars;

t_map	*read_fdf(const char *filename);
void	draw_map(t_vars *vars);
int		close_window(t_vars *vars);
void	free_map(t_map *map);
void	error_exit(char *message);
t_point	iso_proj(int x, int y, int z, t_vars *vars);
void	draw_line(t_vars *vars, t_point p0, t_point p1);
int		handle_keypress(int keycode, t_vars *vars);

#endif