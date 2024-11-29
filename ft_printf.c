#include "ft_printf.h"

static int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_formats(va_list *args, const char format)
{
	int		printed_len;

	printed_len = 0;
	if (format == 'c')
		printed_len += ft_print_char(va_arg((*args), int)); // neden int ?
	else if (format == 's')
		printed_len += ft_print_string(va_arg((*args), char *));
	else if (format == 'd' || format == 'i')
		printed_len += ft_print_int(va_arg((*args), int));
	else if (format == 'x' || format == 'X')
		printed_len += ft_print_hex(va_arg((*args), unsigned int), format);
	else if(format == 'u')
		printed_len += ft_print_unsigned(va_arg((*args), unsigned int));
	else if (format == '%')
		printed_len += ft_print_char('%');
	return (printed_len);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			args;
	int				printed_len;
	
	i = 0;
	printed_len = 0;
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			printed_len += ft_formats(&args, str[i + 1]);
			i++;
		}
		else
			printed_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (printed_len);
}

int main()
{
	ft_printf("%c", 'a');
}