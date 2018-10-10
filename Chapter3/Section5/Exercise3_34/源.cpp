#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	constexpr int sz = 10;

	int a[sz], i = 0;

	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}

	cout << "当前的数组的输出：" << endl;

	for (auto c : a)
	{
		cout << c << endl;
	}

	int *abegin = begin(a);
	int *aend = end(a);

	for (abegin; abegin!=aend; abegin++)
	{
		*abegin = 0;
	}
	
	cout << "转换后的数组的输出：" << endl;

	for (auto c : a)
	{
		cout << c << endl;
	}


	system("pause");
	return 0;
}