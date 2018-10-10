#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<string> vString;
	string s;
	char cnt = 'y';
	cout << "请输入第一个词" << endl;

	while (cin>>s)
	{
		vString.push_back(s);
		cout << "是否继续输入(y/n)?" << endl;
		cin >> cnt;
		if (cnt != 'y' && cnt != 'Y')
		{
			break;
		}
		cout << "请输入下一个词" << endl;

	}
	for (auto &mem : vString) // 获取vector中的每个元素
	{
		for (auto &c : mem) // 获取每个元素的每个字符
		{
			c = toupper(c);
		}
		cout << mem << endl;
	}

	system("pause");
	return 0;
}