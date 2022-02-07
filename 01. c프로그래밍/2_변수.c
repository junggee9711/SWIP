#include <stdio.h>


int main(void)
{
	int num;
	double d;
	float f;


	num = 42;
	d = 3.14;
	f = 3.14;
	printf("num = %010d\n", num);
	printf("%x\n", num);
	printf("%X\n", num);
	printf("%o\n", num);

	printf("%lf\n", d);
	printf("%f\n", f);
	return 0;
}