#include<iostream>
#include<vector>
#include<utility>

using namespace std;

struct X
{
	X() { cout << "ֱ�ӳ�ʼ" << endl; }
	X(const X &) { cout << "������ʼ" << endl; }
	X(const X&&) { cout << "�ƶ���ʼ" << endl; }
	X &operator=(const X&) { cout << "������ֵ�����" << endl; return *this; };
	~X() { cout << "��������" << endl; }
};

void f(X)
{

}
void f2(X &)
{

}

int main()
{
	cout << "X x" << endl;
	X x;
	cout << endl;

	cout << "�����ô��ݲ���" << endl;
	f(x);
	cout << endl;

	cout << "���ô��ݲ���" << endl;
	f2(x);
	cout << endl;

	cout << "��̬����" << endl;
	auto *p = new X;
	cout << endl;

	cout << "�ͷŶ�̬�������" << endl;
	delete p;
	cout << endl;

	cout << "��ӳ�ʼ���͸�ֵ" << endl;
	X y = x;
	y = x;
	cout << endl;

	cout << "������ֵ" << endl;
	X z(move(x));
	cout << endl;
		 

	system("pause");
	return 0;
}