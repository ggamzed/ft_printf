#include <stdio.h>

int func(int a, ...)
{
	int *p;
	p = (int *) &a;
	p--;
	printf("%d", *p);
}

int main()
{
	func(8, 2);
}