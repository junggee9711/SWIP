// 7_ĳ����3

#include <iostream>

// 2. reinterpret_cast
//	  1) �º�/�캯 ���� �ٸ� Ÿ���� "�ּ�" ĳ����.
//	  2) ���� <=> �ּ� ������ ĳ����.

int main()
{
	int n = 10;

//	double* p1 = static_cast<double*>(&n);			// error.
	double* p1 = reinterpret_cast<double*>(&n);		// ok. �ǵ������� �̰��� �����ϰ� �ؼ� �ش� �κ��� �����

//	*p1 = 3.4;		// ��, ĳ���� �Ǿ �̷��� ��������� ���ƾ���.

//	int* p2 = 1000;									// error. pointer �� 0 �̿� ������ �ʱ�ȭ �Ұ�.
	int* p2 = (int*)1000;							// ok. �����ϴ�.
//	int* p2 = static_cast<int*>(1000);				// error. ������ �ּҷ� �����ϴ°��� �ո������� ����.
	int* p2 = reinterpret_cast<int*>(1000);			// ok.


	int n2 = reinterpret_cast<int>(3.4);			// error. �ּ� ���� ĳ���ø� ����.
													// static_cast �� ����ϰų�,
													// ĳ������ ���ϸ� ok.

}