/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:04:40 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/30 18:46:40 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_subspec_init(void);
const char	*ft_subspec(const char *format);
const char *ft_get_subspec(const char *format);

int	ft_fspec(const char *format, va_list args)
{
	int flen;

	flen = 0;
	if (*format == 'c')
		flen += ft_convert_c(va_arg(args, int));
	else if (*format == 's')
		flen += ft_convert_s(va_arg(args, char *));
	else if (*format == 'p')
		flen += ft_convert_p(va_arg(args, long long), 16);
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
			format = ft_subspec(format);
			if (!*format)
				break;
			flen += ft_fspec(format, args);
			format++;
		}
		else
		{
			flen += write(1, &*format, 1);
			format++;
		}
	}
	return (flen);
}

void	ft_subspec_init(void)
{
	t_subspec.is_msign = FALSE;
	t_subspec.is_psign = FALSE;
	t_subspec.is_zero = FALSE;
	t_subspec.is_space = FALSE;
	t_subspec.is_hash = FALSE;
	t_subspec.is_dot = FALSE;
	t_subspec.width = 0;
	t_subspec.precision = 0;
}

const char	*ft_subspec(const char *format)
{
	ft_subspec_init();
	while (*format && (*format == '-' || *format == '+'	||
		*format == ' ' || *format == '#' || *format == '.' ||
		(*format >= '0' && *format <= '9')))
	{
		format = ft_get_subspec(format);
		format++;
	}
	return (format);
}

const char *ft_get_subspec(const char *format)
{
	if (*format == '-')
		t_subspec.is_msign = TRUE;
	else if (*format == '+')
		t_subspec.is_psign = TRUE;
	else if (*format == '0')
		t_subspec.is_zero = TRUE;
	else if (*format == ' ')
		t_subspec.is_space = TRUE;
	else if (*format == '#')
		t_subspec.is_hash = TRUE;
	else if (*format == '.')
	{
		format++;
		t_subspec.is_dot = TRUE;
		t_subspec.precision = ft_atoi(format);
		return (format);
	}
	else if (*format >= '0' && *format <= '9')
	{
		t_subspec.width = ft_atoi(format);
		while (*(format + 1) >= '0' && *(format + 1) <= '9')
			format++;
		return (format);
	}
	return (format);
}
