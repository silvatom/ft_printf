/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:45:15 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/12 09:46:33 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../includes/deftypes.h"

int			ft_atoi(const char *str);
int			ft_nbrsize(t_ull_type nbr, t_ull_type base_n);
int			ft_putchar(char c);
int			ft_putstr(char *str);
t_ull_type	ft_power(long long number, long int power);

#endif
