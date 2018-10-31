#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int a, number;
	cin >> a >> number;
	
	auto func = [a](int b) {return a + b; };
	
	cout << func(number) << endl;

	system("pause");
	return 0;
}