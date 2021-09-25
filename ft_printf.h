/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:08:14 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/24 17:18:59 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_convert_d_i(long int nbr, unsigned int base_n);
int	ft_convert_x(unsigned int nbr, unsigned int base_n, char b);
int ft_convert_u(unsigned int nbr, unsigned int base_n);
int	ft_convert_p(size_t nbr, size_t base_n);

size_t	ft_power(size_t number, unsigned long int power);
int	ft_print_number(size_t nbr, size_t base_n, char *base);
int	ft_putstr(char *str);
int	ft_putchar(char c);

#endif
