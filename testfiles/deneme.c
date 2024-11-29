#include <unistd.h>
int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int main()
{
	ft_print_char(37);
}