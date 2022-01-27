#include <stdio.h>


int main()
{
#if 0
	int count = 0;
	while (count < 100)
	{
		printf("%d", ++count);
	}
#endif
	int i = 0;
	while (i < 10) {
		i++;
		if (i == 5) {
			continue;
		}
		printf("%d\n", i);
	}

	return 0;
}