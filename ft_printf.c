#include "ft_printf.h"
#include <unistd.h>

static int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_formats(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_print_point(va_arg(args, unsigned long), format));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (0);
}

int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_len;
	int		tmp;

	printed_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && ft_check(*(++str)))
		{
			tmp = ft_formats(args, *(str++));
			if (tmp == -1)
				return (-1);
			printed_len += tmp;
		}
		else if (*str != '%')
		{
			tmp = ft_print_char(*(str++));
			if (tmp == -1)
				return (-1);
			printed_len += tmp;
		}
	}
	va_end(args);
	return (printed_len);
}
