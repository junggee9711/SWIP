// C�� �ٸ� C++�Լ��� Ư¡ 4-2. �Լ� ���ø�2

#include <cstdio>

template<typename T>
T square(T a)
{
	return a * a;
}


int main()
{

	square(3);						
	square(3.4);					

	printf("%p\n", &square);		// error. square �� �޸𸮿� �����ϴ� �Լ��� �ƴϰ�,
									//		  ������ �ð��� �����Ϸ��� ����ϴ� "Ʋ" �̱� ������
									//		  �޸𸮿� ���̴� ���� �ƴϹǷ� �ּҴ� ���Ҽ� �����ϴ�.

	printf("%p\n", &square<int>);	// ok.	  (�ش� �Լ��� �ּҴ� ������ ������ square(3); �� �ּҿ� ����)
									// square<int> �� Ʋ�� ����ؼ� ���� �Լ��Դϴ�.
									// �޸𸮿� �����Ƿ� �ּҸ� ���Ҽ� �ֽ��ϴ�.

}

// C++ ���� �����߿��� �� : ��ü ���� + generic(template)