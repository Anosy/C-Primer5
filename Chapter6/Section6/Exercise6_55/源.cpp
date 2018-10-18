#include<iostream>
#include<vector>

using namespace std;

int func1(int a, int b)
{
	return a + b;
}

int func2(int a, int b)
{
	return a - b;
}

int func3(int a, int b)
{
	return a * b;
}

int func4(int a, int b)
{
	return a / b;
}

int main()
{
	decltype(func1) *p1 = func1;
	decltype(func2) *p2 = func2;
	decltype(func3) *p3 = func3;
	decltype(func4) *p4 = func4;

	vector<decltype(func1)*> vF = { p1, p2, p3, p4 };

	return 0;
}
