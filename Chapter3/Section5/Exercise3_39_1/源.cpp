#include<iostream>
#include<string>
using namespace std;

int main()
{
	string aString, bString;

	cout << "�����������ַ���:" << endl;

	cin >> aString >> bString;

	if (aString > bString)
	{
		cout << "��һ���ַ����ȵڶ����ַ����� " << endl;
	}
	else if (aString < bString)
	{
		cout << "��һ���ַ����ȵڶ����ַ���С!  " << endl;
	}
	else
	{
		cout << "�����ַ�����ͬ��" << endl;
	}

	system("pause");
	return 0;
}