#include<iostream>
#include<vector>

using namespace std;

bool func(vector<int>::iterator beg, vector<int>::iterator end, int t)
{
	unsigned i = 0;
	for (; beg != end; ++beg)
	{
		if (*beg == t)
		{
			cout << "�ڵ�" << i << "��λ���ҵ���" << endl;
			return true;
		}
		++i;
	}
	cout << "�Ҳ�����" << endl;

	return false;
}



int main()
{
	vector<int> ilist = { 1,2,3,4,5,6,7,8,9 };
	func(ilist.begin(), ilist.end(), 5);
	func(ilist.begin(), ilist.end(), 15);


	system("pause");
	return 0;
}