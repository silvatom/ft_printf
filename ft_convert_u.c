#include "ft_printf.h"

int ft_convert_u(unsigned int nbr, unsigned int base_n)
{
	int	nbr_s;

	nbr_s = ft_print_number(nbr, base_n, "0123456789");

	return (nbr_s);
}
