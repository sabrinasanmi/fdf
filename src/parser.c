/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:40:28 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/29 03:17:07 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>

t_color	parse_color(char *s)
{
	const char	*hex = "0123456789ABCDEF";
	t_color		res;

	if (!s || ft_strncmp(s, "0x", 2) != 0)
		return ((t_color){.r = 255, .g = 255, .b = 255, .a = 255});
	if (ft_strlen(s) == 5)
	{
		res.r = 17 * (ft_strchr(hex, s[2]) - hex);
		res.g = 17 * (ft_strchr(hex, s[3]) - hex);
		res.b = 17 * (ft_strchr(hex, s[4]) - hex);
		res.a = 255;
	}
	else
	{
		res.r = 16 * (ft_strchr(hex, s[2]) - hex)
			+ (ft_strchr(hex, s[3]) - hex);
		res.g = 16 * (ft_strchr(hex, s[4]) - hex)
			+ (ft_strchr(hex, s[5]) - hex);
		res.b = 16 * (ft_strchr(hex, s[6]) - hex)
			+ (ft_strchr(hex, s[7]) - hex);
		res.a = 255;
	}
	return (res);
}

static int	get_width_from_line(char *line)
{
	char	**split;
	int		width;
	int		i;

	split = ft_split(line, ' ');
	width = 0;
	while (split[width])
		width++;
	i = 0;
	while (i < width)
		free(split[i++]);
	free(split);
	return (width);
}

static int	count_lines_and_width(char *filename, int *width)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (line)
	{
		*width = get_width_from_line(line);
		free(line);
		count++;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	process_map_row(t_pt3 **map, int x, int width, int fd)
{
	char	*line;
	char	**split;
	char	**values;
	int		y;

	line = get_next_line(fd);
	split = ft_split(line, ' ');
	map[x] = calloc(width, sizeof(t_pt3));
	y = 0;
	while (split[y] && y < width)
	{
		map[x][y].x = x;
		map[x][y].y = y;
		values = ft_split(split[y], ',');
		map[x][y].z = ft_atoi(values[0]);
		map[x][y].color = parse_color(values[1]);
		free(values[0]);
		if (values[1])
			free(values[1]);
		free(values);
		free(split[y]);
		y++;
	}
	free(split);
	free(line);
}

t_pt3	**parse_map(char *filename, t_settings *settings)
{
	int		fd;
	int		width;
	int		height;
	int		x;
	t_pt3	**map;

	height = count_lines_and_width(filename, &width);
	if (height == -1)
		return (NULL);
	map = calloc(height, sizeof(t_pt3 *));
	fd = open(filename, O_RDONLY);
	x = 0;
	while (x < height)
	{
		process_map_row(map, x, width, fd);
		x++;
	}
	close(fd);
	settings->map_height = height;
	settings->map_width = width;
	settings->index_offset_x = height / 2;
	settings->index_offset_y = width / 2;
	return (map);
}
