// 3_복사생성자6

#include <iostream>
#include <mutex>

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

	// 아래는 컴파일러에게 복사 생성자가 필요없으니 만들지 말라고 명령하는 것
	// => 자동으로 만든 복사 생성자를 delete 하라는 명령
	Buffer(const Buffer&) = delete;
};


int main()
{
	Buffer b1(64);
//	Buffer b2 = b1;		// error. 복사 생성자가 없기 때문에.	

	// 타입들중에서 논리적으로 생각했을때 "복사되면 안되는 타입" 도 있습니다.
	// => 이런 경우, "복사생성자를 삭제 합니다"
	std::mutex m1;
//	std::mutex m2 = m1; // error. 뮤텍스는 복사 생성자가 삭제되어 있습니다.
}