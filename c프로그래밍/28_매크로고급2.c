// �����Ϸ��� �����Ϸ� ������ ���� �̸� ���ǵ� ��ũ�� �ɺ��� �ֽ��ϴ�. (���� define �� �ʿ� ����)
// GNU		   => __GNUC__
// Windows(c1) => _MSC_VER

#include <stdio.h>

int main()
{
#ifdef _MSC_VER
	printf("Windows\n");
#else
	printf("Other\n");
#endif

	return 0;
}