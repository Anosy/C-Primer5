#include<iostream>

using namespace std;

int main()
{
	int num1, num2;
	cout << "请输入两个数字" << endl;
	cin >> num1 >> num2;
	if (num2 == 0)
	{
		cout << "除数不能为0" << endl;
		system("pause");
		return -1;
	}
	cout << "两个数相除的结果：" << num1/num2 <<endl;

	system("pause");
	return 0;
}