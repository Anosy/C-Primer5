#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	unsigned sz = 1;
	vector<int> a(sz);
	vector<int> b(sz);
	srand((unsigned)time(NULL));

	for (unsigned i = 0; i < sz; i++)
	{
		a[i] = rand() % 10;
	} 

	for (unsigned j = 0; j < sz; j++)
	{
		b[j] = rand() % 10;
	}

	cout << "ϵͳ���ɵ��������aΪ��" << endl;
	for (auto aa : a)
	{
		cout << aa << " " << endl;
	}

	cout << "ϵͳ���ɵ��������bΪ��" << endl;

	for (auto bb : b)
	{
		cout << bb << " " << endl;
	}

	auto abegin = a.cbegin();
	auto aend = a.cend();
	auto bbegin = b.cbegin();
	auto bend = b.cend();

	while (abegin != aend && bbegin != bend)
	{
		if (*abegin != *bbegin)
		{
			cout << "������������ͬ" << endl;
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