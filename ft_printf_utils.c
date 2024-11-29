#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	i;

	i = -1;
	if(!str)
		return (write(1, "(null)", 6));
	while(str[++i])
		write(1, &str[i], 1);
	return (i);
}

int ft_print_int(int num)
{
	int len;

	len = 1;
	if(num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		len += ft_print_int(num / 10);
	write(1, &"0123456789"[num % 10], 1);
	return (len);
}

int ft_print_hex(unsigned int num, char format)
{
	int	len;
	char *num_type;

	len = 1;
	if(format == 'x')
		num_type = "0123456789abcdef";
	if(format == 'X')
		num_type = "0123456789ABCDEF";
	if(num >= 16)
		len += ft_print_hex(num / 16, format);
	write(1, &num_type[num % 16], 1);
	return (len);
}

int ft_print_point(unsigned long num, int sign)
{
	int len;

	len = 1;
	if(sign)
		write(1, "0x", 2);
	if(num >= 16)
		len += ft_print_point(num / 16, 0);
	write(1, &"0123456789abcdef"[num % 16], 1);
	return (len);
}

int ft_print_unsigned(unsigned int num)
{
	int len;

	len = 1;
	if(num >= 10)
		len += ft_print_unsigned(num / 10);
	write(1, &"0123456789"[num % 10], 1);
	return (len);
}
