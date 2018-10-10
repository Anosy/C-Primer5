#include<iostream>
#include<string>
using namespace std;

int main()
{
	constexpr unsigned sz = 10;
	int arr[sz];
	for (unsigned i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (auto a : arr)
		cout << a << endl;


	system("pause");
	return 0;
}