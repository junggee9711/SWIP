// 8_new1 52 page


#include <iostream>
#include <cstdlib>		// malloc �� ����. visual c �� ��� �Ǳ��մϴ�.

int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	free(p1);

	// C++ ��Ÿ���� ���� �޸� �Ҵ�
	int* p2 = new int;				// "new Ÿ��" �� �޸� �Ҵ�
	delete p2;

	int* p3 = new int[10];			// �迭 ��� �Ҵ� (sizeof(int)*10 �ƴ�)
	delete[] p3;					// => "delete[]" �� �����ؾ� �մϴ�.
}

//			    [��ü]				[��ȯ Ÿ��]		   [����]		[�ٽ�]
// malloc :		 �Լ�			void* (ĳ���� �ʿ�)		ũ��		������ ȣ�� �ȵ�
// new	  :	 Ű����(������)		��Ȯ�� Ÿ������ ��ȯ		Ÿ��		 ������ ȣ�� ��

//		 => Ű���� : �����Ϸ��� ��� �Ǿ��ִ� �ܾ�. �ٸ��� ��� �Ұ�.