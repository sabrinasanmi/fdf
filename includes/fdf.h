/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:08:41 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 00:56:07 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 1000

#include <MLX42/MLX42.h>
#include <stdio.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_point3
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}	t_pt3;

typedef struct s_point2
{
	double	x;
	double	y;
	t_color	color;
}	t_pt2;

typedef struct s_settings
{
	float	rotation;
	int		center_x;
	int		center_y;
	int		index_offset_x;
	int		index_offset_y;
	double	zoom;
	double	elips_a;
	double	elips_b;
	int		map_width;
	int		map_height;
	double	depth;
	double	rotation_speed;
}	t_settings;

typedef struct s_mouse_event
{
	t_pt2	start;
	t_pt2	start_iso;
	t_pt2	end;
}	t_mouse_event;

typedef struct s_vector2
{
	double	x;
	double	y;	
}	t_vector2;

typedef struct s_param
{
	t_settings		*cfg;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_pt3		**map;
	t_mouse_event	*mouse;
}	t_param;

void	render(mlx_image_t *image, t_pt3 **map, t_settings *settings, mlx_t *mlx);
void	ft_hook(mlx_t *mlx, mlx_image_t *image, t_pt3 **map, t_settings *cfg);
void	get_base_vectors(t_vector2 *u, t_vector2 *v, t_settings *settings);
t_pt3	**parse_map(char *s, t_settings *settings);
int		get_color(t_color color);
#endif