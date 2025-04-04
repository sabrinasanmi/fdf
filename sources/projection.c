/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:11:36 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/26 18:55:12 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	iso_proj(int x, int y, int z, t_vars *vars)
{
	t_point	point;
	double	angle;

	angle = vars->angle_y;
	point.x = (x - y) * cos(angle) * vars->zoom + vars->offset_x;
	point.y = (x + y) * sin(angle) * vars->zoom - (z * vars->zoom) 
		+ vars->offset_y;
	point.z = z;
	point.color = DEFAULT_COLOR;
	return (point);
}

static void	init_sign(t_point *sign, t_point p0, t_point p1)
{
	if (p0.x < p1.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (p0.y < p1.y)
		sign->y = 1;
	else
		sign->y = -1;
}

static void	draw_pixel(t_vars *vars, t_point cur)
{
	mlx_pixel_put(vars->mlx, vars->win, cur.x, cur.y, cur.color);
}

static void	update_position(t_point *cur, t_point sign, int *error, t_point delta)
{
	int	e2;

	e2 = 2 * *error;
	if (e2 >= delta.y)
	{
		*error += delta.y;
		cur->x += sign.x;
	}
	if (e2 <= delta.x)
	{
		*error += delta.x;
		cur->y += sign.y;
	}
}

void	draw_line(t_vars *vars, t_point p0, t_point p1)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(p1.x - p0.x);
	delta.y = -abs(p1.y - p0.y);
	init_sign(&sign, p0, p1);
	error[0] = delta.x + delta.y;
	cur = p0;
	while (cur.x != p1.x || cur.y != p1.y)
	{
		draw_pixel(vars, cur);
		update_position(&cur, sign, &error[0], delta);
	}
}
