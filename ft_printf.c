#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_formats(va_list args, const char format)
{
	int		printed_len;

	printed_len = 0;
	if (format == 'c')
		printed_len += ft_print_char(va_arg(args, int)); // neden int ?
	/*
	In function ‘print_numbers’:
den.c:10:22: warning: ‘char’ is promoted to ‘int’ when passed through ‘...’
   10 |     a = va_arg(args, char); // char yapınca böyle warning veriyor
	*/
	/*
	C dilinde, değişken sayıda argümanlarla çalışırken, va_arg makrosu parametrelerin tam türünü bilmek zorundadır. 
	Fakat C dilinde, char türündeki bir argüman, int türüne genişletilir (promote edilir) fonksiyon çağrısı sırasında.
	Genişletme (promotion), değişken sayıda parametre alan fonksiyonlar için gereklidir çünkü:

	Derleyici, küçük türlerin taşınmasını (örneğin, char ve short türlerini) ve işlenmesini daha verimli hale getirebilir.
	Değişken sayıda parametreli fonksiyonlarda, parametrelerin türü belirli olmayabilir, bu nedenle küçük türler (örneğin char) 
	daha geniş türlere (int) genişletilir.
	void func(char a, ...) // peki buradaki a karakteri genişler mi?
	lk parametre (yani a) genişlemez, çünkü değişken sayıda parametrelerin türlerinin 
	genişletilmesi sadece ... kısmındaki parametreler için geçerlidir.
	bellek hizalaması
	*/
	else if (format == 's')
		printed_len += ft_print_string(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		printed_len += ft_print_int(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		printed_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		printed_len += ft_print_point(va_arg(args, unsigned long), format);
	else if(format == 'u')
		printed_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		printed_len += ft_print_char('%');
	return (printed_len);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			args;
	int				printed_len;
	if(str == NULL)
		return (-1);
	i = 0;
	printed_len = 0;
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			printed_len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			printed_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (printed_len);
}
#include <stdio.h>
int	main()
{
	int i = -2;
	ft_printf("%d", i);
}
