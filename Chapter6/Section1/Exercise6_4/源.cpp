#include<iostream>

using namespace std;

int fact(int val)
{
	int result = 1;
	if (val < 0)
	{
		return -1;
	}

	while (val>1)
	{
		result *= val--;
	}
	return result;
}

int main()
{
	cout << "请输入一个数字：" << endl;
	int num;

	cin >> num;
	int result = fact(num);
	if (result == -1)
	{
		cout << "输入的数字有误！" << endl;
		system("pause");
		return -1;
	}
	cout << "阶乘计算的结果为：" << result << endl;
	
	system("pause");
	return 0;
}