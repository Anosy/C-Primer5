#include<iostream>
using namespace std;
int main()
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto g = ci;

	cout << a << endl;
	a = 42;
	cout << a << endl;
	
	cout << b << endl;
	b = 42;
	cout << b << endl;
	
	cout << c << endl;
	c = 42;
	cout << c << endl;

	cout << d << endl;
	// d = 42;

	system("pause");
	return 0;
}
