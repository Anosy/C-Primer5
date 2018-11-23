#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;


template <typename I, typename T>
I my_find(I b, I e, const T &v)
{
	while (b != e && *b != v)
	{
		++b;
	}
	return b;
}

int main()
{
	vector<int> vInt{ 1, 2, 3, 4 ,5, 6 };
	list<string> lStr{ "a", "b", "c", "d", "e" };

	auto viter = my_find(vInt.begin(), vInt.end(), 5);
	if (viter == vInt.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "在第" << viter - vInt.begin() + 1 << "位置找到了该元素" << endl;
	}


	auto liter = my_find(lStr.begin(), lStr.end(), "b");
	if (liter == lStr.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了该元素" << endl;
	}

	system("pause");
	return 0;
}