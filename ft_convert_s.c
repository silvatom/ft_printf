#include "ft_printf.h"

int	ft_putnstr(char *str, int size);
size_t	ft_strlen_printf(char *str);

int	ft_convert_s(char *str)
{
	size_t	len_str;
	size_t	len_p;

	len_str = 0;
	len_p = 0;
	len_str = ft_strlen_printf(str);
	if (t_subspec.precision < len_str && t_subspec.is_dot)
		len_str = t_subspec.precision;
	if (t_subspec.width > len_str)
	{
		if (t_subspec.is_msign)
		{
			len_p += ft_putnstr(str, len_str);
			len_p += ft_print_width(' ', t_subspec.width - len_str);
			return (len_p);
		}
		else if (t_subspec.is_zero)
			ft_print_width('0', t_subspec.width - len_str);
		else
			ft_print_width(' ', t_subspec.width - len_str);
		ft_putnstr(str, len_str);
		len_p = t_subspec.width;
	}
	else
		len_p += ft_putnstr(str, len_str);
	/*if (t_subspec.is_msign)
	{
		if (t_subspec.width > len_str)
		{
			len_p += ft_putnstr(str, len_str);
			len_p += ft_print_width(' ', t_subspec.width - len_str);
		}
		else
			len_p += ft_putnstr(str, len_str);
	}
	else
	{
		if (t_subspec.is_zero)
			len_p += ft_print_width('0', t_subspec.width - len_str);
		else
			len_p += ft_print_width(' ', t_subspec.width - len_str);
		len_p += ft_putnstr(str, len_str);
	}*/
	return (len_p);
}

int	ft_putnstr(char *str, int size)
{
	int i;

	i = 0;
	if (!str)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	while (i < size)
	{
			write(1, &str[i], 1);
			i++;
	}
	return (i);
}

size_t	ft_strlen_printf(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (6);
	while (str[len])
		len++;
	return (len);
}
