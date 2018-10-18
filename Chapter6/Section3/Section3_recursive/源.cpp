#include<iostream>

using namespace std;

int factorial(int val)
{
	if (val > 1)
	{
		return factorial(val - 1)*val;
	}
	return 1;
}


int main()
{
	int a = 5;
	int results = factorial(5);
	cout << results << endl;

	system("pause");
	return 0;
}