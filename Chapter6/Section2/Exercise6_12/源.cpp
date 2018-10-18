#include<iostream>

using namespace std;

void change(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main()
{
	int a = 5, b = 10;
	cout << "交换前的值为：" << endl;
	cout << "a：" << a << "  b：" << b << endl;
	change(a, b);
	cout << "交换后的值为：" << endl;
	cout << "a：" << a << " b：" << b << endl;

	system("pause");
	return 0;
}