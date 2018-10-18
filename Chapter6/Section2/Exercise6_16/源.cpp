#include<iostream>
#include<string>

using namespace std;

bool isUp(const string &str)
{
	for (const auto c : str)
	{
		if (isupper(c))
		{
			return true;
		}
	}
	return false;
}

void translow(string &str)
{
	for (auto &c : str)
	{
		c = tolower(c);
	}
}



int main()
{
	string str;
	cout << "请输入一个字符串：" << endl;

	cin >> str;
	if (isUp(str))
	{
		translow(str);
		cout << "转换后的字符串为：" << str << endl;
	}
	else
	{
		cout << "该字符没有大写字母，无需转换" << endl;
	}

	system("pause");
	return 0;
}