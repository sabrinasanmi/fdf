/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:19:56 by sabsanto          #+#    #+#             */
/*   Updated: 2024/11/01 20:19:15 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				count;
	const unsigned char	*ptr;

	count = 0;
	ptr = (const unsigned char *)s;
	while (count < n)
	{
		if (ptr[count] == (unsigned char)c)
		{
			return ((void *)ptr + count);
		}
		count++;
	}
	return (NULL);
}
