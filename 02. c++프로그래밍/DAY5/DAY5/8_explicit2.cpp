// 8_explicit2

#include <vector>
#include <string>

void f1(std::string s) {}			// std::string s = "hello" 허용됨.
void f2(std::vector<int> v) {}		// std::vector<int> v = 10 은 허용되지 않음.

int main()
{
	std::string		 s1("hello");	// 그러므로, string(const char*) 생성자가 있습니다.
	std::vector<int> v1(10);		// 그러므로, vector(int) 생성자가 있습니다.

	// 아래 2줄의 코드가 각각 되는게 좋을까요? 안되는게 좋을까요?
	f1("hello");					// ok.
//	f2(10);							// error. 안되는게 좋기때문에, "함수의 인자로 받을때" explicit으로 구현됨.
}

// 질문 : smkang@codenuri.co.kr 메일
