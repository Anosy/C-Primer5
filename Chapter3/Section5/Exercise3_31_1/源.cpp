#include<iostream>
#include<string>
using namespace std;


// ����Ŀ�������ֱ�Ӹ�ֵ
int main()
{
	int a[10];
	int b[10];

	for (unsigned i = 0; i < 10; i++)
	{
		a[i] = i;
	}

	for (unsigned j = 0; j < 10; j++)
	{
		b[j] = a[j];
	}

	for (auto c : b)
	{
		cout << c << endl;
	}

	system("pause");
	return 0;
}