#include <unistd.h>

int ft_int_u_hex(int a, char c, int num_type)
{
	int len;

	if(c == 'x'|| c == 'X' || c == 'u')
		a = (unsigned int)a;
	len = 0;
	if(a == 0)
		return (write(1, "0", 1));
	if(c == 'd' || c == 'i')
	{
		if (a == -2147483648)
			return (write(1, "-2147483648", 11));
		if (a < 0)
		{
			len += write(1, "-", 1);
			a *= -1;
		}
	}
	if(a >= num_type)
		len += ft_int_hex(a / num_type, c, num_type);
	if(c == 'd' || c == 'i' || c == 'u')
		write(1, &"0123456789"[a % num_type], 1);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[a % num_type], 1);
	if (c == 'x')
		write(1, &"0123456789abcdef"[a % num_type], 1);
	return (len + 1);
}