/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:08:14 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/30 20:05:12 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef enum {FALSE, TRUE} e_bool;

struct s_subspec
{
	e_bool 	is_msign;
	e_bool 	is_psign;
	e_bool 	is_zero;
	e_bool 	is_space;
	e_bool 	is_hash;
	e_bool 	is_dot;
	size_t	width;
	size_t	precision;
}	t_subspec;

int	ft_printf(const char *format, ...);
int	ft_convert_d_i(long long nbr, long long base_n);
int	ft_convert_x(unsigned int nbr, unsigned int base_n, char b);
int ft_convert_u(unsigned int nbr, unsigned int base_n);
int	ft_convert_p(unsigned long long nbr, unsigned long long base_n);

unsigned long long	ft_power(long long number, long int power);
int	ft_print_number(unsigned long long nbr, unsigned long long base_n, char *base);
int	ft_putstr(char *str);
int	ft_putchar(char c);
//novo utils
int	ft_atoi(const char *str);
int	ft_print_width(char chr, int i);
int ft_nbrsize(unsigned long long nbr, unsigned long long base_n);

// novo diverso
int	ft_convert_c(char c);
int	ft_convert_s(char *str);

#endif
