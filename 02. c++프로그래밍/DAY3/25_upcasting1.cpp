// 25_upcasting1 140 page

#include <iostream>

class Animal
{
	int age;
public:
	void cry() {}
};

class Dog : public Animal
{
	int color;
public:
	void run() {}
};

int main()
{
	Dog dog;
	Dog*    p1 = &dog;				// ok.
//	int*    p2 = &dog;				// error.
	Animal* p3 = &dog;				// ok. upcasting
	
	// �ٽ� 1. ���Ŭ���� ������(p3)�� �Ļ�Ŭ���� ��ü(dog)�� ����ų�� �ִ�.
	//		  => �� �ݴ�� �Ұ�

	// �ٽ� 2. ������, Animal* p3 �� ����ϸ� �����Ϸ��� p3�� ����Ű�� ���� Animal �̶�� �����ϹǷ�,
	//		   Dog ���� �߰��� ����� �����Ҽ� �����ϴ�.
	p3->cry();						// ok
//	p3->run();						// error. 

	// �ٽ� 3. Dog ������ ����� �����Ϸ��� ĳ���� �ϸ� �˴ϴ�.
	//		   ��, �̰�� p3 �� ����Ű�� ���� Dog �� Ȯ���ؾ� �մϴ�. 
	//		  => (Animal* p3 = &dog �̹Ƿ� ���⼱ Ȯ��)
	//		   Dog �� �ƴϸ� runtime error �� �߻��� �� �ֽ��ϴ�.
	static_cast<Dog*>(p3)->run();	// ok. ��Ӱ����� static_cast �� ���.

}