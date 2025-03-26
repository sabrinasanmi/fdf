/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:40:28 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/25 21:50:16 by sabsanto         ###   ########.fr       */
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

static void	redraw(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
}

static void	handle_rotation(int keycode, t_vars *vars)
{
	if (keycode == KEY_LEFT)
		vars->angle_y -= 0.1;
	else if (keycode == KEY_RIGHT)
		vars->angle_y += 0.1;
	else if (keycode == KEY_UP)
		vars->angle_x -= 0.1;
	else if (keycode == KEY_DOWN)
		vars->angle_x += 0.1;
}

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		return (close_window(vars));
	else if (keycode == KEY_P)
		vars->projection = !vars->projection;
	else if (keycode == KEY_PLUS || keycode == KEY_NUMPAD_P)
	{
		if (vars->zoom < 100)
			vars->zoom += 1;
	}
	else if (keycode == KEY_MINUS || keycode == KEY_NUMPAD_M)
	{
		if (vars->zoom > 1)
			vars->zoom -= 1;
	}
	else
	{
		handle_rotation(keycode, vars);
		return (0);
	}
	redraw(vars);
	return (0);
}
