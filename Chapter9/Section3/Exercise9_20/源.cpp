#include<list>
#include<deque>
#include<iostream>

using namespace std;

int main()
{
	list<int> lInt = { 1, 2, 3, 4, 5, 6 };
	deque<int> dInt1;
	deque<int> dInt2;

	for (auto beg = lInt.cbegin(); beg != lInt.cend(); ++beg)
	{
		if ((*beg)%2 != 0) // 可以使用*beg &1 位与
		{
			dInt1.push_back(*beg);
		}
		else
		{
			dInt2.push_back(*beg);
		}
	}

	for (auto d1 : dInt1)
	{
		cout << d1 ;
	}
	cout << endl;

	for (auto d2 : dInt2)
	{
		cout << d2 ;
	}
	cout << endl;

	system("pause");
	return 0;
}