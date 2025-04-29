/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:22:40 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/23 21:26:01 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_puthex(unsigned long nbr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_puthex(nbr / 16);
	count += write(1, &hex[nbr % 16], 1);
	return (count);
}
