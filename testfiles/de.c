#include <stdio.h>
#include <unistd.h>
int main()
{
	char *a = "";
	printf("%d", write(1, '\0', 1));
}