/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:03:47 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/30 23:10:53 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(long long  nbr, long long  base_n, size_t nbr_len);
int ft_int_size(long long nbr, long long base_n);

int	ft_convert_d_i(long long nbr, long long base_n)
{
	long long int	tmp;
	size_t		nbr_len;
	int			len_p;


	len_p = 0;
	tmp = nbr;
	nbr_len = ft_int_size(nbr, base_n);
	if (t_subspec.precision > nbr_len || (t_subspec.is_dot && nbr_len == 0))
		nbr_len = t_subspec.precision;
	if (nbr < 0)
		nbr_len++;
	if (t_subspec.width > nbr_len)
	{
		if (t_subspec.is_msign)
		{
			len_p += ft_print_int(nbr, base_n, nbr_len);// o número deve ser printado aqui
			len_p += ft_print_width(' ', t_subspec.width - len_p);
			return (len_p);
		}
		else if (t_subspec.is_zero && !t_subspec.is_dot)
			//len_p += ft_print_width('0', t_subspec.width - nbr_len);
			t_subspec.precision += t_subspec.width;
		else
			len_p += ft_print_width(' ', t_subspec.width - nbr_len/* - t_subspec.precision*/);
	}
	len_p += ft_print_int(nbr, base_n, nbr_len);
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

int	ft_print_int(long long nbr, long long base_n, size_t nbr_len)
{
	int	len_p;

	len_p = 0;
	if (nbr < 0)
	{
		len_p += write(1, "-", 1);
		nbr = -nbr;
	}
	else
	{

	}
	if (nbr_len < t_subspec.precision)
		len_p += ft_print_width('0', t_subspec.precision - nbr_len);
	if (nbr == 0 && t_subspec.is_dot /*t_subspec.precision == 0 */)
		return (0);
	len_p += ft_print_number(nbr, base_n, "0123456789");
	return (len_p++);
}

int ft_int_size(long long nbr, long long base_n)
{
	size_t	ret;

	if (nbr < 0)
		nbr *= (-1);
	if (nbr == 0)
		return (1);
	ret = 0;
	while (nbr > 0)
	{
		nbr /= base_n;
		ret++;
	}
	return (ret);
}
