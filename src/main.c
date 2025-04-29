/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:03:24 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 00:52:15 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include "ft_printf.h"

#include <stdio.h>

#include <stdlib.h>

t_settings get_default_settings(void)
{
	t_settings res;

	res.center_x = 500;
	res.center_y = 500;
	res.depth = 2;
	res.elips_a = 20;
	res.elips_b = 10;
	res.rotation = 30;
	res.zoom = 1;
	return (res);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_pt3	**map;
	t_settings	settings;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <fdf file to show>\n");
		return (0);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	if (!mlx)
		return (0);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		return (0);
	settings = get_default_settings();
	map = parse_map(argv[1], &settings);
	if (!map)
		return (0);
	render(image, map, &settings, mlx);
	ft_hook(mlx, image, map, &settings);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit(0);
}
