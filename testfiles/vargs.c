#include <stdio.h>

void func(int a, ...)
{
	// va_start
   char *p = (char *) &a + sizeof a;

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
	func(2, 3, 4);
}