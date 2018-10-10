#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string s;
	cout << "请输入字符串，可以包含空格：" << endl;
	getline(cin, s);

	for (unsigned i = 0; i < s.size(); i++)
	{
		s[i] = 'X';
	}

	cout << s << endl;

	system("pause");
	return 0;
}