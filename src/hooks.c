/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:22:59 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 03:57:29 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "fdf.h"
#include <stdlib.h>

void	ft_movement_controls(t_param *p)
{
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	if (mlx_is_key_down(p->mlx, MLX_KEY_UP))
		p->cfg->center_y -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
		p->cfg->center_y += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		p->cfg->center_x -= 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		p->cfg->center_x += 5;
}

void	ft_transform_controls(t_param *p)
{
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
		p->cfg->elips_b += 1;
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
		p->cfg->elips_b -= 1;
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
		p->cfg->rotation += 5;
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
		p->cfg->rotation -= 5;
	if (p->cfg->elips_b > p->cfg->elips_a)
		p->cfg->elips_b = p->cfg->elips_a;
	if (p->cfg->elips_b < 0)
		p->cfg->elips_b = 0;
}

void	ft_keyhook(void *params)
{
	t_param	*p;

	p = (t_param *)params;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	ft_movement_controls(p);
	ft_transform_controls(p);
	render(p->image, p->map, p->cfg, p->mlx);
}

void	ft_scrollhook(double xdelta, double ydelta, void *params)
{
	t_param	*p;

	(void) xdelta;
	p = (t_param *)params;
	if (ydelta > 0)
		p->cfg->zoom *= 1.2;
	else if (ydelta < 0)
		p->cfg->zoom /= 1.2;
	p->cfg->depth = 2 * p->cfg->zoom;
	render(p->image, p->map, p->cfg, p->mlx);
}

t_param	*ft_hook(mlx_t *mlx, mlx_image_t *image, t_pt3 **map, t_settings *cfg)
{
	static t_param	*param = NULL;

	if (!param)
	{
		param = calloc(sizeof(t_param), 1);
		if (!param)
			return (NULL);
		param->mlx = mlx;
		param->cfg = cfg;
		param->map = map;
		param->image = image;
	}
	mlx_loop_hook(mlx, ft_keyhook, param);
	mlx_scroll_hook(mlx, ft_scrollhook, param);
	return (param);
}
