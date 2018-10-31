#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<iterator>
#include<string>

using namespace std;

int main()
{
	vector<int> vInt1 = { 1,2,3,4,5,6,7,8,9 };
	list<int> list1;
	vector<int> vInt3;
	vector<int> vInt4;

	copy(vInt1.begin(), vInt1.end(), front_inserter(list1));
	copy(vInt1.begin(), vInt1.end(), inserter(vInt3, vInt3.begin()));
	copy(vInt1.begin(), vInt1.end(), back_inserter(vInt4));

	for (const auto v : list1)
	{
		cout << v << " ";
	}
	cout << endl;

	for (const auto v : vInt3)
	{
		cout << v << " ";
	}
	cout << endl;

	for (const auto v : vInt4)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}