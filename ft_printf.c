/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:04:40 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/24 17:19:40 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fspec(const char *format, va_list args, unsigned int flen)
{
	if (*format == 'c')
		flen += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		flen += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		flen += ft_convert_p(va_arg(args, size_t), 16);
	else if (*format == 'd' || *format == 'i')
		flen += ft_convert_d_i(va_arg(args, int), 10);
	else if (*format == 'u')
		flen += ft_convert_u(va_arg(args, int), 10);
	else if (*format == 'x')
		flen += ft_convert_x(va_arg(args, unsigned int), 16, 'x');
	else if (*format == 'X')
		flen += ft_convert_x(va_arg(args, unsigned int), 16, 'X');
	else if (*format == '%')
		flen += write(1, "%", 1);
	return (flen);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	flen;

	va_start(args, format);
	flen = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flen = ft_fspec(format, args, flen);
			format++;
		}
		else
		{
			write(1, &*format, 1);
			format++;
			flen++;
		}
	}
	return (flen);
}
