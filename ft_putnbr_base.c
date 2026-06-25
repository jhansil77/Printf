#include "libft.h"

int	ft_putnbr_base_ul(unsigned long nbr, char *base)
{
	int	base_n;
	char	c;
	int	count;

	base_n = ft_strlen(base);
	count = 0;
	if (nbr >= (unsigned long)base_n)
	{
		count += ft_putnbr_base_ul(nbr / base_n, base);
		count += ft_putnbr_base_ul(nbr % base_n, base);
	}
	else
	{
		c = base[nbr % base_n];
		write(1, &c, 1);
		count += 1;
	}
	return (count);
}

int ft_putnbr_base(long long nbr, char *base)
{
	int	base_n;
	char	c;
	int	count;

	base_n = ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		write (1, "-", 1);
		count += 1;
	}
	if (nbr >= base_n)
	{
		count += ft_putnbr_base(nbr / base_n, base);
		count += ft_putnbr_base(nbr % base_n, base);
	}
	else
	{
		c = base[nbr % base_n];
		write (1, &c, 1);
		count += 1;
	}
	return (count);
}

int ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int ft_print_str(char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	return (ft_strlen(str));
}

int	ft_print_ptr(void *ptr, char *base)
{
	if (ptr)
		return (ft_print_str("0x") + ft_putnbr_base_ul((unsigned long)ptr, base));
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
}