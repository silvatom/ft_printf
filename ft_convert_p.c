/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:04:12 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/25 00:10:31 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_p(size_t nbr, size_t base_n)
{
	int	nbr_s;

	if (nbr == 0)
		return (write(1, "(nil)", 5));
	nbr_s = write(1, "0x", 2);
	nbr_s += ft_print_number(nbr, base_n, "0123456789abcdef");
	return (nbr_s);
}
