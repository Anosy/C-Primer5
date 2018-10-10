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
	while (cin>>iVal)
	{
		vInt.push_back(iVal);
	}

	if (vInt.begin() == vInt.end())
	{
		cout << "没有输入数据！" << endl;
		return -1;
	}
	
	cout << "相邻两个数的和为：" << endl;

	for (auto it = vInt.cbegin(); it != vInt.cend()-1; it++)
	{
		cout << (*it + *(++it)) << endl;
	}
	if (vInt.size() % 2 != 0)
	{
		cout << *(vInt.cend() - 1);
	}


	system("pause");
	return 0;
}