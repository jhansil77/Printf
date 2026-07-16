#include "ft_printf.h"

int	ft_print_type(char c, va_list list)
{
	char	*base_ten;
	char	*base_hex;
	char	*base_HEX;

	base_ten = "0123456789";
	base_hex = "0123456789abcdef";
	base_HEX = "0123456789ABCDEF";
	if (c == 'c')
		return (ft_print_char((char)va_arg(list, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base((long long)va_arg(list, int), base_ten));
	else if (c == 'u')
		return (ft_putnbr_base_ul((unsigned long)va_arg(list, unsigned int), base_ten));
	else if (c == 'x')
		return (ft_putnbr_base_ul((unsigned long)va_arg(list, unsigned int), base_hex));
	else if (c == 'X')
		return (ft_putnbr_base_ul((unsigned long)va_arg(list, unsigned int), base_HEX));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(list, void *), base_hex));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	print_output(char *str, va_list list)
{
	size_t	i;
	int	printed;

	i = 0;
	printed = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			i++;
			printed += ft_print_type(str[i], list);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			printed++;
		}
		i++;
	}
	return (printed);
}

int	ft_printf(char const *format, ...)
{
	va_list	list;
	char	*str;
	int	printed;

	if (!format)
		return (-1);
	printed = 0;
	str = (char *)format;
	va_start(list, format);
	printed = print_output(str, list);
	va_end(list);
	return (printed);
}
