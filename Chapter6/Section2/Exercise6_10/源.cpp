#include<iostream>

using namespace std;

void func(int *ip, int *iq)
{
	int temp = *ip;
	*ip = *iq;
	*iq = temp;
}

int main()
{
	int a = 5, b = 10;
	int *r = &a, *s = &b;
	cout << "交换前：" << " a= " << a << " b= " << b << endl;
	func(r, s);
	cout << "交换后：" << " a= " << a << " b= " << b << endl;

	system("pause");
	return 0;
}