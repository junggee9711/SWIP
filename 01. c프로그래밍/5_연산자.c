#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;

	int r = c++ || ++a && b++;
	printf("%d", r);
	return 0;
}