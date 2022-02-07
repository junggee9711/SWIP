#include <stdio.h>

// 1. ���Ǻ� ������
// => ���ǵ� ��ũ�ο� ���� �������� �ڵ尡 ����ǵ��� �ϴ� ���
// => ������ �ܰ迡�� ���� �ش� �κ��� �ڵ忡 ���Ե��� �ȵ����� ���� �� �� �ְ� ����

// Windows
// : CreateThread �Լ�
// Linux
// : pthread_create

// #define WINDOWS
// ������ �ܰ迡�� ��ũ�θ� ������ �� �ֽ��ϴ�.

// 2. ��ũ�� �ɺ��� ���� ���θ� üũ�Ѵ�.
//		: #ifdef / #ifndef
//	  ��ũ�� �ɺ��� ���� üũ�Ѵ�.
//		: #if / #elif


#define VERSION 1000

#if VERSION > 1000
void newFeature()
{
	printf("xxx\n");
}
#endif

void foo() 
{
#ifdef WINDOWS
	printf("Windows - foo\n");
#else
	printf("Linux - foo\n");
#endif
}

void process()
{
#ifdef DEBUG
	printf("Process Start\n");
	printf("Processing---\n");
#endif
}

int main()
{
#if VERSION > 1000
	newFeature();
#endif

	foo();
}