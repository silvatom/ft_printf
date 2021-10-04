/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:19:13 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/04 00:19:14 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_c(char c)
{
	int	len_p;

	len_p = 0;
	if (t_subspec.width > 1)
	{
		if (t_subspec.is_msign)
		{
			len_p += write(1, &c, 1);
			len_p += ft_print_width(' ', t_subspec.width - 1);
		}
		else
		{
			if (t_subspec.is_zero)
				len_p += ft_print_width('0', t_subspec.width - 1);
			else
				len_p += ft_print_width(' ', t_subspec.width - 1);
			len_p += write(1, &c, 1);
			return (len_p);
		}
	}
	else
		len_p += write(1, &c, 1);
	return (len_p);
}
