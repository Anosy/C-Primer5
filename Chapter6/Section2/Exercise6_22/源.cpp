#include<iostream>

using namespace std;

// ����ָ����ָ�����ֵ
void changevalue(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void changeip(int *(&p), int *(&q))
{
	int *temp = p;
	p = q;
	q = temp;
}


int main()
{
	int a = 5, b = 10;
	int *p = &a, *q = &b;
	cout << "����ǰ��ֵΪ��" << "a=" << a << ", b=" << b << endl;
	changevalue(p, q);
	cout << "�������ֵΪ��" << "a=" << a << ", b=" << b << endl;

	cout << "����ǰ��ָ��" << "p=" << p << ", q=" << q << endl;
	changeip(p, q);
	cout << "�������ָ��" << "p=" << p << ", q=" << q << endl;

	system("pause");
	return 0;
}