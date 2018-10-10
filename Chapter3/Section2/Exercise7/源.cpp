#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string s, results;
	cout << "请输入字符串，可以包含空格：" << endl;

	getline(cin, s);
	for (auto &c : s)
	{
		if (!ispunct(c))
		{
			results += c;
		}
	}
	cout << results << endl;

	system("pause");
	return 0;
}
