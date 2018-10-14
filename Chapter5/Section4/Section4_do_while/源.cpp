#include<string>
#include<iostream>

using namespace std;

int main()
{
	string rsp;

	do {
		cout << "请输入两个数字：" << endl;
		int num1, num2;
		cin >> num1 >> num2;
		cout << "两个数字的和为：" << num1 + num2 << endl;
		cout << "是否还要继续计算(y/n)?" << endl;
		cin >> rsp;
	} while (rsp == "y");

	system("pause");
	return 0;
}