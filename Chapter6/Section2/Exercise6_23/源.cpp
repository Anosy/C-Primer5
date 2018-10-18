#include<iostream>

using namespace std;

// �򵥵�ָ���β�
void print1(const int *p)
{
	cout << *p << endl;
}

// ָ�������ά��
void print2(const int *p, const int sz)
{
	int i = 0;
	while (i != sz)
	{
		cout << *p++ << endl;
		++i;
	}
}

// ָ��begin��end���޶��߽�
void print3(const int *p, const int *q)
{
	for (auto it = p; it != q; ++it)
	{
		cout << *it << endl;
	}
}

int main()
{
	int i = 0, j[2] = { 5, 6 };
	print1(&i);
	print1(j);
	print2(&i, 1);
	print2(j, sizeof(j) / sizeof(*j)); // sizeof(j) / sizeof(*j) �����ڼ�������ĳ���
	auto b = begin(j);
	auto e = end(j);
	print3(b, e);

	system("pause");
	return 0;
}