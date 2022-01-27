#include <stdio.h>

#include "add.h"


int global = 10;

int main()
{
	int a = 1;
	int b = 2;
	int r = add(a, b);
	printf("%d\n", r);
	printf("%d\n", global);
}