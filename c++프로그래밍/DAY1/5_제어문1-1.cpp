// 5_제어문1 38 page


// 1. C++11 의 새로운 for 문 - "range for"

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
	// 2) Decay 예외에 해당 (Decay 가 일어나지 않음)

	for (auto n : x) {
		std::cout << n << std::endl;
	}

	// 3) 문자열의 경우, 문자열 배열 또는 string 은 가능. char* 는 안됨
	char s[] = "ABCDEFG";		// range for 가능
	std::string s = "ABCDEFG";	// 가능
//	const char* s = "ABCDEFG";	// 불가능
	
	for (auto c : s) {
		std::cout << c << std::endl;
	}
}