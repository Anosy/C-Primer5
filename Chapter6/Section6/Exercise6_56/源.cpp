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

void Compute(int a, int b, int(*p)(int, int))
{
	cout << p(a, b) << endl;
}


int main()
{
	int i = 5, j = 10;
	decltype(func1) *p1 = func1;
	decltype(func2) *p2 = func2;
	decltype(func3) *p3 = func3;
	decltype(func4) *p4 = func4;

	cout << typeid(func1).name() << ' ' << typeid(p2).name() << endl;

	vector<decltype(func1)*> vF = { p1, p2, p3, p4 };

	for (auto p : vF)
	{
		Compute(i, j, p);
	}

	system("pause");
	return 0;
}
