#include<iostream>

using namespace std;

int main()
{
	auto func = [](int a, int b) { return a + b;  };
	cout << func(1, 2) << endl;

	system("pause");
	return 0;
}