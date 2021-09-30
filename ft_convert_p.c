/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:04:12 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/30 19:42:39 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_p(unsigned long long nbr, unsigned long long base_n)
{
	size_t	print_s;
	size_t	nbr_s;

	nbr_s = ft_nbrsize(nbr, base_n);
	print_s = 0;
	// e se nbr for 0?
	if (t_subspec.width > nbr_s)
	{
		if (t_subspec.is_msign)
		{
			print_s += write(1, "0x", 2);
			print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
			print_s += ft_print_width(' ', t_subspec.width - nbr_s - 2);
			return (print_s);
		}
		else if (t_subspec.is_zero)
			print_s += ft_print_width('0', t_subspec.width - nbr_s - 2);
		else
			print_s += ft_print_width(' ', t_subspec.width - nbr_s - 2);
		print_s += write(1, "0x", 2);
		print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
		//return (print_s); //t_subspec.width
	}
	else
	{
		print_s += write(1, "0x", 2);
		print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
	}

	return (print_s);
	/*if (t_subspec.is_msign)
	{
		if (nbr == 0)
		{
			print_s = write(1, "(nil)", 5);
			print_s += ft_print_width(' ', t_subspec.width - print_s);
			return (print_s);
		}
		else
		{
			print_s += write(1, "0x", 2);
			print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
			print_s += ft_print_width(' ', t_subspec.width - nbr_s - 2);
		}
	}
	else
	{
		if (t_subspec.is_zero)
			print_s += ft_print_width('0', t_subspec.width - nbr_s - 2);
		else
			print_s += ft_print_width(' ', t_subspec.width - nbr_s - 2);
		print_s += write(1, "0x", 2);
		print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
	}
	return (print_s);*/
}


