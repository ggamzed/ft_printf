#include <stdio.h>
//0123456789abcdef
//    c   b   a
// geriye doğru
/*
0x16d78b1a4
0x16d78b1a5
0x16d78b1a6
0x16d78b1a7
*/
void func(int a, int b, int c, ...)
{
	printf("a: %p\n", &a);
	printf("b: %p\n", &b);
	printf("c: %p\n", &c);
	// va_start
   int *p = (int *) &a;

	// p += sizeof(a);
	p--;
	printf("=>%d\n", *p);

	p--;
	printf("=>%d\n", *p);
	return ;
   // va_arg
   int i1 = *((int *)p);
   p += sizeof (int);

   // va_arg
   int i2 = *((int *)p);
   p += sizeof (int);

   // va_arg
   long i3 = *((long *)p);
   p += sizeof (long);
	
	printf("%d\n", *p);
}

int main()
{
	func(2, 3, 4, 5, 6, 7, 8);
}