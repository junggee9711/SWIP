#include <iostream>
#include <stdlib.h>

int main()
{
	// ����ڰ� �Է��� ũ��(count) ��ŭ ������ �Է¹������� �մϴ�.
	int count;
	std::cin >> count;
	
//	int score[count];		// error.

	// ����� ������ ũ��� �޸𸮸� ������� ���� �޸� �Ҵ��� ����ؾ� ��.
	int* score = new int[count];

	score[0] = 10;

	delete[] score;			// �޸� ����.
}