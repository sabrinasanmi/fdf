/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:03:24 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 04:44:32 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include "ft_printf.h"
#include <stdlib.h>

static t_settings	get_default_settings(void)
{
	return ((t_settings){
		.center_x = 500,
		.center_y = 500,
		.depth = 2,
		.elips_a = 20,
		.elips_b = 10,
		.rotation = 30,
		.zoom = 1
	});
}

static int	setup_fdf(mlx_t **mlx, mlx_image_t **image)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	if (!*mlx)
		return (0);
	*image = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (!*image)
	{
		mlx_terminate(*mlx);
		return (0);
	}
	return (1);
}

static int	initialize_resources(t_fdf *fdf, const char *filename)
{
	fdf->settings = get_default_settings();
	if (!setup_fdf(&fdf->mlx, &fdf->image))
		return (0);
	fdf->map = parse_map((char *)filename, &fdf->settings);
	if (!fdf->map)
	{
		mlx_delete_image(fdf->mlx, fdf->image);
		mlx_terminate(fdf->mlx);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf <fdf file to show>\n"), 1);
	if (!initialize_resources(&fdf, argv[1]))
		return (1);
	render(fdf.image, fdf.map, &fdf.settings, fdf.mlx);
	fdf.param = ft_hook(fdf.mlx, fdf.image, fdf.map, &fdf.settings);
	mlx_image_to_window(fdf.mlx, fdf.image, 0, 0);
	mlx_loop(fdf.mlx);
	cleanup_resources(&fdf);
	return (0);
}
