# ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_convert_d_i(long int nbr, unsigned int base_n);
int	ft_convert_xu(unsigned int nbr, unsigned int base_n, char b);

// colocar em outro lugar estas funções (ft_power & print_number)

static int	ft_power(int number, int power)
{
	if (power == 0)
		return (1);
	number *= ft_power(number, power - 1);
	return(number);
}

static int ft_print_number(unsigned int nbr, unsigned int base_n, char *base)
{
	int	nbr_s;
	int	tmp;
	int	n_print;
	int	ret;

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

# endif
