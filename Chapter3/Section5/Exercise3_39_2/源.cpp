#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char cal1[80], cal2[80];

	cout << "请输入两个字符串:" << endl;

	cin >> cal1 >> cal2;

	if (strcmp(cal1, cal2) == 0)
		cout << "两个字符串相同！" << endl;
	else if (strcmp(cal1, cal2) > 0)
		cout << "第一个字符串比第二个字符串大!" << endl;
	else
		cout << "第一个字符串比第二个字符串小！" << endl;
	system("pause");
	return 0;
}