#include <iostream>
#include <stdlib.h>

int main()
{
	// ����ڰ� -1 �� �Է��Ҷ� ���� �Է¹޾ƾ� �Ѵ�.
	// �׷���, �Է°��� �ݵ�� �����ϰ� �־�� �Ѵ�. (���� �迭)

	int count = 0;					// �Էµ� ����
	int size = 5;					// ���� ũ�� (�迭 ũ��)
	int n = 0;

	int* buff = new int[size];

	while (1) {
		std::cin >> n;
		if (n == -1) break;

		buff[count] = n;
		++count;

		if (count == size) {
			int* temp = new int[size + 5];			// ���� �迭 ũ�⺸�� 5 ��ŭ ū �迭�� ���� �Ҵ�

			memcpy(temp, buff, sizeof(int) * size); // ���� ������ �迭(temp)�� ���� �迭(buff) ���� ���� ũ�⸸ŭ ����

			delete[] buff;

			buff = temp;

			size = size + 5;
		}
		std::cout << "�Էµ� ���� : " << count << std::endl;

		for (int i = 0; i < count; i++)				// range for ��� �Ұ�. �迭�� ũ�Ⱚ�� ���� ������
			std::cout << buff[i] << std::endl;

		delete[] buff;
	}


}