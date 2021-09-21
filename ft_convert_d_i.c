/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:34:30 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/20 22:44:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_d_i(long int nbr, unsigned int base_n)
{
	long int		tmp;
	int				nbr_len;
	int				i;

	tmp = nbr;
	nbr_len = 0;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr = nbr * (-1);
		nbr_len++;
	}
	nbr_len += ft_print_number(nbr, base_n, "0123456789");
	return (nbr_len);
}
