#include<iostream>
#include<vector>

using namespace std;

vector<int>::iterator func(vector<int>::iterator beg, vector<int>::iterator end, int t)
{
	unsigned i = 0;
	for (; beg != end; ++beg)
	{
		if (*beg == t)
		{
			cout << "在第" << i << "个位置找到的" << endl;
			return beg;
		}
		++i;
	}
	cout << "找不到！" << endl;

	return end;
}



int main()
{
	vector<int> ilist = { 1,2,3,4,5,6,7,8,9 };
	cout << func(ilist.begin(), ilist.end(), 5) - ilist.begin() << endl;
	cout << func(ilist.begin(), ilist.end(), 15) - ilist.begin() << endl;



	system("pause");
	return 0;
}