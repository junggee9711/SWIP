// 25_upcasting2

#include <iostream>
#include <vector>


class Animal
{
public:
	int age;
};

class Dog : public Animal {};
class Cat : public Animal
{
public:
	int color;
};

//void HappyNewYear(Dog* p)		// Dog 만 전달 가능한 함수
void HappyNewYear(Animal* p)	// "동일 기반클래스를 사용하는(동종)" 타입을 모두 전달 가능한 함수
{								// => 인자를 Animal* p = &c 로 받기 때문에
	++(p->age);
}

int main()
{
	Dog d;
	HappyNewYear(&d);			// ok.
	Cat c;
	HappyNewYear(&c);			// error. 함수가 Dog* p 를 인자로 받기 때문에

	std::vector<Dog*> woori;		// Dog 만 보관하는 우리
	std::vector<Animal*> woori;		// 모든 동물(동종)을 보관하는 컨테이너 만들기
									// 142 page 아래 부분
}