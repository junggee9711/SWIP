#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#if 0
int main()
{
	int x[5] = { 1,2,3,4,5 };
	int* p1 = x;
	int* p2 = x + 5;
	int* p3 = 0;
	int* p4 = NULL;

	printf("%p\n%p\n", p3, p4);
	printf("%d\n", p2 - p1);
}
#endif

#if 0
int add(int a, int b);
int global = 10;

int main()
{
	int a = 10;
	int b = 20;

	int rst = add(a, b);
	printf("%d", rst);

	return 0;
}
#endif

#if 0
int add()
{
	static int count;
	printf("%d\n", count);
	count++;
}

int main()
{	
	add();
	add();
	add();

	return 0;

}
#endif

int main()
{
	char* s1 = "ABC";
	char s2[] = "ABC";
	char s3[] = "BBC";

	printf("%d\n", strcmp(s3, s2));

	char s4[32];
	strcpy(s4, s3);
	printf("%s\n", s4);

	strcat(s4, s3);
	printf("%s\n", s4);

	printf("%d\n", strlen(s4));

#if 0
	char s5 = "Hello, World good game";
	char* s6 = strtok(s5, " ");
	printf("%s\n", s6);
#endif

	char* s7 = strdup(s4);
	printf("%s\n", s7);

	return 0;
}