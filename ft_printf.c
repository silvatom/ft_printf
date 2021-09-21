/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:38:51 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/20 22:46:00 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_fspec(const char *format, va_list args, unsigned int flen)
{
	if (*format == 'c')
		printf("c encontrado");
	else if (*format == 's')
		printf("s encontrado");
	else if (*format == 'p')
		printf("p encontrado");
	else if (*format == 'd' || *format == 'i')
		flen += ft_convert_d_i(va_arg(args, int), 10);
	else if (*format == 'u')
		flen += ft_convert_xu(va_arg(args, int), 10, 'u');
	else if (*format == 'x')
		flen += ft_convert_xu(va_arg(args, unsigned int), 16, 'x');
	else if (*format == 'X')
		flen += ft_convert_xu(va_arg(args, unsigned int), 16, 'X');
	else if (*format == '%')
		printf("%% encontrado");
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
