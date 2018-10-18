#include<iostream>

using namespace std;

void f()
{
	cout << "该函数无须参数" << endl;
}

void f(int)
{
	cout << "该函数需要一个int参数" << endl;
}

void f(int, int)
{
	cout << "该函数需要两个int参数" << endl;
}

void f(double a, double b = 3.14)
{
	cout << "该函数需要量个double参数" << endl;
}

int main()
{
	// f(2.56, 46);  // 无最佳匹配
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	system("pause");
	return 0;
}
