#include <iostream>

// void f1(int arr[3])			
void f1(int* p, int size)
{

}

template<typename T, int N>		// ���ø��� typename ��� ������ ����
int size(T (&arr)[N])
{
	return N;
}
int main()
{
	int x[3] = { 1,2,3 }		// 1) error. �迭�� ����� �� �����Ƿ�!!

	f1(&x[0], 3);				// 2) �迭�� 1��° ����� �ּ� ����
								//	  => �迭�� ũ�⸦ ���� �ؾ���.
	f1(x, 3);					//	  => Decay ����					

	int n = size(x);			// 3) C++ ������ �迭�� ũ�⸦ ���ϴ� �Լ��� ���� �� �ֽ��ϴ�.

	for (auto n : x)			// 4) x �� ������ ���ϴ� ������ ���� �����մϴ�.
	{

	}
}