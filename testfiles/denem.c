#include <stdio.h>

void func(char a, ...)
{
	printf("a size: %zu\n", sizeof(a));
}

int main()
{
	char b = 'x';
	printf("b size: %zu\n", sizeof('x')); // output: b size: 4
	printf("b size: %zu\n", sizeof(b)); // output: b size: 1
}
