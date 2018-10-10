#include<iostream>
#include<string>
using namespace std;

int main()
{
	string aString, bString;

	cout << "请输入两个字符串:" << endl;

	cin >> aString >> bString;

	if (aString > bString)
	{
		cout << "第一个字符串比第二个字符串大！ " << endl;
	}
	else if (aString < bString)
	{
		cout << "第一个字符串比第二个字符串小!  " << endl;
	}
	else
	{
		cout << "两个字符串相同！" << endl;
	}

	system("pause");
	return 0;
}