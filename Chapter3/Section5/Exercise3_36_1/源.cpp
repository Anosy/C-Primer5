#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	constexpr int sz = 2;
	int a[sz], b[sz];
	srand((unsigned)time(NULL));


	for (unsigned i = 0; i < sz; i++)
	{
		a[i] = rand() % 10;
	}

	for (unsigned j = 0; j < sz; j++)
	{
		b[j] = rand() % 10;
	}

	cout << "系统生成的随机a数组为：" << endl;
	for (auto aa : a)
	{
		cout << aa << " " << endl;
	}

	cout << "系统生成的随机b数组为：" << endl;

	for (auto bb : b)
	{
		cout << bb << " " << endl;
	}

	int *abegin = begin(a);
	int *bbegin = begin(b);

	for (unsigned i = 0; i < sz; i++)
	{
		if (*abegin != *bbegin)
		{
			cout << "两个数组不相同" << endl;
			system("pause");
			return -1;
		}
		++abegin;
		++bbegin;
	}
	cout << "两个数组相同" << endl;

	system("pause");
	return 0;
}