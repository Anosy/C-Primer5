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
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ڵ�" << viter - vInt.begin() + 1 << "λ���ҵ��˸�Ԫ��" << endl;
	}


	auto liter = my_find(lStr.begin(), lStr.end(), "b");
	if (liter == lStr.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˸�Ԫ��" << endl;
	}

	system("pause");
	return 0;
}