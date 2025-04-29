/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:08:41 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 03:49:56 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <MLX42/MLX42.h>
# include <stdint.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_pt3
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}	t_pt3;

typedef struct s_pt2
{
	float	x;
	float	y;
	t_color	color;
}	t_pt2;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_settings
{
	int		center_x;
	int		center_y;
	int		depth;
	int		elips_a;
	int		elips_b;
	int		rotation;
	float	zoom;
	int		map_height;
	int		map_width;
	int		index_offset_x;
	int		index_offset_y;
}	t_settings;

typedef struct s_param
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_pt3		**map;
	t_settings	*cfg;
}	t_param;

t_pt3	**parse_map(char *filename, t_settings *settings);
void	render(mlx_image_t *image, t_pt3 **map, t_settings *cfg, mlx_t *mlx);
void	ft_hook(mlx_t *mlx, mlx_image_t *image, t_pt3 **map, t_settings *cfg);

int		get_color(t_color color);
void	get_base_vectors(t_vec2 *u, t_vec2 *v, t_settings *settings);

void	free_map(t_pt3 **map, int height);
void	ft_cleanup(t_param **param);

#endif
