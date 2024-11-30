#include <unistd.h>

int	ft_print_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_print_int(int num)
{
	int	len;
	int	tmp;

	len = 1;
	if (num == 0)
		return (write(1, "0", 1));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		num *= -1;
	}
	if (num >= 10)
	{
		tmp = ft_print_int(num / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	write(1, &"0123456789"[num % 10], 1);
	return (len);
}

int	ft_print_hex(unsigned int num, char format)
{
	int		len;
	char	*num_type;
	int		tmp;

	len = 1;
	if (format == 'x')
		num_type = "0123456789abcdef";
	if (format == 'X')
		num_type = "0123456789ABCDEF";
	if (num >= 16)
	{
		tmp = ft_print_hex(num / 16, format);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &num_type[num % 16], 1) == -1)
		return (-1);
	return (len);
}

int	ft_print_point(unsigned long num, int flag)
{
	int	len;
	int	tmp;

	len = 1;
	if (flag)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		flag = 0;
		len += 2;
	}
	if (num >= 16)
	{
		tmp = ft_print_point(num / 16, flag);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789abcdef"[num % 16], 1) == -1)
		return (-1);
	return (len);
}

int	ft_print_unsigned(unsigned int num)
{
	int	len;
	int	tmp;

	len = 1;
	if (num >= 10)
	{
		tmp = ft_print_unsigned(num / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[num % 10], 1) == -1)
		return (-1);
	return (len);
}
