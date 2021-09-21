/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:03:17 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/20 22:44:09 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_xu(unsigned int nbr, unsigned int base_n, char b)
{
	unsigned int	tmp;
	int				nbr_s;

	if (b == 'x')
		nbr_s = ft_print_number(nbr, base_n, "0123456789abcdef");
	else if (b == 'X')
		nbr_s = ft_print_number(nbr, base_n, "0123456789ABCDEF");
	else if (b == 'u')
		nbr_s = ft_print_number(nbr, base_n, "0123456789");
	return (nbr_s);
}
