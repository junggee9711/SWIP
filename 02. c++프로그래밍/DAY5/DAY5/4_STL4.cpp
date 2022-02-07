// 3_STL4

#include <iostream>
#include <vector>
#include <list>				
#include <set>			
#include <unordered_set>


int main()
{
	// �����̳ʰ� primitive Ÿ���� �����ϱ⵵ ������..
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	// �����̳ʰ� �����̳ʸ� �����ϴ� ���� �Ǹ��� �ڵ尡 �����մϴ�.
	std::vector< std::list<int> > v2(10);	// 10��¥�� vector(�迭), �� ��Ҵ� list

	v[0] = 10;
	v2[0];
	v2[0].push_back(1);
	v2[0].push_back(2);
	v2[0].push_back(3);
	v2[1].push_back(20);
	v2[1].push_back(30);


	// �����̳ʳ��� �����ϸ�, ���� ����ִ� ������ ����� �ֽ��ϴ�.
	// STL �� ���� ���� ����..
	std::vector< std::set<int> > v(3);		// 10��¥�� vector(�迭), �� ��Ҵ� tree(set)

	std::vector< std::vector<int> > matrix(3, std::vector<int>(3));
	// => "std::vector<int>(3)" �ӽ� ��ü��� ǥ��� (�ȹ��)
	matrix[0][0] = 10;						// ok.
}






