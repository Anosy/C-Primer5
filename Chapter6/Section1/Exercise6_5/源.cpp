#include<iostream>
#include<cmath>

using namespace std;

int fact(int val)
{
	int result = abs(val);
	return result;
}


int main()
{
	cout << "请输入一个数字：" << endl;
	int num;
	cin >> num;
	cout << "该数的绝对值为：" << fact(num) << endl;

	system("pause");
	return 0;
}