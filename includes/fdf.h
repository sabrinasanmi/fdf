/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:08:41 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/24 22:55:42 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>          // Para O_RDONLY
# include <stdlib.h>         // Para malloc/free
# include <unistd.h>         // Para close
# include <math.h>           // Para funções matemáticas
# include "mlx.h"            // Para gráficos
# include "libft.h"          // Para libft básica
# include "get_next_line.h"  // Para get_next_line
# include "../libft/ft_printf/include/ft_printf.h"  // Caminho completo para ft_printf

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800
# define DEFAULT_COLOR 0xFFFFFF
# define ESC_KEY 65307

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
int		key_hook(int keycode, t_vars *vars);
void	free_map(t_map *map);
void	error_exit(char *message);
t_point	iso_projection(int x, int y, int z, t_vars *vars);
void	draw_line(t_vars *vars, t_point p0, t_point p1);

#endif
