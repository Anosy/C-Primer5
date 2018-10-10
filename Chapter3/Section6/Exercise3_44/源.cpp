#include<iostream>

using namespace std;

int main()
{
	int arr[3][4];
	size_t cnt = 0;
	for (auto &a : arr)
	{
		for (auto &b : a)
		{
			b = cnt;
			++cnt;
		}
	}

	using int_arrary = int[4];  // int_arrary就是int[4]的别名
	for (int_arrary *p = arr; p != arr + 3; p++)
	{
		for (int *q = *p; q != *p + 4; q++)
		{
			cout << *q << " ";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}