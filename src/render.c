/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:23:55 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 02:42:56 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include <string.h>

static t_pt2	**make_points(t_vec2 u, t_vec2 v, t_pt3 **map, t_settings *cfg);
static void		draw_line(t_pt2 start, t_pt2 end, mlx_image_t *image);

static void	draw_and_free(t_pt2 **points, t_settings *cfg, mlx_image_t *image)
{
	int	x;
	int	y;

	x = 0;
	while (x < cfg->map_height)
	{
		y = 0;
		while (y < cfg->map_width)
		{
			if (y != cfg->map_width - 1)
				draw_line(points[x][y], points[x][y + 1], image);
			if (x != cfg->map_height - 1)
				draw_line(points[x][y], points[x + 1][y], image);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < cfg->map_height)
	{
		free(points[x]);
		x++;
	}
	free(points);
}

void	render(mlx_image_t *image, t_pt3 **map, t_settings *cfg, mlx_t *mlx)
{
	t_vec2	u;
	t_vec2	v;
	t_pt2	**points;

	(void) mlx;
	memset(image->pixels, 0, image->width * image->height * sizeof(int32_t));
	get_base_vectors(&u, &v, cfg);
	points = make_points(u, v, map, cfg);
	draw_and_free(points, cfg, image);
}

static t_pt2	get_iso_pos(t_pt3 p, t_vec2 u, t_vec2 v, t_settings *cfg)
{
	t_pt2	res;

	res.x = u.x * (p.x - cfg->index_offset_x);
	res.x += v.x * (p.y - cfg->index_offset_y);
	res.x += cfg->center_x;
	res.y = u.y * (p.x - cfg->index_offset_x);
	res.y += v.y * (p.y - cfg->index_offset_y);
	res.y += cfg->center_y - cfg->depth * p.z;
	return (res);
}

static t_pt2	**make_points(t_vec2 u, t_vec2 v, t_pt3 **map, t_settings *cfg)
{
	int			x;
	int			y;
	t_pt2		**res;

	res = calloc(sizeof (t_pt2 *), cfg->map_width);
	x = 0;
	while (x < cfg->map_height)
	{
		y = 0;
		res[x] = calloc(sizeof(t_pt2), cfg->map_width);
		while (y < cfg->map_width)
		{
			res[x][y] = get_iso_pos(map[x][y], u, v, cfg);
			res[x][y].color = map[x][y].color;
			y++;
		}
		x++;
	}
	return (res);
}

static void	draw_line(t_pt2 start, t_pt2 end, mlx_image_t *image)
{
	int		pixels;
	float	x_step;
	float	y_step;
	float	x;
	float	y;

	if ((start.x < 0 && end.x < 0) || (start.y < 0 && end.y < 0)
		|| (start.x >= WIDTH && end.x >= WIDTH)
		|| (start.y >= HEIGHT && end.y >= HEIGHT))
		return ;
	pixels = (int)fmax(fabs(end.x - start.x), fabs(end.y - start.y));
	if (pixels == 0)
		pixels = 1;
	x_step = (end.x - start.x) / pixels;
	y_step = (end.y - start.y) / pixels;
	x = start.x;
	y = start.y;
	while (pixels-- >= 0)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			mlx_put_pixel(image, (int)x, (int)y, get_color(start.color));
		x += x_step;
		y += y_step;
	}
}
