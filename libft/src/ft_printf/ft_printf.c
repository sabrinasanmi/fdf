/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:51:19 by sabsanto          #+#    #+#             */
/*   Updated: 2025/04/23 21:17:44 by sabsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	pars(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (*format == 'p')
		count += ft_putptr(va_arg(ap, unsigned long));
	else if (*format == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (*format == 'X')
		count += ft_putuphex(va_arg(ap, unsigned int));
	else if (*format == '%')
		count += ft_putchar('%');
	format++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start (ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' )
		{
			format++;
			count += pars(format, ap);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
