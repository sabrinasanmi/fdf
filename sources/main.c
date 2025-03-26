/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:40:52 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/26 18:42:26 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error_exit("Usage: ./fdf <filename.fdf>");
	vars.mlx = mlx_init();
	if (!vars.mlx)
		error_exit("MLX initialization failed");
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!vars.win)
		error_exit("Window creation failed");
	vars.map = read_fdf(argv[1]);
	if (!vars.map)
		error_exit("Map reading failed");
	vars.zoom = 20;
	vars.angle_x = 0;
	vars.angle_y = 0;
	vars.angle_z = 0;
	vars.offset_x = WIN_WIDTH / 2;
	vars.offset_y = WIN_HEIGHT / 2;
	vars.projection = 0;
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	draw_map(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
