/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:12:04 by sabsanto          #+#    #+#             */
/*   Updated: 2025/02/08 05:20:18 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_container(int fd, char *buf, char *container)
{
	int		readcount;
	char	*tmp;

	readcount = 1;
	tmp = NULL;
	while (readcount != 0)
	{
		readcount = read(fd, buf, BUFFER_SIZE);
		if (readcount == -1)
			return (NULL);
		if (readcount == 0)
			break ;
		buf[readcount] = '\0';
		if (!container)
			container = ft_strdup("");
		tmp = container;
		container = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(container, '\n'))
			break ;
	}
	return (container);
}

char	*dismember_line(char *line)
{
	int		end;
	char	*remaining;
	char	*newline;

	if (line && ft_strchr(line, '\n'))
	{
		newline = ft_strchr(line, '\n');
		end = ft_strlen(line) - ft_strlen(newline) + 1;
		remaining = ft_strdup(newline + 1);
		line[end] = '\0';
		return (remaining);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = fill_container(fd, buf, container);
	free(buf);
	buf = NULL;
	if (line == NULL && container)
		free(container);
	container = dismember_line(line);
	if (line == NULL || *line == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}
