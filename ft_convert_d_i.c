/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:03:47 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/30 18:31:29 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(long int nbr, long int base_n);

int	ft_convert_d_i(long int nbr, unsigned int base_n)
{
	long int	tmp;
	size_t		nbr_len;
	int			len_p;


	len_p = 0;
	tmp = nbr;
	nbr_len = ft_nbrsize(nbr, base_n);
	//if (t_subspec.precision > nbr_len && t_subspec.is_dot /* && nbr_len == 0 */)
	//	len_p = t_subspec.precision;
	if (t_subspec.width > nbr_len)
	{
		if (t_subspec.is_msign)
		{
			len_p += ft_print_int(nbr, base_n);// o número deve ser printado aqui
			len_p += ft_print_width(' ', t_subspec.width - len_p);
			return (len_p);
		} else if (t_subspec.is_zero)
			len_p += ft_print_width('0', t_subspec.width - nbr_len);
		else
			len_p += ft_print_width(' ', t_subspec.width - len_p/*nbr_len*/ - t_subspec.precision);
	}
	len_p += ft_print_int(nbr, base_n);
	//len_p += ft_print_number(nbr, base_n, "0123456789");
	/*
	nbr_len = 0;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr = nbr * (-1);
		nbr_len++;
	}
	nbr_len += ft_print_number(nbr, base_n, "0123456789");
	*/
	return (len_p);
}

int	ft_print_int(long int nbr, long int base_n)
{
	size_t nbr_len;
	int	len_p;

	len_p = 0;
	nbr_len = ft_nbrsize(nbr, base_n);
	if (nbr < 0)
	{
		len_p += write(1, "-", 1);
	}
	else
	{

	}
	if (nbr_len < t_subspec.precision)
		len_p += ft_print_width('0', t_subspec.precision - nbr_len);
	len_p += ft_print_number(nbr, base_n, "0123456789");
	return (len_p++);
}
