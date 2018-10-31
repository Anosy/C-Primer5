#include<algorithm>
#include<vector>
#include<iostream>
#include<list>

using namespace std;

int main()
{
	vector<int> vec; 
	list<int> lst;
	int i;

	while (cin >> i)
	{
		lst.push_back(i);
	}
	copy(lst.cbegin(), lst.cend(), back_inserter(vec));

	for (auto l : lst)
	{
		cout << l << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}