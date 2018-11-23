#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a = 1;
	double b = 2.0;
	auto m = max<int>(a, b);
	cout << m << endl;

	system("pause");
	return 0;
}