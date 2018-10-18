#include<iostream>

using namespace std;

// 交换指针所指对象的值
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
	cout << "交换前的值为：" << "a=" << a << ", b=" << b << endl;
	changevalue(p, q);
	cout << "交换后的值为：" << "a=" << a << ", b=" << b << endl;

	cout << "交换前的指针" << "p=" << p << ", q=" << q << endl;
	changeip(p, q);
	cout << "交换后的指针" << "p=" << p << ", q=" << q << endl;

	system("pause");
	return 0;
}