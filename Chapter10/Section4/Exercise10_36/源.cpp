#include<fstream>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<list>
#include<string>

using namespace std;

int main()
{
	list<int> ilist = { 1,2,3,4,0,3,4,0,2,1,3,1,2 };
	auto cw = find(ilist.crbegin(), ilist.crend(), 0);
	cw++;
	unsigned p = 0;
	for (auto it = ilist.begin(); it != cw.base(); it++, p++);
	if (p > ilist.size())
	{
		cout << "没有找到0" << endl;
	}
	else
	{
		cout << "最后一个值为0的数在第" << p << "个位置" << endl;
	}

	system("pause");
	return 0;
}