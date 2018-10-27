#include<list>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	list<int> ilist= { 1, 2, 3, 4 };
	vector<double> vDouble1(ilist.begin(), ilist.end());
	
	vector<int> vInt = { 2, 3, 4, 5 };
	vector<double> vDouble2(vInt.begin() + 1, vInt.end());

	for (auto d : vDouble1)
	{
		cout << d << " ";
	}
	cout << endl;

	for (auto d : vDouble2)
	{
		cout << d << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}