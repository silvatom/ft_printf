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
			len_p += ft_print_width('0', t_subspec.width - 1);
			len_p += write(1, &c, 1);
			return (len_p);
		}
	}
	else
		len_p += write(1, &c, 1);
	return (len_p);
}
