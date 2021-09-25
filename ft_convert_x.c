/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:03:17 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/24 17:22:58 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_x(unsigned int nbr, unsigned int base_n, char b)
{
	int	nbr_s;

	nbr_s = 0;
	if (b == 'x')
		nbr_s = ft_print_number(nbr, base_n, "0123456789abcdef");
	else if (b == 'X' || b == 'p')
		nbr_s = ft_print_number(nbr, base_n, "0123456789ABCDEF");
	return (nbr_s);
}
