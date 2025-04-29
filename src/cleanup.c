/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:58:33 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 04:26:44 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "MLX42/MLX42.h"
#include "fdf.h"
#include <stdlib.h>

void	free_map(t_pt3 **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup_resources(t_fdf *fdf)
{
	if (fdf->image)
		mlx_delete_image(fdf->mlx, fdf->image);
	if (fdf->mlx)
		mlx_terminate(fdf->mlx);
	if (fdf->map)
		free_map(fdf->map, fdf->settings.map_height);
	if (fdf->param)
		free(fdf->param);
}
