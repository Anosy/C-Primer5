#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<int> vInt;
	int iVal;
	cout << "请输入一组数据：" << endl;
	while (cin >> iVal)
	{
		vInt.push_back(iVal);
	}

	if (vInt.begin() == vInt.end())
	{
		cout << "没有输入数据！" << endl;
		return -1;
	}

	auto begin = vInt.cbegin(), end = vInt.cend();
	auto mid = begin + (end - begin) / 2;

	for (auto it = begin; it != mid; it++)
	{
		cout << (*it + *(begin + (end - it) - 1)) << " " << endl;
	}

	if (vInt.size() % 2 != 0)
	{
		cout << "剩下的数为：" << *mid << endl;
	}
	
	system("pause");
	return 0;

}