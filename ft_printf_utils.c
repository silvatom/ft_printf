#include "ft_printf.h"

unsigned long long	ft_power(long long number, long int power)
{
	if (power == 0)
		return (1);
	number *= ft_power(number, power - 1);
	return (number);
}

int	ft_print_number(unsigned long long nbr, unsigned long long base_n, char *base)
{
	int			nbr_s;
	unsigned long long int	tmp;
	unsigned long long int	n_print;
	int			ret;

	if (nbr < 0)
		nbr *= (-1);
	nbr_s = 1;
	ret = 0;
	tmp = nbr;
	while (tmp >= base_n)
	{
		nbr_s++;
		tmp /= base_n;
	}
	while (--nbr_s >= 0)
	{
		n_print = (nbr / ft_power(base_n, nbr_s));
		write(1, &base[n_print], 1);
		nbr %= ft_power(base_n, nbr_s);
		ret++;
	}
	return (ret);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ' || str[i] == '.')
		i++;
	if (str[i] == '-')
		sign = sign * (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_print_width(char chr, int i)
{
	int	count;
	//if (t_subspec.is_dot && t_subspec.precision == 0)
	//	chr = ' ';
	count = 0;
	while (i > 0)
	{
		count += write(1, &chr, 1);
		i--;
	}
	return (count);
}

int ft_nbrsize(unsigned long long nbr, unsigned long long base_n)
{
	size_t	ret;

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
