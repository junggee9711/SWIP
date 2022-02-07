// 7_ĳ����2 50 page

#include <iostream>

// C++ �� �뵵 ���� ����ϱ� ���� "4��"�� ĳ������ ���� 
//
// 1. static_cast : '����(�ո���)'���� �´� ��츸 ���

int main()
{
	double d = 3.4;

	// 1) primitive type ���� �� ĳ���� ���
//	int n = (int)d;
	int n = static_cast<int>(d);				// ok.

	// 2) void* => �ٸ�Ÿ��* �� ĳ����
	int* p = static_cast<int*>(malloc(100));	// ok.
	free(p);

	// 3) ��Ӱ��� Ÿ�Գ����� ĳ���� ��� - 1/26�Ͽ� ���
	
	// �� ���� ���� ��κ� ����
	// �Ʒ� �ڵ�� ���� "�º�/�캯 ���� ������ ����" Ÿ���� �ּ� ĳ������ ��� ����.
//	double* p1 = static_cast<double>(&n);		// error.

}