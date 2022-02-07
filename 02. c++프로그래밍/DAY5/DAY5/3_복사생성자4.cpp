// 3_복사생성자4

#include <iostream>
class Buffer
{
	int* buff;
	int size;
public:
	Buffer(int sz) : size(sz)
	{
		buff = new int[size];
	}
	~Buffer()
	{
		delete[] buff;
	}

	// 1. 깊은 복사 (deep copy) 로 구현한 복사 생성자
	// => 깊은 복사 : 포인터가 아니라 메모리 자체를 복사 한것. 
	Buffer(const Buffer& buf) : size(buf.size)
	{
		// 1) 포인터가 아닌 멤버는 그냥 복사 한다
		// size = buf.size;			// <== 초기화리스트에서 초기화가 더 좋음
		// 2) 포인터 멤버는 메모리 할당후 메모리 자체를 복사한다.
		//  => b1, b2 가 서로 다른 주소를 가리키도록 한다.
		buff = new int[size];		// <== buff 는 멤버 변수 buff
		memcpy(buff, buf.buff, sizeof(int) * size);
	}
};

// 2. 결론
//  1) class 내부적으로 포인터같은 멤버가 없다면.. 컴파일러가 만든 복사 생성자를 사용해도 문제 없습니다
//  2) class 내부적으로 포인터같은 멤버가 있다면, 항상 위험합니다 (얕은복사 현상)
//	  => 반드시 복사 생성자를 따로 만들어서 해결해야 합니다.
// 
// 3. 권장 - 되도록 클래스 멤버로 포인터를 넣지 마세요.
//  1) char* => string 사용
//  2) int* p = new int[10] => vector<int> v(10) 사용하세요.


/* 시험문제 : 컴파일러가 만드는 복사생성자는 "deep copy" 를 사용하므로 포인터멤버 복사가 필요 없습니다. false.*/

int main()
{
	Buffer b1(64);
	Buffer b2 = b1;			
}