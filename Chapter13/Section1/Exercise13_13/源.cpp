#include<iostream>
#include<vector>

using namespace std;

struct X
{
	X() { cout << "���캯�� X()" << endl; }

	X(const X&) { cout << "�������캯�� X(const X&)" << endl; }

	X& operator=(const X& rhs) { cout << "������ֵ�����" << endl; return *this; }

	~X() { cout << "�������� ~X()" << endl; }

};


void f(X x)
{

}

void f2(X &x)
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
	
	system("pause");
	return 0;
}