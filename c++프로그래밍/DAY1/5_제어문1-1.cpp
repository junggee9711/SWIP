// 5_���1 38 page


// 1. C++11 �� ���ο� for �� - "range for"

#include <iostream>
#include <string>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	for (int i = 0; i < 10; i++) {
		std::cout << x[i] << std::endl;
	}

	// - range for
	// 1) Python : for n in x:
	// 2) Decay ���ܿ� �ش� (Decay �� �Ͼ�� ����)

	for (auto n : x) {
		std::cout << n << std::endl;
	}

	// 3) ���ڿ��� ���, ���ڿ� �迭 �Ǵ� string �� ����. char* �� �ȵ�
	char s[] = "ABCDEFG";		// range for ����
	std::string s = "ABCDEFG";	// ����
//	const char* s = "ABCDEFG";	// �Ұ���
	
	for (auto c : s) {
		std::cout << c << std::endl;
	}
}