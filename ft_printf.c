/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:29 by gdemirci          #+#    #+#             */
/*   Updated: 2024/12/07 16:21:23 by gdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

static int	ft_formats(va_list *args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg((*args), int)));
	else if (format == 's')
		return (ft_print_string(va_arg((*args), char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg((*args), int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg((*args), unsigned int), format));
	else if (format == 'p')
		return (ft_print_point(va_arg((*args), unsigned long), format));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg((*args), unsigned int)));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_len;
	int		tmp;

	if (!str)
		return (-1);
	printed_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			tmp = ft_formats(&args, *(++str));
			if (tmp == -1 || *(str++) == '\0')
				return (-1);
			printed_len += tmp;
		}
		else if (*str)
		{
			if (ft_print_char(*(str++)) == -1)
				return (-1);
			printed_len++;
		}
	}
	return (va_end(args), printed_len);
}
