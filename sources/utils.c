/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:03:24 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/26 18:57:04 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
}

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->map->height)
	{
		x = 0;
		while (x < vars->map->width)
		{
			if (x < vars->map->width - 1)
				draw_line(vars,
					iso_proj(x, y, vars->map->matrix[y][x], vars),
					iso_proj(x + 1, y, vars->map->matrix[y][x + 1], vars));
			if (y < vars->map->height - 1)
				draw_line(vars,
					iso_proj(x, y, vars->map->matrix[y][x], vars),
					iso_proj(x, y + 1, vars->map->matrix[y + 1][x], vars));
			x++;
		}
		y++;
	}
}
