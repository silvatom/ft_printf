/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:03:17 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/01 23:21:42 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nbr, char c);
int	ft_put_nbr_hexa(unsigned int nbr, char x);

int	ft_convert_x(unsigned int nbr, unsigned int base_n, char x)
{
	size_t	print_s;
	size_t	nbr_s;

	nbr_s = ft_nbrsize(nbr, base_n);
	print_s = 0;
	// e se nbr for 0?
	/*if (t_subspec.precision > nbr_s || (t_subspec.is_dot && nbr == 0))
		nbr_s = t_subspec.precision;*/
	if (nbr == 0)
		nbr_s++;
	if (t_subspec.width > nbr_s)
	{
		if (t_subspec.is_msign)
		{
			print_s += ft_print_hexa(nbr, x);
			print_s += ft_put_nbr_hexa(nbr, x);
			//print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
			print_s += ft_print_width(' ', t_subspec.width - nbr_s);
			return (print_s);
		}
		else if (t_subspec.is_zero /*&& !t_subspec.is_dot*/)
			print_s += ft_print_width('0', t_subspec.width - nbr_s);
		else
			print_s += ft_print_width(' ', t_subspec.width - nbr_s - 2);
		print_s += ft_print_hexa(nbr, x);
		print_s += ft_put_nbr_hexa(nbr, x);
		//print_s += ft_print_number(nbr, base_n, "0123456789abcdef");
		//return (print_s); //t_subspec.width
	}
	else
	{
		print_s += ft_print_hexa(nbr, x);;
		print_s += ft_put_nbr_hexa(nbr, x);
	}

	return (print_s);


/*
	int	nbr_s;

	nbr_s = 0;
	if (b == 'x')
		nbr_s = ft_print_number(nbr, base_n, "0123456789abcdef");
	else if (b == 'X' || b == 'p')
		nbr_s = ft_print_number(nbr, base_n, "0123456789ABCDEF");
	return (nbr_s);
*/
}

int	ft_print_hexa(unsigned int nbr, char c)
{
	int		ret;
	size_t	nbr_s;

	ret = 0;
	nbr_s = ft_nbrsize(nbr, 16);
	if (nbr == 0)
		nbr_s++;
	if (t_subspec.is_hash && nbr > 0) //pq nbr > 0?
	{
		write(1, "0", 1);
		write(1, &c, 1);
		if (!t_subspec.is_dot)
			ret += 2;
	}
	if (t_subspec.is_dot && nbr == 0 && t_subspec.precision == 0)
		return (0);
	if (t_subspec.precision > nbr_s)
		ret += ft_print_width('0', t_subspec.precision - nbr_s);
	return (ret);
}

int	ft_put_nbr_hexa(unsigned int nbr, char x)
{
	int ret;

	ret = 0;
	if (x == 'x')
		ret = ft_print_number(nbr, 16, "0123456789abcdef");
	if (x == 'X')
		ret = ft_print_number(nbr, 16, "0123456789ABCDEF");
	return (ret);
}
