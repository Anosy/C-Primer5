#include<string>
#include<iostream>

using namespace std;

int main()
{
	string rsp;

	do {
		cout << "�������������֣�" << endl;
		int num1, num2;
		cin >> num1 >> num2;
		cout << "�������ֵĺ�Ϊ��" << num1 + num2 << endl;
		cout << "�Ƿ�Ҫ��������(y/n)?" << endl;
		cin >> rsp;
	} while (rsp == "y");

	system("pause");
	return 0;
}