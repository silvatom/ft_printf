/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:33:29 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/04 00:33:54 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(long long nbr, long long base_n);
int	ft_u_size(long long nbr, long long base_n);

int	ft_convert_u(unsigned int nbr, unsigned int base_n)
{
	int				len_p;
	size_t			nbr_len;
	long long int	tmp;

	len_p = 0;
	tmp = nbr;
	nbr_len = ft_u_size(nbr, base_n);
	if (t_subspec.precision > nbr_len || (t_subspec.is_dot && nbr == 0))
		nbr_len = t_subspec.precision;
	if (nbr < 0 || t_subspec.is_space || t_subspec.is_psign)
		nbr_len++;
	if (t_subspec.width > nbr_len)
	{
		if (t_subspec.is_msign)
		{
			len_p += ft_print_u(nbr, base_n);
			len_p += ft_print_width(' ', t_subspec.width - len_p);
			return (len_p);
		}
		else if (t_subspec.is_zero && !t_subspec.is_dot)
			t_subspec.precision += t_subspec.width;
		else
			len_p += ft_print_width(' ', t_subspec.width - nbr_len);
	}
	len_p += ft_print_u(nbr, base_n);
	return (len_p);
}

int	ft_print_u(long long nbr, long long base_n)
{
	int		len_p;
	size_t	nbr_len;

	nbr_len = ft_u_size(nbr, base_n);
	len_p = 0;
	if (t_subspec.is_space)
		len_p += write (1, " ", 1);
	if (t_subspec.is_psign)
		len_p += write(1, "+", 1);
	if (t_subspec.is_space)
		nbr_len++;
	if (nbr_len < t_subspec.precision)
		len_p += ft_print_width('0', t_subspec.precision - nbr_len);
	if (nbr == 0 && t_subspec.is_dot && t_subspec.precision == 0)
		return (0);
	len_p += ft_print_number(nbr, base_n, "0123456789");
	return (len_p++);
}

int	ft_u_size(long long nbr, long long base_n)
{
	size_t	ret;

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
