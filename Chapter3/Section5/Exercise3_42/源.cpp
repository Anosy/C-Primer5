#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<int> vInt;

	int num;
	const int sz = 5;
	int a[sz];
	cout << "请输入5个数字：" << endl;

	for (int i = 0; i < sz; i++)
	{
		cin >> num;
		vInt.push_back(num);
	}
	
	cout << "容器中的值为：" << endl;
	for (auto v : vInt)
		cout << v << " " << endl;

	auto it = vInt.cbegin();
	
	for (auto &c : a)
	{
		c = *it;
		++it;
	}

	cout << "数组中的值为：" << endl;
	for (auto aa : a)
	{
		cout << aa << " " << endl;
	}

	system("pause");
	return 0;
}