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

	cout << "ϵͳ���ɵ����a����Ϊ��" << endl;
	for (auto aa : a)
	{
		cout << aa << " " << endl;
	}

	cout << "ϵͳ���ɵ����b����Ϊ��" << endl;

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
			cout << "�������鲻��ͬ" << endl;
			system("pause");
			return -1;
		}
		++abegin;
		++bbegin;
	}
	cout << "����������ͬ" << endl;

	system("pause");
	return 0;
}