#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str1, str2;
	do
	{
		cout << "请输入两个字符串：" << endl;
		cin >> str1 >> str2;
		
		if (str1.size() > str2.size())
		{
			cout << "第一个字符串比第二字符串长" << endl;
		}
		else if (str1.size() < str2.size())
		{
			cout << "第一个字符串比第二字符串短" << endl;

		}
		else
		{
			cout << "两个字符串长度相同" << endl;
		}
		
	} while (cin);

	system("pause");
	return 0;
}