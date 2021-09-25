#include "ft_printf.h"

size_t	ft_power(size_t number, unsigned long int power)
{
	if (power == 0)
		return (1);
	number *= ft_power(number, power - 1);
	return (number);
}

int	ft_print_number(size_t nbr, size_t base_n, char *base)
{
	int		nbr_s;
	size_t	tmp;
	int		n_print;
	int		ret;

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
