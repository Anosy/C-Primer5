#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str1, str2;
	bool b1 = true;
	cout << "请输入两个字符串：" << endl;
	cin >> str1;
	while (cin >> str2)
	{
		if (str1 == str2)
		{
			b1 = false;
			cout << "连续出现的单词为：" << str1 << endl;
			break;
		}
		str1 = str2;
	}
	if (b1)
	{
		cout << "没有连续出现的单词！" << endl;
	}

	system("pause");
	return 0;
}