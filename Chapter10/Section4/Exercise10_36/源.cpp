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
		cout << "û���ҵ�0" << endl;
	}
	else
	{
		cout << "���һ��ֵΪ0�����ڵ�" << p << "��λ��" << endl;
	}

	system("pause");
	return 0;
}