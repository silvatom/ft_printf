/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:04:12 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/04 15:59:01 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hexa_printing(t_ull_type nbr, t_ull_type base_n);

int	ft_convert_p(t_ull_type nbr, t_ull_type base_n)
{
	size_t	print_s;
	size_t	nbr_s;

	nbr_s = 2;
	nbr_s += ft_nbrsize(nbr, base_n);
	print_s = 0;
	if (t_subspec.width > nbr_s)
	{
		if (t_subspec.is_msign)
		{
			print_s += ft_hexa_printing(nbr, base_n);
			print_s += ft_print_width(' ', t_subspec.width - nbr_s);
			return (print_s);
		}
		else if (t_subspec.is_zero)
			print_s += ft_print_width('0', t_subspec.width - nbr_s);
		else
			print_s += ft_print_width(' ', t_subspec.width - nbr_s);
		print_s += ft_hexa_printing(nbr, base_n);
	}
	else
		print_s += ft_hexa_printing(nbr, base_n);
	return (print_s);
}

static size_t	ft_hexa_printing(t_ull_type nbr, t_ull_type base_n)
{
	int	print_s;

	print_s = 0;
	print_s += write(1, "0x", 2);
	print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
	return (print_s);
}
