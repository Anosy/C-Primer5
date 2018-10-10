#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<int> vInt(10);
	for (auto &i:vInt )
	{
		i = rand() % 10;
	}
	
	cout << "产生的随机数为：" << endl;

	for (auto it = vInt.cbegin(); it != vInt.cend(); it++)
	{
		cout << *it << " " << endl;
	}

	cout << "放大两倍的结果：" << endl;

	for (auto is = vInt.begin(); is != vInt.cend(); is++)
	{
		*is *= 2;
		cout << *is << " " << endl;
	}

	system("pause");
	return 0;
}