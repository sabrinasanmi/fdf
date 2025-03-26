/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:43:36 by sabsanto          #+#    #+#             */
/*   Updated: 2025/03/26 18:56:27 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char *line)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*line)
	{
		if (*line != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*line == ' ')
			in_word = 0;
		line++;
	}
	return (count);
}

static int	*parse_line(char *line, int width)
{
	int		*values;
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	values = (int *)malloc(sizeof(int) * width);
	if (!values)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
		return (NULL);
	}
	i = 0;
	while (i < width)
	{
		values[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (values);
}

static void	read_map_dimensions(t_map *map, int fd)
{
	char	*line;

	map->height = 0;
	line = get_next_line(fd);
	if (!line)
		error_exit("Empty file");
	map->width = count_words(line);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	fill_matrix(t_map *map, int fd)
{
	char	*line;
	int		y;

	y = 0;
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->matrix[y] = parse_line(line, map->width);
		free(line);
		if (!map->matrix[y])
			error_exit("Error parsing line");
		y++;
	}
}

t_map	*read_fdf(const char *filename)
{
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening file");
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_exit("Memory allocation failed");
	read_map_dimensions(map, fd);
	close(fd);
	map->matrix = (int **)malloc(sizeof(int *) * map->height);
	if (!map->matrix)
		error_exit("Memory allocation failed");
	fd = open(filename, O_RDONLY);
	fill_matrix(map, fd);
	close(fd);
	return (map);
}
