#include <iostream>

template<typename T1, typename T2>
// ?? add(T1 a, T2 b)						// 1) ?? �κ��� T1, T2 �� � type ������ ���� �޶����� ������ ä��� �����
// decltype(a+b) add(T1 a, T2 b)			// 2) �� �ڵ�� �� �����ϱ��?
											//    ���� a, b �� ���𺸴� decltype(a+b) ���� ���� ����� �ռ� �ֱ� ������.
// auto add(T1 a, T2 b) -> decltype(a+b)	// 4) ���� ��ȯ Ÿ���� ����Ͽ� �ذ� ����. (C++11 ��Ÿ��)
auto add(T1 a, T2 b)						// 5) C++14 ���ʹ� ���� ��ȯ Ÿ���ڵ� ������ ����
{
	return a + b;
}

int main()
{
	std::cout << add<int, double>(1, 2.2) << std::endl; // ��Ȯ�� ǥ���

	std::cout << add(1, 2.2)			  << std::endl; // Ÿ�� ���� ����.
														// �Լ� ���ڷ� Ÿ�� ����.

}