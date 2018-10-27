#include<vector>
#include<list>
#include<iostream>

using namespace std;

int main()
{
	vector<int> vInt = { 1,2,3,4 };
	list<int> lInt = { 1,2,3,4 };

	auto beg1 = vInt.begin();
	auto end1 = vInt.end();
	auto beg2 = lInt.begin();
	auto end2 = lInt.end();

	if (vInt.size()!=lInt.size())
	{
		cout << "����ͬ" << endl;
		system("pause");

		return -1;
	}
	for (;beg1 != end1; ++beg1, ++beg2)
	{
		if (*beg1 != *beg2)
		{
			cout << "����ͬ" << endl;
			system("pause");

			return -1;
		}
	}
	cout << "��ͬ" << endl;

	system("pause");
	return 0;
}