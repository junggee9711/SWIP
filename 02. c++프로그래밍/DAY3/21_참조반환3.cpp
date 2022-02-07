// 21_참조반환3

#include <iostream>

// - 왜 임시객체를 조심해야 할까?

class Counter
{
public:
	int value = 0;

	Counter increment()
	{
		++value;
		return *this;
	}

	~Counter() { std::cout << "~Counter()" << std::endl; }
};

int main()
{
	Counter c;
	c.increment().increment().increment();	// <== 여기서 3개의 "리턴용임시객체파괴"
	std::cout << c.value << std::endl;
} // <== 여기서 c 파괴 
// 그러므로 ~Counter()\n ~Counter()\n ~Counter()\n 1\n ~Counter()\n 으로 출력

