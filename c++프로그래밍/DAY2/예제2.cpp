#include <iostream>
#include <stdlib.h>

int main()
{
	// 사용자가 -1 을 입력할때 까지 입력받아야 한다.
	// 그런데, 입력값은 반드시 보관하고 있어야 한다. (동적 배열)

	int count = 0;					// 입력된 갯수
	int size = 5;					// 버퍼 크기 (배열 크기)
	int n = 0;

	int* buff = new int[size];

	while (1) {
		std::cin >> n;
		if (n == -1) break;

		buff[count] = n;
		++count;

		if (count == size) {
			int* temp = new int[size + 5];			// 현재 배열 크기보다 5 만큼 큰 배열을 동적 할당

			memcpy(temp, buff, sizeof(int) * size); // 새로 생성한 배열(temp)에 기존 배열(buff) 값을 정한 크기만큼 복사

			delete[] buff;

			buff = temp;

			size = size + 5;
		}
		std::cout << "입력된 갯수 : " << count << std::endl;

		for (int i = 0; i < count; i++)				// range for 사용 불가. 배열의 크기값이 없기 때문에
			std::cout << buff[i] << std::endl;

		delete[] buff;
	}


}