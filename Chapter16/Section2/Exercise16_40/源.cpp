#include<iostream>
#include<type_traits>

using namespace std;

class Bar
{
};

Bar operator+(const Bar &lhs, int a)
{
	return lhs;
}

int main()
{
	Bar b;
	int a = 0;
	const int c = 0;
	const int d = 0;
	auto sum = b + a;
	cout << typeid(sum).name() << endl;
	cout << typeid(a * c).name() << endl;
	cout << typeid(d * c).name() << endl;

	system("pause");
	return 0;
}