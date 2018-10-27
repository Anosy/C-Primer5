#include<vector>
#include<list>
#include<iostream>

using namespace std;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55 ,89 };
	vector<int> vInt;
	list<int> lInt;
	for (auto beg = begin(ia); beg != end(ia); ++beg)
	{
		vInt.push_back(*beg);
		lInt.push_back(*beg);
	}
	auto vt = vInt.begin();
	while (vt != vInt.end())
	{
		if (*vt % 2 == 0)
		{
			vt = vInt.erase(vt);
		}
		else
		{
			++vt;
		}
	}
	auto lt = lInt.begin();
	while (lt != lInt.end())
	{
		if (*lt % 2 != 0)
		{
			lt = lInt.erase(lt);
		}
		else
		{
			++lt;
		}
	}

	for (auto v : vInt)
	{
		cout << v << " ";
	}
	cout << endl;

	for (auto l : lInt)
	{
		cout << l << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}