// 26 page


#include <iostream>
#include <string>


int main()
{
	// C��� ���ڿ� : char[] �Ǵ� char* - �ʹ� �����մϴ�.
	char s1[] = "ABCD";
	char s2[5];

	// s2 = s1;				// error. strcpy() �ʿ�

	if (s2 == s1) {}		// error �� �ƴ�����, �ּҸ� ���ϹǷ� �׻� false
							// strcmp(s2, s1) == 0 �̸� ���� ���� ���ڿ�

	// 1. string ����� ����� ���ڿ�
	std::string s3 = "ABCD";
	std::string s4;

	s4 = s3;				// 1) ���� ����
	s4 = s4 + s3;			// 2) ������ ���� (s4 = "ABCDABCD", ������ �Ұ�)

	if (s4 == s3) {}		// 3) �̷��� �񱳵� ����

	std::cout << s4 << std::endl; // 4) ��µ� ����

	//	=> ��, s3, s4 �� int Ÿ��ó�� ��� �����ϴ�


}