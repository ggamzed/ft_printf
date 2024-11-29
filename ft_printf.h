#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_formats(va_list *args, const char format);
int	ft_print_string(char *str);
int ft_print_int(int num);
int ft_print_hex(unsigned int num, char format);
int ft_print_unsigned(unsigned int num);

#endif