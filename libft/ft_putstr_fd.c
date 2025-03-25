/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:41:09 by sabsanto          #+#    #+#             */
/*   Updated: 2024/11/01 21:27:04 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char const *s, int fd)
{
	if (fd < 0)
	{
		return ;
	}
	if (!s)
	{
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
