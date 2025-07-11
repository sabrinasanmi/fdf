/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:49:08 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 03:17:45 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static double	get_radians(double angle)
{
	return (angle * 3.141592654 / 180);
}

void	get_base_vectors(t_vec2 *u, t_vec2 *v, t_settings *settings)
{
	double	radians;

	radians = get_radians(settings->rotation);
	u->x = settings->elips_a * cos(radians);
	u->y = settings->elips_b * sin(radians);
	v->x = settings->elips_a * sin(radians);
	v->y = -settings->elips_b * cos(radians);
	u->x *= settings->zoom;
	u->y *= settings->zoom;
	v->x *= settings->zoom;
	v->y *= settings->zoom;
}
