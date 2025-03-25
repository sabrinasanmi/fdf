/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:40:28 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/24 16:47:17 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->matrix[y]);
		y++;
	}
	free(map->matrix);
	free(map);
}

int	close_window(t_vars *vars)
{
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free_map(vars->map);
	exit(0);
	return (0);
}

void	handle_projection(t_vars *vars)
{
	vars->projection = !vars->projection;
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
}

void	handle_zoom(int keycode, t_vars *vars)
{
	if (keycode == 65451 && vars->zoom < 100)
		vars->zoom += 1;
	else if (keycode == 65453 && vars->zoom > 1)
		vars->zoom -= 1;
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		close_window(vars);
	else if (keycode == 65451 || keycode == 65453)
		handle_zoom(keycode, vars);
	else if (keycode == 112)
		handle_projection(vars);
	else if (keycode == 65361)
		vars->angle_y -= 0.1;
	else if (keycode == 65363)
		vars->angle_y += 0.1;
	else if (keycode == 65362)
		vars->angle_x -= 0.1;
	else if (keycode == 65364)
		vars->angle_x += 0.1;
	else
		return (0);
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}
