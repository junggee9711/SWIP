#include <iostream>
#include <vector>		// 이미 C++ 표준에 vector 가 있음. (동적 배열을 vector 라고 함)

// OOP 를 추구하는 이유 - 극상의 재사용성 !!

int main()
{
	std::vector<int> v(5);		// 5개 배열

	v[0] = 10;					// "연산자 재정의 문법" 으로 진짜 배열과 사용법 동일 - 마지막 날 배움
	v.resize(7);

	std::cout << v[0] << std::endl;

	std::vector<int> v2;		// 크기가 0인 배열
	v2.push_back(1);
	v2.push_back(5);			// 메모리가 부족하면 n 만큼 자동 증가 됩니다.

	std::cout << v2.size() << std::endl;

	int n = 0;

	while (1)
	{
		std::cin >> n;
		if (n == -1) break;
		v2.push_back(n);		// 알아서 메모리가 증가해서 들어갑니다.
	}
}

// 파이썬의 list 가 vector 입니다.
// s = [1, 2, 3]
// s.append(5)