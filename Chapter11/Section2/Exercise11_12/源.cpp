#include<iostream>
#include<utility>
#include<vector>
#include<string>

using namespace std;

int main()
{
	cout << "请输入一个string和一个int类型的元素" << endl;
	string str;
	int num;
	vector<pair<string, int>> mypair;

	while (cin >> str >> num)
	{
		auto temp_pair = make_pair(str, num);
		mypair.push_back(temp_pair);
	}

	for (const auto &v : mypair)
	{
		cout << v.first << " : " << v.second << endl;
	}
	
	system("pause");
	return 0;

}