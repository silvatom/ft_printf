/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:40:50 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/12 05:13:11 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrsize(t_ull_type nbr, t_ull_type base_n)
{
	size_t	ret;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= (-1);
	ret = 0;
	while (nbr > 0)
	{
		nbr /= base_n;
		ret++;
	}
	return (ret);
}
