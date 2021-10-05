/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:08:14 by anjose-d          #+#    #+#             */
/*   Updated: 2021/10/04 23:07:05 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef enum e_bool {
	FALSE,
	TRUE
}			t_bool;

typedef unsigned long long int	t_ull_type;
typedef unsigned int			t_uint;

typedef struct s_subspec
{
	t_bool	is_msign;
	t_bool	is_psign;
	t_bool	is_zero;
	t_bool	is_space;
	t_bool	is_hash;
	t_bool	is_dot;
	size_t	width;
	size_t	precision;
}	t_subspec;

int			ft_printf(const char *format, ...);
int			ft_convert_d_i(long long nbr, long long base_n, t_subspec *flags);
int			ft_convert_x(t_uint nbr, t_uint base_n, char x, t_subspec *flags);
int			ft_convert_u(t_uint nbr, t_uint base_n, t_subspec *flags);
int			ft_convert_p(t_ull_type nbr, t_ull_type base_n, t_subspec *flags);

t_ull_type	ft_power(long long number, long int power);
int			ft_print_number(t_ull_type nbr, t_ull_type base_n, char *base);
int			ft_putstr(char *str);
int			ft_putchar(char c);
//novo utils
int			ft_atoi(const char *str);
int			ft_print_width(char chr, int i);
int			ft_nbrsize(unsigned long long nbr, unsigned long long base_n);

// novo diverso
int			ft_convert_c(char c, t_subspec *flags);
int			ft_convert_s(char *str, t_subspec *flags);

#endif
