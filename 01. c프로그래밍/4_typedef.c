#include <stdio.h>
#include <stdint.h>


int main()
{
	typedef int ARR[10];
	ARR arr2;
	printf("%lu\n", sizeof(arr2));
}